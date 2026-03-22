#include <stdio.h>

int main() {
    // ========== DECLARACION DE VARIABLES ==========
    int VEC[100];               // arreglo unidimensional
    int N;                      // número actual de elementos
    int opcion;                 // opción del menú
    int ELE;                    // elemento a insertar o eliminar
    int i, j;                   // contadores para bucles
    int encontrado;             // bandera para buscar elementos
    int posicion;               // posición donde se encuentra un elemento
    
    // ========== ENTRADA INICIAL DE DATOS ==========
    printf("================================================\n");
    printf("  INSERTAR Y ELIMINAR EN ARREGLO (PS5.4)\n");
    printf("================================================\n\n");
    
    printf("Ingrese la cantidad inicial de elementos (1-100): ");
    scanf("%d", &N);
    
    // ========== VALIDACION ==========
    if (N < 1 || N > 100) {
        printf("\nError: N debe estar entre 1 y 100.\n");
        return 1;
    }
    
    // ========== LECTURA DEL ARREGLO INICIAL ==========
    printf("\nIngrese los %d elementos del arreglo:\n", N);
    for (i = 0; i < N; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &VEC[i]);
    }
    
    // ========== MENU PRINCIPAL ==========
    while (1) {
        printf("\n================================================\n");
        printf("MENU PRINCIPAL\n");
        printf("================================================\n\n");
        
        printf("1. Mostrar arreglo actual\n");
        printf("2. Insertar elemento\n");
        printf("3. Eliminar elemento\n");
        printf("4. Salir\n\n");
        
        printf("Seleccione una opcion (1-4): ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                // ========== MOSTRAR ARREGLO ==========
                printf("\n================================================\n");
                printf("ARREGLO ACTUAL\n");
                printf("================================================\n\n");
                
                printf("Total de elementos: %d\n\n", N);
                printf("Indice |  Valor\n");
                printf("--------|--------\n");
                
                for (i = 0; i < N; i++) {
                    printf("  %2d   |  %5d\n", i + 1, VEC[i]);
                }
                printf("\n");
                break;
                
            case 2:
                // ========== INSERTAR ELEMENTO ==========
                printf("\n================================================\n");
                printf("INSERTAR ELEMENTO\n");
                printf("================================================\n\n");
                
                if (N >= 100) {
                    printf("Error: El arreglo esta lleno (100 elementos).\n");
                    break;
                }
                
                printf("Ingrese el elemento a insertar: ");
                scanf("%d", &ELE);
                
                // Verificar si el elemento ya existe
                encontrado = 0;
                for (i = 0; i < N; i++) {
                    if (VEC[i] == ELE) {
                        encontrado = 1;
                        break;
                    }
                }
                
                if (encontrado) {
                    printf("\nError: El elemento %d ya existe en el arreglo.\n", ELE);
                    printf("No se pueden insertar elementos repetidos.\n");
                } else {
                    // Insertar el elemento al final del arreglo
                    VEC[N] = ELE;
                    N++;
                    printf("\nElement %d insertado correctamente.\n", ELE);
                    printf("Nuevo tamano del arreglo: %d elementos\n", N);
                }
                break;
                
            case 3:
                // ========== ELIMINAR ELEMENTO ==========
                printf("\n================================================\n");
                printf("ELIMINAR ELEMENTO\n");
                printf("================================================\n\n");
                
                if (N == 0) {
                    printf("Error: El arreglo esta vacio.\n");
                    break;
                }
                
                printf("Ingrese el elemento a eliminar: ");
                scanf("%d", &ELE);
                
                // Buscar el elemento a eliminar
                encontrado = 0;
                posicion = -1;
                
                for (i = 0; i < N; i++) {
                    if (VEC[i] == ELE) {
                        encontrado = 1;
                        posicion = i;
                        break;
                    }
                }
                
                if (!encontrado) {
                    printf("\nError: El elemento %d no existe en el arreglo.\n", ELE);
                } else {
                    // Eliminar el elemento desplazando los siguientes
                    for (i = posicion; i < N - 1; i++) {
                        VEC[i] = VEC[i + 1];
                    }
                    N--;
                    printf("\nElemento %d eliminado correctamente.\n", ELE);
                    printf("Nuevo tamano del arreglo: %d elementos\n", N);
                }
                break;
                
            case 4:
                // ========== SALIR ==========
                printf("\n================================================\n");
                printf("Programa finalizado.\n");
                printf("================================================\n\n");
                return 0;
                
            default:
                printf("\nError: Opcion no valida. Intente nuevamente.\n");
        }
    }
    
    return 0;
}