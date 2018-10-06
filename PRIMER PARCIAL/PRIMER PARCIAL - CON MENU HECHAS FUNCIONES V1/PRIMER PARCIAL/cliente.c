#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacionesinput.h"
#include "cliente.h"
#define CANT_CLIENTES 100 // CANTIDAD DE CLIENTES


/**\brief Para indicar que todas las posiciones del array CLIENTES estan vacias, esta funcion pone la bandera isEmpty de la estructura en 1.
* \param Clientes arrayClientes [] Es el array de tipo de dato estructura a ser inicializado.
*\param int longitudArray Es la cantidad de elementos del array.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

 int initClientes(Clientes arrayClientes [], int longitudArray)
 {
     int i, retorno = -1;

     if (arrayClientes!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray; i++)
         {
             arrayClientes[i].isEmpty = 1;
         }
             retorno=0;
     }
     return retorno;
 }

 /**\brief Busca el primer lugar vacio en un array estructura, previamente cargado con el valor 1.
 * \param Clientes arrayClientes [] Es el array de tipo de dato estructura en donde se busca el dato.
 *\param int longitudArray Es la cantidad de elementos del array de enteros.
 * \return Devuelve el subindice vacio en el array (i) o -1 en caso de no haber lugar vacio.
 *
 */

 int utn_buscarLugarVacioClientes (Clientes arrayClientes[],int longitudArray)
 {
     int i, retorno=-1;

     if (arrayClientes!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if ( arrayClientes[i].isEmpty == 1)
             {
                 retorno= i;
                 break;
             }
         }
     }
         return retorno;
 }

 /** \brief Agrega, en un array de CLIENTES existente, los valores recibidos como parámetro en la primer posición libre encontrada.
 * \param Clientes arrayClientes [] Array de  CLIENTES donde se cargan los datos ingresados
 * \param int longitudArray longitud del array de empleados.
 * \param int auxCodigoCliente CODIGO DE CLIENTE GENERADO AUTOMATICAMENTE PASADO POR REFERENCIA.
 * \param char auxApellidoCliente [] apellido del CLIENTE a cargar, pasado por referencia.
 * \param char auxNombreCliente[] nombre del CLIENTE a cargar, pasado por referencia.
 * \param char auxDomicilio[] DOMICILIO del CLIENTE a cargar, pasado por referencia.
 * \param char auxTelefono[] TELEFONO del CLIENTE a cargar, pasado por referencia.
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */

 int addClientes (Clientes arrayClientes[] ,int longitudArray, int auxCodigoCliente, char auxApellidoCliente [], char auxNombreCliente[], char auxDomicilio[], char auxTelefono[] )
 {
       int i;
       int retorno=-1;

     if (arrayClientes!= NULL && longitudArray > 0)
     {
        i= utn_buscarLugarVacioClientes(arrayClientes, longitudArray); // BUSCA EL 1 Q ES EL LUGAR VACIO...

        if (i != -1) // o sea si no hay error en la funcion anterior
        {
            arrayClientes[i].isEmpty=0;
            arrayClientes[i].codigoCliente = auxCodigoCliente;
            strcpy (arrayClientes[i].apellido, auxApellidoCliente);
            strcpy (arrayClientes[i].nombre, auxNombreCliente);
            strcpy (arrayClientes[i].domicilio, auxDomicilio);
            strcpy (arrayClientes[i].telefono, auxTelefono);

            retorno= 0;
        }
     }
         return retorno;
 }

 /** \brief BUSCA UN CLIENTE EN EL ARRAY DE CLIENTES Y DEVUELVE SU POSICION EN LA ESTRUCTURA.
 * \param Clientes arrayClientes[] array de CLIENTES en el cual se va a buscar el id.
 * \param int longitudArray longitud del array de empleados.
 * \param int codigoCliente el id del CLIENTE a buscar.
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
  int findClienteById(Clientes arrayClientes[], int longitudArray, int codigoCliente)
 {
     int i;
     int retorno=-1;

     if (arrayClientes!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if (arrayClientes[i].codigoCliente == codigoCliente)
             {
                 retorno= i;
                 break;
             }
         }
     }
         return retorno;
 }

/** \brief Remove a CLIENTE by Id (put isEmpty Flag in 1)
* \param Clientes arrayClientes[] Array de empleados donde se va a buscar el que se desea eliminar.
* \param int longitudArray tamaño del array de CLIENTES.
* \param int codigoCliente el id del CLIENTE a buscar.
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
  int removeClientes (Clientes arrayClientes[], int longitudArray, int codigoCliente)
 {
     int i;
     int retorno=-1;

     if (arrayClientes!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if (arrayClientes[i].codigoCliente == codigoCliente)
             {
                 arrayClientes[i].isEmpty=1;
                 retorno= 0;
             }
         }
     }
         return retorno;
 }

/** \brief ORDENA EL ARRAY CLIENTES POR APELLIDO Y NOMBRE, EN ORDEN ASCENDENTE.
* \param Clientes arrayClientes[] Array de CLIENTES que se va a ordenar.
* \param int longitudArray tamaño del array de CLIENTES.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortClientes (Clientes arrayClientes[], int longitudArray)
{
     int i, j, retorno=-1;
     Clientes auxArrayClientes;

     if (arrayClientes!= NULL && longitudArray > 0)
     {
         for(i=0; i<longitudArray-1; i++)
         {
             if (arrayClientes[i].isEmpty==0)   //PARA QUE LEA UNICAMENTE LOS ESPACIOS CARGADOS
             {
                for(j=i+1; j<longitudArray; j++)
                {
                    if (arrayClientes[j].isEmpty==0) //PARA QUE LEA UNICAMENTE LOS ESPACIOS CARGADOS
                    {
                        if (strcmp(arrayClientes[i].apellido, arrayClientes[j].apellido) >0)
                        {
                            auxArrayClientes = arrayClientes[i];
                            arrayClientes[i] = arrayClientes[j];
                            arrayClientes[j] = auxArrayClientes;
                            retorno=0;
                        }
                        else
                        {
                            if (strcmp (arrayClientes[i].apellido, arrayClientes[j].apellido) ==0)
                            {
                                if (strcmp(arrayClientes[i].nombre, arrayClientes[j].nombre) >0)
                                {
                                    auxArrayClientes = arrayClientes[i];
                                    arrayClientes[i] = arrayClientes[j];
                                    arrayClientes[j] = auxArrayClientes;
                                    retorno=0;
                                }
                            }
                        }
                    }
                }
             }
         }
     }
    return retorno;
}

/** \brief print the content of CLIENTES array.
* \param Clientes arrayClientes[], es es array a ser impreso
* \param int longitudArray Longitud del array de CLIENTES.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
*
*/
int printClientes(Clientes arrayClientes[], int longitudArray)
 {
     int i;
     int retorno=-1;

     if (arrayClientes!= NULL && longitudArray > 0)
     {
          for (i=0; i< longitudArray ; i++)
         {
             if (arrayClientes[i].isEmpty != 1) // SOLAMENTE VA A MOSTRAS LOS VECTORES GUARDADOS, SINO HAY DATOS MUESTRA BASURA..
             {
                 printf("\nAPELLIDO:%s\nNOMBRE:%s\nCODIGO CLIENTE:%d\nDOMICILIO:%s\nTELEFONO:%s\n", arrayClientes[i].apellido, arrayClientes[i].nombre,
                        arrayClientes[i].codigoCliente, arrayClientes[i].domicilio, arrayClientes[i].telefono);
             }
         }
         retorno=0;
     }
     return retorno;
 }

/** \brief find an Employee by Id en returns the index position in array.
* \param Employee arrayEmployees array de CLIENTES en el cual se va a buscar el id.
* \param int longitudArray tamaño del array de CLIENTES.
* \param int codigoCliente el id del CLIENTE a buscar.
* \return Return 0 if ok index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
 int checkCodigoClientes (Clientes arrayClientes[], int longitudArray, int codigoCliente)
 {
     int i;
     int retorno=-1;

     if (arrayClientes!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if (arrayClientes[i].isEmpty != 1)
             {
                if (arrayClientes[i].codigoCliente == codigoCliente)
                {
                    retorno= 0;
                    break;
                }
            }
        }
     }
    return retorno;
 }


// FUNCIONES GENERALES

/** \brief DESPLIEGA EL MENU CLIENTES Y REALIZA TODAS LAS OPERANCIONES DE DICHO MENU
* \return void
*
*/

void menuClientes()
{
    int respuesta, contadorInicio=0;
    int index, contadorAltasClientes=0;
    char auxApellidoCliente[51], auxNombreCliente[51], auxDomicilio[51], auxTelefono[21];
    int auxIndexClientes;
    int verificarIdClientes;
    int opcionesClientes, contadorClientes=0, auxCodigoCliente, opcionesDosClientes;

    Clientes arrayClientes [CANT_CLIENTES];


                do
                {
                    contadorInicio++;

                    if (contadorInicio ==1)
                    {
                        initClientes(arrayClientes , CANT_CLIENTES);
                    }

                    utn_getNumeroAvanzada(&opcionesClientes, "\n \n------CLIENTES------\n 1. ALTAS \n 2. MODIFICAR  \n 3. BAJA  \n 4. LISTAR. \n 5. Salir.\n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);

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





}



