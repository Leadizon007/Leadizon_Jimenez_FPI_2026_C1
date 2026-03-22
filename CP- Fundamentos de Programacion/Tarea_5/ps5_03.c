#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    long long FIB[100];         // arreglo para almacenar 100 numeros de Fibonacci
    int i;                      // contador para los bucles
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    PRIMEROS 100 NUMEROS DE FIBONACCI (PS5.3)\n");
    printf("================================================\n\n");
    
    printf("Generando los primeros 100 numeros de Fibonacci...\n\n");
    
    // ========== PROCESAMIENTO - GENERACION DE FIBONACCI ==========
    // Los dos primeros numeros de Fibonacci son 1 y 1
    FIB[0] = 1;
    FIB[1] = 1;
    
    // Calcular el resto de los numeros
    // Cada numero es la suma de los dos anteriores
    for (i = 2; i < 100; i++) {
        FIB[i] = FIB[i - 1] + FIB[i - 2];
    }
    
    // ========== RESULTADO FINAL - IMPRESION DEL ARREGLO ==========
    printf("================================================\n");
    printf("ARREGLO DE FIBONACCI\n");
    printf("================================================\n\n");
    
    // Imprimir todos los 100 numeros de Fibonacci
    for (i = 0; i < 100; i++) {
        printf("FIB[%3d] = %18lld\n", i, FIB[i]);
    }
    
    // ========== ESTADISTICAS ==========
    printf("\n================================================\n");
    printf("INFORMACION DEL ARREGLO\n");
    printf("================================================\n\n");
    
    printf("Total de elementos:        100\n");
    printf("Primer elemento (FIB[0]):  %lld\n", FIB[0]);
    printf("Ultimo elemento (FIB[99]): %lld\n\n", FIB[99]);
    
    printf("================================================\n\n");
    
    return 0;
}