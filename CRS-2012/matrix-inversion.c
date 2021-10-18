// Matrix Inverse Using Adjoint Method

#include<stdio.h>

#define MAX_MATRIX_DIMENSION 10

struct Matrix {
    float cell[MAX_MATRIX_DIMENSION][MAX_MATRIX_DIMENSION];
    int dimension;
};

void print(struct Matrix matrix) {
    printf("\nMatrix of %d dimension:\n", matrix.dimension);
    for(int r = 0; r < matrix.dimension; r++) {
        for(int c = 0; c < matrix.dimension; c++) {
            printf("%f\t", matrix.cell[r][c]);
        }
        printf("\n");
    }
}

struct Matrix getMinorMatrix(struct Matrix matrix, int excludeRow, int excludeColumn) {
    struct Matrix minor;
    minor.dimension = matrix.dimension - 1;

    for(int r = 0; r < minor.dimension; r++) {
        for(int c = 0; c < minor.dimension; c++) {
            minor.cell[r][c] = matrix.cell[r + (r >= excludeRow ? 1 : 0)][c + (c >= excludeColumn ? 1 : 0)];
        }
    }

    return minor;
}

float determinant(struct Matrix matrix) {
    if(matrix.dimension == 1) {
        return matrix.cell[0][0];
    } else if(matrix.dimension == 2) {
        return matrix.cell[0][0] * matrix.cell[1][1] - matrix.cell[1][0] * matrix.cell[0][1];
    } else {
        float det = 0;
        for(int i = 0; i < matrix.dimension; i++) {
            struct Matrix minor = getMinorMatrix(matrix, 0, i);
            float minorDet = matrix.cell[0][i] * determinant(minor);
            if(i % 2 == 0) {
                det = det + minorDet;
            } else {
                det = det - minorDet;
            }
        }
        return det;
    }
}

struct Matrix getCofactorMatrix(struct Matrix matrix) {
    struct Matrix cofactor;
    cofactor.dimension = matrix.dimension;

    for(int r = 0; r < cofactor.dimension; r++) {
        for(int c = 0; c < cofactor.dimension; c++) {
            struct Matrix minor = getMinorMatrix(matrix, r, c);
            float minorDet = matrix.cell[r][c] * determinant(minor);
            int sign = ((r+c) % 2 == 0 ? 1 : -1);
            cofactor.cell[r][c] = sign * minorDet;
        }
    }
    return cofactor;
}

int main() {
    struct Matrix matrix;

    printf("Enter the dimension of the square matrix: ");
	scanf("%d", &matrix.dimension);

    for(int r = 0; r < matrix.dimension; r++) {
        for(int c = 0; c < matrix.dimension; c++) {
            printf("Enter Row %d Column %d entry: ", r, c);
        	scanf("%f", &matrix.cell[r][c]);
        }
    }

    print(matrix);

    float det = determinant(matrix);
    printf("Determinant: %f", det);

    struct Matrix cofactor = getCofactorMatrix(matrix);
    for(int r = 0; r < cofactor.dimension; r++) {
        for(int c = 0; c < cofactor.dimension; c++) {
            cofactor.cell[r][c] = cofactor.cell[r][c] / det;
        }
    }
    printf("\nInverse Matrix");
    print(cofactor);
}