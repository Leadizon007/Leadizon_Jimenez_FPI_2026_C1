#include <stdio.h>
#include <math.h>

int main() {
    float L1, L2, L3;
    float semiperimetro;
    float area;
    float lado1, lado2, lado3;
    
    printf("Ingrese el primer lado del triangulo: ");
    scanf("%f", &L1);
    
    printf("Ingrese el segundo lado del triangulo: ");
    scanf("%f", &L2);
    
    printf("Ingrese el tercer lado del triangulo: ");
    scanf("%f", &L3);
    
    // Ordenar los lados para identificar el mayor
    if (L1 > L2 && L1 > L3) {
        lado3 = L1;
        lado1 = L2;
        lado2 = L3;
    }
    else if (L2 > L1 && L2 > L3) {
        lado3 = L2;
        lado1 = L1;
        lado2 = L3;
    }
    else {
        lado3 = L3;
        lado1 = L1;
        lado2 = L2;
    }
    
    // Verificar si es un triángulo válido
    // La suma de los dos lados menores debe ser mayor que el lado mayor
    if (lado1 + lado2 > lado3) {
        printf("\nLos lados forman un TRIANGULO valido.\n");
        
        // Calcular el semiperímetro
        semiperimetro = (L1 + L2 + L3) / 2.0;
        
        // Calcular el área usando la fórmula de Herón
        area = sqrt(semiperimetro * (semiperimetro - L1) * (semiperimetro - L2) * (semiperimetro - L3));
        
        printf("Area del triangulo: %.2f\n", area);
        
        // Determinar el tipo de triángulo
        if (L1 == L2 && L2 == L3) {
            printf("Tipo de triangulo: EQUILATERO (todos los lados son iguales)\n");
        }
        else if (L1 == L2 || L2 == L3 || L1 == L3) {
            printf("Tipo de triangulo: ISOSCELES (dos lados son iguales)\n");
        }
        else {
            printf("Tipo de triangulo: ESCALENO (todos los lados son diferentes)\n");
        }
    }
    else {
        printf("\nLos lados NO forman un triangulo valido.\n");
        printf("La suma de los dos lados menores debe ser mayor que el lado mayor.\n");
    }
    
    return 0;
}