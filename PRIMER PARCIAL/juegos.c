#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacionesinput.h"
#include "juegos.h"


/**\brief Para indicar que todas las posiciones del array employee estan vacias, esta funcion pone la bandera isEmpty de la estructura en 1 (TRUE).
 * \param Employee arrayEmployees Es el array de tipo de dato estructura a ser inicializado.
 *\param int longitudArray Es la cantidad de elementos del array.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

 int initJuegos(Juegos arrayJuegos [], int longitudArray)
 {
     int i, retorno = -1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray; i++)
         {
             arrayJuegos[i].isEmpty = 1;
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

 int utn_buscarLugarVacioJuegos (Juegos arrayJuegos [],int longitudArray)
 {
     int i, retorno=-1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if ( arrayJuegos[i].isEmpty == 1)
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

 int addJuegos (Juegos arrayJuegos [], int longitudArray, int codigoJuego , char descripcion[], float importe)
 {
       int i;
       int retorno=-1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
        i= utn_buscarLugarVacioJuegos(arrayJuegos, longitudArray); // BUSCA EL 1 Q ES EL LUGAR VACIO...

        if (i != -1) // o sea si no hay error en la funcion anterior
        {
            arrayJuegos[i].isEmpty=0;
            arrayJuegos[i].codigoJuego = codigoJuego;
            strcpy (arrayJuegos[i].descripcionJuego, descripcion);
            arrayJuegos[i].importeJuego=importe;

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
 int findJuegoById(Juegos arrayJuegos [], int longitudArray, int codigoJuego)
 {
     int i;
     int retorno=-1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if (arrayJuegos[i].codigoJuego == codigoJuego)
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
 int removeJuegos (Juegos arrayJuegos [], int longitudArray, int codigoJuego)
 {
     int i;
     int retorno=-1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if (arrayJuegos[i].codigoJuego == codigoJuego)
             {
                 arrayJuegos[i].isEmpty=1;
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
 int sortJuegos (Juegos arrayJuegos [], int longitudArray) // TENGO QUE HACER UN FLAG PARA VER SI ESTA ORDENADO O NO...OJO!
 {
     int i, j, retorno=-1;
     Juegos auxArrayJuegos;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         for(i=0; i<longitudArray-1; i++)
         {
             if (arrayJuegos[i].isEmpty==0) // PARA QUE LEA SOLO LOS QUE ESTAN GUARDADOS !
             {
                 for(j=i+1; j<longitudArray; j++)
                {
                     if (arrayJuegos[j].isEmpty==0) // PARA QUE LEA SOLO LOS QUE ESTAN GUARDADOS !
                     {
                        if (arrayJuegos[i].importeJuego > arrayJuegos[j].importeJuego)
                        {
                            auxArrayJuegos = arrayJuegos[i];
                            arrayJuegos[i] = arrayJuegos[j];
                            arrayJuegos[j] = auxArrayJuegos;
                            retorno=0;
                        }
                        else
                        {
                            if (arrayJuegos[i].importeJuego == arrayJuegos[j].importeJuego)
                            {
                                if (strcmp(arrayJuegos[i].descripcionJuego,arrayJuegos[j].descripcionJuego) >0) // PIDE ORDENAMIENTO POR APELLIDO Y SECTOR VER SI SE PONE UN Y ACA O HAY OTRA FORMA
                                {
                                    auxArrayJuegos = arrayJuegos[i];
                                    arrayJuegos[i] = arrayJuegos[j];
                                    arrayJuegos[j] = auxArrayJuegos;
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
 int printJuegos(Juegos arrayJuegos [], int longitudArray)
 {
     int i;
     int retorno=-1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
          for (i=0; i< longitudArray ; i++)
         {
             if (arrayJuegos[i].isEmpty != 1) // SOLAMENTE VA A MOSTRAS LOS VECTORES GUARDADOS, SINO HAY DATOS MUESTRA BASURA..
             {
                 printf("\nIMPORTE JUEGO:%0.2f\t DESCRIPCION:%s\t CODIGO JUEGO:%d\n", arrayJuegos[i].importeJuego, arrayJuegos[i].descripcionJuego, arrayJuegos[i].codigoJuego);
             }
         }
         retorno=0;
     }
     return retorno;
 }

//SECTOR ALQUILERES ************************************************************************************************************************************

/**\brief Para indicar que todas las posiciones del array employee estan vacias, esta funcion pone la bandera isEmpty de la estructura en 1 (TRUE).
 * \param Employee arrayEmployees Es el array de tipo de dato estructura a ser inicializado.
 *\param int longitudArray Es la cantidad de elementos del array.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

 int initAlquileres (Alquileres arrayAlquileres [] , int longitudArray)
 {
     int i, retorno = -1;

     if (arrayAlquileres!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray; i++)
         {
             arrayAlquileres[i].isEmpty = 1;
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

 int utn_buscarLugarVacioAlquileres(Alquileres arrayAlquileres [], int longitudArray)
 {
     int i, retorno=-1;

     if (arrayAlquileres!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if ( arrayAlquileres[i].isEmpty == 1)
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

int addAlquileres (Alquileres arrayAlquileres [],int longitudArray, int contadorAlquileres, int auxCodigoJuegoAlquileres,
                   int auxCodigoClienteAlquileres, int auxDiaFecha, int auxMesFecha, int auxAnioFecha)
 {
    int i;
    int retorno=-1;

     if (arrayAlquileres!= NULL && longitudArray > 0)
     {
        i= utn_buscarLugarVacioAlquileres(arrayAlquileres, longitudArray); // BUSCA EL 1 Q ES EL LUGAR VACIO...

        if (i != -1) // o sea si no hay error en la funcion anterior
        {
            arrayAlquileres[i].isEmpty=0;
            arrayAlquileres[i].codigoAlquileres = contadorAlquileres;
            arrayAlquileres[i].codigoJuegoAlquileres = auxCodigoJuegoAlquileres;
            arrayAlquileres[i].codigoClienteAlquileres = auxCodigoClienteAlquileres;
            arrayAlquileres[i].fecha.dia=auxDiaFecha;
            arrayAlquileres[i].fecha.mes=auxMesFecha;
            arrayAlquileres[i].fecha.anio=auxAnioFecha;

            retorno= 0;
        }
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
 int checkCodigoJuegos (Juegos arrayJuegos [], int longitudArray, int codigoJuego)
 {
     int i;
     int retorno=-1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if (arrayJuegos[i].isEmpty != 1)
             {
                if (arrayJuegos[i].codigoJuego == codigoJuego)
                {
                    retorno= 0;
                    break;
                }
             }
         }
     }
         return retorno;
 }

