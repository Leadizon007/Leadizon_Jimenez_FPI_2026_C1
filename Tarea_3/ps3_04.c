#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;              // cantidad de números a ingresar
    int i;              // contador para el bucle
    int numero;         // número ingresado por el usuario
    int positivos = 0;  // contador de números positivos
    int negativos = 0;  // contador de números negativos
    int nulos = 0;      // contador de números nulos (ceros)
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================\n");
    printf("  CLASIFICACION DE NUMEROS\n");
    printf("================================\n\n");
    
    printf("Ingrese la cantidad de numeros N: ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N <= 0) {
        printf("\nError: N debe ser un numero positivo (mayor a 0).\n");
        return 1;
    }
    
    // ========== PROCESAMIENTO ==========
    printf("\nIngrese los %d numeros:\n\n", N);
    
    // Bucle para leer N números y clasificarlos
    for (i = 1; i <= N; i++) {
        printf("Numero %d: ", i);
        scanf("%d", &numero);
        
        // Clasifica el número ingresado
        if (numero > 0) {
            positivos++;  // Es positivo
        } else if (numero < 0) {
            negativos++;  // Es negativo
        } else {
            nulos++;      // Es nulo (cero)
        }
    }
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================\n");
    printf("Total de numeros ingresados: %d\n", N);
    printf("Numeros positivos:  %d\n", positivos);
    printf("Numeros negativos:  %d\n", negativos);
    printf("Numeros nulos (0):  %d\n", nulos);
    printf("================================\n\n");
    
    return 0;
}