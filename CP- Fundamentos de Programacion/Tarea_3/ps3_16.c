#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;              // número que define el tamaño de la pirámide
    int i, j;           // contadores para los bucles
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    PATRON PIRAMIDAL DOBLE (PS3.16)\n");
    printf("================================================\n\n");
    
    printf("Ingrese el numero N (entero positivo): ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N <= 0) {
        printf("\nError: El numero debe ser positivo (mayor a 0).\n");
        return 1;
    }
    
    // ========== PROCESAMIENTO - PARTE ASCENDENTE ==========
    printf("\n================================================\n");
    printf("Resultado - Patron Piramidal Doble:\n");
    printf("================================================\n\n");
    
    // Bucle externo: controla las filas (de 1 a N)
    for (i = 1; i <= N; i++) {
        // Bucle interno: escribe los números de 1 a i
        for (j = 1; j <= i; j++) {
            printf("%d  ", j);
        }
        printf("\n");
    }
    
    // ========== PROCESAMIENTO - PARTE DESCENDENTE ==========
    // Bucle externo: controla las filas (de N-1 a 1)
    for (i = N - 1; i >= 1; i--) {
        // Bucle interno: escribe los números de 1 a i
        for (j = 1; j <= i; j++) {
            printf("%d  ", j);
        }
        printf("\n");
    }
    
    // ========== RESULTADO FINAL ==========
    printf("\n================================================\n");
    printf("PATRON COMPLETADO EXITOSAMENTE\n");
    printf("Total de filas: %d\n", (2 * N - 1));
    printf("================================================\n\n");
    
    return 0;
}