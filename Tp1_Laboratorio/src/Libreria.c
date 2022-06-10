/*
 * prototipo.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Usuario
 */

#include "Libreria.h"


int calcularKm(int* cantidadKm) //funcion cantidad de kilometros
{
    //variables
    int ingresoKm = 0;
    int cant;

    system("cls");

    //pedida de km

    printf("Ingrese la cantidad de kilometros: "); //primera vez
    fflush(stdin);
    cant = scanf("%d", cantidadKm);
    ingresoKm = 1;
    for(int i = 0; cant == 0 || *cantidadKm < 0; i++) //for con 5 intentos
    {
        if(i == 5) //se rompe al 5to intento
        {
            printf("Ha echo muchos intentos, intente con otra opcion\n\n");
            ingresoKm = 0;
            break;
        }

        printf("Opcion invalida. Ingrese un numero igual o mayor a 0: ");
        fflush(stdin);
        cant = scanf("%d", cantidadKm);
    }

    printf("\n");

    return ingresoKm;
}

int realizarCalculos(int sumaFlags) //define que va a calcular en funcion de lo ingresado hasta ahora
{
    int opcionCalculos = 0;

    system("cls");

    switch(sumaFlags)
    {
        case 0:
            printf("\nNo se han ingresado km ni valores de aerolineas!\n\n");
            break;
        case 1:
            printf("\nNo se ha ingresado ningun precio de aeorolineas!\n\n");
            break;
        case 3:
        case 5:
            printf("\nNo se ha ingresado cantidad de kilometros!\n\n");
            break;
        case 4:
            opcionCalculos = 1;
            printf("\nNo se ha ingresado un valor para Latam!\n");
            printf("Los calculos de Aerolineas se han realizado exitosamente!!\n\n");
            break;
        case 6:
            opcionCalculos = 2;
            printf("\nNo se ha ingresado un valor para Aerolineas!\n");
            printf("Los calculos de Latam se han realizado exitosamente!!\n\n");
            break;
        case 9:
            opcionCalculos = 3;
            printf("\nSe han realizaron los calculos exitosamente!!\n\n");
            break;
    }

    return opcionCalculos;
}

//funciones para calcular los valores por separado
int calcularPrecioAerolineas(int x, float y, float* debitoA, float* creditoA, float* bitcoinA, float* unitarioA)
{
    *debitoA = y - (y * 10 / 100);
	*creditoA = y + (y * 25 / 100);
	*bitcoinA = y / 4653059.85;
	*unitarioA = y / x;

	return 1;
}

int calcularPrecioLatam(int x, float z, float* debitoL, float* creditoL, float* bitcoinL, float* unitarioL)
{
    *debitoL = z - (z * 10 / 100);
	*creditoL = z + (z * 25 / 100);
	*bitcoinL = z / 4653059.85;
	*unitarioL = z / x;

	return 2;
}

//funciones para mostrar los valores por separado

void mostrarAerolineas(float y, float debitoA, float creditoA, float bitcoinA, float unitarioA)
{
    printf("Aerolineas: %.2f\n", y);
    printf("El precio del vuelo en Aerolineas con debito es: %.2f\n", debitoA);
    printf("El precio del vuelo en Aerolineas con credito es: %.2f\n", creditoA);
    printf("El precio del vuelo en Aerolineas con Bitcoin es: %.6f\n", bitcoinA);
    printf("El precio unitario del vuelo en Latam es: %.2f\n", unitarioA);
}

void mostrarLatam(float z, float debitoL, float creditoL, float bitcoinL, float unitarioL)
{
    printf("Latam: %.2f\n", z);
    printf("El precio del vuelo en Latam con debito es: %.2f\n", debitoL);
    printf("El precio del vuelo en Latam con credito es: %.2f\n", creditoL);
    printf("El precio del vuelo en Latam con Bitcoin es: %.6f\n", bitcoinL);
    printf("El precio unitario del vuelo en Latam es: %.2f\n", unitarioL);
}

//funciones para reestablecer los datos despues de mostrar

void resetValores(int* x, float* y, float* z)
{
    *x = 0;
    *y = 0;
    *z = 0;
}

void resetFlags(int* flag1, int* flag2, int* flag3, int* flag4, int* flag5)
{
    *flag1 = 0;
    *flag2 = 0;
    *flag3 = 0;
    *flag4 = 0;
    *flag5 = 0;
}

// menu con un limite de intentos
int menu()
{
    int opcion;
    int cant;

    printf("*** Menu de opciones ***\n");
    printf("1. Ingresar kilometros\n");
    printf("2. Ingrese el valor del vuelo\n");
    printf("3. Calcular todos los costos\n");
    printf("4. Informar resultados\n");
    printf("5. Carga forzada de datos\n");
    printf("6. Salir\n\n");

    printf("Que opcion quiere?: ");
    fflush(stdin);
    cant = scanf("%d", &opcion);
    for(int i = 0; cant == 0 || opcion < 1 || opcion > 6; i ++)
    {
        system("cls");
        if(i == 5)
        {
            printf("Ha realizado muchos intentos. Intente denuevo mas tarde");
            opcion = 7;
            break;
        }
        printf("Opcion invalida. Ingrese una opcion del 1 al 6: \n\n");
        printf("*** Menu de opciones ***\n");
        printf("1. Ingresar kilometros\n");
        printf("2. Ingrese el valor del vuelo\n");
        printf("3. Calcular todos los costos\n");
        printf("4. Informar resultados\n");
        printf("5. Carga forzada de datos\n");
        printf("6. Salir\n\n");
        printf("Que opcion quiere?: ");
        fflush(stdin);
        cant = scanf("%d", &opcion);
    }

    return opcion;
}

//submenu para pedir datos de aerolineas
int submenu(float* aerolineas, float* latam, int* flagIngresoAerolineas, int* flagIngresoLatam)
{
    //variables
    int cant;
    int tomoDatos = 1; //no se usa pero esta ahi por si hace falta, es el return de la funcion
    char opcion;
    char confirmacion;

    system("cls");

    //desarrollo de submenu
    do
    {

        //pedir dato de la opcion entre ingresar valor de aerolineas, latam o si desea volver al menu
        printf("Elija el valor que desea ingresar o si desea volver al menu...\n");
        printf("A para ingresar el valor de Aerolineas, L para latam o M para volver al menu: ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = tolower(opcion);
        for(int i = 0; opcion != 'a' && opcion != 'l' && opcion != 'm'; i ++)
        {
            if(i == 3)
            {
                system("cls");
                printf("Muchos intentos, intente con otra opcion: \n\n");
                confirmacion = 'y';
                break;
            }
            printf("Opcion invalida. A para ingresar el valor de Aerolineas, L para latam o M para volver al menu: ");
            fflush(stdin);
            scanf("%c", &opcion);
            opcion = tolower(opcion);
        }

        printf("\n\n");

        //opciones

        if(opcion == 'a')//opcion Aerolineas con validacion
        {
            printf("Ingrese el valor del vuelo en Aerolineas: ");
            fflush(stdin);
            cant = scanf("%f", aerolineas);
            *flagIngresoAerolineas = 3;
            for(int i = 0; cant == 0 || *aerolineas < 0; i++)
            {
                if(i == 5) //se rompe al 5to intento
                {
                    system("cls");
                    printf("Ha echo muchos intentos, intente con otra opcion..\n");
                    *flagIngresoAerolineas = 0;
                    break;
                }
                printf("Opcion invalida. Ingrese un numero igual o mayor a 0: ");
                fflush(stdin);
                cant = scanf("%f", aerolineas);
            }
            printf("\n\n");
        }
        else if(opcion == 'l') //opcion Latam con validacion
        {
            printf("Ingrese el valor del vuelo en Latam: ");
            fflush(stdin);
            cant = scanf("%f", latam);
            *flagIngresoLatam = 5;
            for(int i = 0; cant == 0 || *latam < 0; i++)
            {
                if(i == 5) //se rompe al 5to intento
                {
                    system("cls");
                    printf("Ha echo muchos intentos, intente con otra opcion\n");
                    *flagIngresoLatam = 0;
                    break;
                }
                printf("Opcion invalida. Ingrese un numero igual o mayor a 0: ");
                fflush(stdin);
                cant = scanf("%f", latam);
            }
            printf("\n\n");
        }
        else if(opcion == 'm') //opcion menu, solo ingresara a esta opcion si desea
        {
            printf("Desea salir al menu (Seleccione Y para salir): ");
            fflush(stdin);
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);
            for(int i = 0; confirmacion != 'y'; i++)
            {
                if(i == 3) //se rompe al 3er intento
                {
                    system("cls");
                    printf("Ha echo muchos intentos, intente con otra opcion\n");
                    break;
                }
                printf("Opcion invalida. (Seleccione Y para salir): ");
                fflush(stdin);
                cant = scanf("%c", &confirmacion);
                confirmacion = tolower(confirmacion);
            }
            printf("\n\n");
        }

    }while(confirmacion != 'y');

    return tomoDatos;
}

//confirmacion punto numero 6, devuelve al menu si nunca seleccione 'y'
void salirDelPrograma(char* confirmar)
{
    int cant = 0;

    printf("Desea salir? ('y' para salir): ");
    fflush(stdin);
    cant = scanf("%c", confirmar);
    *confirmar = tolower(*confirmar);
    for(int i = 0; *confirmar != 'y' || cant == 0; i ++)
    {
        if(i == 3)
        {
            system("cls");
            printf("Ha realizado muchos intentos. Intente con otra opcion.\n");
            break;
        }
        printf("Opcion invalida. Seleccione 'y' para salir: ");
        fflush(stdin);
        cant = scanf("%c", confirmar);
        *confirmar = tolower(*confirmar);
    }
}
