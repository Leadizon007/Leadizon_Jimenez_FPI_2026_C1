#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char cad[30];               // cadena con número telefónico
    char numero_formateado[30]; // cadena con número formateado
    int longitud;               // longitud de la cadena
    int i, j;                   // contadores
    int contador_digitos = 0;   // contador de dígitos
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("     FORMATEAR NUMERO TELEFONICO (PS7.7)\n");
    printf("================================================\n\n");
    
    printf("Convierte un numero telefonico al formato:\n");
    printf("(XX)-X-XXXXXX\n\n");
    
    printf("Ejemplo:\n");
    printf("Entrada:  5256284000\n");
    printf("Salida:   (52)-5-6284000\n\n");
    
    printf("Ingrese un numero telefonico (10 digitos):\n");
    printf("Numero: ");
    fgets(cad, 30, stdin);
    
    // ========== VALIDACION Y PROCESAMIENTO ==========
    // Obtener longitud
    longitud = strlen(cad);
    
    // Eliminar salto de línea
    if (cad[longitud - 1] == '\n') {
        cad[longitud - 1] = '\0';
        longitud--;
    }
    
    // ========== CONTAR Y VALIDAR DIGITOS ==========
    printf("\n================================================\n");
    printf("VALIDACION DEL NUMERO\n");
    printf("================================================\n\n");
    
    for (i = 0; i < longitud; i++) {
        if (isdigit(cad[i])) {
            contador_digitos++;
        }
    }
    
    printf("Cadena ingresada: %s\n", cad);
    printf("Longitud: %d caracteres\n", longitud);
    printf("Digitos encontrados: %d\n\n", contador_digitos);
    
    // Validar que tenga exactamente 10 dígitos
    if (contador_digitos != 10) {
        printf("Error: El numero telefonico debe tener exactamente 10 digitos.\n");
        printf("Digitos encontrados: %d\n", contador_digitos);
        return 1;
    }
    
    // ========== FORMATEAR NUMERO TELEFONICO ==========
    printf("================================================\n");
    printf("FORMATEANDO NUMERO...\n");
    printf("================================================\n\n");
    
    // Extraer solo los dígitos
    char digitos[11];
    int digito_idx = 0;
    
    for (i = 0; i < longitud; i++) {
        if (isdigit(cad[i])) {
            digitos[digito_idx] = cad[i];
            digito_idx++;
        }
    }
    digitos[10] = '\0';
    
    printf("Digitos extraidos: %s\n\n", digitos);
    
    // Construir el número formateado: (XX)-X-XXXXXX
    // Posiciones 0-1 dentro de paréntesis
    // Posición 2 separado
    // Posiciones 3-8 separados
    
    sprintf(numero_formateado, "(%c%c)-%c-%c%c%c%c%c%c",
            digitos[0], digitos[1],
            digitos[2],
            digitos[3], digitos[4], digitos[5], 
            digitos[6], digitos[7], digitos[8], digitos[9]);
    
    printf("Numero formateado: %s\n\n", numero_formateado);
    
    // ========== TABLA DE CARACTERES ORIGINAL ==========
    printf("================================================\n");
    printf("TABLA DE CARACTERES - ENTRADA ORIGINAL\n");
    printf("================================================\n\n");
    
    printf("Pos | Caracter | Es Digito?\n");
    printf("----|----------|----------\n");
    
    for (i = 0; i < longitud; i++) {
        printf(" %2d |    %c    | ", i + 1, cad[i]);
        
        if (isdigit(cad[i])) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    }
    
    // ========== TABLA DE DIGITOS EXTRAIDOS ==========
    printf("\n================================================\n");
    printf("TABLA DE DIGITOS EXTRAIDOS\n");
    printf("================================================\n\n");
    
    printf("Pos | Digito | Uso en Formato\n");
    printf("----|--------|-------------------\n");
    
    for (i = 0; i < 10; i++) {
        printf(" %2d |   %c   | ", i + 1, digitos[i]);
        
        if (i < 2) {
            printf("Dentro paréntesis\n");
        } else if (i == 2) {
            printf("Después paréntesis\n");
        } else {
            printf("Parte final\n");
        }
    }
    
    // ========== TABLA DE CARACTERES FORMATEADO ==========
    printf("\n================================================\n");
    printf("TABLA DE CARACTERES - SALIDA FORMATEADA\n");
    printf("================================================\n\n");
    
    printf("Pos | Caracter | Tipo\n");
    printf("----|----------|------------------\n");
    
    int pos_formato = strlen(numero_formateado);
    for (i = 0; i < pos_formato; i++) {
        printf(" %2d |    %c    | ", i + 1, numero_formateado[i]);
        
        if (numero_formateado[i] == '(') {
            printf("Parentesis abierto\n");
        } else if (numero_formateado[i] == ')') {
            printf("Parentesis cerrado\n");
        } else if (numero_formateado[i] == '-') {
            printf("Separador\n");
        } else {
            printf("Digito\n");
        }
    }
    
    // ========== RESULTADO FINAL ==========
    printf("\n================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Número original:    %s\n", cad);
    printf("Número formateado:  %s\n\n", numero_formateado);
    
    // ========== DESGLOSE DEL FORMATO ==========
    printf("================================================\n");
    printf("DESGLOSE DEL FORMATO\n");
    printf("================================================\n\n");
    
    printf("Estructura: (XX)-X-XXXXXX\n\n");
    
    printf("Componentes:\n");
    printf("  Parte 1 (paréntesis): (%c%c)\n", digitos[0], digitos[1]);
    printf("  Separador 1: -\n");
    printf("  Parte 2: %c\n", digitos[2]);
    printf("  Separador 2: -\n");
    printf("  Parte 3: %c%c%c%c%c%c%c\n", 
           digitos[3], digitos[4], digitos[5], digitos[6],
           digitos[7], digitos[8], digitos[9]);
    
    printf("\nSignificado (ejemplo típico):\n");
    printf("  (%c%c) = Código de país (Mexico = 52)\n", digitos[0], digitos[1]);
    printf("  %c = Area o primer dígito\n", digitos[2]);
    printf("  %c%c%c%c%c%c%c = Número local\n", 
           digitos[3], digitos[4], digitos[5], digitos[6],
           digitos[7], digitos[8], digitos[9]);
    
    // ========== ESTADISTICAS ==========
    printf("\n================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    printf("Longitud original: %d caracteres\n", longitud);
    printf("Digitos validos: %d\n", contador_digitos);
    printf("Caracteres especiales agregados: 3 (2 guiones + 2 paréntesis)\n");
    printf("Longitud formateada: %lu caracteres\n\n", strlen(numero_formateado));
    
    printf("================================================\n\n");
    
    return 0;
}