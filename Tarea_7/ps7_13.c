#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char ARC[10][50];           // arreglo de 10 cadenas de máximo 50 caracteres
    int num_cadenas = 0;        // número de cadenas ingresadas
    int palabras[10];           // arreglo para contar palabras de cada cadena
    int i, j;                   // contadores
    char respuesta;             // respuesta del usuario
    int longitud;               // longitud de cadena
    int contador_palabras;      // contador de palabras actual
    int en_palabra = 0;         // bandera para detectar palabras
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("      CONTAR PALABRAS EN CADA CADENA (PS7.13)\n");
    printf("================================================\n\n");
    
    printf("Este programa lee varias cadenas y cuenta\n");
    printf("el numero de palabras en cada una.\n\n");
    
    printf("Se pueden ingresar hasta 10 cadenas.\n");
    printf("Cada cadena puede tener hasta 50 caracteres.\n\n");
    
    printf("Las palabras se separan por espacios.\n\n");
    
    // ========== LECTURA DE CADENAS ==========
    printf("================================================\n");
    printf("INGRESO DE CADENAS\n");
    printf("================================================\n\n");
    
    while (num_cadenas < 10) {
        printf("¿Desea ingresar la cadena %d? (S/N): ", num_cadenas + 1);
        scanf("%c", &respuesta);
        
        // Limpiar buffer
        while (getchar() != '\n');
        
        // Validar respuesta
        if (respuesta == 'S' || respuesta == 's') {
            printf("Ingrese la cadena %d (máximo 50 caracteres): ", num_cadenas + 1);
            fgets(ARC[num_cadenas], 50, stdin);
            
            // Eliminar salto de línea
            longitud = strlen(ARC[num_cadenas]);
            if (ARC[num_cadenas][longitud - 1] == '\n') {
                ARC[num_cadenas][longitud - 1] = '\0';
                longitud--;
            }
            
            printf("Cadena ingresada: %s\n", ARC[num_cadenas]);
            printf("Longitud: %d caracteres\n\n", longitud);
            
            num_cadenas++;
            
        } else if (respuesta == 'N' || respuesta == 'n') {
            printf("Ingreso finalizado.\n\n");
            break;
        } else {
            printf("Respuesta invalida. Intente nuevamente (S/N).\n\n");
        }
    }
    
    // ========== VERIFICACION ==========
    if (num_cadenas == 0) {
        printf("\nError: No se ingresaron cadenas.\n");
        return 1;
    }
    
    // ========== CONTAR PALABRAS EN CADA CADENA ==========
    printf("================================================\n");
    printf("CONTANDO PALABRAS\n");
    printf("================================================\n\n");
    
    for (i = 0; i < num_cadenas; i++) {
        contador_palabras = 0;
        longitud = strlen(ARC[i]);
        en_palabra = 0;
        
        printf("Cadena %d: %s\n", i + 1, ARC[i]);
        printf("Palabras: ");
        
        // Contar palabras
        int palabra_num = 0;
        for (j = 0; j < longitud; j++) {
            // Si es un carácter no espacio
            if (!isspace(ARC[i][j])) {
                // Si no estábamos en palabra, comenzamos una nueva
                if (!en_palabra) {
                    en_palabra = 1;
                    contador_palabras++;
                    palabra_num++;
                    printf("%d. ", palabra_num);
                }
            } else {
                // Si era espacio, terminamos la palabra actual
                en_palabra = 0;
                printf(" | ");
            }
            
            // Mostrar carácter
            if (!isspace(ARC[i][j])) {
                printf("%c", ARC[i][j]);
            }
        }
        
        palabras[i] = contador_palabras;
        printf("\n\nTotal de palabras: %d\n\n", contador_palabras);
    }
    
    // ========== TABLA DE PALABRAS ==========
    printf("================================================\n");
    printf("TABLA DE PALABRAS POR CADENA\n");
    printf("================================================\n\n");
    
    printf("Num | Cadena                            | Palabras\n");
    printf"----|-----------------------------------|----------\n");
    
    for (i = 0; i < num_cadenas; i++) {
        printf(" %d  | %-35s | %8d\n", i + 1, ARC[i], palabras[i]);
    }
    
    // ========== TABLA DETALLADA DE ANALISIS ==========
    printf("\n================================================\n");
    printf("ANALISIS DETALLADO DE CADA CADENA\n");
    printf("================================================\n\n");
    
    for (i = 0; i < num_cadenas; i++) {
        printf("Cadena %d: %s\n", i + 1, ARC[i]);
        printf("Longitud: %lu caracteres\n", strlen(ARC[i]));
        printf("Total de palabras: %d\n\n", palabras[i]);
        
        // Extraer y mostrar cada palabra
        longitud = strlen(ARC[i]);
        int palabra_idx = 1;
        char palabra_actual[50];
        int idx_palabra = 0;
        
        printf("Palabras identificadas:\n");
        
        for (j = 0; j <= longitud; j++) {
            // Si es espacio o fin de cadena
            if (isspace(ARC[i][j]) || ARC[i][j] == '\0') {
                if (idx_palabra > 0) {
                    palabra_actual[idx_palabra] = '\0';
                    printf("  %d. %s (%d caracteres)\n", 
                           palabra_idx, palabra_actual, idx_palabra);
                    palabra_idx++;
                    idx_palabra = 0;
                }
            } else {
                // Agregar carácter a palabra
                palabra_actual[idx_palabra] = ARC[i][j];
                idx_palabra++;
            }
        }
        
        printf("\n");
    }
    
    // ========== TABLA DE CARACTERES DE CADA CADENA ==========
    printf("================================================\n");
    printf("TABLA DE CARACTERES - ANALISIS POR CADENA\n");
    printf("================================================\n\n");
    
    for (i = 0; i < num_cadenas; i++) {
        printf("Cadena %d: %s\n", i + 1, ARC[i]);
        printf("Pos | Caracter | Tipo\n");
        printf"----|----------|----------\n");
        
        longitud = strlen(ARC[i]);
        for (j = 0; j < longitud; j++) {
            printf(" %2d |    %c    | ", j + 1, ARC[i][j]);
            
            if (isspace(ARC[i][j])) {
                printf("Espacio\n");
            } else if (isalpha(ARC[i][j])) {
                printf("Letra\n");
            } else if (isdigit(ARC[i][j])) {
                printf("Digito\n");
            } else {
                printf("Especial\n");
            }
        }
        printf("\n");
    }
    
    // ========== RESULTADO FINAL ==========
    printf("================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Total de cadenas ingresadas: %d\n\n", num_cadenas);
    
    for (i = 0; i < num_cadenas; i++) {
        printf("Cadena %d: %s\n", i + 1, ARC[i]);
        printf("  Palabras: %d\n", palabras[i]);
        printf("  Caracteres: %lu\n\n", strlen(ARC[i]));
    }
    
    // ========== ESTADISTICAS ==========
    printf("================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    // Calcular estadísticas
    int suma_palabras = 0;
    int minimo_palabras = palabras[0];
    int maximo_palabras = palabras[0];
    int indice_minimo = 0;
    int indice_maximo = 0;
    
    for (i = 0; i < num_cadenas; i++) {
        suma_palabras += palabras[i];
        
        if (palabras[i] < minimo_palabras) {
            minimo_palabras = palabras[i];
            indice_minimo = i;
        }
        if (palabras[i] > maximo_palabras) {
            maximo_palabras = palabras[i];
            indice_maximo = i;
        }
    }
    
    double promedio_palabras = suma_palabras / (double)num_cadenas;
    
    printf("Minimo de palabras encontrado: %d\n", minimo_palabras);
    printf("  Cadena: %s\n", ARC[indice_minimo]);
    printf("  Posicion: %d\n\n", indice_minimo + 1);
    
    printf("Maximo de palabras encontrado: %d\n", maximo_palabras);
    printf("  Cadena: %s\n", ARC[indice_maximo]);
    printf("  Posicion: %d\n\n", indice_maximo + 1);
    
    printf("Promedio de palabras por cadena: %.2f\n\n", promedio_palabras);
    
    printf("Suma total de palabras: %d\n", suma_palabras);
    printf("Cadenas analizadas: %d\n\n", num_cadenas);
    
    // ========== RANKING DE PALABRAS ==========
    printf("================================================\n");
    printf("RANKING DE CADENAS POR NUMERO DE PALABRAS\n");
    printf("================================================\n\n");
    
    // Crear arreglo de índices ordenado
    int indices[10];
    for (i = 0; i < num_cadenas; i++) {
        indices[i] = i;
    }
    
    // Ordenar índices por número de palabras (de mayor a menor)
    for (i = 0; i < num_cadenas - 1; i++) {
        for (j = 0; j < num_cadenas - i - 1; j++) {
            if (palabras[indices[j]] < palabras[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    
    printf("Rango | Cadena                            | Palabras | Caracteres\n");
    printf("------|-----------------------------------|----------|----------\n");
    
    for (i = 0; i < num_cadenas; i++) {
        int idx = indices[i];
        printf(" %2d   | %-35s | %8d | %10lu\n", 
               i + 1, ARC[idx], palabras[idx], strlen(ARC[idx]));
    }
    
    printf("\n================================================\n\n");
    
    return 0;
}