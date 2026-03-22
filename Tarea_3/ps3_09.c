#include <stdio.h>
#include <string.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int mes;            // contador para los 12 meses
    
    // Arrays para almacenar temperaturas de cada región (12 meses)
    float NORTE[12], CENTRO[12], SUR[12], GOLFO[12], PACIFICO[12], CARIBE[12];
    
    // Variables para promedios anuales
    float promNORTE = 0.0, promCENTRO = 0.0, promSUR = 0.0;
    float promGOLFO = 0.0, promPACIFICO = 0.0, promCAARIBE = 0.0;
    float sumaNORTE = 0.0, sumaCENTRO = 0.0, sumaSUR = 0.0;
    float sumaGOLFO = 0.0, sumaPACIFICO = 0.0, sumaCAARIBE = 0.0;
    
    // Variables para máximo y mínimo
    float maxTemp = -999.0, minTemp = 999.0;
    int mesMáx, mesMin;
    char regionMáx[15], regionMin[15];
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("   ANALISIS DE TEMPERATURAS POR REGION\n");
    printf("   Centro Meteorologico - Baja California Sur\n");
    printf("================================================\n\n");
    
    printf("Regiones: NORTE, CENTRO, SUR, GOLFO, PACIFICO, CARIBE\n\n");
    
    // Lectura de temperaturas para los 12 meses
    for (mes = 1; mes <= 12; mes++) {
        printf("--- MES %d ---\n", mes);
        
        printf("NORTE: ");
        scanf("%f", &NORTE[mes - 1]);
        sumaNORTE += NORTE[mes - 1];
        
        printf("CENTRO: ");
        scanf("%f", &CENTRO[mes - 1]);
        sumaCENTRO += CENTRO[mes - 1];
        
        printf("SUR: ");
        scanf("%f", &SUR[mes - 1]);
        sumaSUR += SUR[mes - 1];
        
        printf("GOLFO: ");
        scanf("%f", &GOLFO[mes - 1]);
        sumaGOLFO += GOLFO[mes - 1];
        
        printf("PACIFICO: ");
        scanf("%f", &PACIFICO[mes - 1]);
        sumaPACIFICO += PACIFICO[mes - 1];
        
        printf("CARIBE: ");
        scanf("%f", &CARIBE[mes - 1]);
        sumaCAARIBE += CARIBE[mes - 1];
        
        printf("\n");
        
        // Detecta máximas y mínimas
        if (NORTE[mes - 1] > maxTemp) {
            maxTemp = NORTE[mes - 1];
            mesMáx = mes;
            strcpy(regionMáx, "NORTE");
        }
        if (NORTE[mes - 1] < minTemp) {
            minTemp = NORTE[mes - 1];
            mesMin = mes;
            strcpy(regionMin, "NORTE");
        }
        
        if (CENTRO[mes - 1] > maxTemp) {
            maxTemp = CENTRO[mes - 1];
            mesMáx = mes;
            strcpy(regionMáx, "CENTRO");
        }
        if (CENTRO[mes - 1] < minTemp) {
            minTemp = CENTRO[mes - 1];
            mesMin = mes;
            strcpy(regionMin, "CENTRO");
        }
        
        if (SUR[mes - 1] > maxTemp) {
            maxTemp = SUR[mes - 1];
            mesMáx = mes;
            strcpy(regionMáx, "SUR");
        }
        if (SUR[mes - 1] < minTemp) {
            minTemp = SUR[mes - 1];
            mesMin = mes;
            strcpy(regionMin, "SUR");
        }
        
        if (GOLFO[mes - 1] > maxTemp) {
            maxTemp = GOLFO[mes - 1];
            mesMáx = mes;
            strcpy(regionMáx, "GOLFO");
        }
        if (GOLFO[mes - 1] < minTemp) {
            minTemp = GOLFO[mes - 1];
            mesMin = mes;
            strcpy(regionMin, "GOLFO");
        }
        
        if (PACIFICO[mes - 1] > maxTemp) {
            maxTemp = PACIFICO[mes - 1];
            mesMáx = mes;
            strcpy(regionMáx, "PACIFICO");
        }
        if (PACIFICO[mes - 1] < minTemp) {
            minTemp = PACIFICO[mes - 1];
            mesMin = mes;
            strcpy(regionMin, "PACIFICO");
        }
        
        if (CARIBE[mes - 1] > maxTemp) {
            maxTemp = CARIBE[mes - 1];
            mesMáx = mes;
            strcpy(regionMáx, "CARIBE");
        }
        if (CARIBE[mes - 1] < minTemp) {
            minTemp = CARIBE[mes - 1];
            mesMin = mes;
            strcpy(regionMin, "CARIBE");
        }
    }
    
    // ========== CALCULO DE PROMEDIOS ==========
    promNORTE = sumaNORTE / 12.0;
    promCENTRO = sumaCENTRO / 12.0;
    promSUR = sumaSUR / 12.0;
    promGOLFO = sumaGOLFO / 12.0;
    promPACIFICO = sumaPACIFICO / 12.0;
    promCAARIBE = sumaCAARIBE / 12.0;
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n================================================\n");
    printf("A. PROMEDIO ANUAL DE CADA REGION\n");
    printf("================================================\n");
    printf("NORTE:    %.2f °C\n", promNORTE);
    printf("CENTRO:   %.2f °C\n", promCENTRO);
    printf("SUR:      %.2f °C\n", promSUR);
    printf("GOLFO:    %.2f °C\n", promGOLFO);
    printf("PACIFICO: %.2f °C\n", promPACIFICO);
    printf("CARIBE:   %.2f °C\n", promCAARIBE);
    
    printf("\n================================================\n");
    printf("B. TEMPERATURA MAXIMA Y MINIMA\n");
    printf("================================================\n");
    printf("Temperatura MAXIMA:\n");
    printf("  Valor:   %.2f °C\n", maxTemp);
    printf("  Mes:     %d\n", mesMáx);
    printf("  Region:  %s\n", regionMáx);
    
    printf("\nTemperatura MINIMA:\n");
    printf("  Valor:   %.2f °C\n", minTemp);
    printf("  Mes:     %d\n", mesMin);
    printf("  Region:  %s\n", regionMin);
    
    printf("\n================================================\n");
    printf("C. REGION CON MAYOR PROMEDIO (SUR, PACIFICO, CARIBE)\n");
    printf("================================================\n");
    
    float maxRegional = promSUR;
    char regionMáxRegional[15] = "SUR";
    
    if (promPACIFICO > maxRegional) {
        maxRegional = promPACIFICO;
        strcpy(regionMáxRegional, "PACIFICO");
    }
    
    if (promCAARIBE > maxRegional) {
        maxRegional = promCAARIBE;
        strcpy(regionMáxRegional, "CARIBE");
    }
    
    printf("Region con mayor promedio: %s (%.2f °C)\n", regionMáxRegional, maxRegional);
    printf("SUR:      %.2f °C\n", promSUR);
    printf("PACIFICO: %.2f °C\n", promPACIFICO);
    printf("CARIBE:   %.2f °C\n", promCAARIBE);
    
    printf("\n================================================\n\n");
    
    return 0;
}