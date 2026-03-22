#include <stdio.h>
#include <string.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char cad[30];               // cadena de caracteres (máximo 30)
    int longitud;               // longitud actual de la cadena
    int longitud_maxima = 30;   // longitud máxima permitida
    int caracteres_faltantes;   // número de guiones a agregar
    int i;                      // contador para bucles
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    COMPLETAR CADENA CON GUIONES (PS7.3)\n");
    printf("================================================\n\n");
    
    printf("Ingrese una cadena de caracteres (máximo 30):\n");
    printf("Cadena: ");
    fgets(cad, 30, stdin);
    
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
    printf("Longitud actual: %d caracteres\n", longitud);
    printf("Longitud máxima: %d caracteres\n\n", longitud_maxima);
    
    // ========== CALCULAR CARACTERES FALTANTES ==========
    caracteres_faltantes = longitud_maxima - longitud;
    
    printf("Caracteres faltantes: %d\n", caracteres_faltantes);
    printf("Carácter a usar: - (guión)\n\n");
    
    // ========== COMPLETAR LA CADENA ==========
    printf("================================================\n");
    printf("COMPLETANDO LA CADENA...\n");
    printf("================================================\n\n");
    
    // Agregar los guiones a la cadena
    for (i = 0; i < caracteres_faltantes; i++) {
        cad[longitud + i] = '-';
    }
    
    // Agregar el terminador nulo
    cad[longitud + caracteres_faltantes] = '\0';
    
    // ========== MOSTRAR CADENA MODIFICADA ==========
    printf("Cadena modificada: %s\n\n", cad);
    
    printf("Nueva longitud: %d caracteres\n\n", 
           (int)strlen(cad));
    
    // ========== TABLA DE CARACTERES ==========
    printf("================================================\n");
    printf("TABLA DE CARACTERES\n");
    printf("================================================\n\n");
    
    printf("Posicion | Caracter | Tipo\n");
    printf("---------|----------|------------------\n");
    
    for (i = 0; i < strlen(cad); i++) {
        printf("   %2d    |    %c    | ", i + 1, cad[i]);
        
        if (i < longitud) {
            printf("Original\n");
        } else {
            printf("Agregado (guion)\n");
        }
    }
    
    // ========== ESTADISTICAS ==========
    printf("\n================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    printf("Longitud original: %d caracteres\n", longitud);
    printf("Caracteres agregados: %d guiones (-)\n", caracteres_faltantes);
    printf("Longitud final: %d caracteres\n\n", (int)strlen(cad));
    
    printf("Porcentaje de contenido original: %.2f%%\n", 
           (longitud * 100.0) / strlen(cad));
    printf("Porcentaje de guiones agregados: %.2f%%\n\n", 
           (caracteres_faltantes * 100.0) / strlen(cad));
    
    // ========== VISUALIZACION ==========
    printf("================================================\n");
    printf("VISUALIZACION CON LIMITES\n");
    printf("================================================\n\n");
    
    printf("Cadena con delimitadores:\n");
    printf("|%s|\n\n", cad);
    
    printf("Longitud visual confirmada: %d caracteres\n\n", 
           (int)strlen(cad));
    
    printf("================================================\n\n");
    
    return 0;
}