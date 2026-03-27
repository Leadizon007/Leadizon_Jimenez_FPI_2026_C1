
#include <stdio.h>
#include <ctype.h>  // para tolower

int main() {
    FILE *archivo;
    char c;
    int a=0, e=0, i=0, o=0, u=0;

    archivo = fopen("arc.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while ((c = fgetc(archivo)) != EOF) {
        c = tolower(c);  // convertir a minúscula
        if (c == 'a') a++;
        else if (c == 'e') e++;
        else if (c == 'i') i++;
        else if (c == 'o') o++;
        else if (c == 'u') u++;
    }

    fclose(archivo);

    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i);
    printf("o: %d\n", o);
    printf("u: %d\n", u);

    return 0;
}
