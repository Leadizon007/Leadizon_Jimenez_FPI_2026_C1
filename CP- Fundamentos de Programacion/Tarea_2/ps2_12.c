#include <stdio.h>

int main() {
    int NUM;
    int digito1, digito2, digito3, digito4;
    
    printf("Ingrese un numero entero de cuatro digitos: ");
    scanf("%d", &NUM);
    
    // Verificar que el número tenga exactamente cuatro dígitos
    if (NUM < 1000 || NUM > 9999) {
        printf("\nEl numero ingresado no tiene cuatro digitos.\n");
        return 0;
    }
    
    // Extraer cada dígito del número
    digito1 = NUM / 1000;           // Dígito más significativo (miles)
    digito2 = (NUM / 100) % 10;     // Dígito de centenas
    digito3 = (NUM / 10) % 10;      // Dígito de decenas
    digito4 = NUM % 10;             // Dígito menos significativo (unidades)
    
    printf("\nDigitos del numero %d: %d %d %d %d\n", NUM, digito1, digito2, digito3, digito4);
    
    // Verificar si todos los dígitos son pares
    if (digito1 % 2 == 0 && digito2 % 2 == 0 && digito3 % 2 == 0 && digito4 % 2 == 0) {
        printf("TODOS los digitos son PARES.\n");
    }
    else {
        printf("NO todos los digitos son pares. Existe uno o mas digitos impares.\n");
    }
    
    return 0;
}