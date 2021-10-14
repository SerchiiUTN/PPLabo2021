/*
 * eLocalidad.c
 *
 *  Created on: 14 oct. 2021
 *      Author: Sergio
 */

#include "eLocalidad.h"

int eLocalidad_IngresarLocalidad(eLocalidad* localidad)
{
	int retorno;
	int retornoAuxiliar;
	eLocalidad auxLocalidad;

	retorno = 0;

	if(localidad != NULL)
	{
		retornoAuxiliar = utn_PedirTexto(auxLocalidad.localidad,sizeof(auxLocalidad.localidad),"Ingrese la localidad: ","La localidad ingresada no es valida",2);

		if(retornoAuxiliar == 1)
		{
			retorno = 1;
			*localidad = auxLocalidad;

		}

	}

	return retorno;
}
