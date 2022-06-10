/*
 * Libreria.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Usuario
 */

#ifndef LIBRERIA_H_
#define LIBRERIA_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/** \brief
 *
 * \param int*
 * \return int
 *
 */
int calcularKm(int*); // funcion cantidad de kilometros


/** \brief
 *
 * \param int
 * \return int
 *
 */
int realizarCalculos(int); //prototipo de que calcula

/** \brief
 *
 * \param int
 * \param float
 * \param float*
 * \param float*
 * \param float*
 * \param float*
 * \return int
 *
 */
int calcularPrecioAerolineas(int, float, float*, float*, float*, float*); //prototipo calcula Aerolineas

/** \brief
 *
 * \param int
 * \param float
 * \param float*
 * \param float*
 * \param float*
 * \param float*
 * \return int
 *
 */
int calcularPrecioLatam(int, float, float*, float*, float*, float*); //prototipo calcula Latam

/** \brief
 *
 * \param float
 * \param float
 * \param float
 * \param float
 * \param float
 * \return void
 *
 */
void mostrarAerolineas(float, float, float, float, float); //mostrar resultados Aerolineas

/** \brief
 *
 * \param z float
 * \param debitoL float
 * \param creditoL float
 * \param bitcoinL float
 * \param unitarioL float
 * \return void
 *
 */
void mostrarLatam(float z, float debitoL, float creditoL, float bitcoinL, float unitarioL); //mostrar Latam

/** \brief
 *
 * \param int*
 * \param float*
 * \param float*
 * \return void
 *
 */
void resetValores(int*, float*, float*);

/** \brief
 *
 * \param int*
 * \param int*
 * \param int*
 * \param int*
 * \param int*
 * \return void
 *
 */
void resetFlags(int*, int*, int*, int*, int*);

// prototipo menu
/** \brief
 *
 * \return return
 *
 */
int menu();

//prototipo submenu

/** \brief
 *
 * \param float*
 * \param float*
 * \param int*
 * \param int*
 * \return int
 *
 */
int submenu(float*, float*, int*, int*); //ingreso previo de vuelos

/** \brief
 *
 * \param char*
 * \return void
 *
 */
void salirDelPrograma(char*);



#endif /* LIBRERIA_H_ */
