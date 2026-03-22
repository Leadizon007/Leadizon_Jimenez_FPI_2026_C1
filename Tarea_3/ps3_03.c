#include <stdio.h>
#include <math.h>  // Librería para usar la función pow()

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;          // número de términos de la serie
    int i;          // contador para el bucle
    double suma;    // suma acumulada de la serie
    double termino; // cada término de la serie: (1/i)^i
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================\n");
    printf("  SERIE DE POTENCIAS DE FRACCIONES\n");
    printf("================================\n\n");
    
    printf("Ingrese la cantidad de terminos N: ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N <= 0) {
        printf("\nError: N debe ser un numero positivo (mayor a 0).\n");
        printf("Por favor, intente nuevamente.\n");
        return 1;  // Termina el programa con error
    }
    
    // ========== PROCESAMIENTO ==========
    // Inicializamos la suma en cero
    suma = 0.0;
    
    printf("\n================================\n");
    printf("Calculando la serie:\n");
    printf("================================\n\n");
    
    // Bucle que calcula los términos: (1/1)^1 + (1/2)^2 + (1/3)^3 + ... + (1/N)^N
    for (i = 1; i <= N; i++) {
        // Calcula el término: (1/i) elevado a la potencia i
        termino = pow(1.0 / i, i);
        
        // Acumula el término a la suma
        suma = suma + termino;
        
        // Muestra cada término y la suma parcial
        printf("Termino %d: (1/%d)^%d = %.8f  |  Suma parcial: %.8f\n", 
               i, i, i, termino, suma);
    }
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================\n");
    printf("Cantidad de terminos (N): %d\n", N);
    printf("Serie: (1/1)^1 + (1/2)^2 + (1/3)^3 + ... + (1/%d)^%d\n", N, N);
    printf("Suma total: %.8f\n", suma);
    printf("================================\n\n");
    
    return 0;  // Termina el programa correctamente
}