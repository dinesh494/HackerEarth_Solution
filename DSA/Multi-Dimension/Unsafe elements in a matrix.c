#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
/* Get the next continuous group of digits as an int */
static int parse_int()
{
	int n = 0;
	char c;
	do {
		c = getchar_unlocked();
	} while(c < '0' || c > '9');
 
	while (c >= '0' && c <= '9') {
		n *= 10;
		n += c - '0';
		c = getchar_unlocked();
	}
	return n;
}
 
int main()
{
	/* Get the number of testcases */
	int num_cases;
	num_cases = parse_int();
 
	/* For each testcase */
	for (int test = 0; test < num_cases; test++) {
		size_t N, M, matr_len;
		int min = INT_MAX, max = INT_MIN;
		size_t safe_rows, safe_cols, total_vals;
		int row_unsafe = 0;
 
		/* Get matrix dimensions */
		N = (size_t)parse_int();
		M = (size_t)parse_int();
 
		/* Set safe rows to all rows, initially */
		safe_rows = N;
		
		/* Set safe columns to 0, initially */
		safe_cols = 0;
 
#ifdef MATRIX_MALLOC
		int *matrix, *unsafe_cols;
		/* Allocate matrix, plus extra row to record unsafe columns */
		matr_len = (N + 1) * M * sizeof(int);
		matrix = (int *)malloc(matr_len);
		if (matrix == NULL)
			return -1;
 
		/* Unsafe columns recorded in a row at the end */
		unsafe_cols = matrix + (N * M);
#else
		/* Abandon malloc in favour of VLAs (grumble grumble security) */
		int matrix[N * M];
		int unsafe_cols[M];
#endif
 
		/* Zero the unsafe columns row */
		for (int i = 0; i < M; i++) {
			unsafe_cols[i] = 0;
		}
 
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				/* Get value from input */
				matrix[M*j + i] = parse_int();
 
				/* Update min and max */
				if (matrix[M*j + i] < min)
					min = matrix[M*j + i];
				if (matrix[M*j + i] > max)
					max = matrix[M*j + i];
			}
 
		}
 
		/* Run through and process max and min values */
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				/* Record min or max value */
				if (matrix[M*j + i] == min || matrix[M*j + i] == max) {
					unsafe_cols[i] = 1;
					row_unsafe = 1;
				}
			}
 
			/* If row is unsafe, reduce the total rows */
			if (row_unsafe != 0) {
				safe_rows--;
			}
			row_unsafe = 0;
		}
 
		/* Walk through and record safe columns */
		for (int i = 0; i < M; i++) {
			if (unsafe_cols[i] == 0)
				safe_cols++;
		}
 
		/* Total up the safe values */
		total_vals = safe_rows * safe_cols;
		printf("%zu\n", total_vals);
 
/* See above */
#ifdef MATRIX_MALLOC
		/* Free the matrix for the next round */
		free(matrix);
		matrix = NULL;
#endif
	}
}