#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validacionesinput.h"
#include "parser.h"
#include "Controller.h"




/** \brief DESPLIEGA EL SUPER MENU PRINCIPAL!
 */
int menuPrincipal ()
{
    int opciones;

    printf ("\n ------------------------MENU PRINCIPAL-------------------------------------\n");
    printf("\nSeleccione 1- ALTA DE EMPLEADOS");
    printf("\nSeleccione 2- MODIFICAR EMPLEADOS");
    printf("\nSeleccione 3- ELIMINAR EMPLEADOS");
    printf("\nSeleccione 4- LISTAR EMPLEADOS");
    printf("\nSeleccione 5- FICHAR EMPLEADOS");
    printf("\nSeleccione 6- INFORMAR EMPLEADOS PRESENTES EN FECHA INGRESADA");
    printf("\n7. Salir\n");

    utn_getNumeroAvanzada(&opciones, " \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 10,3);

    return opciones;

}



/** \brief Carga los datos de los SOCIOS DEL ARCHIVO SOCIOS
 * \param path char* ES EL NOMBRE DEL ARCHIVO PASADO DESDE EL MAIN
 * \param pArrayListEmployee LinkedList*
 * \return int 0 SI PUDO ABRIR EL ARCHIVO E INGRESAR AL PARSEO -1 SINO LO PUDO ABRIR.
 *
 */
int controller_loadFromTextSocios(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
     // HAY QUE CREAR LAS VARIABLES EMPLOYEE CON RESERVA DINAMICA DE MEMORIA SINO NO SE PUEDE GUARDAR EN NINGUN LADO ESTO...
    pFile = fopen(path,"r"); // OJOOOOOO ACA VA EL TIPO LO Q TENGO QUE HACER! ES MEJOR ABRIRLO POR CADA ITEM DE ACUERDO A LO Q TE PIDAN!!
    // O SEA SI SE PUDO ABRIR EL ARCHIVO...! SE HACE EL PARSEO!!
    if(pFile != NULL && path != NULL) // ACA HAY QUE PREGUNTAR POR LOS DOS, HAY QUE PREGUNTAR POR EL ERROR..., ACA PATH SON UNICAMENTE LOS CARACTERES, VER SI ESTA OK PREGUNTAR X NULL ACA!
    {
        parser_EmployeeFromTextSocios(pFile, pArrayListEmployee);
        return 0;
    }
    else
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO...");
        fclose(pFile);
        return -1;
    }

}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* ES EL NOMBRE DEL ARCHIVO PASADO DESDE EL MAIN
 * \param pArrayListEmployee LinkedList*
 * \return int 0 SI PUDO ABRIR EL ARCHIVO E INGRESAR AL PARSEO -1 SINO LO PUDO ABRIR.
 *
 */
int controller_loadFromTextFichajes(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
     // HAY QUE CREAR LAS VARIABLES EMPLOYEE CON RESERVA DINAMICA DE MEMORIA SINO NO SE PUEDE GUARDAR EN NINGUN LADO ESTO...
    pFile = fopen(path,"r"); // OJOOOOOO ACA VA EL TIPO LO Q TENGO QUE HACER! ES MEJOR ABRIRLO POR CADA ITEM DE ACUERDO A LO Q TE PIDAN!!
    // O SEA SI SE PUDO ABRIR EL ARCHIVO...! SE HACE EL PARSEO!!
    if(pFile != NULL && path != NULL) // ACA HAY QUE PREGUNTAR POR LOS DOS, HAY QUE PREGUNTAR POR EL ERROR..., ACA PATH SON UNICAMENTE LOS CARACTERES, VER SI ESTA OK PREGUNTAR X NULL ACA!
    {
        parser_EmployeeFromTextFichajes(pFile, pArrayListEmployee);
        return 0;
    }
    else
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO...");
        fclose(pFile);
        return -1;
    }

}



/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int respuesta, id;
    char nombre[70], apellido[70], dni[50], clave [128];

    if(pArrayListEmployee != NULL ) // ACA HAY QUE PREGUNTAR POR LOS DOS, HAY QUE PREGUNTAR POR EL ERROR...
    {
        do
        {                                           //100 POR QUE EL ID EN EL ARCHIVO DE TEXTO EMPIEZA EN EL 100....OJO!!!
            id= (ll_len(pArrayListEmployee)) + 100; // TE RETORNA EL TAMAÑO DEL LL LIST Y LE SUMAS UNO PARA QUE SE AGREGUE AL FINAL EN NUEVO ID

            utn_getCadenaDeCaracteresAvanzada( nombre, "Ingrese NOMBRE \n", "ERROR EN EL INGRESO DEL NOMBRE \n",10 );
            utn_getCadenaDeCaracteresAvanzada( apellido, "Ingrese APELLIDO \n", "ERROR EN EL INGRESO DEL APELLIDO \n",10 );


            printf("Ingrese DNI \n");
            scanf("%s", dni);
            fflush(stdin);

            utn_getAlfanumericoAvanzada( clave, "Ingrese CLAVE \n", "ERROR EN EL INGRESO DE CLAVE \n",10 );


            Employee* employeeAdd= employee_newParametrosSociosIdAutomatico(id, nombre, apellido, dni, clave); // LE PASAS LAS VARIABLES AUX PARA DAR DE ALTA EL NUEVO EMPLEADO

            ll_add(pArrayListEmployee,employeeAdd); // OJO ACA, LO INTEGRA EN LA LISTA PERO, LO GUARDA EN EL ARCHIVO?? // ACA LO PONE EN LA LISTA

            utn_getNumeroAvanzada(&respuesta, "Desea continuar ingresando los datos ?: 1 (si) / 0 (no) \n", "ERROR", 0, 1, 3);

        } while (respuesta == 1);

        return 1;
    }
    else
    {
        printf("\n ERROR PUNTEROS NULL");
        return -1;
    }

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
 {
     int retorno = -1;
     int i, id, idAux,opcion,opcionDos;
     char auxNombre[51], auxApellido[51], auxDni[31], auxClave[51];


     utn_getNumeroAvanzada(&opcion, "Desea ver la lista de empleados? ?: 1 (si) / 0 (no) \n", "ERROR", 0, 1, 3);

     if(opcion==1)
     {
         controller_ListEmployeeSocios(pArrayListEmployee);
     }

     if(pArrayListEmployee != NULL)
     {
         if(utn_getNumeroAvanzada(&id,"Ingrese el ID del empleado a modificar: ","Reingrese un numero valido", 0, 2000, 10)==1) // O SEA SI SE PUDO GUARDAR EL ID
         {
             for(i = 0;i< ll_len(pArrayListEmployee);i++)           //LO HACE DE A UNA VEZ...
             {                                                      //GUARDAS LAS DIRECCIONES DE MEMORIA EL LA VARIABLE EMPLEADO...
                Employee* empleado = ll_get(pArrayListEmployee,i); // IMPRIME LA DIRECCION DE MEMORIA QUE ALMACENA LOS DATOS CARGADOS DE LOS EMPLEADOS

                employee_getId(empleado, &idAux); // VER BIEN, ACA LE PASAS L ARRAY Y LA DIRECCION DE MEMORIA DEL ID AUX   OJOOOO VER!!!!

                if(idAux == id) // SI EL ID DE LA LISTA ES IGUAL AL QUE INGRESO EL SUJETO, EL CUAL QUIERE MODIFICAR SE EJECUTA EL PROGRAMA!
                {
                    do
                    {
                        utn_getNumeroAvanzada(&opcionDos,"QUE CAMPO DESEA MODIFICAR ??:\n 1- NOMBRE \n 2- APELLIDO \n 3- DNI \n 4- CLAVE \n 5- SALIR \n","Reingrese OPCION VALIDA", 0, 5, 10);

                        switch(opcionDos)
                        {
                            case 1: //NOMBRE

                                if(utn_getCadenaDeCaracteresAvanzada( auxNombre, "Ingrese NOMBRE \n", "ERROR EN EL INGRESO DEL NOMBRE \n",10 )==1)
                                {
                                     if(!employee_setNombre(empleado, auxNombre)) // SI EL DATO SE GUARDA OK...
                                       {
                                         retorno = 0;
                                         break;
                                       }
                                }
                            break;


                            case 2: // APELLIDO !

                               if(utn_getCadenaDeCaracteresAvanzada( auxApellido, "Ingrese APELLIDO \n", "ERROR EN EL INGRESO DEL APELLIDO \n",10 )==1)
                                {
                                     if(!employee_setApellido(empleado, auxApellido)) // SI EL DATO SE GUARDA OK...
                                       {
                                         retorno = 0;
                                         break;
                                       }
                                }

                            break;

                            case 3: // DNI !

                                printf("Ingrese DNI: \n");
                                scanf("%s", auxDni);
                                fflush(stdin);

                                if(!employee_setDni(empleado, auxDni)); // SI EL DATO SE GUARDA OK...
                               {
                                    retorno = 0;
                                    break;
                               }

                            break;

                           case 4: // CLAVE!

                           if(utn_getAlfanumericoAvanzada( auxClave, "Ingrese CLAVE \n", "ERROR EN EL INGRESO DE CLAVE \n",10 )==1)
                            {
                                 if(!employee_setClave(empleado, auxClave)) // SI EL DATO SE GUARDA OK...
                                   {
                                     retorno = 0;
                                     break;
                                   }
                            }
                        }

                    }while (opcionDos != 5);
                }
             }
         }
     }

     return retorno;
 }


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i, id, idAux;
    int opcion, opcionDos;

    do
    {
        utn_getNumeroAvanzada(&opcionDos,"\n QUE DESEA REALIZAR:\n \n 1- ELIMINAR EMPLEADO \n 2- SALIR \n ","Reingrese OPCION VALIDA", 0, 2, 10);

        switch(opcionDos)
        {
            case 1:

            utn_getNumeroAvanzada(&opcion, "Desea ver la lista de empleados? ?: 1 (si) / 0 (no) \n", "ERROR", 0, 1, 3);

            if(opcion==1)
            {
             controller_ListEmployeeSocios(pArrayListEmployee);
            }

            if(pArrayListEmployee != NULL)
            {
                if(utn_getNumeroAvanzada(&id,"Ingrese el ID del empleado a ELIMINAR: \n","Reingrese un numero valido", 0, 2000, 10)==1) // O SEA SI SE PUDO GUARDAR EL ID
                {
                     for(i = 0;i< ll_len(pArrayListEmployee);i++)           //LO HACE DE A UNA VEZ...
                     {                                                      //GUARDAS LAS DIRECCIONES DE MEMORIA EL LA VARIABLE EMPLEADO...
                        Employee* empleado = ll_get(pArrayListEmployee,i); // IMPRIME LA DIRECCION DE MEMORIA QUE ALMACENA LOS DATOS CARGADOS DE LOS EMPLEADOS

                        employee_getId(empleado, &idAux); // VER BIEN, ACA LE PASAS L ARRAY Y LA DIRECCION DE MEMORIA DEL ID AUX   OJOOOO VER!!!!

                        if(idAux == id)
                        {
                            employee_delete(empleado); // hace un free a esa direccion de memoria
                            ll_remove(pArrayListEmployee,i);

                            retorno = 0;

                            break;
                        }
                     }
                }
            }

            break;
        }

    }while (opcionDos!= 2);

    return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* ARRAY CON LISTA DE PUNTEROS...
 * \return int -1 ERROR INT 0 OK!
 *
 */
int controller_ListEmployeeSocios(LinkedList* pArrayListEmployee)
{
     int retorno = -1;
     int i;
     char nombre[128], apellido[128], dni[60], clave[128] ;
     int id ;

     Employee* auxPunteroEmpleado;

     if(pArrayListEmployee != NULL)
     {
         for(i=0;i < ll_len(pArrayListEmployee);i++)
         {
            if(i%50==0) // si pones mas de 60 te cuenta desde un id diferente de 0
            {
                system("pause"); // si no va aca y lo pones abajo, en el else imprime de a uno...

                 auxPunteroEmpleado = ll_get(pArrayListEmployee,i);// FUNCION LL_GET RECIBE LA LISTA Y EL INDICE Y DEVUELVE LO POSICION DE MEMORIA DEL EMPLEADO QUE TIENE GUARDADO, ACCEDIENDO A ESA POSICION DE MEMORIA SE IMPRIMEN LOS DATOS...

                 employee_getId(auxPunteroEmpleado,&id); // ESTAS VARIABLES ESTAN VACIAS, LAS USA COMO AUXILIARES, CUANDO SALE DE ACA TIENEN EL ID CARGADO!
                 employee_getName(auxPunteroEmpleado,nombre);
                 employee_getApellido(auxPunteroEmpleado,apellido);
                 employee_getDni(auxPunteroEmpleado,dni);
                 employee_getClave(auxPunteroEmpleado,clave);


                 printf("\nID: %d",id);
                 printf("\nNombre: %s",nombre);
                 printf("\nApellido: %s",apellido);
                 printf("\nDNI: %s",dni);
                 printf("\nCLAVE: %s",clave);
                 printf("\n");
                 retorno = 0;
            }
            else
            {
                 auxPunteroEmpleado = ll_get(pArrayListEmployee,i); // FUNCION LL_GET RECIBE LA LISTA Y EL INDICE Y DEVUELVE LO POSICION DE MEMORIA DEL EMPLEADO QUE TIENE GUARDADO

                 employee_getId(auxPunteroEmpleado,&id); // ESTAS VARIABLES ESTAN VACIAS, LAS USA COMO AUXILIARES, CUANDO SALE DE ACA TIENEN EL ID CARGADO!
                 employee_getName(auxPunteroEmpleado,nombre);
                 employee_getApellido(auxPunteroEmpleado,apellido);
                 employee_getDni(auxPunteroEmpleado,dni);
                 employee_getClave(auxPunteroEmpleado,clave);


                printf("\nID: %d",id);
                 printf("\nNombre: %s",nombre);
                 printf("\nApellido: %s",apellido);
                 printf("\nDNI: %s",dni);
                 printf("\nCLAVE: %s",clave);
                 printf("\n");

            }
         }
     }
     else
     {
        printf("\n ERROR PUNTEROS NULL");
        retorno=-1;

     }
     system("pause");

     return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* ARRAY CON LISTA DE PUNTEROS...
 * \return int -1 ERROR INT 0 OK!
 *
 */
int controller_ListFichajes(LinkedList* pArrayListEmployee)
{
     int retorno = -1;
     int i;
     char ingresoEgreso[20];
     int id, idEmpleado, minutos, hora, dia, mes, anio;

     Fichajes* auxPunteroFichajes;

     if(pArrayListEmployee != NULL)
     {
         for(i=0;i < ll_len(pArrayListEmployee);i++)
         {
            if(i%50==0) // si pones mas de 60 te cuenta desde un id diferente de 0
            {
                system("pause"); // si no va aca y lo pones abajo, en el else imprime de a uno...

                 auxPunteroFichajes = ll_get(pArrayListEmployee,i);// FUNCION LL_GET RECIBE LA LISTA Y EL INDICE Y DEVUELVE LO POSICION DE MEMORIA DEL EMPLEADO QUE TIENE GUARDADO, ACCEDIENDO A ESA POSICION DE MEMORIA SE IMPRIMEN LOS DATOS...

                 fichajes_getId(auxPunteroFichajes,&id); // ESTAS VARIABLES ESTAN VACIAS, LAS USA COMO AUXILIARES, CUANDO SALE DE ACA TIENEN EL ID CARGADO!
                 fichajes_getIdEmpleado(auxPunteroFichajes, &idEmpleado);
                 fichajes_getMinutos(auxPunteroFichajes, &minutos); // ME QUEDE ACA!!!!!!!!!!!!!!------------------------------
                 fichajes_getHora(auxPunteroFichajes, &hora);
                 fichajes_getDia(auxPunteroFichajes, &dia);
                 fichajes_getMes(auxPunteroFichajes, &mes);
                 fichajes_getAnio(auxPunteroFichajes, &anio);
                 fichajes_getIngresoEgreso(auxPunteroFichajes, ingresoEgreso);


                 printf("\nID FICHAJE: %d",id);
                 printf("\nID EMPLEADO: %d",idEmpleado);
                 printf("\n HORA: %d MINUTOS:%d - %d/%d/ %d",hora, minutos, dia, mes, anio );
                 printf("\nINGRESO O EGRESO: %s",ingresoEgreso);

                 printf("\n");
                 retorno = 0;
            }
            else
            {
                 auxPunteroFichajes = ll_get(pArrayListEmployee,i);// FUNCION LL_GET RECIBE LA LISTA Y EL INDICE Y DEVUELVE LO POSICION DE MEMORIA DEL EMPLEADO QUE TIENE GUARDADO, ACCEDIENDO A ESA POSICION DE MEMORIA SE IMPRIMEN LOS DATOS...

                 fichajes_getId(auxPunteroFichajes,&id); // ESTAS VARIABLES ESTAN VACIAS, LAS USA COMO AUXILIARES, CUANDO SALE DE ACA TIENEN EL ID CARGADO!
                 fichajes_getIdEmpleado(auxPunteroFichajes, &idEmpleado);
                 fichajes_getMinutos(auxPunteroFichajes, &minutos); // ME QUEDE ACA!!!!!!!!!!!!!!------------------------------
                 fichajes_getHora(auxPunteroFichajes, &hora);
                 fichajes_getDia(auxPunteroFichajes, &dia);
                 fichajes_getMes(auxPunteroFichajes, &mes);
                 fichajes_getAnio(auxPunteroFichajes, &anio);
                 fichajes_getIngresoEgreso(auxPunteroFichajes, ingresoEgreso);


                 printf("\nID FICHAJE: %d",id);
                 printf("\nID EMPLEADO: %d",idEmpleado);
                 printf("\n HORA: %d MINUTOS:%d - %d/%d/ %d",hora, minutos, dia, mes, anio );
                 printf("\nINGRESO O EGRESO: %s",ingresoEgreso);

                 printf("\n");

            }
         }
     }
     else
     {
        printf("\n ERROR PUNTEROS NULL");
        retorno=-1;

     }
     system("pause");

     return retorno;
}


/** \brief Ordenar empleados LFABETICAMENTE
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("\n ORDENANDO ALFABETICAMENTE, ESPERE POR FAVOR...\n");

        if(! ll_sort(pArrayListEmployee,employee_sortByName,1))
        {
            controller_ListEmployeeSocios(pArrayListEmployee);
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int -1 ERROR 0 OK
 *
 */

int controller_saveAsTextEmpleados(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
     // HAY QUE CREAR LAS VARIABLES EMPLOYEE CON RESERVA DINAMICA DE MEMORIA SINO NO SE PUEDE GUARDAR EN NINGUN LADO ESTO...
    pFile = fopen(path,"w"); // OJOOOOOO ACA VA EL TIPO LO Q TENGO QUE HACER! ES MEJOR ABRIRLO POR CADA ITEM DE ACUERDO A LO Q TE PIDAN!!
    // O SEA SI SE PUDO ABRIR EL ARCHIVO...! SE HACE EL PARSEO!!
    if(pFile != NULL && path != NULL) // ACA HAY QUE PREGUNTAR POR LOS DOS, HAY QUE PREGUNTAR POR EL ERROR...
    {
        parser_SaveToTextEmpleados(pFile, pArrayListEmployee);
        return 0;
    }
    else
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO EN MODO ESCRITURA...");
        fclose(pFile);

        return -1;
    }

}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int -1 ERROR 0 OK
 *
 */

int controller_fichajeEmpleado (LinkedList* pArrayListEmployee, LinkedList* pArrayListFichajes )
{
    int retorno = -1;
    int i, id, idAux, idFichajes, opcion, opcionDos, minutos, dia, hora, mes, anio, respuesta;
    char auxClave[51], clave[51], ingresoEgreso[51];

    if(pArrayListEmployee != NULL && pArrayListFichajes != NULL)
    {
        do
        {
            utn_getNumeroAvanzada(&opcionDos,"\n QUE DESEA REALIZAR:\n \n 1- FICHAJE EMPLEADO \n 2- SALIR \n ","Reingrese OPCION VALIDA", 0, 2, 10);

            switch(opcionDos)
            {
                case 1:

                utn_getNumeroAvanzada(&opcion, "Desea ver la lista de empleados? ?: 1 (si) / 0 (no) \n", "ERROR", 0, 1, 3);

                if(opcion==1)
                {
                 controller_ListEmployeeSocios(pArrayListEmployee);
                }


                if(utn_getNumeroAvanzada(&id,"Ingrese el ID del empleado a FICHAR: \n","Reingrese un numero valido", 0, 2000, 10)==1) // O SEA SI SE PUDO GUARDAR EL ID
                {
                     for(i = 0;i< ll_len(pArrayListEmployee);i++)           //LO HACE DE A UNA VEZ...
                     {                                                      //GUARDAS LAS DIRECCIONES DE MEMORIA EL LA VARIABLE EMPLEADO...
                        Employee* empleado = ll_get(pArrayListEmployee,i); // IMPRIME LA DIRECCION DE MEMORIA QUE ALMACENA LOS DATOS CARGADOS DE LOS EMPLEADOS

                        employee_getId(empleado, &idAux); // VER BIEN, ACA LE PASAS L ARRAY Y LA DIRECCION DE MEMORIA DEL ID AUX   OJOOOO VER!!!!

                        if(idAux == id) // ACA ENCONTRO EL ID EN LA LISTA, AHORA TIENE QUE INGRESAR LA CLAVE Y TIENE QUE ESTAR OK!
                        {
                            if(utn_getAlfanumericoAvanzada( auxClave, "Ingrese CLAVE \n", "ERROR EN EL INGRESO DE CLAVE \n",10 )==1)
                            {
                                employee_getClave(empleado, clave);

                                if( strcmp(clave, auxClave ) == 0 ) // LOS CHAR NO SE COMPARAN CON IGUAL.......WTF!------> O SEA SI SON IGUALES!
                                {
                                    do
                                    {                                           //100 POR QUE EL ID EN EL ARCHIVO DE TEXTO EMPIEZA EN EL 100....OJO!!!
                                        idFichajes= ll_len(pArrayListFichajes) +1 ; // EL ID VA A SER LA CANTIDAD DE ELEMETOS MAS UNO

                                        printf( "\n BIENVENIDOS AL SUPER MENU DE FICHAJES DE EMPLEADOS ! \n");

                                        utn_getNumeroAvanzada(&minutos,"\n INGRESE LOS MINUTOS ","Reingrese OPCION VALIDA", 0, 60, 10);


                                        utn_getNumeroAvanzada(&hora,"\n INGRESE LA HORA \n ","Reingrese OPCION VALIDA", 0, 24, 10);


                                        utn_getNumeroAvanzada(&dia,"\n INGRESE EL DIA \n ","Reingrese OPCION VALIDA", 0, 31, 10);


                                        utn_getNumeroAvanzada(&mes,"\n INGRESE EL MES \n ","Reingrese OPCION VALIDA", 0, 12, 10);


                                        utn_getNumeroAvanzada(&anio,"\n INGRESE EL ANIO \n ","Reingrese OPCION VALIDA", 2000, 3000, 10);


                                        utn_getCadenaDeCaracteresAvanzada( ingresoEgreso , "Ingrese SI EL EMPLEADO INGRESA (IN) O SI SE VA PARA CASA (OUT) \n", "ERROR EN EL INGRESO \n",10 );



                                        Fichajes* fichaje=fichajes_newParametrosFichajesDos(idFichajes, idAux, minutos, hora, dia, mes, anio, ingresoEgreso ); // USA EL MISMO ID QUE EL DE EMPLOYEE


                                        ll_add(pArrayListFichajes,fichaje); // OJO ACA, LO INTEGRA EN LA LISTA PERO, LO GUARDA EN EL ARCHIVO?? // ACA LO PONE EN LA LISTA

                                        utn_getNumeroAvanzada(&respuesta, "Desea continuar ingresando los datos ?: 1 (si) / 0 (no) \n", "ERROR", 0, 1, 3);

                                    } while (respuesta == 1);

                                        retorno=0;
                                }
                            }
                        }
                     }
                }

            break; // break del case 1
        }

        }while (opcionDos!= 2);
    }
        return retorno;
}

/** \brief Guarda los datos de los FICHAJES
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int -1 ERROR 0 OK
 *
 */

int controller_saveAsTextFichajes(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
     // HAY QUE CREAR LAS VARIABLES EMPLOYEE CON RESERVA DINAMICA DE MEMORIA SINO NO SE PUEDE GUARDAR EN NINGUN LADO ESTO...
    pFile = fopen(path,"w"); // OJOOOOOO ACA VA EL TIPO LO Q TENGO QUE HACER! ES MEJOR ABRIRLO POR CADA ITEM DE ACUERDO A LO Q TE PIDAN!!
    // O SEA SI SE PUDO ABRIR EL ARCHIVO...! SE HACE EL PARSEO!!
    if(pFile != NULL && path != NULL) // ACA HAY QUE PREGUNTAR POR LOS DOS, HAY QUE PREGUNTAR POR EL ERROR...
    {
        parser_SaveToTextFichajes(pFile, pArrayListEmployee);
        return 0;
    }
    else
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO EN MODO ESCRITURA...");
        fclose(pFile);

        return -1;
    }

}


/** \brief IMPRIME LOS EMPLEADOS EN DETERMINADA FECHA!
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int -1 ERROR 0 OK
 *
 */

int controller_printEmployeeEnFechaDeterminada ( LinkedList* listaSocios, LinkedList* listaFichajes)
{
    int retorno = -1;
    int i, j, idEmpleado, idFichajes, opcionDos, dia, mes, anio;
    int auxDia, auxMes, auxAnio;
    char nombre[128], apellido[128], dni[60], clave[128] ;

    if(listaSocios != NULL && listaFichajes != NULL)
    {
        do
        {
            utn_getNumeroAvanzada(&opcionDos,"\n QUE DESEA REALIZAR:\n \n 1- INGRESAR FECHA A BUSCAR LOS EMPLEADOS QUE TRABAJARON ESE DIA \n 2- SALIR \n ","Reingrese OPCION VALIDA", 0, 2, 10);

            switch(opcionDos)
            {
                case 1:

                    if(utn_getNumeroAvanzada(&auxDia,"Ingrese EL DIA A BUSCAR \n","Reingrese un numero valido", 0, 31, 10)==1 &&
                       utn_getNumeroAvanzada(&auxMes,"Ingrese EL MES A BUSCAR\n","Reingrese un numero valido", 0, 12, 10)==1 &&
                       utn_getNumeroAvanzada(&auxAnio,"Ingrese EL ANIO A BUSCAR \n","Reingrese un numero valido", 2000, 3000, 10)==1) // O SEA SI SE PUDO GUARDAR EL ID
                    {
                         for(i = 0;i< ll_len(listaFichajes);i++)           //LO HACE DE A UNA VEZ...
                         {                                                      //GUARDAS LAS DIRECCIONES DE MEMORIA EL LA VARIABLE EMPLEADO...
                            Fichajes* auxFichaje = ll_get(listaFichajes,i); // IMPRIME LA DIRECCION DE MEMORIA QUE ALMACENA LOS DATOS CARGADOS DE LOS EMPLEADOS

                            fichajes_getDia(auxFichaje, &dia);
                            fichajes_getMes(auxFichaje, &mes);
                            fichajes_getAnio(auxFichaje, &anio);
                            fichajes_getIdEmpleado(auxFichaje, &idFichajes); // SACAS EL ID DEL EMPLEADO PARA BUSCARLO EN LA LISTA DE EMPLEADOS!


                            if((auxDia == dia) && (auxMes==mes) && (auxAnio==anio)) // ACA ENCONTRO EL ID EN LA LISTA, AHORA TIENE QUE INGRESAR LA CLAVE Y TIENE QUE ESTAR OK!
                            {
                                for( j= 0; j< ll_len(listaSocios); j++ ) // BUSCAS EL ID DEL SOCIO Y LO IMPRIMIS
                                {
                                    Employee* auxEmployee= ll_get(listaSocios,j);

                                    employee_getId(auxEmployee, &idEmpleado); // ID TOMADA DE LOS EMPLEADOS QUE ES IGUAL AL ID EMPLEADOS DE FICHAJES
                                    employee_getName(auxEmployee,nombre);
                                    employee_getApellido(auxEmployee,apellido);
                                    employee_getDni(auxEmployee,dni);
                                    employee_getClave(auxEmployee,clave);

                                    printf("\nID: %d",idEmpleado);
                                     printf("\nNombre: %s",nombre);
                                     printf("\nApellido: %s",apellido);
                                     printf("\nDNI: %s",dni);
                                     printf("\nCLAVE: %s",clave);
                                     printf("\n");
                                     retorno = 0;

                                }
                            }
                                retorno=0;
                        }

                    }

            }
            break; // break del case 1

        }while (opcionDos!= 2);
    }
        return retorno;
}



