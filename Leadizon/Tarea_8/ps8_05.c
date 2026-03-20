#include <stdio.h>
#include <string.h>

// ========== DEFINICION DE ESTRUCTURAS ==========
typedef struct {
    int clave;                  // clave del producto
    char nombre[50];            // nombre del producto
    int existencia;             // existencia en inventario
} Producto;

// ========== FUNCIONES AUXILIARES ==========

// Función para buscar producto por clave
int buscarProducto(Producto tienda[], int num_productos, int clave) {
    for (int i = 0; i < num_productos; i++) {
        if (tienda[i].clave == clave) {
            return i;
        }
    }
    return -1;
}

// Función para mostrar información de un producto
void mostrarProducto(Producto producto) {
    printf("Clave: %d\n", producto.clave);
    printf("Nombre: %s\n", producto.nombre);
    printf("Existencia: %d unidades\n\n", producto.existencia);
}

// Función para registrar una compra
int registrarCompra(Producto tienda[], int num_productos, int clave, int cantidad) {
    int indice = buscarProducto(tienda, num_productos, clave);
    
    if (indice == -1) {
        printf("\n¡ERROR! Producto no encontrado.\n");
        return 0;
    }
    
    if (cantidad <= 0) {
        printf("\n¡ERROR! La cantidad debe ser positiva.\n");
        return 0;
    }
    
    int existencia_anterior = tienda[indice].existencia;
    tienda[indice].existencia += cantidad;
    
    printf("\n================================================\n");
    printf("COMPRA REGISTRADA\n");
    printf("================================================\n\n");
    
    printf("Producto: %s\n", tienda[indice].nombre);
    printf("Clave: %d\n", clave);
    printf("Cantidad comprada: %d unidades\n", cantidad);
    printf("Existencia anterior: %d unidades\n", existencia_anterior);
    printf("Existencia actual: %d unidades\n\n", tienda[indice].existencia);
    
    return 1;
}

// Función para registrar una venta
int registrarVenta(Producto tienda[], int num_productos, int clave, int cantidad) {
    int indice = buscarProducto(tienda, num_productos, clave);
    
    if (indice == -1) {
        printf("\n¡ERROR! Producto no encontrado.\n");
        return 0;
    }
    
    if (cantidad <= 0) {
        printf("\n¡ERROR! La cantidad debe ser positiva.\n");
        return 0;
    }
    
    if (tienda[indice].existencia < cantidad) {
        printf("\n================================================\n");
        printf("VENTA RECHAZADA\n");
        printf("================================================\n\n");
        
        printf("Producto: %s\n", tienda[indice].nombre);
        printf("Clave: %d\n", clave);
        printf("Cantidad solicitada: %d unidades\n", cantidad);
        printf("Existencia disponible: %d unidades\n", tienda[indice].existencia);
        printf("Falta: %d unidades\n\n", cantidad - tienda[indice].existencia);
        
        return 0;
    }
    
    int existencia_anterior = tienda[indice].existencia;
    tienda[indice].existencia -= cantidad;
    
    printf("\n================================================\n");
    printf("VENTA REGISTRADA\n");
    printf("================================================\n\n");
    
    printf("Producto: %s\n", tienda[indice].nombre);
    printf("Clave: %d\n", clave);
    printf("Cantidad vendida: %d unidades\n", cantidad);
    printf("Existencia anterior: %d unidades\n", existencia_anterior);
    printf("Existencia actual: %d unidades\n\n", tienda[indice].existencia);
    
    return 1;
}

// Función para mostrar inventario completo
void mostrarInventario(Producto tienda[], int num_productos) {
    printf("\n================================================\n");
    printf("INVENTARIO COMPLETO\n");
    printf("================================================\n\n");
    
    if (num_productos == 0) {
        printf("No hay productos registrados.\n\n");
        return;
    }
    
    printf("Clave | Nombre                            | Existencia\n");
    printf"------|-----------------------------------|----------\n");
    
    for (int i = 0; i < num_productos; i++) {
        printf(" %3d  | %-35s | %9d\n",
               tienda[i].clave,
               tienda[i].nombre,
               tienda[i].existencia);
    }
    
    printf("\n");
}

// Función para mostrar productos con bajo inventario
void mostrarBajoInventario(Producto tienda[], int num_productos, int limite) {
    printf("\n================================================\n");
    printf("PRODUCTOS CON BAJO INVENTARIO\n");
    printf("(Existencia <= %d unidades)\n", limite);
    printf("================================================\n\n");
    
    int encontrados = 0;
    printf("Clave | Nombre                            | Existencia\n");
    printf"------|-----------------------------------|----------\n");
    
    for (int i = 0; i < num_productos; i++) {
        if (tienda[i].existencia <= limite) {
            encontrados++;
            printf(" %3d  | %-35s | %9d\n",
                   tienda[i].clave,
                   tienda[i].nombre,
                   tienda[i].existencia);
        }
    }
    
    if (encontrados == 0) {
        printf("No hay productos con bajo inventario.\n");
    } else {
        printf("\nTotal de productos con bajo inventario: %d\n", encontrados);
    }
    
    printf("\n");
}

// ========== PROGRAMA PRINCIPAL ==========
int main() {
    // ========== DECLARACION DE VARIABLES ==========
    Producto tienda[100];       // arreglo de productos
    int num_productos = 0;      // número de productos
    char operacion;             // tipo de operación (C/V)
    int clave;                  // clave del producto
    int cantidad;               // cantidad
    int opcion;                 // opción del menú
    int indice;                 // índice de búsqueda
    
    // Variables para estadísticas
    int total_compras = 0;
    int total_ventas = 0;
    int total_cantidad_comprada = 0;
    int total_cantidad_vendida = 0;
    
    // ========== ENCABEZADO ==========
    printf("================================================\n");
    printf("SISTEMA DE INVENTARIO - TIENDA ELECTRONICA (PS8.5)\n");
    printf("================================================\n\n");
    
    // ========== REGISTRO INICIAL DE PRODUCTOS ==========
    printf("================================================\n");
    printf("REGISTRO INICIAL DE PRODUCTOS\n");
    printf("================================================\n\n");
    
    printf("Ingrese la informacion de los productos.\n");
    printf("Termine con clave 0.\n\n");
    
    while (num_productos < 100) {
        printf("Producto %d\n", num_productos + 1);
        printf("Clave del producto (0 para terminar): ");
        scanf("%d", &tienda[num_productos].clave);
        
        if (tienda[num_productos].clave == 0) {
            break;
        }
        
        // Limpiar buffer
        while (getchar() != '\n');
        
        printf("Nombre del producto: ");
        fgets(tienda[num_productos].nombre, 50, stdin);
        tienda[num_productos].nombre[strlen(tienda[num_productos].nombre) - 1] = '\0';
        
        printf("Existencia inicial: ");
        scanf("%d", &tienda[num_productos].existencia);
        
        printf("\n");
        
        num_productos++;
    }
    
    if (num_productos == 0) {
        printf("\nNo se registraron productos.\n");
        return 1;
    }
    
    printf("\n%d productos registrados.\n\n", num_productos);
    
    // ========== MOSTRAR INVENTARIO INICIAL ==========
    mostrarInventario(tienda, num_productos);
    
    // ========== MENU PRINCIPAL ==========
    while (1) {
        printf("================================================\n");
        printf("MENU PRINCIPAL\n");
        printf("================================================\n\n");
        
        printf("1. Registrar transaccion (Compra/Venta)\n");
        printf("2. Ver inventario completo\n");
        printf("3. Ver productos con bajo inventario\n");
        printf("4. Buscar producto\n");
        printf("5. Ver estadisticas\n");
        printf("6. Salir\n\n");
        
        printf("Seleccione opcion (1-6): ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: // Transacción
                printf("\n================================================\n");
                printf("REGISTRAR TRANSACCION\n");
                printf("================================================\n\n");
                
                printf("Tipo de operacion (C/V): ");
                scanf("%c", &operacion);
                
                // Limpiar buffer
                while (getchar() != '\n');
                
                printf("Clave del producto: ");
                scanf("%d", &clave);
                
                printf("Cantidad: ");
                scanf("%d", &cantidad);
                
                if (operacion == 'C' || operacion == 'c') {
                    if (registrarCompra(tienda, num_productos, clave, cantidad)) {
                        total_compras++;
                        total_cantidad_comprada += cantidad;
                    }
                } else if (operacion == 'V' || operacion == 'v') {
                    if (registrarVenta(tienda, num_productos, clave, cantidad)) {
                        total_ventas++;
                        total_cantidad_vendida += cantidad;
                    }
                } else {
                    printf("\n¡ERROR! Operacion invalida.\n");
                }
                
                break;
                
            case 2: // Ver inventario
                mostrarInventario(tienda, num_productos);
                break;
                
            case 3: // Bajo inventario
                printf("Ingrese el limite de existencia: ");
                int limite;
                scanf("%d", &limite);
                mostrarBajoInventario(tienda, num_productos, limite);
                break;
                
            case 4: // Buscar producto
                printf("\n================================================\n");
                printf("BUSCAR PRODUCTO\n");
                printf("================================================\n\n");
                
                printf("Ingrese la clave del producto: ");
                scanf("%d", &clave);
                
                indice = buscarProducto(tienda, num_productos, clave);
                
                if (indice == -1) {
                    printf("\n¡ERROR! Producto no encontrado.\n\n");
                } else {
                    printf("\n");
                    mostrarProducto(tienda[indice]);
                }
                
                break;
                
            case 5: // Estadísticas
                printf("\n================================================\n");
                printf("ESTADISTICAS\n");
                printf("================================================\n\n");
                
                printf("Total de productos: %d\n\n", num_productos);
                
                printf("Transacciones:\n");
                printf("  Total de compras: %d\n", total_compras);
                printf("  Total de ventas: %d\n\n", total_ventas);
                
                printf("Cantidades:\n");
                printf("  Total cantidad comprada: %d unidades\n", total_cantidad_comprada);
                printf("  Total cantidad vendida: %d unidades\n\n", total_cantidad_vendida);
                
                // Calcular inventario total
                int inventario_total = 0;
                for (int i = 0; i < num_productos; i++) {
                    inventario_total += tienda[i].existencia;
                }
                
                printf("Inventario:\n");
                printf("  Total de unidades en stock: %d\n\n", inventario_total);
                
                // Productos con mayor y menor existencia
                int max_existencia = tienda[0].existencia;
                int min_existencia = tienda[0].existencia;
                int indice_max = 0;
                int indice_min = 0;
                
                for (int i = 1; i < num_productos; i++) {
                    if (tienda[i].existencia > max_existencia) {
                        max_existencia = tienda[i].existencia;
                        indice_max = i;
                    }
                    if (tienda[i].existencia < min_existencia) {
                        min_existencia = tienda[i].existencia;
                        indice_min = i;
                    }
                }
                
                printf("Mayor existencia:\n");
                printf("  Producto: %s\n", tienda[indice_max].nombre);
                printf("  Unidades: %d\n\n", max_existencia);
                
                printf("Menor existencia:\n");
                printf("  Producto: %s\n", tienda[indice_min].nombre);
                printf("  Unidades: %d\n\n", min_existencia);
                
                break;
                
            case 6: // Salir
                printf("\n================================================\n");
                printf("RESUMEN FINAL\n");
                printf("================================================\n\n");
                
                printf("Total de productos: %d\n", num_productos);
                printf("Total de transacciones: %d\n", total_compras + total_ventas);
                printf("  - Compras: %d\n", total_compras);
                printf("  - Ventas: %d\n\n", total_ventas);
                
                int total_inventario = 0;
                for (int i = 0; i < num_productos; i++) {
                    total_inventario += tienda[i].existencia;
                }
                printf("Total de unidades en inventario: %d\n\n", total_inventario);
                
                printf("¡Gracias por usar el sistema!\n");
                printf("================================================\n\n");
                
                return 0;
                
            default:
                printf("\n¡Opcion invalida!\n\n");
        }
    }
    
    return 0;
}