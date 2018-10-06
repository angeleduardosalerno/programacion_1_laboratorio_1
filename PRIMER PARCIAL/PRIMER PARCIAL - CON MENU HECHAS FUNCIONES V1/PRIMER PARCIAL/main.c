#include <stdio.h>
#include <stdlib.h>
#include "validacionesinput.h"
#include "juegos.h"
#include "cliente.h"
#define CANT_CLIENTES 100 // CANTIDAD DE CLIENTES
#define CANT_JUEGOS 20 // CANTIDAD DE JUEGOS
#define CANT_ALQUILERES (CANT_CLIENTES * CANT_JUEGOS) // CANTIDAD DE ALQUILERES POSIBLES
#define IMPORTE_JUEGOS 5000 //VALOR MAXIMO DE LOS JUEGOS INGRESADOS



int main()
{
    int opciones;

    do
    {
        system("cls");
        utn_getNumeroAvanzada(&opciones, "\n ------MENU PRINCIPAL------\n 1. JUEGOS \n 2. CLIENTES  \n 3. ALQUILERES  \n 4. Salir. \n \n Seleccione una opcion: ",
                                        " \n Seleccione una opcion valida.", 1, 4,3);

        switch (opciones)
        {
            case 1: // MENU PRINCIPAL: JUEGOS-----

                menuJuegos(); //DENTRO DE ESTA FUNCION SE REALIZA LA LOGICA DEL CASO JUEGOS.

                break;


            case 2: // MENU PRINCIPAL: CLIENTES-----

                menuClientes(); //DENTRO DE ESTA FUNCION SE REALIZA LA LOGICA DEL CASO CLIENTES.

                break;


            case 3: // MENU PRINCIPAL: ALQUILERES-----

                menuAlquileres(); //DENTRO DE ESTA FUNCION SE REALIZA LA LOGICA DEL CASO ALQUILERES.

                break;

        }

    }while (opciones != 4); // OPCIONES MENU PRINCIPAL

    return 0;

}





