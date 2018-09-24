#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arrayemployees.h"
#define CANTEMPLOYEES 3 // DESPUES DE LA PRUEBA PONER LOS 1000 Q CORRESPONDEN!
#define MINSALARY 1
#define MAXSALARY 100000



/** \brief Verifica si el valor recibido es numerico.
* \param char cadena de caracteres a ser analizada.
* \return Devuelve 1 si es numerico y 0 si no lo es.
*
*/
int utn_esNumericoAvanzada (char cadena [])
{
    int i=0;
    int retorno = 0;

    if(cadena!=NULL)
    {
        while (cadena[i]!= '\0')
        {
            if (cadena[i] < '0' || cadena[i] > '9' )
                break;
            i++;
        }
        if(cadena[i]=='\0')
        retorno=1;
    }
    return retorno;
}

/** \brief Almacena el numero ingresado (usando fgets en lugar de scanf)  luego de validar el dato como cadena de caracteres.
* \param int* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
*
*/
int utn_getIntAvanzada(int* pResultado)
{
    int retorno = 0;
    char buffer[10];

    if(pResultado!=NULL)
    {

        fgets(buffer,sizeof(buffer),stdin);
        buffer[strlen(buffer)-1]='\0';

        if(utn_esNumericoAvanzada(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 1;
        }
    }
        return retorno;
}

/** \brief Almacena el numero ingresado, luego de validar el dato.
* \param int* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \param char* mensaje Mensaje a ser mostrado al usuario para que determine que dato desee ingresar.
* \param char* mensajeError Mensaje a ser mostrado al usuario en caso de no ingresar un dato valido.
* \param int minimo Numero minimo valido para ingresar.
* \param int maximo Numero maximo valido para ingresar.
* \param int reintentos Reintentos brindados al usuario en caso de ingresar datos invalidos.
* \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
*
*/

int utn_getNumeroAvanzada(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno;
    int numero;

        if (pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
        {
            while(reintentos>0)
            {
                printf("%s", mensaje);

                if(utn_getIntAvanzada(&numero)==1)
                {
                    if(numero<=maximo && numero>=minimo)
                    break;
                }
                reintentos--;
                printf("%s", mensajeError);
            }
            if(reintentos==0)
            {
                retorno=0;
            }
            else
            {
                retorno=1;
                *pResultado = numero;
            }
        }
            return retorno;
}

/** \brief Verifica si el valor recibido es decimal.
* \param char cadena de caracteres a ser analizada.
* \return Devuelve 1 si es decimal y 0 si no lo es.
*
*/
int utn_esDecimalAvanzada(char cadena [])
{
    int i=0;
    int retorno = 0;
    int contadorPuntos=0;

    if(cadena!=NULL)
    {
        while (cadena[i]!= '\0')
        {
            if (cadena[i] == '.')
            {
                contadorPuntos++;
            }

            if ((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.') && (contadorPuntos != 1))
                break;
            i++;
        }
        if(cadena[i]=='\0')
        retorno=1;
    }
    return retorno;
}

/** \brief Almacena el numero decimal ingresado (usando fgets en lugar de scanf)  luego de validar el dato como cadena de caracteres.
* \param float* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
*
*/
int utn_getFloatAvanzada(float* pResultado)
{
    int retorno = 0;
    char buffer[16];

    if(pResultado!=NULL)
    {

        fgets(buffer,sizeof(buffer),stdin);
        buffer[strlen(buffer)-1]='\0';

        if(utn_esDecimalAvanzada(buffer))
        {
            *pResultado = atof(buffer); // VER SI ATOF ESTA OK
            retorno = 1;
        }
    }
        return retorno;
}

/** \brief Almacena el numero con decimal ingresado, luego de validar el dato.
* \param float* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \param char* mensaje Mensaje a ser mostrado al usuario para que determine que dato desee ingresar.
* \param char* mensajeError Mensaje a ser mostrado al usuario en caso de no ingresar un dato valido.
* \param int minimo Numero minimo valido para ingresar.
* \param int maximo Numero maximo valido para ingresar.
* \param int reintentos Reintentos brindados al usuario en caso de ingresar datos invalidos.
* \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
*
*/

int utn_getNumeroConDecimalesAvanzada(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno;
    float numero;

        if (pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
        {
            while(reintentos>0)
            {
                printf("%s", mensaje);

                if(utn_getFloatAvanzada(&numero)==1)
                {
                    if(numero<=maximo && numero>=minimo)
                    break;
                }
                reintentos--;
                printf("%s", mensajeError);
            }
            if(reintentos==0)
            {
                retorno=0;
            }
            else
            {
                retorno=1;
                *pResultado = numero;
            }
        }
            return retorno;
}



/** \brief Valida que la cadena de caracteres ingresada posea solo letras y espacios vacios.
* \param char cadena Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \return Devuelve 1 si pudo guardar el dato en char cadena y 0 si no lo pudo guardar por no pasar la validacion.
*
*/

int utn_esStringAvanzada(char cadena [])
{
    int i=0;
    int retorno=0;

    if(cadena!=NULL)
    {
        while (cadena[i]!= '\0')
        {
            if ((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i]< 'A' || cadena[i]> 'Z')&& (cadena[i] != ' '))
            break;

            i++;
        }
        if(cadena[i]=='\0')
        retorno=1;
    }
    return retorno;
}

/** \brief Almacena la cadena de caracteres ingresada y la devuelve.
* \param char cadena Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \return Devuelve 1 si pudo guardar el dato en char cadena y 0 si no lo pudo guardar por no pasar la validacion.
*
*/
int utn_getStringAvanzada(char cadena [])
{
    int retorno = 0;
    char buffer[52];

    if(cadena!=NULL)
    {

        fgets(buffer,sizeof(buffer),stdin);
        buffer[strlen(buffer)-1]='\0';

        if(utn_esStringAvanzada(buffer))
        {
            strcpy( cadena, buffer);
            retorno = 1;
        }
    }
        return retorno;
}

/** \brief Obtiene una cadena de caracteres y la valida. (solo letras y espacios vacios).
* \param char cadena Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \param char* mensaje Mensaje a ser mostrado al usuario para que determine que dato desee ingresar.
* \param char* mensajeError Mensaje a ser mostrado al usuario en caso de no ingresar un dato valido.
* \param int reintentos Reintentos brindados al usuario en caso de ingresar datos invalidos.
* \return Devuelve 1 si pudo guardar el dato en char cadena y 0 si no lo pudo guardar por no pasar la validacion.
*
*/

int utn_getCadenaDeCaracteresAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos)
{
    int retorno;
    char texto [52];

        if (cadena!= NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
        {
            while(reintentos>0)
            {
                printf("%s", mensaje);

                if(utn_getStringAvanzada(texto))
                    break;

                reintentos--;
                printf("%s", mensajeError);
            }
            if(reintentos==0)
            {
                retorno=0;
            }
            else
            {
                strcpy(cadena, texto );
                retorno=1;
            }
        }
            return retorno;
}
// FUNCIONES PROPIAS DEL TP

/**\brief Para indicar que todas las posiciones del array employee estan vacias, esta funcion pone la bandera isEmpty de la estructura en 1 (TRUE).
* \param Employee arrayEmployees Es el array de tipo de dato estructura a ser inicializado.
*\param int longitudArray Es la cantidad de elementos del array.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int utn_inicializarArrayEmployee (Employee arrayEmployees [], int longitudArray)
{
    int i, retorno = -1;

    if (arrayEmployees!= NULL && longitudArray > 0)
    {
        for (i=0; i< longitudArray; i++)
    {
        arrayEmployees[i].isEmpty = 1;
    }
        retorno=0;
    }
    return retorno;

}

/**\brief Busca el primer lugar vacio en un array estructura de Personas, buscandolo en el legajo.
* \param ePersona arrayPersonas Es el array de tipo de dato estructura en donde se busca el dato.
*\param int longitudArray Es la cantidad de elementos del array de enteros.
*\param int valorBuscado Es el numero que se va a buscar en el array. Tener en cuenta que anteriormente debio ser inicializado y cargado ej -1.Le podes dar directamente tambien una cadena aux con un dato guardado
* \return Devuelve el subindice vacio en el array (i) o -1 en caso de no haber lugar vacio. // OJO ACA USO EL -1 PARA INDICAR LUGAR VACIO
*
*/

/*int utn_buscarLugarVacioEmployee (Employee arrayEmployees [],int longitudArray, int valorBuscado)
{
    int i;

    for (i=0; i< longitudArray ; i++)
    {
        if ( arrayEmployees[i].legajo == valorBuscado)
        {
            return i;
        }
    }
        return -1;
}*/

/** \brief Agrega en un array de empleados existente, los valores recibidos como parámetro, en la primer posición libre encontrada.
* \param Employee arrayEmployees [] Array de  empleados donde se cargan los datos ingresador
* \param int longitudArray longitud del array de empleados.
* \param id int // no va se calcula automaticamente....x funcion random
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok --- or without free space...ver!
*/

int addEmployee(Employee arrayEmployees [], int longitudArray, char name[],char lastName[],float salary,int sector)
{
      int i;

    if (arrayEmployees!= NULL && longitudArray > 0) //VER PARA AGREGAR SI NO HAY ESPACIO VACIO...
    {
        for (i=0; i< longitudArray ; i++)
        {
            if (arrayEmployees[i].isEmpty == 1)
            {
                srand(time(NULL)); // VER SI ACA ESTA OK...

                for (i=0; i< longitudArray ; i++) // VER SI ESTA OK ACA...
                {
                    arrayEmployees[i].id=  1 + rand() % (CANTEMPLOYEES -1 + 1); // SE CALCULA EL ID CON UN NUMERO RANDOM del 1 -a CANTEMPLOYEE
    //VER SI HAY QUE USAR EL RETORNO DE LAS FUNCIONES DE ALGUNA FORMA! ----------VER SI ESTA OK---------

                    if (! (utn_getCadenaDeCaracteresAvanzada( arrayEmployees[i].name, "\n Ingrese su nombre: ", "\n El nombre ingresado no es valido. ", 3 )))
                    {
                        printf("El nombre ingresado no es valido, debe estar compuesto solo por letras...");
                        break;
                    }

                    if (! (utn_getCadenaDeCaracteresAvanzada( arrayEmployees[i].lastName, "\n Ingrese su apellido: ", "\n El apellido ingresado no es valido. ", 3 )))
                    {
                        printf("El apellido ingresado no es valido, debe estar compuesto solo por letras...");
                        break;
                    }

                    if (! (utn_getNumeroConDecimalesAvanzada( arrayEmployees[i].salary, "\n Ingrese salario: ", "\n El salario ingresado no es valido. ", MINSALARY , MAXSALARY, 3  )))
                    {
                        printf("El salario debe ser numerico...");
                        break;
                    }

                    if (! (utn_getNumeroAvanzada( arrayEmployees[i].sector, "\n Ingrese sector: ", "\n El sector ingresado no es valido. ", 1 , 20, 3 ))) // VER SI EL SECTOR ES OK NUMERICO OJO VER SI HAY QUE HACER UN PUNTERO A SECTOR COMO LO ANTERIOR
                    {
                        printf("El sector debe ser numerico...");
                        break;
                    }



                }
                return i;
            }
            return 0;



        }



    }
}
