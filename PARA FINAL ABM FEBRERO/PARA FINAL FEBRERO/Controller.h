int menuPrincipal ();

int controller_loadFromTextSocios(char* path, LinkedList* pArrayListEmployee);
int controller_loadFromTextFichajes(char* path, LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee); // VER COMO USO LA FUNCION GET ID Y LA COMPARACION !!!OJOOO!
int controller_removeEmployee(LinkedList* pArrayListEmployee);

int controller_ListEmployeeSocios(LinkedList* pArrayListEmployee);
int controller_ListFichajes(LinkedList* pArrayListEmployee);

int controller_sortEmployee(LinkedList* pArrayListEmployee);

int controller_saveAsTextEmpleados(char* path , LinkedList* pArrayListEmployee);

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

int controller_fichajeEmpleado (LinkedList* pArrayListEmployee, LinkedList* pArrayListFichajes );


int controller_saveAsTextFichajes(char* path , LinkedList* pArrayListEmployee);
int controller_printEmployeeEnFechaDeterminada ( LinkedList* listaSocios, LinkedList* listaFichajes);
