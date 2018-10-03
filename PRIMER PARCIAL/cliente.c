#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
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

 int addClientes (Clientes arrayClientes[] ,int longitudArray, int auxCodigoCliente, char auxApellidoCliente, char auxNombreCliente, char auxDomicilio, char auxTelefono )
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
