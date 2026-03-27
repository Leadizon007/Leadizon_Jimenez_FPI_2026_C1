#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicion de la estructura del alumno
typedef struct {
    int matricula;
    char nombre[50];
    int carrera;
    float promedio;
} Alumno;

void depurarArchivo(const char *origen, const char *destino) {
    FILE *fEntrada, *fSalida;
    Alumno actual, ultimoProcesado;
    int primerRegistro = 1;
    int totalOriginal = 0, totalDepurado = 0;

    fEntrada = fopen(origen, "rb");
    fSalida = fopen(destino, "wb");

    if (fEntrada == NULL || fSalida == NULL) {
        perror("Error al abrir los archivos");
        return;
    }

    // Leemos el primer registro para tener un punto de comparacion
    while (fread(&actual, sizeof(Alumno), 1, fEntrada)) {
        totalOriginal++;

        // Si es el primer registro que leemos o si la matrícula es distinta ala anterior
        if (primerRegistro || actual.matricula != ultimoProcesado.matricula) {
            fwrite(&actual, sizeof(Alumno), 1, fSalida);
            ultimoProcesado = actual;
            primerRegistro = 0;
            totalDepurado++;
        }
    }

    fclose(fEntrada);
    fclose(fSalida);

    printf("--- Proceso Finalizado ---\n");
    printf("Registros leidos: %d\n", totalOriginal);
    printf("Registros únicos guardados: %d\n", totalDepurado);
    printf("Archivo generado: %s\n", destino);
}

int main() {
    // Nombre de archivo de entrada según el requerimiento
    const char *archivoOrigen = "ad5.dat";
    const char *archivoDestino = "ad5_sin_repetidos.dat";

    depurarArchivo(archivoOrigen, archivoDestino);

    return 0;
}