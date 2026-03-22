#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char ARC[10][50];           // arreglo de 10 cadenas de máximo 50 caracteres
    int num_cadenas = 0;        // número de cadenas ingresadas
    int mayusculas[10];         // arreglo para contar mayúsculas de cada cadena
    int mayor_mayusculas = -1;  // mayor número de mayúsculas encontrado
    int indice_mayor = -1;      // índice de la cadena con más mayúsculas
    int i, j;                   // contadores
    char respuesta;             // respuesta del usuario
    int longitud;               // longitud de cadena
    int contador_mayusculas;    // contador de mayúsculas actual
    char caracter;              // carácter actual
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("CADENA CON MAYOR NUMERO DE MAYUSCULAS (PS7.12)\n");
    printf("================================================\n\n");
    
    printf("Este programa lee varias cadenas y encuentra\n");
    printf("la que tiene el mayor numero de letras mayusculas.\n\n");
    
    printf("Se pueden ingresar hasta 10 cadenas.\n");
    printf("Cada cadena puede tener hasta 50 caracteres.\n\n");
    
    printf("Mayusculas consideradas: A-Z\n\n");
    
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
    
    // ========== CONTAR MAYUSCULAS EN CADA CADENA ==========
    printf("================================================\n");
    printf("CONTANDO LETRAS MAYUSCULAS\n");
    printf("================================================\n\n");
    
    for (i = 0; i < num_cadenas; i++) {
        contador_mayusculas = 0;
        longitud = strlen(ARC[i]);
        
        printf("Cadena %d: %s\n", i + 1, ARC[i]);
        printf("Mayusculas encontradas: ");
        
        // Contar mayúsculas
        for (j = 0; j < longitud; j++) {
            caracter = ARC[i][j];
            
            if (isupper(caracter)) {
                contador_mayusculas++;
                printf("%c ", caracter);
            }
        }
        
        mayusculas[i] = contador_mayusculas;
        printf("\nTotal de mayusculas: %d\n\n", contador_mayusculas);
        
        // Actualizar mayor
        if (contador_mayusculas > mayor_mayusculas) {
            mayor_mayusculas = contador_mayusculas;
            indice_mayor = i;
        }
    }
    
    // ========== TABLA DE MAYUSCULAS ==========
    printf("================================================\n");
    printf("TABLA DE MAYUSCULAS POR CADENA\n");
    printf("================================================\n\n");
    
    printf("Num | Cadena                            | Mayusc. | Mayor?\n");
    printf"----|-----------------------------------|---------|-------\n");
    
    for (i = 0; i < num_cadenas; i++) {
        printf(" %d  | %-35s | %7d | ", i + 1, ARC[i], mayusculas[i]);
        
        if (i == indice_mayor) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    }
    
    // ========== TABLA DETALLADA DE ANALISIS ==========
    printf("\n================================================\n");
    printf("ANALISIS DETALLADO DE CADA CADENA\n");
    printf("================================================\n\n");
    
    for (i = 0; i < num_cadenas; i++) {
        printf("Cadena %d: %s\n", i + 1, ARC[i]);
        printf("Longitud: %lu caracteres\n", strlen(ARC[i]));
        printf("Mayusculas: %d\n", mayusculas[i]);
        
        longitud = strlen(ARC[i]);
        int minusculas = 0;
        int digitos = 0;
        int especiales = 0;
        
        for (j = 0; j < longitud; j++) {
            caracter = ARC[i][j];
            
            if (isupper(caracter)) {
                // Ya contamos mayúsculas
            } else if (islower(caracter)) {
                minusculas++;
            } else if (isdigit(caracter)) {
                digitos++;
            } else {
                especiales++;
            }
        }
        
        printf("Minusculas: %d\n", minusculas);
        printf("Digitos: %d\n", digitos);
        printf("Caracteres especiales: %d\n", especiales);
        
        if (longitud > 0) {
            printf("Porcentaje de mayusculas: %.2f%%\n\n", 
                   (mayusculas[i] * 100.0) / longitud);
        }
    }
    
    // ========== TABLA DE CARACTERES DE CADENA CON MAS MAYUSCULAS ==========
    printf("================================================\n");
    printf("TABLA DE CARACTERES - CADENA CON MAS MAYUSCULAS\n");
    printf("================================================\n\n");
    
    printf("Cadena: %s\n\n", ARC[indice_mayor]);
    
    printf("Pos | Caracter | Tipo\n");
    printf("----|----------|------------------\n");
    
    longitud = strlen(ARC[indice_mayor]);
    for (j = 0; j < longitud; j++) {
        caracter = ARC[indice_mayor][j];
        
        printf(" %2d |    %c    | ", j + 1, caracter);
        
        if (isupper(caracter)) {
            printf("MAYUSCULA\n");
        } else if (islower(caracter)) {
            printf("Minuscula\n");
        } else if (isdigit(caracter)) {
            printf("Digito\n");
        } else if (caracter == ' ') {
            printf("Espacio\n");
        } else {
            printf("Especial\n");
        }
    }
    
    // ========== COMPARACION CON OTRAS CADENAS ==========
    printf("\n================================================\n");
    printf("COMPARACION CON OTRAS CADENAS\n");
    printf("================================================\n\n");
    
    printf("Cadena ganadora: %s\n", ARC[indice_mayor]);
    printf("Mayusculas: %d\n\n", mayor_mayusculas);
    
    printf("Comparativa con otras cadenas:\n");
    printf("Cadena | Mayusculas | Diferencia\n");
    printf("-------|----------|----------\n");
    
    for (i = 0; i < num_cadenas; i++) {
        if (i != indice_mayor) {
            int diferencia = mayor_mayusculas - mayusculas[i];
            printf("%2d     |    %2d      |    +%d\n", i + 1, mayusculas[i], diferencia);
        }
    }
    
    // ========== RESULTADO FINAL ==========
    printf("\n================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Total de cadenas ingresadas: %d\n\n", num_cadenas);
    
    printf("Cadena con MAYOR numero de mayusculas:\n");
    printf("  Numero de orden: %d\n", indice_mayor + 1);
    printf("  Contenido: %s\n", ARC[indice_mayor]);
    printf("  Mayusculas: %d\n\n", mayor_mayusculas);
    
    // ========== ESTADISTICAS ==========
    printf("================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    // Calcular estadísticas
    int suma_mayusculas = 0;
    int minimo_mayusculas = mayusculas[0];
    int maximo_mayusculas = mayusculas[0];
    
    for (i = 0; i < num_cadenas; i++) {
        suma_mayusculas += mayusculas[i];
        
        if (mayusculas[i] < minimo_mayusculas) {
            minimo_mayusculas = mayusculas[i];
        }
        if (mayusculas[i] > maximo_mayusculas) {
            maximo_mayusculas = mayusculas[i];
        }
    }
    
    double promedio_mayusculas = suma_mayusculas / (double)num_cadenas;
    
    printf("Minimo de mayusculas encontrado: %d\n", minimo_mayusculas);
    printf("Maximo de mayusculas encontrado: %d\n", maximo_mayusculas);
    printf("Promedio de mayusculas por cadena: %.2f\n\n", promedio_mayusculas);
    
    printf("Suma total de mayusculas: %d\n", suma_mayusculas);
    printf("Cadenas analizadas: %d\n\n", num_cadenas);
    
    // ========== RANKING DE MAYUSCULAS ==========
    printf("================================================\n");
    printf("RANKING DE CADENAS POR NUMERO DE MAYUSCULAS\n");
    printf("================================================\n\n");
    
    // Crear arreglo de índices ordenado
    int indices[10];
    for (i = 0; i < num_cadenas; i++) {
        indices[i] = i;
    }
    
    // Ordenar índices por número de mayúsculas (de mayor a menor)
    for (i = 0; i < num_cadenas - 1; i++) {
        for (j = 0; j < num_cadenas - i - 1; j++) {
            if (mayusculas[indices[j]] < mayusculas[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    
    printf("Rango | Cadena                            | Mayusculas | Porcentaje\n");
    printf("------|-----------------------------------|------------|----------\n");
    
    for (i = 0; i < num_cadenas; i++) {
        int idx = indices[i];
        int longitud_cad = strlen(ARC[idx]);
        double porcentaje = 0;
        
        if (longitud_cad > 0) {
            porcentaje = (mayusculas[idx] * 100.0) / longitud_cad;
        }
        
        printf(" %2d   | %-35s | %10d | %7.2f%%\n", 
               i + 1, ARC[idx], mayusculas[idx], porcentaje);
    }
    
    printf("\n================================================\n\n");
    
    return 0;
}