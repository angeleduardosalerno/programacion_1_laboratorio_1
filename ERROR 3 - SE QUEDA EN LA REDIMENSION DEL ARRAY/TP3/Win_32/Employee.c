#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "validaciones.h"

//LINKED LIST -----------------------------------------------

/** \brief Crea una estructura del tipo LinkedList e inicilizará sus campos.
* \param path char*
* \param pArrayListEmployee LinkedList*
* \return int devuelve la posicion de memoria de ll
*
*/

LinkedList* ll_newLinkedList(void) // ES IGUAL A INIT LIST !!! // SE CREA UNA LISTA EN PARTICULAR!!
{
    LinkedList* ll = (LinkedList*) malloc(sizeof(LinkedList));

    ll->index=0;
    ll->listSize=2;
    ll->lista= (Employee**)malloc(sizeof(Employee*)*ll->listSize); //OJO LA IDEA ACA ES CREAR UNA LISTA PARA LOS EMPLEADOS, POR LO QUE SE TIENE Q RESERVAR MEMORIA PARA TIPO DE DATOS EMPLOYEE

    return ll;
}


/** \brief Agrega un elemento DE LA ESTRUCTURA EMPLEADOS al final de LinkedList..
* \param LinkedList* this PUNTERO A LINKED LIST
* \param void* pElement ES EL PUNTERO A LA ESTRUCTURA DE EMPLEADOS QUE SE VA A AGREGAR A LINKEDLIST
* \return int 0 ok - 1 error
*
*/
void ll_add (LinkedList* this, Employee* pElement) // OJO ESTA MODIFICADA DEL ORIGINAL, TIPO DE DATO EMPLOYEE
{
    this->lista[this->index]=pElement; // COPIA LA DIRECCION DE MEMORIA DE LA ESTRUCTURA CREADA CON employee_newEmployee()
    this->index++;

    // si no hay mas lugar, pedimos más memoria para hacer un array DE PUNTEROS más grande

    if(this->index >= this->listSize)
    {
        printf("NO HAY MAS ESPACIO, redefinimos el array\r\n");
        this->listSize+=2;
        this->lista = (Employee**)realloc(this->lista,sizeof(Employee*)*this->listSize); // ACA EL TAMAÑO DE LA LISTA QUE AUMENTAS ES LA DE LA LISTA DE LOS PUNTEROS DENTRO DE LINKED LIST!!
    }

}

/** \brief DEVUELVE LA CANTIDAD DE ITEMS EN EL ARRAY LINKED LIST
 * \return RETORNA LA CANTIDAD DE ELEMENTOS EN EL ARRAY LINKED LIST.
 */

int ll_getSize(LinkedList* this)
{
    return this->index; // EL INDEX INCREMENTA DE ACUERDO A CUANTOS ELEMENTOS ESTEN GUARDADOS EN EL ARRAY LINKED LIST.
}

/** \brief BUSCA EL INDICE EN LINKED LIST Y DEVUELVE EL PUNTERO QUE TIENE GUARDADO DE EMPLOYEE
 * \param int i INDICE QUE SE DESEA OBTENEr
 * \return PUNTERO A ESTRUCTURA EMPLOYEE, QUE SE ENCUENTRA EN LA POSICION PASADA COMO PARAMETRO
 */

Employee* ll_get(LinkedList* this, int i)
{
    if (i < this->index)
    {
        return this->lista[i];
    }
    else
    {
        return NULL;
    }

}

/** \brief Libera LA MEMORIA PEDIDA LA LISTA DE PUNTEROS DENTRO DEL ARRAY LINKED LIST.
 * \param Person* this Puntero al empleado
 * \return void
 *
 */

void ll_free(LinkedList* this)
{
    if (this != NULL)
    {
        free(this->lista);
    }
}

/** \brief BUSCA EL INDICE EN LINKED LIST Y DEVUELVE EL PUNTERO QUE TIENE GUARDADO DE EMPLOYEE
* \param nt indexToRemove INDICE QUE SE DESEA ELIMINAR DE LA LISTA DE PUNTEROS
* \return RETORNA UN PUNTERO AL INDICE PASADO COMO PARAMETRO DE LA LISTA DENTRO DE PUNTERO EMPLOYEE.
*/

void ll_remove(LinkedList* this, int indexToRemove)
{
    int i;

    if (this != NULL)
    {
        if (this->index != 0 && indexToRemove < this->index) // NO ENTIENDO POR QUE PREGUNTAR POR EL MENOR, VER!!! OJOOOOOOOO!
        {
            for (i=indexToRemove ; i< (this->index-1) ; i++)
            {
                this->lista[i] = this->lista[i+1];
            }

            this->index--;
        }
    }
}

/** \brief IMPRIME EL CONTENIDO DEL PUNTERO A EMPLEADO PASADO COMO PARAMETRO
* \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE LA CUAL SE VA A IMPRIMIR.
* \return VOID
*
*/
void ll_printEmployee(Employee* this)
{
    printf("Nombre:%s – ID:%d - HORAS TRABAJADAS:%d - SUELDO: %d \n",this->nombre,this->id, this->horasTrabajadas, this->sueldo);
}



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

//EMPLOYEE

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
 void employee_initialize(Employee* this, char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr) // ACA LOS DATOS HAY QUE PASARSELO A LA LISTA LINKED LIST, SERIA ASI SI FUERAN LISTAS ESTATICAS DE TIPO EMPLOYEE [5]
{
    int id, horasT, sueldo;

    id = atoi(idStr);
    horasT = atoi(horasTrabajadasStr);
    sueldo=atoi(sueldoStr);
    //EL NOMBRE NO SE CONVIERTE POR QUE YA ESTA EN STR...

    //this = employee_newEmployee(); //VER SI ESTA OK ACA RESERVAS MEMORIA DINAMICA PARA CADA EMPLEADO NUEVO...

    employee_setId(this, id);
    employee_setNombre(this, nombreStr);
    employee_setHorasTrabajadas(this, horasT);
    employee_setSueldo(this, sueldo);

}



// CHEQUEAR SI HICE OK ESTA FUNCION, LE AGREGUE EL SUELDO STR COMO PARAMETRO Q ESTABA FALTANDO !!! **********ARREGLAR!!!
/** \brief RECIBE LOS DATOS DE LOS EMPLEADOS POR PARAMETROS COMO STRING, LOS CONVIERTE A SU TIPO DE DATO ESPECIFICO Y LOS GUARDA
 * \param char* idStr PARAMETROS RECIBIDOS COMO STRING
 * \param char* nombreStr PARAMETROS RECIBIDOS COMO STRING
 * \param char* horasTrabajadasStr PARAMETROS RECIBIDOS COMO STRING
 * \param char* sueldoStr PARAMETROS RECIBIDOS COMO STRING
 * \param pArrayListEmployee LinkedList*
 * \return Employee* RETORNA LA POSICION DE MEMORIA DONDE ESTAN LOS DATOS NUEVOS GUARDADOS.
 *
 */

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    //VAN TODOS LOS SET!!!


    return 0 ; // cambiar ojo

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

char* employee_getNombre(Employee* this)
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

/** \brief PIDE AL USUARIO EL INGRESO DE DATOS DE UN EMPLEADO
* \param nt indexToRemove PUNTERO A ESTRUCTURA EMPLEADOS
* \return int 0 SI OK - -1 SI se ingresa palabra "salir"
*/
int employee_enterEmployeeManual(Employee* this)  // AGREGARLE EL -1 EN CASO DE ERROR
{
    utn_getCadenaDeCaracteresAvanzada( this->nombre, "Ingrese NOMBRE \n", "ERROR EN EL INGRESO DEL NOMBRE \n",3 );
    if (strncmp(this->nombre, "salir", 5)==0)
        return 1;

    utn_getNumeroAvanzada(&this->id, "Ingrese ID \n", "ERROR EN EL INGRESO DEL ID \n", 1, 10000, 3 );
    utn_getNumeroAvanzada(&this->horasTrabajadas, "Ingrese HORAS TRABAJADAS \n", "ERROR EN EL INGRESO DE HORAS TRABAJADAS \n", 1, 10000, 3 );
    utn_getNumeroAvanzada(&this->sueldo, "Ingrese SUELDO \n", "ERROR EN EL INGRESO DEL SUELDO \n", 1, 10000, 3 );

    return 0;

}
