#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r,i=0;
    char var1[50], var2[50] ,var3[50] ,var4[50]; // VARIABLES AUX EN Q SE ALMACENA LOS DATOS DEL ARCHIVO LEIDOS COMO STRING


    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);// LECTURA EN FALSO PARA EVITAR LOS TITULOS

    do{

        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4); // SE LEE DEL ARCHIVO LOS ELEMENTOS COMO STRING...

        if(r==4) // SI PUDO LEER LOS 4 ELEMENTOS DEL ARCHIVO: EL id,nombre,horasTrabajadas,sueldo
        {
            Employee* e = employee_newEmployee();
            employee_initialize(&e[i], var1, var2, var3, var4); // ACA HAY QUE PASAR LOS STRING A SUS RESPECTIVOS FORMATOS Y GUARDALO EN LA LISTA
            i++;
            ll_add(pArrayListEmployee,e); // SE CARGAN LOS DATOS GUARDADOS EN LA ESTRUCTURA EN LA LISTA!
            //ACA HAY QUE USAR EL LL ADD DE LA LISTA!!!
        }
        else
        {
            break;
        }

    }while(!feof(pFile));

    fclose(pFile);

    return 1;
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
