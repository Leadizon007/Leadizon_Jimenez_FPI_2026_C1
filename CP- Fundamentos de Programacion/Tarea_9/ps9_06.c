#include <stdio.h>
#include <ctype.h>

void revisarOrtografia(FILE *archivo) {
    char actual, anterior = ' ';
    int errores = 0;
    int posicion = 1;

    printf("--- Iniciando revision ortografica ---\n");

    while ((actual = fgetc(archivo)) != EOF) {
        // Convertimos a minusculas para simplificar la comparación
        char lowActual = tolower(actual);
        char lowAnterior = tolower(anterior);

        // Regla:Antes de 'b' va 'm', no 'n'
        if (lowActual == 'b' && lowAnterior == 'n') {
            printf("Error en posicion %d: Se encontro 'nb'. Debe ser 'mb'.\n", posicion);
            errores++;
        }
        // Regla: Antes de 'p' va 'm', no 'n'
        else if (lowActual == 'p' && lowAnterior == 'n') {
            printf("Error en posicion %d: Se encontro 'np'. Debe ser 'mp'.\n", posicion);
            errores++;
        }
        // Regla:Antesde 'v' va 'n', no 'm'
        else if (lowActual == 'v' && lowAnterior == 'm') {
            printf("Error en posicion %d: Se encontro 'mv'. Debe ser 'nv'.\n", posicion);
            errores++;
        }

        anterior = actual;
        posicion++;
    }

    if (errores == 0) {
        printf("Felicidades No se encontraron errores segun las reglas dadas.\n");
    } else {
        printf("\nRevision terminada. Total de errores encontrados: %d\n", errores);
    }
}

int main() {
    FILE *archivo = fopen("doc.dat", "r");

    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo 'doc.dat'. Asegurate de que exista.\n");
        return 1;
    }

    revisarOrtografia(archivo);

    fclose(archivo);
    return 0;
}