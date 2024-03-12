#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"
#include <time.h>
#include <math.h>

#pragma warning (disable: 4996)

using namespace std;

int main(int argc, char** argv)
{
	int rank, numtasks, i, next, prev, iteration, buf, N, recvBuf;
	int rankEven = 0, rankOdd = 0;

	MPI_Status* status = (MPI_Status*)malloc(sizeof(MPI_Status));
	MPI_Request* request = (MPI_Request*)malloc(sizeof(MPI_Request));

	//if (argc > 1) N = atoi(argv[1]);

	/*else
	{
		cout << "no argc" << endl;
		return 0;
	}*/

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

	srand(rank);

	next = rank + 2;
	prev = rank - 2;

	if (rank == 0) {
		if ((numtasks - 1) % 2 == 0)
			prev = numtasks - 1;
		else
			prev = numtasks - 2;
	}
	if (rank == 1) {
		if ((numtasks - 1) % 2 != 0)
			prev = numtasks - 1;
		else
			prev = numtasks - 2;
	}

	if (((rank == numtasks - 1) && ((numtasks - 1) % 2 == 0)) || ((rank == numtasks - 2) && ((numtasks - 2) % 2 == 0)))
		next = 0;

	if (((rank == numtasks - 1) && ((numtasks - 1) % 2 != 0)) || ((rank == numtasks - 2) && ((numtasks - 2) % 2 != 0))) 
		next = 1;

	//count odds and evens
	for (i = 0; i < numtasks; i++) {
		if (i % 2 == 0)
			rankEven++;
		else
			rankOdd++;
	}

	if (rank % 2 == 0)
		numtasks = rankEven;
	else
		numtasks = rankOdd;

	N = numtasks;

	if (rank % 2 == 0) {
		if (N % numtasks > rank - rank / 2 )
			iteration = N / numtasks + 1;
		else
			iteration = N / numtasks;
	}
	else {
		if (N % numtasks > numtasks - 1 - (rank - rank / 2 - rank % 2))
			iteration = N / numtasks + 1;
		else
			iteration = N / numtasks;
	}

	if (rank % 2 != 0) {	//reverse to send
		int a = prev;
		prev = next;
		next = a;
	}

	int lastOdd = 0;
	if ((rankOdd + rankEven - 1) % 2 == 0)
		lastOdd = (rankOdd + rankEven - 2);
	else
		lastOdd = (rankOdd + rankEven - 1);

	for (i = 0; i < iteration; i++) {

		if ((i == 0) && ((rank == 0) || (rank == lastOdd))) {
			buf = rand() % 101;
			MPI_Isend(&buf, 1, MPI_INT, next, 99, MPI_COMM_WORLD, request);
			printf("proc %d send sum = %d\n", rank, buf);
			continue;
		}

		MPI_Irecv(&buf, 1, MPI_INT, prev, 99, MPI_COMM_WORLD, request);
		MPI_Wait(request, status);
		recvBuf = buf;
		buf += rand() % 101;
		
		if (rank % 2 == 0) {
			if (i * numtasks + rank - rank / 2 + 1 == N) {
				printf("proc %d recv %d and final even sum = %d\n", rank, recvBuf, buf);
				break;
			}
		}
		else {
			if (i * numtasks + numtasks - 1 - (rank - rank / 2 - rank % 2) + 1 == N) {
				printf("proc %d recv %d final odd sum = %d\n", rank, recvBuf, buf);
				break;
			}
		}

		MPI_Isend(&buf, 1, MPI_INT, next, 99, MPI_COMM_WORLD, request);
		printf("proc %d recv %d and send sum = %d\n", rank, recvBuf, buf);
	}


	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
	return 0;
}
