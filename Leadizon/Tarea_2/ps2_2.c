#include <stdio.h>

int main() {
    float SAL;
    float incremento;
    float nuevoSAL;
    
    printf("Ingrese el salario del profesor: $");
    scanf("%f", &SAL);
    
    // Determinar el porcentaje de incremento según el salario
    if (SAL < 18000) {
        incremento = SAL * 0.12;  // Incremento 12%
    }
    else if (SAL >= 18000 && SAL <= 30000) {
        incremento = SAL * 0.08;  // Incremento 8%
    }
    else if (SAL > 30000 && SAL <= 50000) {
        incremento = SAL * 0.07;  // Incremento 7%
    }
    else {  // SAL > 50000
        incremento = SAL * 0.06;  // Incremento 6%
    }
    
    // Calcular el nuevo salario
    nuevoSAL = SAL + incremento;
    
    // Mostrar resultados
    printf("\nSalario Original: $%.2f\n", SAL);
    printf("Incremento: $%.2f\n", incremento);
    printf("Nuevo Salario: $%.2f\n", nuevoSAL);
    
    return 0;
}