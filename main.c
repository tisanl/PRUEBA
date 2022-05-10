#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassengers.h"
#include "Validaciones.h"

#define LEN 2000
#define LENNAME 51


int main()
{
    char confirm = 'n';
    passenger listaPasajeros[LEN];
    int id = 1000;

    if((initPassengers(listaPasajeros, LEN)) == 0)
    {
        do
        {
            switch(menu())
            {
                case 1:
                    addPassenger(listaPasajeros, LEN, &id);
                    break;
                case 2:
                    //modificar
                    mostrarPasajeros(listaPasajeros, LEN);
                    findPassengerById(listaPasajeros, LEN);
                    system("pause");
                    break;
                case 3:
                    //dar de baja
                    break;
                case 4:
                    //informar
                    break;
                case 5:
                    salirDelPrograma(&confirm);
                    system("pause");
                default:
                    confirm = 'y';
            }

        }while(confirm != 'y');
    }

    return 0;
}
