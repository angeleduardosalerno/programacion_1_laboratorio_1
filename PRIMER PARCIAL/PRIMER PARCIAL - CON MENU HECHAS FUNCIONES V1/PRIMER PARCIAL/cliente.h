#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

 typedef struct
 {
     int codigoCliente;
     char descripcionJuego[51];
     char nombre[51];
     char apellido[51];
     char domicilio[51];
     char telefono[21];
     int isEmpty;

 } Clientes;

    int initClientes(Clientes arrayClientes [], int longitudArray);

    int utn_buscarLugarVacioClientes (Clientes arrayClientes[],int longitudArray);

    int addClientes (Clientes arrayClientes[] ,int longitudArray, int auxCodigoCliente, char auxApellidoCliente [], char auxNombreCliente[], char auxDomicilio[], char auxTelefono[]);

    int findClienteById(Clientes arrayClientes[], int longitudArray, int codigoCliente);

    int removeClientes (Clientes arrayClientes[], int longitudArray, int codigoCliente);

    int sortClientes (Clientes arrayClientes[], int longitudArray);

    int printClientes(Clientes arrayClientes[], int longitudArray);

    int checkCodigoClientes (Clientes arrayClientes[], int longitudArray, int codigoCliente);

//FUNCION GENERAL

    void menuClientes();


 #endif
