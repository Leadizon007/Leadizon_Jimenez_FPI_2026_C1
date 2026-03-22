#include <stdio.h>

int main() {
    float N1;
    float N2;
    float N3;
    float mayor;
    
    printf("Ingrese el primer numero real: ");
    scanf("%f", &N1);
    
    printf("Ingrese el segundo numero real: ");
    scanf("%f", &N2);
    
    printf("Ingrese el tercer numero real: ");
    scanf("%f", &N3);
    
    // Determinar cuál es el mayor número
    if (N1 >= N2 && N1 >= N3) {
        mayor = N1;
    }
    else if (N2 >= N1 && N2 >= N3) {
        mayor = N2;
    }
    else {
        mayor = N3;
    }
    
    // Mostrar el resultado
    printf("\nEl numero mayor es: %.2f\n", mayor);
    
    return 0;
}