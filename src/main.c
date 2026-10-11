#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define ROWS_A 2
#define COLS_A 2
#define ROWS_B 2
#define COLS_B 2

// Función para multiplicar dos matrices
void multiplyMatrices(int matA[ROWS_A][COLS_A], int matB[ROWS_B][COLS_B], int res[ROWS_A][COLS_B]) {
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            res[i][j] = 0;
            for (int k = 0; k < COLS_A; k++) {
                res[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

void printMatrix(int rows, int cols, int mat[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}

void app_main(void) {
    vTaskDelay(pdMS_TO_TICKS(2000));
    
    printf("\n--- Operacion de Multiplicacion de Matrices en ESP32 ---\n");

    int A[ROWS_A][COLS_A] = {
        {1, 2},
        {3, 4}
    };

    int B[ROWS_B][COLS_B] = {
        {5, 6},
        {7, 8}
    };

    int resultado[ROWS_A][COLS_B];

    multiplyMatrices(A, B, resultado);

    printf("Matriz A:\n");
    printMatrix(ROWS_A, COLS_A, A);

    printf("Matriz B:\n");
    printMatrix(ROWS_B, COLS_B, B);

    printf("Resultado de la Multiplicacion (A x B):\n");
    printMatrix(ROWS_A, COLS_B, resultado);

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}