#include <stdio.h>

int main() {
    int Y;
    float resultado;
    int residuo;
    
    printf("Ingrese un numero entero Y: ");
    scanf("%d", &Y);
    
    // Calcular el residuo de Y dividido entre 4
    residuo = Y % 4;
    
    // Calcular f(X) según el residuo
    if (residuo == 0) {
        resultado = 86;  // Si (Y mod 4) = 0, f(X) = 86
    }
    else if (residuo == 1) {
        resultado = Y * 3;  // Si (Y mod 4) = 1, f(X) = Y * 3
    }
    else if (residuo == 2) {
        resultado = (Y * 2 - 14) / (float)Y;  // Si (Y mod 4) = 2, f(X) = (Y2 - 14) / Y
    }
    else {  // residuo == 3
        resultado = Y + 5;  // Si (Y mod 4) = 3, f(X) = Y + 5
    }
    
    // Mostrar el resultado
    printf("\nPara Y = %d\n", Y);
    printf("Residuo de Y mod 4 = %d\n", residuo);
    printf("f(X) = %.2f\n", resultado);
    
    return 0;
}