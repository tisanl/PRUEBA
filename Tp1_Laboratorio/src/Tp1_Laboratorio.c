/*
 ============================================================================
 Name        : Tp1_Laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Libreria.h"


int main(void)
{
	setbuf(stdout, NULL);

    //Valores de datos x y z
    int x = 0; //km
    float y = 0; //Aerolineas Arg
    float z = 0; //Latam
    float diferenciaPrecio = 0;
    //salida
    int opcion;
    char confirmarSalida = 'n';
    //Banderas
    int flagIngresoKm = 0;
    int flagIngresoAerolineas = 0;
    int flagIngresoLatam = 0;
    int sumaFlagsIngresoDatos = 0;
    int opcionCalculos = 0;
    int flagCalculoAerolineas = 0;
    int flagCalculoLatam = 0;
    int sumaFlagsHizoCalculos = 0;
    int opcionMostrar = 0;
    //variables con resultados
    //variables Aerolineas
	float debitoA;
	float creditoA;
	float bitcoinA;
	float unitarioA;

	//variables Latam
	float debitoL;
	float creditoL;
	float bitcoinL;
	float unitarioL;

    do
    {
        switch(opcion = menu())
        {
            case 1: //funcion cantidad de kilometros
                flagIngresoKm = calcularKm(&x);
                break;
            case 2:  //ingreso precio de vuelos
                submenu(&y, &z, &flagIngresoAerolineas, &flagIngresoLatam);
                break;
            case 3:  //calcular precios
                sumaFlagsIngresoDatos = flagIngresoKm + flagIngresoAerolineas + flagIngresoLatam;
                opcionCalculos = realizarCalculos(sumaFlagsIngresoDatos); //se da una respuesta en funcion de lo que haya echo el usuario hasta ahora
                switch(opcionCalculos) //se elige el calculo si es posible
                {
                    case 1:
                        flagCalculoAerolineas = calcularPrecioAerolineas(x, y, &debitoA, &creditoA, &bitcoinA, &unitarioA);
                        break;
                    case 2:
                        flagCalculoLatam = calcularPrecioLatam(x, z, &debitoL, &creditoL, &bitcoinL, &unitarioL);
                        break;
                    case 3:
                        flagCalculoAerolineas = calcularPrecioAerolineas(x, y, &debitoA, &creditoA, &bitcoinA, &unitarioA);
                        flagCalculoLatam = calcularPrecioLatam(x, z, &debitoL, &creditoL, &bitcoinL, &unitarioL);
                        break;
                }
                break;
            case 4: //mostrar resultados, se elegira una opcion en funcion de lo que haya ingresado el usuario hasta ese momento
                sumaFlagsHizoCalculos = flagCalculoAerolineas + flagCalculoLatam;
                system("cls");
                switch(sumaFlagsHizoCalculos) //se reestableceran los valores una vez mostrados
                {
                    case 0:
                        printf("\nPrimero hay que realizar los calculos..\n\n");
                        break;
                    case 1:
                        printf("Los Km ingresados son: %d\n\n", x);
                        mostrarAerolineas(y, debitoA, creditoA, bitcoinA, unitarioA);
                        resetValores(&x, &y, &z);
                        resetFlags(&flagIngresoKm, &flagIngresoAerolineas, &flagIngresoLatam, &flagCalculoAerolineas, &flagCalculoLatam);
                        printf("Los valores se han reestablecido\n\n");
                        break;
                    case 2:
                        printf("Los Km ingresados son: %d\n\n", x);
                        mostrarLatam(z, debitoL, creditoL, bitcoinL, unitarioL);
                        resetValores(&x, &y, &z);
                        resetFlags(&flagIngresoKm, &flagIngresoAerolineas, &flagIngresoLatam, &flagCalculoAerolineas, &flagCalculoLatam);
                        printf("Los valores se han reestablecido\n\n");
                        break;
                    case 3:
                        printf("Los Km ingresados son: %d\n\n", x);
                        mostrarAerolineas(y, debitoA, creditoA, bitcoinA, unitarioA);
                        printf("\n");
                        mostrarLatam(z, debitoL, creditoL, bitcoinL, unitarioL);
                        if(y > z)
                        {
                            diferenciaPrecio = y - z;
                            printf("\nAerolineas es %.2f pesos mas caro que Latam\n\n", diferenciaPrecio);
                        }
                        else
                        {
                            diferenciaPrecio = z - y;
                            printf("\nLatam es %.2f pesos mas caro que Aerolineas\n\n", diferenciaPrecio);
                        }
                        resetValores(&x, &y, &z);
                        resetFlags(&flagIngresoKm, &flagIngresoAerolineas, &flagIngresoLatam, &flagCalculoAerolineas, &flagCalculoLatam);
                        printf("Los valores se han reestablecido\n\n");
                        break;
                }
                break;
            case 5:
                system("cls");
                printf("Los Km ingresados son: %d\n\n", 7090);
                flagCalculoAerolineas = calcularPrecioAerolineas(7090, 162965, &debitoA, &creditoA, &bitcoinA, &unitarioA);
                flagCalculoLatam = calcularPrecioLatam(7090, 159339, &debitoL, &creditoL, &bitcoinL, &unitarioL);
                mostrarAerolineas(162965, debitoA, creditoA, bitcoinA, unitarioA);
                printf("\n");
                mostrarLatam(159339, debitoL, creditoL, bitcoinL, unitarioL);
                diferenciaPrecio = 162965 - 159339;
                printf("\nAerolineas es %.2f pesos mas caro que Latam\n\n", diferenciaPrecio);
                resetValores(&x, &y, &z);
                resetFlags(&flagIngresoKm, &flagIngresoAerolineas, &flagIngresoLatam, &flagCalculoAerolineas, &flagCalculoLatam);
                printf("Los valores se han reestablecido\n\n");
                break;
            case 6:
                salirDelPrograma(&confirmarSalida);
                break;
            default:
                confirmarSalida = 'y';
        }
    }while(confirmarSalida != 'y');

    printf("\n\nHasta luego\n\n");
    printf("Toque cualquier tecla para continuar\n\n");

	return EXIT_SUCCESS;
}
