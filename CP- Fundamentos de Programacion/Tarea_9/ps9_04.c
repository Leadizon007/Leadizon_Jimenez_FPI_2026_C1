#include <stdio.h>
#include <string.h>

int main() {
    FILE *archivo;
    char cad[50];
    char linea[256];
    int contador = 0;

    printf("Ingrese la cadena a buscar: ");
    scanf("%s", cad);

    archivo = fopen("arc2.txt", "r");
    if (archivo == NULL) {
        printf("No se logro abrir.\n");
        return 1;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        int lenCad = strlen(cad);
        int lenLinea = strlen(linea);

        for (int i = 0; i <= lenLinea - lenCad; i++) {
            int j;
            for (j = 0; j < lenCad; j++) {
                if (linea[i + j] != cad[j]) {
                    break;
                }
            }
            if (j == lenCad) {
                contador++;
            }
        }
    }

    fclose(archivo);

    printf("La cadena '%s' aparece %d veces en el archivo.\n", cad, contador);

    return 0;
}
