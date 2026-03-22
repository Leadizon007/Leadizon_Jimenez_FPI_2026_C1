#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    long long PERF[30];         // arreglo para almacenar 30 números perfectos
    int contador = 0;           // contador de números perfectos encontrados
    long long numero = 1;       // número a verificar
    long long suma_divisores;   // suma de divisores del número
    long long i;                // contador para encontrar divisores
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("      PRIMEROS 30 NUMEROS PERFECTOS (PS5.11)\n");
    printf("================================================\n\n");
    
    printf("Un numero es perfecto si la suma de sus divisores\n");
    printf("(excepto el mismo) es igual al numero.\n");
    printf("Ejemplo: 6 = 1 + 2 + 3\n\n");
    
    printf("Buscando los 30 primeros numeros perfectos...\n");
    printf("(Esto puede tomar algunos segundos)\n\n");
    
    // ========== PROCESAMIENTO - BUSCAR NUMEROS PERFECTOS ==========
    // Continuar hasta encontrar 30 números perfectos
    while (contador < 30) {
        suma_divisores = 0;
        
        // Encontrar todos los divisores de 'numero'
        // Los divisores son menores que el número
        for (i = 1; i < numero; i++) {
            // Si i es divisor de numero
            if (numero % i == 0) {
                suma_divisores += i;
            }
        }
        
        // Verificar si es un número perfecto
        if (suma_divisores == numero) {
            PERF[contador] = numero;
            contador++;
        }
        
        numero++;
    }
    
    // ========== RESULTADO FINAL - IMPRESION DEL ARREGLO ==========
    printf("================================================\n");
    printf("ARREGLO DE NUMEROS PERFECTOS\n");
    printf("================================================\n\n");
    
    printf("Indice |        Numero Perfecto\n");
    printf("--------|----------------------\n");
    
    for (i = 0; i < 30; i++) {
        printf("  %2lld   | %18lld\n", i + 1, PERF[i]);
    }
    
    // ========== ESTADISTICAS ==========
    printf("\n================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    printf("Total de numeros perfectos encontrados: 30\n\n");
    
    printf("Primer numero perfecto:  %lld\n", PERF[0]);
    printf("Ultimo numero perfecto:  %lld\n\n", PERF[29]);
    
    printf("Diferencia:              %lld\n\n", PERF[29] - PERF[0]);
    
    // ========== VERIFICACION DEL PRIMER NUMERO PERFECTO ==========
    printf("================================================\n");
    printf("VERIFICACION - PRIMER NUMERO PERFECTO: %lld\n", PERF[0]);
    printf("================================================\n\n");
    
    printf("Divisores de %lld:\n", PERF[0]);
    suma_divisores = 0;
    for (i = 1; i < PERF[0]; i++) {
        if (PERF[0] % i == 0) {
            printf("  %lld", i);
            suma_divisores += i;
            if (i < PERF[0] / 2) {
                printf(" +");
            }
        }
    }
    printf(" = %lld\n\n", suma_divisores);
    
    printf("Como %lld = %lld, es un numero perfecto.\n\n", PERF[0], suma_divisores);
    
    // ========== VERIFICACION DEL SEGUNDO NUMERO PERFECTO ==========
    printf("================================================\n");
    printf("VERIFICACION - SEGUNDO NUMERO PERFECTO: %lld\n", PERF[1]);
    printf("================================================\n\n");
    
    printf("Divisores de %lld:\n", PERF[1]);
    suma_divisores = 0;
    for (i = 1; i < PERF[1]; i++) {
        if (PERF[1] % i == 0) {
            printf("  %lld", i);
            suma_divisores += i;
            if (i < PERF[1] / 2) {
                printf(" +");
            }
        }
    }
    printf(" = %lld\n\n", suma_divisores);
    
    printf("Como %lld = %lld, es un numero perfecto.\n\n", PERF[1], suma_divisores);
    
    printf("================================================\n\n");
    
    return 0;
}