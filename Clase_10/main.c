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
}ePersona;

typedef struct{
    int id;
    char descripcion[31];
}ePais;

int main()
{
    ePersona pers[10] = {
                        {30000000, "Juan", "Perez", 1,1,1980,1},
                        {31000000, "Jose", "Araoz", 2,2,1990,3}
                        };
    ePais paises[3]={
                    {1, "Argentina"},
                    {2, "Peru"},
                    {3, "Brasil"}
                    };

    int i, j;

    for(i=0; i<2;i++){
        for(j=0; j<3; j++){
            if(pers[i].idPais == paises[j].id){
                printf("%s\t%s\n", pers[i].nombre, paises[j].descripcion);
            }
        }
    }

    return 0;
}
