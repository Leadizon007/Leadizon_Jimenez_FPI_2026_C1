#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int VEC1[100];              // primer arreglo
    int VEC2[100];              // segundo arreglo
    int VEC3[200];              // arreglo resultado (mezcla)
    int N, M;                   // tamaño de VEC1 y VEC2
    int total;                  // tamaño total del arreglo resultado
    int i, j;                   // contadores para bucles
    int temp;                   // variable auxiliar para intercambio
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("  MEZCLAR Y ORDENAR DOS ARREGLOS (PS5.8)\n");
    printf("================================================\n\n");
    
    printf("Ingrese el numero de elementos del primer arreglo N (1-100): ");
    scanf("%d", &N);
    
    // ========== VALIDACION N ==========
    if (N < 1 || N > 100) {
        printf("\nError: N debe estar entre 1 y 100.\n");
        return 1;
    }
    
    printf("\nIngrese el numero de elementos del segundo arreglo M (1-100): ");
    scanf("%d", &M);
    
    // ========== VALIDACION M ==========
    if (M < 1 || M > 100) {
        printf("\nError: M debe estar entre 1 y 100.\n");
        return 1;
    }
    
    // ========== LECTURA DEL PRIMER ARREGLO ==========
    printf("\n================================================\n");
    printf("Ingrese los %d elementos del primer arreglo:\n", N);
    printf("================================================\n\n");
    
    for (i = 0; i < N; i++) {
        printf("VEC1[%d]: ", i + 1);
        scanf("%d", &VEC1[i]);
    }
    
    // ========== LECTURA DEL SEGUNDO ARREGLO ==========
    printf("\n================================================\n");
    printf("Ingrese los %d elementos del segundo arreglo:\n", M);
    printf("================================================\n\n");
    
    for (i = 0; i < M; i++) {
        printf("VEC2[%d]: ", i + 1);
        scanf("%d", &VEC2[i]);
    }
    
    // ========== MEZCLA DE ARREGLOS ==========
    printf("\n================================================\n");
    printf("Mezclando los arreglos...\n");
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
    
    printf("Primer arreglo copiado: %d elementos\n", N);
    printf("Segundo arreglo copiado: %d elementos\n", M);
    printf("Total de elementos: %d\n\n", total);
    
    // ========== ORDENAMIENTO EN FORMA DESCENDENTE ==========
    printf("================================================\n");
    printf("Ordenando en forma DESCENDENTE...\n");
    printf("================================================\n\n");
    
    // Algoritmo de burbuja para ordenar en forma descendente
    for (i = 0; i < total - 1; i++) {
        for (j = 0; j < total - i - 1; j++) {
            // Comparación para orden descendente (mayor primero)
            if (VEC3[j] < VEC3[j + 1]) {
                // Intercambio
                temp = VEC3[j];
                VEC3[j] = VEC3[j + 1];
                VEC3[j + 1] = temp;
            }
        }
    }
    
    // ========== MOSTRAR ARREGLOS ORIGINALES ==========
    printf("================================================\n");
    printf("ARREGLOS ORIGINALES\n");
    printf("================================================\n\n");
    
    printf("Primer arreglo (VEC1) - %d elementos:\n", N);
    printf("Indice |  Valor\n");
    printf("--------|--------\n");
    
    for (i = 0; i < N; i++) {
        printf("  %2d   |  %5d\n", i + 1, VEC1[i]);
    }
    
    printf("\nSegundo arreglo (VEC2) - %d elementos:\n", M);
    printf("Indice |  Valor\n");
    printf("--------|--------\n");
    
    for (i = 0; i < M; i++) {
        printf("  %2d   |  %5d\n", i + 1, VEC2[i]);
    }
    
    // ========== MOSTRAR ARREGLO RESULTADO ==========
    printf("\n================================================\n");
    printf("ARREGLO RESULTADO (MEZCLA ORDENADA EN FORMA DESCENDENTE)\n");
    printf("================================================\n\n");
    
    printf("Total de elementos: %d\n\n", total);
    printf("Indice |  Valor\n");
    printf("--------|--------\n");
    
    for (i = 0; i < total; i++) {
        printf("  %2d   |  %5d\n", i + 1, VEC3[i]);
    }
    
    // ========== ESTADISTICAS ==========
    printf("\n================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    printf("Elementos del primer arreglo:  %d\n", N);
    printf("Elementos del segundo arreglo: %d\n", M);
    printf("Elementos del arreglo final:   %d\n\n", total);
    
    printf("Elemento mayor: %d\n", VEC3[0]);
    printf("Elemento menor: %d\n\n", VEC3[total - 1]);
    
    printf("================================================\n\n");
    
    return 0;
}