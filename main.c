#include <stdio.h>
#include <stdlib.h>
#include "inc/ArrayList.h"
#include "inc/funciones.h"
#include "ArrayList.c"
#include "funciones.c"

int main()
{
    ArrayList* clientes;
	clientes = al_newArrayList();
	ArrayList* ventas;
	ventas = al_newArrayList();

    cargarClientes(clientes);
    cargarVentas(ventas);

	char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Alta de cliente.\n");
        printf("2- Modificacion de cliente.\n");
        printf("3- Baja de cliente.\n");
        printf("4- Listar clientes.\n");
        printf("5- Importar clientes desde CSV.\n");
        printf("6- Realizar una venta.\n");
        //printf("7- Finalizar un servicio tecnico.\n");
        //printf("8- Exportar servicios tecnicos de un cliente.\n");
        //printf("9- Imprimir servicios tecnicos finalizados por producto.\n");
        printf("10- Salir.\n");

        scanf("%d",&opcion);

        int subOpcion=0;
        char subSeguir='s';
        switch(opcion)
        {
            case 1:
                agregarCliente(clientes);
                break;
            case 2:
                modificarCliente(clientes);
                break;
            case 3:
                eliminarCliente(clientes, ventas);
                break;
            case 4:
                mostrarClientes(clientes);
                break;
            case 5:
                importarClientes(clientes);
                break;
            case 6:
                realizarVenta(ventas);
                break;
            case 10:
                seguir = 'n';
                break;
            default:
                printf("    Error: Opcion invalida.\n");
                break;
        }
    }
    return 0;
}
