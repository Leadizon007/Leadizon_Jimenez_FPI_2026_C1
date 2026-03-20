#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ========== DEFINICION DE ESTRUCTURAS ==========
typedef struct {
    char calle[50];             // calle y número
    char codigo_postal[10];     // código postal
    char colonia[50];           // colonia
    char ciudad[50];            // ciudad
} Domicilio;

typedef struct {
    long numero_cuenta;         // número de cuenta
    char nombre[50];            // nombre del cliente
    Domicilio domicilio;        // estructura de domicilio
    char telefono[15];          // teléfono
    double saldo;               // saldo en cuenta
} Cliente;

// ========== FUNCIONES AUXILIARES ==========

// Función para buscar cliente por número de cuenta
int buscarCliente(Cliente clientes[], int num_clientes, long numero_cuenta) {
    for (int i = 0; i < num_clientes; i++) {
        if (clientes[i].numero_cuenta == numero_cuenta) {
            return i;
        }
    }
    return -1;
}

// Función para mostrar información de un cliente
void mostrarCliente(Cliente cliente) {
    printf("\n================================================\n");
    printf("INFORMACION DEL CLIENTE\n");
    printf("================================================\n\n");
    
    printf("Numero de cuenta: %ld\n", cliente.numero_cuenta);
    printf("Nombre: %s\n", cliente.nombre);
    printf("Telefono: %s\n\n", cliente.telefono);
    
    printf("Domicilio:\n");
    printf("  Calle: %s\n", cliente.domicilio.calle);
    printf("  Colonia: %s\n", cliente.domicilio.colonia);
    printf("  Codigo Postal: %s\n", cliente.domicilio.codigo_postal);
    printf("  Ciudad: %s\n\n", cliente.domicilio.ciudad);
    
    printf("Saldo actual: $%.2f\n", cliente.saldo);
}

// Función para realizar depósito
int realizarDeposito(Cliente clientes[], int num_clientes, 
                      long numero_cuenta, double monto) {
    int indice = buscarCliente(clientes, num_clientes, numero_cuenta);
    
    if (indice == -1) {
        printf("\n¡ERROR! Cuenta no encontrada.\n");
        return 0;
    }
    
    if (monto <= 0) {
        printf("\n¡ERROR! El monto debe ser positivo.\n");
        return 0;
    }
    
    double saldo_anterior = clientes[indice].saldo;
    clientes[indice].saldo += monto;
    
    printf("\n================================================\n");
    printf("DEPOSITO REALIZADO\n");
    printf("================================================\n\n");
    
    printf("Numero de cuenta: %ld\n", numero_cuenta);
    printf("Nombre del cliente: %s\n", clientes[indice].nombre);
    printf("Monto depositado: $%.2f\n", monto);
    printf("Saldo anterior: $%.2f\n", saldo_anterior);
    printf("Saldo actual: $%.2f\n\n", clientes[indice].saldo);
    
    printf("¡Deposito realizado exitosamente!\n");
    
    return 1;
}

// Función para realizar retiro
int realizarRetiro(Cliente clientes[], int num_clientes, 
                   long numero_cuenta, double monto, char tipo[]) {
    int indice = buscarCliente(clientes, num_clientes, numero_cuenta);
    
    if (indice == -1) {
        printf("\n¡ERROR! Cuenta no encontrada.\n");
        return 0;
    }
    
    if (monto <= 0) {
        printf("\n¡ERROR! El monto debe ser positivo.\n");
        return 0;
    }
    
    if (clientes[indice].saldo < monto) {
        printf("\n================================================\n");
        printf("RETIRO RECHAZADO\n");
        printf("================================================\n\n");
        
        printf("Numero de cuenta: %ld\n", numero_cuenta);
        printf("Nombre del cliente: %s\n", clientes[indice].nombre);
        printf("Monto solicitado: $%.2f\n", monto);
        printf("Saldo disponible: $%.2f\n", clientes[indice].saldo);
        printf("Fondos insuficientes: $%.2f\n\n", monto - clientes[indice].saldo);
        
        printf("¡Retiro rechazado! Saldo insuficiente.\n");
        
        return 0;
    }
    
    double saldo_anterior = clientes[indice].saldo;
    clientes[indice].saldo -= monto;
    
    printf("\n================================================\n");
    printf("RETIRO REALIZADO\n");
    printf("================================================\n\n");
    
    printf("Tipo de retiro: %s\n", tipo);
    printf("Numero de cuenta: %ld\n", numero_cuenta);
    printf("Nombre del cliente: %s\n", clientes[indice].nombre);
    printf("Monto retirado: $%.2f\n", monto);
    printf("Saldo anterior: $%.2f\n", saldo_anterior);
    printf("Saldo actual: $%.2f\n\n", clientes[indice].saldo);
    
    printf("¡Retiro realizado exitosamente!\n");
    
    return 1;
}

// ========== PROGRAMA PRINCIPAL ==========
int main() {
    // ========== DECLARACION DE VARIABLES ==========
    Cliente clientes[100];      // arreglo de clientes
    int num_clientes = 0;       // número de clientes registrados
    long numero_cuenta;         // número de cuenta ingresado
    double monto;               // monto a depositar o retirar
    int opcion;                 // opción de menú
    int indice;                 // índice del cliente
    char tipo_retiro[20];       // tipo de retiro (cheque, cajero)
    int respuesta;              // respuesta del usuario
    
    // ========== ENCABEZADO ==========
    printf("================================================\n");
    printf("SISTEMA BANCARIO - DEPOSITOS Y RETIROS (PS8.1)\n");
    printf("================================================\n\n");
    
    printf("Banco ubicado en Quito, Ecuador\n\n");
    
    // ========== INGRESO INICIAL DE CLIENTES ==========
    printf("================================================\n");
    printf("REGISTRO INICIAL DE CLIENTES\n");
    printf("================================================\n\n");
    
    printf("Ingrese la informacion de los clientes.\n");
    printf("Termine con numero de cuenta 0.\n\n");
    
    while (num_clientes < 100) {
        printf("Cliente %d\n", num_clientes + 1);
        printf("Ingrese el numero de cuenta (0 para terminar): ");
        scanf("%ld", &numero_cuenta);
        
        if (numero_cuenta == 0) {
            break;
        }
        
        // Limpiar buffer
        while (getchar() != '\n');
        
        clientes[num_clientes].numero_cuenta = numero_cuenta;
        
        printf("Nombre: ");
        fgets(clientes[num_clientes].nombre, 50, stdin);
        clientes[num_clientes].nombre[strlen(clientes[num_clientes].nombre) - 1] = '\0';
        
        printf("Calle y numero: ");
        fgets(clientes[num_clientes].domicilio.calle, 50, stdin);
        clientes[num_clientes].domicilio.calle[strlen(clientes[num_clientes].domicilio.calle) - 1] = '\0';
        
        printf("Colonia: ");
        fgets(clientes[num_clientes].domicilio.colonia, 50, stdin);
        clientes[num_clientes].domicilio.colonia[strlen(clientes[num_clientes].domicilio.colonia) - 1] = '\0';
        
        printf("Codigo postal: ");
        fgets(clientes[num_clientes].domicilio.codigo_postal, 10, stdin);
        clientes[num_clientes].domicilio.codigo_postal[strlen(clientes[num_clientes].domicilio.codigo_postal) - 1] = '\0';
        
        printf("Ciudad: ");
        fgets(clientes[num_clientes].domicilio.ciudad, 50, stdin);
        clientes[num_clientes].domicilio.ciudad[strlen(clientes[num_clientes].domicilio.ciudad) - 1] = '\0';
        
        printf("Telefono: ");
        fgets(clientes[num_clientes].telefono, 15, stdin);
        clientes[num_clientes].telefono[strlen(clientes[num_clientes].telefono) - 1] = '\0';
        
        printf("Saldo inicial: $");
        scanf("%lf", &clientes[num_clientes].saldo);
        
        printf("\n");
        
        num_clientes++;
    }
    
    // Limpiar buffer después del último scanf
    while (getchar() != '\n');
    
    if (num_clientes == 0) {
        printf("\nNo se registraron clientes.\n");
        return 1;
    }
    
    // ========== MOSTRAR CLIENTES REGISTRADOS ==========
    printf("\n================================================\n");
    printf("CLIENTES REGISTRADOS\n");
    printf("================================================\n\n");
    
    printf("Num | Cuenta      | Nombre                | Saldo\n");
    printf"----|-------------|--------------------|-----------\n");
    
    for (int i = 0; i < num_clientes; i++) {
        printf(" %d  | %11ld | %-21s | $%9.2f\n", 
               i + 1, clientes[i].numero_cuenta, clientes[i].nombre, clientes[i].saldo);
    }
    
    // ========== MENU DE TRANSACCIONES ==========
    printf("\n\n================================================\n");
    printf("MENU DE TRANSACCIONES\n");
    printf("================================================\n\n");
    
    while (1) {
        printf("Ingrese el numero de cuenta para transaccion (0 para terminar): ");
        scanf("%ld", &numero_cuenta);
        
        if (numero_cuenta == 0) {
            printf("\nFin del proceso de transacciones.\n");
            break;
        }
        
        // Buscar cliente
        indice = buscarCliente(clientes, num_clientes, numero_cuenta);
        
        if (indice == -1) {
            printf("\n¡ERROR! La cuenta %ld no existe.\n\n", numero_cuenta);
            continue;
        }
        
        // Mostrar cliente
        mostrarCliente(clientes[indice]);
        
        // Menu de operación
        printf("\n================================================\n");
        printf("TIPO DE OPERACION\n");
        printf("================================================\n\n");
        
        printf("1. Deposito\n");
        printf("2. Retiro (Cajero)\n");
        printf("3. Retiro (Cheque)\n");
        printf("4. Cancelar transaccion\n\n");
        
        printf("Seleccione la operacion (1-4): ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: // Depósito
                printf("\nIngrese el monto a depositar: $");
                scanf("%lf", &monto);
                realizarDeposito(clientes, num_clientes, numero_cuenta, monto);
                break;
                
            case 2: // Retiro por cajero
                printf("\nIngrese el monto a retirar: $");
                scanf("%lf", &monto);
                strcpy(tipo_retiro, "Retiro de Cajero");
                realizarRetiro(clientes, num_clientes, numero_cuenta, monto, tipo_retiro);
                break;
                
            case 3: // Retiro por cheque
                printf("\nIngrese el monto del cheque: $");
                scanf("%lf", &monto);
                strcpy(tipo_retiro, "Cheque");
                realizarRetiro(clientes, num_clientes, numero_cuenta, monto, tipo_retiro);
                break;
                
            case 4:
                printf("\nTransaccion cancelada.\n");
                break;
                
            default:
                printf("\nOpcion invalida.\n");
        }
        
        printf("\n");
    }
    
    // ========== REPORTE FINAL ==========
    printf("\n================================================\n");
    printf("REPORTE FINAL DE SALDOS\n");
    printf("================================================\n\n");
    
    printf("Num | Cuenta      | Nombre                | Saldo\n");
    printf("----|-------------|--------------------|-----------\n");
    
    double suma_saldos = 0;
    for (int i = 0; i < num_clientes; i++) {
        printf(" %d  | %11ld | %-21s | $%9.2f\n", 
               i + 1, clientes[i].numero_cuenta, clientes[i].nombre, clientes[i].saldo);
        suma_saldos += clientes[i].saldo;
    }
    
    printf("----|-------------|--------------------|-----------\n");
    printf("    |             | TOTAL               | $%9.2f\n\n", suma_saldos);
    
    printf("================================================\n\n");
    
    return 0;
}