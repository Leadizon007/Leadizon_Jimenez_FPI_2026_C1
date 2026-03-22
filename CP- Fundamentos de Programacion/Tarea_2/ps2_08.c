#include <stdio.h>

int main() {
    int MED;
    float VAL;
    float resultado;
    int valido;
    
    // Bucle para repetir el menú si la opción es inválida
    do {
        valido = 0;
        
        printf("Seleccione el tipo de conversion:\n");
        printf("1 - Pulgadas a milimetros\n");
        printf("2 - Yardas a metros\n");
        printf("3 - Millas a kilometros\n");
        printf("Ingrese su opcion (1, 2 o 3): ");
        scanf("%d", &MED);
        
        // Validar la opción ingresada
        if (MED == 1 || MED == 2 || MED == 3) {
            valido = 1;
            
            printf("Ingrese el valor a convertir: ");
            scanf("%f", &VAL);
            
            // Realizar la conversión según la opción seleccionada
            if (MED == 1) {
                // Conversión de pulgadas a milímetros
                resultado = VAL * 25.40;
                printf("\n%.2f pulgadas = %.2f milimetros\n", VAL, resultado);
            }
            else if (MED == 2) {
                // Conversión de yardas a metros
                resultado = VAL * 0.9144;
                printf("\n%.2f yardas = %.2f metros\n", VAL, resultado);
            }
            else if (MED == 3) {
                // Conversión de millas a kilómetros
                resultado = VAL * 1.6093;
                printf("\n%.2f millas = %.2f kilometros\n", VAL, resultado);
            }
        }
        else {
            printf("\nOpcion no valida. Por favor, ingrese 1, 2 o 3.\n");
            printf("================================================\n\n");
        }
    } while (valido == 0);
    
    return 0;
}