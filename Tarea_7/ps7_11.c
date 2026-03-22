#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char ARC[10][50];           // arreglo de 10 cadenas de máximo 50 caracteres
    int num_cadenas = 0;        // número de cadenas ingresadas
    int vocales[10];            // arreglo para contar vocales de cada cadena
    int mayor_vocales = -1;     // mayor número de vocales encontrado
    int indice_mayor = -1;      // índice de la cadena con más vocales
    int i, j;                   // contadores
    char respuesta;             // respuesta del usuario
    int longitud;               // longitud de cadena
    int contador_vocales;       // contador de vocales actual
    char caracter;              // carácter actual
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("CADENA CON MAYOR NUMERO DE VOCALES (PS7.11)\n");
    printf("================================================\n\n");
    
    printf("Este programa lee varias cadenas y encuentra\n");
    printf("la que tiene el mayor numero de vocales.\n\n");
    
    printf("Se pueden ingresar hasta 10 cadenas.\n");
    printf("Cada cadena puede tener hasta 50 caracteres.\n\n");
    
    printf("Vocales consideradas: a, e, i, o, u (mayúsculas y minúsculas)\n\n");
    
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
    
    // ========== CONTAR VOCALES EN CADA CADENA ==========
    printf("================================================\n");
    printf("CONTANDO VOCALES\n");
    printf("================================================\n\n");
    
    for (i = 0; i < num_cadenas; i++) {
        contador_vocales = 0;
        longitud = strlen(ARC[i]);
        
        printf("Cadena %d: %s\n", i + 1, ARC[i]);
        printf("Vocales encontradas: ");
        
        // Contar vocales
        for (j = 0; j < longitud; j++) {
            caracter = tolower(ARC[i][j]);
            
            if (caracter == 'a' || caracter == 'e' || caracter == 'i' || 
                caracter == 'o' || caracter == 'u') {
                contador_vocales++;
                printf("%c ", ARC[i][j]);
            }
        }
        
        vocales[i] = contador_vocales;
        printf("\nTotal de vocales: %d\n\n", contador_vocales);
        
        // Actualizar mayor
        if (contador_vocales > mayor_vocales) {
            mayor_vocales = contador_vocales;
            indice_mayor = i;
        }
    }
    
    // ========== TABLA DE VOCALES ==========
    printf("================================================\n");
    printf("TABLA DE VOCALES POR CADENA\n");
    printf("================================================\n\n");
    
    printf("Num | Cadena                            | Vocales | Mayor?\n");
    printf"----|-----------------------------------|---------|-------\n");
    
    for (i = 0; i < num_cadenas; i++) {
        printf(" %d  | %-35s | %7d | ", i + 1, ARC[i], vocales[i]);
        
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
        printf("Total de vocales: %d\n", vocales[i]);
        
        longitud = strlen(ARC[i]);
        int consonantes = 0;
        int digitos = 0;
        int otros = 0;
        
        for (j = 0; j < longitud; j++) {
            caracter = tolower(ARC[i][j]);
            
            if (caracter == 'a' || caracter == 'e' || caracter == 'i' || 
                caracter == 'o' || caracter == 'u') {
                // Ya contamos vocales
            } else if (isalpha(ARC[i][j])) {
                consonantes++;
            } else if (isdigit(ARC[i][j])) {
                digitos++;
            } else {
                otros++;
            }
        }
        
        printf("Consonantes: %d\n", consonantes);
        printf("Dígitos: %d\n", digitos);
        printf("Otros caracteres: %d\n", otros);
        
        if (longitud > 0) {
            printf("Porcentaje de vocales: %.2f%%\n\n", 
                   (vocales[i] * 100.0) / longitud);
        }
    }
    
    // ========== TABLA DE CARACTERES DE CADENA CON MAS VOCALES ==========
    printf("================================================\n");
    printf("TABLA DE CARACTERES - CADENA CON MAS VOCALES\n");
    printf("================================================\n\n");
    
    printf("Cadena: %s\n\n", ARC[indice_mayor]);
    
    printf("Pos | Caracter | Tipo\n");
    printf("----|----------|----------\n");
    
    longitud = strlen(ARC[indice_mayor]);
    for (j = 0; j < longitud; j++) {
        caracter = tolower(ARC[indice_mayor][j]);
        
        printf(" %2d |    %c    | ", j + 1, ARC[indice_mayor][j]);
        
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || 
            caracter == 'o' || caracter == 'u') {
            printf("VOCAL\n");
        } else if (isalpha(ARC[indice_mayor][j])) {
            printf("Consonante\n");
        } else if (isdigit(ARC[indice_mayor][j])) {
            printf("Digito\n");
        } else if (ARC[indice_mayor][j] == ' ') {
            printf("Espacio\n");
        } else {
            printf("Especial\n");
        }
    }
    
    // ========== RESULTADO FINAL ==========
    printf("\n================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Total de cadenas ingresadas: %d\n\n", num_cadenas);
    
    printf("Cadena con MAYOR numero de vocales:\n");
    printf("  Numero de orden: %d\n", indice_mayor + 1);
    printf("  Contenido: %s\n", ARC[indice_mayor]);
    printf("  Vocales: %d\n\n", mayor_vocales);
    
    // ========== ESTADISTICAS ==========
    printf("================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    // Calcular promedio de vocales
    int suma_vocales = 0;
    int minimo_vocales = vocales[0];
    int maximo_vocales = vocales[0];
    
    for (i = 0; i < num_cadenas; i++) {
        suma_vocales += vocales[i];
        
        if (vocales[i] < minimo_vocales) {
            minimo_vocales = vocales[i];
        }
        if (vocales[i] > maximo_vocales) {
            maximo_vocales = vocales[i];
        }
    }
    
    double promedio_vocales = suma_vocales / (double)num_cadenas;
    
    printf("Minimo de vocales encontrado: %d\n", minimo_vocales);
    printf("Maximo de vocales encontrado: %d\n", maximo_vocales);
    printf("Promedio de vocales por cadena: %.2f\n\n", promedio_vocales);
    
    printf("Suma total de vocales: %d\n", suma_vocales);
    printf("Cadenas analizadas: %d\n\n", num_cadenas);
    
    // ========== RANKING DE VOCALES ==========
    printf("================================================\n");
    printf("RANKING DE CADENAS POR NUMERO DE VOCALES\n");
    printf("================================================\n\n");
    
    // Crear arreglo de índices ordenado
    int indices[10];
    for (i = 0; i < num_cadenas; i++) {
        indices[i] = i;
    }
    
    // Ordenar índices por número de vocales (de mayor a menor)
    for (i = 0; i < num_cadenas - 1; i++) {
        for (j = 0; j < num_cadenas - i - 1; j++) {
            if (vocales[indices[j]] < vocales[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    
    printf("Rango | Cadena                            | Vocales\n");
    printf"-----|-----------------------------------|-------\n");
    
    for (i = 0; i < num_cadenas; i++) {
        int idx = indices[i];
        printf(" %2d  | %-35s | %7d\n", i + 1, ARC[idx], vocales[idx]);
    }
    
    printf("\n================================================\n\n");
    
    return 0;
}