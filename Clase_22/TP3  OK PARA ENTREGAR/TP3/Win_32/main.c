#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validacionesinput.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


//PREGUNTAS 1 , EN FUNCION PARSER EMPLOYE FROM TEXT USAR EL PUNTERO QUE DEVUELVE LA FUNCION NEW PARAMETROS O ASIGNARLA DIRECTO???
//2) "data.csv" ES UN PUNTERO A CHAR ESTO??
//3) VER COMO HACER LA FORMA COMO QUIEREN ELLOS LAS FUNCIONES GET CON LA LISTA Y EL PUNTERO A LO Q BUSCAN...
//4) SE TILDA EN EL LINKED LIST...


int main()
{
    int opciones;

    LinkedList* listaEmpleados = ll_newLinkedList(); // SE CREA UNA LISTA LINKED LIST, ASIGNANDOLE MEMORIA DINAMICAMENTE.

    do
    {
        //system("cls");
        printf ("\n ------------------------MENU PRINCIPAL-------------------------------------\n");
        printf("\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("\n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("\n 3. Alta de empleado \n ");
        printf("\n 4. Modificar datos de empleado\n ");
        printf("\n 5. Baja de empleado \n");
        printf("\n 6. Listar empleados\n");
        printf("\n 7. Ordenar empleados\n");
        printf("\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n ");
        printf("\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n ");
        printf("\n10. Salir\n");

        utn_getNumeroAvanzada(&opciones, " \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 10,3);

        switch (opciones)
        {
            case 1: // Cargar los datos de los empleados desde el archivo data.csv (modo texto).

            controller_loadFromText("data.csv",listaEmpleados);
            system("pause");


            break; // BREAK CASO 1

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;

            case 7:
            printf("caso 7");
            break;

            case 8:
            break;

            case 9:
            break;
        }
    } while(opciones != 10);

    return 0;

}





