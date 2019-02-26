#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validacionesinput.h"
#include "parser.h"

/****************************************************
    Menu:
        printf ("\n ------------------------MENU PRINCIPAL-------------------------------------\n");
        printf("\nSeleccione 1- ALTA DE EMPLEADOS");
        printf("\nSeleccione 2- Para modificar los datos de un empleado");
        printf("\nSeleccione 3- Para dar de baja un empleado");
        printf("\nSeleccione 4- Para imprimir la lista de empleados");
        printf("\nSeleccione 5- Para el fichaje del empleado");
        printf("\nSeleccione 6- Para informar empleados presentes");

        7. Salir
*****************************************************/


int main()
{
    int opciones, imprimirLista;


    LinkedList* listaSocios = ll_newLinkedList(); // SE CREA UNA LISTA LINKED LIST, ASIGNANDOLE MEMORIA DINAMICAMENTE.
    LinkedList* listaFichajes = ll_newLinkedList(); // SE CREA UNA LISTA LINKED LIST, ASIGNANDOLE MEMORIA DINAMICAMENTE.

    controller_loadFromTextSocios( "socios.csv" , listaSocios );
    controller_loadFromTextFichajes( "fichajes.csv" , listaFichajes );


    do
    {
        system("cls");
        opciones=menuPrincipal();

        switch (opciones)
        {
            case 1: // 1- ALTA DE EMPLEADOS"

                controller_addEmployee(listaSocios);
                controller_saveAsTextEmpleados("socios.csv" , listaSocios); // SE GUARDA LA INFO AUTOMATICAMENTE DESPUES DE DAR DE ALTA UN EMPLEADO!
                system("pause");

            break;


            case 2: // 2- MODIFICAR EMPLEADOS"

                controller_editEmployee(listaSocios);
                controller_saveAsTextEmpleados("socios.csv" , listaSocios);
                system("pause");

            break;


            case 3: // ELIMINAR UN EMPLEADO!

                controller_removeEmployee(listaSocios);
                controller_saveAsTextEmpleados("socios.csv" , listaSocios);
                system("pause");

            break;

            case 4: // 4- Para imprimir la lista de empleados

                utn_getNumeroAvanzada(&imprimirLista, "Seleccione: \n 1-IMPRIMIR LISTA EMPLEADOS \n 2-IMPRIMIR LISTA FICHAJES \n", "ERROR EN IMPRESION", 1, 2, 6); // SE TILDABA TODO POR QUE LE FALTABA EL & A LA VARIABLE IMPRIMIR LISTA!!!!DIOOOS!

                switch (imprimirLista)
                {
                    case 1:

                        ll_sort(listaSocios, employee_sortByApellido, 1 );   // LE MANDAS LA FUNCION NOMAS!
                        controller_ListEmployeeSocios(listaSocios);
                        system("pause");

                    break;

                    case 2:

                        controller_ListFichajes(listaFichajes);
                        system("pause");

                    break;

                }

                break;

             case 5: // FICHAJE DEL EMPLEADO !

                controller_fichajeEmpleado (listaSocios, listaFichajes );
                controller_saveAsTextFichajes("fichajes.csv", listaFichajes);
                system("pause");

                //ANDA OK ME FALTA HACER EL GUARDADO DEL TEXTO DE FICHAJES Y EL ULTIMO PUNTO!

                break;

             case 6: // 6- INFORMAR EMPLEADOS PRESENTES EN FECHA INGRESADA

                controller_printEmployeeEnFechaDeterminada (listaSocios, listaFichajes);
                system("pause");

                break;
        }
    } while(opciones != 7);

    return 0;

}



