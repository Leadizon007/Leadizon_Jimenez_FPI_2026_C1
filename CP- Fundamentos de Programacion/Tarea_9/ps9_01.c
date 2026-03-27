#include <stdio.h>

int main() {
    FILE *archivo;
    char cadena[256];   // buffer para cada línea
    int max_longitud = 0;

    archivo = fopen("texto.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while (fgets(cadena, sizeof(cadena), archivo) != NULL) {
        int contador = 0;
        // Contar caracteres manualmente
        while (cadena[contador] != '\0' && cadena[contador] != '\n') {
            contador++;
        }
        if (contador > max_longitud) {
            max_longitud = contador;
        }
    }

    fclose(archivo);

    printf("La longitud de la cadena más grande es: %d\n", max_longitud);

    return 0;
}
