#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    double COS[12];             // arreglo de cosechas mensuales en toneladas
    int i;                      // contador para bucles
    double suma = 0.0;          // suma total de cosechas
    double promedio;            // promedio anual
    int meses_superior = 0;     // meses con cosecha > promedio
    double mayor;               // mayor cosecha
    int mes_mayor;              // mes con mayor cosecha
    
    // Nombres de los meses
    char *meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                       "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("  ANALISIS DE COSECHA MENSUAL DE CEREALES (PS5.7)\n");
    printf("================================================\n\n");
    
    printf("Ingrese las toneladas cosechadas durante cada mes:\n\n");
    
    for (i = 0; i < 12; i++) {
        printf("Toneladas en %s: ", meses[i]);
        scanf("%lf", &COS[i]);
    }
    
    // ========== PROCESAMIENTO ==========
    printf("\n================================================\n");
    printf("Calculando estadisticas de cosecha...\n");
    printf("================================================\n\n");
    
    // Calcular suma y encontrar mayor
    mayor = COS[0];
    mes_mayor = 0;
    
    for (i = 0; i < 12; i++) {
        suma += COS[i];
        
        if (COS[i] > mayor) {
            mayor = COS[i];
            mes_mayor = i;
        }
    }
    
    // Calcular promedio
    promedio = suma / 12;
    
    // Contar meses con cosecha superior al promedio
    for (i = 0; i < 12; i++) {
        if (COS[i] > promedio) {
            meses_superior++;
        }
    }
    
    // ========== RESULTADO FINAL ==========
    printf("================================================\n");
    printf("TABLA DE COSECHAS MENSUALES\n");
    printf("================================================\n\n");
    
    printf("Mes           | Toneladas | Diferencia a Promedio\n");
    printf("--------------|-----------|----------------------\n");
    
    for (i = 0; i < 12; i++) {
        printf("%-13s | %9.2f | ", meses[i], COS[i]);
        
        if (COS[i] > promedio) {
            printf("+%.2f (Superior)\n", COS[i] - promedio);
        } else if (COS[i] < promedio) {
            printf("%.2f (Inferior)\n", COS[i] - promedio);
        } else {
            printf("0.00 (Igual)\n");
        }
    }
    
    // ========== RESPUESTAS A LAS PREGUNTAS ==========
    printf("\n================================================\n");
    printf("RESULTADOS DEL ANALISIS\n");
    printf("================================================\n\n");
    
    printf("a) PROMEDIO ANUAL DE TONELADAS COSECHADAS\n");
    printf("   Suma total: %.2f toneladas\n", suma);
    printf("   Numero de meses: 12\n");
    printf("   Promedio anual: %.2f toneladas\n\n", promedio);
    
    printf("b) MESES CON COSECHA SUPERIOR AL PROMEDIO\n");
    printf("   Numero de meses: %d de 12\n", meses_superior);
    printf("   Porcentaje: %.2f%%\n\n", (meses_superior * 100.0) / 12);
    
    printf("c) MES CON MAYOR COSECHA\n");
    printf("   Mes: %s\n", meses[mes_mayor]);
    printf("   Toneladas: %.2f\n", mayor);
    printf("   Diferencia al promedio: +%.2f toneladas\n\n", mayor - promedio);
    
    printf("================================================\n\n");
    
    return 0;
}