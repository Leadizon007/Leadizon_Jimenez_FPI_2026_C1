#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char calle[50];
    int numero;
    char colonia[50];
    char codigoPostal[10];
    char ciudad[50];
    char telefono[15];
} Domicilio;

typedef struct {
    int clave;
    char nombre[50];
    int edad;
    char sexo; // 'H' o 'M'
    int condicion; // 1 a 5
    Domicilio domicilio;
} Paciente;

int main() {
    FILE *fp;
    Paciente p;
    int total = 0, hombres = 0, mujeres = 0;
    int condiciones[6] = {0}; // indices 1-5
    int edades[11] = {0};     // rangos de edad

    fp = fopen("pacientes.dat", "rb");
    if (fp == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while (fread(&p, sizeof(Paciente), 1, fp)) {
        total++;

        // Contar sexo
        if (p.sexo == 'H' || p.sexo == 'h')
            hombres++;
        else if (p.sexo == 'M' || p.sexo == 'm')
            mujeres++;

        // Contar condicion
        if (p.condicion >= 1 && p.condicion <= 5)
            condiciones[p.condicion]++;

        // edad
        if (p.edad >= 0 && p.edad <= 9) edades[0]++;
        else if (p.edad <= 19) edades[1]++;
        else if (p.edad <= 29) edades[2]++;
        else if (p.edad <= 39) edades[3]++;
        else if (p.edad <= 49) edades[4]++;
        else if (p.edad <= 59) edades[5]++;
        else if (p.edad <= 69) edades[6]++;
        else if (p.edad <= 79) edades[7]++;
        else if (p.edad <= 89) edades[8]++;
        else if (p.edad <= 99) edades[9]++;
        else edades[10]++;
    }

    fclose(fp);

    // Resultados
    printf("Total de pacientes: %d\n", total);
    printf("Porcentaje hombres: %.2f%%\n", (total ? (hombres * 100.0 / total) : 0));
    printf("Porcentaje mujeres: %.2f%%\n", (total ? (mujeres * 100.0 / total) : 0));

    printf("\nPacientes por condición:\n");
    for (int i = 1; i <= 5; i++) {
        printf("Condición %d: %d\n", i, condiciones[i]);
    }

    printf("\nPacientes por rango de edad:\n");
    printf("0-9: %d\n", edades[0]);
    printf("10-19: %d\n", edades[1]);
    printf("20-29: %d\n", edades[2]);
    printf("30-39: %d\n", edades[3]);
    printf("40-49: %d\n", edades[4]);
    printf("50-59: %d\n", edades[5]);
    printf("60-69: %d\n", edades[6]);
    printf("70-79: %d\n", edades[7]);
    printf("80-89: %d\n", edades[8]);
    printf("90-99: %d\n", edades[9]);
    printf(">=100: %d\n", edades[10]);

    return 0;
}
