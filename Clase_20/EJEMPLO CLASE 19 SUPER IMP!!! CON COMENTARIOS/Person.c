#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"



/* static void initialize(Person* this, int age, int something); */

static void initialize(Person* this, int id, char *name, char *lastName, int age);

/** \brief  Reseva espacio en meomoria para una nueva persona y la inicializa
 *
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return Person* Retorna un puntero a la persona o NULL en caso de error
 *
 */
Person* person_new (int id, char *name, char *lastName, int age)
{
    Person* this = malloc(sizeof(Person));
    if(this != NULL)
        initialize(this, id, name, lastName, age);

    return this;
}

/*
Person* person_new (int age, int something)
{
    Person* this = malloc(sizeof(Person));
    if(this != NULL)
        initialize(this,age,something);

    return this;
}
*/

/** \brief  Inicializa a una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return void
 *
 */
static void initialize(Person* this, int id, char *name, char *lastName, int age)
{
    this->id = id;
    this->age = age;
    strcpy(this->name, name);
    strcpy(this->lastName, lastName);
    printf("INICIALIZA\n");
}

/*
static void initialize(Person* this, int age, int something)
{
    this->age = age;
    this->something = something;
}
*/

/** \brief  Setea la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \return void
 *
 */
void person_setAge(Person* this, int age)
{
    if(age > 0)
        this->age = age;
}

/** \brief  Setea la id de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \return void
 *
 */
void person_setId (Person* this, int id)
{
    //if(age > 0) ACA VAN LAS DIFERENTES VALIDACIONES SI LAS HUBIEREN
        this->id = id;
}

/** \brief Obtiene la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return int age Edad de la persona
 *
 */
int person_getAge(Person* this)
{
    return this->age;
}


/** \brief Libera el espacio ocupado por una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return void
 *
 */
void person_free(Person * this) {
    // Do any other freeing required here.
    free(this);
}

int parseData( char* fileName, Person* arrayPersonas ){
    FILE *pFile;
    int r,i=0;
    char var1[50],var3[50],var2[50],var4[50];
    int auxEdad, auxId;

    //Person arrayPersonas[10];

    pFile = fopen(fileName,"r");

    if(pFile == NULL){
        return -1;
    }
    //leo los titulos
    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4); // LECTURA EN FALSO

    do{
            //printf("LLEGA2");
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4){
            //ACA SE USA LA FUNCION INICIALIZAR, LA FUNCION INICIALIZAR TOMA COMO PARAMETROS LAS 4 VARIABLES DEL PARSEO, DENTRO DE LA FUNCION INICIALIZAR ESTAN LAS FUNCIONES SET QUE CARGAN LOS DATOS EN LA ESTRUCTURA. AL FINALIZAR LA FUNCION INICIALIZAR UNO YA TIENE LAS ESTRUCTURAS CARGADAS Q SE LEYERON DEL ARCHIVO.

            auxId=atoi(var1);
            person_setId (&arrayPersonas[i], auxId); // ESTA PARTE DE ACA SE TIENE Q SUPLANTAR POR LAS FUNCIONES SET, TIENE Q HABER UNA FUNCION SET PARA CADA DATO!!!
            strncpy(arrayPersonas[i].name,var2,sizeof(arrayPersonas[i].name)); //SE NECESITA Q LA FUNCION INICIALIZAR TOME LOS PARAMETROS QUE SE LEEN EN LOS ARCHIVOS!!!
            strncpy(arrayPersonas[i].lastName,var3,sizeof(arrayPersonas[i].lastName));
            auxEdad= atoi(var4);
            person_setAge(&arrayPersonas[i], auxEdad); // ASI TIENE QUE ESTAR, ES UN EJEMPLO OK, SE LE PASA CON EL AMPERSAD &arrayPersonas[i].age POR QUE EN ESTE EJEMPLO NO SE TRABAJA CON PUNTEROS SINO CON UN ARRAY DE ESTRUCTURAS OJO!!!
            i++;                                        //ACA LE PASAS LA DIRECCION DE MEMORIA 0 DEL ARRAY PERSONAS OJO!!!!
                                                        // LA IDEA ES QUE EL FOR TE CARGUE TODO EL ARRAY !!!
        }
        else
            break;
    }while( !feof(pFile) && i< 10 );

    fclose(pFile);

    printf("LLEGA...");

    return i;
}

/*
int parseData( char* fileName, Persona* arrayPersonas ){
    FILE *pFile;
    int r,i=0;
    char var1[50],var3[50],var2[50],var4[50];
    pFile = fopen(fileName,"r");

    if(pFile == NULL){
        return -1;
    }

    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4){
            arrayPersonas[i].id = atoi(var1);
            strncpy(arrayPersonas[i].nombre,var2,sizeof(arrayPersonas[i].nombre));
            strncpy(arrayPersonas[i].apellido,var3,sizeof(arrayPersonas[i].apellido));
            arrayPersonas[i].edad = atoi(var4);
            i++;
        }
        else
            break;
    }while( !feof(pFile) );

    fclose(pFile);

    return i;
}
*/
