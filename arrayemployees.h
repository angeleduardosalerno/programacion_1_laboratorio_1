#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float *salary; // OJO LE AGREGE UN PUNTERO VER SI ESTA OK, NO ME LO TOMABA LA FUNCION GETNUMEROCONDECIMALAVANZADA SINO... EL PROBLEMA ERA QUE LA FUNCION RECIBIA STRING NO NUMEROS DIRECTOS
    int *sector; // VER SI ES NUMERICO Y ENTE Q RANGOS HAY QUE VALIDAR...MAX Y MIN
    int isEmpty;

} Employee;


//  PARA INPUTS DE DATOS CON VALIDACION AVANZADA:

int utn_esNumericoAvanzada (char cadena []); // CONVIERTE EN ARRAY Y LO RECORRE CARACTER POR CARACTER PARA VALIDARLO...
int utn_getIntAvanzada(int* pResultado); // PARA GUARDAR EL DATO USANDO FGETS EN VES DE SCAN F...
int utn_getNumeroAvanzada(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos); // PARA OBTENER UN NUMERO VALIDADO, INCLUYE FUNCIONES ANTERIORES...

int utn_esDecimalAvanzada (char cadena []); // CONVIERTE EN ARRAY Y LO RECORRE CARACTER POR CARACTER PARA VALIDARLO...
int utn_getFloatAvanzada(float* pResultado); // USE ATOF PARA CONVERTIR CADENA DE CARACTERES EN FLOAT, NO SE SI ESTA OK
int utn_getNumeroConDecimalesAvanzada(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
//EL UNICO PROBLEMA ES QUE SI INGRESAS UN ENTERO LO ACEPTA IGUAL... Y NO SE COMO PONER QUE MUESTRE SOLO 2 DECIMALES...

int utn_esStringAvanzada(char cadena []);
int utn_getStringAvanzada(char cadena []);
int utn_getCadenaDeCaracteresAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos);

//FUNCIONES PROPIAS DEL TP

int utn_inicializarArrayEmployee ( Employee arrayEmployees [], int longitudArray);
int utn_buscarLugarVacioEmployee (Employee arrayEmployees [],int longitudArray, int valorBuscado); //OJO ACA USO EL -1 PARA INDICAR LUGAR VACIO*/


#endif
