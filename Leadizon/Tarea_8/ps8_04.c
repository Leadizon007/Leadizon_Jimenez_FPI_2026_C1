#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ========== DEFINICION DE ESTRUCTURAS ==========
typedef struct {
    char calle[50];             // calle y número
    char colonia[50];           // colonia
    char codigo_postal[10];     // código postal
    char ciudad[50];            // ciudad
} Domicilio;

typedef struct {
    int numero_empleado;        // número de empleado
    char nombre[50];            // nombre y apellido
    char departamento[30];      // departamento
    Domicilio domicilio;        // estructura de domicilio
    char telefono[15];          // teléfono
    double salario_mensual;     // salario mensual
} Empleado;

// ========== FUNCIONES AUXILIARES ==========

// Función para buscar empleado por número
int buscarEmpleado(Empleado emple[], int num_empleados, int numero_empleado) {
    for (int i = 0; i < num_empleados; i++) {
        if (emple[i].numero_empleado == numero_empleado) {
            return i;
        }
    }
    return -1;
}

// Función para mostrar información de un empleado
void mostrarEmpleado(Empleado empleado) {
    printf("\n================================================\n");
    printf("INFORMACION DEL EMPLEADO\n");
    printf("================================================\n\n");
    
    printf("Numero de empleado: %d\n", empleado.numero_empleado);
    printf("Nombre: %s\n", empleado.nombre);
    printf("Departamento: %s\n", empleado.departamento);
    printf("Telefono: %s\n\n", empleado.telefono);
    
    printf("Domicilio:\n");
    printf("  Calle: %s\n", empleado.domicilio.calle);
    printf("  Colonia: %s\n", empleado.domicilio.colonia);
    printf("  Codigo Postal: %s\n", empleado.domicilio.codigo_postal);
    printf("  Ciudad: %s\n\n", empleado.domicilio.ciudad);
    
    printf("Salario mensual: $%.2f\n", empleado.salario_mensual);
}

// Función para dar de alta un empleado
void altaEmpleado(Empleado emple[], int *num_empleados) {
    if (*num_empleados >= 100) {
        printf("\n¡ERROR! No hay espacio para mas empleados.\n");
        return;
    }
    
    printf("\n================================================\n");
    printf("ALTA DE EMPLEADO\n");
    printf("================================================\n\n");
    
    int numero;
    printf("Numero de empleado: ");
    scanf("%d", &numero);
    
    // Verificar si ya existe
    if (buscarEmpleado(emple, *num_empleados, numero) != -1) {
        printf("\n¡ERROR! El empleado ya existe.\n");
        return;
    }
    
    // Limpiar buffer
    while (getchar() != '\n');
    
    emple[*num_empleados].numero_empleado = numero;
    
    printf("Nombre y apellido: ");
    fgets(emple[*num_empleados].nombre, 50, stdin);
    emple[*num_empleados].nombre[strlen(emple[*num_empleados].nombre) - 1] = '\0';
    
    printf("Departamento: ");
    fgets(emple[*num_empleados].departamento, 30, stdin);
    emple[*num_empleados].departamento[strlen(emple[*num_empleados].departamento) - 1] = '\0';
    
    printf("\nDomicilio:\n");
    printf("Calle y numero: ");
    fgets(emple[*num_empleados].domicilio.calle, 50, stdin);
    emple[*num_empleados].domicilio.calle[strlen(emple[*num_empleados].domicilio.calle) - 1] = '\0';
    
    printf("Colonia: ");
    fgets(emple[*num_empleados].domicilio.colonia, 50, stdin);
    emple[*num_empleados].domicilio.colonia[strlen(emple[*num_empleados].domicilio.colonia) - 1] = '\0';
    
    printf("Codigo postal: ");
    fgets(emple[*num_empleados].domicilio.codigo_postal, 10, stdin);
    emple[*num_empleados].domicilio.codigo_postal[strlen(emple[*num_empleados].domicilio.codigo_postal) - 1] = '\0';
    
    printf("Ciudad: ");
    fgets(emple[*num_empleados].domicilio.ciudad, 50, stdin);
    emple[*num_empleados].domicilio.ciudad[strlen(emple[*num_empleados].domicilio.ciudad) - 1] = '\0';
    
    printf("Telefono: ");
    fgets(emple[*num_empleados].telefono, 15, stdin);
    emple[*num_empleados].telefono[strlen(emple[*num_empleados].telefono) - 1] = '\0';
    
    printf("Salario mensual: $");
    scanf("%lf", &emple[*num_empleados].salario_mensual);
    
    printf("\n¡Empleado registrado exitosamente!\n");
    
    (*num_empleados)++;
    
    // Ordenar por número de empleado
    for (int i = 0; i < *num_empleados - 1; i++) {
        for (int j = 0; j < *num_empleados - i - 1; j++) {
            if (emple[j].numero_empleado > emple[j + 1].numero_empleado) {
                Empleado temp = emple[j];
                emple[j] = emple[j + 1];
                emple[j + 1] = temp;
            }
        }
    }
}

// Función para dar de baja un empleado
void bajaEmpleado(Empleado emple[], int *num_empleados) {
    printf("\n================================================\n");
    printf("BAJA DE EMPLEADO\n");
    printf("================================================\n\n");
    
    int numero;
    printf("Numero de empleado a dar de baja: ");
    scanf("%d", &numero);
    
    // Limpiar buffer
    while (getchar() != '\n');
    
    int indice = buscarEmpleado(emple, *num_empleados, numero);
    
    if (indice == -1) {
        printf("\n¡ERROR! Empleado no encontrado.\n");
        return;
    }
    
    // Mostrar datos del empleado
    printf("\nEmpleado a dar de baja:\n");
    printf("Numero: %d\n", emple[indice].numero_empleado);
    printf("Nombre: %s\n", emple[indice].nombre);
    printf("Departamento: %s\n\n", emple[indice].departamento);
    
    printf("¿Confirma la baja? (S/N): ");
    char respuesta;
    scanf("%c", &respuesta);
    
    if (respuesta != 'S' && respuesta != 's') {
        printf("\nBaja cancelada.\n");
        return;
    }
    
    // Eliminar empleado
    for (int i = indice; i < *num_empleados - 1; i++) {
        emple[i] = emple[i + 1];
    }
    
    (*num_empleados)--;
    
    printf("\n¡Empleado dado de baja exitosamente!\n");
}

// Función para listar empleados por departamento
void listadoDepartamento(Empleado emple[], int num_empleados) {
    printf("\n================================================\n");
    printf("LISTADO POR DEPARTAMENTO\n");
    printf("================================================\n\n");
    
    // Limpiar buffer
    while (getchar() != '\n');
    
    char departamento[30];
    printf("Ingrese el nombre del departamento: ");
    fgets(departamento, 30, stdin);
    departamento[strlen(departamento) - 1] = '\0';
    
    // Buscar empleados del departamento
    int encontrados = 0;
    printf("\n");
    
    printf("Num |  Numero | Nombre                   | Salario Mensual\n");
    printf"----|---------|--------------------------|---------------\n");
    
    for (int i = 0; i < num_empleados; i++) {
        if (strcmp(emple[i].departamento, departamento) == 0) {
            encontrados++;
            printf(" %d  | %7d | %-24s | $%11.2f\n",
                   encontrados,
                   emple[i].numero_empleado,
                   emple[i].nombre,
                   emple[i].salario_mensual);
        }
    }
    
    if (encontrados == 0) {
        printf("No se encontraron empleados en el departamento '%s'.\n", departamento);
    } else {
        printf("\nTotal de empleados: %d\n", encontrados);
        
        // Calcular total de salarios
        double total_salarios = 0;
        for (int i = 0; i < num_empleados; i++) {
            if (strcmp(emple[i].departamento, departamento) == 0) {
                total_salarios += emple[i].salario_mensual;
            }
        }
        printf("Total de salarios mensuales: $%.2f\n", total_salarios);
        printf("Promedio de salarios: $%.2f\n", total_salarios / encontrados);
    }
    
    printf("\n");
}

// Función para mostrar todos los empleados
void mostrarTodosEmpleados(Empleado emple[], int num_empleados) {
    printf("\n================================================\n");
    printf("LISTA COMPLETA DE EMPLEADOS\n");
    printf("================================================\n\n");
    
    if (num_empleados == 0) {
        printf("No hay empleados registrados.\n\n");
        return;
    }
    
    printf("Num |  Numero | Nombre                   | Departamento          | Salario\n");
    printf("----|---------|--------------------------|----------------------|----------\n");
    
    double total_salarios = 0;
    
    for (int i = 0; i < num_empleados; i++) {
        printf(" %d  | %7d | %-24s | %-20s | $%8.2f\n",
               i + 1,
               emple[i].numero_empleado,
               emple[i].nombre,
               emple[i].departamento,
               emple[i].salario_mensual);
        total_salarios += emple[i].salario_mensual;
    }
    
    printf("----|---------|--------------------------|----------------------|----------\n");
    printf("    |         |                          |                      | $%8.2f\n", 
           total_salarios);
    
    printf("\nTotal de empleados: %d\n", num_empleados);
    printf("Total de salarios mensuales: $%.2f\n\n", total_salarios);
}

// ========== PROGRAMA PRINCIPAL ==========
int main() {
    // ========== DECLARACION DE VARIABLES ==========
    Empleado emple[100];        // arreglo de empleados
    int num_empleados = 0;      // número de empleados
    int opcion;                 // opción del menú
    
    // ========== ENCABEZADO ==========
    printf("================================================\n");
    printf("SISTEMA DE GESTION DE EMPLEADOS (PS8.4)\n");
    printf("================================================\n");
    printf("Santiago de Chile\n\n");
    
    // ========== MENU PRINCIPAL ==========
    while (1) {
        printf("================================================\n");
        printf("MENU PRINCIPAL\n");
        printf("================================================\n\n");
        
        printf("1. Alta de empleado\n");
        printf("2. Baja de empleado\n");
        printf("3. Listado por departamento\n");
        printf("4. Ver todos los empleados\n");
        printf("5. Ver informacion de empleado\n");
        printf("6. Salir\n\n");
        
        printf("Seleccione opcion (1-6): ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: // Alta
                altaEmpleado(emple, &num_empleados);
                break;
                
            case 2: // Baja
                bajaEmpleado(emple, &num_empleados);
                break;
                
            case 3: // Listado por departamento
                listadoDepartamento(emple, num_empleados);
                break;
                
            case 4: // Ver todos
                mostrarTodosEmpleados(emple, num_empleados);
                break;
                
            case 5: // Ver información de empleado
                printf("\n================================================\n");
                printf("BUSCAR EMPLEADO\n");
                printf("================================================\n\n");
                
                int numero;
                printf("Numero de empleado: ");
                scanf("%d", &numero);
                
                int indice = buscarEmpleado(emple, num_empleados, numero);
                
                if (indice == -1) {
                    printf("\n¡ERROR! Empleado no encontrado.\n\n");
                } else {
                    mostrarEmpleado(emple[indice]);
                    printf("\n");
                }
                
                break;
                
            case 6: // Salir
                printf("\n================================================\n");
                printf("RESUMEN FINAL\n");
                printf("================================================\n\n");
                
                printf("Total de empleados registrados: %d\n\n", num_empleados);
                
                if (num_empleados > 0) {
                    double total_salarios = 0;
                    for (int i = 0; i < num_empleados; i++) {
                        total_salarios += emple[i].salario_mensual;
                    }
                    
                    printf("Total de salarios mensuales: $%.2f\n", total_salarios);
                    printf("Promedio de salarios: $%.2f\n\n", total_salarios / num_empleados);
                }
                
                printf("¡Gracias por usar el sistema!\n\n");
                printf("================================================\n\n");
                
                return 0;
                
            default:
                printf("\n¡Opcion invalida!\n\n");
        }
    }
    
    return 0;
}