#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validacionesinput.h"


/** \brief CREA LA ESTRUCTURA EMPLOYEE RESERVANDO MEMORIA EN FORMA DINAMICA
 * \return Employee* DEVUELVE LA DIRECCION DE MEMORIA DONDE DICHA ESTRUCTURA FUE CREADA.
 *
 */

Employee* employee_newEmployee()
{
    Employee* employee = (Employee*) malloc(sizeof(Employee)); // VER LA DIFERENCIA ENTRE EL CASTEO EL CUAL INTEGRA EL * Y EL SIZEOF Q SE HACE SIN EL *

    return employee;
}


/** \brief RECIBE LOS DATOS DE LOS EMPLEADOS POR PARAMETROS COMO STRING DESDE EL PARSEO DE DATOS, LOS CONVIERTE A SU TIPO DE DATO ESPECIFICO Y LOS GUARDA
 * \param Employee* this CADENA DEL TIPO EMPLOYEE EN DONDE SE GUARDAN LOS DATOS CONVERTIDOS.
 * \param char* idStr PARAMETROS RECIBIDOS COMO STRING
 * \param char* nombreStr PARAMETROS RECIBIDOS COMO STRING
 * \param char* horasTrabajadasStr PARAMETROS RECIBIDOS COMO STRING
 * \param char* sueldoStr PARAMETROS RECIBIDOS COMO STRING
 * \param pArrayListEmployee LinkedList*
 * \return VOID
 *
 */
 Employee* employee_newParametros(Employee* this, char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr) // ACA LOS DATOS HAY QUE PASARSELO A LA LISTA LINKED LIST, SERIA ASI SI FUERAN LISTAS ESTATICAS DE TIPO EMPLOYEE [5]
{
    int id, horasT, sueldo;

    id = atoi(idStr);
    horasT = atoi(horasTrabajadasStr);
    sueldo=atoi(sueldoStr);
    //EL NOMBRE NO SE CONVIERTE POR QUE YA ESTA EN STR...

    employee_setId(this, id);
    employee_setNombre(this, nombreStr);
    employee_setHorasTrabajadas(this, horasT);
    employee_setSueldo(this, sueldo);

    return this; // SE DEVUELVE LA DIRECCION DE MEMORIA DONDE ESTA LA ESTRUCTURA EMPLOYEE CARGADA!

}

/** \brief CARGA EL ID DEL EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \param int id ES EL ID A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */

int employee_setId(Employee* this,int id)
{
    if (this!=NULL) // LAS OTRAS VALIDACIONES NO HARIAN FALTA POR QUE ESTO LO GENERAMOS AUTOMATICAMENTE SIN INTERVENCION DEL USUARIO.
    {
        this->id=id;
        return 0;
    }
    else
    {
        printf("No se pudo asignar un ID \n");
        return 1;
    }
}

/** \brief RETORNA (LA POSICION DE MEMORIA)EL ID OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \return EL ID DEL EMPLEADO EN LA POSICION DE MEMORIA PASADA COMO PARAMETRO.
 *
 */

int employee_getId(Employee* this)
{
    return this->id;

}

/** \brief CARGA EL NOMBRE DEL EMPLEADO PASADO COMO PARAMETRO, VALIDANDO QUE SEA SOLO LETRAS.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL NOMBRE
 * \param char* nombre ES EL NOMBRE A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */

int employee_setNombre(Employee* this,char* nombre)
{
    int i=0;
    int retorno=1;

    if(this!=NULL)
    {
         while (nombre[i]!= '\0')
         {
             if ((nombre[i] < 'a' || nombre[i] > 'z') && (nombre[i]< 'A' || nombre[i]> 'Z')&& (nombre[i] != ' '))
             break;

             i++;
         }
         if(nombre[i]=='\0')
         {
             strncpy(this->nombre, nombre, sizeof(this->nombre));
             retorno=0;
         }
    }
     return retorno;
}

/** \brief RETORNA LA POSICION DE MEMORIA DEL NOMBRE OBTENIDO DE LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA LEER EL NOMBRE
 * \return char RETORNA LA POSICION DE MEMORIA DE EL NOMBRE DE LA ESTRUCTURA PASADA COMO PARAMETRO.
 *
 */

int employee_getNombre(Employee* this)   //WARDA LO Q DEVUELVE ES LA UBICACION??
{
    return this->nombre;
}


/** \brief CARGA LAS HORAS TRABAJADAS POR EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL NOMBRE
 * \param int horasTrabajadas HORAS TRABAJADAS A SER PASADAS COMO PARAMETRO SI CUMPLE LAS CONDICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */
 int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
 {
    if(this != NULL && horasTrabajadas > 0 )
    {
        this->horasTrabajadas=horasTrabajadas;
        return 0;
    }
    else
    {
        printf("No se pudo asignar LAS HORAS TRABAJADAS \n");
        return 1;
    }

 }

 /** \brief RETORNA (LA POSICION DE MEMORIA)LAS HORAS TRABAJADAS OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE VA A MOSTRAR LAS HORA TRABAJADAS
 * \return POSICION DE MEMORIA DE LAS HORAS TRABAJADAS POR EL EMPLEADO.
 *
 */

int employee_getHorasTrabajadas(Employee* this)
{
    return this->horasTrabajadas;
}

/** \brief CARGA EL SUELDO DEL EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL SUELDO
 * \param int sueldo SUELDO PASADO COMO PARAMETRO SI CUMPLE LAS CONDICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
 {
    if(this != NULL && sueldo > 0 )
    {
        this->sueldo=sueldo;
        return 0;
    }
    else
    {
        printf("No se pudo asignar EL SUELDO \n");
        return 1;
    }

 }

 /** \brief RETORNA (LA POSICION DE MEMORIA)EL SUELDO OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE VA A MOSTRAR EL SUELDO
 * \return POSICION DE MEMORIA DEL SUELDO DEL EMPLEADO
 *
 */

int employee_getSueldo(Employee* this)
{
    return this->sueldo;
}


/** \brief Libera el espacio ocupado por un empleado recibido como parametro
 * \param Person* this Puntero al empleado
 * \return void
 *
 */

void employee_free(Employee* this)
{
    if (this != NULL)
    {
        free(this);
    }
}



