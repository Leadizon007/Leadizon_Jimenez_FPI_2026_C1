#include <stdio.h>
#include <string.h>

#define MAX_LINEAS 100
#define MAX_LONG 256

int main() {
    FILE *entrada, *salida;
    char lineas[MAX_LINEAS][MAX_LONG];
    int total = 0;

    // Abrir archivo de entrada
    entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) {
        printf("No se pudo abrir el archivo de entrada.\n");
        return 1;
    }

    // Leer líneas y guardarlas
    while (fgets(lineas[total], MAX_LONG, entrada) != NULL) {
        total++;
    }

    fclose(entrada);

    // Intercambiar líneas
    for (int i = 0; i < total / 2; i++) {
        char temp[MAX_LONG];
        strcpy(temp, lineas[i]);
        strcpy(lineas[i], lineas[total - 1 - i]);
        strcpy(lineas[total - 1 - i], temp);
    }

    // Crear archivo de salida
    salida = fopen("salida.txt", "w");
    if (salida == NULL) {
        printf("No se pudo crear el archivo de salida.\n");
        return 1;
    }

    // Escribir líneas intercambiadas
    for (int i = 0; i < total; i++) {
        fputs(lineas[i], salida);
    }

    fclose(salida);

    printf("Archivo generado correctamente.\n");

    return 0;
}