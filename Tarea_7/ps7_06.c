#include <stdio.h>
#include <string.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char cadena[20];            // cadena temporal
    char mayor_cadena[20];      // cadena de mayor longitud
    int longitud;               // longitud de la cadena actual
    int mayor_longitud = 0;     // mayor longitud encontrada
    int num_cadenas = 0;        // número de cadenas ingresadas
    char respuesta;             // respuesta del usuario (S/N)
    int i;                      // contador
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("     ENCONTRAR CADENA DE MAYOR LONGITUD (PS7.6)\n");
    printf("================================================\n\n");
    
    printf("Este programa lee cadenas de caracteres y\n");
    printf("determina cual es la de mayor longitud.\n\n");
    
    printf("Nota: Cada cadena tiene un maximo de 20 caracteres.\n");
    printf("      Se le preguntara si desea ingresar cada cadena.\n\n");
    
    // ========== LECTURA DE CADENAS ==========
    printf("================================================\n");
    printf("INGRESO DE CADENAS\n");
    printf("================================================\n\n");
    
    while (1) {
        num_cadenas++;
        
        printf("¿Desea ingresar la cadena %d? (S/N): ", num_cadenas);
        scanf("%c", &respuesta);
        
        // Limpiar el buffer de entrada
        while (getchar() != '\n');
        
        // Validar respuesta
        if (respuesta == 'S' || respuesta == 's') {
            printf("Ingrese la cadena %d (máximo 20 caracteres): ", num_cadenas);
            fgets(cadena, 20, stdin);
            
            // Obtener longitud
            longitud = strlen(cadena);
            
            // Eliminar salto de línea si existe
            if (cadena[longitud - 1] == '\n') {
                cadena[longitud - 1] = '\0';
                longitud--;
            }
            
            // Mostrar información de la cadena
            printf("Cadena ingresada: %s\n", cadena);
            printf("Longitud: %d caracteres\n\n", longitud);
            
            // Comparar con la mayor encontrada
            if (longitud > mayor_longitud) {
                mayor_longitud = longitud;
                strcpy(mayor_cadena, cadena);
            }
            
        } else if (respuesta == 'N' || respuesta == 'n') {
            printf("Ingreso finalizado.\n\n");
            num_cadenas--;
            break;
        } else {
            printf("Respuesta invalida. Intente nuevamente (S/N).\n\n");
            num_cadenas--;
        }
    }
    
    // ========== VERIFICACION ==========
    if (num_cadenas == 0) {
        printf("\nError: No se ingresaron cadenas.\n");
        return 1;
    }
    
    // ========== RESULTADO FINAL ==========
    printf("================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Total de cadenas ingresadas: %d\n\n", num_cadenas);
    
    printf("Cadena de MAYOR longitud:\n");
    printf("  Contenido: %s\n", mayor_cadena);
    printf("  Longitud: %d caracteres\n\n", mayor_longitud);
    
    printf("================================================\n\n");
    
    return 0;
}