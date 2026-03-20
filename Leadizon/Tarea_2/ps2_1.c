#include <stdio.h>

int main() {
    int S;
    float FA;
    
    printf("Ingrese el numero de sonidos de grillos por minuto: ");
    scanf("%d", &S);
    
    FA = S / 4.0 + 40;
    
    printf("\nTemperatura: %.2f Fahrenheit\n", FA);
    
    return 0;
}