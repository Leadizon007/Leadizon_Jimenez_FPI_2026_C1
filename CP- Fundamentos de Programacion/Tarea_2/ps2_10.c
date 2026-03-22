#include <stdio.h>

int main() {
    float SAL;
    int CAT;
    int PHE;
    float pagoHorasExtra;
    float totalPago;
    int horasExtraValidas;
    int validoCAT;
    int validoPHE;
    
    printf("Ingrese el salario del trabajador: $");
    scanf("%f", &SAL);
    
    // Bucle para validar la categoría del trabajador
    do {
        validoCAT = 0;
        
        printf("\nSeleccione la categoria del trabajador:\n");
        printf("1 - Categoria 1 ($40 por hora extra)\n");
        printf("2 - Categoria 2 ($50 por hora extra)\n");
        printf("3 - Categoria 3 ($85 por hora extra)\n");
        printf("4 - Categoria 4 o mayor (Sin beneficio de horas extra)\n");
        printf("Ingrese su opcion (1, 2, 3 o 4): ");
        scanf("%d", &CAT);
        
        if (CAT >= 1 && CAT <= 4) {
            validoCAT = 1;
        }
        else {
            printf("\nOpcion no valida. Por favor, ingrese 1, 2, 3 o 4.\n");
            printf("====================================================\n");
        }
    } while (validoCAT == 0);
    
    // Bucle para validar las horas extra
    do {
        validoPHE = 0;
        
        printf("\nIngrese el numero de horas extra trabajadas: ");
        scanf("%d", &PHE);
        
        if (PHE >= 0) {
            validoPHE = 1;
        }
        else {
            printf("\nEl numero de horas extra debe ser mayor o igual a 0.\n");
            printf("================================================\n");
        }
    } while (validoPHE == 0);
    
    // Verificar si el trabajador puede recibir pago de horas extra
    if (CAT >= 4) {
        printf("\nLos trabajadores con categoria 4 o mayor no reciben beneficio de horas extra.\n");
        printf("\nSalario base: $%.2f\n", SAL);
        printf("Categoria del trabajador: %d\n", CAT);
        printf("Salario total a pagar: $%.2f\n", SAL);
    }
    else {
        // Limitar las horas extra a un máximo de 30
        if (PHE > 30) {
            horasExtraValidas = 30;
            printf("\nNota: Las horas extra se han limitado a 30 (máximo permitido).\n");
        }
        else {
            horasExtraValidas = PHE;
        }
        
        // Calcular el pago de horas extra según la categoría
        if (CAT == 1) {
            pagoHorasExtra = horasExtraValidas * 40;
        }
        else if (CAT == 2) {
            pagoHorasExtra = horasExtraValidas * 50;
        }
        else if (CAT == 3) {
            pagoHorasExtra = horasExtraValidas * 85;
        }
        
        // Calcular el total a pagar
        totalPago = SAL + pagoHorasExtra;
        
        // Mostrar los resultados
        printf("\nSalario base: $%.2f\n", SAL);
        printf("Categoria del trabajador: %d\n", CAT);
        printf("Horas extra trabajadas: %d\n", PHE);
        printf("Horas extra a pagar: %d\n", horasExtraValidas);
        printf("Pago por horas extra: $%.2f\n", pagoHorasExtra);
        printf("Salario total a pagar: $%.2f\n", totalPago);
    }
    
    return 0;
}