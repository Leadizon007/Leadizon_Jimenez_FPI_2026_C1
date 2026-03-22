#include <stdio.h>
#include <math.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    double X;              // valor en radianes para calcular sen(X)
    double senX = 0.0;     // suma acumulada de la serie
    double terminoAnterior = 0.0;  // término anterior de la serie
    double terminoActual;  // término actual de la serie
    double diferencia;     // diferencia entre términos consecutivos
    int n;                 // número del término
    double factorial;      // factorial de n
    double potencia;       // X elevada a la potencia (2n+1)
    int contTerminos = 0;  // contador de términos utilizados
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    CALCULO DE sen(X) USANDO SERIE DE TAYLOR\n");
    printf("================================================\n\n");
    
    printf("Ingrese el valor de X en radianes: ");
    scanf("%lf", &X);
    
    // ========== PROCESAMIENTO ==========
    printf("\n================================================\n");
    printf("Calculando sen(X) con precision <= 0.001:\n");
    printf("================================================\n\n");
    printf("Termino | Valor Termino | Suma Acumulada | Diferencia\n");
    printf("---------+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
    
    // Serie de Taylor para sen(X):
    // sen(X) = X - X^3/3! + X^5/5! - X^7/7! + ...
    // Término general: (-1)^n * X^(2n+1) / (2n+1)!
    
    n = 0;
    
    // Bucle que calcula términos hasta que la diferencia sea <= 0.001
    while (1) {
        // Calcula factorial de (2n+1)
        factorial = 1.0;
        for (int i = 1; i <= (2 * n + 1); i++) {
            factorial *= i;
        }
        
        // Calcula X^(2n+1)
        potencia = pow(X, 2 * n + 1);
        
        // Calcula el término actual con su signo alternado
        // (-1)^n alterna entre 1 y -1
        terminoActual = (pow(-1.0, n) * potencia) / factorial;
        
        // Acumula el término a la suma
        senX += terminoActual;
        
        contTerminos++;
        
        // Calcula la diferencia absoluta entre términos
        diferencia = fabs(terminoActual - terminoAnterior);
        
        // Muestra el término actual
        printf("%7d | %13.8f | %14.8f | %.8f\n", 
               contTerminos, terminoActual, senX, diferencia);
        
        // Condición de parada: diferencia <= 0.001
        if (diferencia <= 0.001) {
            break;
        }
        
        // Prepara para la siguiente iteración
        terminoAnterior = terminoActual;
        n++;
        
        // Protección contra bucle infinito
        if (contTerminos > 100) {
            printf("\nAdvertencia: Se alcanzó el limite de 100 terminos.\n");
            break;
        }
    }
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n");
    printf("Valor de X: %.8f radianes\n", X);
    printf("sen(X) calculado: %.8f\n", senX);
    printf("sen(X) con math.h: %.8f\n", sin(X));
    printf("Diferencia real: %.8f\n", fabs(senX - sin(X)));
    printf("Numero de terminos utilizados: %d\n", contTerminos);
    printf("Ultima diferencia entre terminos: %.8f\n", diferencia);
    printf("================================================\n\n");
    
    return 0;
}