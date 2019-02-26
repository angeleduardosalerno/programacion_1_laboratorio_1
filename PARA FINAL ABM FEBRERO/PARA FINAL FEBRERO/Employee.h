#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    char dni[50];
    char clave [128];

}Employee;

typedef struct
 {
    int minutos;
    int hora;
    int dia;
    int mes;
    int anio;

 }Horario;

typedef struct
{
    int id_Fichajes;
    int id_Empleado;
    Horario horario;
    char ingresoEgreso[20];

}Fichajes;


Employee* employee_newEmployee(); // MIRAR LA DE ABAJO POR COMO UTILIZAR EL PUNTERO Q DEVUELVE, VER SI NO FUNCIONA DIRECTAMENTE!


Employee* employee_newParametrosSocios(char* idStr, char* nombreStr, char* apellidoStr, char* dniStr, char* claveStr); //FUNCION INICIALIZAR PARA USAR DENTRO DEL PARSEO DE DATOS
Employee* employee_newParametrosSociosIdAutomatico(int id, char* nombreStr, char* apellidoStr, char* dniStr, char* claveStr); // CON EL ID AGREGADO DE FORMA AUTOMATICA

Employee* employee_newParametrosAddEmployee(int id, char* nombreStr, int horasTrabajadas);



int employee_delete(Employee* this);

void employee_free(Employee* this); // PARA LIBERAR MEMORIA DE LA ESTRUCTURA EMPLOYEE

//FUNCIONES PARAMETROS PARA EL SORT!


int employee_sortByName(void* thisA,void* thisB);
int employee_sortByApellido(void* thisA,void* thisB);



//--------------------------------------------------------------

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id); // OJOOO LAS FUNCIONES GET LE PASAN COMO PARAMETRO EL PUNETO AL ID YO LA TENIA SIMPLE int employee_getId(Employee* this); OJOOO VER!

int employee_setNombre(Employee* this,char* nombre);
int employee_getName(Employee* this, char* nombre);  // OJOOO LAS FUNCIONES GET LE PASAN COMO PARAMETRO EL PUNETO AL ID YO LA TENIA SIMPLE int employee_getId(Employee* this); OJOOO VER!
//ACA RETORNAN UN ENTERO, VER SI ESTA OK POR QUE EL NOMBRE ES CHAR!!

int employee_setApellido(Employee* this, char* apellido);
int employee_getApellido(Employee* this, char* apellido);

int employee_setDni(Employee* this, char* dni);
int employee_getDni(Employee* this, char* dni);

int employee_setClave(Employee* this, char* clave);
int employee_getClave(Employee* this, char* clave);


//--------------------------------------------------------------------
//FICHAJES
Fichajes* fichajes_newFichaje ();
Fichajes* fichajes_newParametrosFichajes(char* idFichajeStr, char* idEmpleadoStr, char* minutosStr, char* horaStr, char* diaStr, char* mesStr, char* anioStr, char* ingresoEgresoStr); // USADA EN EL PARSEO
Fichajes* fichajes_newParametrosFichajesDos(int idFichajeStr, int idEmpleadoStr, int minutosStr, int horaStr, int diaStr, int mesStr, int anioStr, char* ingresoEgresoStr); // USADA EN EL INGRESO DE NUEVOS FICHAJES

int fichajes_setId( Fichajes* this, int id );
int fichajes_getId( Fichajes* this, int* id);

int fichajes_setIdEmpleado( Fichajes* this, int id);
int fichajes_getIdEmpleado( Fichajes* this, int* id);

int fichajes_setMinutos( Fichajes* this, int minutos);
int fichajes_getMinutos( Fichajes* this, int* minutos);

int fichajes_setHora( Fichajes* this, int horas);
int fichajes_getHora( Fichajes* this, int* horas);

int fichajes_setDia( Fichajes* this, int dia);
int fichajes_getDia( Fichajes* this, int* dia);

int fichajes_setMes( Fichajes* this, int mes);
int fichajes_getMes( Fichajes* this, int* mes);

int fichajes_setAnio( Fichajes* this, int anio);
int fichajes_getAnio( Fichajes* this, int* anio);

int fichajes_setIngresoEgreso( Fichajes* this, char* ingresoEgreso);
int fichajes_getIngresoEgreso( Fichajes* this, char* ingresoEgreso);

//----------------------------------------------------------------------



Employee* employee_newParametrosDos(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);

#endif // employee_H_INCLUDED
