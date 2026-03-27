#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int clave;
    char nombre[50];
    int existencia;
    float precio;
} Producto;

// Prototipos
void ventas();
void reabastecimiento();
void nuevosProductos();
void imprimirInventario();

int main() {
    int opcion;
    do {
        printf("\n--- SISTEMA DE CONTROL DE INVENTARIO (Monterrey) ---\n");
        printf("1. Ventas\n2. Reabastecimiento\n3. Nuevos Productos\n4. Ver Inventario\n5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: ventas(); break;
            case 2: reabastecimiento(); break;
            case 3: nuevosProductos(); break;
            case 4: imprimirInventario(); break;
        }
    } while(opcion != 5);
    return 0;
}

// a) Modulo de Ventas
void ventas() {
    FILE *f = fopen("com.dat", "rb+");
    if (!f) return;
    int clave, cant;
    float total = 0;
    Producto p;

    printf("Ingrese clave del producto (0 para terminar): ");
    scanf("%d", &clave);
    while (clave != 0) {
        rewind(f);
        int encontrado = 0;
        while (fread(&p, sizeof(Producto), 1, f)) {
            if (p.clave == clave) {
                encontrado = 1;
                printf("Producto: %s | Precio: %.2f | Stock: %d\n", p.nombre, p.precio, p.existencia);
                printf("Cantidad a vender: ");
                scanf("%d", &cant);
                if (cant <= p.existencia) {
                    p.existencia -= cant;
                    total += (cant * p.precio);
                    fseek(f, -(long)sizeof(Producto), SEEK_CUR);
                    fwrite(&p, sizeof(Producto), 1, f);
                } else {
                    printf("Error: Existencia insuficiente.\n");
                }
                break;
            }
        }
        if (!encontrado) printf("Clave no encontrada.\n");
        printf("Siguiente clave (0 para terminar): ");
        scanf("%d", &clave);
    }
    printf("Total de la venta: $%.2f\n", total);
    fclose(f);
}

// b) Modulo de reabastecimiento
void reabastecimiento() {
    FILE *f = fopen("com.dat", "rb+");
    if (!f) return;
    int clave, cant;
    Producto p;

    printf("Reabastecimiento - Clave (0 para salir): ");
    scanf("%d", &clave);
    while (clave != 0) {
        rewind(f);
        while (fread(&p, sizeof(Producto), 1, f)) {
            if (p.clave == clave) {
                printf("Producto: %s | Cantidad actual: %d\n Cantidad a sumar: ", p.nombre, p.existencia);
                scanf("%d", &cant);
                p.existencia += cant;
                fseek(f, -(long)sizeof(Producto), SEEK_CUR);
                fwrite(&p, sizeof(Producto), 1, f);
                break;
            }
        }
        printf("Siguiente clave (0 para salir): ");
        scanf("%d", &clave);
    }
    fclose(f);
}

// c) Modulo de Nuevos Productos (Mantiene el orden mediante un archivo temporal)
void nuevosProductos() {
    FILE *fOld = fopen("com.dat", "rb");
    FILE *fNew = fopen("temp.dat", "wb");
    Producto nuevo, actual;
    int fin = 0;

    printf("--- Registro de Nuevos Productos ---\n");
    while (!fin) {
        printf("Nueva Clave (0 para terminar): ");
        scanf("%d", &nuevo.clave);
        if (nuevo.clave == 0) break;
        printf("Nombre: "); scanf("%s", nuevo.nombre);
        printf("Existencia: "); scanf("%d", &nuevo.existencia);
        printf("Precio: "); scanf("%f", &nuevo.precio);

        if (!fOld) { // Si el archivo original no existe
            fwrite(&nuevo, sizeof(Producto), 1, fNew);
        } else {
            rewind(fOld);
            int insertado = 0;
            while (fread(&actual, sizeof(Producto), 1, fOld)) {
                if (!insertado && nuevo.clave < actual.clave) {
                    fwrite(&nuevo, sizeof(Producto), 1, fNew);
                    insertado = 1;
                }
                fwrite(&actual, sizeof(Producto), 1, fNew);
            }
            if (!insertado) fwrite(&nuevo, sizeof(Producto), 1, fNew);
        }
        // Para permitir multiples inserciones ordenadas, cerramos y reabrimos
        fclose(fOld); fclose(fNew);
        remove("com.dat"); rename("temp.dat", "com.dat");
        fOld = fopen("com.dat", "rb"); fNew = fopen("temp.dat", "wb");
    }
    if (fOld) fclose(fOld);
    fclose(fNew);
    remove("temp.dat");
}

// d) Mdulo de Inventario
void imprimirInventario() {
    FILE *f = fopen("com.dat", "rb");
    if (!f) { printf("Archivo vacio.\n"); return; }
    Producto p;
    printf("\n%-10s %-20s %-12s %-10s\n", "CLAVE", "NOMBRE", "EXISTENCIA", "PRECIO");
    while (fread(&p, sizeof(Producto), 1, f)) {
        printf("%-10d %-20s %-12d %-10.2f\n", p.clave, p.nombre, p.existencia, p.precio);
    }
    fclose(f);
}