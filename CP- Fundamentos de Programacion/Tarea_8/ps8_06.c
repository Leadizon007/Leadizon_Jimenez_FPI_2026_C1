#include <stdio.h>
#include <string.h>

// ========== DEFINICION DE ESTRUCTURAS ==========
typedef struct {
    char calle[50];             // calle y número
    int codigo_postal;          // código postal
    char colonia[50];           // colonia
    char ciudad[50];            // ciudad
} Domicilio;

typedef struct {
    char nivel[20];             // nivel (Primaria, Secundaria, Preparatoria)
    int grado;                  // grado (1-6)
    char salon[10];             // salón
} NivelEstudios;

typedef struct {
    char materia[30];           // nombre de la materia
    double promedio;            // promedio en la materia
} Calificacion;

typedef struct {
    int matricula;              // matrícula del alumno
    char nombre[50];            // nombre y apellido
    Domicilio domicilio;        // estructura de domicilio
    char telefono[15];          // teléfono
    NivelEstudios nivel_estudios;  // nivel de estudios
    Calificacion calificaciones[7]; // 7 materias
} Alumno;

// ========== FUNCIONES AUXILIARES ==========

// Función para buscar alumno por matrícula
int buscarAlumno(Alumno escuela[], int num_alumnos, int matricula) {
    for (int i = 0; i < num_alumnos; i++) {
        if (escuela[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

// Función para calcular promedio general de un alumno
double calcularPromedioGeneral(Calificacion calificaciones[7]) {
    double suma = 0;
    for (int i = 0; i < 7; i++) {
        suma += calificaciones[i].promedio;
    }
    return suma / 7.0;
}

// Función para mostrar información completa de un alumno
void mostrarAlumno(Alumno alumno) {
    printf("\n================================================\n");
    printf("INFORMACION DEL ALUMNO\n");
    printf("================================================\n\n");
    
    printf("Matricula: %d\n", alumno.matricula);
    printf("Nombre: %s\n\n", alumno.nombre);
    
    printf("Domicilio:\n");
    printf("  Calle: %s\n", alumno.domicilio.calle);
    printf("  Colonia: %s\n", alumno.domicilio.colonia);
    printf("  Codigo Postal: %d\n", alumno.domicilio.codigo_postal);
    printf("  Ciudad: %s\n\n", alumno.domicilio.ciudad);
    
    printf("Telefono: %s\n\n", alumno.telefono);
    
    printf("Nivel de Estudios:\n");
    printf("  Nivel: %s\n", alumno.nivel_estudios.nivel);
    printf("  Grado: %d\n", alumno.nivel_estudios.grado);
    printf("  Salon: %s\n\n", alumno.nivel_estudios.salon);
    
    printf("Calificaciones:\n");
    printf("Materia                    | Promedio\n");
    printf"---------------------------|----------\n");
    
    for (int i = 0; i < 7; i++) {
        printf("%-26s | %8.2f\n", 
               alumno.calificaciones[i].materia,
               alumno.calificaciones[i].promedio);
    }
    
    double promedio_general = calcularPromedioGeneral(alumno.calificaciones);
    printf("\nPromedio General: %.2f\n", promedio_general);
}

// Función para módulo A: Promedio general por matrícula
void moduloA(Alumno escuela[], int num_alumnos) {
    printf("\n================================================\n");
    printf("MODULO A: PROMEDIO GENERAL DE ALUMNO\n");
    printf("================================================\n\n");
    
    int matricula;
    printf("Ingrese la matricula del alumno: ");
    scanf("%d", &matricula);
    
    int indice = buscarAlumno(escuela, num_alumnos, matricula);
    
    if (indice == -1) {
        printf("\n¡ERROR! Alumno no encontrado.\n\n");
        return;
    }
    
    Alumno alumno = escuela[indice];
    double promedio_general = calcularPromedioGeneral(alumno.calificaciones);
    
    printf("\n================================================\n");
    printf("RESULTADO\n");
    printf("================================================\n\n");
    
    printf("Matricula: %d\n", alumno.matricula);
    printf("Nombre: %s\n\n", alumno.nombre);
    
    printf("Calificaciones por materia:\n");
    printf("Num | Materia                    | Promedio\n");
    printf"----|---------------------------|----------\n");
    
    for (int i = 0; i < 7; i++) {
        printf(" %d  | %-26s | %8.2f\n",
               i + 1,
               alumno.calificaciones[i].materia,
               alumno.calificaciones[i].promedio);
    }
    
    printf("\nPromedio General: %.2f\n\n", promedio_general);
    
    // Desempeño
    if (promedio_general >= 9.0) {
        printf("Desempeño: Excelente\n\n");
    } else if (promedio_general >= 8.0) {
        printf("Desempe��o: Muy Bueno\n\n");
    } else if (promedio_general >= 7.0) {
        printf("Desempeño: Bueno\n\n");
    } else if (promedio_general >= 6.0) {
        printf("Desempeño: Satisfactorio\n\n");
    } else {
        printf("Desempeño: Deficiente\n\n");
    }
}

// Función para módulo B: Listado por clase
void moduloB(Alumno escuela[], int num_alumnos) {
    printf("\n================================================\n");
    printf("MODULO B: LISTADO DE ALUMNOS POR CLASE\n");
    printf("================================================\n\n");
    
    // Limpiar buffer
    while (getchar() != '\n');
    
    char nivel[20];
    int grado;
    char salon[10];
    
    printf("Ingrese el nivel de estudios: ");
    fgets(nivel, 20, stdin);
    nivel[strlen(nivel) - 1] = '\0';
    
    printf("Ingrese el grado: ");
    scanf("%d", &grado);
    
    // Limpiar buffer
    while (getchar() != '\n');
    
    printf("Ingrese el salon: ");
    fgets(salon, 10, stdin);
    salon[strlen(salon) - 1] = '\0';
    
    printf("\n================================================\n");
    printf("RESULTADO\n");
    printf("================================================\n\n");
    
    printf("Nivel: %s | Grado: %d | Salon: %s\n\n", nivel, grado, salon);
    
    int encontrados = 0;
    double suma_promedios = 0;
    
    printf("Num | Matricula |  Nombre                  | Promedio\n");
    printf"----|-----------|--------------------------|----------\n");
    
    for (int i = 0; i < num_alumnos; i++) {
        if (strcmp(escuela[i].nivel_estudios.nivel, nivel) == 0 &&
            escuela[i].nivel_estudios.grado == grado &&
            strcmp(escuela[i].nivel_estudios.salon, salon) == 0) {
            
            encontrados++;
            double promedio = calcularPromedioGeneral(escuela[i].calificaciones);
            suma_promedios += promedio;
            
            printf(" %d  | %9d | %-24s | %8.2f\n",
                   encontrados,
                   escuela[i].matricula,
                   escuela[i].nombre,
                   promedio);
        }
    }
    
    if (encontrados == 0) {
        printf("No se encontraron alumnos con esos criterios.\n\n");
    } else {
        printf("----|-----------|--------------------------|----------\n");
        printf("Total de alumnos: %d\n", encontrados);
        printf("Promedio de la clase: %.2f\n\n", suma_promedios / encontrados);
    }
}

// Función para módulo C: Mejor alumno de una clase
void moduloC(Alumno escuela[], int num_alumnos) {
    printf("\n================================================\n");
    printf("MODULO C: ALUMNO CON MAYOR PROMEDIO\n");
    printf("================================================\n\n");
    
    // Limpiar buffer
    while (getchar() != '\n');
    
    char nivel[20];
    int grado;
    char salon[10];
    
    printf("Ingrese el nivel de estudios: ");
    fgets(nivel, 20, stdin);
    nivel[strlen(nivel) - 1] = '\0';
    
    printf("Ingrese el grado: ");
    scanf("%d", &grado);
    
    // Limpiar buffer
    while (getchar() != '\n');
    
    printf("Ingrese el salon: ");
    fgets(salon, 10, stdin);
    salon[strlen(salon) - 1] = '\0';
    
    printf("\n================================================\n");
    printf("RESULTADO\n");
    printf("================================================\n\n");
    
    printf("Nivel: %s | Grado: %d | Salon: %s\n\n", nivel, grado, salon);
    
    int indice_mayor = -1;
    double mayor_promedio = -1;
    
    for (int i = 0; i < num_alumnos; i++) {
        if (strcmp(escuela[i].nivel_estudios.nivel, nivel) == 0 &&
            escuela[i].nivel_estudios.grado == grado &&
            strcmp(escuela[i].nivel_estudios.salon, salon) == 0) {
            
            double promedio = calcularPromedioGeneral(escuela[i].calificaciones);
            
            if (promedio > mayor_promedio) {
                mayor_promedio = promedio;
                indice_mayor = i;
            }
        }
    }
    
    if (indice_mayor == -1) {
        printf("No se encontraron alumnos con esos criterios.\n\n");
    } else {
        Alumno alumno = escuela[indice_mayor];
        
        printf("Matricula: %d\n", alumno.matricula);
        printf("Nombre: %s\n", alumno.nombre);
        printf("Promedio General: %.2f\n\n", mayor_promedio);
        
        printf("Calificaciones:\n");
        printf("Materia                    | Promedio\n");
        printf"---------------------------|----------\n");
        
        for (int i = 0; i < 7; i++) {
            printf("%-26s | %8.2f\n",
                   alumno.calificaciones[i].materia,
                   alumno.calificaciones[i].promedio);
        }
        printf("\n");
    }
}

// ========== PROGRAMA PRINCIPAL ==========
int main() {
    // ========== DECLARACION DE VARIABLES ==========
    Alumno escuela[1000];       // arreglo de alumnos
    int num_alumnos = 0;        // número de alumnos
    int opcion;                 // opción del menú
    
    // ========== ENCABEZADO ==========
    printf("================================================\n");
    printf("SISTEMA DE ALUMNOS - ESCUELA PRIVADA (PS8.6)\n");
    printf("================================================\n");
    printf("Ciudad de Mexico\n\n");
    
    // ========== REGISTRO DE ALUMNOS ==========
    printf("================================================\n");
    printf("REGISTRO DE ALUMNOS\n");
    printf("================================================\n\n");
    
    printf("Ingrese la informacion de los alumnos.\n");
    printf("Termine con matricula 0.\n\n");
    
    while (num_alumnos < 1000) {
        printf("Alumno %d\n", num_alumnos + 1);
        printf("Matricula (0 para terminar): ");
        scanf("%d", &escuela[num_alumnos].matricula);
        
        if (escuela[num_alumnos].matricula == 0) {
            break;
        }
        
        // Limpiar buffer
        while (getchar() != '\n');
        
        printf("Nombre y apellido: ");
        fgets(escuela[num_alumnos].nombre, 50, stdin);
        escuela[num_alumnos].nombre[strlen(escuela[num_alumnos].nombre) - 1] = '\0';
        
        printf("\nDomicilio:\n");
        printf("Calle y numero: ");
        fgets(escuela[num_alumnos].domicilio.calle, 50, stdin);
        escuela[num_alumnos].domicilio.calle[strlen(escuela[num_alumnos].domicilio.calle) - 1] = '\0';
        
        printf("Colonia: ");
        fgets(escuela[num_alumnos].domicilio.colonia, 50, stdin);
        escuela[num_alumnos].domicilio.colonia[strlen(escuela[num_alumnos].domicilio.colonia) - 1] = '\0';
        
        printf("Codigo postal: ");
        scanf("%d", &escuela[num_alumnos].domicilio.codigo_postal);
        
        // Limpiar buffer
        while (getchar() != '\n');
        
        printf("Ciudad: ");
        fgets(escuela[num_alumnos].domicilio.ciudad, 50, stdin);
        escuela[num_alumnos].domicilio.ciudad[strlen(escuela[num_alumnos].domicilio.ciudad) - 1] = '\0';
        
        printf("Telefono: ");
        fgets(escuela[num_alumnos].telefono, 15, stdin);
        escuela[num_alumnos].telefono[strlen(escuela[num_alumnos].telefono) - 1] = '\0';
        
        printf("\nNivel de Estudios:\n");
        printf("Nivel (Primaria, Secundaria, Preparatoria): ");
        fgets(escuela[num_alumnos].nivel_estudios.nivel, 20, stdin);
        escuela[num_alumnos].nivel_estudios.nivel[strlen(escuela[num_alumnos].nivel_estudios.nivel) - 1] = '\0';
        
        printf("Grado: ");
        scanf("%d", &escuela[num_alumnos].nivel_estudios.grado);
        
        // Limpiar buffer
        while (getchar() != '\n');
        
        printf("Salon: ");
        fgets(escuela[num_alumnos].nivel_estudios.salon, 10, stdin);
        escuela[num_alumnos].nivel_estudios.salon[strlen(escuela[num_alumnos].nivel_estudios.salon) - 1] = '\0';
        
        printf("\nCalificaciones (7 materias):\n");
        for (int i = 0; i < 7; i++) {
            printf("Materia %d: ", i + 1);
            fgets(escuela[num_alumnos].calificaciones[i].materia, 30, stdin);
            escuela[num_alumnos].calificaciones[i].materia[strlen(escuela[num_alumnos].calificaciones[i].materia) - 1] = '\0';
            
            printf("Promedio: ");
            scanf("%lf", &escuela[num_alumnos].calificaciones[i].promedio);
            
            // Limpiar buffer
            while (getchar() != '\n');
        }
        
        printf("\n");
        
        num_alumnos++;
    }
    
    if (num_alumnos == 0) {
        printf("\nNo se registraron alumnos.\n");
        return 1;
    }
    
    printf("\n%d alumnos registrados.\n\n", num_alumnos);
    
    // ========== MENU PRINCIPAL ==========
    while (1) {
        printf("================================================\n");
        printf("MENU PRINCIPAL\n");
        printf("================================================\n\n");
        
        printf("a) Promedio general de alumno (por matricula)\n");
        printf("b) Listado de alumnos por clase\n");
        printf("c) Mejor alumno de una clase\n");
        printf("d) Ver informacion completa de alumno\n");
        printf("e) Salir\n\n");
        
        printf("Seleccione opcion (a-e): ");
        scanf("%c", (char*)&opcion);
        
        // Limpiar buffer
        while (getchar() != '\n');
        
        switch (opcion) {
            case 'a':
            case 'A':
                moduloA(escuela, num_alumnos);
                break;
                
            case 'b':
            case 'B':
                moduloB(escuela, num_alumnos);
                break;
                
            case 'c':
            case 'C':
                moduloC(escuela, num_alumnos);
                break;
                
            case 'd':
            case 'D':
                printf("\n¿Matricula del alumno? ");
                int matricula;
                scanf("%d", &matricula);
                
                int indice = buscarAlumno(escuela, num_alumnos, matricula);
                
                if (indice == -1) {
                    printf("\n¡ERROR! Alumno no encontrado.\n\n");
                } else {
                    mostrarAlumno(escuela[indice]);
                    printf("\n");
                }
                
                break;
                
            case 'e':
            case 'E':
                printf("\n================================================\n");
                printf("RESUMEN FINAL\n");
                printf("================================================\n\n");
                
                printf("Total de alumnos: %d\n\n", num_alumnos);
                
                double promedio_escuela = 0;
                for (int i = 0; i < num_alumnos; i++) {
                    promedio_escuela += calcularPromedioGeneral(escuela[i].calificaciones);
                }
                promedio_escuela /= num_alumnos;
                
                printf("Promedio general de la escuela: %.2f\n\n", promedio_escuela);
                
                printf("¡Gracias por usar el sistema!\n");
                printf("================================================\n\n");
                
                return 0;
                
            default:
                printf("\nOpcion invalida.\n\n");
        }
    }
    
    return 0;
}