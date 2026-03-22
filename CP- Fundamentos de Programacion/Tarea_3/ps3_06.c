#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int N;                          // cantidad de personas
    int i;                          // contador para el bucle
    float peso;                     // peso de cada persona
    float altura;                   // altura de cada persona
    int sexo;                       // sexo de cada persona (1=hombre, 0=mujer)
    
    // Contadores y acumuladores para hombres
    int contHombres = 0;            // cantidad de hombres
    float sumaHombres = 0.0;        // suma de pesos de hombres
    float sumaAlturaHombres = 0.0;  // suma de alturas de hombres
    
    // Contadores y acumuladores para mujeres
    int contMujeres = 0;            // cantidad de mujeres
    float sumaMujeres = 0.0;        // suma de pesos de mujeres
    float sumaAlturaMujeres = 0.0;  // suma de alturas de mujeres
    
    // Variables para promedios
    float promedioPesoHombres = 0.0;
    float promedioAlturaHombres = 0.0;
    float promedioPesoMujeres = 0.0;
    float promedioAlturaMujeres = 0.0;
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("  PROMEDIO DE PESO Y ALTURA POR SEXO\n");
    printf("================================================\n\n");
    
    printf("Ingrese la cantidad de personas N: ");
    scanf("%d", &N);
    
    // ========== VALIDACION DE DATOS ==========
    if (N <= 0) {
        printf("\nError: N debe ser un numero positivo (mayor a 0).\n");
        return 1;
    }
    
    // ========== PROCESAMIENTO ==========
    printf("\nIngrese los datos de las %d personas:\n", N);
    printf("(Sexo: 1=Hombre, 0=Mujer)\n\n");
    
    // Bucle para leer datos de N personas
    for (i = 1; i <= N; i++) {
        printf("--- Persona %d ---\n", i);
        
        printf("Peso (kg): ");
        scanf("%f", &peso);
        
        printf("Altura (m): ");
        scanf("%f", &altura);
        
        printf("Sexo (1=Hombre, 0=Mujer): ");
        scanf("%d", &sexo);
        
        printf("\n");
        
        // Clasifica por sexo y acumula datos
        if (sexo == 1) {
            // Es hombre
            contHombres++;
            sumaHombres = sumaHombres + peso;
            sumaAlturaHombres = sumaAlturaHombres + altura;
        } else if (sexo == 0) {
            // Es mujer
            contMujeres++;
            sumaMujeres = sumaMujeres + peso;
            sumaAlturaMujeres = sumaAlturaMujeres + altura;
        } else {
            printf("Advertencia: Sexo invalido. Ingrese 1 (hombre) o 0 (mujer).\n\n");
            i--;  // Repite la entrada para esta persona
        }
    }
    
    // ========== CALCULO DE PROMEDIOS ==========
    // Calcula promedios de hombres
    if (contHombres > 0) {
        promedioPesoHombres = sumaHombres / contHombres;
        promedioAlturaHombres = sumaAlturaHombres / contHombres;
    }
    
    // Calcula promedios de mujeres
    if (contMujeres > 0) {
        promedioPesoMujeres = sumaMujeres / contMujeres;
        promedioAlturaMujeres = sumaAlturaMujeres / contMujeres;
    }
    
    // ========== SALIDA DE RESULTADOS ==========
    printf("\n================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Total de personas: %d\n\n", N);
    
    // Resultados para hombres
    printf("--- HOMBRES ---\n");
    printf("Cantidad de hombres: %d\n", contHombres);
    if (contHombres > 0) {
        printf("Promedio de peso: %.2f kg\n", promedioPesoHombres);
        printf("Promedio de altura: %.2f m\n", promedioAlturaHombres);
    } else {
        printf("No hay datos de hombres.\n");
    }
    
    printf("\n--- MUJERES ---\n");
    printf("Cantidad de mujeres: %d\n", contMujeres);
    if (contMujeres > 0) {
        printf("Promedio de peso: %.2f kg\n", promedioPesoMujeres);
        printf("Promedio de altura: %.2f m\n", promedioAlturaMujeres);
    } else {
        printf("No hay datos de mujeres.\n");
    }
    
    printf("\n================================================\n\n");
    
    return 0;
}