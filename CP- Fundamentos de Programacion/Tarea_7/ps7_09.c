#include <stdio.h>
#include <string.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char cad[50];               // cadena original
    char cadena_invertida[50];  // cadena con palabras invertidas
    
    // Arreglos para almacenar palabras
    char palabras[20][20];      // palabras de la cadena
    int num_palabras = 0;       // número de palabras
    
    int i, j;                   // contadores
    int idx_palabra = 0;        // índice para palabra actual
    char palabra_actual[20];    // palabra temporal
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    INVERTIR ORDEN DE PALABRAS EN CADENA (PS7.9)\n");
    printf("================================================\n\n");
    
    printf("Invierte el orden de las palabras de una cadena.\n\n");
    
    printf("Ejemplo:\n");
    printf("Original:  mundo del economia novena la es Mexico\n");
    printf("Invertida: Mexico es la novena economia del mundo\n\n");
    
    printf("Ingrese una cadena de caracteres (máximo 50):\n");
    printf("Cadena: ");
    fgets(cad, 50, stdin);
    
    // ========== VALIDACION Y PROCESAMIENTO ==========
    // Eliminar salto de línea
    int longitud = strlen(cad);
    if (cad[longitud - 1] == '\n') {
        cad[longitud - 1] = '\0';
        longitud--;
    }
    
    // ========== VERIFICACION ==========
    if (longitud == 0) {
        printf("\nError: La cadena no puede estar vacia.\n");
        return 1;
    }
    
    // ========== EXTRAER PALABRAS ==========
    printf("\n================================================\n");
    printf("EXTRAYENDO PALABRAS\n");
    printf("================================================\n\n");
    
    printf("Cadena original: %s\n\n", cad);
    
    idx_palabra = 0;
    for (i = 0; i <= longitud; i++) {
        // Si encuentra espacio o fin de cadena
        if (cad[i] == ' ' || cad[i] == '\0') {
            if (idx_palabra > 0) {
                palabra_actual[idx_palabra] = '\0';
                strcpy(palabras[num_palabras], palabra_actual);
                printf("Palabra %d: %s\n", num_palabras + 1, palabras[num_palabras]);
                num_palabras++;
                idx_palabra = 0;
            }
        } else {
            // Agregar carácter a la palabra actual
            palabra_actual[idx_palabra] = cad[i];
            idx_palabra++;
        }
    }
    
    printf("\nTotal de palabras: %d\n\n", num_palabras);
    
    // ========== INVERTIR PALABRAS ==========
    printf("================================================\n");
    printf("INVIRTIENDO ORDEN DE PALABRAS\n");
    printf("================================================\n\n");
    
    strcpy(cadena_invertida, "");
    
    for (i = num_palabras - 1; i >= 0; i--) {
        printf("Agregando palabra %d: %s\n", num_palabras - i, palabras[i]);
        strcat(cadena_invertida, palabras[i]);
        
        if (i > 0) {
            strcat(cadena_invertida, " ");
        }
    }
    
    printf("\n");
    
    // ========== TABLA DE PALABRAS ORIGINAL ==========
    printf("================================================\n");
    printf("TABLA DE PALABRAS - ORDEN ORIGINAL\n");
    printf("================================================\n\n");
    
    printf("Posicion | Palabra\n");
    printf("---------|----------\n");
    
    for (i = 0; i < num_palabras; i++) {
        printf("   %2d    | %s\n", i + 1, palabras[i]);
    }
    
    // ========== TABLA DE PALABRAS INVERTIDO ==========
    printf("\n================================================\n");
    printf("TABLA DE PALABRAS - ORDEN INVERTIDO\n");
    printf("================================================\n\n");
    
    printf("Posicion | Palabra\n");
    printf("---------|----------\n");
    
    for (i = num_palabras - 1; i >= 0; i--) {
        printf("   %2d    | %s\n", num_palabras - i, palabras[i]);
    }
    
    // ========== TABLA COMPARATIVA ==========
    printf("\n================================================\n");
    printf("TABLA COMPARATIVA\n");
    printf("================================================\n\n");
    
    printf("Original | Invertida\n");
    printf("---------|----------\n");
    
    for (i = 0; i < num_palabras; i++) {
        printf("   %2d    | ", i + 1);
        printf("%2d\n", num_palabras - i);
    }
    
    // ========== TABLA DE CARACTERES ORIGINAL ==========
    printf("\n================================================\n");
    printf("TABLA DE CARACTERES - ORIGINAL\n");
    printf("================================================\n\n");
    
    printf("Pos | Caracter | Tipo\n");
    printf("----|----------|----------\n");
    
    for (i = 0; i < strlen(cad); i++) {
        printf(" %2d |    %c    | ", i + 1, cad[i]);
        
        if (cad[i] == ' ') {
            printf("Espacio\n");
        } else {
            printf("Letra\n");
        }
    }
    
    // ========== TABLA DE CARACTERES INVERTIDA ==========
    printf("\n================================================\n");
    printf("TABLA DE CARACTERES - INVERTIDA\n");
    printf("================================================\n\n");
    
    printf("Pos | Caracter | Tipo\n");
    printf("----|----------|----------\n");
    
    for (i = 0; i < strlen(cadena_invertida); i++) {
        printf(" %2d |    %c    | ", i + 1, cadena_invertida[i]);
        
        if (cadena_invertida[i] == ' ') {
            printf("Espacio\n");
        } else {
            printf("Letra\n");
        }
    }
    
    // ========== RESULTADO FINAL ==========
    printf("\n================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Cadena ORIGINAL:\n");
    printf("%s\n\n", cad);
    
    printf("Cadena INVERTIDA:\n");
    printf("%s\n\n", cadena_invertida);
    
    // ========== ANALISIS DE CAMBIOS ==========
    printf("================================================\n");
    printf("ANALISIS DE CAMBIOS\n");
    printf("================================================\n\n");
    
    printf("Primera palabra original: %s\n", palabras[0]);
    printf("Primera palabra invertida: %s\n\n", palabras[num_palabras - 1]);
    
    printf("Ultima palabra original: %s\n", palabras[num_palabras - 1]);
    printf("Ultima palabra invertida: %s\n\n", palabras[0]);
    
    printf("Posicion primera palabra:\n");
    printf("  Original: posicion 1\n");
    printf("  Invertida: posicion %d\n\n", num_palabras);
    
    printf("Posicion ultima palabra:\n");
    printf("  Original: posicion %d\n", num_palabras);
    printf("  Invertida: posicion 1\n\n");
    
    // ========== ESTADISTICAS ==========
    printf("================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    printf("Total de palabras: %d\n", num_palabras);
    printf("Longitud original: %d caracteres\n", (int)strlen(cad));
    printf("Longitud invertida: %d caracteres\n\n", (int)strlen(cadena_invertida));
    
    // Palabra más larga
    int max_longitud = 0;
    int palabra_larga = 0;
    for (i = 0; i < num_palabras; i++) {
        if ((int)strlen(palabras[i]) > max_longitud) {
            max_longitud = strlen(palabras[i]);
            palabra_larga = i;
        }
    }
    
    printf("Palabra mas larga: %s (%d caracteres)\n", 
           palabras[palabra_larga], max_longitud);
    printf("Palabra mas corta: %s (%lu caracteres)\n\n", 
           palabras[0], strlen(palabras[0]));
    
    for (i = 1; i < num_palabras; i++) {
        if ((int)strlen(palabras[i]) < max_longitud) {
            if ((int)strlen(palabras[i]) < (int)strlen(palabras[0])) {
                // Continuar buscando
            }
        }
    }
    
    printf("================================================\n\n");
    
    return 0;
}