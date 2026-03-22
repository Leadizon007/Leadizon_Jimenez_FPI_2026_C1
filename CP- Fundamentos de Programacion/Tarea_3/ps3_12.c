#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int NUM;            // número entero positivo ingresado
    int i, j;           // contadores para bucles
    int esPrimo;        // bandera: 1 si es primo, 0 si no es primo
    int contPrimos = 0; // contador de números primos encontrados
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================\n");
    printf("     NUMEROS PRIMOS MENORES A N\n");
    printf("================================\n\n");
    
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &NUM);
    
    // ========== VALIDACION DE DATOS ==========
    if (NUM <= 1) {
        printf("\nError: NUM debe ser mayor a 1.\n");
        printf("No hay numeros primos menores a 1.\n");
        return 1;
    }
    
    // ========== PROCESAMIENTO Y SALIDA ==========
    printf("\nNumeros primos menores a %d:\n\n", NUM);
    
    // Bucle que verifica cada número desde 2 hasta NUM-1
    for (i = 2; i < NUM; i++) {
        // Inicializa la bandera: asume que i es primo
        esPrimo = 1;
        
        // Bucle que verifica si i tiene divisores
        // Solo necesita verificar hasta la raíz cuadrada de i
        for (j = 2; j * j <= i; j++) {
            // Si i es divisible por j, no es primo
            if (i % j == 0) {
                esPrimo = 0;  // No es primo
                break;        // Sale del bucle interno
            }
        }
        
        // Si esPrimo es 1, entonces i es primo
        if (esPrimo == 1) {
            printf("%d ", i);
            contPrimos++;
        }
    }
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n\n================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================\n");
    printf("Numero ingresado: %d\n", NUM);
    printf("Cantidad de primos encontrados: %d\n", contPrimos);
    
    if (contPrimos == 0) {
        printf("No hay numeros primos menores a %d.\n", NUM);
    }
    
    printf("================================\n\n");
    
    return 0;
}