#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    double ALU[100];            // arreglo de calificaciones de alumnos
    int N;                      // número de alumnos
    int i;                      // contador para bucles
    double suma = 0.0;          // suma de todas las calificaciones
    double promedio;            // promedio general del grupo
    int aprobados = 0;          // contador de alumnos aprobados (>1300)
    int excelentes = 0;         // contador de alumnos con calificación >= 1500
    double porcentaje;          // porcentaje de aprobados
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    ANALISIS DE CALIFICACIONES DE EXAMEN (PS5.6)\n");
    printf("================================================\n\n");
    
    printf("Ingrese el numero de alumnos (1-100): ");
    scanf("%d", &N);
    
    // ========== VALIDACION ==========
    if (N < 1 || N > 100) {
        printf("\nError: N debe estar entre 1 y 100.\n");
        return 1;
    }
    
    // ========== ENTRADA DE CALIFICACIONES ==========
    printf("\nIngrese las calificaciones de los %d alumnos:\n", N);
    printf("(Rango esperado: 0 - 2000 puntos)\n\n");
    
    for (i = 0; i < N; i++) {
        printf("Calificacion alumno [%d]: ", i + 1);
        scanf("%lf", &ALU[i]);
    }
    
    // ========== PROCESAMIENTO - ANALISIS DE CALIFICACIONES ==========
    printf("\n================================================\n");
    printf("Analizando las calificaciones...\n");
    printf("================================================\n\n");
    
    // Bucle para analizar cada calificación
    for (i = 0; i < N; i++) {
        // Sumar todas las calificaciones
        suma += ALU[i];
        
        // Contar aprobados (>1300)
        if (ALU[i] > 1300) {
            aprobados++;
        }
        
        // Contar excelentes (>=1500)
        if (ALU[i] >= 1500) {
            excelentes++;
        }
    }
    
    // Calcular promedio
    promedio = suma / N;
    
    // Calcular porcentaje de aprobados
    porcentaje = (aprobados * 100.0) / N;
    
    // ========== RESULTADO FINAL ==========
    printf("================================================\n");
    printf("RESULTADOS DEL ANALISIS\n");
    printf("================================================\n\n");
    
    printf("a) PROMEDIO GENERAL DEL GRUPO\n");
    printf("   Promedio: %.2f puntos\n\n", promedio);
    
    printf("b) PORCENTAJE DE ALUMNOS APROBADOS\n");
    printf("   Criterio: Calificacion > 1300 puntos\n");
    printf("   Alumnos aprobados: %d\n", aprobados);
    printf("   Total de alumnos: %d\n", N);
    printf("   Porcentaje: %.2f%%\n\n", porcentaje);
    
    printf("c) ALUMNOS CON CALIFICACION EXCELENTE\n");
    printf("   Criterio: Calificacion >= 1500 puntos\n");
    printf("   Numero de alumnos: %d\n\n", excelentes);
    
    printf("================================================\n\n");
    
    return 0;
}