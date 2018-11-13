#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "string.h"
#include "Validaciones.h"
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


int main()
{
    int option=0;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        system("cls");
        option = menu();
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            flag = 1;
            break;

        case 2:
            controller_loadFromBinary("data.dat", listaEmpleados); // ACA CREA UN ARCHIVO DATA.DAT....VER Q ES ESTO...VER DIFERENCIAS ENTRE EL DATA.DAT Y EL DATA.CSV
            flag = 2;
            break;

        case 3:

            system("cls");
            if(flag==1) // USA LA FLAG ESTA SI CARGO EL ARCHIVO DE TEXTO...
            {
                controller_addEmployeeTxt(listaEmpleados);
            }
            else if(flag==2){
                    controller_addEmployeeBin(listaEmpleados);}
            break;

        case 4:
            system("cls");
            if(flag!=0)
            {
                controller_editEmployee(listaEmpleados);
            }
            else printf("Cargue datos primero para poder realizar la modificacion");
            break;
        case 5:
          system("cls");
            if(flag!=0)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else printf("Cargue datos primero para poder realizar la eliminacion");
            break;
        case 6:
            system("cls");
            if(flag!=0)
            {
                printf("A continuacion se imprimiran los datos en un salto de 60 empleados a la vez.\n");
                controller_ListEmployee(listaEmpleados);
            }
            else printf("Cargue datos primero para poder realizar la lista");
            break;
        case 7:
            system("cls");
            if(flag!=0)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else printf("Cargue datos primero para poder realizar el ordenamiento");
            break;
        case 8:
            system("cls");
            if(flag!=0)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                {
                    printf("Cargue datos primero para poder guardarlos");
                }
                break;
        case 9:
            system("cls");
            if(flag!=0)
                {
                    controller_saveAsBinary("data.dat",listaEmpleados);
                {
                    printf("Cargue datos primero para poder guardarlos");
                }
                break;
        case 10:
            break;
        default:
            printf("Ingrese una opcion valida \n");
            system("pause");
        }
    }
    }
    }while(option != 10);

return 0;
}
