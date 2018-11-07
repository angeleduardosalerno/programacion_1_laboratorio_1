#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/Cliente.h"

int compareCliente(void* pClienteA,void* pClienteB)
{
    char apellidoA[51];
    getApellido(pClienteA, apellidoA);

    char apellidoB[51];
    getApellido(pClienteB, apellidoB);

    if(strcmp(apellidoA, apellidoB) > 0)
    {
        return 1;
    }
    if(strcmp(apellidoA, apellidoB) < 0)
    {
        return -1;
    }
    return 0;
}

void printCliente(Cliente* p)
{
    char nombre[51];
    char apellido[51];
    if(p != NULL)
    {
        getNombre(p, nombre);
        getApellido(p, apellido);
        printf("ID: %d - NOMBRE: %s - APELLIDO: %s - DNI:%ld\n", p->id, nombre, apellido, p->dni);
    }
    else
    {
        printf("    Error: p = NULL\n");
    }
}

Cliente* newClienteParam(int id, char nombre[], char apellido[], long int dni)
{
    Cliente* returnAux = NULL;
    Cliente* pCliente = malloc(sizeof(Cliente));

    if(pCliente != NULL)
    {
        setIdCliente(pCliente, id);
        setNombre(pCliente, nombre);
        setApellido(pCliente, apellido);
        setDni(pCliente, dni);
        returnAux = pCliente;
    }

    return returnAux;
}

Cliente* newCliente()
{
    Cliente* returnAux = NULL;
    Cliente* pCliente = malloc(sizeof(Cliente));

    if(pCliente != NULL)
    {
        returnAux = pCliente;
    }

    return returnAux;
}


void setIdCliente(Cliente* cliente, int id)
{
    cliente->id = id;
}

void setNombre(Cliente* cliente, char nombre[])
{
    strcpy(cliente->nombre, nombre);
}

void setApellido(Cliente* cliente, char apellido[])
{
    strcpy(cliente->apellido, apellido);
}

void setDni(Cliente* cliente, long int dni)
{
    cliente->dni = dni;
}


int getIdCliente(Cliente* cliente)
{
    return cliente->id;
}

void getNombre(Cliente* cliente, char nombre[])
{
    strcpy(nombre, cliente->nombre);
}

void getApellido(Cliente* cliente, char apellido[])
{
    strcpy(apellido, cliente->apellido);
}

long int getDni(Cliente* cliente)
{
    return cliente->dni;
}
