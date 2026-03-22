#include <stdio.h>
#include <math.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int T, P, R;        // variables que satisfacen la expresión
    long resultado;     // resultado de la expresión: 7*T^4 - 6*P^3 + 12*R^5
    int contador;       // contador de soluciones encontradas
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    BUSQUEDA DE VALORES POSITIVOS (PS3.20)\n");
    printf("================================================\n\n");
    
    printf("Expresion: 7*T^4 - 6*P^3 + 12*R^5 < 5850\n");
    printf("Restriccion: T, P, R deben ser positivos (>= 1)\n\n");
    
    // ========== PROCESAMIENTO ==========
    printf("================================================\n");
    printf("Valores que satisfacen la expresion:\n");
    printf("================================================\n\n");
    
    printf("  T  |  P  |  R  | 7*T^4 - 6*P^3 + 12*R^5\n");
    printf("-----|-----|-----|------------------------\n");
    
    contador = 0;
    
    // Bucle para T: valores positivos
    // Se estima un rango razonable basado en el término dominante 7*T^4
    // Si 7*T^4 < 5850, entonces T^4 < 835, por lo tanto T < 5.4
    for (T = 1; T <= 10; T++) {
        
        // Bucle para P: valores positivos
        // Se estima un rango basado en el término -6*P^3
        // Si -6*P^3 > -5850, entonces P^3 < 975, por lo tanto P < 10
        for (P = 1; P <= 20; P++) {
            
            // Bucle para R: valores positivos
            // Se estima un rango basado en el término 12*R^5
            // Si 12*R^5 < 5850, entonces R^5 < 487.5, por lo tanto R < 3.5
            for (R = 1; R <= 5; R++) {
                
                // Calcula la expresión: 7*T^4 - 6*P^3 + 12*R^5
                resultado = 7 * T * T * T * T 
                          - 6 * P * P * P 
                          + 12 * R * R * R * R * R;
                
                // Verifica si satisface la condición
                if (resultado < 5850) {
                    printf("%3d | %3d | %3d | %16ld\n", T, P, R, resultado);
                    contador++;
                }
            }
        }
    }
    
    // ========== RESULTADO FINAL ==========
    printf("\n================================================\n");
    printf("BUSQUEDA COMPLETADA EXITOSAMENTE\n");
    printf("Total de combinaciones encontradas: %d\n", contador);
    printf("================================================\n\n");
    
    return 0;
}