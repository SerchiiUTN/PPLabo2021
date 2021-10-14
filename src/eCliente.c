/*
 * eCliente.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Sergio
 */

#include "eCliente.h"

int eCliente_InicializarClientes(eCliente clientes[], int tam)
{
	int retorno;
	int i;


	retorno = 0;

	if(clientes != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			clientes[i].isEmpty = EMPTY;
		}
		retorno = 1;
	}

	return retorno;
}

/*
 * ESTA SI
 *
 * */
int eCliente_BuscarPrimerEspacioLibre(eCliente clientes[], int tam)
{
	int index;
	int i;

	index = -1;

	if(clientes != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(clientes[i].isEmpty == EMPTY)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

/*
 * ESTA FUNCION NO VA
 *
 *
int eCliente_BuscarEspacioNuevoCliente(eCliente clientes[], int tam, int id)
{
	int index;

	index = -1;

	if(clientes != NULL && tam > 0 && id < tam)
	{
		if(clientes[id].isEmpty == EMPTY)
		{
			index = id;
		}

	}

	return index;
}
*/

int eCliente_IngresarUnCliente(eCliente* cliente)
{
	int retorno;
	eCliente clienteAuxiliar;

	retorno = 0;

	if(cliente != NULL)
	{
		if(
			utn_PedirTexto(clienteAuxiliar.empresa, 51, "Ingrese el nombre de la empresa: ", "Error, ingrese un nombre valido", 2) == 1 &&
			utn_PedirCuit(clienteAuxiliar.cuit, sizeof(clienteAuxiliar.cuit), "Ingrese el CUIT con guiones (XX-XXXXXXXX-X): ", "Error, intente nuevamente", 2) == 1 &&
			eDireccion_IngresarDireccion(&clienteAuxiliar.direccion) == 1		&&
			eLocalidad_IngresarLocalidad(&clienteAuxiliar.localidad) == 1
		  )
		{
			retorno = 1;
			*cliente = clienteAuxiliar;
		}
	}


	return retorno;
}

int eCliente_CargarUnCliente(eCliente clientes[], int tam, int* ultimoId)
{
	int retorno;
	int id;
	eCliente clienteAuxiliar;
	int index;
	int retornoAuxiliar;

	retorno = -1;
	id = *ultimoId;

	if(clientes != NULL && tam > 0)
	{
		index = eCliente_BuscarPrimerEspacioLibre(clientes, tam);

		if(index != -1)
		{
			retorno = 0;
			retornoAuxiliar = eCliente_IngresarUnCliente(&clienteAuxiliar);
			if(retornoAuxiliar == 1)
			{
				id++;
				*ultimoId = id;
				clientes[index] = clienteAuxiliar;
				clientes[index].idCliente = id;
				clientes[index].isEmpty = FULL;
				retorno = 1;
			}
		}
	}


	return retorno;
}

int eCliente_BuscarClientePorID(eCliente clientes[], int tam, int id)
{
	int index;
	int i;

	index = -1;

	if(clientes != NULL && tam > 0 && id <= tam)
	{
		for(i = 0; i < tam; i++)
		{
			if(clientes[i].idCliente == id && clientes[i].isEmpty == FULL)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int eCliente_ModificarCliente(eCliente clientes[], int tam)
{
	int retorno;
	int index;
	int id;
	eCliente auxiliar;

	retorno = 0;

	if(clientes != NULL && tam > 0 && utn_PedirEntero(&id,"Ingrese el ID del cliente: ","El ID es incorrecto, intente nuevamente", 1, tam,2) == 1)
	{
		index = eCliente_BuscarClientePorID(clientes, tam, id);

		if(
				index != -1 		&&
				clientes[index].isEmpty == FULL &&
				eDireccion_IngresarDireccion(&auxiliar.direccion) == 1 &&
				eLocalidad_IngresarLocalidad(&auxiliar.localidad) == 1
			)
		{
			clientes[index] = auxiliar;
			retorno = 1;
		}
	}


	return retorno;
}

int eCliente_EliminarCliente(eCliente clientes[], int tam, int id)
{
	int retorno;
	int respuesta;
	int index;

	respuesta = 0;
	retorno = 0;



	if(clientes != NULL && tam > 0)
	{
		index = eCliente_BuscarClientePorID(clientes, tam, id);

		if(index != -1 && clientes[index].isEmpty == FULL)
		{
			retorno = -1;
			printf("\nEsta a punto de eliminar al cliente N° %d.\n¿Estas seguro?\n",clientes[index].idCliente);


			if(utn_PedirEntero(&respuesta,"1 - Si\n2 - No\nRespuesta: ","La opcion ingresada no es valida, intente nuevamente.",1,2,2) == 1 && respuesta == 1)
			{
				clientes[index].isEmpty = EMPTY;
				retorno = 1;
			}
		}


	}


	return retorno;
}

int eCliente_VerificarClientes(eCliente clientes[], int tam)
{
	int retorno;

	retorno = 0;

	if(clientes != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(clientes[i].isEmpty == FULL)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int eCliente_MostrarUnCliente(eCliente cliente)
{
	int retorno;

	retorno = 0;


	printf("%4d - %30s -%14s - ",cliente.idCliente,cliente.empresa,cliente.cuit);
	eDireccion_MostrarDireccion(cliente.direccion);
	printf(" - %20s\n",cliente.localidad.localidad);
	retorno = 1;


	return retorno;
}

int eCliente_MostrarDatosClienteEnPedido(eCliente clientes[], int tam, int idCliente)
{
	int retorno;
	int index;

	retorno = 0;

	if(clientes != NULL && tam > 0)
	{
		index = eCliente_BuscarClientePorID(clientes, tam, idCliente);

		if(index != -1)
		{
			printf("CUIT : %s \nDireccion : ",clientes[index].cuit);
			eDireccion_MostrarDireccion(clientes[index].direccion);
			printf("\nLocalidad : %s \n\n",clientes[index].localidad.localidad);
			retorno = 1;
		}
	}


	return retorno;
}

int eCliente_MostrarClientes(eCliente clientes[], int tam)
{
	int retorno;

	retorno = 0;

	if(clientes != NULL && tam > 0 && eCliente_VerificarClientes(clientes,tam) == 1)
	{
		printf("\nClientes activos: \n");
		printf("N°   - Empresa  \t  \t      - CUIT\t      - Direccion\t\t    - Localidad\n");
		for(int i = 0; i < tam; i++)
		{
			if(clientes[i].isEmpty == FULL)
			{
				eCliente_MostrarUnCliente(clientes[i]);
			}

		}
		retorno = 1;
	}

	return retorno;
}


