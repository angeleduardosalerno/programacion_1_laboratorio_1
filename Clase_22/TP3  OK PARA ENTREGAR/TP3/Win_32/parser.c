#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validacionesinput.h"
#include "parser.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int i CANTIDAD DE LINEAS LEIDAS EN EL ARCHIVO
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r,i=0;
    char var1[50], var2[50] ,var3[50] ,var4[50]; // VARIABLES AUX EN Q SE ALMACENA LOS DATOS DEL ARCHIVO LEIDOS COMO STRING

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);// LECTURA EN FALSO PARA EVITAR LOS TITULOS

    printf("LLEGA A la lectura en falso");

     do{
         r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4); // SE LEE DEL ARCHIVO LOS ELEMENTOS COMO STRING...

        if(r==4) // SI PUDO LEER LOS 4 ELEMENTOS DEL ARCHIVO: EL id,nombre,horasTrabajadas,sueldo
        {
            printf("LLEGA A la lectura DEL ARCHIVO");

            Employee* e = employee_newEmployee();
            printf("LLEGA A CREAR NEW EMPLOYEE");

            employee_newParametros(&e[i], var1, var2, var3, var4); // ACA HAY QUE PASAR LOS STRING A SUS RESPECTIVOS FORMATOS Y GUARDALO EN LA LISTA
            printf("LLEGA A la NEW PARAMETROS");

            i++; // OJO LA FUNCION NEW PARAMETROS DEVUELVE UN PUNTERO, VER SI PASARLE E DIRECTAMENTE O HACER E=EMPLOYEE NEW PARAMETROS!!! OJOOOOOOOOO!

            ll_add(pArrayListEmployee,e); // SE CARGAN LOS DATOS GUARDADOS EN LA ESTRUCTURA EN LA LISTA!
            printf("LLEGA A LIST ADD");
            //ACA HAY QUE USAR EL LL ADD DE LA LISTA!!!
        }
        else
        {
            break;
        }

    }while(!feof(pFile));

    fclose(pFile); // CIERRA EL ARCHIVO SI EL PARSEO TERMINO!

 return i;
}



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
