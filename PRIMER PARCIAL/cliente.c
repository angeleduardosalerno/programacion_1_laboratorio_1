#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacionesinput.h"
#include "cliente.h"

 /**\brief Para indicar que todas las posiciones del array employee estan vacias, esta funcion pone la bandera isEmpty de la estructura en 1 (TRUE).
 * \param Employee arrayEmployees Es el array de tipo de dato estructura a ser inicializado.
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
 * \param ePersona arrayPersonas Es el array de tipo de dato estructura en donde se busca el dato.
 *\param int longitudArray Es la cantidad de elementos del array de enteros.
 * \return Devuelve el subindice vacio en el array (i) o -1 en caso de no haber lugar vacio. // OJO ACA USO EL -1 PARA INDICAR LUGAR VACIO
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


 /** \brief Agrega en un array de empleados existente, los valores recibidos como parámetro, en la primer posición libre encontrada.
 * \param Employee arrayEmployees [] Array de  empleados donde se cargan los datos ingresador
 * \param int longitudArray longitud del array de empleados.
 * \param id int // no va se calcula automaticamente....x funcion random
 * \param name[] char nombre del empleado a cargar, pasado por referencia desde main.
 * \param lastName[] char apellido del empleado a cargar, pasado por referencia desde main
 * \param salary float salario del empleado a cargar, pasado por referencia desde main
 * \param sector int sector del empleado a cargar, pasado por referencia desde main
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

 /** \brief find an Employee by Id en returns the index position in array.
 * \param Employee arrayEmployees array de empleados en el cual se va a buscar el id.
 * \param len int tamaño del array de empleados.
 * \param id int el id de empleado a buscar.
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

 /** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param Employee arrayEmployees Array de empleados donde se va a buscar el que se desea eliminar.
 * \param int longitudArray tamaño del array de empleados.
 * \param id int el id de empleado a buscar.
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

  /** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 * \param Employee arrayEmployees Array de empleados que se va a ordenar.
 * \param int longitudArray tamaño del array de empleados.
 * \param orden int [1] indicate UP ascendente - [0] indicate DOWN descendente
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
                        if (strcmp(arrayClientes[i].apellido, arrayClientes[j].apellido) >0) // PIDE ORDENAMIENTO POR APELLIDO Y SECTOR VER SI SE PONE UN Y ACA O HAY OTRA FORMA
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

/** \brief print the content of employees array.
 * \param Employee arrayEmployees [], es es array a ser impreso
 * \param int longitudArray Longitud del array de empleados.
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
 * \param Employee arrayEmployees array de empleados en el cual se va a buscar el id.
 * \param len int tamaño del array de empleados.
 * \param id int el id de empleado a buscar.
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

