#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
double mat[4][3][3] = {0};
void matrix() {
	int mat_choice, M, N;
	printf("1. matA           2. matB\n");
	printf("3. matC           4. matD\n");
	printf("Enter your matrix choice: ");
	int item = scanf_s("%d", &mat_choice);
	if (item != 1 || (mat_choice > 4||mat_choice<1)) {
		printf("Not a number or input > 4 or < 1");
		return;
	}
	printf("Enter your matrix dimention(max is 3): ");
	scanf_s("%d %d", &M, &N);
	printf("Enter your matrix: ");
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%df",&mat[mat_choice-1][i][j]);
		}
	}
	
}