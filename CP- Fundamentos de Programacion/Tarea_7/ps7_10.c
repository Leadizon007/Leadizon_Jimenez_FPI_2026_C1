#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char cadena[50];            // cadena ingresada
    char fecha_hoy[11];         // fecha de hoy en formato dd/mm/yyyy
    char fecha_cadena[11];      // fecha extraída de la cadena
    char contenido[50];         // contenido de la cadena sin fecha
    int num_cadenas = 0;        // número de cadenas ingresadas
    int cadenas_validas = 0;    // cadenas con fecha actual
    char respuesta;             // respuesta del usuario (S/N)
    int i;                      // contador
    
    // Arreglos para almacenar cadenas válidas
    char cadenas_filtradas[20][50];
    char fechas_filtradas[20][11];
    
    // ========== OBTENER FECHA ACTUAL ==========
    time_t tiempo_actual = time(NULL);
    struct tm *tiempo_local = localtime(&tiempo_actual);
    
    // Formatear fecha: dd/mm/yyyy
    sprintf(fecha_hoy, "%02d/%02d/%04d",
            tiempo_local->tm_mday,
            tiempo_local->tm_mon + 1,
            tiempo_local->tm_year + 1900);
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("FILTRAR CADENAS POR FECHA ACTUAL (PS7.10)\n");
    printf("================================================\n\n");
    
    printf("Este programa lee cadenas con formato:\n");
    printf("dd/mm/yyyy Contenido\n\n");
    
    printf("y muestra solo aquellas que tengan la fecha de hoy.\n\n");
    
    printf("Fecha actual del sistema: %s\n\n", fecha_hoy);
    
    printf("Nota: Se le preguntara si desea ingresar cada cadena.\n");
    printf("      Responda con S (Si) o N (No).\n\n");
    
    // ========== LECTURA DE CADENAS ==========
    printf("================================================\n");
    printf("INGRESO DE CADENAS\n");
    printf("================================================\n\n");
    
    while (1) {
        num_cadenas++;
        
        printf("¿Desea ingresar la cadena %d? (S/N): ", num_cadenas);
        scanf("%c", &respuesta);
        
        // Limpiar buffer
        while (getchar() != '\n');
        
        // Validar respuesta
        if (respuesta == 'S' || respuesta == 's') {
            printf("Ingrese la cadena %d (formato: dd/mm/yyyy Contenido):\n", num_cadenas);
            printf("Cadena: ");
            fgets(cadena, 50, stdin);
            
            // Eliminar salto de línea
            int longitud = strlen(cadena);
            if (cadena[longitud - 1] == '\n') {
                cadena[longitud - 1] = '\0';
                longitud--;
            }
            
            printf("Cadena ingresada: %s\n", cadena);
            printf("Longitud: %d caracteres\n\n", (int)strlen(cadena));
            
            // ========== EXTRAER FECHA DE LA CADENA ==========
            // Validar que tenga al menos 10 caracteres para la fecha
            if (strlen(cadena) >= 10) {
                // Extraer los primeros 10 caracteres como fecha
                strncpy(fecha_cadena, cadena, 10);
                fecha_cadena[10] = '\0';
                
                // Extraer contenido (después de la fecha y espacio)
                if (strlen(cadena) > 11) {
                    strcpy(contenido, cadena + 11);
                } else {
                    strcpy(contenido, "");
                }
                
                printf("Fecha extraída: %s\n", fecha_cadena);
                printf("Contenido: %s\n\n", contenido);
                
                // ========== COMPARAR FECHAS ==========
                if (strcmp(fecha_cadena, fecha_hoy) == 0) {
                    printf("✓ COINCIDE CON FECHA ACTUAL\n\n");
                    
                    // Guardar en arreglo de filtradas
                    strcpy(cadenas_filtradas[cadenas_validas], cadena);
                    strcpy(fechas_filtradas[cadenas_validas], fecha_cadena);
                    cadenas_validas++;
                } else {
                    printf("✗ NO COINCIDE CON FECHA ACTUAL\n\n");
                }
            } else {
                printf("✗ ERROR: Cadena sin formato valido (muy corta)\n\n");
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
    
    // ========== TABLA DE TODAS LAS CADENAS ==========
    printf("================================================\n");
    printf("TABLA DE TODAS LAS CADENAS INGRESADAS\n");
    printf("================================================\n\n");
    
    printf("Num | Fecha      | ¿Hoy? | Contenido\n");
    printf"----|------------|-------|------------------------\n");
    
    for (i = 0; i < num_cadenas; i++) {
        // Reconstruir las cadenas (necesitamos guardarlas en el proceso anterior)
        // Por ahora mostraremos las filtradas
        printf(" %d  | %s |  SI   | %s\n", 
               i + 1, fechas_filtradas[i], 
               cadenas_filtradas[i] + 11);
    }
    
    // ========== TABLA DE CADENAS FILTRADAS ==========
    printf("\n================================================\n");
    printf("CADENAS CON FECHA DE HOY\n");
    printf("================================================\n\n");
    
    printf("Fecha del sistema: %s\n\n", fecha_hoy);
    printf("Total de cadenas ingresadas: %d\n", num_cadenas);
    printf("Cadenas con fecha actual: %d\n\n", cadenas_validas);
    
    if (cadenas_validas == 0) {
        printf("No se encontraron cadenas con la fecha de hoy.\n\n");
    } else {
        printf("Num | Cadena Completa\n");
        printf"----|------------------------\n");
        
        for (i = 0; i < cadenas_validas; i++) {
            printf(" %d  | %s\n", i + 1, cadenas_filtradas[i]);
        }
    }
    
    // ========== DESGLOSE DE FECHAS ==========
    printf("\n================================================\n");
    printf("DESGLOSE DE FECHAS\n");
    printf("================================================\n\n");
    
    printf("Fecha actual del sistema:\n");
    printf("  Día: %02d\n", tiempo_local->tm_mday);
    printf("  Mes: %02d\n", tiempo_local->tm_mon + 1);
    printf("  Año: %04d\n\n", tiempo_local->tm_year + 1900);
    
    printf("Formato completo: %s\n\n", fecha_hoy);
    
    // ========== ESTADISTICAS ==========
    printf("================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    printf("Total de cadenas ingresadas: %d\n", num_cadenas);
    printf("Cadenas con fecha actual: %d\n", cadenas_validas);
    printf("Cadenas sin fecha actual: %d\n\n", num_cadenas - cadenas_validas);
    
    if (num_cadenas > 0) {
        printf("Porcentaje de cadenas válidas: %.2f%%\n\n", 
               (cadenas_validas * 100.0) / num_cadenas);
    }
    
    // ========== RESULTADO FINAL ==========
    printf("================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    if (cadenas_validas > 0) {
        printf("Cadenas que coinciden con la fecha %s:\n\n", fecha_hoy);
        
        for (i = 0; i < cadenas_validas; i++) {
            printf("%d. %s\n", i + 1, cadenas_filtradas[i]);
        }
    } else {
        printf("No hay cadenas que coincidan con la fecha de hoy (%s).\n", fecha_hoy);
    }
    
    printf("\n================================================\n\n");
    
    return 0;
}