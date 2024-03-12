#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#pragma warning (disable: 4996)

double random100()
{
	return rand() % 101;
}

int main(int argc, char** argv)
{
	int myrank, size, i, next, prev, iteration, buf, N;
	int sizeEven = 0, sizeOdd = 0;

	MPI_Status* status = (MPI_Status*)malloc(sizeof(MPI_Status));
	MPI_Request* request = (MPI_Request*)malloc(sizeof(MPI_Request));

 	if (argc>1) N=atoi(argv[1]);
 	else
 		{
			printf("number of points is needed\n");
			return;
 	}

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	srand(myrank);

	next = myrank + 2;
	prev = myrank - 2;

	if (myrank == 0)
	{
		if ((size - 1) % 2 == 0)
		{
			prev = size - 1;
		}
		else
		{
			prev = size - 2;
		}
	}
	if (myrank == 1)
	{
		if ((size - 1) % 2 != 0)
		{
			prev = size - 1;
		}
		else
		{
			prev = size - 2;
		}
	}
	if (((myrank == size - 1) && ((size - 1) % 2 == 0)) || ((myrank == size - 2) && ((size - 2) % 2 == 0)))
	{
		next = 0;
	}
	if (((myrank == size - 1) && ((size - 1) % 2 != 0)) || ((myrank == size - 2) && ((size - 2) % 2 != 0)))
	{
		next = 1;
	}

	//number of odds and evens;
	for (i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			sizeEven++;
		}
		else
		{
			sizeOdd++;
		}
	}
	if (myrank % 2 == 0)
	{
		size = sizeEven;
	}
	else
	{
		size = sizeOdd;
	}


	if (myrank % 2 == 0)
	{
		if (N%size > myrank - myrank / 2 - myrank % 2)
		{
			iteration = N / size + 1; 
		}
		else
		{
			iteration = N / size;
		}
	}
	else
	{
		if (N%size > size - 1 - (myrank - myrank / 2 - myrank % 2))
		{
			iteration = N / size + 1; 
		}
		else
		{
			iteration = N / size;
		}
	}

	if (myrank % 2 != 0)
	{
		int a = prev;
		prev = next;
		next = a;
	}

	int lastOdd = 0;
	if ((sizeOdd + sizeEven - 1) % 2 == 0)
	{
		lastOdd = (sizeOdd + sizeEven - 2);
	}
	else
	{
		lastOdd = (sizeOdd + sizeEven - 1);
	}

	for (i = 0; i < iteration; i++)
	{
		if ((i == 0) && ((myrank == 0) || (myrank == lastOdd)))
		{
			buf = random100();
			MPI_Isend(&buf, 1, MPI_INT, next, 99, MPI_COMM_WORLD, request);
			printf("proc %d send sum = %d\n", myrank, buf);
			continue;
		}
		MPI_Irecv(&buf, 1, MPI_INT, prev, 99, MPI_COMM_WORLD, request);
		MPI_Wait(request, status);
		buf += random100();
		if (myrank % 2 == 0)
		{
			if (i*size + myrank - myrank / 2 - myrank % 2 + 1 == N) 
			{
				printf("proc %d final even sum = %d\n", myrank, buf);
				break;
			}
		}
		else
		{
			if (i*size + size - 1 - (myrank - myrank / 2 - myrank % 2) + 1 == N)
			{
				printf("proc %d final odd sum = %d\n", myrank, buf);
				break;
			}
		}
		
		MPI_Isend(&buf, 1, MPI_INT, next, 99, MPI_COMM_WORLD, request); 
		printf("proc %d send sum = %d\n", myrank, buf);
	}


	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
	return 0;
}
