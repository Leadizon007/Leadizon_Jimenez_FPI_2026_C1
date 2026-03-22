#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;              // número que define el tamaño del patrón
    int i, j;           // contadores para los bucles
    int espacios;       // cantidad de espacios para alineación
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    PATRON ESPEJO HORIZONTAL (PS3.18)\n");
    printf("================================================\n\n");
    
    printf("Ingrese el numero N (entero positivo): ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N <= 0) {
        printf("\nError: El numero debe ser positivo (mayor a 0).\n");
        return 1;
    }
    
    // ========== PROCESAMIENTO - CONSTRUCCION DEL PATRON ==========
    printf("\n================================================\n");
    printf("Resultado - Patron Espejo Horizontal:\n");
    printf("================================================\n\n");
    
    // Bucle externo: controla las filas (de N a 1, descendente)
    for (i = N; i >= 1; i--) {
        // Primera secuencia: números ascendentes de 1 a i
        for (j = 1; j <= i; j++) {
            printf("%d  ", j);
        }
        
        // Calcula espacios de separación entre las dos secuencias
        // Cada número ocupa 3 caracteres (número + 2 espacios)
        espacios = (N - i) * 6;
        for (j = 0; j < espacios; j++) {
            printf(" ");
        }
        
        // Segunda secuencia: números descendentes de i a 1
        for (j = i; j >= 1; j--) {
            printf("%d  ", j);
        }
        
        printf("\n");
    }
    
    // ========== RESULTADO FINAL ==========
    printf("\n================================================\n");
    printf("PATRON ESPEJO HORIZONTAL COMPLETADO EXITOSAMENTE\n");
    printf("Total de filas: %d\n", N);
    printf("Estructura: Ascendente | Espacios | Descendente\n");
    printf("================================================\n\n");
    
    return 0;
}