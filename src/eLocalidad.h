/*
 * eLocalidad.h
 *
 *  Created on: 14 oct. 2021
 *      Author: Sergio
 */

#ifndef ELOCALIDAD_H_
#define ELOCALIDAD_H_

#include "utn.h"
#define EMPTY 0
#define FULL 1

typedef struct{
	int idLocalidad;
	char localidad[51];
	int isEmpty;
}eLocalidad;

/// @fn int eLocalidad_ValidarLocalidades(eLocalidad[], int)
/// @brief Valida que al menos haya una localidad
///
/// @param lista -> Array de la localidad
/// @param tam -> Tamaño del array
/// @return Retorna 1 (OK) o 0 (ERROR)
int eLocalidad_ValidarLocalidades(eLocalidad lista[], int tam);

/// @fn int eLocalidad_MostrarUnaLocalidad(int, eLocalidad[], int)
/// @brief Imprime una localidad
///
/// @param idLocalidad -> ID de la localidad
/// @param lista -> Array de la localidad
/// @param tam -> Tamaño del array
/// @return Retorna 1 (OK) o 0 (ERROR)
int eLocalidad_MostrarUnaLocalidad(int idLocalidad, eLocalidad lista[], int tam);

/// @fn int eLocalidad_MostrarLocalidades(eLocalidad[], int)
/// @brief Muestra por consola las localidades disponibles
///
/// @param lista -> Array de la localidad
/// @param tam -> Tamaño del array
/// @return Retorna 1 (OK) o 0 (ERROR)
int eLocalidad_MostrarLocalidades(eLocalidad lista[], int tam);

/// @fn int eLocalidad_IngresarLocalidad(int*, eLocalidad[], int)
/// @brief
///
/// @param idLocalidad -> ID de la localidad elegida
/// @param lista -> Array de localidades
/// @param tam -> Tamaño del array
/// @return Retorna 1 (OK) o 0 (ERROR)
int eLocalidad_IngresarLocalidad(int* idLocalidad, eLocalidad lista[], int tam);

#endif /* ELOCALIDAD_H_ */
