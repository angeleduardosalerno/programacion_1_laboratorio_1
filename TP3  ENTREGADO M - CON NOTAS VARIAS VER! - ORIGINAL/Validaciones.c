#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "Validaciones.h"
#define BUFFST 4096
#define SLEN 1000

/** \brief funcion que toma y valida un nombre ingresado.
 *
 * \param pNombre char*
 * \param limite int
 * \param msg char*
 * \param msgErr char*
 * \param reintentos int
 * \return int
 *
 */
int getName(char* pNombre, int limite, char* msg, char* msgErr, int reintentos)
{
    int retorno=-1;
    char bufferNombre[BUFFST];

    if( pNombre != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getString(bufferNombre,limite) == 0 &&
                isValidName(bufferNombre,limite))
            {
                strncpy(pNombre,bufferNombre,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

/** \brief Funcion que obtiene un texto y lo valida.
 *
 * \param pTexto char*
 * \param limite int
 * \param mensaje char*
 * \param mensajeError char*
 * \param reintentos int
 * \return int
 *
 */
int getText(char *pTexto, int limite, char *mensaje,char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[BUFFST];
    if( pTexto != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidText(buffer, limite))
            {
                strncpy(pTexto, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

/** \brief Funcion validadora de texto.
 *
 * \param pBuffer char*
 * \param limite int
 * \return int
 *
 */
int isValidText(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0)
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(!(   (pBuffer[i] >= ' ' && pBuffer[i] <= '"') ||
                     pBuffer[i] == '(' || pBuffer[i] == ')' ||
                    (pBuffer[i] >= ',' && pBuffer[i] <= '.') ||
                    (pBuffer[i] >= '0' && pBuffer[i] <= ';') ||
                    (pBuffer[i] >= '?' && pBuffer[i] <= 'Z') ||
                    (pBuffer[i] >= 'a' && pBuffer[i] <= 'z')))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief funcion que toma y valida una cadena string.
 *
 * \param pBuffer char*
 * \param limite int
 * \return int
 *
 */
int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[BUFFST];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        fflush(stdin);
        fgets(bufferStr,limite,stdin);
        fflush(stdin);
        len = strlen(bufferStr);
        if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer,bufferStr,limite);
    }
    return retorno;
}


/** \brief funcion que toma y valida un numero entero.
 *
 * \param pResultado int*
 * \param mensaje[] char
 * \param mensajeError[] char
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int
 *
 */
int getInt(int* pResultado, char mensaje[], char mensajeError[], int  minimo, int  maximo, int  reintentos)
{
    char stringIngresado[SLEN];
    int numero;
    int validado = 1;
    int hayUnMenos = 0;

    printf("%s",mensaje);

     for(int i = 0;i<reintentos;i++)
    {
        validado = 1;
        fflush(stdin);
        fgets(stringIngresado, SLEN, stdin);

        for (int j=0; j<strlen(stringIngresado)-1; j++)
        {
            if (stringIngresado[j] < '0' || stringIngresado[j] > '9')
            {
                if(j > 0 || stringIngresado[j] != 45)
                {
                    validado = 0;
                    printf("%s",mensajeError);
                    break;
                }
                hayUnMenos = 1;
            }
        }
        if(hayUnMenos == 1 && strlen(stringIngresado)-1 == 1)
        {
            validado = 0;

        }
        if (validado)
        {
            numero = atoi(stringIngresado);
            if(numero >= minimo && numero <= maximo)
            {
                *pResultado = numero;
                return 0;
            }
            if(numero < minimo || numero > maximo)
            {
                printf("%s",mensajeError);
            }
        }
    }

    return -1;
}

/** \brief validador empleado para verificar nombres.
 *
 * \param pBuffer char*
 * \param limite int
 * \return int
 *
 */
int isValidName(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if((tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z') && pBuffer[i]!= ' ')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief validador empleado para verificar numeros enteros (int).
 *
 * \param pBuffer char*
 * \return int
 *
 */
int isInt(char* pBuffer)
{
    int retorno = 0;
    int i = 0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Imprime el menu principal y toma la opcion seleccionada.
 *
 * \return int
 *
 */
int menu()
{
    int opcion;
        system ("COLOR 0A");
        system("cls");
        printf("\n         ################################################################");
        printf("\n         *                                                              *");
        printf("\n         *                 - Trabajo Practico Nro. 3 -                  *");
        printf("\n         *                                                              *");
        printf("\n         *                      >> LinkedList <<                        *");
        printf("\n         *                                                              *");
        printf("\n         *                  x Silva Chauvie Martin x                    *");
        printf("\n         *                                                              *");
        printf("\n         ################################################################");
        printf("\n         |                                                              |");
        printf("\n             1 - Carga de datos tipo texto");
        printf("\n         |                                                              |" );
        printf("\n             2 - Carga de datos tipo binario");
        printf("\n         |                                                              |" );
        printf("\n             3 - Alta de empleado");
        printf("\n         |                                                              |" );
        printf("\n             4 - Modificacion de datos de empleado");
        printf("\n         |                                                              |" );
        printf("\n             5 - Baja de empleado");
        printf("\n         |                                                              |" );
        printf("\n             6 - Listar empleados");
        printf("\n         |                                                              |" );
        printf("\n             7 - Ordenar empleados");
        printf("\n         |                                                              |" );
        printf("\n             8 - Guardar datos tipo texto");
        printf("\n         |                                                              |" );
        printf("\n             9 - Guardar datos tipo binario");
        printf("\n         |                                                              |" );
        printf("\n             10 - Salir");
        printf("\n         |                                                              |" );
        printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" );
        printf("\n");
        printf("\n          Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    return opcion;
}
