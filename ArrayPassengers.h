#ifndef ARRAYPASSENGER_H_INCLUDED
#define ARRAYPASSENGER_H_INCLUDED
#define LENNAME 51

typedef struct
{
    int id;
    char name[LENNAME];
    char lastName[LENNAME];
    float price;
    char flyCode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;

}passenger;

typedef struct
{
    char destino[20];
    char code[15];
    float precio;
    char statusFlight[15];
    int numeroStatusFlight;

}codigoVuelo;

typedef struct
{
    char clase[20];
    int numeroClave;
    float precio;
}tipoPasajero;

#endif // ARRAYPASSENGER_H_INCLUDED

int menu();

int initPassengers(passenger[], int);

int addPassenger(passenger[], int, int*);

void hardcodeoCodigoVuelo(codigoVuelo[], int);

void mostrarVuelos(codigoVuelo[], int);

void hardcodeoTipoPasajero(tipoPasajero[], int);

void mostrarTipoPasajero(tipoPasajero[], int);

void mostrarPasajeroUnico(passenger[], int);

void mostrarPasajeros(passenger[], int);

