#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning (disable: 4996)

int main(int argc, char ** argv)
{
	int M, N, x, sum[2], count, p, dest, myid, i, j;
	N = atoi(argv[1]);
	M = atoi(argv[2]);
	MPI_Init(&argc, &argv);
	MPI_Status* stat;
	MPI_Request* req;
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	stat = (MPI_Status*)malloc(M * p * sizeof(MPI_Status));
	req = (MPI_Request*)malloc(M * p * sizeof(MPI_Request));
	for (i = 0; i < M; i++)
		for (j = 0; j < p; j++)
			req[i * p + j] = MPI_REQUEST_NULL;
	srand(myid + 1);
	sum[0] = 0;
	sum[1] = 0;
	count = 0;
	MPI_Barrier(MPI_COMM_WORLD);
	for (i = 0; i < M; i++)
	{
		if (myid == i)
		{
			x = rand() % 101;
			sum[0] = x;
			sum[1] = 1;
			count = 1;
			dest = rand() % (p - 1) + 1;
			if (dest == myid) dest = (myid + 1) / 2;
			MPI_Issend(sum, 2, MPI_INT, dest, i, MPI_COMM_WORLD, &req[i]);
			printf("\nproc %d sent %d to proc %d in the line %d\n", myid, x, dest, i);			
		}
	}
	for (i = 0; i < M; i++)
	{
		while (sum[1] < N)
		{
			MPI_Irecv(sum, 2, MPI_INT, MPI_ANY_SOURCE, i, MPI_COMM_WORLD, &req[i * p + myid]);
			MPI_Wait(&req[i * p + myid], &stat[i * p + myid]);
			if ((sum[0] + sum[1]) == -100) break;
			printf("\nproc %d received %d in the line %d\n", myid, sum[0], i);
			x = rand() % 101;
			sum[0] += x;
			count++;
			sum[1]++;
			if (sum[1] >= N)
			{
				printf("\nproc %d final sum %d in line %d\n", myid, sum[0], i);
				sum[0] = -99;
				sum[1] = -1;
				for (j = 0; j < p; j++)
				{
					if (j != myid)
					{
						MPI_Issend(sum, 2, MPI_INT, j, i, MPI_COMM_WORLD, &req[i * p + j]);
					}
				}
				break;
			}
			dest = rand() % (p - 1) + 1;
			if (dest == myid) dest = (myid + 1) / 2;
			printf("\nproc %d sent %d to proc in line %d%d\n", myid, x, dest, i);
			MPI_Issend(sum, 2, MPI_INT, dest, i, MPI_COMM_WORLD, &req[i * p + myid]);
		}
	}
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
	return 0;
}