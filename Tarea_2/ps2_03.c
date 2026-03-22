#include <stdio.h>

int main() {
    int N1;
    int N2;
    int residuo;
    
    printf("Ingrese el primer numero entero: ");
    scanf("%d", &N1);
    
    printf("Ingrese el segundo numero entero: ");
    scanf("%d", &N2);
    
    // Calcular el residuo de la división N2 / N1
    residuo = N2 % N1;
    
    // Determinar si N1 es divisor de N2
    if (residuo == 0) {
        printf("\n%d ES divisor de %d\n", N1, N2);
    }
    else {
        printf("\n%d NO ES divisor de %d\n", N1, N2);
    }
    
    return 0;
}