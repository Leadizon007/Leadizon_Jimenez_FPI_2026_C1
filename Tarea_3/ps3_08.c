#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;              // cantidad de valores de Y a procesar
    int i;              // contador para el bucle
    int Y;              // valor de entrada
    double resultado;   // resultado de la función F(Y)
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================\n");
    printf("  FUNCION CONDICIONAL POR RANGOS\n");
    printf("================================\n\n");
    
    printf("Ingrese la cantidad de valores N: ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N <= 0) {
        printf("\nError: N debe ser un numero positivo (mayor a 0).\n");
        return 1;
    }
    
    // ========== PROCESAMIENTO ==========
    printf("\nRangos de evaluacion:\n");
    printf("  Si 0 <= Y <= 15:     F(Y) = Y^2 - 15\n");
    printf("  Si 15 < Y <= 30:     F(Y) = Y^3 - Y^2 + 12\n");
    printf("  Si 30 < Y <= 60:     F(Y) = 4 * Y^3 / Y^2\n");
    printf("  Si Y < 0 o Y > 60:   F(Y) = 0\n\n");
    
    printf("Ingrese los %d valores de Y:\n\n", N);
    
    // Bucle para procesar N valores
    for (i = 1; i <= N; i++) {
        printf("Valor %d: ", i);
        scanf("%d", &Y);
        
        // ========== EVALUACION DE LA FUNCION ==========
        // Evalúa según el rango en que se encuentre Y
        if (Y >= 0 && Y <= 15) {
            // Rango 1: 0 <= Y <= 15
            resultado = (Y * Y) - 15;  // Y^2 - 15
        } else if (Y > 15 && Y <= 30) {
            // Rango 2: 15 < Y <= 30
            resultado = (Y * Y * Y) - (Y * Y) + 12;  // Y^3 - Y^2 + 12
        } else if (Y > 30 && Y <= 60) {
            // Rango 3: 30 < Y <= 60
            resultado = (4.0 * Y * Y * Y) / (Y * Y);  // 4 * Y^3 / Y^2 = 4 * Y
        } else {
            // Fuera de rango: Y < 0 o Y > 60
            resultado = 0;
        }
        
        // Muestra el resultado
        printf("  F(%d) = %.2f\n\n", Y, resultado);
    }
    
    // ========== SALIDA FINAL ==========
    printf("================================\n");
    printf("Procesamiento completado.\n");
    printf("================================\n\n");
    
    return 0;
}