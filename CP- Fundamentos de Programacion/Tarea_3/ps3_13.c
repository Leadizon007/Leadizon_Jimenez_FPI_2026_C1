#include <stdio.h>

// ========== FUNCION AUXILIAR ==========
// Función que verifica si un número es primo
int esPrimo(int numero) {
    int j;
    
    // Números menores a 2 no son primos
    if (numero < 2) {
        return 0;
    }
    
    // Verifica divisores desde 2 hasta la raíz cuadrada del número
    for (j = 2; j * j <= numero; j++) {
        if (numero % j == 0) {
            return 0;  // No es primo
        }
    }
    
    return 1;  // Es primo
}

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N1, N2;         // números límite del rango
    int i;              // contador para el bucle
    int contGemelos = 0;  // contador de pares de primos gemelos
    int temporal;       // variable temporal para ordenar N1 y N2
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("        NUMEROS PRIMOS GEMELOS\n");
    printf("================================================\n\n");
    
    printf("Ingrese el primer numero entero positivo: ");
    scanf("%d", &N1);
    
    printf("Ingrese el segundo numero entero positivo: ");
    scanf("%d", &N2);
    
    // ========== VALIDACION DE DATOS ==========
    if (N1 <= 0 || N2 <= 0) {
        printf("\nError: Ambos numeros deben ser positivos.\n");
        return 1;
    }
    
    // ========== ORDENAMIENTO DE LOS NUMEROS ==========
    // Si N1 es mayor que N2, los intercambia
    if (N1 > N2) {
        temporal = N1;
        N1 = N2;
        N2 = temporal;
    }
    
    // ========== PROCESAMIENTO Y SALIDA ==========
    printf("\n================================================\n");
    printf("Primos gemelos entre %d y %d:\n", N1, N2);
    printf("================================================\n\n");
    
    // Bucle que verifica cada número en el rango
    for (i = N1; i < N2 - 1; i++) {
        // Verifica si i y (i+2) son ambos primos
        if (esPrimo(i) && esPrimo(i + 2)) {
            printf("(%d, %d)\n", i, i + 2);
            contGemelos++;
        }
    }
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n");
    printf("Rango: %d a %d\n", N1, N2);
    printf("Pares de primos gemelos encontrados: %d\n", contGemelos);
    
    if (contGemelos == 0) {
        printf("No hay primos gemelos en este rango.\n");
    }
    
    printf("================================================\n\n");
    
    return 0;
}