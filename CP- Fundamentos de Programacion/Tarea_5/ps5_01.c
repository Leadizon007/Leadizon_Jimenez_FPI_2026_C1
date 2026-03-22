#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;                      // número de elementos del arreglo
    int VEC[100];               // arreglo unidimensional de hasta 100 elementos
    int i;                      // contador para los bucles
    int positivos = 0;          // contador de números positivos
    int negativos = 0;          // contador de números negativos
    int nulos = 0;              // contador de números nulos (ceros)
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    ANALISIS DE ARREGLO UNIDIMENSIONAL (PS5.1)\n");
    printf("================================================\n\n");
    
    printf("Ingrese la cantidad de elementos (1-100): ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N < 1 || N > 100) {
        printf("\nError: N debe estar entre 1 y 100.\n");
        return 1;
    }
    
    // ========== ENTRADA DEL ARREGLO ==========
    printf("\n================================================\n");
    printf("Ingrese los %d elementos del arreglo:\n", N);
    printf("================================================\n\n");
    
    // Bucle para leer los elementos del arreglo
    for (i = 0; i < N; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &VEC[i]);
    }
    
    // ========== PROCESAMIENTO - CLASIFICACION DE ELEMENTOS ==========
    printf("\n================================================\n");
    printf("Analizando los elementos del arreglo...\n");
    printf("================================================\n\n");
    
    // Bucle para analizar cada elemento
    for (i = 0; i < N; i++) {
        if (VEC[i] > 0) {
            positivos++;
        } else if (VEC[i] < 0) {
            negativos++;
        } else {
            nulos++;
        }
    }
    
    // ========== RESULTADO FINAL ==========
    printf("================================================\n");
    printf("RESULTADO DEL ANALISIS\n");
    printf("================================================\n\n");
    
    printf("Total de elementos: %d\n\n", N);
    
    printf("Numeros POSITIVOS:  %d\n", positivos);
    printf("Numeros NEGATIVOS:  %d\n", negativos);
    printf("Numeros NULOS:      %d\n\n", nulos);
    
    // ========== PORCENTAJES ==========
    printf("================================================\n");
    printf("PORCENTAJES\n");
    printf("================================================\n\n");
    
    printf("Positivos:  %.2f%%\n", (positivos * 100.0) / N);
    printf("Negativos:  %.2f%%\n", (negativos * 100.0) / N);
    printf("Nulos:      %.2f%%\n\n", (nulos * 100.0) / N);
    
    printf("================================================\n\n");
    
    return 0;
}