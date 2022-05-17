/*
 *  File: p2.c -- C driver for matrice multiplication
 *
 *  Program #2, cssc4820, Dominic Griffith
 *  CS320-01
 *  10/10/21
 *
 */

#include "p2.h"

/* This function reads m, n, and p from the datafile.  
    It then allocates the correct amount of memory required for matrices
    A, B, and C.
    Then matrices A and B are filled from the datafile.
    The values for m, n, and p are passed by reference, and are
    thus filled in by this function
    PARAMETERS in order are:
    int **      matrix A
    int **      matrix B
    int **      matrix C    
    int *       m   The number of rows in matrix A
    int *       n   The number of columns in matrix A and
                    The number of rows in matrix B
    int *       p   The number of columns in matrix B
    char *      The name of the datafile, from the command line
*/
void read_matrices(int **A, int **B, int **C,  int *m, int *n, int *p, char *datafile)
{
	FILE * fptr = fopen(datafile, "r");

    int i;
    int j;

    if(fptr == NULL) {
        perror("Opening datafile");
        exit(1);
    }
    fscanf(fptr, "%d %d %d", m, n, p);

    *A = (int*)malloc((*m)*(*n)*sizeof(int));
    *B = (int*)malloc((*n)*(*p)*sizeof(int));
    *C = (int*)malloc((*m)*(*p)*sizeof(int));

    if((A == NULL) || (B == NULL) || (C == NULL)){
        exit(1);
    }

    for(i = 0; i < (*m); i++) {
        for(j = 0; j < (*n); j++) {
            fscanf(fptr, "%d", (*A + ((i*(*n)) + j)));
        }
    }
    for(i = 0; i < (*n); i++) {
        for(j = 0; j < (*p); j++) {
            fscanf(fptr, "%d", (*B + ((i*(*p)) + j)));
        }
    }

    fclose(fptr);
}


/*  This function prints a matrix.  Rows and columns should be preserved.
    PARAMETERS in order are:
    int *       The matrix to print
    int         The number of rows in the matrix
    int         The number of columns in the matrix
*/    
void print_matrix(int *matrix, int rows, int columns)
{
    int i;
    int j;

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            printf("    %d", *(matrix + ((i*columns)+j)));
        }        
        printf("\n");
    }
}
/*  The two matrices A and B are multiplied, and matrix C contains the
    result.
    PARAMETERS in order are:
    int *       Matrix A
    int *       Matrix B
    int *       Matrix C
    int         m
    int         n
    int         p
*/    
void mult_matrices(int *A, int *B, int *C, int m, int n, int p) 
{
    int i;
    int j;
    int k;

    for(i = 0; i < m; i++){
        for(j = 0; j < p; j++){
            *(C + ((i*p)+j)) = 0;
            for(k = 0; k < n; k++) {
                *(C + ((i*p)+j)) += (*(A + ((i*n)+k))) * (*(B + ((k*p)+j)));
            }
        }
    }
}

int  main(int argc, char ** argv)
{
    int m;
    int n;
    int p;

    int *A;
    int *B;
    int *C;

    if (*(argv+1) == NULL)    {
        perror("Opening datafile");
        exit(1);
    }
    if(argc != 2) {
        printf("Usage:  malloc N\n");
        exit(1);
    }
    
	read_matrices(&A, &B, &C, &m, &n, &p, *(argv + 1));

    printf("Matrix A contents:\n");
    print_matrix(A, m, n);
    printf("\n");
    printf("Matrix B contents:\n");
    print_matrix(B, n, p);
    printf("\n");
    printf("Matrix A * B is:\n");
    mult_matrices(A, B, C, m, n, p);
    print_matrix(C, m, p);
    printf("\n");

	return 0;
}
