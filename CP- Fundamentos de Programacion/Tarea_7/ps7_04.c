#include <stdio.h>
#include <string.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    char cad[30];               // cadena con fecha en formato dd/mm/aa
    char fecha_nueva[50];       // cadena con fecha en formato dd de mes de aaaa
    int dia, mes, anio;         // componentes de la fecha
    
    // Arreglo con nombres de meses
    char *meses[12] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };
    
    // ========== ENTRADA DE DATOS ==========
    printf("================================================\n");
    printf("    CONVERSION DE FORMATO DE FECHA (PS7.4)\n");
    printf("================================================\n\n");
    
    printf("Formato entrada: dd/mm/aa\n");
    printf("Formato salida:  dd de nombre_mes de aaaa\n\n");
    
    printf("Ejemplo: 06/08/05 -> 06 de Agosto de 2005\n\n");
    
    printf("Ingrese la fecha en formato dd/mm/aa: ");
    fgets(cad, 30, stdin);
    
    // ========== VALIDACION Y PROCESAMIENTO ==========
    // Eliminar el salto de línea si existe
    int longitud = strlen(cad);
    if (cad[longitud - 1] == '\n') {
        cad[longitud - 1] = '\0';
    }
    
    // ========== VERIFICACION DEL FORMATO ==========
    if (strlen(cad) != 8 || cad[2] != '/' || cad[5] != '/') {
        printf("\nError: El formato debe ser dd/mm/aa (ejemplo: 06/08/05)\n");
        return 1;
    }
    
    // ========== EXTRAER COMPONENTES DE LA FECHA ==========
    // Extraer día (primeros 2 caracteres)
    dia = (cad[0] - '0') * 10 + (cad[1] - '0');
    
    // Extraer mes (caracteres 3 y 4)
    mes = (cad[3] - '0') * 10 + (cad[4] - '0');
    
    // Extraer año (últimos 2 caracteres)
    anio = (cad[6] - '0') * 10 + (cad[7] - '0');
    
    // Convertir año de 2 dígitos a 4 dígitos
    // Si es menor a 50, asumimos 20xx, si no 19xx
    if (anio < 50) {
        anio = 2000 + anio;
    } else {
        anio = 1900 + anio;
    }
    
    // ========== VALIDACION DE FECHA ==========
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12) {
        printf("\nError: Fecha invalida.\n");
        printf("El dia debe estar entre 1 y 31\n");
        printf("El mes debe estar entre 1 y 12\n");
        return 1;
    }
    
    // ========== MOSTRAR DATOS EXTRAIDOS ==========
    printf("\n================================================\n");
    printf("DATOS EXTRAIDOS\n");
    printf("================================================\n\n");
    
    printf("Cadena ingresada: %s\n\n", cad);
    
    printf("Componentes extraidos:\n");
    printf("  Día:   %02d\n", dia);
    printf("  Mes:   %02d\n", mes);
    printf("  Año:   %02d -> %04d\n\n", (anio % 100), anio);
    
    printf("Nombre del mes: %s\n\n", meses[mes - 1]);
    
    // ========== CONSTRUIR NUEVA CADENA ==========
    printf("================================================\n");
    printf("CONSTRUCCION DE LA NUEVA CADENA\n");
    printf("================================================\n\n");
    
    // Construir la fecha en el nuevo formato
    sprintf(fecha_nueva, "%02d de %s de %04d", dia, meses[mes - 1], anio);
    
    printf("Cadena construida: %s\n\n", fecha_nueva);
    
    // ========== RESULTADO FINAL ==========
    printf("================================================\n");
    printf("RESULTADO FINAL\n");
    printf("================================================\n\n");
    
    printf("Formato original:    dd/mm/aa\n");
    printf("Fecha ingresada:     %s\n\n", cad);
    
    printf("Formato nuevo:       dd de nombre_mes de aaaa\n");
    printf("Fecha convertida:    %s\n\n", fecha_nueva);
    
    // ========== TABLA DE CONVERSION ==========
    printf("================================================\n");
    printf("TABLA DE CONVERSION\n");
    printf("================================================\n\n");
    
    printf("Elemento    | Formato Original | Formato Nuevo\n");
    printf("------------|------------------|-------------------\n");
    printf("Dia         | %02d              | %02d\n", dia, dia);
    printf("Mes         | %02d              | %s\n", mes, meses[mes - 1]);
    printf("Anio        | %02d              | %04d\n\n", (anio % 100), anio);
    
    // ========== CARACTERES DE LA CADENA ==========
    printf("================================================\n");
    printf("CARACTERES DE LA CADENA NUEVA\n");
    printf("================================================\n\n");
    
    printf("Posicion | Caracter\n");
    printf("---------|----------\n");
    
    for (int i = 0; i < strlen(fecha_nueva); i++) {
        printf("   %2d    |    %c\n", i + 1, fecha_nueva[i]);
    }
    
    // ========== ESTADISTICAS ==========
    printf("\n================================================\n");
    printf("ESTADISTICAS\n");
    printf("================================================\n\n");
    
    printf("Longitud cadena original: %lu caracteres\n", strlen(cad));
    printf("Longitud cadena nueva: %lu caracteres\n\n", strlen(fecha_nueva));
    
    printf("Cambio de formato completado exitosamente.\n\n");
    
    printf("================================================\n\n");
    
    return 0;
}