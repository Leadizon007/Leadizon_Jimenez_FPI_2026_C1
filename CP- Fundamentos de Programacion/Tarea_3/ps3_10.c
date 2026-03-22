#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    
    // Precios de las 6 localidades
    float L1, L2, L3, L4, L5, L6;
    
    // Arrays para almacenar precios y cantidad de boletos vendidos
    float precios[7];       // índices 1-6 para las localidades
    int boletosVendidos[7]; // contadores de boletos por localidad
    
    // Variables para lectura de datos de ventas
    int clase;              // tipo de localidad (1-6)
    int cantidad;           // cantidad de boletos
    float montoVenta;       // monto de cada venta
    float recaudacionTotal = 0.0;  // suma de todas las ventas
    
    int i;                  // contador para inicialización
    
    // ========== ENTRADA DE DATOS - PRECIOS ==========
    printf("================================================\n");
    printf("     SISTEMA DE VENTA DE BOLETOS - CIRCO\n");
    printf("================================================\n\n");
    
    printf("Ingrese los precios de las 6 localidades:\n\n");
    
    printf("Precio localidad 1: $");
    scanf("%f", &L1);
    precios[1] = L1;
    
    printf("Precio localidad 2: $");
    scanf("%f", &L2);
    precios[2] = L2;
    
    printf("Precio localidad 3: $");
    scanf("%f", &L3);
    precios[3] = L3;
    
    printf("Precio localidad 4: $");
    scanf("%f", &L4);
    precios[4] = L4;
    
    printf("Precio localidad 5: $");
    scanf("%f", &L5);
    precios[5] = L5;
    
    printf("Precio localidad 6: $");
    scanf("%f", &L6);
    precios[6] = L6;
    
    // ========== INICIALIZACION DE CONTADORES ==========
    for (i = 1; i <= 6; i++) {
        boletosVendidos[i] = 0;
    }
    
    // ========== ENTRADA DE DATOS - VENTAS ==========
    printf("\n================================================\n");
    printf("Ingrese los datos de ventas:\n");
    printf("(Ingrese clase = 0 para finalizar)\n\n");
    
    int venta = 1;
    
    // Bucle para leer ventas hasta que ingrese clase = 0
    while (1) {
        printf("--- Venta %d ---\n", venta);
        printf("Clase de localidad (1-6, 0 para salir): ");
        scanf("%d", &clase);
        
        // Condición de salida
        if (clase == 0) {
            break;
        }
        
        // Validación de clase
        if (clase < 1 || clase > 6) {
            printf("Error: Ingrese una clase entre 1 y 6.\n\n");
            continue;  // Salta a la siguiente iteración
        }
        
        printf("Cantidad de boletos: ");
        scanf("%d", &cantidad);
        
        // Validación de cantidad
        if (cantidad <= 0) {
            printf("Error: La cantidad debe ser mayor a 0.\n\n");
            continue;
        }
        
        // ========== CALCULO DE MONTO DE VENTA ==========
        montoVenta = precios[clase] * cantidad;
        
        // Acumula boletos vendidos por localidad
        boletosVendidos[clase] += cantidad;
        
        // Acumula recaudación total
        recaudacionTotal += montoVenta;
        
        // ========== SALIDA - MONTO DE VENTA ==========
        printf("Monto de venta: $%.2f\n\n", montoVenta);
        
        venta++;
    }
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n================================================\n");
    printf("A. MONTOS DE CADA VENTA\n");
    printf("================================================\n");
    printf("(Se mostraron durante el proceso de venta)\n");
    
    printf("\n================================================\n");
    printf("B. BOLETOS VENDIDOS POR LOCALIDAD\n");
    printf("================================================\n");
    printf("Localidad 1 (Precio: $%.2f): %d boletos\n", precios[1], boletosVendidos[1]);
    printf("Localidad 2 (Precio: $%.2f): %d boletos\n", precios[2], boletosVendidos[2]);
    printf("Localidad 3 (Precio: $%.2f): %d boletos\n", precios[3], boletosVendidos[3]);
    printf("Localidad 4 (Precio: $%.2f): %d boletos\n", precios[4], boletosVendidos[4]);
    printf("Localidad 5 (Precio: $%.2f): %d boletos\n", precios[5], boletosVendidos[5]);
    printf("Localidad 6 (Precio: $%.2f): %d boletos\n", precios[6], boletosVendidos[6]);
    
    int totalBoletos = 0;
    for (i = 1; i <= 6; i++) {
        totalBoletos += boletosVendidos[i];
    }
    printf("\nTotal de boletos vendidos: %d\n", totalBoletos);
    
    printf("\n================================================\n");
    printf("C. RECAUDACION TOTAL\n");
    printf("================================================\n");
    printf("Recaudación total: $%.2f\n", recaudacionTotal);
    printf("================================================\n\n");
    
    return 0;
}