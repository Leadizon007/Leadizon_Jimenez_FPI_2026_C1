#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int numJugador1, numJugador2, numJugador3;  // números ingresados por el usuario
    int numAzar1, numAzar2, numAzar3;           // números generados al azar
    int coincidencias;                          // contador de números que coinciden
    int i;                                      // variable auxiliar
    int encontrado;                             // bandera para verificar si existe coincidencia
    
    // ========== INICIALIZACION DE NUMEROS ALEATORIOS ==========
    srand(time(NULL));  // Inicializa la semilla con la hora actual
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("        JUEGO DE LOTERIA - 3 NUMEROS\n");
    printf("================================================\n\n");
    
    printf("Ingrese 3 numeros entre 10 y 40 para jugar:\n\n");
    
    printf("Ingrese el primer numero (10-40): ");
    scanf("%d", &numJugador1);
    
    printf("Ingrese el segundo numero (10-40): ");
    scanf("%d", &numJugador2);
    
    printf("Ingrese el tercer numero (10-40): ");
    scanf("%d", &numJugador3);
    
    // ========== VALIDACION DE DATOS ==========
    if ((numJugador1 < 10 || numJugador1 > 40) ||
        (numJugador2 < 10 || numJugador2 > 40) ||
        (numJugador3 < 10 || numJugador3 > 40)) {
        printf("\nError: Todos los numeros deben estar entre 10 y 40.\n");
        return 1;
    }
    
    // ========== GENERACION DE NUMEROS ALEATORIOS ==========
    printf("\n================================================\n");
    printf("Generando numeros al azar...\n");
    printf("================================================\n\n");
    
    numAzar1 = 10 + rand() % 31;  // Genera número entre 10 y 40
    numAzar2 = 10 + rand() % 31;  // Genera número entre 10 y 40
    numAzar3 = 10 + rand() % 31;  // Genera número entre 10 y 40
    
    // ========== MOSTRAR RESULTADOS ==========
    printf("Numeros que jugaste:    %d  |  %d  |  %d\n", numJugador1, numJugador2, numJugador3);
    printf("Numeros sorteados:      %d  |  %d  |  %d\n\n", numAzar1, numAzar2, numAzar3);
    
    // ========== COMPARACION Y CONTEO DE COINCIDENCIAS ==========
    printf("================================================\n");
    printf("Verificando coincidencias:\n");
    printf("================================================\n\n");
    
    coincidencias = 0;
    
    // Verifica si numJugador1 coincide con alguno generado
    printf("Numero %d: ", numJugador1);
    encontrado = 0;
    if (numJugador1 == numAzar1 || numJugador1 == numAzar2 || numJugador1 == numAzar3) {
        printf("¡COINCIDE!\n");
        coincidencias++;
        encontrado = 1;
    }
    if (!encontrado) {
        printf("No coincide\n");
    }
    
    // Verifica si numJugador2 coincide con alguno generado
    printf("Numero %d: ", numJugador2);
    encontrado = 0;
    if (numJugador2 == numAzar1 || numJugador2 == numAzar2 || numJugador2 == numAzar3) {
        printf("¡COINCIDE!\n");
        coincidencias++;
        encontrado = 1;
    }
    if (!encontrado) {
        printf("No coincide\n");
    }
    
    // Verifica si numJugador3 coincide con alguno generado
    printf("Numero %d: ", numJugador3);
    encontrado = 0;
    if (numJugador3 == numAzar1 || numJugador3 == numAzar2 || numJugador3 == numAzar3) {
        printf("¡COINCIDE!\n");
        coincidencias++;
        encontrado = 1;
    }
    if (!encontrado) {
        printf("No coincide\n");
    }
    
    // ========== RESULTADO FINAL Y PREMIO ==========
    printf("\n================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Total de coincidencias: %d de 3\n\n", coincidencias);
    
    switch (coincidencias) {
        case 0:
            printf("❌ Sin premio\n");
            printf("   No acertaste ningun numero. ¡Mejor suerte proxima vez!\n");
            break;
            
        case 1:
            printf("🎁 PREMIO MENOR\n");
            printf("   ¡Acertaste 1 numero! Ganaste $100\n");
            break;
            
        case 2:
            printf("🎁 PREMIO INTERMEDIO\n");
            printf("   ¡Acertaste 2 numeros! Ganaste $1,000\n");
            break;
            
        case 3:
            printf("🏆 PREMIO MAYOR - ¡JACKPOT!\n");
            printf("   ¡Acertaste los 3 numeros! ¡GANASTE $100,000!\n");
            break;
    }
    
    printf("\n================================================\n\n");
    
    return 0;
}