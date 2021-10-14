/*
 * eLocalidad.h
 *
 *  Created on: 14 oct. 2021
 *      Author: Sergio
 */

#ifndef ELOCALIDAD_H_
#define ELOCALIDAD_H_

#include "utn.h"

typedef struct{
	char localidad[51];
}eLocalidad;

/// @fn int eLocalidad_IngresarLocalidad(eLocalidad*)
/// @brief Pide la localidad en consola
///
/// @param localidad -> Puntero a estructura donde se guardara la localidad
/// @return Retorna 1 (Se pudo guardar la localidad) o 0 (No se pudo guardar)
int eLocalidad_IngresarLocalidad(eLocalidad* localidad);

#endif /* ELOCALIDAD_H_ */
