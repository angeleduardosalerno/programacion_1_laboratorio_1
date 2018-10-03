#include <stdio.h>
#include <stdlib.h>
#include "validacionesinput.h"
#include "juegos.h"
#include "cliente.h"
#define CANT_CLIENTES 100
#define CANT_JUEGOS 20
#define IMPORTE_JUEGOS 5000 //VALOR MAXIMO DE LOS JUEGOS INGRESADOS


int main()
{
    int respuesta, opciones, opcionesDosJuegos, auxSector, auxId;
    int contadorAltasJuegos =0, contadorJuego =0, auxIndexJuegos, index, contadorAltasClientes=0;
    char auxDescripcionJuego[51], auxApellidoCliente[51], auxNombreCliente[51], auxDomicilio[51], auxTelefono[21];
    int auxCodigoJuego;
    float auxSalary;
    int opcionesJuegos;
    float auxImporteJuego;
    int opcionesClientes, contadorClientes=0, auxCodigoCliente;

    Juegos arrayJuegos[CANT_JUEGOS];
    Clientes arrayClientes [CANT_CLIENTES];

    initJuegos(arrayJuegos , CANT_JUEGOS); // INICIALIZACION DE LA BANDERA EN EL ARRAY IS EMPTY, INDICANDO CON 1 QUE TODAS LAS POSICIONES ESTAN VACIAS.
    initClientes(arrayClientes , CANT_CLIENTES); // inicializar clientes

    do
    {
        system("cls");
        utn_getNumeroAvanzada(&opciones, "------MENU PRINCIPAL------\n 1. JUEGOS \n 2. CLIENTES  \n 3. ALQUILERES  \n 4. Salir. \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 4,3);

        switch (opciones)
        {
            case 1: // MENU JUEGOS

                do
                {
                    utn_getNumeroAvanzada(&opcionesJuegos, "------JUEGOS------\n 1. ALTAS \n 2. MODIFICAR  \n 3. BAJA  \n 4. LISTAR. \n 5. Salir.\n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);

                    switch (opcionesJuegos)
                    {

                        case 1:

                    do {
                        contadorJuego++; //GENERA EL CODIGO DE JUEGO AUTOINCREMENTAL
                        auxCodigoJuego=contadorJuego;

                        if (utn_getCadenaDeCaracteresAvanzada( auxDescripcionJuego, "\n Ingrese el nombre del juego: ", "El nombre ingresado no es valido, debe estar compuesto solo por letras....\n", 3 ) != 1)
                        break;

                        if (utn_getNumeroConDecimalesAvanzada(&auxImporteJuego, "\n Ingrese importe del juego: ", "El importe ingresado no es valido, debe ser numerico mayor a cero...\n ", 1 ,IMPORTE_JUEGOS, 3 ) != 1)
                        break;

                        addJuegos(arrayJuegos ,CANT_JUEGOS, auxCodigoJuego, auxDescripcionJuego, auxImporteJuego);

                        contadorAltasJuegos ++;

                        if (utn_getNumeroAvanzada(&respuesta, " \n DESEA CONTINUAR INGRESANDO DATOS: 1 (SI) -  2 (NO):", "No ingreso un dato valido, reintente por favor", 1, 2, 3) != 1)
                        break;

                        } while (respuesta != 2);

                        break;


                    case 2: // MENU MODIFICACION

                    if (contadorAltasJuegos > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                    {
                    utn_getNumeroAvanzada(& auxIndexJuegos, " \n Ingrese el ID del Juego que desea modificar: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                    index=findJuegoById (arrayJuegos, CANT_JUEGOS, auxIndexJuegos);

                    if (index==-1) // CHEQUEAR ESTA PARTE A VER SI ESTA OK PARA INDICAR QUE NO SE ENCONTRO EL ID INGRESADO...
                    {
                        printf("No se encuentra ese ID...\n");
                        break;
                    }

                    do
                    {
                        utn_getNumeroAvanzada(&opcionesDosJuegos, "\n 1. Modificar DESCRIPCION \n 2. Modificar IMPORTE \n 3. Salir. \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);

                        switch (opcionesDosJuegos)
                        {
                            case 1:

                                utn_getCadenaDeCaracteresAvanzada( arrayJuegos[index].descripcionJuego, "\n Ingrese NOMBRE O DESCRIPCION DEL JUEGO: ", "El nombre ingresado no es valido, debe estar compuesto solo por letras....\n", 3 );
                                printf( "\n *****El nombre o descripcion fue modificado con exito. ****\n \n ");
                                break;

                            case 2:

                                utn_getNumeroConDecimalesAvanzada(& arrayJuegos[index].importeJuego, "\n Ingrese nuevo importe: ", "El importe ingresado no es valido, debe estar compuesto solo por numeros....\n ", 1 , IMPORTE_JUEGOS, 3  );
                                printf( "\n *****El salario fue modificado con exito. ****\n \n ");
                                break;
                        }
                    } while (opcionesDosJuegos != 3);

                    break;
                }
                else
                {
                    printf("\n ****Primero debe dar de alta un JUEGO..****\n \n ");
                    break;
                }

            case 3: // MENU BAJAS JUEGOS

                if (contadorAltasJuegos > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                {
                    utn_getNumeroAvanzada(& auxIndexJuegos, " \n Ingrese el ID del JUEGO que desea dar de baja: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                    removeJuegos (arrayJuegos, CANT_JUEGOS, auxIndexJuegos);

                    printf( "\n *****El JUEGO fue removido con exito. ****\n \n ");

                    contadorAltasJuegos --;

                    break;
                }
                else
                {
                    printf("\n ****Primero debe dar de alta un JUEGO..****\n \n ");
                    break;
                }

            break;

            case 4: //MENU INFORMAR JUEGOS

                if (contadorAltasJuegos > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                {
                    sortJuegos(arrayJuegos, CANT_JUEGOS);

                    printJuegos (arrayJuegos, CANT_JUEGOS);

                     break;
                }
                else
                {
                    printf("\n ****Primero debe dar de alta un empleado..****\n \n ");
                    break;
                }


            }while (opcionesJuegos!= 5);

            break;
            }
        }while (opciones != 4);

    return 0;

}

//*********************TENGO QUE ARREGLAR EL CASE, ANDA HASTA LA PARTE DE ALTAS LLEGUE HASTA ACA....

            /*case 2 : //MENU CLIENTES ******************************************

                do
                {
                    utn_getNumeroAvanzada(&opcionesClientes, "------CLIENTES------\n 1. ALTAS \n 2. MODIFICAR  \n 3. BAJA  \n 4. LISTAR. \n 5. Salir.\n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);

                    switch (opcionesClientes)
                    {
                        case 1: //ALTA CLIENTES

                        contadorClientes++; //GENERA EL CODIGO DE JUEGO AUTOINCREMENTAL
                        auxCodigoCliente=contadorClientes;

                        if (utn_getCadenaDeCaracteresAvanzada( auxApellidoCliente, "\n Ingrese el nombre del cliente: ", "El nombre ingresado no es valido, debe estar compuesto solo por letras....\n", 3 ) != 1)
                        break;

                        if (utn_getCadenaDeCaracteresAvanzada( auxNombreCliente, "\n Ingrese el nombre del cliente: ", "El nombre ingresado no es valido, debe estar compuesto solo por letras....\n", 3 ) != 1)
                        break;

                        if (utn_getAlfanumericoAvanzada( auxDomicilio, "\n Ingrese la direccion del cliente: ", "La direccion ingresada no es valido....\n", 3 ) != 1)
                        break;

                        if (utn_getTelefonoAvanzada( auxTelefono, "\n Ingrese TELEFONO CELULAR del cliente (FORMATO VALIDO XX-XXXX-XXXX): ", "El telefono no es valido....\n", 3 ) != 1)
                        break;


                        addClientes (arrayClientes ,CANT_CLIENTES, auxCodigoCliente, auxApellidoCliente, auxNombreCliente, auxDomicilio, auxTelefono );

                        contadorAltasClientes ++;

                        if (utn_getNumeroAvanzada(&respuesta, " \n DESEA CONTINUAR INGRESANDO DATOS: 1 (SI) -  2 (NO):", "No ingreso un dato valido, reintente por favor", 1, 2, 3) != 1)
                        break;

                        } while (respuesta != 2);

                        break;


*/



