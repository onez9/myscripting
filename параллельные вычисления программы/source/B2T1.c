#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#pragma warning (disable: 4996)

int main(int argc, char** argv)
{
	int rank, numtasks, i, j, next, prev, iteration, buf, N;

	N = atoi(argv[1]);

	MPI_Status* status = (MPI_Status*)malloc(sizeof(MPI_Status));

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

	srand(rank);
	
	if (rank < numtasks - 1) {
		next = rank + 1;
		if (rank == 0)
			prev = numtasks - 1;
		else
			prev = rank - 1;
	}
	else {
		next = 0;
		prev = rank - 1;
	}

	if (N % numtasks > rank) {
		iteration = N / numtasks + 1;
	}
	else {
		iteration = N / numtasks;
	}

	for (i = 0; i < iteration; i++) {
		if ((i == 0) && (rank == 0)) {
			buf = rand() % 101;
			MPI_Send(&buf, 1, MPI_INT, next, 99, MPI_COMM_WORLD);
			printf("proc %d send %d sum = %d\n", rank, next, buf);
			continue;
		}
		MPI_Recv(&buf, 1, MPI_INT, prev, 99, MPI_COMM_WORLD, status);
		printf("proc %d recv %d sum = %d\n", rank, prev, buf);
		buf += rand() % 101;
		if (i*numtasks + rank + 1 == N) {
			printf("proc %d final sum = %d\n", rank, buf);
			break;
		}
		MPI_Send(&buf, 1, MPI_INT, next, 99, MPI_COMM_WORLD);
		printf("proc %d send %d sum = %d\n", rank, next, buf);
	}

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
	return 0;
}
