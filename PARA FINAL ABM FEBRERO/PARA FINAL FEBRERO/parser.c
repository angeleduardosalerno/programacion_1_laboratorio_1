#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validacionesinput.h"
#include "parser.h"
#include "Controller.h"
#include <string.h>


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 SI ES OK -1 SI HAY ERROR
 *
 */
int parser_EmployeeFromTextSocios(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    char var1[50], var2[50] ,var3[50],var4[50], var5[50]; // VARIABLES AUX EN Q SE ALMACENA LOS DATOS DEL ARCHIVO LEIDOS COMO STRING, POSTERIORMENTE SE GUARDAN EN SU TIPO ESPECIFICO!

    if (pFile != NULL && pArrayListEmployee != NULL )
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);// LECTURA EN FALSO PARA EVITAR LOS TITULOS, EL ARCHIVO SIGUE ESTE FORMATO: ID, NOMBRE, HORAS TRABAJADAS Y ENTER!

        do{
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5); // WARDA CON LAS COMAS QUE SEPARAN LOS ELEMENTOS EN EL MEDIO, SI FALTA UNA NO ANDA OK EL PARSEO!

            if(r==5) // SI PUDO LEER LOS 5 ELEMENTOS DEL ARCHIVO
            {
                Employee* e= employee_newParametrosSocios(var1, var2, var3, var4, var5); // ACA HAY QUE PASAR LOS STRING A SUS RESPECTIVOS FORMATOS Y GUARDALO EN LA LISTA

                ll_add(pArrayListEmployee,e); // SE CARGAN LOS DATOS GUARDADOS EN LA ESTRUCTURA EN LA LISTA!
                //EL E QUE SE AGREGA ES EL DATO DEL NODO QUE CONTIENE EL PUNTERO AL ESPACIO DE MEMORIA CON LOS DATOS CARGADOS DE E EMPLOYEE!

            }

        }while(!feof(pFile));

        rewind(pFile);
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


/** \brief Parsea los datos los datos de los FICHAJES DE LOS EMPLEADOS
 * \return int 0 SI ES OK -1 SI HAY ERROR
 *
 */

int parser_EmployeeFromTextFichajes(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    char var1[50], var2[50] ,var3[50],var4[50], var5[50], var6[50], var7[50], var8[50]; // VARIABLES AUX EN Q SE ALMACENA LOS DATOS DEL ARCHIVO LEIDOS COMO STRING, POSTERIORMENTE SE GUARDAN EN SU TIPO ESPECIFICO!

    if (pFile != NULL && pArrayListEmployee != NULL )
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7,var8);// LECTURA EN FALSO PARA EVITAR LOS TITULOS, EL ARCHIVO SIGUE ESTE FORMATO: ID, NOMBRE, HORAS TRABAJADAS Y ENTER!

        do{
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7,var8); // WARDA CON LAS COMAS QUE SEPARAN LOS ELEMENTOS EN EL MEDIO, SI FALTA UNA NO ANDA OK EL PARSEO!

            if(r==8) // SI PUDO LEER LOS 5 ELEMENTOS DEL ARCHIVO
            {
                Fichajes* fichaje= fichajes_newParametrosFichajes(var1, var2, var3, var4, var5,var6,var7,var8); // ACA HAY QUE PASAR LOS STRING A SUS RESPECTIVOS FORMATOS Y GUARDALO EN LA LISTA

                ll_add(pArrayListEmployee,fichaje); // SE CARGAN LOS DATOS GUARDADOS EN LA ESTRUCTURA EN LA LISTA!
                //EL E QUE SE AGREGA ES EL DATO DEL NODO QUE CONTIENE EL PUNTERO AL ESPACIO DE MEMORIA CON LOS DATOS CARGADOS DE E EMPLOYEE!

            }

        }while(!feof(pFile));

        rewind(pFile); // SUPER IMP! PONE DEVUELTA EL INDICADOR DE POSICION AL PRINCIPIO DEL ARCHIVO!
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


/** \brief Parsea los datos de los empleados para guardar en data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_SaveToTextEmpleados(FILE* pFile , LinkedList* pArrayListEmployee) // LO GUARDA CON UN FOR
{
    int retorno = -1;

    Employee* auxEmployee;

    int len, i, auxId;
    char auxNombre[70], auxApellido[70], auxDni[70], auxClave[70];

    //CHEQUEAR SI HACE FALTA PONER EL FPRINT F PARA LA LECTURA EN FALSO!!! PARA ESO CHEQUEAR SI CUANDO SE GUARDA, SE CIERRA EL PROGRAMA SE COME LA PRIMERA LECTURA!!!
    //DE SEGURO HAY QUE PONERLO!!
     //fprintf(pFile,"%d,%s,%s,%s,%s\n", auxId,auxNombre,auxApellido,auxDni, auxClave );

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee); // USA LA FUNCION PARA SABER EL TAMAÑO DE LA LISTA DE PUNTEROS

        for(i=0;i<len;i++) // RECORRE LA LISTA DE PUNTEROS
        {
            auxEmployee = ll_get(pArrayListEmployee,i); // LE VA ASIGNANDO A LA AUX EMPLOYEE LAS DIRECCIONES DE MEMORIA DONDE ESTAN GUARDADOS LOS DATOS DE LA LISTA DE PUNTEROS

            //REALIZA TODOS LO GET DE UN EMPLEADO!

            employee_getId(auxEmployee, &auxId);
            employee_getName(auxEmployee, auxNombre);
            employee_getApellido(auxEmployee, auxApellido);
            employee_getDni(auxEmployee, auxDni);
            employee_getClave(auxEmployee, auxClave);


            fprintf(pFile,"%d,%s,%s,%s,%s\n", auxId,auxNombre,auxApellido,auxDni, auxClave ); // OJOOOOOOOOOOO SUPER IMP!!!! fprintf(pFile,"%d,%s,%s,%s,%s \n",-------->POR TENER UN ESPACIO ENTRE EL S Y EL ENTER NO GUARDABA LA CLAVE AL FINAL!!!OJOOO!
            retorno = 0;
        }
    }
    return retorno;
}



/** \brief Parsea los datos de los empleados para guardar en data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList* FICHAJES
 * \return int
 *
 */

int parser_SaveToTextFichajes(FILE* pFile , LinkedList* pArrayListEmployee) // LO GUARDA CON UN FOR
{
    int retorno = -1;

    Fichajes* auxFichaje;

    int minutos, hora, dia, mes, anio, id_Fichajes, id_Empleado, len, i ;
    char ingresoEgreso[20];



    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee); // USA LA FUNCION PARA SABER EL TAMAÑO DE LA LISTA DE PUNTEROS

        fprintf(pFile,"%d,%d,%d,%d,%d,%d,%d,%s\n", id_Fichajes, id_Empleado, minutos, hora, dia, mes, anio, ingresoEgreso); // PARA AGREGAR UNO MAS AL PRINCIPIO YA QUE EL DE LECTURA LEE UNO EN FALTSO

        // PARA AGREGAR UNO MAS AL PRINCIPIO YA QUE EL DE LECTURA LEE UNO EN FALSOOO OJO SUPER IMP!!!!

        for(i=0;i<len;i++) // RECORRE LA LISTA DE PUNTEROS
        {
            auxFichaje = ll_get(pArrayListEmployee,i); // LE VA ASIGNANDO A LA AUX EMPLOYEE LAS DIRECCIONES DE MEMORIA DONDE ESTAN GUARDADOS LOS DATOS DE LA LISTA DE PUNTEROS

            //REALIZA TODOS LO GET DE UN EMPLEADO!

            fichajes_getId( auxFichaje, &id_Fichajes );
            fichajes_getIdEmpleado( auxFichaje, &id_Empleado );

            fichajes_getMinutos( auxFichaje, &minutos );
            fichajes_getHora( auxFichaje, &hora );
            fichajes_getDia( auxFichaje, &dia );
            fichajes_getMes( auxFichaje, &mes );
            fichajes_getAnio( auxFichaje, &anio );

            fichajes_getIngresoEgreso( auxFichaje, ingresoEgreso );


            // PARA UN PRINT F: "%ID FICHAJE : %d -  ID EMPLEADO: %d \n HORA: %d : %d  \n FECHA: %d / %d / %d \n INGRESO O EGRESO: %s \n"
            fprintf(pFile,"%d,%d,%d,%d,%d,%d,%d,%s\n", id_Fichajes, id_Empleado, minutos, hora, dia, mes, anio, ingresoEgreso); // OJOOOOOOOOOOO SUPER IMP!!!! fprintf(pFile,"%d,%s,%s,%s,%s \n",-------->POR TENER UN ESPACIO ENTRE EL S Y EL ENTER NO GUARDABA LA CLAVE AL FINAL!!!OJOOO!
            // UN ESPACIO DE MAS ACA TE ARRUINA TODO, TIENE QUE ESTAR TODO JUNTO Y CON EL N DEL FINAL TMB


            retorno = 0;
        }
    }
    return retorno;
}
