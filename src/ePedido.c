/*
 * ePedido.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Sergio
 */

#include "ePedido.h"


int ePedido_InicializarPedidos(ePedido pedidos[], int tam)
{
	int retorno;
	int i;

	retorno = 0;

	if(pedidos != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			pedidos[i].isEmpty = EMPTY;
		}
		retorno = 1;
	}

	return retorno;
}

int ePedido_BuscarPrimerEspacioLibre(ePedido pedidos[], int tam)
{
	int index;
	int i;

	index = -1;

	if(pedidos != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(pedidos[i].isEmpty == EMPTY)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int ePedido_BuscarPedidoPendientePorCliente(ePedido pedidos[], int tam, int id)
{
	int index;
	int i;

	index = -1;

	if(pedidos != NULL && tam > 0 && id <= tam)
	{
		for(i = 0; i < tam; i++)
		{
			if(pedidos[i].idCliente == id && strcmp(pedidos[i].estado,"Pendiente") == 0)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

/*
 * ESTA NO VA
 *
 * */
/*
int ePedido_BuscarEspacioNuevoPedido(ePedido pedidos[], int tam, int id)
{
	int index;

	index = -1;

	if(pedidos != NULL && tam > 0 && id < tam)
	{
		if(pedidos[id].isEmpty == EMPTY)
		{
			index = id;
		}

	}

	return index;
}
*/

int ePedido_BuscarPedidoPorID(ePedido pedidos[], int tam, int id)
{
	int index;
	int i;

	index = -1;

	if(pedidos != NULL && tam > 0 && id <= tam)
	{
		for(i = 0; i < tam; i++)
		{
			if(pedidos[i].idPedido == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int ePedido_SepararResiduos(ePedido* pedido)
{
	int retorno;
	ePedido pedidoAuxiliar;
	float totalKgAuxiliar;
	float acumulador;
	int retornoAuxiliar;

	pedidoAuxiliar = *pedido;
	retorno = 0;
	acumulador = 0;

	if(pedido != NULL)
	{
		totalKgAuxiliar = pedidoAuxiliar.kilosTotales;
		printf("El total de kilos es de %.2f\n", totalKgAuxiliar);
		retornoAuxiliar = utn_PedirFlotante(&pedidoAuxiliar.kilosHDPE, "Ingrese la cantidad de kilos de HDPE: ", "El valor es incorrecto, intente nuevamente.",0,totalKgAuxiliar,2);
		acumulador += pedidoAuxiliar.kilosHDPE;
		retorno = -1;
		if(retornoAuxiliar == 1 &&	acumulador <= totalKgAuxiliar)
		{
			printf("El total de kilos restante es de %.2f\n", totalKgAuxiliar-acumulador);
			utn_PedirFlotante(&pedidoAuxiliar.kilosLDPE, "Ingrese la cantidad de kilos de LDPE: ", "El valor es incorrecto, intente nuevamente.",0,totalKgAuxiliar,2);
			acumulador += pedidoAuxiliar.kilosLDPE;

			if(retornoAuxiliar == 1 &&	acumulador <= totalKgAuxiliar)
			{
				printf("El total de kilos restante es de %.2f\n", totalKgAuxiliar-acumulador);
				utn_PedirFlotante(&pedidoAuxiliar.kilosPP, "Ingrese la cantidad de kilos de PP: ", "El valor es incorrecto, intente nuevamente.",0,totalKgAuxiliar,2);
				acumulador += pedidoAuxiliar.kilosPP;

				if(retornoAuxiliar == 1 &&	acumulador <= totalKgAuxiliar)
				{
					*pedido = pedidoAuxiliar;
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

int ePedido_CargarUnPedido(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int* ultimoPedido)
{
	int retorno;
	int idPedido;
	int idCliente;
	int index;
	int retornoAuxiliar;
	int idAuxiliar;
	float kilosAuxiliar;

	retorno = -1;
	idPedido = *ultimoPedido;



	if(pedidos != NULL && tamPedidos > 0)
	{
		index = ePedido_BuscarPrimerEspacioLibre(pedidos, tamPedidos);

		if(index != -1)
		{
			retornoAuxiliar = utn_PedirEntero(&idCliente,"Ingrese el N° de Cliente al que se el asignara el pedido: ","El numero es incorrecto, intente nuevamente.",1,tamClientes,2);

			if(retornoAuxiliar == 1 )
			{
				idAuxiliar = eCliente_BuscarClientePorID(clientes,tamClientes,idCliente);

				if(idAuxiliar != -1)
				{
					retornoAuxiliar = utn_PedirFlotante(&kilosAuxiliar, "Ingrese el total de kg a reciclar (2000 Maximo): ", "Error, ingrese un peso valido", 0, 2000, 2);
					retorno = 0;

					if(retornoAuxiliar == 1)
					{
						idPedido++;
						*ultimoPedido = idPedido;
						pedidos[index].kilosTotales = kilosAuxiliar;
						pedidos[index].idPedido = idPedido;
						pedidos[index].idCliente = idCliente;
						strcpy(pedidos[index].estado, "Pendiente");
						pedidos[index].isEmpty = FULL;
						retorno = 1;
					}
				}
			}
		}
	}

	return retorno;
}

int ePedido_ContarPedidosPendientes(ePedido pedidos[], int tam, int idCliente)
{
	int contador;


	contador = 0;

	if(pedidos != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(pedidos[i].isEmpty == FULL && strcmp(pedidos[i].estado,"Pendiente") == 0 && pedidos[i].idCliente == idCliente)
			{
				contador++;
			}

		}

	}

	return contador;
}

int ePedido_MostrarUnPedido(ePedido pedido, int modo)
{
	int retorno;

	retorno = 0;

	if(modo == 1 && strcmp(pedido.estado, "Pendiente") == 0)//Modo 1 : Pendiente
	{
		printf("N°Pedido : %d \nKg Totales: %.2f \nEstado: %s\n",pedido.idPedido, pedido.kilosTotales, pedido.estado);
		retorno = 1;
	}

	if(modo == 2 && strcmp(pedido.estado, "Completado") == 0)//Modo 2 : Completado
	{
		printf("N°Pedido : %d \nKg HDPE: %.2f \nKg LDPE: %.2f \nKg PP: %.2f \nEstado: %s\n",pedido.idPedido, pedido.kilosHDPE, pedido.kilosLDPE , pedido.kilosPP , pedido.estado);
		retorno = 1;
	}

	return retorno;
}

int ePedido_MostrarPedidos(ePedido pedidos[], int tam, int modo)
{
	int retorno;
	int retornoAuxiliar;

	retorno = 0;

	if(pedidos != NULL && tam > 0)
	{
		printf("Pedidos: \n");
		for(int i = 0; i < tam; i++)
		{
			if(pedidos[i].isEmpty == FULL && strcmp(pedidos[i].estado,"Pendiente") == 0)
			{
				retornoAuxiliar = ePedido_MostrarUnPedido(pedidos[i],modo);
				printf("\n");
				retorno = 1;
			}

			if(retornoAuxiliar == 0)
			{
				retorno = 0;
			}

		}
	}

	return retorno;
}

int ePedido_MostrarPedidosPorCliente(ePedido pedidos[], int tam, int idCliente, int modo)
{
	int retorno;

	retorno = 0;

	if(pedidos != NULL && tam > 0)
	{
		printf("Pedidos: \n");
		for(int i = 0; i < tam; i++)
		{
			if(pedidos[i].idCliente == idCliente && pedidos[i].isEmpty == FULL && modo == 1)
			{
				ePedido_MostrarUnPedido(pedidos[i],modo);
				printf("\n");
				retorno = 1;
			}
		}
	}

	return retorno;
}

int ePedido_ProcesarResiduos(ePedido pedidos[],int tam)
{
	int retorno;
	int id;
	int retornoAuxiliar;
	int index;
	ePedido pedidoAuxiliar;

	retorno = 0;

	if(pedidos != NULL && tam > 0)
	{
		retornoAuxiliar = utn_PedirEntero(&id,"Ingrese el N° de Pedido a procesar: ","El numero es incorrecto, intente nuevamente.",1,tam,2);

		if(retornoAuxiliar == 1)
		{
			index = ePedido_BuscarPedidoPorID(pedidos,tam,id);

			if(index != -1 && strcmp(pedidos[index].estado, "Pendiente") == 0)
			{
				pedidoAuxiliar = pedidos[index];
				retornoAuxiliar = ePedido_SepararResiduos(&pedidoAuxiliar);
				retorno = -1;

				if(retornoAuxiliar == 1)
				{
					pedidos[index] = pedidoAuxiliar;
					strcpy(pedidos[index].estado,"Completado");
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}
