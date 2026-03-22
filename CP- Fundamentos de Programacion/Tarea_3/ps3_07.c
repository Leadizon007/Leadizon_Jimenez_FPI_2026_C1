#include <stdio.h>
#include <math.h>  // Librería para usar la función pow()

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;              // número de términos de la serie
    int i;              // contador para el bucle
    double suma;        // suma acumulada de la serie
    double termino;     // cada término de la serie
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================\n");
    printf("   SERIE ALTERNADA CON POTENCIAS\n");
    printf("================================\n\n");
    
    printf("Ingrese la cantidad de terminos N: ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N <= 0) {
        printf("\nError: N debe ser un numero positivo (mayor a 0).\n");
        return 1;
    }
    
    // ========== PROCESAMIENTO ==========
    // Inicializamos la suma en cero
    suma = 0.0;
    
    printf("\nCalculando la serie:\n");
    printf("Seria: 1^1 - 2^2 + 3^3 - 4^4 + ... +/- %d^%d\n\n", N, N);
    
    // Bucle que calcula los términos alternados
    for (i = 1; i <= N; i++) {
        // Calcula el término: i elevado a la potencia i
        termino = pow(i, i);
        
        // Si i es impar, suma; si es par, resta
        if (i % 2 == 1) {
            // i es impar: suma
            suma = suma + termino;
            printf("Termino %d: +%d^%d = +%.0f  |  Suma parcial: %.0f\n", 
                   i, i, i, termino, suma);
        } else {
            // i es par: resta
            suma = suma - termino;
            printf("Termino %d: -%d^%d = -%.0f  |  Suma parcial: %.0f\n", 
                   i, i, i, termino, suma);
        }
    }
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================\n");
    printf("Cantidad de terminos (N): %d\n", N);
    printf("Serie: 1^1 - 2^2 + 3^3 - 4^4 + ... +/- %d^%d\n", N, N);
    printf("Suma total: %.0f\n", suma);
    printf("================================\n\n");
    
    return 0;
}