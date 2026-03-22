#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;      // número del cual queremos la tabla de multiplicar
    int i;      // contador para el bucle de 1 a 10
    int resultado;  // resultado de la multiplicación
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================\n");
    printf("    TABLA DE MULTIPLICAR\n");
    printf("================================\n\n");
    
    printf("Ingrese un numero entero positivo N: ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N <= 0) {
        printf("\nError: El numero debe ser positivo (mayor a 0).\n");
        printf("Por favor, intente nuevamente.\n");
        return 1;  // Termina el programa con error
    }
    
    // ========== PROCESAMIENTO Y SALIDA DE RESULTADOS ==========
    printf("\n================================\n");
    printf("Tabla de multiplicar del %d\n", N);
    printf("================================\n");
    
    // Bucle que va desde 1 hasta 10
    for (i = 1; i <= 10; i++) {
        resultado = N * i;  // Calcula la multiplicación
        printf("%d x %2d = %3d\n", N, i, resultado);
    }
    
    printf("================================\n\n");
    
    return 0;  // Termina el programa correctamente
}