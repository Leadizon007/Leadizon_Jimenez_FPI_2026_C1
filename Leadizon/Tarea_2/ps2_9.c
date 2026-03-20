#include <stdio.h>

int main() {
    int MED;
    int SME;
    float VAL;
    float resultado;
    int validoMED;
    int validoSME;
    
    // Bucle para validar la opción de tipo de medida
    do {
        validoMED = 0;
        
        printf("Seleccione el tipo de medida a convertir:\n");
        printf("1 - Medidas de Longitud\n");
        printf("2 - Medidas de Volumen\n");
        printf("3 - Medidas de Peso\n");
        printf("Ingrese su opcion (1, 2 o 3): ");
        scanf("%d", &MED);
        
        // Validar que MED sea 1, 2 o 3
        if (MED >= 1 && MED <= 3) {
            validoMED = 1;
            
            printf("Ingrese el valor a convertir: ");
            scanf("%f", &VAL);
        }
        else {
            printf("\nOpcion no valida. Por favor, ingrese 1, 2 o 3.\n");
            printf("================================================\n\n");
        }
    } while (validoMED == 0);
    
    // Conversiones de Longitud
    if (MED == 1) {
        do {
            validoSME = 0;
            
            printf("\nSeleccione la conversión de Longitud:\n");
            printf("1 - Pulgadas a milimetros\n");
            printf("2 - Yardas a metros\n");
            printf("3 - Millas a kilometros\n");
            printf("4 - Pulgadas² a centimetros²\n");
            printf("5 - Pies² a metros²\n");
            printf("6 - Yardas² a metros²\n");
            printf("7 - Acres a hectareas\n");
            printf("8 - Millas² a kilometros²\n");
            printf("Ingrese su opcion: ");
            scanf("%d", &SME);
            
            if (SME == 1) {
                resultado = VAL * 25.40;
                printf("\n%.2f pulgadas = %.2f milimetros\n", VAL, resultado);
                validoSME = 1;
            }
            else if (SME == 2) {
                resultado = VAL * 0.9144;
                printf("\n%.2f yardas = %.2f metros\n", VAL, resultado);
                validoSME = 1;
            }
            else if (SME == 3) {
                resultado = VAL * 1.6093;
                printf("\n%.2f millas = %.2f kilometros\n", VAL, resultado);
                validoSME = 1;
            }
            else if (SME == 4) {
                resultado = VAL * 6.452;
                printf("\n%.2f pulgadas² = %.2f centimetros²\n", VAL, resultado);
                validoSME = 1;
            }
            else if (SME == 5) {
                resultado = VAL * 0.09290;
                printf("\n%.2f pies² = %.2f metros²\n", VAL, resultado);
                validoSME = 1;
            }
            else if (SME == 6) {
                resultado = VAL * 0.8361;
                printf("\n%.2f yardas² = %.2f metros²\n", VAL, resultado);
                validoSME = 1;
            }
            else if (SME == 7) {
                resultado = VAL * 0.4047;
                printf("\n%.2f acres = %.2f hectareas\n", VAL, resultado);
                validoSME = 1;
            }
            else if (SME == 8) {
                resultado = VAL * 2.59;
                printf("\n%.2f millas² = %.2f kilometros²\n", VAL, resultado);
                validoSME = 1;
            }
            else {
                printf("\nOpcion no valida. Ingrese una opcion del 1 al 8.\n");
                printf("==================================================\n\n");
            }
        } while (validoSME == 0);
    }
    
    // Conversiones de Volumen
    else if (MED == 2) {
        do {
            validoSME = 0;
            
            printf("\nSeleccione la conversión de Volumen:\n");
            printf("1 - Pies³ a metros³\n");
            printf("2 - Yardas³ a metros³\n");
            printf("3 - Pintas a litros\n");
            printf("4 - Galones a litros\n");
            printf("Ingrese su opcion: ");
            scanf("%d", &SME);
            
            if (SME == 1) {
                resultado = VAL * 0.02832;
                printf("\n%.2f pies³ = %.2f metros³\n", VAL, resultado);
                validoSME = 1;
            }
            else if (SME == 2) {
                resultado = VAL * 0.7646;
                printf("\n%.2f yardas³ = %.2f metros³\n", VAL, resultado);
                validoSME = 1;
            }
            else if (SME == 3) {
                resultado = VAL * 0.56826;
                printf("\n%.2f pintas = %.2f litros\n", VAL, resultado);
                validoSME = 1;
            }
            else if (SME == 4) {
                resultado = VAL * 4.54609;
                printf("\n%.2f galones = %.2f litros\n", VAL, resultado);
                validoSME = 1;
            }
            else {
                printf("\nOpcion no valida. Ingrese una opcion del 1 al 4.\n");
                printf("==================================================\n\n");
            }
        } while (validoSME == 0);
    }
    
    // Conversiones de Peso
    else if (MED == 3) {
        do {
            validoSME = 0;
            
            printf("\nSeleccione la conversión de Peso:\n");
            printf("1 - Onzas a gramos\n");
            printf("2 - Libras a kilogramos\n");
            printf("3 - Toneladas inglesas a toneladas metricas\n");
            printf("Ingrese su opcion: ");
            scanf("%d", &SME);
            
            if (SME == 1) {
                resultado = VAL * 28.35;
                printf("\n%.2f onzas = %.2f gramos\n", VAL, resultado);
                validoSME = 1;
            }
            else if (SME == 2) {
                resultado = VAL * 0.45359;
                printf("\n%.2f libras = %.2f kilogramos\n", VAL, resultado);
                validoSME = 1;
            }
            else if (SME == 3) {
                resultado = VAL * 1.0160;
                printf("\n%.2f toneladas inglesas = %.2f toneladas metricas\n", VAL, resultado);
                validoSME = 1;
            }
            else {
                printf("\nOpcion no valida. Ingrese una opcion del 1 al 3.\n");
                printf("==================================================\n\n");
            }
        } while (validoSME == 0);
    }
    
    return 0;
}