#include <stdio.h>
#include <stdlib.h>
#include "validacionesinput.h"
#include "juegos.h"
#include "cliente.h"
#define CANT_CLIENTES 100 // CANTIDAD DE CLIENTES
#define CANT_JUEGOS 20 // CANTIDAD DE JUEGOS
#define CANT_ALQUILERES (CANT_CLIENTES * CANT_JUEGOS) // CANTIDAD DE ALQUILERES POSIBLES
#define IMPORTE_JUEGOS 10000 //VALOR MAXIMO DE LOS JUEGOS INGRESADOS



int main()
{
    int respuesta, opciones, opcionesDosJuegos, auxCodigoJuego, opcionesJuegos;
    int contadorAltasJuegos =0, contadorJuego =0, auxIndexJuegos, index, contadorAltasClientes=0;
    char auxDescripcionJuego[51], auxApellidoCliente[51], auxNombreCliente[51], auxDomicilio[51], auxTelefono[21];
    int opcionesClientes, contadorClientes=0, auxCodigoCliente, opcionesDosClientes, auxIndexClientes, verificarIdJuegos, verificarIdClientes;
    int opcionesAlquileres, contadorAlquileres=0, auxCodigoJuegoAlquileres, auxCodigoClienteAlquileres, auxDiaFecha, auxMesFecha, auxAnioFecha;
    int opcionesInformes, i, j;
    float auxImporteJuego;

    Juegos arrayJuegos[CANT_JUEGOS];
    Clientes arrayClientes [CANT_CLIENTES];
    Alquileres arrayAlquileres [CANT_ALQUILERES];



//*********************************************INICIO DEL PROGRAMA********************************************************************************************************************************

    initJuegos(arrayJuegos , CANT_JUEGOS); // INICIALIZACION DE LOS 3 ARRAYS UTILIZADOS.
    initClientes(arrayClientes , CANT_CLIENTES);
    initAlquileres (arrayAlquileres , CANT_ALQUILERES);

    do
    {
        system("cls");
        utn_getNumeroAvanzada(&opciones, "\n ------MENU PRINCIPAL------\n\n 1. JUEGOS \n 2. CLIENTES  \n 3. ALQUILERES \n 4. INFORMES \n 5. Salir. \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);

        switch (opciones)
        {
            case 1: // MENU PRINCIPAL: JUEGOS-----

                do
                {
                    utn_getNumeroAvanzada(&opcionesJuegos, "\n\n------JUEGOS------\n\n 1. ALTAS \n 2. MODIFICAR  \n 3. BAJA  \n 4. LISTAR. \n 5. Salir.\n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);

                    switch (opcionesJuegos)
                    {
 //****************************************************************************************************************************************************************************************************
                        case 1: // ALTAS JUEGOS

                        do
                        {
                            contadorJuego++; //GENERA EL CODIGO DE JUEGO AUTOINCREMENTAL
                            auxCodigoJuego=contadorJuego;

                            if (utn_getCadenaDeCaracteresAvanzada(auxDescripcionJuego, "\n Ingrese el nombre del juego: ", "El nombre ingresado no es valido, debe estar compuesto solo por letras....\n", 3 ) != 1)
                            break;

                            if (utn_getNumeroConDecimalesAvanzada(&auxImporteJuego, "\n Ingrese importe del juego: ", "El importe ingresado no es valido, debe ser numerico, mayor a cero...\n ", 1 ,IMPORTE_JUEGOS, 3 ) != 1)
                            break;

                            addJuegos(arrayJuegos ,CANT_JUEGOS, auxCodigoJuego, auxDescripcionJuego, auxImporteJuego);

                            contadorAltasJuegos ++;

                            if (utn_getNumeroAvanzada(&respuesta, " \n DESEA CONTINUAR INGRESANDO DATOS: 1 (SI) -  2 (NO):", "No ingreso un dato valido, reintente por favor", 1, 2, 3) != 1)
                            break;

                        }  while (respuesta != 2);

                        break; // BREAK CASE 1 ALTAS JUEGOS

                        case 2: // MODIFICACION JUEGOS

                            if (contadorAltasJuegos > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                            {
                                utn_getNumeroAvanzada(& auxIndexJuegos, " \n Ingrese el ID del Juego que desea modificar: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                                index=findJuegoById (arrayJuegos, CANT_JUEGOS, auxIndexJuegos);

                                if (index==-1)
                                {
                                    printf("\n ****NO SE ENCUENTRA ESE ID..****\n \n ");
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
                                        printf( "\n *****El importe fue modificado con exito. ****\n \n ");
                                        break;
                                    }
                                } while (opcionesDosJuegos != 3); // JUEGOS CASE 2

                            }
                            else
                            {
                                printf("\n ****Primero debe dar de alta un JUEGO..****\n \n ");
                                break;
                            }

                        break; // BREAK CASE 2 ALTAS JUEGOS


                        case 3: // MENU BAJAS JUEGOS

                            if (contadorAltasJuegos > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                            {
                                utn_getNumeroAvanzada(& auxIndexJuegos, " \n Ingrese el ID del JUEGO que desea dar de baja: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                                verificarIdJuegos= removeJuegos (arrayJuegos, CANT_JUEGOS, auxIndexJuegos);

                                if (verificarIdJuegos==0)
                                {
                                    printf( "\n *****El JUEGO fue removido con exito. ****\n \n ");
                                    contadorAltasJuegos --;
                                }
                                else
                                {
                                    printf("\n ****NO SE ENCUENTRA ESE ID..****\n \n");
                                    break;
                                }

                            }
                            else
                            {
                                printf("\n ****Primero debe dar de alta un JUEGO..****\n \n ");
                                break;
                            }

                        break; // BREAK CASE 3 BAJA JUEGOS


                        case 4: //MENU INFORMAR JUEGOS

                            if (contadorAltasJuegos > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                            {
                                sortJuegos(arrayJuegos, CANT_JUEGOS);

                                printJuegos (arrayJuegos, CANT_JUEGOS);
                            }
                            else
                            {
                                printf("\n ****Primero debe dar de alta un JUEGO..****\n \n ");
                            }

                        break; // BREAK CASE 4 JUEGOS

                    } // FIN SWITCH OPCIONES JUEGOS

                  }while (opcionesJuegos!= 5); // WHILE OPCIONES MENU JUEGOS

            break; // BREAK CASE 1 MENU PRINCIPAL


//******************************************************************************************************************************************************************************************************

            case 2: // MENU PRINCIPAL: CLIENTES--------

                do
                {
                    utn_getNumeroAvanzada(&opcionesClientes, "\n \n------CLIENTES------\n\n 1. ALTAS \n 2. MODIFICAR  \n 3. BAJA  \n 4. LISTAR. \n 5. Salir.\n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);

                    switch (opcionesClientes)
                    {
                        case 1: //ALTA CLIENTES

                            do
                            {
                                contadorClientes++; //GENERA EL CODIGO DE JUEGO AUTOINCREMENTAL
                                auxCodigoCliente=contadorClientes;

                                if (utn_getCadenaDeCaracteresAvanzada( auxApellidoCliente, "\n Ingrese el apellido del cliente: ", "El apellido ingresado no es valido, debe estar compuesto solo por letras....\n", 3 ) != 1)
                                break;

                                if (utn_getCadenaDeCaracteresAvanzada( auxNombreCliente, "\n Ingrese el nombre del cliente: ", "El nombre ingresado no es valido, debe estar compuesto solo por letras....\n", 3 ) != 1)
                                break;

                                if (utn_getAlfanumericoAvanzada( auxDomicilio, "\n Ingrese el domicilio del cliente: ", "\nLa direccion ingresada no es valida (debe contener al menos una letra, un espacio y un numero)....\n", 3 ) != 1)
                                break;

                                if (utn_getTelefonoAvanzada( auxTelefono, "\n Ingrese TELEFONO CELULAR del cliente (FORMATO VALIDO XX-XXXX-XXXX):\n ", "El telefono no es valido....\n", 3 ) != 1)
                                break;


                                addClientes (arrayClientes ,CANT_CLIENTES, auxCodigoCliente, auxApellidoCliente, auxNombreCliente, auxDomicilio, auxTelefono );

                                contadorAltasClientes ++;

                                if (utn_getNumeroAvanzada(&respuesta, " \n DESEA CONTINUAR INGRESANDO DATOS: 1 (SI) -  2 (NO):", "No ingreso un dato valido, reintente por favor", 1, 2, 3) != 1)
                                break;

                            } while (respuesta != 2);


                        break; // BREAK ALTA CLIENTES

                        case 2: // MENU MODIFICACION CLIENTES

                            if (contadorAltasClientes > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                            {
                                utn_getNumeroAvanzada(& auxIndexClientes, " \n Ingrese el ID del Cliente que desea modificar: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                                index=findClienteById (arrayClientes, CANT_CLIENTES, auxIndexClientes);

                                if (index==-1)
                                {
                                    printf("No se encuentra ese ID...\n");
                                    break;
                                }

                                do
                                {
                                    utn_getNumeroAvanzada(&opcionesDosClientes, "\n 1. Modificar APELLIDO \n 2. Modificar NOMBRE \n 3. Modificar DOMICILIO \n 4. Modificar TELEFONO  \n 5. Salir. \n \n Seleccione una opcion: ",
                                                                                " \n Seleccione una opcion valida.", 1, 5,3);

                                    switch (opcionesDosClientes)
                                    {
                                        case 1:

                                        utn_getCadenaDeCaracteresAvanzada( arrayClientes[index].apellido, "\n Ingrese el apellido del cliente: ", "El apellido ingresado no es valido, debe estar compuesto solo por letras....\n", 3 );
                                        printf( "\n *****El apellido fue modificado con exito. ****\n \n ");
                                        break;

                                        case 2:

                                        utn_getCadenaDeCaracteresAvanzada( arrayClientes[index].nombre, "\n Ingrese el nombre del cliente: ", "El nombre ingresado no es valido, debe estar compuesto solo por letras....\n", 3 );
                                        printf( "\n *****El nombre fue modificado con exito. ****\n \n ");
                                        break;

                                        case 3:

                                        utn_getAlfanumericoAvanzada( arrayClientes[index].domicilio, "\n Ingrese el domicilio del cliente: ", "\nEl domicilio ingresado no es valido (debe contener al menos una letra, un espacio y un numero)....\n", 3 );
                                        printf( "\n *****El domicilio fue modificado con exito. ****\n \n ");
                                        break;

                                        case 4:

                                        utn_getTelefonoAvanzada( arrayClientes[index].telefono, "\n Ingrese TELEFONO CELULAR del cliente (FORMATO VALIDO XX-XXXX-XXXX):\n ", "El telefono no es valido....\n", 3 );
                                        printf( "\n *****El telefono fue modificado con exito. ****\n \n ");
                                        break;
                                    }

                                } while (opcionesDosClientes != 5);

                            }
                            else
                            {
                                printf("\n ****Primero debe dar de alta un CLIENTE..****\n \n ");
                            }

                        break; // BREAK CASE 2 MODIFICACION CLIENTES

                        case 3: //BAJA DE CLIENTES

                            if (contadorAltasClientes > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                            {
                                utn_getNumeroAvanzada(& auxIndexClientes, " \n Ingrese el ID del CLIENTE que desea dar de baja: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                                verificarIdClientes =removeClientes (arrayClientes, CANT_CLIENTES, auxIndexClientes);

                                if (verificarIdClientes==0)
                                {
                                    printf( "\n *****El CLIENTE fue removido con exito. ****\n \n ");

                                    contadorAltasClientes --;
                                }
                                else
                                {
                                     printf("\n ****NO SE ENCUENTRA ESE ID..****\n \n");
                                    break;
                                }
                            }
                            else
                            {
                                printf("\n ****Primero debe dar de alta un CLIENTE..****\n \n ");
                            }

                        break; //BREAK CASE 3 BAJA DE CLIENTES


                        case 4: // INFORMAR CLIENTES

                            if (contadorAltasClientes > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                            {
                                sortClientes(arrayClientes, CANT_CLIENTES);

                                printClientes (arrayClientes, CANT_CLIENTES);
                            }
                            else
                            {
                                printf("\n ****Primero debe dar de alta un cliente..****\n \n ");
                            }


                        break; //CASE 4 CLIENTES BREAK...


                    } //FIN SWITCH OPCIONES CLIENTES...

                }while (opcionesClientes != 5);


            break; // BREAK CASE 2 MENU PRINCIPAL CLIENTES

//*****************************************************************************************************************************************************************************************************

            case 3: // MENU PRINCIPAL: ALQUILERES-----

                do
                {
                    utn_getNumeroAvanzada(&opcionesAlquileres, "\n\n------ALQUILERES------\n\n 1. ALTAS  \n 2. Salir.\n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 2,3);

                    switch (opcionesAlquileres)
                    {
                        case 1: // ALTAS ALQUILERES

                        do
                        {
                            contadorAlquileres ++; //GENERA EL CODIGO DE ALQUILER AUTOINCREMENTAL

                            if (utn_getNumeroAvanzadaSinMax(& auxCodigoJuegoAlquileres, "\n Ingrese el codigo del juego: ", "El codigo ingresado no es valido, debe estar dentro del rango valido y compuesto solo por numeros....\n",1, 3 ) != 1)
                            break; // HAY QUE VOLVER A HACER EL CONTADOR CUANDO LO PASE A FUNCIONES..IGUAL EL DE ABAJO

                            if (checkCodigoJuegos(arrayJuegos, CANT_JUEGOS,auxCodigoJuegoAlquileres)!=0) // BUSCA SI EXISTE EN JUEGOS EL CODIGO A BUSCAR.
                            {
                                printf("\n ****NO EXISTE ESE CODIGO DE JUEGO, POR FAVOR INTENTE NUEVAMENTE O INGRESE UN JUEGO..****\n \n ");
                                break;
                            }

                            if (utn_getNumeroAvanzadaSinMax(& auxCodigoClienteAlquileres, "\n Ingrese el codigo del cliente: ", "El codigo ingresado no es valido, debe estar entro del rango valido y compuesto solo por numeros....\n",1, 3 ) != 1)
                            break;

                            if (checkCodigoClientes(arrayClientes, CANT_CLIENTES,auxCodigoClienteAlquileres)!=0) // BUSCA SI EXISTE EN CLIENTES EL CODIGO A BUSCAR.
                            {
                                printf("\n ****NO EXISTE ESE CODIGO DE CLIENTE, POR FAVOR INTENTE NUEVAMENTE O INGRESE UN CLIENTE..****\n \n ");
                                break;
                            }

                            if (utn_getNumeroAvanzada(& auxDiaFecha, "\n Ingrese el dia del alquiler: ", "El dia ingresado no es valido, debe estar compuesto solo por numeros (hasta 31 dias)....\n",1, 31,3 ) != 1)
                            break;

                            if (utn_getNumeroAvanzada(& auxMesFecha, "\n Ingrese el mes del alquiler: ", "El mes ingresado no es valido, debe estar compuesto solo por numeros (hasta 12 meses)....\n",1,12, 3 ) != 1)
                            break;

                            if (utn_getNumeroAvanzada(& auxAnioFecha, "\n Ingrese el anio del alquiler: ", "El anio ingresado no es valido, debe estar compuesto solo por numeros y dentro del rango valido....\n", 2000, 2200, 3 ) != 1)
                            break;

                            addAlquileres (arrayAlquileres ,CANT_ALQUILERES, contadorAlquileres, auxCodigoJuegoAlquileres, auxCodigoClienteAlquileres,auxDiaFecha, auxMesFecha, auxAnioFecha);

                            if (utn_getNumeroAvanzada(&respuesta, " \n DESEA CONTINUAR INGRESANDO DATOS: 1 (SI) -  2 (NO):", "No ingreso un dato valido, reintente por favor", 1, 2, 3) != 1)
                            break;

                        } while (respuesta != 2);
                    }

                }while(opcionesAlquileres!=2);


            break; // BREAK CASE 3 MENU PRINCIPAL ALQUILERES

//*****************************************************************************************************************************************************************************************************

            case 4: //***************MENU INFORMES***********************************************************

                if (contadorAltasClientes > 0 && contadorAltasJuegos > 0) // PARA INGRESAR UNICAMENTE SI HAY POR LO MENOS UN ALTA DE CLIENTE  JUEGO
                {
                    utn_getNumeroAvanzada(& opcionesInformes,
                    "\n ------MENU INFORMES------\n\n 1.PROMEDIO Y TOTAL DE LOS IMPORTES DE LOS JUEGOS ALQUILADOS  \n 2. CANTIDAD DE JUEGOS CUYO IMPORTE NO SUPERA AL PROMEDIO \n 3. CLIENTES QUE ALQUILARON UN DETERMINADO JUEGO \n 4. TODOS LOS JUEGOS QUE FUERON ALQUILADOS POR UN CLIENTE \n 5.JUEGOS MENOS ALQUILADOS \n 6. CLIENTES CON MAS ALQUILERES\n 7. JUEGOS ALQUILADOS EN DETERMINADA FECHA \n 8. JUEGOS ORDENADOS POR IMPORTE DESCENDENTE\n 9. ORDENADOS POR APELLIDO \n. \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 10,3);
//OJO MODIFICAR EL MAXIMO DE GET NUMERO DE ACUERDO A LAS OPCIONES,,,
                    switch (opcionesInformes)
                    {
                        case 1: //CASO 1 INFORMES

                            printPromedioImporteTotales(arrayJuegos, CANT_JUEGOS);
                            system ("pause");
                        break; // BREAK CASO 1 INFORMES

                        case 2: //CASO 2 INFORMES

                            printPromediosMin(arrayJuegos, CANT_JUEGOS);
                            system ("pause");
                        break;// BREAK CASO 2 INFORMES

                        case 3: //CASO 3 INFORMES

                            utn_getNumeroAvanzada(& auxIndexJuegos, " \n Ingrese el ID del JUEGO AL CUAL INFORMAR: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                            verificarIdJuegos=checkCodigoJuegos(arrayJuegos, CANT_JUEGOS, auxIndexJuegos);

                            if (verificarIdJuegos ==-1)
                            {
                                printf( " ******NO SE ESCUENTRA ESE ID DE JUEGO****");
                                system ("pause");
                                break;
                            }

                            for (i=0; i< CANT_JUEGOS ; i++)
                            {
                                if (arrayJuegos[i].isEmpty==0)
                                {
                                    if (arrayJuegos[i].codigoJuego == auxIndexJuegos)
                                    {
                                        for(j=0; j<CANT_ALQUILERES; j++)
                                        {
                                            if (arrayAlquileres[j].isEmpty==0)
                                            {
                                                if (arrayAlquileres[j].codigoJuegoAlquileres == auxIndexJuegos)
                                                {
                                                    printf("\n APELLIDO:%s\n NOMBRE:%s \n DOMICILIO:%s \n TELEFONO:%s"
                                                    , arrayClientes[j].apellido, arrayClientes[j].nombre, arrayClientes[j].domicilio, arrayClientes[j].telefono);

                                                }
                                            }

                                        }
                                    }
                                }
                            }

                        system ("pause");
                        break;// BREAK CASO 3 INFORMES

                        case 4: //INICIO CASE 4

                            utn_getNumeroAvanzada(& auxIndexClientes, " \n Ingrese el ID del CLIENTE A INFORMAR: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                            verificarIdClientes=checkCodigoJuegos(arrayJuegos, CANT_CLIENTES, auxIndexClientes);

                            if (verificarIdJuegos ==-1)
                            {
                                printf( " ******NO SE ESCUENTRA ESE ID DE JUEGO****");
                                system ("pause");
                                break;
                            }

                            for (i=0; i< CANT_CLIENTES; i++)
                            {
                                if (arrayClientes[i].isEmpty==0)
                                {
                                    if (arrayClientes[i].codigoCliente == auxIndexClientes)
                                    {
                                        for(j=0; j<CANT_ALQUILERES; j++)
                                        {
                                            if (arrayAlquileres[j].isEmpty==0)
                                            {
                                                if (arrayAlquileres[j].codigoClienteAlquileres == auxIndexClientes)
                                                {
                                                    printf("\n DESCRIPCION DEL JUEGO:%s\n IMPORTE DEL JUEGO %f "
                                                    , arrayJuegos[j].descripcionJuego, arrayJuegos[j].importeJuego);

                                                }
                                            }

                                        }
                                    }
                                }
                            }

                        system ("pause");

                        break;// BREAK CASO 4 INFORMES

                        case 5: // JUEGOS MENOS ALQUILADOS

                            /*for(j=0; j<CANT_ALQUILERES; j++)
                            {
                                if (arrayAlquileres[j].isEmpty==0)
                                {
                                    for (i=0; i< CANT_JUEGOS ; i++)
                                    {
                                        if (arrayJuegos[i].isEmpty==0)
                                        {
                                            if (arrayAlquileres[j].codigoAlquileres == arrayJuegos[i].codigoJuego)
                                            {
                                                contadorAlquileres[j]

                                            }

                                        }
                                    }

                                }
                            }
                            printf( "\n CODIGO DE JUEGO:%d   -   DESCRIPCION: %d",  );*/


                        break; // CASO 5 INFORMES

                        case 6:
                        break;

                        case 7:

                            if (utn_getNumeroAvanzada(& auxDiaFecha, "\n Ingrese el dia del alquiler: ", "El dia ingresado no es valido, debe estar compuesto solo por numeros (hasta 31 dias)....\n",1, 31,3 ) != 1)
                            break;

                            if (utn_getNumeroAvanzada(& auxMesFecha, "\n Ingrese el mes del alquiler: ", "El mes ingresado no es valido, debe estar compuesto solo por numeros (hasta 12 meses)....\n",1,12, 3 ) != 1)
                            break;

                            if (utn_getNumeroAvanzada(& auxAnioFecha, "\n Ingrese el anio del alquiler: ", "El anio ingresado no es valido, debe estar compuesto solo por numeros y dentro del rango valido....\n", 2000, 2200, 3 ) != 1)
                            break;

                            for(j=0; j<CANT_ALQUILERES; j++)
                            {
                                if (arrayAlquileres[j].isEmpty==0)
                                {
                                    for (i=0; i< CANT_JUEGOS ; i++)
                                    {
                                        if (arrayJuegos[i].isEmpty==0)
                                        {
                                            if ((arrayAlquileres[j].fecha.dia == auxDiaFecha) && (arrayAlquileres[j].fecha.mes == auxMesFecha) && (arrayAlquileres[j].fecha.anio == auxAnioFecha))
                                            {
                                                printf("\n JUEGOS ALQUILADOS EN DETERMINADA FECHA: %s\t \%d \t \n", arrayJuegos[i].descripcionJuego, arrayJuegos[i].codigoJuego);
                                            }
                                        }
                                    }
                                }
                            }


                        system ("pause");

                        break; //FIN CASO 7...

                        case 8: //JUEGOS ORDENADOS DESCENDENTE

                            sortJuegosMasEficiente(arrayJuegos, CANT_JUEGOS);
                            printJuegos(arrayJuegos, CANT_JUEGOS);

                            system ("pause");
                        break; //fin case 8...

                        case 9:

                            sortClientesPorInsersion(arrayClientes, CANT_CLIENTES);
                            printClientes(arrayClientes, CANT_CLIENTES);

                            system ("pause");


                        system ("pause");
                        break; //break case 9



                    } // FIN SWITCH INFORMES...
                }
                else
                {
                    printf("\n ****Primero debe dar de alta un cliente y un juego..****\n \n ");
                    system( "pause");
                }


            break; //BREAK MENU INFORMES!


        } //FIN SWITCH PRINCIPAL

    }while (opciones != 5); // OPCIONES MENU PRINCIPAL

    return 0;

}





