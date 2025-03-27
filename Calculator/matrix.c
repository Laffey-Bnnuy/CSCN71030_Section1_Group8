#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double mat[4][3][3] = { 0 };
bool assign[4] = { false };
int mat_size[4][2] = { 0 };

double** add_sub_calculate(char ch, double operand1[4][3][3], double operand2[4][3][3], int m, int n, int mat_1, int mat_2) {
    double** result;
    result = (double**)malloc(mat_size[mat_1][0] * sizeof(double*));
    for (int i = 0; i < mat_size[mat_1][0]; i++) {
        result[i] = (double*)malloc(mat_size[mat_1][1] * sizeof(result[0]));
    }

    switch (ch) {
    case '+':
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = operand1[mat_1][i][j] + operand2[mat_2][i][j];
            }
        }
        break;
    case '-':
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = operand1[mat_1][i][j] - operand2[mat_2][i][j];
            }
        }
        break;
    case '*': {
        
        int rowsA = mat_size[mat_1][0];
        int colsA = mat_size[mat_1][1];
        int rowsB = mat_size[mat_2][0];
        int colsB = mat_size[mat_2][1];

        if (colsA != rowsB) {
            printf("Matrix dimensions do not allow multiplication.\n");
            return NULL;
        }
        result = (double**)malloc(rowsA * sizeof(double*));
        for (int i = 0; i < rowsA; i++) {
            result[i] = (double*)malloc(colsB * sizeof(double));
        }

        for (int i = 0; i < rowsA; ++i) {
            for (int j = 0; j < colsB; ++j) {
                result[i][j] = 0;
                for (int k = 0; k < colsA; ++k) {
                    result[i][j] += operand1[mat_1][i][k] * operand2[mat_2][k][j];
                }
            }
        }
        break;
    }
    }

    return result;
}

void matrix() {
    int mat_choice, M, N;
    printf("-------------------------\n");
    printf("1. matA           2. matB\n");
    printf("3. matC           4. matD\n");
    printf("0. Exit          \n");
    printf("Enter your matrix choice: ");
    int item = scanf_s("%d", &mat_choice);
    if (item != 1 || (mat_choice > 4 || mat_choice < 0)) {
        printf("Not a number or input > 4 or < 1");
        return;
    }
    if (mat_choice == 0) {
        return;
    }
    printf("Enter your matrix dimension (max is 3): ");
    scanf_s("%d %d", &M, &N);
    printf("Enter your matrix: ");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf_s("%lf", &mat[mat_choice - 1][i][j]);
        }
    }
    assign[mat_choice - 1] = true;
    mat_size[mat_choice - 1][0] = M;
    mat_size[mat_choice - 1][1] = N;
}

void matrix_operations() {
    printf("Enter your operation (+ - * ): ");
    char input;

    input = getchar();
    while (getchar() != '\n');
    printf("Enter your two choice of matrix (1-4): ");
    int mat_1, mat_2;
    scanf_s("%d %d", &mat_1, &mat_2);
    if (!assign[mat_1 - 1] || !assign[mat_2 - 1]) {
        printf("You need to define the matrix first\n");
        return;
    }
    if (mat_size[mat_1 - 1][0] != mat_size[mat_2 - 1][0] && input != '*') {
        printf("Two matrices must be the same size for addition or subtraction\n");
        return;
    }
    double** result;
    result = add_sub_calculate(input, mat, mat, mat_size[mat_1 - 1][0], mat_size[mat_1 - 1][1], mat_1 - 1, mat_2 - 1);

    if (result == NULL) {
        return;
    }

    printf("Resultant matrix:\n");
    for (int i = 0; i < mat_size[mat_1 - 1][0]; i++) {
        for (int j = 0; j < mat_size[mat_2 - 1][1]; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory for the result
    for (int i = 0; i < mat_size[mat_1 - 1][0]; i++) {
        free(result[i]);
    }
    free(result);
}

double determinant() {
    printf("Enter your choice of matrix (1-4): ");
    int mat_1;
    scanf_s("%d", &mat_1);
    if (!assign[mat_1 - 1]) {
        printf("You need to define the matrix first\n");
        return;
    }
    if (mat_size[mat_1 - 1][0] != mat_size[mat_1 - 1][1]) {
        printf("Must be a square matrix for determinant\n");
        return;
    }

    
   

    // Base case for 1x1 matrix
    if (mat_size[mat_1 - 1][0] == 1) {
        return mat[mat_1-1][0][0];
    }

    // Base case for 2x2 matrix
    if (mat_size[mat_1 - 1][0] == 2) {
        return mat[mat_1 - 1][0][0] * mat[mat_1 - 1][1][1] - mat[mat_1 - 1][0][1] * mat[mat_1 - 1][1][0];
    }
    double det = 0;
    if (mat_size[mat_1 - 1][0] == 3) {
        for (int i = 0; i < 3; i++) {
            det = det + (mat[mat_1 - 1][0][i] * (mat[mat_1 - 1][1][(i + 1) % 3] * mat[mat_1 - 1][2][(i + 2) % 3] - mat[mat_1 - 1][1][(i + 2) % 3] * mat[mat_1 - 1][2][(i + 1) % 3]));
        } 
        return det;
    }

   
}

void matrix_main() {
    int mat_choice = 0;
    bool cont = true;

    while (cont) {
        printf("\n");
        printf("1. Define matrix  2. Perform + - *\n");
        printf("3. Determinant    \n");
        printf("Enter your matrix choice: ");
        int item = scanf_s("%d", &mat_choice);
        while (getchar() != '\n');
        printf("\n");
        switch (mat_choice) {
        case 1:
            matrix();
            break;
        case 2:
            matrix_operations();
            break; 
        case 3:
            printf("Determinant: %lf\n",determinant());
            break;
        case 0:
            return;
    }
        }
       
}
void save_matrices_to_file() {
    FILE* file = fopen("matrices.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    for (int i = 0; i < 4; i++) {
        fprintf(file, "%d ", i);
        fprintf(file, "%d ", mat_size[i][0]);
        fprintf(file, "%d\n", mat_size[i][1]);
           for (int j = 0; j < mat_size[i][0]; j++) {
                for (int k = 0; k < mat_size[i][1]; k++) {
                    fprintf(file, "%lf ", mat[i][j][k]);
                }
                fprintf(file, "\n");
            }
            fprintf(file, "\n");
        }
    

    fclose(file);
    printf("Matrices saved to matrices.txt\n");
}

void load_matrices_from_file() {
    FILE* file = fopen("matrices.txt", "r");
    if (file == NULL) {
        printf("Error opening file for loading.\n");
        return;
    }
    int M = 0, N = 0;

    for (int i = 0; i < 4; i++) {
        fscanf_s(file, "%d", &i);
        fscanf_s(file, "%d", &M);
        fscanf_s(file, "%d\n", &N);
        mat_size[i][0] = M;
        mat_size[i][1] = N;
        if (M > 0 || N > 0) {
            assign[i] = 1;
        }
        else assign[i] = 0;
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                fscanf_s(file, "%lf", &mat[i][j][k]);
            }
         
        }
        
    }

    fclose(file);
    printf("Matrices load from matrices.txt\n");
}

