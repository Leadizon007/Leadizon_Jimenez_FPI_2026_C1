#include <stdio.h>
#include <stdlib.h>

// Definicion de la estructura para los datos del alumno
typedef struct {
    int matricula;
    float cal1;
    float cal2;
    float cal3;
} Alumno;

// Funcin de comparacion para qsort (Orden Ascendente)
int compararMatriculas(const void *a, const void *b) {
    Alumno *alumnoA = (Alumno *)a;
    Alumno *alumnoB = (Alumno *)b;
    return (alumnoA->matricula - alumnoB->matricula);
}

int main() {
    FILE *fEntrada, *fSalida;
    Alumno alumnos[100]; // Capacidad para 100 alumnos (ajustable
    int i = 0, totalAlumnos = 0;

    // 1. Abrir archivo de entrada para lectura
    fEntrada = fopen("arc.dat", "r");
    if (fEntrada == NULL) {
        printf("Error: No se pudo abrir arc.dat\n");
        return 1;
    }

    // 2. Leer los datos y almacenarlos en el arreglo
    while (fscanf(fEntrada, "%d %f %f %f", &alumnos[i].matricula, 
                  &alumnos[i].cal1, &alumnos[i].cal2, &alumnos[i].cal3) == 4) {
        i++;
    }
    totalAlumnos = i;
    fclose(fEntrada);

    // 3. Ordenar el arreglo usando la función qsort de la libreria estndar
    qsort(alumnos, totalAlumnos, sizeof(Alumno), compararMatriculas);

    // 4. Abrir archivo de salida para escritura
    fSalida = fopen("arc1.dat", "w");
    if (fSalida == NULL) {
        printf("Error:No se pudo crear arc1.dat\n");
        return 1;
    }

    // 5. Escribir los datos ordenados en el nuevo archivo
    for (i = 0; i < totalAlumnos; i++) {
        fprintf(fSalida, "%d %.1f %.1f %.1f\n", alumnos[i].matricula, 
                alumnos[i].cal1, alumnos[i].cal2, alumnos[i].cal3);
    }

    fclose(fSalida);
    printf("Proceso completadoSe ha generado arc1.dat con los datos ordenados.\n");

    return 0;
}