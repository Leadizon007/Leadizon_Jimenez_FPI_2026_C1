#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;              // cantidad de números naturales
    int i;              // contador para el bucle
    long long productoria;  // productoria (usamos long long para números grandes)
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================\n");
    printf("   PRODUCTORIA DE N NUMEROS\n");
    printf("================================\n\n");
    
    printf("Ingrese la cantidad de numeros naturales N: ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N <= 0) {
        printf("\nError: N debe ser un numero positivo (mayor a 0).\n");
        return 1;
    }
    
    // ========== PROCESAMIENTO ==========
    // Inicializamos la productoria en 1
    productoria = 1;
    
    printf("\nCalculando la productoria de los %d primeros numeros naturales:\n\n", N);
    
    // Bucle que multiplica los números del 1 al N
    for (i = 1; i <= N; i++) {
        productoria = productoria * i;  // Multiplica el número actual
        printf("Paso %d: %lld x %d = %lld\n", i, productoria / i, i, productoria);
    }
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================\n");
    printf("N = %d\n", N);
    printf("Productoria: %d! = %lld\n", N, productoria);
    printf("================================\n\n");
    
    return 0;
}