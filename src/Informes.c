/*
 * Informes.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Sergio
 */

#include "Informes.h"


int Informes_ImprimirClientesConPedidosPendientes(eCliente clientes[], int tamClientes, ePedido pedidos[], int tamPedidos, eLocalidad localidades[], int tamLocalidades, int ultimoPedido)
{
	int retorno;
	int cantidadPedidos;

	retorno = 0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && localidades != NULL && tamLocalidades > 0 &&eCliente_VerificarClientes(clientes,tamClientes) == 1)
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
					eCliente_MostrarUnCliente(clientes[i],localidades,tamLocalidades);
					cantidadPedidos = ePedido_ContarPedidos(pedidos,tamPedidos, clientes[i].idCliente, 1);

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

int Informes_ImprimirPedidosPendientesConDatosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidades, int ultimoPedido)
{
	int retorno;

	retorno = 0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && localidades != NULL && tamLocalidades > 0 && eCliente_VerificarClientes(clientes,tamClientes) == 1)
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
				if(pedidos[i].isEmpty == FULL && pedidos[i].estado == 1)
				{
					ePedido_MostrarUnPedido(pedidos[i],1);
					eCliente_MostrarDatosClienteEnPedido(clientes,tamClientes,localidades,tamLocalidades,pedidos[i].idCliente);

					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

int Informes_ImprimirPedidosCompletadosConDatosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidades, int ultimoPedido)
{
	int retorno;
	int retornoAuxiliar;

	retorno = 0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && localidades != NULL && tamLocalidades > 0 && eCliente_VerificarClientes(clientes,tamClientes) == 1)
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
				if(pedidos[i].isEmpty == FULL && pedidos[i].estado == 2)
				{
					ePedido_MostrarUnPedido(pedidos[i],2);
					retornoAuxiliar = eCliente_MostrarDatosClienteEnPedido(clientes,tamClientes,localidades, tamLocalidades,pedidos[i].idCliente);
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

int Informes_ImprimirPedidosPendientesSegunLocalidad(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidades, int ultimoPedido)
{
	int retorno;
	int auxLocalidad;
	int acumuladorPedidos;
	int cantidadPedidos;

	acumuladorPedidos = 0;
	retorno = 0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && localidades != NULL && tamLocalidades > 0 && eCliente_VerificarClientes(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0)
		{
			retorno = -1;
		}
		else
		{
			if(eLocalidad_MostrarLocalidades(localidades, tamLocalidades) == 1 && utn_PedirEntero(&auxLocalidad,"Ingrese la localidad: ","La localidad ingresada no es valida",1,tamLocalidades,2) == 1)
			{
				for(int i = 0; i < tamClientes; i++)
				{
					if(clientes[i].isEmpty == FULL && auxLocalidad == clientes[i].localidad)
					{
						retorno = 1;
						cantidadPedidos = ePedido_ContarPedidos(pedidos,tamPedidos,clientes[i].idCliente, 1);
						acumuladorPedidos += cantidadPedidos;

					}
				}

				if(acumuladorPedidos == 0)
				{
					printf("\nNo hay pedidos pendientes en la localidad ingresada.\n\n");

				}
				else
				{
					printf("\nPedidos pendientes : %d\n\n",acumuladorPedidos);

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

				if(pedidos[i].isEmpty == FULL && pedidos[i].estado == 2)
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

int Informes_ClientesConMasPedidos(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente, int modo)
{
	int retorno;
	int i;
	int cantidadPedidos;
	int mayorCantidad;
	int primerPedido;
	int index;

	primerPedido = 0;
	retorno = 0;

	if(clientes != NULL && tamClientes > 0 && pedidos != NULL && tamPedidos > 0 && eCliente_VerificarClientes(clientes,tamClientes) == 1)
	{
		if(ultimoPedido == 0 || ultimoCliente == 0)
		{
			retorno = -1;
		}
		else
		{
			for(i = 0; i < tamClientes; i++)
			{
				if(clientes[i].isEmpty == FULL)
				{

					cantidadPedidos = ePedido_ContarPedidos(pedidos,tamPedidos, clientes[i].idCliente, modo);

					if(primerPedido == 0 || mayorCantidad < cantidadPedidos)
					{
						mayorCantidad = cantidadPedidos;
						index = i;
						primerPedido = 1;
						retorno = 1;
					}
				}
			}

			if(mayorCantidad != 0)
			{

				if(modo == 1)
				{
					printf("\nCliente con mas pedidos pendientes: \n");
					printf("%d - %s : %d pedidos\n\n",clientes[index].idCliente,clientes[index].empresa, mayorCantidad);

				}
				else
				{
					if(modo == 2)
					{
						printf("\nCliente con mas pedidos completados: \n");
						printf("%d - %s : %d pedidos\n\n",clientes[index].idCliente,clientes[index].empresa, mayorCantidad);

					}
					else
					{
						printf("\nCliente con mas pedidos: \n");
						printf("%d - %s : %d pedidos\n\n",clientes[index].idCliente,clientes[index].empresa, mayorCantidad);

					}
				}
			}
			else
			{
				printf("\nNo se encontraron pedidos\n\n");
			}

		}
	}

	return retorno;
}
