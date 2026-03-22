#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char cad1[50];              // primera cadena
    char cad2[50];              // segunda cadena
    char cad_resultado[100];    // cadena resultado intercalada
    
    // Arreglos para almacenar palabras
    char palabras1[20][20];     // palabras de cad1
    char palabras2[20][20];     // palabras de cad2
    int num_palabras1 = 0;      // número de palabras en cad1
    int num_palabras2 = 0;      // número de palabras en cad2
    
    int i, j;                   // contadores
    int idx_cad = 0;            // índice para cadena copia
    int idx_palabra = 0;        // índice para palabra actual
    char palabra_actual[20];    // palabra temporal
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("      INTERCALAR PALABRAS DE DOS CADENAS (PS7.8)\n");
    printf("================================================\n\n");
    
    printf("Intercala palabras de dos cadenas alternadamente.\n\n");
    
    printf("Ejemplo:\n");
    printf("Cadena 1: aa ab ac af ap ar\n");
    printf("Cadena 2: ap bc bd be\n");
    printf("Resultado: aa ap ab bc ac bd af be ap ar\n\n");
    
    printf("Ingrese la primera cadena (máximo 50 caracteres):\n");
    printf("Cadena 1: ");
    fgets(cad1, 50, stdin);
    
    // Eliminar salto de línea
    int longitud = strlen(cad1);
    if (cad1[longitud - 1] == '\n') {
        cad1[longitud - 1] = '\0';
    }
    
    printf("\nIngrese la segunda cadena (máximo 50 caracteres):\n");
    printf("Cadena 2: ");
    fgets(cad2, 50, stdin);
    
    // Eliminar salto de línea
    longitud = strlen(cad2);
    if (cad2[longitud - 1] == '\n') {
        cad2[longitud - 1] = '\0';
    }
    
    // ========== VALIDACION ==========
    if (strlen(cad1) == 0 || strlen(cad2) == 0) {
        printf("\nError: Las cadenas no pueden estar vacias.\n");
        return 1;
    }
    
    // ========== EXTRAER PALABRAS DE CADENA 1 ==========
    printf("\n================================================\n");
    printf("EXTRAYENDO PALABRAS DE CADENA 1\n");
    printf("================================================\n\n");
    
    printf("Cadena 1: %s\n\n", cad1);
    
    idx_palabra = 0;
    for (i = 0; i <= strlen(cad1); i++) {
        // Si encuentra espacio o fin de cadena
        if (cad1[i] == ' ' || cad1[i] == '\0') {
            if (idx_palabra > 0) {
                palabra_actual[idx_palabra] = '\0';
                strcpy(palabras1[num_palabras1], palabra_actual);
                printf("Palabra %d: %s\n", num_palabras1 + 1, palabras1[num_palabras1]);
                num_palabras1++;
                idx_palabra = 0;
            }
        } else {
            // Agregar carácter a la palabra actual
            palabra_actual[idx_palabra] = cad1[i];
            idx_palabra++;
        }
    }
    
    printf("\nTotal de palabras en cadena 1: %d\n\n", num_palabras1);
    
    // ========== EXTRAER PALABRAS DE CADENA 2 ==========
    printf("================================================\n");
    printf("EXTRAYENDO PALABRAS DE CADENA 2\n");
    printf("================================================\n\n");
    
    printf("Cadena 2: %s\n\n", cad2);
    
    idx_palabra = 0;
    for (i = 0; i <= strlen(cad2); i++) {
        // Si encuentra espacio o fin de cadena
        if (cad2[i] == ' ' || cad2[i] == '\0') {
            if (idx_palabra > 0) {
                palabra_actual[idx_palabra] = '\0';
                strcpy(palabras2[num_palabras2], palabra_actual);
                printf("Palabra %d: %s\n", num_palabras2 + 1, palabras2[num_palabras2]);
                num_palabras2++;
                idx_palabra = 0;
            }
        } else {
            // Agregar carácter a la palabra actual
            palabra_actual[idx_palabra] = cad2[i];
            idx_palabra++;
        }
    }
    
    printf("\nTotal de palabras en cadena 2: %d\n\n", num_palabras2);
    
    // ========== INTERCALAR PALABRAS ==========
    printf("================================================\n");
    printf("INTERCALANDO PALABRAS\n");
    printf("================================================\n\n");
    
    strcpy(cad_resultado, "");
    int i1 = 0, i2 = 0;
    
    // Intercalar palabras mientras ambas cadenas tengan palabras
    while (i1 < num_palabras1 || i2 < num_palabras2) {
        // Agregar palabra de cadena 1
        if (i1 < num_palabras1) {
            strcat(cad_resultado, palabras1[i1]);
            printf("Agregada palabra %d de cadena 1: %s\n", i1 + 1, palabras1[i1]);
            
            if (i1 < num_palabras1 - 1 || i2 < num_palabras2) {
                strcat(cad_resultado, " ");
            }
            i1++;
        }
        
        // Agregar palabra de cadena 2
        if (i2 < num_palabras2) {
            strcat(cad_resultado, palabras2[i2]);
            printf("Agregada palabra %d de cadena 2: %s\n", i2 + 1, palabras2[i2]);
            
            if (i1 < num_palabras1 || i2 < num_palabras2 - 1) {
                strcat(cad_resultado, " ");
            }
            i2++;
        }
    }
    
    printf("\n");
    
    // ========== TABLA DE PALABRAS ==========
    printf("================================================\n");
    printf("TABLA COMPARATIVA DE PALABRAS\n");
    printf("================================================\n\n");
    
    int max_palabras = (num_palabras1 > num_palabras2) ? num_palabras1 : num_palabras2;
    
    printf("Num |  Cadena 1  |  Cadena 2  | Intercaladas\n");
    printf"----|------------|------------|---------------------\n");
    
    for (i = 0; i < max_palabras; i++) {
        printf(" %d  | ", i + 1);
        
        if (i < num_palabras1) {
            printf("%-10s | ", palabras1[i]);
        } else {
            printf("           | ");
        }
        
        if (i < num_palabras2) {
            printf("%-10s | ", palabras2[i]);
        } else {
            printf("           | ");
        }
        
        if (i < num_palabras1) {
            printf("%s ", palabras1[i]);
        }
        if (i < num_palabras2) {
            printf("%s", palabras2[i]);
        }
        
        printf("\n");
    }
    
    // ========== RESULTADO FINAL ==========
    printf("\n================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Cadena 1 original:\n");
    printf("%s\n\n", cad1);
    
    printf("Cadena 2 original:\n");
    printf("%s\n\n", cad2);
    
    printf("Cadena intercalada:\n");
    printf("%s\n\n", cad_resultado);
    
    // ========== TABLA DE CARACTERES ==========
    printf("================================================\n");
    printf("TABLA DE CARACTERES - RESULTADO\n");
    printf("================================================\n\n");
    
    printf("Pos | Caracter | Tipo\n");
    printf("----|----------|--------\n");
    
    for (i = 0; i < strlen(cad_resultado); i++) {
        printf(" %2d |    %c    | ", i + 1, cad_resultado[i]);
        
        if (cad_resultado[i] == ' ') {
            printf("Espacio\n");
        } else {
            printf("Letra\n");
        }
    }
    
    // ========== ESTADISTICAS ==========
    printf("\n================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    printf("Cadena 1:\n");
    printf("  Longitud: %lu caracteres\n", strlen(cad1));
    printf("  Palabras: %d\n\n", num_palabras1);
    
    printf("Cadena 2:\n");
    printf("  Longitud: %lu caracteres\n", strlen(cad2));
    printf("  Palabras: %d\n\n", num_palabras2);
    
    printf("Resultado:\n");
    printf("  Longitud: %lu caracteres\n", strlen(cad_resultado));
    printf("  Total de palabras: %d\n\n", num_palabras1 + num_palabras2);
    
    printf("================================================\n\n");
    
    return 0;
}