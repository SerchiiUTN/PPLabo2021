/*
 * eDireccion.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Sergio
 */

#include "eDireccion.h"

int eDireccion_IngresarDireccion(eDireccion* direccion)
{
	int retorno;
	int retornoAuxiliar;
	eDireccion dirAux;

	retorno = 0;

	if(direccion != NULL)
	{

		printf("Direccion:\n");

		retornoAuxiliar = utn_PedirTexto(dirAux.calle,sizeof(dirAux.calle),"Ingrese la calle: ","La calle ingresada no es valida",2);

		if(retornoAuxiliar == 1)
		{
			retornoAuxiliar = utn_PedirEntero(&dirAux.altura, "Ingrese la altura: ", "La altura no es correcta", 1, 50000,2);

			if(retornoAuxiliar == 1)
			{
				retorno = 1;
				*direccion = dirAux;
			}

		}

	}

	return retorno;
}

int eDireccion_MostrarDireccion(eDireccion direccion)
{
	int retorno;

	retorno = 0;

	printf("%-20s %6d",direccion.calle, direccion.altura);
	retorno = 1;

	return retorno;
}
