#include <stdio.h>
#include <string.h>

// ========== DEFINICION DE ESTRUCTURAS ==========
typedef struct {
    int numero_empleado;        // número de empleado
    char nombre[50];            // nombre y apellido
    char departamento[20];      // departamento
    char puesto[30];            // puesto
    char grado_academico[20];   // grado académico
    char nacionalidad[20];      // nacionalidad
    double salario[12];         // salario mensual (12 meses)
} Profesor;

// ========== FUNCIONES AUXILIARES ==========

// Función para calcular salario anual de un profesor
double calcularSalarioAnual(double salario[12]) {
    double total = 0;
    for (int i = 0; i < 12; i++) {
        total += salario[i];
    }
    return total;
}

// Función para mostrar información de un profesor
void mostrarProfesor(Profesor profesor) {
    printf("Numero de empleado: %d\n", profesor.numero_empleado);
    printf("Nombre: %s\n", profesor.nombre);
    printf("Departamento: %s\n", profesor.departamento);
    printf("Puesto: %s\n", profesor.puesto);
    printf("Grado academico: %s\n", profesor.grado_academico);
    printf("Nacionalidad: %s\n\n", profesor.nacionalidad);
}

// Función para mostrar salarios mensuales
void mostrarSalarios(double salario[12]) {
    printf("Salarios mensuales:\n");
    for (int i = 0; i < 12; i++) {
        printf("  Mes %2d: $%10.2f\n", i + 1, salario[i]);
    }
}

// ========== PROGRAMA PRINCIPAL ==========
int main() {
    // ========== DECLARACION DE VARIABLES ==========
    Profesor emple[200];        // arreglo de profesores
    int num_profesores = 0;     // número de profesores
    int i, j;                   // contadores
    char respuesta;             // respuesta del usuario
    
    // Variables para cálculos
    double salario_anual[200];  // salarios anuales
    int indice_mayor_salario = -1;
    double mayor_salario = -1;
    double total_pagado = 0;
    double total_extranjeros = 0;
    
    // Departamentos
    char departamentos[4][20] = {"Economia", "Derecho", "Computacion", "Administracion"};
    double total_departamentos[4] = {0, 0, 0, 0};
    
    // ========== ENCABEZADO ==========
    printf("================================================\n");
    printf("SISTEMA DE PROFESORES - UNIVERSIDAD (PS8.3)\n");
    printf("================================================\n");
    printf("Barranquilla, Colombia\n\n");
    
    // ========== REGISTRO DE PROFESORES ==========
    printf("================================================\n");
    printf("REGISTRO DE PROFESORES\n");
    printf("================================================\n\n");
    
    printf("Ingrese la informacion de los profesores.\n");
    printf("Termine con numero de empleado 0.\n\n");
    
    while (num_profesores < 200) {
        printf("Profesor %d\n", num_profesores + 1);
        printf("Numero de empleado (0 para terminar): ");
        scanf("%d", &emple[num_profesores].numero_empleado);
        
        if (emple[num_profesores].numero_empleado == 0) {
            break;
        }
        
        // Limpiar buffer
        while (getchar() != '\n');
        
        printf("Nombre y apellido: ");
        fgets(emple[num_profesores].nombre, 50, stdin);
        emple[num_profesores].nombre[strlen(emple[num_profesores].nombre) - 1] = '\0';
        
        printf("Departamento (Economia, Derecho, Computacion, Administracion): ");
        fgets(emple[num_profesores].departamento, 20, stdin);
        emple[num_profesores].departamento[strlen(emple[num_profesores].departamento) - 1] = '\0';
        
        printf("Puesto: ");
        fgets(emple[num_profesores].puesto, 30, stdin);
        emple[num_profesores].puesto[strlen(emple[num_profesores].puesto) - 1] = '\0';
        
        printf("Grado academico: ");
        fgets(emple[num_profesores].grado_academico, 20, stdin);
        emple[num_profesores].grado_academico[strlen(emple[num_profesores].grado_academico) - 1] = '\0';
        
        printf("Nacionalidad: ");
        fgets(emple[num_profesores].nacionalidad, 20, stdin);
        emple[num_profesores].nacionalidad[strlen(emple[num_profesores].nacionalidad) - 1] = '\0';
        
        // Ingresar salarios mensuales
        printf("\nIngrese los 12 salarios mensuales:\n");
        for (i = 0; i < 12; i++) {
            printf("  Mes %2d: $", i + 1);
            scanf("%lf", &emple[num_profesores].salario[i]);
        }
        
        printf("\n");
        
        num_profesores++;
    }
    
    if (num_profesores == 0) {
        printf("\nNo se registraron profesores.\n");
        return 1;
    }
    
    printf("\n%d profesores registrados.\n\n", num_profesores);
    
    // ========== CALCULAR SALARIOS ANUALES Y TOTALES ==========
    printf("================================================\n");
    printf("PROCESANDO INFORMACION...\n");
    printf("================================================\n\n");
    
    for (i = 0; i < num_profesores; i++) {
        // Calcular salario anual
        salario_anual[i] = calcularSalarioAnual(emple[i].salario);
        
        // Encontrar profesor con mayor salario
        if (salario_anual[i] > mayor_salario) {
            mayor_salario = salario_anual[i];
            indice_mayor_salario = i;
        }
        
        // Calcular total pagado
        total_pagado += salario_anual[i];
        
        // Calcular total extranjeros
        if (strcmp(emple[i].nacionalidad, "Colombia") != 0 &&
            strcmp(emple[i].nacionalidad, "colombiano") != 0) {
            total_extranjeros += salario_anual[i];
        }
        
        // Calcular total por departamento
        for (j = 0; j < 4; j++) {
            if (strcmp(emple[i].departamento, departamentos[j]) == 0) {
                total_departamentos[j] += salario_anual[i];
                break;
            }
        }
    }
    
    // Encontrar departamento con más egresos
    int indice_max_depto = 0;
    double max_depto = total_departamentos[0];
    
    for (i = 1; i < 4; i++) {
        if (total_departamentos[i] > max_depto) {
            max_depto = total_departamentos[i];
            indice_max_depto = i;
        }
    }
    
    // ========== RESULTADO A: PROFESOR CON MAYOR SALARIO ==========
    printf("================================================\n");
    printf("a) PROFESOR CON MAYOR SALARIO DEL AÑO\n");
    printf("================================================\n\n");
    
    printf("Informacion del profesor:\n");
    mostrarProfesor(emple[indice_mayor_salario]);
    
    printf("Salario anual total: $%.2f\n\n", mayor_salario);
    
    printf("Desglose de salarios:\n");
    mostrarSalarios(emple[indice_mayor_salario].salario);
    
    printf("\n");
    
    // ========== RESULTADO B: PROFESORES EXTRANJEROS ==========
    printf("================================================\n");
    printf("b) PAGO A PROFESORES EXTRANJEROS\n");
    printf("================================================\n\n");
    
    printf("Total pagado a extranjeros: $%.2f\n", total_extranjeros);
    printf("Total pagado a todos: $%.2f\n", total_pagado);
    printf("Porcentaje: %.2f%%\n\n", (total_extranjeros * 100) / total_pagado);
    
    // Listar profesores extranjeros
    printf("Profesores extranjeros:\n\n");
    printf("Num |  Nombre                   | Departamento      | Salario Anual\n");
    printf"----|---------------------------|-------------------|---------------\n");
    
    int contador_extranjeros = 0;
    for (i = 0; i < num_profesores; i++) {
        if (strcmp(emple[i].nacionalidad, "Colombia") != 0 &&
            strcmp(emple[i].nacionalidad, "colombiano") != 0) {
            contador_extranjeros++;
            printf(" %d  | %-25s | %-17s | $%12.2f\n",
                   contador_extranjeros,
                   emple[i].nombre,
                   emple[i].departamento,
                   salario_anual[i]);
        }
    }
    
    printf("\n");
    
    // ========== RESULTADO C: DEPARTAMENTO CON MAS EGRESOS ==========
    printf("================================================\n");
    printf("c) DEPARTAMENTO CON MAS EGRESOS\n");
    printf("================================================\n\n");
    
    printf("Departamento: %s\n", departamentos[indice_max_depto]);
    printf("Total de egresos: $%.2f\n", max_depto);
    printf("Porcentaje del total: %.2f%%\n\n", (max_depto * 100) / total_pagado);
    
    // Mostrar tabla de egresos por departamento
    printf("Tabla de egresos por departamento:\n\n");
    printf("Departamento        | Total Egresos | Porcentaje\n");
    printf"--------------------|---------------|----------\n");
    
    for (i = 0; i < 4; i++) {
        printf("%-19s | $%12.2f | %7.2f%%\n",
               departamentos[i],
               total_departamentos[i],
               (total_departamentos[i] * 100) / total_pagado);
    }
    
    printf("\n");
    
    // ========== ESTADISTICAS GENERALES ==========
    printf("================================================\n");
    printf("ESTADISTICAS GENERALES\n");
    printf("================================================\n\n");
    
    printf("Total de profesores: %d\n", num_profesores);
    printf("Total pagado a profesores: $%.2f\n", total_pagado);
    printf("Salario promedio anual: $%.2f\n\n", total_pagado / num_profesores);
    
    // Contar por nacionalidad
    printf("Profesores por nacionalidad:\n");
    printf("  Colombianos: %d\n", num_profesores - contador_extranjeros);
    printf("  Extranjeros: %d\n\n", contador_extranjeros);
    
    // ========== TABLA COMPLETA DE PROFESORES ==========
    printf("================================================\n");
    printf("TABLA COMPLETA DE PROFESORES\n");
    printf("================================================\n\n");
    
    printf("Num |  Numero | Nombre                   | Departamento      | Salario Anual\n");
    printf"----|---------|--------------------------|-------------------|---------------\n");
    
    for (i = 0; i < num_profesores; i++) {
        printf(" %d  | %7d | %-24s | %-17s | $%12.2f\n",
               i + 1,
               emple[i].numero_empleado,
               emple[i].nombre,
               emple[i].departamento,
               salario_anual[i]);
    }
    
    printf("\n================================================\n\n");
    
    return 0;
}