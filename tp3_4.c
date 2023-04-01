#include <stdio.h>
#include <time.h> // permite usar la funcion time()
#include <stdlib.h> //permite usar la funcion rand() y malloc
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}typedef Cliente;


/*============================= FUNCIONES ===========================*/

void cargar(Cliente *cantClientes, int cant);
void mostrar(Cliente *cantClientes, int cant);
float costoTotalProducto(Producto *producto);

int main(int argc, char const *argv[])
{
    Cliente *cantClientes;
    int cant;

    srand(time(NULL)); // srand me genera una semilla a partir de time

    printf("Cantidad de clientes (5 o menos): ");
    scanf("%d",&cant);
    cantClientes =(Cliente *) malloc(sizeof(Cliente) * cant); // asigno dinamicamente cant espacios 
    cargar(cantClientes, cant);
    mostrar(cantClientes, cant);

    return 0;
}

/*----------------- DESARROLLO DE LAS FUNCIONES-----------------*/


// FUNCION CARGAR
void cargar(Cliente *cantClientes, int cant){
    puts("==================== CARGA ====================");
    char *Buff;
    Buff= (char *) malloc(100*sizeof(char));
    for (int i = 0; i < cant; i++)
    {
        printf("---- Cliente N[%d]: \n",i+1);

        cantClientes[i].ClienteID = i;

        fflush(stdin);
        printf("Nombre: ");
        gets(Buff);
        //(cantClientes + i)->NombreCliente = (char *)malloc(sizeof(char) * (strlen(Buff)+1));
        cantClientes[i].NombreCliente = (char *)malloc(sizeof(char) * (strlen(Buff)+1)); //NombreCliente es un puntero
        //strcpy(*(cantClientes + 1),Buff);
        strcpy(cantClientes[i].NombreCliente,Buff);

        cantClientes[i].CantidadProductosAPedir = 1 + rand() % 5;

        cantClientes[i].Productos = (Producto *)malloc(sizeof(Producto) * cantClientes[i].CantidadProductosAPedir); // Productos es un puntero

        for (int j = 0; j < cantClientes[i].CantidadProductosAPedir; j++)
        {
            cantClientes[i].Productos[j].ProductoID = j;
            cantClientes[i].Productos[j].Cantidad = 1 + rand() % 10;
            cantClientes[i].Productos[j].PrecioUnitario = 10 + rand() % 91;
            cantClientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
        }
    }
}


// FUNCION MOSTRAR
void mostrar(Cliente *cantClientes, int cant){
    printf("\n");
    puts("==================== MUESTRA ====================");
    for (int i = 0; i < cant; i++)
    {
        printf("---- Cliente N[%d]: \n",i+1);
        printf("ID cliente: %d \n",cantClientes[i].ClienteID);
        printf("Nombre: %s\n",cantClientes[i].NombreCliente);
        printf("Cantidad de productos: %d \n",cantClientes[i].CantidadProductosAPedir);

        puts("----Productos----");
        for (int j = 0; j < cantClientes[i].CantidadProductosAPedir; j++)
        {
            printf("Producto N[%d]\n",j+1);
            printf("Producto: %s\n",cantClientes[i].Productos[j].TipoProducto);
            printf("ID producto: %d \n",cantClientes[i].Productos[j].ProductoID);
            printf("Cantidad: %d \n",cantClientes[i].Productos[j].Cantidad);
            printf("Precio: $ %.2f \n",cantClientes[i].Productos[j].PrecioUnitario);
            printf("\tPrecio Total: $ %.2f\n",costoTotalProducto(&cantClientes[i].Productos[j]) ); //xq se pone el &??
            printf("\n");
        }
    }
}

// FUNCION QUE CALCULA EL COSTO TOTAL DE UN PRODUCTO
float costoTotalProducto(Producto *producto){
    return producto->Cantidad * producto->PrecioUnitario;
}