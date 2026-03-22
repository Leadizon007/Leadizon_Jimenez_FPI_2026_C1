#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char cad[50];               // cadena de caracteres (máximo 50)
    char cad_modificada[50];    // copia de la cadena modificada
    int longitud;               // longitud de la cadena
    int i;                      // contador para bucles
    int es_inicio_palabra;      // bandera para detectar inicio de palabra
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("CONVERTIR PRIMERA LETRA A MAYUSCULA (PS7.5)\n");
    printf("================================================\n\n");
    
    printf("Convierte el primer caracter de cada palabra\n");
    printf("de minuscula a mayuscula.\n\n");
    
    printf("Ejemplo:\n");
    printf("Entrada:  Estructuras de datos, año 2003, edicion 2\n");
    printf("Salida:   Estructuras De Datos, Año 2003, Edicion 2\n\n");
    
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
    
    // ========== COPIAR LA CADENA ==========
    strcpy(cad_modificada, cad);
    
    // ========== MOSTRAR CADENA ORIGINAL ==========
    printf("\n================================================\n");
    printf("CADENA ORIGINAL\n");
    printf("================================================\n\n");
    
    printf("Cadena ingresada: %s\n", cad);
    printf("Longitud: %d caracteres\n\n", longitud);
    
    // ========== PROCESAMIENTO - CONVERTIR PRIMERAS LETRAS ==========
    printf("================================================\n");
    printf("Procesando cadena...\n");
    printf("================================================\n\n");
    
    // El primer carácter siempre es inicio de palabra
    es_inicio_palabra = 1;
    
    for (i = 0; i < longitud; i++) {
        // Verificar si es espacio, coma, punto, etc. (separador)
        if (cad_modificada[i] == ' ' || cad_modificada[i] == ',' || 
            cad_modificada[i] == '.' || cad_modificada[i] == ';' ||
            cad_modificada[i] == ':') {
            // Marcar que el siguiente carácter es inicio de palabra
            es_inicio_palabra = 1;
        } else {
            // Si es inicio de palabra y es una letra
            if (es_inicio_palabra && isalpha(cad_modificada[i])) {
                // Convertir a mayúscula
                cad_modificada[i] = toupper(cad_modificada[i]);
                es_inicio_palabra = 0;
            } else {
                // No es inicio de palabra
                es_inicio_palabra = 0;
            }
        }
    }
    
    // ========== MOSTRAR CADENA MODIFICADA ==========
    printf("Cadena modificada: %s\n\n", cad_modificada);
    
    // ========== TABLA DE CARACTERES CON ANALISIS ==========
    printf("================================================\n");
    printf("TABLA DE CARACTERES CON ANALISIS\n");
    printf("================================================\n\n");
    
    printf("Pos | Original | Modificado | Tipo\n");
    printf("----|----------|-----------|------------------\n");
    
    for (i = 0; i < longitud; i++) {
        printf(" %2d |    %c    |     %c      | ", i + 1, cad[i], cad_modificada[i]);
        
        if (cad[i] == cad_modificada[i]) {
            printf("Sin cambio\n");
        } else {
            printf("Convertido a mayuscula\n");
        }
    }
    
    // ========== IDENTIFICACION DE PALABRAS ==========
    printf("\n================================================\n");
    printf("IDENTIFICACION DE PALABRAS\n");
    printf("================================================\n\n");
    
    printf("Cadena original:\n");
    printf("%s\n\n", cad);
    
    printf("Palabras identificadas y su primer caracter:\n\n");
    
    int palabra_num = 1;
    int en_palabra = 0;
    char palabra[50];
    int palabra_idx = 0;
    
    for (i = 0; i < longitud; i++) {
        // Si es letra o dígito, está en una palabra
        if (isalnum(cad[i])) {
            if (!en_palabra) {
                // Inicio de nueva palabra
                en_palabra = 1;
                palabra_idx = 0;
            }
            palabra[palabra_idx] = cad[i];
            palabra_idx++;
        } else {
            // Fin de palabra
            if (en_palabra) {
                palabra[palabra_idx] = '\0';
                
                printf("Palabra %d: %s\n", palabra_num, palabra);
                printf("  Primer caracter: %c\n", palabra[0]);
                printf("  Es letra: %s\n", isalpha(palabra[0]) ? "SI" : "NO");
                if (isalpha(palabra[0])) {
                    printf("  Convertido a: %c\n\n", toupper(palabra[0]));
                } else {
                    printf("  No se convierte (es dígito)\n\n");
                }
                
                palabra_num++;
                en_palabra = 0;
            }
        }
    }
    
    // Última palabra si la cadena termina sin separador
    if (en_palabra) {
        palabra[palabra_idx] = '\0';
        printf("Palabra %d: %s\n", palabra_num, palabra);
        printf("  Primer caracter: %c\n", palabra[0]);
        printf("  Es letra: %s\n", isalpha(palabra[0]) ? "SI" : "NO");
        if (isalpha(palabra[0])) {
            printf("  Convertido a: %c\n\n", toupper(palabra[0]));
        } else {
            printf("  No se convierte (es dígito)\n\n");
        }
    }
    
    // ========== ESTADISTICAS ==========
    printf("================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    int cambios = 0;
    for (i = 0; i < longitud; i++) {
        if (cad[i] != cad_modificada[i]) {
            cambios++;
        }
    }
    
    printf("Longitud de la cadena: %d caracteres\n", longitud);
    printf("Caracteres convertidos a mayúscula: %d\n", cambios);
    printf("Caracteres sin cambio: %d\n\n", longitud - cambios);
    
    printf("Porcentaje de conversión: %.2f%%\n\n", 
           (cambios * 100.0) / longitud);
    
    // ========== RESULTADO FINAL ==========
    printf("================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Original:  %s\n", cad);
    printf("Convertida: %s\n\n", cad_modificada);
    
    printf("================================================\n\n");
    
    return 0;
}