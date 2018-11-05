#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"


/** \brief Crea una estructura del tipo LinkedList e inicilizará sus campos.
* \param path char*
* \param pArrayListEmployee LinkedList*
* \return int
*
*/

LinkedList* ll_newLinkedList(void)
{
    LinkedList* ll = (LinkedList*) malloc(sizeof(LinkedList));

    ll->size=2;
    ll->index=0;
//    ll->lista= (LinkedList**)malloc(sizeof(LinkedList*)*ll->size);

    return ll;
}


/** \brief Agrega un elemento DE LA ESTRUCTURA EMPLEADOS al final de LinkedList..
* \param LinkedList* this PUNTERO A LINKED LIST
* \param void* pElement ES EL PUNTERO A LA ESTRUCTURA DE EMPLEADOS QUE SE VA A AGREGAR A LINKEDLIST
* \return int 0 ok - 1 error
*
*/
int ll_add(LinkedList* this, void* pElement)
{
    if(this != NULL && pElement != NULL)
    {
//        this->lista[this->index]=pElement; // COPIA LA ESTRUCTURA DE EMPLEADOS EN LA LISTA
        this->index++;

        // si no hay mas lugar, pedimos más memoria para hacer un array más grande

        if(this->index>=this->size)
        {
            printf("no hay mas lugar, redefinimos el array\r\n");
            this->size+=10;
//            this->lista = (LinkedList**)realloc(this->lista,sizeof(LinkedList*)*this->size);
        }
        return 0;
    }
    else
    {
        return 1;
    }

}
