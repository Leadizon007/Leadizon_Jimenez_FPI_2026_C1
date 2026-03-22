#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;          // número de términos de la serie
    int i;          // contador para el bucle
    double suma;    // suma acumulada de la serie (usamos double para decimales)
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================\n");
    printf("      SERIE DE FRACCIONES\n");
    printf("================================\n\n");
    
    printf("Ingrese la cantidad de terminos N: ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N <= 0) {
        printf("\nError: N debe ser un numero positivo (mayor a 0).\n");
        printf("Por favor, intente nuevamente.\n");
        return 1;  // Termina el programa con error
    }
    
    // ========== PROCESAMIENTO ==========
    // Inicializamos la suma en cero
    suma = 0.0;
    
    printf("\n================================\n");
    printf("Calculando la serie:\n");
    printf("================================\n\n");
    
    // Bucle que suma los términos: 1/1 + 1/2 + 1/3 + ... + 1/N
    for (i = 1; i <= N; i++) {
        suma = suma + (1.0 / i);  // Sumamos el término 1/i
        printf("Termino %d: 1/%d = %.4f  |  Suma parcial: %.6f\n", i, i, (1.0 / i), suma);
    }
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================\n");
    printf("Cantidad de terminos (N): %d\n", N);
    printf("Serie: 1/1 + 1/2 + 1/3 + ... + 1/%d\n", N);
    printf("Suma total: %.6f\n", suma);
    printf("================================\n\n");
    
    return 0;  // Termina el programa correctamente
}

