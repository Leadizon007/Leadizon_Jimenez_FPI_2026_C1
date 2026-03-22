#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int VEC1[100];              // primer arreglo ordenado ascendente
    int VEC2[100];              // segundo arreglo ordenado ascendente
    int VEC3[200];              // arreglo resultado (mezcla ordenada)
    int N, M;                   // tamaño de VEC1 y VEC2
    int total;                  // tamaño total del arreglo resultado
    int i, j, k;                // contadores para bucles
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("MEZCLAR DOS ARREGLOS ORDENADOS ASCENDENTE (PS5.9)\n");
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
    printf("(EN ORDEN ASCENDENTE):\n");
    printf("================================================\n\n");
    
    for (i = 0; i < M; i++) {
        printf("VEC2[%d]: ", i + 1);
        scanf("%d", &VEC2[i]);
    }
    
    // ========== MEZCLA DE ARREGLOS ORDENADOS ==========
    printf("\n================================================\n");
    printf("Mezclando los arreglos ordenados...\n");
    printf("================================================\n\n");
    
    // Usar dos apuntadores para recorrer VEC1 y VEC2
    i = 0;  // indice para VEC1
    j = 0;  // indice para VEC2
    k = 0;  // indice para VEC3
    
    // Comparar elementos de ambos arreglos
    while (i < N && j < M) {
        if (VEC1[i] <= VEC2[j]) {
            VEC3[k] = VEC1[i];
            i++;
        } else {
            VEC3[k] = VEC2[j];
            j++;
        }
        k++;
    }
    
    // Copiar elementos restantes de VEC1
    while (i < N) {
        VEC3[k] = VEC1[i];
        i++;
        k++;
    }
    
    // Copiar elementos restantes de VEC2
    while (j < M) {
        VEC3[k] = VEC2[j];
        j++;
        k++;
    }
    
    total = N + M;
    
    printf("Arreglos mezclados correctamente.\n");
    printf("Total de elementos: %d\n\n", total);
    
    // ========== MOSTRAR PRIMER ARREGLO ==========
    printf("================================================\n");
    printf("PRIMER ARREGLO (VEC1) - %d ELEMENTOS\n", N);
    printf("================================================\n\n");
    
    printf("Indice |  Valor\n");
    printf("--------|--------\n");
    
    for (i = 0; i < N; i++) {
        printf("  %2d   |  %5d\n", i + 1, VEC1[i]);
    }
    
    // ========== MOSTRAR SEGUNDO ARREGLO ==========
    printf("\n================================================\n");
    printf("SEGUNDO ARREGLO (VEC2) - %d ELEMENTOS\n", M);
    printf("================================================\n\n");
    
    printf("Indice |  Valor\n");
    printf("--------|--------\n");
    
    for (i = 0; i < M; i++) {
        printf("  %2d   |  %5d\n", i + 1, VEC2[i]);
    }
    
    // ========== MOSTRAR ARREGLO RESULTADO ==========
    printf("\n================================================\n");
    printf("ARREGLO RESULTADO (MEZCLA ORDENADA ASCENDENTE)\n");
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
    
    printf("Elemento menor: %d\n", VEC3[0]);
    printf("Elemento mayor: %d\n\n", VEC3[total - 1]);
    
    printf("================================================\n\n");
    
    return 0;
}