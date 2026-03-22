#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;              // número que define el tamaño del diamante
    int i, j;           // contadores para los bucles
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    PATRON DIAMANTE (PS3.17)\n");
    printf("================================================\n\n");
    
    printf("Ingrese el numero N (entero positivo): ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N <= 0) {
        printf("\nError: El numero debe ser positivo (mayor a 0).\n");
        return 1;
    }
    
    // ========== PROCESAMIENTO - CONSTRUCCION DEL DIAMANTE ==========
    printf("\n================================================\n");
    printf("Resultado - Patron Diamante:\n");
    printf("================================================\n\n");
    
    // Bucle externo: controla las filas (de 1 a N)
    for (i = 1; i <= N; i++) {
        // Bucle interno ascendente: escribe números de 1 a i
        for (j = 1; j <= i; j++) {
            printf("%d  ", j);
        }
        
        // Bucle interno descendente: escribe números de i-1 a 1
        // (sin repetir el número i del pico)
        for (j = i - 1; j >= 1; j--) {
            printf("%d  ", j);
        }
        
        printf("\n");
    }
    
    // ========== RESULTADO FINAL ==========
    printf("\n================================================\n");
    printf("PATRON DIAMANTE COMPLETADO EXITOSAMENTE\n");
    printf("Total de filas: %d\n", N);
    printf("Estructura: Ascendente + Descendente (sin pico duplicado)\n");
    printf("================================================\n\n");
    
    return 0;
}