#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;              // número de años
    int i, j;           // contadores para años y tipos de vino
    
    // Matriz para almacenar producción de vinos
    // VIN[año][tipo]: año (0 a N-1), tipo (0 a 3 para tipos 1-4)
    float VIN[20][4];   // máximo 20 años y 4 tipos de vino
    
    // Arrays para totales por tipo de vino
    float totalPorTipo[4] = {0.0, 0.0, 0.0, 0.0};  // tipos 1, 2, 3, 4
    
    // Arrays para totales por año
    float totalPorAño[20];  // máximo 20 años
    
    // Variable para total general
    float totalGeneral = 0.0;
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("     ANALISIS DE PRODUCCION DE VINOS\n");
    printf("     Bodega de Tarija, Bolivia\n");
    printf("================================================\n\n");
    
    printf("Ingrese el numero de años a analizar: ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N <= 0 || N > 20) {
        printf("\nError: El numero de anos debe estar entre 1 y 20.\n");
        return 1;
    }
    
    // ========== LECTURA DE DATOS ==========
    printf("\nIngrese las cantidades de vino (en litros)\n");
    printf("para cada tipo y ano:\n");
    printf("(Tipos: 1=Tinto, 2=Blanco, 3=Rosado, 4=Espumante)\n\n");
    
    // Bucle para leer datos de N años
    for (i = 0; i < N; i++) {
        printf("--- AÑO %d ---\n", i + 1);
        
        // Inicializa total anual
        totalPorAño[i] = 0.0;
        
        // Lectura de 4 tipos de vino para cada año
        for (j = 0; j < 4; j++) {
            printf("Tipo %d (Vino %d): ", j + 1, j + 1);
            scanf("%f", &VIN[i][j]);
            
            // Acumula al total del tipo
            totalPorTipo[j] += VIN[i][j];
            
            // Acumula al total anual
            totalPorAño[i] += VIN[i][j];
            
            // Acumula al total general
            totalGeneral += VIN[i][j];
        }
        
        printf("\n");
    }
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n================================================\n");
    printf("A. TOTAL PRODUCIDO DE CADA TIPO DE VINO\n");
    printf("================================================\n");
    printf("Tipo 1 (Tinto):     %.2f litros\n", totalPorTipo[0]);
    printf("Tipo 2 (Blanco):    %.2f litros\n", totalPorTipo[1]);
    printf("Tipo 3 (Rosado):    %.2f litros\n", totalPorTipo[2]);
    printf("Tipo 4 (Espumante): %.2f litros\n", totalPorTipo[3]);
    
    printf("\n================================================\n");
    printf("B. TOTAL DE PRODUCCION ANUAL\n");
    printf("================================================\n");
    
    // Muestra totales anuales
    for (i = 0; i < N; i++) {
        printf("Año %d: %.2f litros\n", i + 1, totalPorAño[i]);
    }
    
    printf("\n================================================\n");
    printf("RESUMEN GENERAL\n");
    printf("================================================\n");
    printf("Total general producido: %.2f litros\n", totalGeneral);
    printf("Promedio anual: %.2f litros\n", totalGeneral / N);
    printf("Numero de anos analizados: %d\n", N);
    printf("================================================\n\n");
    
    return 0;
}