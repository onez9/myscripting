#include "mpi.h" 
#include <stdio.h>
#include <stdlib.h>
main (int argc, char **argv)
 {
    int myrank, size, i, j, k, N = 5, choose;
    double t, t1;
    MPI_Init (&argc, &argv);
    MPI_Comm_rank (MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double* A = (double*) malloc(N * sizeof(double));
    double* A1 = (double*) malloc(N * sizeof(double));
    double** B = (double**)malloc(size * sizeof(double*));
    for (i = 0; i < size; i++) {
	B[i] = (double*)malloc(N * sizeof(double));
    }

    srand(myrank);
    for (i = 0; i < N; i++) {
	A1[i] = rand()%10000 / 1000.0;
    }
    for (i = 0; i < size; i++) {
	t = MPI_Wtime();
	t1 = 0;
	while (t1 < 0.5) {
	    t1 = MPI_Wtime() - t;
	}
	if (myrank == i) {
	    printf("\nproc %d generic mas: \n", myrank);
	    for (j = 0; j < N; j++) {
		printf("%f\t", A1[j]);
	    }
	}
    }


for (choose = 1; choose < 6; choose++) {
    t = MPI_Wtime();
    t1 = 0;
    while (t1 < 1.0) {
        t1 = MPI_Wtime() - t;
    }


    if (choose == 1) {   // MPI_Bcast
	if (myrank == 0)
	    printf("\n\nMPI_Bcast\n");
	for (i = 0; i < size; i++) {
	    for (j = 0; j < N; j++) {
		A[j] = A1[j];
	    }

	    MPI_Bcast(A, N, MPI_DOUBLE, i, MPI_COMM_WORLD);
	    for (j = 0; j < N; j++) {
		B[i][j] = A[j];
	    }
	}
    }

    if (choose == 2) {   // MPI_Scatter
	if (myrank == 0)
	printf("\n\nMPI_Scatter\n");
	double* sendbuf = (double*) malloc(size * N * sizeof(double));

	for (i = 0; i < size; i++) {
	    for (j = 0; j < N; j++) {
		A[j] = A1[j];
	    }
	    for (j = 0; j < size; j++) {
		for (k = 0; k < N; k++) {
		    sendbuf[k + j * N] = A[k];
		}
	    }
	    MPI_Scatter(sendbuf, N, MPI_DOUBLE, A, N, MPI_DOUBLE, i, MPI_COMM_WORLD);
	    for (j = 0; j < N; j++) {
		B[i][j] = A[j];
	    }
	}
    }

    if (choose == 3) {   // MPI_Gather
	if (myrank == 0)
	    printf("\n\nMPI_Gather\n");
	double* sendbuf = (double*) malloc(size * N * sizeof(double));
	
	for (i = 0; i < size; i++) {
	    for (j = 0; j < N; j++) {
		A[j] = A1[j];
	    }

	    MPI_Gather(A, N, MPI_DOUBLE, sendbuf, N, MPI_DOUBLE, i, MPI_COMM_WORLD);
	    if (myrank == i) {
		for (j = 0; j < size; j++) {
		    for (k = 0; k < N; k++) {
			B[j][k] = sendbuf[j * N + k];
		    }
		}
	    }
	}
    }

    if (choose == 4) {   // MPI_Allgather
	if (myrank == 0)
	    printf("\n\nMPI_Allgather\n");
	double* recvbuf = (double*) malloc(size * N * sizeof(double));
	for (j = 0; j < N; j++) {
	    A[j] = A1[j];
	}
	MPI_Allgather(A, N, MPI_DOUBLE, recvbuf, N, MPI_DOUBLE, MPI_COMM_WORLD);

	for (j = 0; j < size; j++) {
	    for (k = 0; k < N; k++) {
		B[j][k] = recvbuf[j * N + k];
	    }
	}
    }

    if (choose == 5) {   // MPI_Alltoall
	if (myrank == 0)
	    printf("\n\nMPI_Alltoall\n");
	double* sendbuf = (double*) malloc(size * N * sizeof(double));
	double* recvbuf = (double*) malloc(size * N * sizeof(double));
	for (j = 0; j < N; j++) {
	    A[j] = A1[j];
	}
	for (j = 0; j < size; j++) {
	    for (k = 0; k < N; k++) {
		sendbuf[k + j * N] = A[k];
	    }
	}
	MPI_Alltoall(sendbuf, N, MPI_DOUBLE, recvbuf, N, MPI_DOUBLE, MPI_COMM_WORLD);

	for (j = 0; j < size; j++) {
	    for (k = 0; k < N; k++) {
		B[j][k] = recvbuf[j * N + k];
	    }
	}
    }



    if (myrank == size / 2) {
	printf("proc %d (example)\n", myrank);
	for (i = 0; i < size; i++) {
	    for (j = 0; j < N; j++) {
		printf("%f\t", B[i][j]);
	    }
	printf("\n");
	}
    }


}


    MPI_Finalize();
}