#ifndef Employee_H_INCLUDED
#define Employee_H_INCLUDED

struct S_Employee
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
};
typedef struct S_Employee Employee;

struct S_LinkedList
{
    int listSize;
    Employee** lista; // ESTA ES LA LISTA DE PUNTEROS EN LA QUE SE GUARDA EL PUNTERO A EMPLOYEE!!! ESTA ES LA LISTA PROPIAMENTE DICHA, QUE TIENE EL TAMAÑO DE EMPLOYEE
    int index;

};
typedef struct S_LinkedList LinkedList; // OJO ACA LINKED LIST ES UNA ESTRUCTURA DE TIPO S_LINKED LIST, LO MISMO EL CASO DE ARRIBA...


// LINKED LIST --------------------------------------------------------------------------------------------

LinkedList* ll_newLinkedList(void);
void ll_add(LinkedList* this, Employee* pElement);
int ll_getSize(LinkedList* this);
Employee* ll_get(LinkedList* this, int i);
void ll_free(LinkedList* this);
void ll_remove(LinkedList* this, int indexToRemove);
void ll_printEmployee(Employee* this); // PARA IMPRIMIR EL CONTENIDO DEL ARRAY ESTRUCTURA EMPLOYEE


//EMPLOYEE-------------------------------------------------------------------------------------------------

Employee* employee_newEmployee();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

void employee_initialize(Employee* this, char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr); // LA AGREGUE YO PARA EL PARSEO DE DATOS!

void employee_delete(); //FALTA HACER!

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this); // aca lo tenian definido asi, se lo saque del parametro...int employee_getId(Employee* this,int* id) el id...

int employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this); // aca lo tenian definido asi, se lo saque del parametro ***PREGUNTAR COMO HACER COMO LO QUERIAN ELLOS!

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this); // LE SAQUE EL SEGUNDO PARAMETRO EL CUAL LE PASABA EL PUNTERO A LA VARIABLE A BUSCAR

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this);

void employee_free(Employee* this); //FUNCION AGREGADA PARA LIBERAR


int employee_enterEmployeeManual(Employee* this); // CREADA POR MI POARA INGRESAR UN EMPLEADO DE FORMA MANUAL... ojoooooooooo! AGREGARLE EL RETURN EN CASO DE ERROR!

#endif // employee_H_INCLUDED
