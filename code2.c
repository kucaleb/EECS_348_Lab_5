#include <stdio.h>
#define SIZE 5

// Takes in two 2D arrays and returns the sum as a pointer to a 2D array
int (*addMatrices(int matrixA[SIZE][SIZE], int matrixB[SIZE][SIZE]))[SIZE] {
    static int sum[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j]; // adds the indeces together
        }
    }
    return sum;
}

// Takes in two 2D arrays and returns the product as a pointer to a 2D array
int (*multiplyMatrices(int matrixA[SIZE][SIZE], int matrixB[SIZE][SIZE]))[SIZE] {
    static int product[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            int sum;
            for (int k = 0; k < SIZE; k++) {
                sum += matrixA[i][k] * matrixB[k][i]; // adds up the product of the indeces
            }
            product[i][j] = sum;
        }
    }
    return product;
}

// Takes in a 2D array and returns the transpose as a pointer to a 2D array
int (*transposeMatrix(int matrix[SIZE][SIZE]))[SIZE] {
    static int matrixT[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrixT[i][j] = matrix[j][i]; // sets the new matrix index equal to the flipped indeces
        }
    }
    return matrixT;
}

// Takes in a 2D array and prints it
void printMatrix(int matrix[SIZE][SIZE]) {   
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    printf("matrix 1:\n");
    printMatrix(m1);

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    printf("\nmatrix 2:\n");
    printMatrix(m2);

    int (*m3)[SIZE] = addMatrices(m1, m2); // sets m3 equal to the pointer of a 1D array with SIZE elements, which is what addMatrices returns
    printf("\nmatrix 3:\n");
    printMatrix(m3);

    // Makes sure no bad inputs are given
    if (sizeof(m1[0]) / sizeof(m1[0][0]) != sizeof(m2[0]) / sizeof(m2[0][0])) {
        printf("You cannot multiply the matrices\n");
    } else {
        int (*m4)[SIZE] = multiplyMatrices(m1, m2); // sets m4 equal to the pointer of a 1D array with SIZE elements, which is what addMatrices returns
        printf("\nmatrix 4:\n");
        printMatrix(m4);
    }

    int (*m5)[SIZE] = transposeMatrix(m1); // sets m5 equal to the pointer of a 1D array with SIZE elements, which is what addMatrices returns
    printf("\nmatrix 5:\n");
    printMatrix(m5);
}