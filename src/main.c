#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define ROWS 2
#define COLS 2

// Función para restar dos matrices
void subtractMatrices(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int res[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Función para imprimir una matriz en la consola serial
void printMatrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}

void app_main(void) {
    vTaskDelay(pdMS_TO_TICKS(2000));
    
    printf("\n--- Operacion de Resta de Matrices en ESP32 ---\n");

    int A[ROWS][COLS] = {
        {10, 20},
        {30, 40}
    };

    int B[ROWS][COLS] = {
        {2, 4},
        {6, 8}
    };

    int resultado[ROWS][COLS];

    subtractMatrices(A, B, resultado);

    printf("Matriz A:\n");
    printMatrix(A);

    printf("Matriz B:\n");
    printMatrix(B);

    printf("Resultado de la Resta (A - B):\n");
    printMatrix(resultado);

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}