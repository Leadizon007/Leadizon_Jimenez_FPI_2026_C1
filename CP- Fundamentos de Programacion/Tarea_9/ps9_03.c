#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *archivo;
    char c;
    int contador_palabras = 0;
    int en_palabra = 0;  // bandera para saber si estamos dentro de una palabra

    archivo = fopen("arc.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while ((c = fgetc(archivo)) != EOF) {
        if (isspace(c)) {
            // Si encontramos espacio o salto de línea, cerramos palabra
            if (en_palabra) {
                contador_palabras++;
                en_palabra = 0;
            }
        } else {
            // Si encontramos un carácter no espacio, estamos dentro de una palabra
            en_palabra = 1;
        }
    }

    // Si el archivo termina dentro de una palabra, contarla
    if (en_palabra) {
        contador_palabras++;
    }

    fclose(archivo);

    printf("El archivo contiene %d palabras.\n", contador_palabras);

    return 0;
}
