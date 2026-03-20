#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ========== DEFINICION DE ESTRUCTURAS ==========
typedef struct {
    char nombre[30];            // nombre del equipo
    int partidos_jugados;       // partidos jugados
    int partidos_ganados;       // partidos ganados
    int partidos_empatados;     // partidos empatados
    int partidos_perdidos;      // partidos perdidos
    int goles_favor;            // goles a favor
    int goles_contra;           // goles en contra
    int diferencia_goles;       // diferencia de goles
    int puntos;                 // puntos
} Equipo;

// ========== FUNCIONES AUXILIARES ==========

// Función para buscar equipo por nombre
int buscarEquipo(Equipo futbol[], int num_equipos, char nombre[]) {
    for (int i = 0; i < num_equipos; i++) {
        if (strcmp(futbol[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

// Función para actualizar partido
void actualizarPartido(Equipo futbol[], int num_equipos,
                      char equipo1[], int goles1,
                      char equipo2[], int goles2) {
    int indice1 = buscarEquipo(futbol, num_equipos, equipo1);
    int indice2 = buscarEquipo(futbol, num_equipos, equipo2);
    
    if (indice1 == -1 || indice2 == -1) {
        printf("\n¡ERROR! Uno o ambos equipos no existen.\n");
        return;
    }
    
    // Actualizar estadísticas generales
    futbol[indice1].partidos_jugados++;
    futbol[indice2].partidos_jugados++;
    
    futbol[indice1].goles_favor += goles1;
    futbol[indice1].goles_contra += goles2;
    
    futbol[indice2].goles_favor += goles2;
    futbol[indice2].goles_contra += goles1;
    
    // Actualizar diferencia de goles
    futbol[indice1].diferencia_goles = 
        futbol[indice1].goles_favor - futbol[indice1].goles_contra;
    futbol[indice2].diferencia_goles = 
        futbol[indice2].goles_favor - futbol[indice2].goles_contra;
    
    // Actualizar resultado
    if (goles1 > goles2) {
        // Ganó equipo1
        futbol[indice1].partidos_ganados++;
        futbol[indice1].puntos += 3;
        
        futbol[indice2].partidos_perdidos++;
    } else if (goles1 < goles2) {
        // Ganó equipo2
        futbol[indice2].partidos_ganados++;
        futbol[indice2].puntos += 3;
        
        futbol[indice1].partidos_perdidos++;
    } else {
        // Empate
        futbol[indice1].partidos_empatados++;
        futbol[indice1].puntos += 1;
        
        futbol[indice2].partidos_empatados++;
        futbol[indice2].puntos += 1;
    }
}

// Función para ordenar equipos por puntos (de mayor a menor)
void ordenarEquipos(Equipo futbol[], int num_equipos) {
    for (int i = 0; i < num_equipos - 1; i++) {
        for (int j = 0; j < num_equipos - i - 1; j++) {
            // Comparar primero por puntos (descendente)
            if (futbol[j].puntos < futbol[j + 1].puntos) {
                Equipo temp = futbol[j];
                futbol[j] = futbol[j + 1];
                futbol[j + 1] = temp;
            } else if (futbol[j].puntos == futbol[j + 1].puntos) {
                // Si puntos iguales, comparar por diferencia de goles
                if (futbol[j].diferencia_goles < futbol[j + 1].diferencia_goles) {
                    Equipo temp = futbol[j];
                    futbol[j] = futbol[j + 1];
                    futbol[j + 1] = temp;
                } else if (futbol[j].diferencia_goles == futbol[j + 1].diferencia_goles) {
                    // Si diferencia igual, comparar por goles a favor
                    if (futbol[j].goles_favor < futbol[j + 1].goles_favor) {
                        Equipo temp = futbol[j];
                        futbol[j] = futbol[j + 1];
                        futbol[j + 1] = temp;
                    }
                }
            }
        }
    }
}

// Función para mostrar tabla de posiciones
void mostrarTabla(Equipo futbol[], int num_equipos) {
    printf("\n================================================\n");
    printf("TABLA DE POSICIONES\n");
    printf("================================================\n\n");
    
    printf("Pos | Equipo                 | PJ | G | E | P | GF | GC | DG | Pts\n");
    printf"----|------------------------|----|----|----|----|----|----|----|----|---\n");
    
    for (int i = 0; i < num_equipos; i++) {
        printf("%2d  | %-22s | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d\n",
               i + 1,
               futbol[i].nombre,
               futbol[i].partidos_jugados,
               futbol[i].partidos_ganados,
               futbol[i].partidos_empatados,
               futbol[i].partidos_perdidos,
               futbol[i].goles_favor,
               futbol[i].goles_contra,
               futbol[i].diferencia_goles,
               futbol[i].puntos);
    }
    
    printf("\n");
}

// Función para mostrar estadísticas detalladas de un equipo
void mostrarEquipo(Equipo equipo, int posicion) {
    printf("\n================================================\n");
    printf("ESTADISTICAS DEL EQUIPO\n");
    printf("================================================\n\n");
    
    printf("Posicion: %d\n", posicion);
    printf("Nombre: %s\n\n", equipo.nombre);
    
    printf("Partidos:\n");
    printf("  Jugados: %d\n", equipo.partidos_jugados);
    printf("  Ganados: %d\n", equipo.partidos_ganados);
    printf("  Empatados: %d\n", equipo.partidos_empatados);
    printf("  Perdidos: %d\n\n", equipo.partidos_perdidos);
    
    printf("Goles:\n");
    printf("  A favor: %d\n", equipo.goles_favor);
    printf("  En contra: %d\n", equipo.goles_contra);
    printf("  Diferencia: %d\n\n", equipo.diferencia_goles);
    
    printf("Puntos: %d\n\n", equipo.puntos);
    
    if (equipo.partidos_jugados > 0) {
        printf("Promedio de goles por partido: %.2f\n", 
               (double)equipo.goles_favor / equipo.partidos_jugados);
    }
}

// ========== PROGRAMA PRINCIPAL ==========
int main() {
    // ========== DECLARACION DE VARIABLES ==========
    Equipo futbol[20];          // arreglo de equipos
    int num_equipos = 0;        // número de equipos
    char nombre_equipo[30];     // nombre de equipo ingresado
    char equipo1[30], equipo2[30];  // nombres de equipos que juegan
    int goles1, goles2;         // goles del partido
    int opcion;                 // opción del menú
    char respuesta;             // respuesta del usuario
    
    // ========== ENCABEZADO ==========
    printf("================================================\n");
    printf("TABLA DE POSICIONES FEMEXFUT (PS8.2)\n");
    printf("================================================\n\n");
    
    printf("Sistema de actualizacion de tabla de posiciones\n\n");
    
    // ========== REGISTRO DE EQUIPOS ==========
    printf("================================================\n");
    printf("REGISTRO DE EQUIPOS\n");
    printf("================================================\n\n");
    
    printf("Ingrese los equipos. Termine con una cadena vacia.\n\n");
    
    while (num_equipos < 20) {
        printf("Equipo %d: ", num_equipos + 1);
        fgets(nombre_equipo, 30, stdin);
        
        // Eliminar salto de línea
        nombre_equipo[strlen(nombre_equipo) - 1] = '\0';
        
        if (strlen(nombre_equipo) == 0) {
            break;
        }
        
        strcpy(futbol[num_equipos].nombre, nombre_equipo);
        futbol[num_equipos].partidos_jugados = 0;
        futbol[num_equipos].partidos_ganados = 0;
        futbol[num_equipos].partidos_empatados = 0;
        futbol[num_equipos].partidos_perdidos = 0;
        futbol[num_equipos].goles_favor = 0;
        futbol[num_equipos].goles_contra = 0;
        futbol[num_equipos].diferencia_goles = 0;
        futbol[num_equipos].puntos = 0;
        
        num_equipos++;
    }
    
    if (num_equipos == 0) {
        printf("\nNo se registraron equipos.\n");
        return 1;
    }
    
    printf("\n%d equipos registrados.\n\n", num_equipos);
    
    // ========== MOSTRAR TABLA INICIAL ==========
    mostrarTabla(futbol, num_equipos);
    
    // ========== MENU PRINCIPAL ==========
    while (1) {
        printf("================================================\n");
        printf("MENU PRINCIPAL\n");
        printf("================================================\n\n");
        
        printf("1. Ingresar resultado de partido\n");
        printf("2. Ver tabla de posiciones\n");
        printf("3. Ver estadisticas de equipo\n");
        printf("4. Terminar\n\n");
        
        printf("Seleccione opcion (1-4): ");
        scanf("%d", &opcion);
        
        // Limpiar buffer
        while (getchar() != '\n');
        
        switch (opcion) {
            case 1: // Ingresar resultado
                printf("\n================================================\n");
                printf("INGRESO DE RESULTADO\n");
                printf("================================================\n\n");
                
                printf("Ingrese el resultado en formato: Equipo1 Goles1 Equipo2 Goles2\n");
                printf("Ejemplo: America 0 Puebla 2\n\n");
                
                printf("Equipo 1: ");
                fgets(equipo1, 30, stdin);
                equipo1[strlen(equipo1) - 1] = '\0';
                
                printf("Goles equipo 1: ");
                scanf("%d", &goles1);
                
                // Limpiar buffer
                while (getchar() != '\n');
                
                printf("Equipo 2: ");
                fgets(equipo2, 30, stdin);
                equipo2[strlen(equipo2) - 1] = '\0';
                
                printf("Goles equipo 2: ");
                scanf("%d", &goles2);
                
                // Limpiar buffer
                while (getchar() != '\n');
                
                printf("\n%s %d - %s %d\n\n", equipo1, goles1, equipo2, goles2);
                
                actualizarPartido(futbol, num_equipos, equipo1, goles1, equipo2, goles2);
                ordenarEquipos(futbol, num_equipos);
                
                printf("Partido registrado.\n");
                
                break;
                
            case 2: // Ver tabla
                mostrarTabla(futbol, num_equipos);
                
                break;
                
            case 3: // Ver estadísticas
                printf("\nIngrese el nombre del equipo: ");
                fgets(nombre_equipo, 30, stdin);
                nombre_equipo[strlen(nombre_equipo) - 1] = '\0';
                
                int indice = buscarEquipo(futbol, num_equipos, nombre_equipo);
                
                if (indice == -1) {
                    printf("\n¡ERROR! Equipo no encontrado.\n");
                } else {
                    // Encontrar posición después de ordenar
                    int posicion = 1;
                    for (int i = 0; i < num_equipos; i++) {
                        if (strcmp(futbol[i].nombre, nombre_equipo) == 0) {
                            posicion = i + 1;
                            break;
                        }
                    }
                    mostrarEquipo(futbol[indice], posicion);
                }
                
                break;
                
            case 4: // Terminar
                printf("\n¡Gracias por usar el sistema!\n\n");
                
                printf("================================================\n");
                printf("TABLA FINAL DE POSICIONES\n");
                printf("================================================\n\n");
                mostrarTabla(futbol, num_equipos);
                
                printf("================================================\n\n");
                
                return 0;
                
            default:
                printf("\nOpcion invalida.\n");
        }
    }
    
    return 0;
}