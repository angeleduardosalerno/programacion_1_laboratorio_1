#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, anio;
}eFecha;

typedef struct{
    long int dni;
    char nombre[31];
    char apellido[31];
    eFecha feNac;
    int idPais;
    int isEmpty;
}ePersona;

typedef struct{
    int id;
    char descripcion[31];
    int isEmpty;
}ePais;

int main()
{
    ePersona pers[] = {
                        {30000000, "Juan", "Perez", 1,1,1980,1,0},
                        {31000000, "Jose", "Araoz", 2,2,1990,3,0}
                        };
    ePais paises[]={
                    {1, "Argentina",0},
                    {2, "Peru",0},
                    {3, "Brasil",0}
                    };

    int i, j;

    for(i=0; i<2;i++){
        for(j=0; j<3; j++){
            if(pers[i].idPais == paises[j].id){
                printf("%s\t%s\n", pers[i].nombre, paises[j].descripcion);
                break;
            }
        }
    }

    return 0;
}
