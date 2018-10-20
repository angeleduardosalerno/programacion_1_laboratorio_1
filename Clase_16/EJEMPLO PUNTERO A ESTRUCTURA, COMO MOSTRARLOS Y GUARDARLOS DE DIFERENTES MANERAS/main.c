#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}EFecha;

typedef struct{
    long int dni;
    char nombre[31];
    EFecha fechaNac;
}EPersona;

int main()
{
    EPersona per, *ptrPer, pers[2], *ptrPers;
    int i;

    ptrPer = &per;

    ptrPers = pers;

    printf("\n\nESTRUCTURA SIMPLE:");

    printf("DNI: ");
    scanf("%ld", &per.dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", &per.nombre); // SIGNIFICA QUE ACEPTA TODO MENOS \N O SEA EL ENTER, ACA SE PUEDE PONER NOMBRES COMPLETOS!!

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &per.fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &per.fechaNac.mes);

    printf("\nAÑO: ");
    scanf("%d", &per.fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", per.nombre, per.dni, per.fechaNac.dia, per.fechaNac.mes, per.fechaNac.anio);


    printf("\n\nPUNTERO A ESTRUCTURA OPERADOR FLECHA:");

    printf("DNI: ");
    scanf("%ld", &ptrPer->dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL); // ES LO MISMO QUE EL FFLUSH, SE USA EN TODOS LOS SO!!
    scanf("%[^\n]", ptrPer->nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &ptrPer->fechaNac.dia); // ACA NO SE REPITE LA FLECHA, LA FLECHA SOLO SE PONE UNA VES, DEL PUNTERO AL CAMPO

    printf("\nMES: ");
    scanf("%d", &ptrPer->fechaNac.mes);

    printf("\nAÑO: ");
    scanf("%d", &ptrPer->fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", ptrPer->nombre, ptrPer->dni, ptrPer->fechaNac.dia, ptrPer->fechaNac.mes, ptrPer->fechaNac.anio);


    printf("\n\nPUNTERO A ESTRUCTURA NOTACION PUNTERO:");

    printf("DNI: ");
    scanf("%ld", &(*ptrPer).dni); // PUNTERO A ESTRUCTURA NOTACION PUNTERO!

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", (*ptrPer).nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &(*ptrPer).fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &(*ptrPer).fechaNac.mes);

    printf("\nAÑO: ");
    scanf("%d", &(*ptrPer).fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", (*ptrPer).nombre, (*ptrPer).dni, (*ptrPer).fechaNac.dia, (*ptrPer).fechaNac.mes, (*ptrPer).fechaNac.anio);

    //
    printf("\n\nPUNTERO A ARRAY DE ESTRUCTURA:");

    for(i=0; i<2; i++){
        printf("DNI: ");
        scanf("%ld", &(*(ptrPers+i)).dni); // NOMENCLATURA PUNTERO!

        printf("\nNOMBRE: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", (*(ptrPers+i)).nombre);

        printf("FECHA NACIMIENTO\n");

        printf("\nDIA: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.dia); // MISMA NOMENCLATURA QUE ARRIBA PERO EN DIA.

        printf("\nMES: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.mes);

        printf("\nAÑO: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.anio);
    }

    for(i=0; i<2; i++){
        //printf("%s - %ld - %d/%d/%d\n", (*(ptrPers+i)).nombre, (*(ptrPers+i)).dni, (*(ptrPers+i)).fechaNac.dia, (*(ptrPers+i)).fechaNac.mes, (*(ptrPers+i)).fechaNac.anio);

        printf("%s - %ld - %d/%d/%d\n", (ptrPers+i)->nombre, (ptrPers+i)->dni, (ptrPers+i)->fechaNac.dia, (ptrPers+i)->fechaNac.mes, (ptrPers+i)->fechaNac.anio);

    }

    return 0;
}
