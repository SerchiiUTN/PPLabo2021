/*
 * utn.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Sergio
 */

#include "utn.h"


int myGets(char cadena[],int tam,char mensaje[])
{
	int retorno;
    char auxiliar[tam];
    int largo;

    retorno = 0;

    if(cadena != NULL && tam > 0)
    {
    	printf("%s", mensaje);
		fflush(stdin);
		fgets(auxiliar,tam,stdin);
		largo = strlen(auxiliar);

		if(auxiliar[largo-1] == '\n')
		{
			auxiliar[largo-1] = '\0';
		}

		if(auxiliar[0] != '\0')
		{
			strcpy(cadena, auxiliar);
			retorno = 1;
		}

    }


    return retorno;
}

int esNumerica(char cadena[])
{
	int retorno;
	int i;
	int largo;
	int validar;

	i = 0;
	retorno = 1;
	largo = strlen(cadena);

	if(cadena[0] == '-' || cadena[0] == '+')
	{
		i = 1;
	}

	if(cadena[i] == '\0')
	{
		retorno = 0;
	}

	for( ; i < largo ; i++)
	{
		validar = isdigit(cadena[i]);

		if(validar == 0)
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int esFlotante(char cadena[])
{
	int retorno;
	int i;
	int largo;
	int validar;
	int puntos;

	i = 0;
	puntos = 0;
	retorno = 1;
	largo = strlen(cadena);

	if(cadena[0] == '-' || cadena[0] == '+' || cadena[0] == '.')
	{
		i = 1;
	}

	if(cadena[0] == '.')
	{
		puntos++;
	}


	if(cadena[i] == '\0')
	{
		retorno = 0;
	}

	for(; i < largo ; i++)
	{
		validar = isdigit(cadena[i]);

		if(validar == 0 && (cadena[i] != '.'))
		{
			retorno = 0;
			break;
		}

		if(cadena[i] == '.')
		{
			puntos++;
		}

	}

	if(puntos > 1)// modificar si solo ingresa Enter
	{
		retorno = 0;
	}


	return retorno;
}


int esCuit(char cadena[])
{
	int retorno;
	int i;
	int largo;
	int validar;


	i = 0;
	retorno = 0;
	largo = 13;

	if(cadena != NULL && cadena[2] == '-' && cadena[11] == '-')
	{
		retorno = 1;
		for(i = 0; i < largo ; i++)
		{
			validar = isdigit(cadena[i]);

			if((i == 2 || i == 11) && cadena[i] == '-')
			{
				continue;
			}

			if(validar == 0)
			{
				retorno = 0;
				break;
			}

		}
	}

	return retorno;
}


int getInt(int* numero, char mensaje[])
{
	int retorno;
	char numeroString[65];
	int retornoAuxiliar;

	retorno = 0;

	if(numero != NULL)
	{
		retornoAuxiliar = myGets(numeroString, sizeof(numeroString), mensaje);

		if(retornoAuxiliar == 1)
		{
			retornoAuxiliar = esNumerica(numeroString);

			if(retornoAuxiliar == 1)
			{
				*numero = atoi(numeroString);
				retorno = 1;
			}
		}
	}
	return retorno;
}

int getFloat(float* flotante, char mensaje[])
{
	int retorno;
	char numeroString[65];
	int retornoAuxiliar;

	retorno = 0;

	if(flotante != NULL)
	{
		retornoAuxiliar = myGets(numeroString, sizeof(numeroString), mensaje);

		if(retornoAuxiliar == 1)
		{
			retornoAuxiliar = esFlotante(numeroString);

			if(retornoAuxiliar == 1)
			{
				*flotante = atof(numeroString);
				retorno = 1;
			}
		}
	}
	return retorno;
}

int getString(char cadena[],int tam, char mensaje[])
{
	int retorno;
	char textoAuxiliar[256];
	int retornoAuxiliar;

	retorno = 0;

	if(cadena != NULL)
	{
		retornoAuxiliar = myGets(textoAuxiliar, sizeof(textoAuxiliar), mensaje);

		if(retornoAuxiliar == 1)
		{
			strncpy(cadena,textoAuxiliar,tam-1);
			retorno = 1;
		}

	}
	return retorno;
}

int getCuit(char cadena[], int tam, char mensaje[])
{
	int retorno;
	char textoAuxiliar[256];
	int retornoAuxiliar;

	retorno = 0;

	if(cadena != NULL)
	{
		retornoAuxiliar = myGets(textoAuxiliar, sizeof(textoAuxiliar), mensaje);

		if(retornoAuxiliar == 1)
		{
			retornoAuxiliar = esCuit(textoAuxiliar);

			if(retornoAuxiliar == 1)
			{
				strncpy(cadena,textoAuxiliar,tam-1);
				retorno = 1;
			}

		}

	}
	return retorno;
}

int utn_PedirEntero(int* numero, char mensaje[], char error[], int minimo, int maximo, int reintentos)
{
	int auxiliar;
	int retornoAuxiliar;
    int retorno;

    retorno = 0;

    if(numero != NULL && mensaje != NULL && error != NULL && minimo <= maximo && reintentos >= 0)
    {
    	do
		{
			retornoAuxiliar = getInt(&auxiliar, mensaje);

			if(retornoAuxiliar == 1)
			{
				if(auxiliar >= minimo && auxiliar <= maximo)
				{
					*numero = auxiliar;
					retorno = 1;
					break;
				}
			}

			printf("%s\n", error);
			reintentos--;
		}while(reintentos >= 0);
    }


	return retorno;
}

int utn_PedirFlotante(float* flotante, char mensaje[], char error[], float minimo, float maximo, int reintentos)
{
	float auxiliar;
	int retornoAuxiliar;
    int retorno;

    retorno = 0;

    if(flotante != NULL && mensaje != NULL && error != NULL && minimo <= maximo && reintentos >= 0)
    {
    	do
		{
			retornoAuxiliar = getFloat(&auxiliar, mensaje);

			if(retornoAuxiliar == 1)
			{
				if(auxiliar >= minimo && auxiliar <= maximo)
				{
					*flotante = auxiliar;
					retorno = 1;
					break;
				}
			}

			printf("%s\n", error);
			reintentos--;
		}while(reintentos >= 0);
    }


	return retorno;
}

int utn_PedirTexto(char texto[],int tam, char mensaje[], char error[], int reintentos) //CLASE 6 TAREA EJ 1..
{
	int retornoAuxiliar;
    int retorno;
    char auxiliar[256];

    retorno = 0;

    if(texto != NULL && tam > 0 && mensaje != NULL && error != NULL && reintentos >= 0)
    {
    	do
		{
			retornoAuxiliar = getString(auxiliar, sizeof(auxiliar), mensaje);

			if(retornoAuxiliar == 1)
			{
				strncpy(texto,auxiliar,tam-1);
				retorno = -1;
				if(strlen(auxiliar)<tam)
				{
					retorno = 1;
				}
				break;
			}

			printf("%s\n", error);
			reintentos--;
		}while(reintentos >= 0);
    }


	return retorno;
}

int utn_PedirCuit(char cuit[], int tam, char mensaje[], char error[], int reintentos)
{
	int retornoAuxiliar;
	int retorno;
	char auxiliar[256];

	retorno = 0;

	if(cuit != NULL && tam > 0 && mensaje != NULL && error != NULL && reintentos >= 0)
	{
		do
		{
			retornoAuxiliar = getCuit(auxiliar, sizeof(auxiliar), mensaje);

			if(retornoAuxiliar == 1)
			{
				strncpy(cuit,auxiliar,tam-1);
				retorno = -1;
				if(strlen(auxiliar)<tam)
				{
					retorno = 1;
				}
				break;
			}

			printf("%s\n", error);
			reintentos--;
		}while(reintentos >= 0);
	}


	return retorno;
}

