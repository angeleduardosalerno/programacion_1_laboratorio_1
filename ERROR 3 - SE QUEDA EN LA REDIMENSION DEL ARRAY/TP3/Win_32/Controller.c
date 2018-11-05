#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "validaciones.h"
#include "Controller.h"



// EL ARCHIVO TIENE EL id,nombre,horasTrabajadas,sueldo Y ESTO COMO TIRULO, HACER UNA LECTURA EN FALSO
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param fileName char*
 * \param pArrayListEmployee LinkedList*
 * \return int -1 SI NO PUDO LEER EL ARCHIVO - I CANTIDAD DE DATOS LEIDOS
 *
 */

int controller_loadFromText(char* fileName , LinkedList* this ) // EN EL TP LE PASA EL PUNTERO A LINKED LIST NO SE Q HACE CON ESO...
{
    FILE *pFile;
    int r,i=0;
    char var1[50], var2[50] ,var3[50] ,var4[50]; // VARIABLES AUX EN Q SE ALMACENA LOS DATOS DEL ARCHIVO LEIDOS COMO STRING

    // HAY QUE CREAR LAS VARIABLES EMPLOYEE CON RESERVA DINAMICA DE MEMORIA SINO NO SE PUEDE GUARDAR EN NINGUN LADO ESTO...
    pFile = fopen(fileName,"r");

    if(pFile == NULL)
    {
        return -1;
    }

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);// LECTURA EN FALSO PARA EVITAR LOS TITULOS

    do{

        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4); // SE LEE DEL ARCHIVO LOS ELEMENTOS COMO STRING...

        if(r==4) // SI PUDO LEER LOS 4 ELEMENTOS DEL ARCHIVO: EL id,nombre,horasTrabajadas,sueldo
        {
            Employee* e = employee_newEmployee();
            employee_initialize(&e[i], var1, var2, var3, var4); // ACA HAY QUE PASAR LOS STRING A SUS RESPECTIVOS FORMATOS Y GUARDALO EN LA LISTA
            i++;
            ll_add(this,e); // SE CARGAN LOS DATOS GUARDADOS EN LA ESTRUCTURA EN LA LISTA!
        }
        else
        {
            break;
        }

    }while(!feof(pFile));

    fclose(pFile);


    //LIBERAR TODO EL ESPACIO DE MEMORIA USADO //NO SE DONDE PONER ESTO OJOOO!!!!

    //employee_free(e); //SE LIBERA LA ESTRUCTURA POR QUE NO SE GUARDO EN EL ARRAY NO LEE A E???

    /*for (i=0; i<ll_getSize(this); i++); // QUE DIFERENCIA HAY ENTRE ESTE Y EL DE ABAJO? // EL LL_GET TE DA LA POSICION DE MEMORIA DE LA LISTA DE PUNTERO
    {
        free(ll_get(this,i));
    }*/

    //ll_free(this); // SI ESTO NO ESTA ACA NO ANDA!!

     return i;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}
*/
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}
*/
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}
*/
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}
*/
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}
*/
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}
*/
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}
*/
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

*/
