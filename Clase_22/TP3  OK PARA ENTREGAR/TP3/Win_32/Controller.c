#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validacionesinput.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* ES EL NOMBRE DEL ARCHIVO PASADO DESDE EL MAIN
 * \param pArrayListEmployee LinkedList*
 * \return int 1 SI PUDO ABRIR EL ARCHIVO E INGRESAR AL PARSEO -1 SINO LO PUDO ABRIR.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    //ACA HAY QUE PROGRAMAR EL PARSEO....ACA HAY QUE LLAMAR AL PARSE, LE PASAS AL ARCHIVO
    FILE *pFile;
     // HAY QUE CREAR LAS VARIABLES EMPLOYEE CON RESERVA DINAMICA DE MEMORIA SINO NO SE PUEDE GUARDAR EN NINGUN LADO ESTO...
    pFile = fopen(path,"r"); // OJOOOOOO ACA VA EL TIPO LO Q TENGO QUE HACER! ES MEJOR ABRIRLO POR CADA ITEM DE ACUERDO A LO Q TE PIDAN!!
    // O SEA SI SE PUDO ABRIR EL ARCHIVO...! SE HACE EL PARSEO!!
    if(pFile != NULL && path != NULL) // ACA HAY QUE PREGUNTAR POR LOS DOS, HAY QUE PREGUNTAR POR EL ERROR...
    {
        printf("LLEGA AL PARSEO"); // SACAR PARA HACER PRUEBAS NOMAS!

        parser_EmployeeFromText(pFile, pArrayListEmployee);
        return 1;
    }
    else
    {
        fclose(pFile);
        return -1;
    }

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

