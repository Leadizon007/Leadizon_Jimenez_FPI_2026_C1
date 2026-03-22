#include <stdio.h>

int main() {
    int N1;
    int N2;
    int N3;
    
    printf("Ingrese el primer numero entero: ");
    scanf("%d", &N1);
    
    printf("Ingrese el segundo numero entero: ");
    scanf("%d", &N2);
    
    printf("Ingrese el tercer numero entero: ");
    scanf("%d", &N3);
    
    // Verificar si los números están en orden creciente
    if (N1 < N2 && N2 < N3) {
        printf("\nLos numeros ESTAN en orden creciente: %d < %d < %d\n", N1, N2, N3);
    }
    else {
        printf("\nLos numeros NO ESTAN en orden creciente\n");
    }
    
    return 0;
}