#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


/** \brief CREA LA ESTRUCTURA FICHAJE RESERVANDO MEMORIA EN FORMA DINAMICA
 * \return Employee* DEVUELVE LA DIRECCION DE MEMORIA DONDE DICHA ESTRUCTURA FUE CREADA.
 *
 */

Fichajes* fichajes_newFichaje ()
{
    Fichajes* fichaje= (Fichajes*) malloc(sizeof(Fichajes)); // VER LA DIFERENCIA ENTRE EL CASTEO EL CUAL INTEGRA EL * Y EL SIZEOF Q SE HACE SIN EL *

    return fichaje;
}

/** \brief RECIBE LOS DATOS DE LOS EMPLEADOS POR PARAMETROS COMO STRING DESDE EL PARSEO DE DATOS, LOS CONVIERTE A SU TIPO DE DATO ESPECIFICO Y LOS GUARDA
* \param Employee* this CADENA DEL TIPO EMPLOYEE EN DONDE SE GUARDAN LOS DATOS CONVERTIDOS.
* \param char* idStr PARAMETROS RECIBIDOS COMO STRING
* \param char* nombreStr PARAMETROS RECIBIDOS COMO STRING
* \param char* horasTrabajadasStr PARAMETROS RECIBIDOS COMO STRING
* \param char* sueldoStr PARAMETROS RECIBIDOS COMO STRING
* \param pArrayListEmployee LinkedList*
* \return Employee* DEVUELVE LA DIRECCION DE MEMORIA DEL PUNTERO A PERSONA CARGADO, NULL SINO LO PUDO CARGAR
*
*/
Employee* employee_newParametrosSocios(char* idStr, char* nombreStr, char* apellidoStr, char* dniStr, char* claveStr) // ACA LOS DATOS HAY QUE PASARSELO A LA LISTA LINKED LIST, SERIA ASI SI FUERAN LISTAS ESTATICAS DE TIPO EMPLOYEE [5]
{
    int id;

    Employee* this = employee_newEmployee(); // SE LE ASIGNA MEMORIA DINAMICA A UN NUEVO EMPLEADO!

    if ( this != NULL)// SIEMPRE HAY QUE PREGUNTAR POR NULL YA QUE MALLOC EN LA RESERVA DE MEMORIA DINAMICA DEVUELVE NULL SI HAY ERROROR!!!
    {
        id = atoi(idStr);

        //EL NOMBRE NO SE CONVIERTE POR QUE YA ESTA EN STR...

        employee_setId(this, id);
        employee_setNombre(this, nombreStr);
        employee_setApellido(this, apellidoStr);
        employee_setDni(this, dniStr);
        employee_setClave(this, claveStr);


        return this; // SE DEVUELVE LA DIRECCION DE MEMORIA DONDE ESTA LA ESTRUCTURA EMPLOYEE CARGADA!

      }
    else
    {
        printf("ERROR, PUNTERO NULL");

        return NULL;
    }
}

/** \brief RECIBE LOS DATOS DE LOS EMPLEADOS POR PARAMETROS COMO STRING DESDE EL PARSEO DE DATOS, LOS CONVIERTE A SU TIPO DE DATO ESPECIFICO Y LOS GUARDA
* \param Employee* this CADENA DEL TIPO EMPLOYEE EN DONDE SE GUARDAN LOS DATOS CONVERTIDOS.
* \param char* idStr PARAMETROS RECIBIDOS COMO STRING
* \param char* nombreStr PARAMETROS RECIBIDOS COMO STRING
* \param char* horasTrabajadasStr PARAMETROS RECIBIDOS COMO STRING
* \param char* sueldoStr PARAMETROS RECIBIDOS COMO STRING
* \param pArrayListEmployee LinkedList*
* \return Employee* DEVUELVE LA DIRECCION DE MEMORIA DEL PUNTERO A PERSONA CARGADO, NULL SINO LO PUDO CARGAR
*
*/
Employee* employee_newParametrosSociosIdAutomatico(int id, char* nombreStr, char* apellidoStr, char* dniStr, char* claveStr) // ACA LOS DATOS HAY QUE PASARSELO A LA LISTA LINKED LIST, SERIA ASI SI FUERAN LISTAS ESTATICAS DE TIPO EMPLOYEE [5]
{

    Employee* this = employee_newEmployee(); // SE LE ASIGNA MEMORIA DINAMICA A UN NUEVO EMPLEADO!

    if ( this != NULL)// SIEMPRE HAY QUE PREGUNTAR POR NULL YA QUE MALLOC EN LA RESERVA DE MEMORIA DINAMICA DEVUELVE NULL SI HAY ERROROR!!!
    {

        employee_setId(this, id);
        employee_setNombre(this, nombreStr);
        employee_setApellido(this, apellidoStr);
        employee_setDni(this, dniStr);
        employee_setClave(this, claveStr);


        return this; // SE DEVUELVE LA DIRECCION DE MEMORIA DONDE ESTA LA ESTRUCTURA EMPLOYEE CARGADA!

      }
    else
    {
        printf("ERROR, PUNTERO NULL");

        return NULL;
    }
}

/** \brief RECIBE LOS DATOS DE LOS FICHAJES DE LOS EMPLEADOS POR PARAMETROS COMO STRING DESDE EL PARSEO DE DATOS, LOS CONVIERTE A SU TIPO DE DATO ESPECIFICO Y LOS GUARDA
* \param Employee* this CADENA DEL TIPO EMPLOYEE EN DONDE SE GUARDAN LOS DATOS CONVERTIDOS.
* \param char* idStr PARAMETROS RECIBIDOS COMO STRING
* \param char* nombreStr PARAMETROS RECIBIDOS COMO STRING
* \param char* horasTrabajadasStr PARAMETROS RECIBIDOS COMO STRING
* \param char* sueldoStr PARAMETROS RECIBIDOS COMO STRING
* \param pArrayListEmployee LinkedList*
* \return Employee* DEVUELVE LA DIRECCION DE MEMORIA DEL PUNTERO A PERSONA CARGADO, NULL SINO LO PUDO CARGAR
*
*/
Fichajes* fichajes_newParametrosFichajes(char* idFichajeStr, char* idEmpleadoStr, char* minutosStr, char* horaStr, char* diaStr, char* mesStr, char* anioStr, char* ingresoEgresoStr) // ACA LOS DATOS HAY QUE PASARSELO A LA LISTA LINKED LIST, SERIA ASI SI FUERAN LISTAS ESTATICAS DE TIPO EMPLOYEE [5]
{
    int id, idEmpleado, minutos, hora, dia, mes, anio;

    Fichajes* this= fichajes_newFichaje (); // SE LE ASIGNA MEMORIA DINAMICA A UN NUEVO FICHAJE!

    if ( this != NULL)// SIEMPRE HAY QUE PREGUNTAR POR NULL YA QUE MALLOC EN LA RESERVA DE MEMORIA DINAMICA DEVUELVE NULL SI HAY ERROROR!!!
    {
        id = atoi(idFichajeStr);
        idEmpleado=atoi(idEmpleadoStr);
        minutos = atoi(minutosStr);
        hora = atoi(horaStr);
        dia = atoi(diaStr);
        mes = atoi(mesStr);
        anio = atoi(anioStr);


        //EL NOMBRE NO SE CONVIERTE POR QUE YA ESTA EN STR...

        fichajes_setId(this, id);
        fichajes_setIdEmpleado(this, idEmpleado);

        fichajes_setMinutos(this, minutos);
        fichajes_setHora(this, hora);
        fichajes_setDia(this, dia);
        fichajes_setMes(this, mes);
        fichajes_setAnio(this, anio);
        fichajes_setIngresoEgreso(this, ingresoEgresoStr);



        return this; // SE DEVUELVE LA DIRECCION DE MEMORIA DONDE ESTA LA ESTRUCTURA EMPLOYEE CARGADA!

      }
    else
    {
        printf("ERROR, PUNTERO NULL");

        return NULL;
    }
}

/** \brief RECIBE LOS DATOS DE LOS EMPLEADOS POR PARAMETROS COMO STRING DESDE EL PARSEO DE DATOS, LOS CONVIERTE A SU TIPO DE DATO ESPECIFICO Y LOS GUARDA
* \param Employee* this CADENA DEL TIPO EMPLOYEE EN DONDE SE GUARDAN LOS DATOS CONVERTIDOS.
* \param char* idStr PARAMETROS RECIBIDOS COMO STRING
* \param char* nombreStr PARAMETROS RECIBIDOS COMO STRING
* \param char* horasTrabajadasStr PARAMETROS RECIBIDOS COMO STRING
* \param char* sueldoStr PARAMETROS RECIBIDOS COMO STRING
* \param pArrayListEmployee LinkedList*
* \return Employee* DEVUELVE LA DIRECCION DE MEMORIA DEL PUNTERO A PERSONA CARGADO, NULL SINO LO PUDO CARGAR
*
*/
Employee* employee_newParametrosAddEmployee(int id, char* nombreStr, int horasTrabajadas) // ACA LOS DATOS HAY QUE PASARSELO A LA LISTA LINKED LIST, SERIA ASI SI FUERAN LISTAS ESTATICAS DE TIPO EMPLOYEE [5]
{
    Employee* this = employee_newEmployee();

    if (this != NULL)// SIEMPRE HAY QUE PREGUNTAR POR NULL YA QUE MALLOC EN LA RESERVA DE MEMORIA DINAMICA DEVUELVE NULL SI HAY ERROROR!!!
    {
        employee_setId(this, id);
        employee_setNombre(this, nombreStr);
//        employee_setHorasTrabajadas(this, horasTrabajadas);


        return this; // SE DEVUELVE LA DIRECCION DE MEMORIA DONDE ESTA LA ESTRUCTURA EMPLOYEE CARGADA!

      }
    else
    {
        printf("ERROR, PUNTERO NULL");

        return NULL;
    }
}

/** \brief elimina y libera espacio del empleado que ya no se haya en uso.
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

/** \brief RETORNAEL ID OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \return 0 OK -1 ERROR
 *
 */

int employee_getId(Employee* this, int* id)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *id = this->id; // ACA LO QUE SE HACE ES GUARDAR EN LA VARIABLE ID PASADA COMO PARAMETRO, EL VALOR DEL ID QUE ESTA EN LA LISTA!!
        retorno=0;
    }
    return retorno;

}

/** \brief CARGA EL NOMBRE DEL EMPLEADO PASADO COMO PARAMETRO, VALIDANDO QUE SEA SOLO LETRAS.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL NOMBRE
 * \param char* nombre ES EL NOMBRE A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */

int employee_setNombre(Employee* this, char* nombre)
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

/** \brief CARGA EL APELLIDO DEL EMPLEADO PASADO COMO PARAMETRO, VALIDANDO QUE SEA SOLO LETRAS.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL NOMBRE
 * \param char* nombre ES EL NOMBRE A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */

int employee_setApellido(Employee* this, char* apellido)
{
    int i=0;
    int retorno=1;

    if(this!=NULL)
    {
         while (apellido[i]!= '\0')
         {
             if ((apellido[i] < 'a' || apellido[i] > 'z') && (apellido[i]< 'A' || apellido[i]> 'Z')&& (apellido[i] != ' '))
             break;

             i++;
         }
         if(apellido[i]=='\0')
         {
             strncpy(this->apellido, apellido, sizeof(this->apellido));
             retorno=0;
         }
    }
     return retorno;
}

/** \brief RETORNA LA POSICION DE MEMORIA DEL APELLIDO OBTENIDO DE LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA LEER EL NOMBRE
 * \return char RETORNA LA POSICION DE MEMORIA DE EL NOMBRE DE LA ESTRUCTURA PASADA COMO PARAMETRO.
 *
 */

int employee_getApellido(Employee* this, char* apellido)
{
    int retorno=-1;

    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

/** \brief CARGA EL APELLIDO DEL EMPLEADO PASADO COMO PARAMETRO, VALIDANDO QUE SEA SOLO LETRAS.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL NOMBRE
 * \param char* nombre ES EL NOMBRE A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */

int employee_setDni(Employee* this, char* dni)
{
    int i=0;
    int retorno=1;

    if(this!=NULL)
    {
         while (dni[i]!= '\0')
         {
             if (dni[i] < '0' || dni[i] > '9' )
                 break;
             i++;
         }

         if(dni[i]=='\0')
         {
             strncpy(this->dni, dni, sizeof(this->dni));
             retorno=0;
         }
    }
     return retorno;
}


/** \brief RETORNA LA POSICION DE MEMORIA DEL DNI OBTENIDO DE LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA LEER EL NOMBRE
 * \return char RETORNA LA POSICION DE MEMORIA DE EL NOMBRE DE LA ESTRUCTURA PASADA COMO PARAMETRO.
 *
 */

int employee_getDni(Employee* this, char* dni)
{
    int retorno=-1;

    if(this!=NULL && dni!=NULL)
    {
        strcpy(dni,this->dni);
        retorno=0;
    }
    return retorno;
}


/** \brief CARGA LA CLAVE DEL EMPLEADO PASADO COMO PARAMETRO, VALIDANDO QUE SEA SOLO LETRAS.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL NOMBRE
 * \param char* nombre ES EL NOMBRE A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */

int employee_setClave(Employee* this, char* clave)
{
    int i=0;
    int retorno=1;

    if(this!=NULL)
    {
         while (clave[i]!= '\0')
         {
            if ((clave[i] < 'a' || clave[i] > 'z') && (clave[i] < '0' || clave[i] > '9' ) &&(clave[i]< 'A' || clave[i]> 'Z'))
             break;

             i++;
         }
         if(clave[i]=='\0')
         {
             strncpy(this->clave, clave, sizeof(this->clave));
             retorno=0;
         }
    }
     return retorno;
}

/** \brief RETORNA LA POSICION DE MEMORIA DE LA CLAVE OBTENIDO DE LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA LEER EL NOMBRE
 * \return char RETORNA LA POSICION DE MEMORIA DE EL NOMBRE DE LA ESTRUCTURA PASADA COMO PARAMETRO.
 *
 */

int employee_getClave(Employee* this, char* clave)
{
    int retorno=-1;

    if(this!=NULL)
    {
        strcpy(clave,this->clave);
        retorno=0;
    }
    return retorno;
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

/** \brief Base a tomar para realizar un ordenamiento de empleados por nombre.
 *
 * \param thisA void* PUNTEROS VOID
 * \param thisB void* PUNTEROS VOID
 * \return 0 SINO GUARDO NADA 1 SI EL NOMBRE A ES MAS GRANDE QUE EL B Y -1 SINO LO ES
 *
 */
int employee_sortByName(void* employeeA, void* employeeB)
{
    char nameA[51];
    char nameB[51];

    if(employeeA!=NULL && employeeB!=NULL)
    {
        employee_getName(((Employee*)employeeA),nameA);
        employee_getName(((Employee*)employeeB),nameB);
    }

    return strcmp(nameA,nameB);
}

/** \brief Base a tomar para realizar un ordenamiento de empleados por APELLIDO.
 *
 * \param thisA void* PUNTEROS VOID
 * \param thisB void* PUNTEROS VOID
 * \return 0 SINO GUARDO NADA 1 SI EL NOMBRE A ES MAS GRANDE QUE EL B Y -1 SINO LO ES
 *
 */
int employee_sortByApellido(void* employeeA, void* employeeB)
{
    char apellidoA[51];
    char apellidoB[51];

    if(employeeA!= NULL && employeeB != NULL)
    {
        employee_getApellido(((Employee*)employeeA),apellidoA);
        employee_getApellido(((Employee*)employeeB),apellidoB);
    }

    return strcmp(apellidoA,apellidoB);
}


/** \brief CARGA EL ID DEL EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \param int id ES EL ID A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */

int fichajes_setId( Fichajes* this, int id )
{
    if (this!=NULL) // LAS OTRAS VALIDACIONES NO HARIAN FALTA POR QUE ESTO LO GENERAMOS AUTOMATICAMENTE SIN INTERVENCION DEL USUARIO.
    {
        this->id_Fichajes=id;
        return 0;
    }
    else
    {
        printf("No se pudo asignar un ID \n");
        return 1;
    }
}

/** \brief RETORNAEL ID OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \return 0 OK -1 ERROR
 *
 */

int fichajes_getId( Fichajes* this, int* id)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *id = this->id_Fichajes; // ACA LO QUE SE HACE ES GUARDAR EN LA VARIABLE ID PASADA COMO PARAMETRO, EL VALOR DEL ID QUE ESTA EN LA LISTA!!
        retorno=0;
    }
    return retorno;

}

/** \brief CARGA EL ID DEL EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \param int id ES EL ID A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */
int fichajes_setIdEmpleado( Fichajes* this, int id)
{
    if (this!=NULL) // LAS OTRAS VALIDACIONES NO HARIAN FALTA POR QUE ESTO LO GENERAMOS AUTOMATICAMENTE SIN INTERVENCION DEL USUARIO.
    {
        this->id_Empleado=id;
        return 0;
    }
    else
    {
        printf("No se pudo asignar un ID \n");
        return 1;
    }
}

/** \brief RETORNAEL ID OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \return 0 OK -1 ERROR
 *
 */

int fichajes_getIdEmpleado( Fichajes* this, int* id)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *id = this->id_Empleado; // ACA LO QUE SE HACE ES GUARDAR EN LA VARIABLE ID PASADA COMO PARAMETRO, EL VALOR DEL ID QUE ESTA EN LA LISTA!!
        retorno=0;
    }
    return retorno;

}

/** \brief CARGA EL ID DEL EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \param int id ES EL ID A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */
int fichajes_setMinutos( Fichajes* this, int minutos)
{
    if (this!=NULL) // LAS OTRAS VALIDACIONES NO HARIAN FALTA POR QUE ESTO LO GENERAMOS AUTOMATICAMENTE SIN INTERVENCION DEL USUARIO.
    {
        this->horario.minutos=minutos;
        return 0;
    }
    else
    {
        printf("No se pudo asignar un ID \n");
        return 1;
    }
}

/** \brief RETORNAEL ID OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \return 0 OK -1 ERROR
 *
 */

int fichajes_getMinutos( Fichajes* this, int* minutos)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *minutos = this->horario.minutos; // ACA LO QUE SE HACE ES GUARDAR EN LA VARIABLE ID PASADA COMO PARAMETRO, EL VALOR DEL ID QUE ESTA EN LA LISTA!!
        retorno=0;
    }
    return retorno;

}

/** \brief CARGA EL ID DEL EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \param int id ES EL ID A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */
int fichajes_setHora( Fichajes* this, int hora)
{
    if (this!=NULL) // LAS OTRAS VALIDACIONES NO HARIAN FALTA POR QUE ESTO LO GENERAMOS AUTOMATICAMENTE SIN INTERVENCION DEL USUARIO.
    {
        this->horario.hora=hora;
        return 0;
    }
    else
    {
        printf("No se pudo asignar un ID \n");
        return 1;
    }
}

/** \brief RETORNAEL ID OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \return 0 OK -1 ERROR
 *
 */

int fichajes_getHora( Fichajes* this, int* hora)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *hora = this->horario.hora; // ACA LO QUE SE HACE ES GUARDAR EN LA VARIABLE ID PASADA COMO PARAMETRO, EL VALOR DEL ID QUE ESTA EN LA LISTA!!
        retorno=0;
    }
    return retorno;

}

/** \brief CARGA EL ID DEL EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \param int id ES EL ID A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */
int fichajes_setDia( Fichajes* this, int dia)
{
    if (this!=NULL) // LAS OTRAS VALIDACIONES NO HARIAN FALTA POR QUE ESTO LO GENERAMOS AUTOMATICAMENTE SIN INTERVENCION DEL USUARIO.
    {
        this->horario.dia=dia;
        return 0;
    }
    else
    {
        printf("No se pudo asignar un ID \n");
        return 1;
    }
}

/** \brief RETORNAEL ID OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \return 0 OK -1 ERROR
 *
 */

int fichajes_getDia( Fichajes* this, int* dia)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *dia = this->horario.dia; // ACA LO QUE SE HACE ES GUARDAR EN LA VARIABLE ID PASADA COMO PARAMETRO, EL VALOR DEL ID QUE ESTA EN LA LISTA!!
        retorno=0;
    }
    return retorno;

}


/** \brief CARGA EL ID DEL EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \param int id ES EL ID A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */
int fichajes_setMes( Fichajes* this, int mes)
{
    if (this!=NULL) // LAS OTRAS VALIDACIONES NO HARIAN FALTA POR QUE ESTO LO GENERAMOS AUTOMATICAMENTE SIN INTERVENCION DEL USUARIO.
    {
        this->horario.mes=mes;
        return 0;
    }
    else
    {
        printf("No se pudo asignar un ID \n");
        return 1;
    }
}

/** \brief RETORNAEL ID OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \return 0 OK -1 ERROR
 *
 */

int fichajes_getMes( Fichajes* this, int* mes)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *mes = this->horario.mes; // ACA LO QUE SE HACE ES GUARDAR EN LA VARIABLE ID PASADA COMO PARAMETRO, EL VALOR DEL ID QUE ESTA EN LA LISTA!!
        retorno=0;
    }
    return retorno;

}

/** \brief CARGA EL ID DEL EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \param int id ES EL ID A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */
int fichajes_setAnio( Fichajes* this, int anio)
{
    if (this!=NULL) // LAS OTRAS VALIDACIONES NO HARIAN FALTA POR QUE ESTO LO GENERAMOS AUTOMATICAMENTE SIN INTERVENCION DEL USUARIO.
    {
        this->horario.anio=anio;
        return 0;
    }
    else
    {
        printf("No se pudo asignar un ID \n");
        return 1;
    }
}

/** \brief RETORNAEL ID OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \return 0 OK -1 ERROR
 *
 */

int fichajes_getAnio( Fichajes* this, int* anio)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *anio = this->horario.anio; // ACA LO QUE SE HACE ES GUARDAR EN LA VARIABLE ID PASADA COMO PARAMETRO, EL VALOR DEL ID QUE ESTA EN LA LISTA!!
        retorno=0;
    }
    return retorno;

}

/** \brief CARGA EL ID DEL EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \param int id ES EL ID A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */
int fichajes_setIngresoEgreso( Fichajes* this, char* ingresoEgreso)
{
    int i=0;
    int retorno=1;

    if(this!=NULL)
    {
         while (ingresoEgreso[i]!= '\0')
         {
             if ((ingresoEgreso[i] < 'a' || ingresoEgreso[i] > 'z') && (ingresoEgreso[i]< 'A' || ingresoEgreso[i]> 'Z'))
             break;

             i++;
         }
         if(ingresoEgreso[i]=='\0')
         {
             strncpy(this->ingresoEgreso, ingresoEgreso, sizeof(this->ingresoEgreso));
             retorno=0;
         }
    }
     return retorno;
}

/** \brief RETORNAEL ID OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \return 0 OK -1 ERROR
 *
 */

int fichajes_getIngresoEgreso( Fichajes* this, char* ingresoEgreso)
{
    int retorno=-1;

    if(this!=NULL && ingresoEgreso!=NULL)
    {
        strcpy(ingresoEgreso,this->ingresoEgreso);
        retorno=0;
    }
    return retorno;
}

/** \brief RECIBE LOS DATOS DE LOS FICHAJES DE LOS EMPLEADOS POR PARAMETROS COMO STRING DESDE EL PARSEO DE DATOS, LOS CONVIERTE A SU TIPO DE DATO ESPECIFICO Y LOS GUARDA
* \param Employee* this CADENA DEL TIPO EMPLOYEE EN DONDE SE GUARDAN LOS DATOS CONVERTIDOS.
* \param char* idStr PARAMETROS RECIBIDOS COMO STRING
* \param char* nombreStr PARAMETROS RECIBIDOS COMO STRING
* \param char* horasTrabajadasStr PARAMETROS RECIBIDOS COMO STRING
* \param char* sueldoStr PARAMETROS RECIBIDOS COMO STRING
* \param pArrayListEmployee LinkedList*
* \return Employee* DEVUELVE LA DIRECCION DE MEMORIA DEL PUNTERO A PERSONA CARGADO, NULL SINO LO PUDO CARGAR
*
*/
Fichajes* fichajes_newParametrosFichajesDos(int id, int idEmpleado, int minutos, int hora, int dia, int mes, int anio, char* ingresoEgresoStr) // ACA LOS DATOS HAY QUE PASARSELO A LA LISTA LINKED LIST, SERIA ASI SI FUERAN LISTAS ESTATICAS DE TIPO EMPLOYEE [5]
{
    Fichajes* this= fichajes_newFichaje (); // SE LE ASIGNA MEMORIA DINAMICA A UN NUEVO FICHAJE!

    if ( this != NULL)// SIEMPRE HAY QUE PREGUNTAR POR NULL YA QUE MALLOC EN LA RESERVA DE MEMORIA DINAMICA DEVUELVE NULL SI HAY ERROROR!!!
    {

        //EL NOMBRE NO SE CONVIERTE POR QUE YA ESTA EN STR...

        fichajes_setId(this, id);
        fichajes_setIdEmpleado(this, idEmpleado);

        fichajes_setMinutos(this, minutos);
        fichajes_setHora(this, hora);
        fichajes_setDia(this, dia);
        fichajes_setMes(this, mes);
        fichajes_setAnio(this, anio);
        fichajes_setIngresoEgreso(this, ingresoEgresoStr);



        return this; // SE DEVUELVE LA DIRECCION DE MEMORIA DONDE ESTA LA ESTRUCTURA EMPLOYEE CARGADA!

      }
    else
    {
        printf("ERROR, PUNTERO NULL");

        return NULL;
    }
}
