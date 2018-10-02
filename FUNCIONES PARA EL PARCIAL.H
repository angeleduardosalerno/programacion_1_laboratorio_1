//FUNCIONES PARA EL PARCIAL.H

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;


//  PARA INPUTS DE DATOS CON VALIDACION AVANZADA:

int utn_esNumericoAvanzada (char cadena []); // CONVIERTE EN ARRAY Y LO RECORRE CARACTER POR CARACTER PARA VALIDARLO...
int utn_getIntAvanzada(int* pResultado); // PARA GUARDAR EL DATO USANDO FGETS EN VES DE SCAN F...
int utn_getNumeroAvanzada(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos); // PARA OBTENER UN NUMERO VALIDADO, INCLUYE FUNCIONES ANTERIORES...

int utn_esDecimalAvanzada (char cadena []);
int utn_getFloatAvanzada(float* pResultado);
int utn_getNumeroConDecimalesAvanzada(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_esStringAvanzada(char cadena []);
int utn_getStringAvanzada(char cadena []);
int utn_getCadenaDeCaracteresAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos);

int utn_esTelefonoAvanzada (char cadena []);
int utn_getTelefono(char cadena []);
int utn_getTelefonoAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos); //ingresar como telefono como char

int utn_esDniAvanzada (char cadena []);
int utn_getDni(char cadena []);
int utn_getDniAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos); // ingresar dni como char son 8 digitos, no acepta.

int utn_esCuilAvanzada (char cadena []);
int utn_getCuil(char cadena []);
int utn_getCuilAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos);//RECIBE EL CUIL COMO CADENA DE CARACTERES

int utn_esMailAvanzada (char cadena []);
int utn_getMail(char cadena []);
int utn_getMailAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos); //RECIBE MAIL COMO CADENA DE CARACTERES.



//FUNCIONES PROPIAS DEL TP

int initEmployees( Employee arrayEmployees [], int longitudArray);
int utn_buscarLugarVacioEpersona (Employee arrayEmployees [],int longitudArray); //ESTA OK PERO EMPROLIJAR LO DE EL RETORNO..

int addEmployee(Employee arrayEmployees [], int longitudArray, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee arrayEmployees [], int longitudArray, int id);
int removeEmployee(Employee arrayEmployees [], int longitudArray, int id);
int sortEmployees(Employee arrayEmployees [], int longitudArray, int orden); // OJO TENGO Q ARREGLAR QUE SOLO LEA LOS LUGARES EN DONDE ESTA EMPTY, PERO AL SER I Y J SE ARMA UN LIO...
int printEmployees(Employee arrayEmployees [], int longitudArray);

int printSalary(Employee arrayEmployees [], int longitudArray);

#endif