#include "mpi.h" 
#include <stdio.h>
#include <stdlib.h>
main (int argc, char **argv)
 {
    int myrank, size, i, j, k, l, choose;
    double t, t1;
    MPI_Init (&argc, &argv);
    MPI_Comm_rank (MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    srand(myrank);
    int N = 5;
    double* sum = (double*) malloc(size * sizeof(double));
    double* sum1 = (double*) malloc(size * sizeof(double));
    double** A = (double**)malloc(size * sizeof(double*));
    for (i = 0; i < size; i++) {
	A[i] = (double*)malloc(N * sizeof(double));
    }
    double** A1 = (double**)malloc(size * sizeof(double*));
    for (i = 0; i < size; i++) {
	A1[i] = (double*)malloc(N * sizeof(double));
    }



    for (i = 0; i < size; i++) {
	for (j = 0; j < N; j++) {
	    A1[i][j] = rand()%10000 / 1000.0;
	}
	sum[i] = 0;
    }
    for (i = 0; i < size; i++) {
	for (j = 0; j < N; j++) {
	    sum[i] += A1[i][j];
	}
    }
    for (i = 0; i < size; i++) {
	t = MPI_Wtime();
	t1 = 0;
	while (t1 < 0.75) {
	    t1 = MPI_Wtime() - t;
	}
	if (myrank == i) {
	    printf("\nproc %d generic mas with sum's:\n", myrank);
	    for (j = 0; j < size; j++) {
		printf("%f\t", sum[j]);
	    }
	}
    }

for (choose = 1; choose < 5; choose++) {

    t = MPI_Wtime();
    t1 = 0;
    while (t1 < 1.0) {
	t1 = MPI_Wtime() - t;
    }

    if (choose == 1) {   // MPI_Scatter()
	if (myrank == 0)
	    printf("\n\nMPI_Scatter\n");
	double* sendbuf = (double*) malloc(size * N * sizeof(double));
	for (i = 0; i < size; i++)
	    sum1[i] = 0;

	for (i = 0; i < size; i++) {
	    for (j = 0; j < size; j++) {
		for (k = 0; k < N; k++) {
		    A[j][k] = A1[j][k];
		}
	    }
	    for (j = 0; j < size; j++) {
		for (k = 0; k < N; k++) {
		    sendbuf[k + j * N] = A[j][k];
		}
	    }
	    MPI_Scatter(sendbuf, N, MPI_DOUBLE, A[i], N, MPI_DOUBLE, i, MPI_COMM_WORLD);
	    for (j = 0; j < N; j++) {
		sum1[i] += A[i][j];
	    }
	}
    }

    if (choose == 2) {   // MPI_Gather()
	if (myrank == 0) {
	    printf("\n\nMPI_Gather\n");
	}
	double* sendbuf = (double*) malloc(size * N * sizeof(double));
	for (i = 0; i < size; i++)
	    sum1[i] = 0;

	for (i = 0; i < size; i++) {
	    for (j = 0; j < size; j++) {
		for (k = 0; k < N; k++) {
		    A[j][k] = A1[j][k];
		}
	    }

	    MPI_Gather(A[i], N, MPI_DOUBLE, sendbuf, N, MPI_DOUBLE, i, MPI_COMM_WORLD);
	    if (myrank == i) {
		for (j = 0; j < size; j++) {
		    for (k = 0; k < N; k++) {
			sum1[j] += sendbuf[j * N + k];
		    }
		}
	    }
	}
    }

    if (choose == 3) {   // MPI_Allgather()
	if (myrank == 0) {
	    printf("\n\nMPI_Allgather\n");
	}
	double* recvbuf = (double*) malloc(size * N * sizeof(double));
	
	for (j = 0; j < size; j++) {
	    for (k = 0; k < N; k++) {
		A[j][k] = A1[j][k];
	    }
	    sum1[j] = 0;
	}
	for (i = 0; i < size; i++) {
	    MPI_Allgather(A[i], N, MPI_DOUBLE, recvbuf, N, MPI_DOUBLE, MPI_COMM_WORLD);
	    if (myrank == i) {
		for (j = 0; j < size; j++) {
		    for (k = 0; k < N; k++) {
			sum1[j] += recvbuf[j * N + k];
		    }
		}
	    }
	}
    }

    if (choose == 4) {   // MPI_Alltoall
	if (myrank == 0) {
	    printf("\n\nMPI_Alltoall\n");
	}
	double* sendbuf = (double*) malloc(size * N * sizeof(double));
	double* recvbuf = (double*) malloc(size * N * sizeof(double));
	for (i = 0; i < size; i++) {
	    for (j = 0; j < N; j++) {
		A[i][j] = A1[i][j];
	    }
	    sum1[i] = 0;
	}
	for (j = 0; j < size; j++) {
	    for (k = 0; k < N; k++) {
		sendbuf[k + j * N] = A[j][k];
	    }
	}
	MPI_Alltoall(sendbuf, N, MPI_DOUBLE, recvbuf, N, MPI_DOUBLE, MPI_COMM_WORLD);

	for (j = 0; j < size; j++) {
	    for (k = 0; k < N; k++) {
		sum1[j] += recvbuf[j * N + k];
	    }
	}
    }



    if (myrank == size - 1) {
	printf("proc %d sum's (example)\n", myrank);
	for (i = 0; i < size; i++) {
	    printf("%f\t", sum1[i]);
	}
	printf("\n");
    }
}

    MPI_Finalize();
}