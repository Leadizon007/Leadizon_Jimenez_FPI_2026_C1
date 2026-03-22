#include <stdio.h>
#include <math.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;                      // número de términos de la serie
    int i;                      // contador para los bucles
    double suma = 0.0;          // suma acumulada de la serie
    double termino;             // término actual de la serie
    int numerador;              // numerador del término (siempre 1)
    int denominador;            // denominador del término (2, 3, 4, ..., N)
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("        CALCULO DE SERIE MATEMATICA (PS3.3)\n");
    printf("================================================\n\n");
    
    printf("Serie: 1/2 + 1/3 + 1/4 + ... + 1/N\n\n");
    
    printf("Ingrese el numero de terminos N (N >= 2): ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N < 2) {
        printf("\nError: N debe ser mayor o igual a 2.\n");
        return 1;
    }
    
    // ========== PROCESAMIENTO - CALCULO DE LA SERIE ==========
    printf("\n================================================\n");
    printf("Calculando la serie con %d terminos:\n", N);
    printf("================================================\n\n");
    
    printf("Termino | Denominador | Valor del termino | Suma acumulada\n");
    printf("--------|-------------|-------------------|----------------\n");
    
    // Bucle para calcular cada término de la serie
    for (i = 1; i <= N - 1; i++) {
        denominador = i + 1;        // denominador va de 2 a N
        numerador = 1;              // numerador siempre es 1
        
        termino = (double)numerador / denominador;
        suma += termino;
        
        printf("  %2d    |      %2d      |      %.6f       |    %.6f\n", 
               i, denominador, termino, suma);
    }
    
    // ========== RESULTADO FINAL ==========
    printf("\n================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Numero de terminos (N):     %d\n", N);
    printf("Serie:                      1/2 + 1/3 + 1/4 + ... + 1/%d\n", N);
    printf("Suma total de la serie:     %.10f\n\n", suma);
    
    printf("================================================\n");
    printf("DESGLOSE DE LA SERIE\n");
    printf("================================================\n\n");
    
    // Mostrar desglose detallado
    printf("Expresion: ");
    for (i = 2; i <= N; i++) {
        printf("1/%d", i);
        if (i < N) {
            printf(" + ");
        }
    }
    printf("\n\n");
    
    printf("Resultado: %.10f\n\n", suma);
    
    printf("================================================\n\n");
    
    return 0;
}