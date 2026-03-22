#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char cad[50];               // cadena de caracteres (máximo 50)
    int longitud;               // longitud de la cadena
    int i;                      // contador para bucles
    int contador_digitos = 0;   // contador de dígitos encontrados
    int contador_pares = 0;     // contador de posiciones pares
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("EXTRAER DIGITOS EN POSICIONES PARES (PS7.2)\n");
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
    
    printf("Posicion |  Tipo   | Caracter | Es Digito?\n");
    printf("---------|---------|----------|----------\n");
    
    for (i = 0; i < longitud; i++) {
        printf("   %2d    | ", i + 1);
        
        // Verificar si la posición es par o impar
        if ((i + 1) % 2 == 0) {
            printf("PAR     | ");
            contador_pares++;
        } else {
            printf("IMPAR   | ");
        }
        
        printf("   %c     | ", cad[i]);
        
        // Verificar si es un dígito
        if (isdigit(cad[i])) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    }
    
    // ========== RESULTADO FINAL - DIGITOS EN POSICIONES PARES ==========
    printf("\n================================================\n");
    printf("DIGITOS EN POSICIONES PARES\n");
    printf("================================================\n\n");
    
    printf("Posiciones pares: 2, 4, 6, 8, 10, ...\n\n");
    
    printf("Digitos extraidos:\n");
    printf("Posicion | Caracter | Tipo\n");
    printf("---------|----------|------\n");
    
    for (i = 0; i < longitud; i++) {
        // Verificar si la posición es par (2, 4, 6, 8, ...)
        if ((i + 1) % 2 == 0) {
            // Verificar si es un dígito
            if (isdigit(cad[i])) {
                printf("   %2d    |    %c    | Digito\n", i + 1, cad[i]);
                contador_digitos++;
            }
        }
    }
    
    // ========== MOSTRAR EN LINEA ==========
    printf("\n");
    printf("Digitos en linea: ");
    
    int hay_digitos = 0;
    for (i = 0; i < longitud; i++) {
        if ((i + 1) % 2 == 0 && isdigit(cad[i])) {
            printf("%c", cad[i]);
            hay_digitos = 1;
        }
    }
    
    if (!hay_digitos) {
        printf("(ninguno)");
    }
    printf("\n\n");
    
    // ========== ESTADISTICAS ==========
    printf("================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    printf("Total de caracteres en la cadena: %d\n", longitud);
    printf("Total de posiciones pares: %d\n", contador_pares);
    printf("Total de digitos encontrados: %d\n", contador_digitos);
    printf("Total de digitos en posiciones pares: %d\n\n", contador_digitos);
    
    if (contador_pares > 0) {
        printf("Porcentaje de digitos en posiciones pares: %.2f%%\n\n", 
               (contador_digitos * 100.0) / contador_pares);
    }
    
    if (contador_digitos == 0) {
        printf("Resultado: No se encontraron digitos en posiciones pares.\n\n");
    } else if (contador_digitos == 1) {
        printf("Resultado: Se encontro 1 digito en posicion par.\n\n");
    } else {
        printf("Resultado: Se encontraron %d digitos en posiciones pares.\n\n", 
               contador_digitos);
    }
    
    printf("================================================\n\n");
    
    return 0;
}