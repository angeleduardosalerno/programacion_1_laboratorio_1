#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
int employee_delete(Employee* this);
int employee_getNextId();
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setName(Employee* this,char* nombre);
int employee_getName(Employee* this,char* nombre);

int employee_setHours(Employee* this,int horasTrabajadas);
int employee_getHours(Employee* this,int* horasTrabajadas);


int employee_setSalary(Employee* this,int sueldo);
int employee_getSalary(Employee* this,int* sueldo);

Employee* employee_IdGen(char* nombre,int horasTrabajadas,int sueldo);
int employee_sortByName(void* thisA,void* thisB);
int employee_getAll(Employee* this,char* nombre,int* horas,int* sueldo,int* id);

#endif // employee_H_INCLUDED
