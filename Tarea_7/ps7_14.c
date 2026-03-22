#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char ARC[20][80];           // arreglo de 20 cadenas de máximo 80 caracteres
    int num_cadenas = 0;        // número de cadenas ingresadas
    int frecuencia[80];         // arreglo para contar frecuencia por longitud
    int i, j;                   // contadores
    char respuesta;             // respuesta del usuario
    int longitud;               // longitud de cadena
    int longitud_palabra;       // longitud de palabra actual
    int palabra_num = 0;        // número de palabras procesadas
    char palabra_actual[80];    // palabra temporal
    int idx_palabra = 0;        // índice para palabra actual
    int max_longitud = 0;       // longitud máxima encontrada
    
    // ========== INICIALIZAR ARREGLO DE FRECUENCIAS ==========
    for (i = 0; i < 80; i++) {
        frecuencia[i] = 0;
    }
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("FRECUENCIA DE PALABRAS POR LONGITUD (PS7.14)\n");
    printf("================================================\n\n");
    
    printf("Este programa lee varias cadenas y calcula\n");
    printf("la frecuencia de palabras segun su longitud.\n\n");
    
    printf("Se pueden ingresar hasta 20 cadenas.\n");
    printf("Cada cadena puede tener hasta 80 caracteres.\n\n");
    
    printf("Las palabras se separan por espacios y puntuacion.\n\n");
    
    // ========== LECTURA DE CADENAS ==========
    printf("================================================\n");
    printf("INGRESO DE CADENAS\n");
    printf("================================================\n\n");
    
    while (num_cadenas < 20) {
        printf("¿Desea ingresar la cadena %d? (S/N): ", num_cadenas + 1);
        scanf("%c", &respuesta);
        
        // Limpiar buffer
        while (getchar() != '\n');
        
        // Validar respuesta
        if (respuesta == 'S' || respuesta == 's') {
            printf("Ingrese la cadena %d (máximo 80 caracteres):\n", num_cadenas + 1);
            printf("Cadena: ");
            fgets(ARC[num_cadenas], 80, stdin);
            
            // Eliminar salto de línea
            longitud = strlen(ARC[num_cadenas]);
            if (ARC[num_cadenas][longitud - 1] == '\n') {
                ARC[num_cadenas][longitud - 1] = '\0';
                longitud--;
            }
            
            printf("Ingresada correctamente (%d caracteres)\n\n", longitud);
            
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
    
    // ========== MOSTRAR CADENAS INGRESADAS ==========
    printf("================================================\n");
    printf("CADENAS INGRESADAS\n");
    printf("================================================\n\n");
    
    for (i = 0; i < num_cadenas; i++) {
        printf("Cadena %d: %s\n", i + 1, ARC[i]);
    }
    printf("\n");
    
    // ========== EXTRAER PALABRAS Y CONTAR FRECUENCIAS ==========
    printf("================================================\n");
    printf("PROCESANDO PALABRAS\n");
    printf("================================================\n\n");
    
    for (i = 0; i < num_cadenas; i++) {
        printf("Cadena %d:\n", i + 1);
        longitud = strlen(ARC[i]);
        idx_palabra = 0;
        int palabra_cadena = 0;
        
        for (j = 0; j <= longitud; j++) {
            char caracter = ARC[i][j];
            
            // Verificar si es carácter válido (letra o número)
            if (isalnum(caracter)) {
                // Agregar carácter a la palabra
                palabra_actual[idx_palabra] = caracter;
                idx_palabra++;
            } else {
                // Fin de palabra
                if (idx_palabra > 0) {
                    palabra_actual[idx_palabra] = '\0';
                    longitud_palabra = strlen(palabra_actual);
                    
                    // Actualizar frecuencia
                    frecuencia[longitud_palabra]++;
                    palabra_cadena++;
                    palabra_num++;
                    
                    // Actualizar máxima longitud
                    if (longitud_palabra > max_longitud) {
                        max_longitud = longitud_palabra;
                    }
                    
                    printf("  Palabra %d: %s (longitud: %d)\n", 
                           palabra_cadena, palabra_actual, longitud_palabra);
                    
                    idx_palabra = 0;
                }
            }
        }
        printf("\n");
    }
    
    // ========== RESULTADO FINAL ==========
    printf("================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Frecuencia de palabras por longitud:\n\n");
    
    printf("Longitud de palabra | Frecuencia\n");
    printf("--------------------|----------\n");
    
    int total_palabras = 0;
    for (i = 1; i <= max_longitud; i++) {
        printf("        %2d          |    %2d\n", i, frecuencia[i]);
        total_palabras += frecuencia[i];
    }
    
    printf("\nTotal de palabras procesadas: %d\n\n", total_palabras);
    
    // ========== TABLA DETALLADA ==========
    printf("================================================\n");
    printf("TABLA DETALLADA DE FRECUENCIAS\n");
    printf("================================================\n\n");
    
    printf("Longitud | Frecuencia | Porcentaje | Barras\n");
    printf"---------|------------|-----------|----------------------------------\n");
    
    for (i = 1; i <= max_longitud; i++) {
        if (frecuencia[i] > 0) {
            double porcentaje = (frecuencia[i] * 100.0) / total_palabras;
            
            printf("   %2d    |    %2d      |  %6.2f%%  | ", i, frecuencia[i], porcentaje);
            
            // Mostrar barras gráficas
            int barras = frecuencia[i];
            for (j = 0; j < barras && j < 30; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    
    printf("\n");
    
    // ========== ESTADISTICAS ==========
    printf("================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    // Calcular moda (longitud más frecuente)
    int moda = 1;
    int max_frecuencia = frecuencia[1];
    
    for (i = 2; i <= max_longitud; i++) {
        if (frecuencia[i] > max_frecuencia) {
            max_frecuencia = frecuencia[i];
            moda = i;
        }
    }
    
    // Calcular promedio de longitud
    double suma_ponderada = 0;
    for (i = 1; i <= max_longitud; i++) {
        suma_ponderada += i * frecuencia[i];
    }
    double promedio = suma_ponderada / total_palabras;
    
    printf("Total de cadenas ingresadas: %d\n", num_cadenas);
    printf("Total de palabras procesadas: %d\n\n", total_palabras);
    
    printf("Longitud minima de palabra: 1\n");
    printf("Longitud maxima de palabra: %d\n\n", max_longitud);
    
    printf("Moda (longitud mas frecuente): %d caracteres (%d palabras)\n\n", 
           moda, max_frecuencia);
    
    printf("Promedio de longitud de palabras: %.2f caracteres\n\n", promedio);
    
    // ========== DISTRIBUCION ==========
    printf("================================================\n");
    printf("DISTRIBUCION DE FRECUENCIAS\n");
    printf("================================================\n\n");
    
    printf("Palabras cortas (1-3 caracteres): ");
    int cortas = 0;
    for (i = 1; i <= 3; i++) {
        cortas += frecuencia[i];
    }
    printf("%d (%.2f%%)\n", cortas, (cortas * 100.0) / total_palabras);
    
    printf("Palabras medianas (4-7 caracteres): ");
    int medianas = 0;
    for (i = 4; i <= 7; i++) {
        medianas += frecuencia[i];
    }
    printf("%d (%.2f%%)\n", medianas, (medianas * 100.0) / total_palabras);
    
    printf("Palabras largas (8+ caracteres): ");
    int largas = 0;
    for (i = 8; i <= max_longitud; i++) {
        largas += frecuencia[i];
    }
    printf("%d (%.2f%%)\n\n", largas, (largas * 100.0) / total_palabras);
    
    // ========== GRAFICO DE BARRAS ==========
    printf("================================================\n");
    printf("GRAFICO DE BARRAS\n");
    printf("================================================\n\n");
    
    for (i = 1; i <= max_longitud; i++) {
        printf("Longitud %2d | ", i);
        
        // Mostrar barras
        int barras = frecuencia[i];
        for (j = 0; j < barras && j < 40; j++) {
            printf("█");
        }
        
        printf(" %d\n", frecuencia[i]);
    }
    
    printf("\n================================================\n\n");
    
    return 0;
}