#include <stdio.h>

int main() {
    int S;
    float FA;

    printf("Ingrese el numero de sonidos de grillos por minuto: ");

    if (scanf("%d", &S) != 1) {
        printf("Error: no se ingreso un numero valido.\n");
        return 1;
    }

    FA = S / 4.0 + 40;

    printf("Temperatura: %.2f Fahrenheit\n", FA);

    return 0;
}