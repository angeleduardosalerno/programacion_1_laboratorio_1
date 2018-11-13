#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"
#include "Validaciones.h"



/** \brief Solicita espacio en memoria para un nuevo empleado.
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    if(this!=NULL)
    {
        return this;
    }
    else
    {
        return NULL;
    }
}

/**
*\brief llama al Set de datos del empleado.
*\param idStr char*
*\param nombreStr char*
*\param horasTrabajadasStr char*
*\param sueldoStr char*
*\return Employee*
*/

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
  Employee* this;
    this = employee_new();

    int idClienteInt = atoi(idStr);
    int horasTrabajadasInt = atoi(horasTrabajadasStr);
    int sueldoInt = atoi(sueldoStr);

    if(
    !employee_setId(this,idClienteInt)&&
    !employee_setName(this,nombreStr)&&
    !employee_setHours(this,horasTrabajadasInt)&&
    !employee_setSalary(this,sueldoInt))
        return this;
    employee_delete(this);
    return NULL;
}

/** \brief elimina y libera espacio del empleado que ya no se haya en uso.
 *
 * \param this Employee*
 * \return int
 *
 */
int employee_delete(Employee* this)
{
   int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

 /** \brief Generador del siguiente nro de ID.
  *
  * \return int
  *
  */
int employee_getNextId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}

/** \brief set del nombre del empleado.
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */

int employee_setName(Employee* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el nombre del empleado.
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getName(Employee* this, char* nombre)
{
   int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief set de las horas trabajadas por el empleado.
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHours(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar las horas trabajadas del empleado.
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHours(Employee* this, int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief set del sueldo del empleado.
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSalary(Employee* this, int sueldo)
{
     int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el sueldo del empleado.
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSalary(Employee* this, int* sueldo)
{
     int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief Set del ID del empleado.
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{
 int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el ID del empleado.
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this, int* id)
{
     int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id; // DICE, EL VALOR DEL ID ES EL QUE ESTA ALMACENADO EN LA ESTRUCTURA EMPLOYEE Q FUE LEIDA POR FREAD
        retorno=0;
    }
    return retorno;
}

/** \brief Generador de empleado y validador de que este no se halle vacio.
 *
 * \param nombre char*
 * \param horasTrabajadas int
 * \param sueldo int
 * \return Employee*
 *
 */
Employee* employee_IdGen(char* nombre,int horasTrabajadas,int sueldo)
{
    Employee* this;
    this = employee_new();
    if(
    !employee_setId(this,-1)&&
    !employee_setName(this,nombre)&&
    !employee_setHours(this,horasTrabajadas)&&
    !employee_setSalary(this,sueldo))
        return this;

    employee_delete(this);
    return NULL;
}

/** \brief Base a tomar para realizar un ordenamiento de empleados por nombre.
 *
 * \param thisA void*
 * \param thisB void*
 * \return int 1
 *
 */
int employee_sortByName(void* thisA,void* thisB) // FUNCION USADA PARA ORDENAR LA LISTA DE PUNTEROS, LA CUAL PIDE UNA FUNCION CON EL FORMATO int (*pFunc)(void* ,void*)
{
    int retorno = 0;
    char nameA[50];
    char nameB[50];

   employee_getName(thisA,nameA); // OBTIENE EL NOMBRE DE LA LISTA Y LO GUARDA EN LA VARIABLE AUXILIAR NAME A
   employee_getName(thisB,nameB); // OBTIENE EL NOMBRE DE LA LISTA Y LO GUARDA EN LA VARIABLE AUXILIAR NAME B

   if(strcmp(nameA,nameB)>0) // COMPARA EL NOMBRE A CON EL B, SI EL A ES MAYOR DEVUELVE 1...!!!!!
   {
    retorno = 1;
   }
   else if(strcmp(nameA,nameB)< 0)
   {
    retorno = -1;
   }
    return retorno;
}

/** \brief automatizador de datos para realizar todos los gets en una sola funcion.
 *
 * \param this Employee*
 * \param nombre char*
 * \param horas int*
 * \param sueldo int*
 * \param id int*
 * \return int
 *
 */
int employee_getAll(Employee* this,char* nombre,int* horas,int* sueldo,int* id)
{
    int retorno = -1;

    if(this != NULL)
    {
        employee_getName(this,nombre);
        employee_getHours(this,horas);
        employee_getSalary(this,sueldo);
        employee_getId(this,id);
        retorno = 0;
    }
    return retorno;
}
