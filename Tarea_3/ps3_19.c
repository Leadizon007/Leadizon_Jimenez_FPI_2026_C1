#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int fila;           // controla el número de filas (1 a 9)
    int columna;        // controla las columnas dentro de cada fila
    int numero;         // número a mostrar (módulo 10)
    int inicio;         // número inicial de cada fila
    int distancia;      // distancia desde el inicio
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    PATRON NUMERICO PIRAMIDAL (PS3.19)\n");
    printf("================================================\n\n");
    
    printf("Este programa genera una piramide de 9 filas\n");
    printf("con patron numerico especial (módulo 10).\n\n");
    
    // ========== PROCESAMIENTO ==========
    printf("================================================\n");
    printf("Resultado - Patron Numerico Piramidal:\n");
    printf("================================================\n\n");
    
    // Bucle externo: controla las filas (de 1 a 9)
    for (fila = 1; fila <= 9; fila++) {
        
        // Número inicial de la fila es igual al número de fila
        inicio = fila;
        
        // Primera parte: números ascendentes desde inicio
        // Se generan (2*fila - 1) números en total
        // Primera mitad: ascendente (fila números)
        for (columna = 0; columna < fila; columna++) {
            numero = (inicio + columna) % 10;  // módulo 10 para obtener un dígito
            printf("%d ", numero);
        }
        
        // Segunda mitad: descendente (fila-1 números)
        // Comienza desde (inicio + fila - 2) hacia atrás
        for (columna = fila - 2; columna >= 0; columna--) {
            numero = (inicio + columna) % 10;  // módulo 10 para obtener un dígito
            printf("%d ", numero);
        }
        
        printf("\n");
    }
    
    // ========== RESULTADO FINAL ==========
    printf("\n================================================\n");
    printf("PATRON NUMERICO COMPLETADO EXITOSAMENTE\n");
    printf("Total de filas: 9\n");
    printf("Estructura: Cada fila i comienza con número i\n");
    printf("            y sigue patrón: ascendente + descendente\n");
    printf("            con módulo 10 para obtener dígitos únicos\n");
    printf("================================================\n\n");
    
    return 0;
}