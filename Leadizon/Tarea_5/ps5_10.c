#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int VEC1[100];              // primer arreglo ordenado ascendente
    int VEC2[100];              // segundo arreglo ordenado descendente
    int VEC3[200];              // arreglo resultado (mezcla ascendente)
    int N, M;                   // tamaño de VEC1 y VEC2
    int total;                  // tamaño total del arreglo resultado
    int i, j, k;                // contadores para bucles
    int temp;                   // variable auxiliar para intercambio
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("MEZCLAR ARREGLOS CON ORDENES DIFERENTES (PS5.10)\n");
    printf("================================================\n\n");
    
    printf("Ingrese el numero de elementos del primer arreglo N (1-100): ");
    scanf("%d", &N);
    
    // ========== VALIDACION N ==========
    if (N < 1 || N > 100) {
        printf("\nError: N debe estar entre 1 y 100.\n");
        return 1;
    }
    
    printf("Ingrese el numero de elementos del segundo arreglo M (1-100): ");
    scanf("%d", &M);
    
    // ========== VALIDACION M ==========
    if (M < 1 || M > 100) {
        printf("\nError: M debe estar entre 1 y 100.\n");
        return 1;
    }
    
    // ========== LECTURA DEL PRIMER ARREGLO ==========
    printf("\n================================================\n");
    printf("Ingrese los %d elementos del primer arreglo\n", N);
    printf("(EN ORDEN ASCENDENTE):\n");
    printf("================================================\n\n");
    
    for (i = 0; i < N; i++) {
        printf("VEC1[%d]: ", i + 1);
        scanf("%d", &VEC1[i]);
    }
    
    // ========== LECTURA DEL SEGUNDO ARREGLO ==========
    printf("\n================================================\n");
    printf("Ingrese los %d elementos del segundo arreglo\n", M);
    printf("(EN ORDEN DESCENDENTE):\n");
    printf("================================================\n\n");
    
    for (i = 0; i < M; i++) {
        printf("VEC2[%d]: ", i + 1);
        scanf("%d", &VEC2[i]);
    }
    
    // ========== PROCESAMIENTO ==========
    printf("\n================================================\n");
    printf("Procesando mezcla de arreglos...\n");
    printf("================================================\n\n");
    
    // Copiar elementos de VEC1 a VEC3
    for (i = 0; i < N; i++) {
        VEC3[i] = VEC1[i];
    }
    
    // Copiar elementos de VEC2 a VEC3
    for (i = 0; i < M; i++) {
        VEC3[N + i] = VEC2[i];
    }
    
    total = N + M;
    
    printf("Arreglos copiados a VEC3: %d + %d = %d elementos\n\n", N, M, total);
    
    // ========== ORDENAMIENTO ASCENDENTE ==========
    printf("Ordenando VEC3 en forma ASCENDENTE...\n");
    printf("(usando algoritmo de burbuja)\n\n");
    
    // Algoritmo de burbuja para ordenar en forma ascendente
    for (i = 0; i < total - 1; i++) {
        for (j = 0; j < total - i - 1; j++) {
            // Comparación para orden ascendente (menor primero)
            if (VEC3[j] > VEC3[j + 1]) {
                // Intercambio
                temp = VEC3[j];
                VEC3[j] = VEC3[j + 1];
                VEC3[j + 1] = temp;
            }
        }
    }
    
    // ========== MOSTRAR PRIMER ARREGLO ==========
    printf("================================================\n");
    printf("PRIMER ARREGLO (VEC1) - %d ELEMENTOS\n", N);
    printf("ORDENADO ASCENDENTE\n");
    printf("================================================\n\n");
    
    printf("Indice |  Valor\n");
    printf("--------|--------\n");
    
    for (i = 0; i < N; i++) {
        printf("  %2d   |  %5d\n", i + 1, VEC1[i]);
    }
    
    // ========== MOSTRAR SEGUNDO ARREGLO ==========
    printf("\n================================================\n");
    printf("SEGUNDO ARREGLO (VEC2) - %d ELEMENTOS\n", M);
    printf("ORDENADO DESCENDENTE\n");
    printf("================================================\n\n");
    
    printf("Indice |  Valor\n");
    printf("--------|--------\n");
    
    for (i = 0; i < M; i++) {
        printf("  %2d   |  %5d\n", i + 1, VEC2[i]);
    }
    
    // ========== MOSTRAR ARREGLO RESULTADO ==========
    printf("\n================================================\n");
    printf("ARREGLO RESULTADO (VEC3) - %d ELEMENTOS\n", total);
    printf("ORDENADO ASCENDENTE\n");
    printf("================================================\n\n");
    
    printf("Indice |  Valor\n");
    printf("--------|--------\n");
    
    for (i = 0; i < total; i++) {
        printf("  %2d   |  %5d\n", i + 1, VEC3[i]);
    }
    
    // ========== ESTADISTICAS ==========
    printf("\n================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    printf("Elementos del primer arreglo:  %d (ascendente)\n", N);
    printf("Elementos del segundo arreglo: %d (descendente)\n", M);
    printf("Elementos del arreglo final:   %d (ascendente)\n\n", total);
    
    printf("Elemento menor: %d\n", VEC3[0]);
    printf("Elemento mayor: %d\n", VEC3[total - 1]);
    printf("Rango: %d\n\n", VEC3[total - 1] - VEC3[0]);
    
    printf("================================================\n\n");
    
    return 0;
}