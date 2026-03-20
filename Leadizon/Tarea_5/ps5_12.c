#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int VEC[100];               // arreglo unidimensional
    int N;                      // número de elementos
    int i;                      // contador para bucles
    int es_palindromo = 1;      // bandera: 1 = sí, 0 = no
    int inicio, fin;            // índices para comparar desde los extremos
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    VERIFICAR SI ARREGLO ES PALINDROMO (PS5.12)\n");
    printf("================================================\n\n");
    
    printf("Un arreglo es palindromo si se lee igual de\n");
    printf("izquierda a derecha que de derecha a izquierda.\n\n");
    
    printf("Ejemplo: 2 4 5 4 2 es palindromo\n\n");
    
    printf("Ingrese el numero de elementos N (1-100): ");
    scanf("%d", &N);
    
    // ========== VALIDACION ==========
    if (N < 1 || N > 100) {
        printf("\nError: N debe estar entre 1 y 100.\n");
        return 1;
    }
    
    // ========== LECTURA DEL ARREGLO ==========
    printf("\nIngrese los %d elementos del arreglo:\n\n", N);
    
    for (i = 0; i < N; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &VEC[i]);
    }
    
    // ========== PROCESAMIENTO - VERIFICAR PALINDROMO ==========
    printf("\n================================================\n");
    printf("Verificando si el arreglo es palindromo...\n");
    printf("================================================\n\n");
    
    // Comparar elementos desde los extremos hacia el centro
    inicio = 0;
    fin = N - 1;
    
    while (inicio < fin) {
        if (VEC[inicio] != VEC[fin]) {
            // Si no son iguales, no es palíndromo
            es_palindromo = 0;
            break;
        }
        inicio++;
        fin--;
    }
    
    // ========== MOSTRAR ARREGLO ==========
    printf("================================================\n");
    printf("ARREGLO INGRESADO\n");
    printf("================================================\n\n");
    
    printf("Indice |  Valor\n");
    printf("--------|--------\n");
    
    for (i = 0; i < N; i++) {
        printf("  %2d   |  %5d\n", i + 1, VEC[i]);
    }
    
    // ========== MOSTRAR ARREGLO EN FORMA VISUAL ==========
    printf("\n");
    printf("Valores en linea: ");
    for (i = 0; i < N; i++) {
        printf("%d ", VEC[i]);
    }
    printf("\n\n");
    
    // ========== RESULTADO FINAL ==========
    printf("================================================\n");
    printf("RESULTADO\n");
    printf("================================================\n\n");
    
    if (es_palindromo) {
        printf("El arreglo ES PALINDROMO\n\n");
        printf("Se lee igual de izquierda a derecha que de\n");
        printf("derecha a izquierda.\n\n");
        
        printf("Lectura izquierda a derecha: ");
        for (i = 0; i < N; i++) {
            printf("%d ", VEC[i]);
        }
        printf("\n");
        
        printf("Lectura derecha a izquierda: ");
        for (i = N - 1; i >= 0; i--) {
            printf("%d ", VEC[i]);
        }
        printf("\n\n");
    } else {
        printf("El arreglo NO ES PALINDROMO\n\n");
        printf("No se lee igual de izquierda a derecha que de\n");
        printf("derecha a izquierda.\n\n");
    }
    
    // ========== ANALISIS DETALLADO ==========
    printf("================================================\n");
    printf("ANALISIS DETALLADO DE COMPARACIONES\n");
    printf("================================================\n\n");
    
    printf("Comparaciones realizadas:\n\n");
    printf("Posicion Izq | Posicion Der | Valor Izq | Valor Der | Resultado\n");
    printf("--------------|--------------|-----------|-----------|----------\n");
    
    inicio = 0;
    fin = N - 1;
    
    while (inicio < fin) {
        printf("     %2d      |      %2d      |    %2d     |    %2d     | ", 
               inicio + 1, fin + 1, VEC[inicio], VEC[fin]);
        
        if (VEC[inicio] == VEC[fin]) {
            printf("IGUAL\n");
        } else {
            printf("DIFERENTE\n");
        }
        
        inicio++;
        fin--;
    }
    
    printf("\n");
    
    // ========== ESTADISTICAS ==========
    printf("================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    printf("Total de elementos: %d\n", N);
    
    if (N % 2 == 0) {
        printf("Tipo de arreglo: Longitud PAR\n");
        printf("Comparaciones necesarias: %d\n\n", N / 2);
    } else {
        printf("Tipo de arreglo: Longitud IMPAR\n");
        printf("Elemento central: VEC[%d] = %d\n", (N / 2) + 1, VEC[N / 2]);
        printf("Comparaciones necesarias: %d\n\n", N / 2);
    }
    
    printf("Conclusión: El arreglo %s PALINDROMO\n\n", 
           es_palindromo ? "ES" : "NO ES");
    
    printf("================================================\n\n");
    
    return 0;
}