/*
 * Informes.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Sergio
 */

#include "Informes.h"


int Informes_ImprimirClientesConPedidosPendientes(eCliente clientes[], int tamClientes, ePedido pedidos[], int tamPedidos, int ultimoPedido)
{
	int retorno;
	int cantidadPedidos;

	retorno = 0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && eCliente_VerificarClientes(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0)
		{
			retorno = -1;
		}
		else
		{
			printf("\nClientes activos: \n");

			for(int i = 0; i < tamClientes; i++)
			{
				if(clientes[i].isEmpty == FULL)
				{
					retorno = 1;
					printf("N°   - Empresa  \t  \t      - CUIT\t      - Direccion\t\t    - Localidad\n");
					eCliente_MostrarUnCliente(clientes[i]);
					cantidadPedidos = ePedido_ContarPedidosPendientes(pedidos,tamPedidos, clientes[i].idCliente);

					if(cantidadPedidos == 0)
					{
						printf("Pedidos pendientes : No hay pedidos pendientes.\n\n");
						continue;
					}

					printf("Pedidos pendientes : %d\n\n",cantidadPedidos);

				}
			}
		}
	}

	return retorno;
}

int Informes_ImprimirPedidosPendientesConDatosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido)
{
	int retorno;

	retorno = 0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && eCliente_VerificarClientes(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0)
		{
			retorno = -1;
		}
		else
		{
			printf("\nPedidos pendientes: \n");

			for(int i = 0; i < tamPedidos; i++)
			{
				if(pedidos[i].isEmpty == FULL && strcmp(pedidos[i].estado, "Pendiente") == 0)
				{
					ePedido_MostrarUnPedido(pedidos[i],1);
					eCliente_MostrarDatosClienteEnPedido(clientes,tamClientes,pedidos[i].idCliente);
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

int Informes_ImprimirPedidosCompletadosConDatosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido)
{
	int retorno;
	int retornoAuxiliar;

	retorno = 0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && eCliente_VerificarClientes(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0)
		{
			retorno = -1;
		}
		else
		{
			printf("\nPedidos completados: \n\n");

			for(int i = 0; i < tamPedidos; i++)
			{
				if(pedidos[i].isEmpty == FULL && strcmp(pedidos[i].estado, "Completado") == 0)
				{
					ePedido_MostrarUnPedido(pedidos[i],2);
					retornoAuxiliar = eCliente_MostrarDatosClienteEnPedido(clientes,tamClientes,pedidos[i].idCliente);
					retorno = 1;

					if(retornoAuxiliar == 0)
					{
						printf("El cliente de este pedido fue eliminado\n\n");
					}
				}

			}


		}
	}

	return retorno;
}

int Informes_ImprimirPedidosPendientesSegunLocalidad(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido)
{
	int retorno;
	char localidad[sizeof(clientes[0].localidad)];
	int acumuladorPedidos;
	int cantidadPedidos;

	acumuladorPedidos = 0;
	retorno = 0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && eCliente_VerificarClientes(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0)
		{
			retorno = -1;
		}
		else
		{
			if(utn_PedirTexto(localidad,sizeof(localidad),"Ingrese una localidad : ","El dato ingresado es incorrecto.",2) == 1)
			{
				for(int i = 0; i < tamClientes; i++)
				{
					if(clientes[i].isEmpty == FULL && stricmp(clientes[i].localidad, localidad) == 0)
					{
						retorno = 1;
						cantidadPedidos = ePedido_ContarPedidosPendientes(pedidos,tamPedidos,clientes[i].idCliente);
						acumuladorPedidos += cantidadPedidos;

					}
				}

				if(acumuladorPedidos == 0)
				{
					printf("\nNo hay pedidos pendientes en la localidad ingresada.\n\n");

				}
				else
				{
					printf("\n%s : \nPedidos pendientes : %d\n\n",localidad,acumuladorPedidos);

				}

			}
		}
	}

	return retorno;
}

int Informes_ImprimirPromedioKgPolipropilenoPorCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente)
{
	int retorno;
	float acumuladorKilosPP;
	float promedio;

	retorno = 0;
	acumuladorKilosPP = 0;

	if(pedidos != NULL && tamPedidos > 0 && eCliente_VerificarClientes(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0)
		{
			retorno = -1;
		}
		else
		{
			for(int i = 0; i < tamPedidos; i++)
			{
				retorno = 1;

				if(pedidos[i].isEmpty == FULL && strcmp(pedidos[i].estado, "Completado") == 0)
				{
					acumuladorKilosPP += pedidos[i].kilosPP;
				}
			}
			if(acumuladorKilosPP == 0)
			{
				printf("\nNo hay kilos de Polipropileno ingresados.\n\n");

			}
			else
			{
				promedio = acumuladorKilosPP / ultimoCliente;
				printf("\nEl promedio de Kilos de Polipropileno por cliente es de : %.2f\n\n",promedio);
			}

		}
	}

	return retorno;
}

