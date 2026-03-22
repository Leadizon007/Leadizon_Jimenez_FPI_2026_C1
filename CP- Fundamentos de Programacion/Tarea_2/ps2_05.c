#include <stdio.h>

int main() {
    float COM;
    float descuento;
    float montoDescuento;
    float precioFinal;
    
    printf("Ingrese el monto de la compra: $");
    scanf("%f", &COM);
    
    // Determinar el porcentaje de descuento según el monto de compra
    if (COM < 800) {
        descuento = 0;  // Descuento 0%
    }
    else if (COM >= 800 && COM <= 1500) {
        descuento = 0.10;  // Descuento 10%
    }
    else if (COM > 1500 && COM <= 5000) {
        descuento = 0.15;  // Descuento 15%
    }
    else {  // COM > 5000
        descuento = 0.20;  // Descuento 20%
    }
    
    // Calcular el monto del descuento
    montoDescuento = COM * descuento;
    
    // Calcular el precio final después del descuento
    precioFinal = COM - montoDescuento;
    
    // Mostrar resultados
    printf("\nMonto de la compra: $%.2f\n", COM);
    printf("Porcentaje de descuento: %.0f%%\n", descuento * 100);
    printf("Monto del descuento: $%.2f\n", montoDescuento);
    printf("Precio final a pagar: $%.2f\n", precioFinal);
    
    return 0;
}