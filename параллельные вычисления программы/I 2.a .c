#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"
#include <time.h>
#include <math.h>

#pragma warning (disable: 4996)

int main(int argc, char** argv)
{
	int rank, numtasks, i, next, prev, iteration, buf, N = 0;

	/*if(argc > 1)
		N = atoi(argv[1]);*/
	N = 5;

	MPI_Status* status = (MPI_Status*)malloc(sizeof(MPI_Status));

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);


	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
	return 0;
}