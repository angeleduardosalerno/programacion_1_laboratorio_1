#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    char auxSueldo[50];
    int flag = 1;
    int retorno = -1;

    if(pFile!= NULL)
    {
        while(!feof(pFile))
        {
            if(flag)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
                flag = 0;
            }

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

        pAux = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

            if(pAux !=NULL)
            {
            ll_add(pArrayListEmployee,pAux);
            retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param FILE* pFile*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* pEmpleado;
    int auxId;
    int lastId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    if(pFile!=NULL)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            pEmpleado = employee_new();
            fread(pEmpleado,sizeof(Employee),1,pFile);
            //CREA UN ESPACIO DE MEMORIA PARA EMPLEADO, Y LEE DESDE EL P FILE Y LO GUARDA EN EL ESPACIO DE MEMORIA DEL EMPLEADO
            //O SEA, TERMINAS CON UNA ESTRUCTURA DE EMPLEADO CARGADA!

            employee_getId(pEmpleado,&auxId); // NO ENTIENDO, O SEA EN EL AUX ID VA A ESTAR GUARDADO EL DATO DEL ID QUE ESTA EN P EMPLEADO! ???

            employee_getName(pEmpleado,auxNombre); // ESTO PARA QUE SIRVE SINO LO USA...

            employee_getHours(pEmpleado,&auxHorasTrabajadas); // LO MISMO CON ESTAS, ES UNA FORMA DISTINTA DE GUARDAR LOS AUX...

            employee_getSalary(pEmpleado,&auxSueldo);

            if( auxId >= 0 && strlen(auxNombre) > 0 && // VALIDACIONES VARIAS
                auxHorasTrabajadas > 0 && auxSueldo > 0)
            {
                ll_add(pArrayListEmployee, pEmpleado); // COPIA LA DIRECCION DE MEMORIA DE P EMPLEADO A LA LISTA DE PUNTEROS...

                lastId = auxId; // **********ojoo COPIA EL ULTIMO ID Q PASO POR ACA EN UN AUX
            }
        }

        for(i=0;i<=lastId;i++) // FOR Q VA DESDE EL 0 HASTA EL ULTIMO ID
        {
            employee_getNextId(); // NO SE QUE HACE ESTO...
        }
    }
    return retorno;
}


/** \brief Parsea los datos de los empleados para guardar en data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_SaveToText(FILE* pFile , LinkedList* pArrayListEmployee) // LO GUARDA CON UN FOR
{
    int retorno = -1;

    Employee* auxEmployee;

    int len;
    int i;
    int auxId; // VARIABLES AUX
    char auxNombre[1000];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee); // USA LA FUNCION PARA SABER EL TAMAÑO DE LA LISTA DE PUNTEROS

        for(i=0;i<len;i++) // RECORRE LA LISTA DE PUNTEROS
        {
            auxEmployee = ll_get(pArrayListEmployee,i); // LE VA ASIGNANDO A LA AUX EMPLOYEE LAS DIRECCIONES DE MEMORIA DONDE ESTAN GUARDADOS LOS DATOS DE LA LISTA DE UNTEROS

            employee_getAll(auxEmployee,auxNombre,&auxHorasTrabajadas,&auxSueldo,&auxId); // HACE LOS GET, OBTIENE LOS DATOS DE LAS DIFERENTES POSICIONES Y LOS GUARDA EN LAS VARIABLES AUXILIARES!

            fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo); // NO USA FWRITE!!! USA FSCA
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Parsea los datos de los empleados para guardar en data.bin (modo binario).
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_SaveToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i = 0;
    int auxId;
    char auxNombre[51];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* auxEmployee;

 if(pFile != NULL)
    {
        retorno = 0;
        for(i=0;i<ll_len(pArrayListEmployee);i++) // RECORRE LA LISTA DE PUNTEROS!
        {
            auxEmployee = ll_get(pArrayListEmployee,i); // GUARDA LAS DIRECCIONES DE EMPLEADOS CON LOS DATOS

            employee_getId(auxEmployee,&auxId); // EN LA POSICIONES DE MEMORIA DE LOS EMPLEADOS OBTIENE LOS DATOS! Y LOS GUARDA EN LA VARIABLES AUX
            employee_getName(auxEmployee,auxNombre);
            employee_getHours(auxEmployee,&auxHorasTrabajadas);
            employee_getSalary(auxEmployee,&auxSueldo);

            if( auxId > 0 && strlen(auxNombre) > 0 && // ACA USA LAS AUXILIARES PARA VALIDAR LOS DATOS
                auxHorasTrabajadas > 0 && auxSueldo > 0)
            {
                fwrite(auxEmployee,sizeof(Employee),1,pFile); // USA FWIRTE PARA ESCRIBIR EL ARCHIVO!!!
            }
        }
    }
    return retorno;
}
