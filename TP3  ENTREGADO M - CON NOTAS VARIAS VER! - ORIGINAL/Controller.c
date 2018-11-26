#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "Validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo; // SE CREA UN PUNTERO A FILE

    int retorno = -1; // RETORNAS UN ERROR SINO SE CARGA OK ADENTRO

    pArchivo = fopen(path,"r"); // ABRIS EL ARCHIVO EN MODO LECTURA Y LA DIR LA GUARDAS EN LA VARIABLE FILE

    if(!parser_EmployeeFromText(pArchivo, pArrayListEmployee)) //O SEA SI ES ==0, SI ESTA OK
    {
        printf("\n La carga de datos del Archivo tipo Texto se realizo efectivamente.\n");
        retorno = 0;
    }
    else
    {
        printf("\n Archivo de Texto no encontrado.\n");
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;

    pArchivo = fopen(path, "rb"); // ABRIS EL ARCHIVO EN RB
    if(!parser_EmployeeFromBinary(pArchivo, pArrayListEmployee))
    {
        printf("\n La carga de datos del Archivo tipo Binario se realizo efectivamente. \n");
        retorno = 0;
    }
    else
    {
        printf("\n Archivo Binario no encontrado.\n");
    }
    fclose(pArchivo);
    system("pause");

    return retorno;
}

/** \brief Alta de empleados de modo texto.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployeeTxt(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int sueldo;
    int horasTrabajadas;
    char nombre[51];

    if(!getName(nombre,51,"Ingrese el nombre: ","Reingrese el nombre: ",2)&&
    !getInt(&horasTrabajadas,"\nIngrese las horas: ","Reingrese las horas: ",0,99999,2)&&
    !getInt(&sueldo,"\nIngrese el sueldo: ","Reingrese el sueldo: ",0,99999,2)
    )
    {
        Employee* empleado = employee_IdGen(nombre,horasTrabajadas,sueldo); // VER FUNCION ID GENERATOR!! CREA EL EMPLOYEE Y HACE LOS SET

        if(empleado != NULL)
        {
            retorno = ll_add(pArrayListEmployee,empleado); // LOS ADHIERE A LA LISTA DE PUNTEROS!
        }
    }

    return retorno;
}

/** \brief Alta de empleados de modo binario.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployeeBin(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    char auxIdString[20];
    int auxIdInt;
    char auxNombre[51];
    char auxHorasTrabajadas[20];
    char auxSueldo[20];

    if( pArrayListEmployee != NULL &&
        !getText(auxNombre,51,"Ingrese el nombre: ","Reingrese el nombre:",0) &&
        !getText(auxHorasTrabajadas,20,"Ingrese las horas: ", "Reingrese las horas:",0) &&
        !getText(auxSueldo,20,"Ingrese el sueldo: ","Reingrese el sueldo:",0))
    {
        auxIdInt = employee_getNextId();

        snprintf(auxIdString, 20*sizeof(char), "%d", auxIdInt);

        pEmpleado = employee_newParametros(  auxIdString,auxNombre,
                                                auxHorasTrabajadas,auxSueldo);
        if(pEmpleado != NULL)
        {
            ll_add(pArrayListEmployee, pEmpleado);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int id, idAux;

    Employee* empleado; // ES UN PUNTERO A LA ESTRUCTURA EMPLEADO, POR ESO SE USA EL OP FLECHA

    int sueldo;
    int horasTrabajadas;
    char nombre[51];
    char option='n';
    int opcionM=0;

    printf("Desea ver la lista de empleados?");
    scanf("%s", &option);
    fflush(stdin);
    if(option=='s')
    {
        controller_ListEmployee(pArrayListEmployee);
    }

    if(pArrayListEmployee != NULL)
    {
        if(!getInt(&id,"Ingrese el ID del empleado a modificar: ","Reingrese un numero valido",0,99999,2))
        {
            for(i = 0;i< ll_len(pArrayListEmployee);i++) // LO PRIMERO QUE HACE ES RECORRER LA LISTA DE PUNTEROS, USANDO LA FUNCION PARA OBTENER SU TAMAÑO (INDEX)
            {

                empleado = ll_get(pArrayListEmployee,i); // recorre la lista de punteros, Y USANDO EL I DEL FOR DEVUELVE LA POSICION DE MEMORIA DONDE ESTAN GUARDADOS TODOS LOS DATOS DE LOS EMPLEADOS
                //el ll get te DEVUELVE LA POSICION DE MEMORIA DE EMPLEADO GUARDADA EN LA LISTA DE PUNTEROS Y TE RECORRE LA LISTA DE PUNTEROS DESDE EL 0 HASTA EL FINAL


               employee_getId(empleado,&idAux); // GUARDA EN LA VARIABLE ID AUX EL ID QUE CORRESPONDE A LA POSICION DE MEMORIA I DEL EMPLEADO DE LA LINEA ANTERIOR.

               if(idAux == id) // ENTONCES SI EL ID INGRESADO MANUAL, SE ENCUENTRA EN EL ID DE LOS EMPLEADOS, SE INGRESA A EL Y SE MODIFICA...
               {
                   printf("Elija que campo desea modificar:\n 1- Nombre \n 2- Horas de trabajo \n 3- Sueldo \n");
                   scanf("%d", &opcionM);

                   switch(opcionM)
                   {
                   case 1:
                    if(!getName(nombre,51,"Ingrese el nuevo nombre: ","Reingrese un nombre valido",2)) // GUARDAS EL NOMBRE EN UNA VARIABLE AUX
                    {
                        if( !employee_setName(empleado, nombre)) //GUARDAS EL NOMBRE CON LA FUNCION SET...
                          {
                            retorno = 0;
                            break;
                          }
                    }
                    else{
                        break;
                    }
                   case 2:
                    if(!getInt(&horasTrabajadas,"Ingrese las nuevas horas: ","Reingrese un numero valido",0,99999,2))
                    {
                        if(!employee_setHours(empleado, horasTrabajadas))
                        {
                            retorno=0;
                            break;
                        }
                    }
                    else{
                        break;
                    }
                   case 3:
                    if(!getInt(&sueldo,"Ingrese el nuevo sueldo: ","Reingrese un numero valido",0,99999,2))
                    {
                        if(!employee_setSalary(empleado, sueldo))
                        {
                            retorno=0;
                            break;
                        }
                    }
                    else{
                        break;
                    }
                   default: printf("Opcion invalida");
                   }
               }
            }
        }

    }
    return retorno;
}

/** \brief Baja de empleado.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int id, idAux;
    Employee* empleado;
    char option='n';

    printf("Desea ver la lista de empleados?");
    scanf("%s", &option);
    fflush(stdin);

    if(option=='s')
    {
        controller_ListEmployee(pArrayListEmployee);
    }

    if(pArrayListEmployee != NULL)
    {
        if(!getInt(&id,"Ingrese el ID del empleado a borrar: ","Ingrese un ID valido",0,99999,2))
        {
            for(i = 0;i< ll_len(pArrayListEmployee);i++) // LO MISMO QUE EN EL PUNTO ANTERIOR, PIDE EL INGRESO DEL ID, RECORRE LA LISTA Y SI ENCUENTRA EL ID INGRESADO LO MODIFICA
            {
               empleado = ll_get(pArrayListEmployee,i); // VA SACANDO LAS DIFERENTES POSICIONES DE MEMORIA DONDE ESTAN GUARDADOS LOS EMPLEADOS
               employee_getId(empleado,&idAux); // SACA EL ID DE DICHAS POSICIONES

               if(idAux == id) // COMPARA EL ID DE DICHAS POSICIONES CON EL INGRESADO MANUALMENTE!
               {
                    employee_delete(empleado); // LIBERA EL ESPACIO DE MEMORIA DONDE ESTABA GUARDADO ESE EMPLEADO

                    ll_remove(pArrayListEmployee,i); // BORRA ESE ESPACIO DE MEMORIA DE LA LISTA

                    retorno = 0;
                    break;
               }
            }
        }

    }
    return retorno;
}

/** \brief Listar empleados.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    char nombre[128];
    int id;
    int sueldo;
    int horasTrabajadas;

    Employee* auxPunteroEmpleado;

    if(pArrayListEmployee != NULL)
    {
        retorno = 0;

        for(i=0;i < ll_len(pArrayListEmployee);i++) // RECORRE LA LISTA DE PUNTEROS
        {
            if(i%60==0) // SINO ENTRA ACA ENTRA AL DE ABAJO SON IGUALES -------- PARA QUE SE PUEDA VER EN PANTALLA TODA LA LISTA!!
            {
            system("pause");

            auxPunteroEmpleado = ll_get(pArrayListEmployee,i); // GUARDA LAS POSICIONES DE MEMORIA DE EMPLEADO GUARDADAS EN LA LISTA DE PUNTEROS
            employee_getId(auxPunteroEmpleado,&id); // REALIZA TODO LOS GET Y TOMA LOS DATOS DE LAS POSICIONES DE MEMORIA TOMADA ANTES, GUARDANDO TODO EN VARIABLES AUX
            employee_getName(auxPunteroEmpleado,nombre);
            employee_getSalary(auxPunteroEmpleado,&sueldo);
            employee_getHours(auxPunteroEmpleado,&horasTrabajadas);

            printf("\nID: %d",id); // MUESTRA LAS VARIABLES TOMADAS ANTERIORMENTE...
            printf("\nNombre: %s",nombre);
            printf("\nSueldo: %d",sueldo);
            printf("\nHoras trabajadas: %d",horasTrabajadas);
            printf("\n");
            }
            else // REPITE EL PROCEDIMIENTO ANTERIOR, PARA QUE SE PUEDA VER EN PANTALLA TODA LA LISTA!!
            {
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(auxPunteroEmpleado,&id);
            employee_getName(auxPunteroEmpleado,nombre);
            employee_getSalary(auxPunteroEmpleado,&sueldo);
            employee_getHours(auxPunteroEmpleado,&horasTrabajadas);

            printf("\nID: %d",id);
            printf("\nNombre: %s",nombre);
            printf("\nSueldo: %d",sueldo);
            printf("\nHoras trabajadas: %d",horasTrabajadas);
            printf("\n");
            }
        }
    }
    system("pause");
    return retorno;
}

/** \brief Ordenar empleados.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("Realizando reordenamiento alfabetico\n");

        if(!ll_sort(pArrayListEmployee,employee_sortByName,1)) // FUNCION SORT, ORDENA LA LISTA DE PUNTEROS!
        {
            //int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);   ESTE PARAMETRO..? int (*pFunc)(void* ,void*) = employee_sortByName

            //NO ENTIENDO QUE HACE ESTA FUNCION.......! NO LE PASA NINGUN PARAMETRO.....

            controller_ListEmployee(pArrayListEmployee);

            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo salida.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"w"); // ABRE EL ARCHIVO EN MODO ESCRITURA
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToText(pArchivo,pArrayListEmployee)) // LO PARSEA
    {
        printf("\n El grabado de datos en formato texto ha sido un exito.\n");
        retorno = 0;
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo salida.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"wb"); // ABRE EL ARCHIVO EN MODO ESCRITURA BINARIO...
    int retorno = -1;
    if(pArchivo != NULL && !parser_SaveToBinary(pArchivo,pArrayListEmployee))
    {
        printf("\n El grabado de datos en formato binario ha sido un exito.\n");
        retorno = 0;
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}

