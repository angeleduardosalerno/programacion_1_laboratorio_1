#include "inc/funciones.h"
#include "inc/Cliente.h"
#include "inc/ArrayList.h"
#include "Cliente.c"
#include "Venta.c"
#include <string.h>

void cargarClientes(ArrayList* clientes)
{
    if(clientes != NULL)
    {
        FILE * pArchivo;
        pArchivo = fopen("clientes.txt","r");

        if(pArchivo != NULL)
        {
            int id = 0;
            char nombre[51];
            char apellido[51];
            long int dni;
            char dniAux[51];

            Cliente* clienteAux = newCliente();

            if(clienteAux != NULL)
            {
                int flag = 0;

                fscanf(pArchivo, "%[^,],%[^,],%[^\n]\n", nombre, apellido, dniAux);
                while(!feof(pArchivo))
                {
                    fscanf(pArchivo, "%[^,],%[^,],%[^\n]\n", nombre, apellido, dniAux);

                    dni = atoi(dniAux);

                    if(!(buscarClientePorDni(clientes, dni)))
                    {
                        id = idDisponibleClientes(clientes); // La función retorna el siguiente id disponible del ArrayList de clientes, evita repeticiones de id.

                        setIdCliente(clienteAux, id);
                        setNombre(clienteAux, nombre);
                        setApellido(clienteAux, apellido);
                        setDni(clienteAux, dni);

                        if(!clientes->add(clientes, clienteAux))
                        {
                            flag = 1;
                            clienteAux = newCliente();
                        }
                    }
                    else
                    {
                        printf("    Error: Ya hay un cliente con el DNI %ld\n", dni);
                    }

                }
                fclose(pArchivo);

                if(flag)
                {
                    printf("Cliente/s cagado/s desde \"clientes.txt\".\n");
                }
            }
            else
            {
                printf("    Error: clienteAux = NULL.\n");
            }
        }
        else
        {
            printf("    Error: No se pudo abrir el archivo.\n");
        }
    }
    else
    {
        printf("    Error: clientes = NULL.\n");
    }
}

void cargarVentas(ArrayList* ventas)
{
    if(ventas != NULL)
    {
        FILE * pArchivo;
        pArchivo = fopen("ventas.txt","r");

        if(pArchivo != NULL)
        {
            int id = 0;
            char codigoDeProducto[51];
            int idCliente;
            char idClienteAux[51];
            int cantidad;
            char cantidadAux[51];
            float costoUnitario;
            char costoUnitarioAux[51];
            char fecha[51];

            Venta* ventaAux = newVenta();

            if(ventaAux != NULL)
            {
                int flag = 0;

                fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idClienteAux, codigoDeProducto, costoUnitarioAux, cantidadAux, fecha);
                while(!feof(pArchivo))
                {
                    fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idClienteAux, codigoDeProducto, costoUnitarioAux, cantidadAux, fecha);

                    idCliente = atoi(idClienteAux);
                    costoUnitario = atof(costoUnitarioAux);
                    cantidad = atoi(cantidadAux);

                    if(!(buscarVentaPorId(ventas, id)))
                    {
                        id = idDisponibleVentas(ventas); // La función retorna el siguiente id disponible del ArrayList de ventas, evita repeticiones de id.

                        setIdCliente(ventaAux, id);
                        setIdCliente(ventaAux, idCliente);
                        setCodigoDeProducto(ventaAux, codigoDeProducto);
                        setCostoUnitario(ventaAux, costoUnitario);
                        setCantidad(ventaAux, cantidad);
                        setFecha(ventaAux, fecha);

                        if(!ventas->add(ventas, ventaAux))
                        {
                            flag = 1;
                            ventaAux = newVenta();
                        }
                    }
                    else
                    {
                        printf("    Error: Ya hay una venta con el ID %d\n", id);
                    }

                }
                fclose(pArchivo);

                if(flag)
                {
                    printf("Venta/s cagado/s desde \"ventas.txt\".\n");
                }
            }
            else
            {
                printf("    Error: ventaAux = NULL.\n");
            }
        }
        else
        {
            printf("    Error: No se pudo abrir el archivo.\n");
        }
    }
    else
    {
        printf("    Error: ventas = NULL.\n");
    }
}

void agregarCliente(ArrayList* clientes)
{
    if(clientes != NULL)
    {
        char nombre[51];
        char apellido[51];

        pedirNombre(nombre);
        pedirApellido(apellido);
        long int dni = pedirDni();

        int id = idDisponibleClientes(clientes); // La función retorna el menor id disponible del ArrayList, evita repeticiones de id.

        Cliente* cliente = newCliente();

        if(cliente != NULL)
        {
            setIdCliente(cliente, id);
            setNombre(cliente, nombre);
            setApellido(cliente, apellido);
            setDni(cliente, dni);

            if(clientes->add(clientes, cliente))
            {
                printf("    Error: No se guardo el cliente.\n");
            }
            else
            {
                printf("Cliente guardado en memoria RAM.\n");

                printCliente(cliente);
            }
        }
        else
        {
            printf("    Error: cliente = NULL.\n");
        }

    }
    else
    {
        printf("    Error: ArrayList clientes = NULL.\n");
    }
}

void modificarCliente(ArrayList* clientes)
{
    if(clientes != NULL)
    {
        char nombre[51];
        char apellido[51];

        int id = pedirIdCliente();

        Cliente* cliente = buscarClientePorId(clientes, id); // Retorna el cliente que tiene el id indicado, retorna NULL si no lo encuentra.

        if(cliente != NULL)
        {
            pedirNombre(nombre);
            pedirApellido(apellido);
            int dni = pedirDni();

            setNombre(cliente, nombre);
            setApellido(cliente, apellido);
            setDni(cliente, dni);

            guardarClientePorId(clientes, cliente, id); // Sobreescribe el cliente que tiene el id indicado.

            //guardarClienteEnArchivo(cliente);
        }
        else
        {
            printf("    Error: cliente = NULL.\n");
        }
    }
    else
    {
        printf("    Error: ArrayList clientes = NULL.\n");
    }
}

void eliminarCliente(ArrayList* clientes, ArrayList* ventas)
{
    if(clientes != NULL)
    {
        int idCliente = pedirIdCliente(); // Pide el id y verifica que sea >= 0.

        Cliente* cliente = buscarClientePorId(clientes, idCliente); // Retorna el cliente que tiene el id indicado, retorna NULL si no lo encuentra.

        if(cliente != NULL)
        {
            if(buscarClienteEnVentas(ventas, idCliente))
            {
                printf("    Error: Hay alguna venta asociada al cliente, no se puede eliminar el cliente.\n");
            }
            else
            {
                if(eliminarClientePorId(clientes, idCliente)) // Elimina el cliente que tiene ese id.
                {
                    printf("Cliente eliminado de la memoria RAM.\n");
                }
                else
                {
                    printf("    Error: No se pudo eliminar el cliente.\n");
                }
            }
        }
        else
        {
            printf("    Error: cliente = NULL.\n");
        }

    }
    else
    {
        printf("    Error: ArrayList clientes = NULL.\n");
    }
}

void mostrarClientes(ArrayList* clientes)
{
    if(clientes->len(clientes) > 0)
    {
        ArrayList* clientesAux = clientes->clone(clientes); // Se crea un ArrayList auxiliar.
        clientesAux->sort(clientesAux, compareCliente, 1); // Se ordena el ArrayList auxiliar.

        if(clientesAux != NULL)
        {
            int i=0;
            for(i=0;i<clientesAux->len(clientesAux);i++) // Recorre todo el ArrayList auxiliar.
            {
                printCliente(clientesAux->get(clientesAux,i));
            }
        }
        else
        {
            printf("    Error: No se pudo crear el ArrayList auxiliar.\n");
        }
    }
    else
    {
        printf("    Error: No hay clientes en el ArrayList.\n");
    }
}

void importarClientes(ArrayList* clientes)
{
    if(clientes != NULL)
    {
        char pathArchivo[51];
        pedirPathArchivo(pathArchivo); // Faltan verificaciones en esta función.

        FILE * pArchivo;
        pArchivo = fopen(pathArchivo,"r");

        if(pArchivo != NULL)
        {
            int id;
            char nombre[51];
            char apellido[51];
            long int dni;
            char dniAux[51];

            Cliente* clienteAux = newCliente();

            fscanf(pArchivo, "%[^,],%[^,],%[^\n]\n", nombre, apellido, dniAux);
            while(!feof(pArchivo))
            {
                fscanf(pArchivo, "%[^,],%[^,],%[^\n]\n", nombre, apellido, dniAux);

                dni = atoi(dniAux);

                printf("%s,%s,%ld\n", nombre, apellido, dni);
                if(!buscarClientePorDni(clientes, dni))
                {
                    id = idDisponibleClientes(clientes); // La función retorna el siguiente id disponible del ArrayList de clientes, evita repeticiones de id.

                    setIdCliente(clienteAux, id);
                    setNombre(clienteAux, nombre);
                    setApellido(clienteAux, apellido);
                    setDni(clienteAux, dni);

                    if(clientes->add(clientes, clienteAux))
                    {
                        printf("    Error: No se guardo el cliente en la memoria RAM.\n");
                    }
                    else
                    {
                        printf("Guardado en memoria RAM.\n");
                        clienteAux = newCliente();
                    }
                }
                else
                {
                    printf("    Error: Ya hay un cliente con el DNI %ld\n", dni);
                }
            }
            fclose(pArchivo);
        }
        else
        {
            printf("    Error: No se pudo abrir el archivo.\n");
        }
    }
    else
    {
        printf("    Error: clientes = NULL.\n");
    }
}

void realizarVenta(ArrayList* ventas)
{
    if(ventas != NULL)
    {
        //id_servicio,idCliente,codTarea,fecha,costoUnitario
        int id = idDisponibleVentas(ventas);

        int idCliente = pedirIdCliente(); // Pide el id del cliente y verifica que sea >= 0.
        char codigoDeProducto[51];
        pedirCodigoProducto(codigoDeProducto);  // Esta función pide el codigo y verifica que no tenga más de 5 caracteres.
        float costoUnitario = pedirCostoUnitario(); // Faltan verificaciones en esta función.
        int cantidad = pedirCantidad();
        char fecha[51];
        pedirFecha(fecha); // Faltan verificaciones en esta función.

        Venta* venta = newVenta();

        if(venta != NULL)
        {
            setIdVenta(venta, id);
            setIdCliente(venta, idCliente);
            setCodigoDeProducto(venta, codigoDeProducto);
            setFecha(venta, fecha);
            setCostoUnitario(venta, costoUnitario);
            setCantidad(venta, cantidad);

            if(ventas->add(ventas, venta))
            {
                printf("    Error: No se guardo la venta en la memoria RAM.\n");
            }
            else
            {
                printf("Guardado en memoria RAM.\n");
            }
        }
        else
        {
            printf("    Error: venta = NULL.\n");
        }
    }
    else
    {
        printf("    Error: ArrayList ventas = NULL.\n");
    }
}

int idDisponibleClientes(ArrayList* clientes)
{
    int id = 0; // el id por defecto es 0, a menos que esté utilizado quedará ese

    Cliente* clienteAux;

    int i;
    for(i=0; i<clientes->len(clientes); i++) // Recorre todo el ArrayList de los clientes.
    {
        if(clientes->get(clientes, i) != NULL)
        {
            clienteAux = clientes->get(clientes, i);

            if(clienteAux->id == id)
            {
                id++; // Si ya se encuentra ese id, incrementa el id.
                i = -1; // Este valor es para que vuelva a revisar desde el principio.
            }
        }
        else
        {
            printf("    Error: El cliente en la posicion %d del ArrayList esta en NULL.\n", i);
        }

    }

    return id;
}

int idDisponibleVentas(ArrayList* ventas)
{
    int id = 0; // El id por defecto es 0, a menos que esté utilizado quedará ese.

    Venta* ventaAux;

    int i;
    for(i=0; i<ventas->len(ventas); i++) // Recorre todo el ArrayList de los ventas.
    {
        if(ventas->get(ventas, i) != NULL)
        {
            ventaAux = ventas->get(ventas, i);

            if(ventaAux->id == id)
            {
                id++; // Si ya se encuentra ese id, incrementa el id.
                i = -1; // Este valor es para que vuelva a revisar desde el principio.
            }
        }
        else
        {
            printf("Problema.\n");
        }

    }

    return id;
}

Cliente* buscarClientePorId(ArrayList* clientes, int id)
{
    Cliente* cliente = NULL;
    Cliente* clienteAux = newCliente();

    int i=0;
    for(i=0;i<clientes->len(clientes);i++)
    {
        clienteAux = clientes->get(clientes,i);

        if(getIdCliente(clienteAux) == id)
        {
            cliente = clienteAux;
            break;
        }
    }

    if(cliente == NULL)
    {
        printf("    Error: No se encontro un cliente con el id %d.\n", id);
    }

    return cliente;
}

int buscarIdClientePorDni(ArrayList* clientes, int dni)
{
    int resultado = -1;

    Cliente* clienteAux = newCliente();

    int i=0;
    for(i=0;i<clientes->len(clientes);i++)
    {
        clienteAux = clientes->get(clientes,i);

        if(getDni(clienteAux) == dni)
        {
            resultado = getIdCliente(clienteAux);
            break;
        }
    }

    if(resultado == -1)
    {
        printf("    Error: No se encontro un cliente con el dni %d.\n", dni);
    }

    return resultado;
}

int buscarClientePorDni(ArrayList* clientes, int dni)
{
    int resultado = 0;

    Cliente* clienteAux = newCliente();

    int i=0;
    for(i=0;i<clientes->len(clientes);i++)
    {
        clienteAux = clientes->get(clientes,i);

        if(getDni(clienteAux) == dni)
        {
            resultado = 1;
            break;
        }
    }

    return resultado;
}

Venta* buscarVentaPorIdRetornar(ArrayList* ventas, int id)
{
    Venta* servicio = NULL;
    Venta* ventaAux = newVenta();

    int i=0;
    for(i=0;i<ventas->len(ventas);i++)
    {
        ventaAux = ventas->get(ventas,i);

        if(getIdVenta(ventaAux) == id)
        {
            servicio = ventaAux;
            break;
        }
    }

    if(servicio == NULL)
    {
        printf("    Error: No se encontro un servicio con el id %d.\n", id);
    }

    return servicio;
}

int buscarVentaPorId(ArrayList* ventas, int idVenta)
{
    int resultado = 0;
    Venta* ventaAux = newVenta();

    int i=0;
    for(i=0;i<ventas->len(ventas);i++)
    {
        ventaAux = ventas->get(ventas,i);

        if(getIdVenta(ventaAux) == idVenta)
        {
            resultado = 1;
            printf("    Error: Se encontro un servicio con el id %d.\n", idVenta);
            break;
        }
    }

    return resultado;
}

int buscarClienteEnVentas(ArrayList* ventas, int idCliente)
{
    int resultado = 0;
    Venta* ventaAux = newVenta();

    int i=0;
    for(i=0;i<ventas->len(ventas);i++) // Recorre todo el ArrayList de ventas.
    {
        ventaAux = ventas->get(ventas,i);

        if(getIdCliente(ventaAux) == idCliente)
        {
            resultado = 1; // Hay un servicio asociado a ese id de cliente.
            break;
        }
    }

    return resultado;
}

void guardarClientePorId(ArrayList* clientes, Cliente* cliente, int id)
{
    Cliente* clienteAux = newCliente();

    int i=0;
    for(i=0;i<clientes->len(clientes);i++) // Recorre todo el ArrayList de clientes.
    {
        clienteAux = clientes->get(clientes,i);

        if(getIdCliente(clienteAux) == id)
        {
            if(!(clientes->set(clientes, i, cliente))) // Guarda el cliente en la posición indicada por el id.
            {
                printf("Cliente guardado en memoria RAM.\n");
            }
            break;
        }
    }
}

int eliminarClientePorId(ArrayList* clientes, int id)
{
    int returnAux = 0;

    Cliente* clienteAux = newCliente();

    int i=0;
    for(i=0;i<clientes->len(clientes);i++) // Recorre todo el ArrayList de clientes.
    {
        clienteAux = clientes->get(clientes,i);

        if(getIdCliente(clienteAux) == id)
        {
            clientes->remove(clientes, i); // Si se encuentra ese id se elimina el cliente correspondiente.
            returnAux = 1;
            break;
        }
    }

    return returnAux;
}

void pedirNombre(char nombre[])
{
    printf("Ingrese el nombre: ");
    //fflush(stdin);
    scanf("%s",nombre);
    printf("\n");
}

void pedirApellido(char apellido[])
{
    printf("Ingrese el apellido: ");
    //fflush(stdin);
    scanf("%s",apellido);
    printf("\n");
}

long int pedirDni()
{
    long int dni;
    char dniIngresado[4];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el dni del cliente: ");
        fflush(stdin);
        scanf("%s",&dniIngresado);
        dni = atoi(dniIngresado);

        if(!(dni <= 0))
        {
            flag = 1;
        }
        else
        {
            printf("    Error: No es un n%cmero v%clido.\n", 163, 160);
            flag = 0;
        }
    }
    return dni;
}

int pedirIdCliente()
{
    int index;
    char indexIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el ID del cliente: ");
        //fflush(stdin);
        scanf("%s",&indexIngresado);

        index = atoi(indexIngresado);

        if(!(index < 0))
        {
            flag = 1;
        }
        else
        {
            printf("    Error: No es un n%cmero v%clido.\n", 163, 160);
            flag = 0;
        }
    }
    printf("\n");
    return index;
}

int pedirCantidad()
{
    int cantidad;
    char cantidadIngresada[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese la cantidad: ");
        //fflush(stdin);
        scanf("%s",&cantidadIngresada);

        cantidad = atoi(cantidadIngresada);

        if(!(cantidad < 0))
        {
            flag = 1;
        }
        else
        {
            printf("    Error: No es un n%cmero v%clido.\n", 163, 160);
            flag = 0;
        }
    }
    printf("\n");
    return cantidad;
}

int pedirIdVenta()
{
    int index;
    char indexIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el ID del servicio: ");
        //fflush(stdin);
        scanf("%s",&indexIngresado);

        index = atoi(indexIngresado);

        if(!(index < 0))
        {
            flag = 1;
        }
        else
        {
            printf("    Error: No es un n%cmero v%clido.\n", 163, 160);
            flag = 0;
        }
    }
    printf("\n");
    return index;
}

void pedirCodigoProducto(char codigoDeProducto[]) // Esta función pide el codigo y verifica que no tenga más de 5 caracteres.
{
    int flag = 1;
    while(flag)
    {
        printf("Ingrese el codigo del producto: ");
        //fflush(stdin);
        scanf("%s", codigoDeProducto);

        char c;
        int i = -1;
        do
        {
            i++;
            c = codigoDeProducto[i];
        }
        while(c != '\0');

        if(i <= 16)
        {
            flag = 0;
        }
        else
        {
            printf("    Error: El codigo es muy largo, la cantidad de caracteres maxima es 5.\n");
        }
    }
}

void pedirFecha(char fecha[])
{
    char fechaTomada[50];
    int flag = 1;
    while(flag)
    {
        printf("Ingrese la fecha de ingreso (DD/MM/YY): ");
        //fflush(stdin);
        scanf("%s", fechaTomada);

        char c;
        int i = -1;

        char diaTomado[10];
        do
        {
            i++;
            c = fechaTomada[i+1];
            diaTomado[i] = fechaTomada[i];
        }
        while(c != '/');

        char mesTomado[10];
        do
        {
            i++;
            c = fechaTomada[i+1];
            mesTomado[i-3] = fechaTomada[i];
        }
        while(c != '/');

        char anioTomado[10];
        do
        {
            i++;
            c = fechaTomada[i+1];
            anioTomado[i-6] = fechaTomada[i];
        }
        while(i < 10);


        int dia = atoi(diaTomado);
        int mes = atoi(mesTomado);
        int anio = atoi(anioTomado);
        if(dia)
        {
            if(mes)
            {
                if(anio)
                {
                    printf("\n%d/%d/%d\n", dia, mes, anio);

                    strcpy(fecha,diaTomado);
                    strcat(fecha,"/");
                    strcat(fecha,mesTomado);
                    strcat(fecha,"/");
                    strcat(fecha,anioTomado);

                    printf("\n%s\n", fecha);

                    flag = 0;
                }
                else
                {
                    printf("    Error: Anio invalido.\n");
                }
            }
            else
            {
                printf("    Error: Mes invalido.\n");
            }
        }
        else
        {
            printf("    Error: Dia invalido.\n");
        }

        if(i <= 10)
        {
            flag = 0;
        }
        else
        {
            printf("    Error: La fecha es muy larga.\n");
            flag = 1;
        }
    }
}

float pedirCostoUnitario()
{
    float costoUnitario;

    printf("Ingrese el costo unitario: ");
    //fflush(stdin);
    scanf("%f",&costoUnitario);

    return costoUnitario;
}

void pedirPathArchivo(char pathArchivo[])
{
    printf("Ingrese el path del archivo: ");
    //fflush(stdin);
    scanf("%s", pathArchivo);
    printf("\n");
}
