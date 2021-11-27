/*
 * eLocalidad.c
 *
 *  Created on: 14 oct. 2021
 *      Author: Sergio
 */

#include "eLocalidad.h"


int eLocalidad_ValidarLocalidades(eLocalidad lista[], int tam)
{
	int retorno;

	retorno = 0;

	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == FULL)
			{
				retorno = 1;
				break;
			}
		}
	}



	return retorno;
}

int eLocalidad_MostrarLocalidades(eLocalidad lista[], int tam)
{
	int retorno;

	retorno = 0;

	if(lista != NULL && tam > 0 && eLocalidad_ValidarLocalidades(lista,tam) == 1)
	{
		printf("Localidades:\n");
		printf("ID | Localidad\n");
		printf("---------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == FULL)
			{
				printf("%-3d| %s\n",lista[i].idLocalidad,lista[i].localidad);
				retorno = 1;
			}
		}

		printf("\n");

	}


	return retorno;
}

int eLocalidad_BuscarLocalidadPorID(int idLocalidad, eLocalidad lista[], int tam)
{
	int index;

	index = -1;

	if(idLocalidad > 0 && lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].idLocalidad == idLocalidad)
			{
				index = i;
				break;
			}
		}
	}


	return index;
}

int eLocalidad_MostrarUnaLocalidad(int idLocalidad, eLocalidad lista[], int tam)
{
	int retorno;
	int index;

	retorno = 0;

	if(lista != NULL && tam > 0 && eLocalidad_ValidarLocalidades(lista,tam) == 1)
	{
		index = eLocalidad_BuscarLocalidadPorID(idLocalidad,lista,tam);

		if(index != -1)
		{
			printf("%s \n",lista[index].localidad);
			retorno = 1;
		}


	}


	return retorno;
}

int eLocalidad_IngresarLocalidad(int* idLocalidad, eLocalidad lista[], int tam)
{
	int retorno;
	int retornoAuxiliar;
	int idAuxiliar;

	retorno = 0;

	if(idLocalidad != NULL && lista != NULL && tam > 0 && eLocalidad_MostrarLocalidades(lista,tam) == 1)
	{
		retornoAuxiliar = utn_PedirEntero(&idAuxiliar,"Ingrese la localidad: ","La localidad ingresada no es valida",1,tam,2);

		if(retornoAuxiliar == 1)
		{
			retorno = 1;
			*idLocalidad = idAuxiliar;

		}

	}

	return retorno;
}

