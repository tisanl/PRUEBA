#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Validaciones.h"
#include "ArrayPassengers.h"

#define AUX 200

void salirDelPrograma(char* confirm)
{
    printf("Desea salir del programa? Teclee 'Y' para confirmar o cualquier otra tecla para volver al menu: ");
    fflush(stdin);
    scanf("%c", confirm);
    *confirm = tolower(*confirm);
    system("pause");
}

int pedirYValidarString(char string[], int len)
{
    char auxCad[AUX];
    int alpha;
    int todoOk = 0; //retorna case 0 si es largo y hay caracteres invalidos

    fflush(stdin);
    gets(auxCad);
    alpha = validarTodoAlpha(auxCad);
    if(strlen(auxCad) < len && alpha == 1) //devuelve 1 si esta todo bien y guarda el cambio
    {
        todoOk = 1;
        strcpy(string, auxCad);
    }
    else if(strlen(auxCad) > len && alpha == 1) //retorna -1 si es muy larga
    {
        todoOk = -1;
    }
    else if(strlen(auxCad) < len && alpha == 0) //retorna -2 si hay cosas que no son numero
    {
        todoOk = -2;
    }

    return todoOk;
}

int validarTodoAlpha(char auxCad[])
{
    int todoOk = 1;
    int cant;
    for(int i = 0; i < AUX -1; i++)
    {
        cant = isalpha(auxCad[i]);
        if(auxCad[i] == '\0')
        {
            break;
        }
        else if(cant == 0 && auxCad[i] != 32)
        {
            todoOk = 0;
            break;
        }
    }

    return todoOk;
}

void whyInvalidString(int caso)
{
    switch(caso)
    {
        case -1:
            printf(" muy largo. Intente nuevamente: ");
            break;
        case -2:
            printf(" con caracteres no validos. Intente nuevamente: ");
            break;
        case 0:
            printf(" con caracteres no validos y muy largo. Intente nuevamente: ");
            break;
    }
}

