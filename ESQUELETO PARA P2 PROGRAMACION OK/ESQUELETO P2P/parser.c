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
 * \return int 0 SI ES OK -1 SI HAY ERROR
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    char var1[50], var2[50] ,var3[50] ,var4[50]; // VARIABLES AUX EN Q SE ALMACENA LOS DATOS DEL ARCHIVO LEIDOS COMO STRING

    if (pFile != NULL && pArrayListEmployee != NULL )
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);// LECTURA EN FALSO PARA EVITAR LOS TITULOS

        do{
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4); // SE LEE DEL ARCHIVO LOS ELEMENTOS COMO STRING...

            if(r==4) // SI PUDO LEER LOS 4 ELEMENTOS DEL ARCHIVO: EL id,nombre,horasTrabajadas,sueldo
            {
                Employee* e= employee_newParametros(var1, var2, var3, var4); // ACA HAY QUE PASAR LOS STRING A SUS RESPECTIVOS FORMATOS Y GUARDALO EN LA LISTA

                ll_add(pArrayListEmployee,e); // SE CARGAN LOS DATOS GUARDADOS EN LA ESTRUCTURA EN LA LISTA!

            }

        }while(!feof(pFile));

        fclose(pFile); // CIERRA EL ARCHIVO SI EL PARSEO TERMINO!
        return 0;
    }
    else
    {
        printf("Error puntero null");
        fclose(pFile);
        return -1;
    }


}


/*
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pAux; // PUNTERO AL EMPLEADO

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
            ll_add(pArrayListEmployee,pAux); // AGREGA EL ELEMENTO A LA LISTA!, EL ELEMENTO ES EL PUNTERO CON LA UBICACION DE LOS DATOS CARGADOS!
            retorno = 0;
            }
        }
    }
    return retorno;
}
*/

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char var1[50], var2[50] ,var3[50] ,var4[50]; // VARIABLES AUX EN Q SE ALMACENA LOS DATOS DEL ARCHIVO LEIDOS COMO STRING
    int readLine;

    FILE *pFileBinary;

    if((pFileBinary=fopen("BINARY-DATA","rb"))==NULL) // SE ABRE EL BINARIO EN LECTURA, SI ES NULL ES POR QUE NO EXISTE Y SE CREA
    {
        if((pFileBinary=fopen("BINARY-DATA","wb"))==NULL) // SI ES IGUAL A NULL O SEA LA PRIMERA VEZ SI NO EXISTE EL ARCHIVO DEVUELVE NULL, ENTONCES LO CREA
        {
            printf("\nEl archivo no puede ser abierto");
            fclose(pFile);
            return -1;
        }

        // SE CREO EL ARCHIVO BINARIO
    }

    readLine = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    do {
            readLine = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

            if (readLine == 4)
            {
                Employee* e= employee_newParametros(var1, var2, var3, var4);

                fwrite(e, sizeof(Employee), 1, pFileBinary); //ESCRIBE EL ARCHIVO DE TEXTO PFILE EN EL BINARIO PBINARY FILE
                ll_add(pArrayListEmployee, e);
            }
            else
            {
                printf("LINEA CON CARACTERES ERRONEOS.\n");
                fclose(pFileBinary);
                fclose(pFile);
                return -1;
            }

    } while (!feof(pFile));

    fclose(pFileBinary);
    fclose(pFile);
    return 0;

}

/*
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
            fread(pEmpleado,sizeof(Employee),1,pFile); // EL F READ SE USA SOLO EN BINARIO YA QUE PARA LEER EL BINARIO NECESITAR ESTA FUNCION OJO!!!!
            //CREA UN ESPACIO DE MEMORIA PARA EMPLEADO, Y LEE DESDE EL P FILE Y LO GUARDA EN EL ESPACIO DE MEMORIA DEL EMPLEADO
            //O SEA, TERMINAS CON UNA ESTRUCTURA DE EMPLEADO CARGADA!

            employee_getId(pEmpleado,&auxId); // CON ESTA FORMA DE GET ID SE GUARDAN LAS VARIABLES AUX AUTOMATICAMENTE

            employee_getName(pEmpleado,auxNombre); // ESTO PARA QUE SIRVE SINO LO USA...

            employee_getHours(pEmpleado,&auxHorasTrabajadas); // LO MISMO CON ESTAS, ES UNA FORMA DISTINTA DE GUARDAR LOS AUX...

            employee_getSalary(pEmpleado,&auxSueldo);

            if( auxId >= 0 && strlen(auxNombre) > 0 && // VALIDACIONES VARIAS PARA VER Q EL ARCHIVO BINARIO SE LEYO OK!
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

*/


