#include <stdio.h>
#include <stdlib.h>
#include "validacionesinput.h"
#include "juegos.h"
#include "cliente.h"
#define CANT_CLIENTES 100 // CANTIDAD DE CLIENTES
#define CANT_JUEGOS 20 // CANTIDAD DE JUEGOS
#define CANT_ALQUILERES (CANT_CLIENTES * CANT_JUEGOS) // CANTIDAD DE ALQUILERES POSIBLES
#define IMPORTE_JUEGOS 5000 //VALOR MAXIMO DE LOS JUEGOS INGRESADOS

/* LOS ERRORES Q TIENE SON: 1) ARREGRAL LOS INCLUDE Y CONST EN LAS BIBLIOTECAS
2) SI LO DEJO ASI CUANDO SALE AL MENU PRINCIPAL SE BORRAN LOS ARRAYS, SE PIERDE LA INFO..
3) CUANDO INTENTO PONER EL DE ALQUILERES NO ME LEE EL TIPO CLIENTE Q ES UNA ESTRUCTURA HECHA APARTE,
AUNQUE TENGA INCLUIDAS LAS BIBLIOTECAS...NO SE COMO HACER PROBE DECLARANDO LAS VARIABLES ESTRUCTURAS EN EL MAIN Y PASARLAS COMO
PARAMETRO A CADA MENU PERO NO ANDA...

*/

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





