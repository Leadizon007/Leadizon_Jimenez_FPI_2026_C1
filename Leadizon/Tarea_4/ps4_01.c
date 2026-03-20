#include <stdio.h>

#define NUEVO 100
#define SALIR 0
#define SUMAR 1
#define DIVIDIR 2
#define MULTIPLICAR 3
#define RESTAR 4
#define ERR_DivByZero 100
#define ERR_OK 0

// Declaración de funciones
int sumar(float Num1, float Num2, float *r);
int restar(float Num1, float Num2, float *r);
int multiplicar(float Num1, float Num2, float *r);
int dividir(float Num1, float Num2, float *r);

int main() {
    int menu = NUEVO;
    int cod_err = ERR_OK;
    
    float Num1 = 0.0;
    float Num2 = 0.0;
    float result = 0.0;
    
    do {
        printf("\n================================================\n");
        printf("CALCULADORA\n");
        printf("================================================\n");
        printf("0 - SALIR\n");
        printf("1 - SUMAR\n");
        printf("2 - DIVIDIR\n");
        printf("3 - MULTIPLICAR\n");
        printf("4 - RESTAR\n");
        printf("\nSeleccione opcion: ");
        scanf("%i", &menu);
        
        switch(menu) {
            case SUMAR:
                printf("\nEscriba el primer numero: ");
                scanf("%f", &Num1);
                printf("Escriba el segundo numero: ");
                scanf("%f", &Num2);
                cod_err = sumar(Num1, Num2, &result);
                
                if(cod_err != ERR_OK) {
                    printf("\nERROR EN SUMA\n");
                } else {
                    printf("\nSUMA: %.2f + %.2f = %.2f\n", Num1, Num2, result);
                }
                break;
                
            case RESTAR:
                printf("\nEscriba el primer numero: ");
                scanf("%f", &Num1);
                printf("Escriba el segundo numero: ");
                scanf("%f", &Num2);
                cod_err = restar(Num1, Num2, &result);
                
                if(cod_err != ERR_OK) {
                    printf("\nERROR EN RESTA\n");
                } else {
                    printf("\nRESTA: %.2f - %.2f = %.2f\n", Num1, Num2, result);
                }
                break;
                
            case MULTIPLICAR:
                printf("\nEscriba el primer numero: ");
                scanf("%f", &Num1);
                printf("Escriba el segundo numero: ");
                scanf("%f", &Num2);
                cod_err = multiplicar(Num1, Num2, &result);
                
                if(cod_err != ERR_OK) {
                    printf("\nERROR EN MULTIPLICACION\n");
                } else {
                    printf("\nMULTIPLICACION: %.2f * %.2f = %.2f\n", Num1, Num2, result);
                }
                break;
                
            case DIVIDIR:
                printf("\nEscriba el primer numero: ");
                scanf("%f", &Num1);
                printf("Escriba el segundo numero: ");
                scanf("%f", &Num2);
                cod_err = dividir(Num1, Num2, &result);
                
                if(cod_err != ERR_OK) {
                    printf("\nERROR: Division por cero\n");
                } else {
                    printf("\nDIVISION: %.2f / %.2f = %.2f\n", Num1, Num2, result);
                }
                break;
                
            case SALIR:
                printf("\n¡Gracias por usar la calculadora!\n\n");
                break;
                
            default:
                printf("\nOpcion invalida\n");
        }
        
    } while(menu != SALIR);
    
    return 0;
}

// Definición de funciones
int sumar(float Num1, float Num2, float *r) {
    *r = Num1 + Num2;
    return ERR_OK;
}

int restar(float Num1, float Num2, float *r) {
    *r = Num1 - Num2;
    return ERR_OK;
}

int multiplicar(float Num1, float Num2, float *r) {
    *r = Num1 * Num2;
    return ERR_OK;
}

int dividir(float Num1, float Num2, float *r) {
    if(Num2 == 0.0) {
        return ERR_DivByZero;
    }
    *r = Num1 / Num2;
    return ERR_OK;
}