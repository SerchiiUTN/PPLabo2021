/*
 * eDireccion.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Sergio
 */

#ifndef EDIRECCION_H_
#define EDIRECCION_H_

#include "utn.h"

typedef struct
{
	char calle[64];
	int altura;
}eDireccion;

/// @fn int eDireccion_IngresarDireccion(eDireccion*)
/// @brief Le pide una direccion al usuario y lo guarda en una direccion de memoria
///
/// @param direccion -> Direccion de memoria donde guardara el dato
/// @return Retorna 1 (OK) o 0 (Error)
int eDireccion_IngresarDireccion(eDireccion* direccion);

/// @fn int eDireccion_MostrarDireccion(eDireccion)
/// @brief Muestra una direccion por consola
///
/// @param direccion -> direccion a mostrar
/// @return Retorna 1 (OK) o 0 (Error)
int eDireccion_MostrarDireccion(eDireccion direccion);


#endif /* EDIRECCION_H_ */
