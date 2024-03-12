#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
#include <memory.h>
#include <mpi.h>

double random() {
    return rand() / (double)RAND_MAX;
}

void fill_with_randoms(double* nums, int size) {
    for (int i = 0; i < size; i++) {
        nums[i] = random();
    }
}

double sum_dbls(double* nums, int size) {
    double acc = 0.0;
    for (int i = 0; i < size; i++) {
        acc += nums[i];
    }
    return acc;
}

void run_bcast(int rank, int numTasks, int n) {
    double* nums = calloc(n, sizeof(double));
    if (rank == 0) {
        fill_with_randoms(nums, n);
        printf("[bcast]     proc 0 sent   sum=%f\n", sum_dbls(nums, n));
    }

    MPI_Bcast(nums, n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    if (rank > 0) {
        printf("[bcast]     proc %d recved sum=%f\n", rank, sum_dbls(nums, n));
    }
    free(nums);
}

void run_scatter(int rank, int numTasks, int n) {
    double* nums_cs_times = calloc(n * numTasks, sizeof(double));
    if (rank == 0) {
        fill_with_randoms(nums_cs_times, n);
        for (int i = 1; i < numTasks; i++) {
            memcpy(nums_cs_times + i * n, nums_cs_times, n * sizeof(double));
        }
        printf("[scatter]   proc 0 sent   sum=%f\n", sum_dbls(nums_cs_times, n));
    }

    MPI_Scatter(nums_cs_times, n, MPI_DOUBLE, nums_cs_times, n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    if (rank > 0) {
        printf("[scatter]   proc %d recved sum=%f\n", rank, sum_dbls(nums_cs_times, n));
    }
    free(nums_cs_times);
}

void run_gather(int rank, int numTasks, int n) {
    double* nums_cs_times = calloc(n * numTasks, sizeof(double));
    if (rank == 0) {
        fill_with_randoms(nums_cs_times, n);
        printf("[gather]    proc 0 sent   sum=%f\n", sum_dbls(nums_cs_times, n));
    }

    for (int i = 1; i < numTasks; i++) {
        MPI_Gather(nums_cs_times, n, MPI_DOUBLE, nums_cs_times, n, MPI_DOUBLE, i, MPI_COMM_WORLD);
    }

    if (rank > 0) {
        printf("[gather]    proc %d recved sum=%f\n", rank, sum_dbls(nums_cs_times, n));
    }
    free(nums_cs_times);
}

void run_allgather(int rank, int numTasks, int n) {
    double* nums = calloc(n, sizeof(double));
    if (rank == 0) {
        fill_with_randoms(nums, n);
        printf("[allgather] proc 0 sent   sum=%f\n", sum_dbls(nums, n));
    }

    double* buf = calloc(n * numTasks, sizeof(double));
    MPI_Allgather(nums, n, MPI_DOUBLE, buf, n, MPI_DOUBLE, MPI_COMM_WORLD);

    if (rank > 0) {
        printf("[allgather] proc %d recved sum=%f\n", rank, sum_dbls(buf, n));
    }
    free(nums);
    free(buf);
}

void run_alltoall(int rank, int numTasks, int n) {
    double* nums_cs_times = calloc(n * numTasks, sizeof(double));
    if (rank == 0) {
        fill_with_randoms(nums_cs_times, n);
        for (int i = 1; i < numTasks; i++) {
            memcpy(nums_cs_times + i * n, nums_cs_times, n * sizeof(double));
        }
        printf("[alltoall]  proc 0 sent   sum=%f\n", sum_dbls(nums_cs_times, n));
    }

    double* buf = calloc(n * numTasks, sizeof(double));
    MPI_Alltoall(nums_cs_times, n, MPI_DOUBLE, buf, n, MPI_DOUBLE, MPI_COMM_WORLD);

    if (rank > 0) {
        printf("[alltoall]  proc %d recved sum=%f\n", rank, sum_dbls(buf, n));
    }
    free(nums_cs_times);
    free(buf);
}

int main(int argc, char** argv) {
    int n = 100;

    int rank, numTasks;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numTasks);

    srand(1);
    run_bcast(rank, numTasks, n);

    srand(1);
    run_scatter(rank, numTasks, n);

    srand(1);
    run_gather(rank, numTasks, n);

    srand(1);
    run_allgather(rank, numTasks, n);

    srand(1);
    run_alltoall(rank, numTasks, n);

    MPI_Finalize();
    return 0;
}
