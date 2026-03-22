#include <stdio.h>
#include <string.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char cad[50];               // cadena de caracteres (máximo 50)
    int longitud;               // longitud de la cadena
    int i;                      // contador para bucles
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("IMPRIMIR CARACTERES EN POSICIONES IMPARES (PS7.1)\n");
    printf("================================================\n\n");
    
    printf("Ingrese una cadena de caracteres (máximo 50):\n");
    printf("Cadena: ");
    fgets(cad, 50, stdin);
    
    // ========== VALIDACION Y PROCESAMIENTO ==========
    // Obtener la longitud de la cadena
    longitud = strlen(cad);
    
    // Eliminar el salto de línea si existe
    if (cad[longitud - 1] == '\n') {
        cad[longitud - 1] = '\0';
        longitud--;
    }
    
    // ========== VERIFICACION ==========
    if (longitud == 0) {
        printf("\nError: La cadena no puede estar vacia.\n");
        return 1;
    }
    
    // ========== MOSTRAR CADENA ORIGINAL ==========
    printf("\n================================================\n");
    printf("CADENA ORIGINAL\n");
    printf("================================================\n\n");
    
    printf("Cadena ingresada: %s\n", cad);
    printf("Longitud: %d caracteres\n\n", longitud);
    
    // ========== MOSTRAR POSICIONES Y CARACTERES ==========
    printf("================================================\n");
    printf("TABLA DE CARACTERES CON POSICIONES\n");
    printf("================================================\n\n");
    
    printf("Posicion |  Tipo   | Caracter\n");
    printf("---------|---------|----------\n");
    
    for (i = 0; i < longitud; i++) {
        printf("   %2d    | ", i + 1);
        
        // Verificar si la posición es impar o par
        if ((i + 1) % 2 == 1) {
            printf("IMPAR   | ");
        } else {
            printf("PAR     | ");
        }
        
        printf("   %c\n", cad[i]);
    }
    
    // ========== RESULTADO FINAL - CARACTERES IMPARES ==========
    printf("\n================================================\n");
    printf("CARACTERES EN POSICIONES IMPARES\n");
    printf("================================================\n\n");
    
    printf("Posiciones impares: 1, 3, 5, 7, 9, ...\n\n");
    
    printf("Caracteres extraidos:\n");
    printf("Posicion |  Caracter\n");
    printf("---------|----------\n");
    
    int contador = 0;
    
    for (i = 0; i < longitud; i++) {
        // Verificar si la posición es impar (1, 3, 5, 7, ...)
        if ((i + 1) % 2 == 1) {
            printf("   %2d    |    %c\n", i + 1, cad[i]);
            contador++;
        }
    }
    
    // ========== MOSTRAR EN LINEA ==========
    printf("\n");
    printf("Caracteres en linea: ");
    
    for (i = 0; i < longitud; i++) {
        if ((i + 1) % 2 == 1) {
            printf("%c", cad[i]);
        }
    }
    printf("\n\n");
    
    // ========== ESTADISTICAS ==========
    printf("================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    printf("Total de caracteres en la cadena: %d\n", longitud);
    printf("Total de caracteres en posiciones impares: %d\n\n", contador);
    
    if (longitud > 0) {
        printf("Porcentaje de caracteres impares: %.2f%%\n\n", 
               (contador * 100.0) / longitud);
    }
    
    printf("================================================\n\n");
    
    return 0;
}