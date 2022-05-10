#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassengers.h"
#include "Validaciones.h"
#define LENNAME 51

//FUNCION QUE DESPLIEGA EL MENU Y VALIDA LA OPCION
int menu()
{
    int opcion = 6;
    int cant;

    system("cls");
    printf("===========================================================\n");
    printf("******************** MENU DE PASAJEROS ********************\n");
    printf("===========================================================\n\n");
    printf("Opcion 1: Alta de pasajero\n");
    printf("Opcion 2: Modificacion de pasajero\n");
    printf("Opcion 3: Baja de pasajero\n");
    printf("Opcion 4: Informar\n");
    printf("Opcion 5: Salir\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    cant = scanf("%d", &opcion);
    for(int i = 0; cant == 0 || opcion < 0 || opcion > 5; i++)
    {
        printf("Opcion invalida. Ingrese un numero del 1 al 5: ");
        fflush(stdin);
        cant = scanf("%d", &opcion);
        if(i == 7)
        {
            printf("\nHa realizado muchos intentos. Intente denuevo mas tarde.\n"
                   "Hasta luego\n\n");
            system("pause");
            break;
        }
    }

    return opcion;
}

//FUNCION initPassengers tal cual esta descripta en el tp
int initPassengers(passenger list[], int len)
{
    int todoOk = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
            todoOk = 0;
        }
    }

    return todoOk;
}

//FUNCION addPassenger (no entendi como pasarle todos esos valores a la vez pasando el array, con que objetivo, no encontre utilidad ni como hacerlo)
int addPassenger(passenger list[], int len, int* id)
{
    int todoOk = -1;
    int cant;
    codigoVuelo vuelos[7];
    int numeroCodigo;
    tipoPasajero clase[3];
    int numeroTipo;
    float precio;
    char confirmacion = 'y';

    system("cls");

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len && confirmacion == 'y'; i++)
        {
            if(list[i].isEmpty == 1)
            {
                //Pedir name
                printf("\nIngrese el nombre del pasajero: "); //las funciones estan detalladas en cada una
                cant = pedirYValidarString(list[i].name, LENNAME);
                while(cant != 1)
                {
                    printf("Nombre");
                    whyInvalidString(cant);
                    cant = pedirYValidarString(list[i].name, LENNAME);
                }

                //pedir LastName
                printf("Ingrese el apellido del pasajero: "); //las funciones estan detalladas en cada una
                cant = pedirYValidarString(list[i].lastName, LENNAME);
                while(cant != 1)
                {
                    printf("Apellido");
                    whyInvalidString(cant);
                    cant = pedirYValidarString(list[i].lastName, LENNAME);
                }

                //pedir FlyCode
                printf("\n");
                hardcodeoCodigoVuelo(vuelos, 7);
                mostrarVuelos(vuelos, 7);
                printf("Ingrese el numero que corresponda al destino y codigo del vuelo del pasajero: ");
                fflush(stdin);
                cant = scanf("%d", &numeroCodigo);
                while(cant == 0 || numeroCodigo < 1 || numeroCodigo > 7)
                {
                    printf("Numero invalido. Eliga uno del 1 al 7: ");
                    fflush(stdin);
                    cant = scanf("%d", &numeroCodigo);
                }
                numeroCodigo -= 1;
                strcpy(list[i].flyCode, vuelos[numeroCodigo].code);
                list[i].statusFlight = vuelos[numeroCodigo].numeroStatusFlight;
                precio = vuelos[numeroCodigo].precio;

                //pedir TypePassenger
                printf("\n");
                hardcodeoTipoPasajero(clase, 3);
                mostrarTipoPasajero(clase, 3);
                printf("Ingrese el numero que corresponda al tipo del pasajero: ");
                fflush(stdin);
                cant = scanf("%d", &numeroTipo);
                while(cant == 0 || numeroTipo < 1 || numeroTipo > 3)
                {
                    printf("Numero invalido. Eliga uno del 1 al 3: ");
                    fflush(stdin);
                    cant = scanf("%d", &numeroTipo);
                }
                numeroTipo -=1;
                list[i].typePassenger = clase[numeroTipo].numeroClave;
                precio += clase[numeroTipo].precio;
                list[i].price = precio;

                //Poner id
                list[i].id = *id;
                *id += 1;

                //poner isEmpty
                list[i].isEmpty = 0;

                mostrarPasajeroUnico(list, i);

                printf("\nDesea ingresar otro pasajero? Teclee 'y' para ingresar otro o cualquier otra tecla para salir: ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = tolower(confirmacion);

                todoOk = 0;
            }
        }
    }

    system("pause");

    return todoOk;
}

void hardcodeoCodigoVuelo(codigoVuelo vuelo[], int len)
{
    codigoVuelo harcodeados[7]=
    {
        {"Nueva York", "TONYSTARK", 3000, "Confirmado", 1},
        {"Asgard", "THOR4", 4000, "Demorado", 2},
        {"Los Angeles", "LAN420", 2000, "Cancelado", 3},
        {"Texas", "ELONMUSK", 2700, "Confirmado", 1},
        {"Tokio", "JAP164", 1800, "Demorado", 3},
        {"Madrid", "DELAOSSA", 1000, "Confirmado", 1},
        {"Londres", "LON157", 1200, "Cancelado", 3}
    };

    for(int i = 0; i < len; i++)
    {
        strcpy(vuelo[i].destino, harcodeados[i].destino);
        strcpy(vuelo[i].code, harcodeados[i].code);
        strcpy(vuelo[i].statusFlight, harcodeados[i].statusFlight);
        vuelo[i].precio = harcodeados[i].precio;
    }
}

void mostrarVuelos(codigoVuelo vuelo[], int len)
{
    int numero;

    printf("===================================================\n");
    printf("Numero||Destino        ||Codigos    ||Estado       \n");
    printf("------||---------------||-----------||-------------\n");
    for(int i = 0; i < len; i++)
    {
        numero = i+1;
        printf("%-6d||", numero);
        printf("%-15s||", vuelo[i].destino);
        printf("%-11s||", vuelo[i].code);
        printf("%-11s\n", vuelo[i].statusFlight);
    }
    printf("===================================================\n");
    printf("\n");
}

void hardcodeoTipoPasajero(tipoPasajero clase[], int len)
{
    tipoPasajero harcodeados[3] =
    {
        {"Turista", 1, 500},
        {"Bussines", 2, 800},
        {"Primera Clase", 3, 1300, }
    };

    for(int i = 0; i < len; i++)
    {
        strcpy(clase[i].clase, harcodeados[i].clase);
        clase[i].numeroClave = harcodeados[i].numeroClave;
        clase[i].precio = harcodeados[i].precio;
    }
}

void mostrarTipoPasajero(tipoPasajero clase[], int len)
{
    int numero;

    printf("=======================\n");
    printf("Numero||Clase      \n");
    printf("------||---------------\n");
    for(int i = 0; i < len; i++)
    {
        numero = i+1;
        printf("%-6d||", numero);
        printf("%-15s\n", clase[i].clase);
    }
    printf("=======================\n");
    printf("\n");
}

void mostrarPasajeroUnico(passenger lista[], int i)
{
    system("cls");
    printf("============================================================================================\n");
    printf("    Nombre     ||    Apellido   ||   id   || Codigo de vuelo ||Tipo de pasajero||   Precio  \n");
    printf("---------------||---------------||--------||-----------------||----------------||-----------\n");
    printf("%15s||", lista[i].name);
    printf("%15s||", lista[i].lastName);
    printf("%8d||", lista[i].id);
    printf("%17s||", lista[i].flyCode);
    printf("%16d||", lista[i].typePassenger);
    printf("%11f\n", lista[i].price);
    printf("=============================================================================================\n");
    printf("\n");
}

void mostrarPasajeros(passenger lista[], int len)
{
    system("cls");
    printf("============================================================================================\n");
    printf("    Nombre     ||    Apellido   ||   id   || Codigo de vuelo ||Tipo de pasajero||   Precio  \n");
    printf("---------------||---------------||--------||-----------------||----------------||-----------\n");
    for(int i = 0; i < len && lista[i].isEmpty == 0; i++)
    {
        printf("%15s||", lista[i].name);
        printf("%15s||", lista[i].lastName);
        printf("%8d||", lista[i].id);
        printf("%17s||", lista[i].flyCode);
        printf("%16d||", lista[i].typePassenger);
        printf("%11f\n", lista[i].price);
    }
    printf("=============================================================================================\n");
    printf("\n");

}

int findPassengerById(passenger list[], int len)
{
    int id;
    int cant;
    int array = -1;

    printf("Ingrese el Id de el pasajero que busca: ");
    fflush(stdin);
    cant = scanf("%d", &id);
    while(cant == 0 || id < 1000 || id > 3000)
    {
        printf("Dato erroneo. Debe ser un numero igual o mayor a mil e igual menor a 3000: ");
        fflush(stdin);
        cant = scanf("%d", &id);
    }

    for(int i = 0; i < len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            array = i;
            printf("El pasajero ha sido encontrado.\n");
            break;
        }
        else
        {
            printf("Ese id aun no tiene un pasajero asociado.\n");
            break;
        }
    }

    return array;
}
