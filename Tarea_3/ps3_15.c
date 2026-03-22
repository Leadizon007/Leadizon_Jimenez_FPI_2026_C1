#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N1, N2;         // números naturales para calcular MCD
    int residuo;        // residuo de la división
    int N1Original;     // copia de N1 para mostrar al final
    int N2Original;     // copia de N2 para mostrar al final
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    MAXIMO COMUN DIVISOR (MCD)\n");
    printf("    Algoritmo de Euclides\n");
    printf("================================================\n\n");
    
    printf("Ingrese el primer numero natural N1: ");
    scanf("%d", &N1);
    
    printf("Ingrese el segundo numero natural N2: ");
    scanf("%d", &N2);
    
    // ========== VALIDACION DE DATOS ==========
    if (N1 <= 0 || N2 <= 0) {
        printf("\nError: Ambos numeros deben ser naturales (mayores a 0).\n");
        return 1;
    }
    
    // ========== GUARDAR VALORES ORIGINALES ==========
    N1Original = N1;
    N2Original = N2;
    
    // ========== PROCESAMIENTO - ALGORITMO DE EUCLIDES ==========
    printf("\n================================================\n");
    printf("Proceso de calculo (Algoritmo de Euclides):\n");
    printf("================================================\n\n");
    printf("Paso | N1  | N2  | Residuo (N1 mod N2)\n");
    printf("-----|-----|-----|---------------------\n");
    
    int paso = 1;
    
    // Bucle que aplica el algoritmo de Euclides
    // Mientras N2 no sea cero, realiza división
    while (N2 != 0) {
        residuo = N1 % N2;  // Calcula el residuo
        
        printf("%4d | %3d | %3d | %3d\n", paso, N1, N2, residuo);
        
        // Intercambia valores: N1 toma el valor de N2
        //                      N2 toma el valor del residuo
        N1 = N2;
        N2 = residuo;
        
        paso++;
    }
    
    // Cuando N2 es 0, N1 contiene el MCD
    int MCD = N1;
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n");
    printf("Numero 1 (N1): %d\n", N1Original);
    printf("Numero 2 (N2): %d\n", N2Original);
    printf("Maximo Comun Divisor (MCD): %d\n", MCD);
    printf("================================================\n\n");
    
    // ========== VERIFICACION ==========
    printf("Verificacion:\n");
    printf("%d = %d × %d\n", N1Original, MCD, N1Original / MCD);
    printf("%d = %d × %d\n", N2Original, MCD, N2Original / MCD);
    printf("================================================\n\n");
    
    return 0;
}