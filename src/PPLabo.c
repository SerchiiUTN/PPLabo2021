/*
 ============================================================================
 Name        : PPLabo.c
 Author      : Ledesma Sergio
 Version     : Final final full esta si (antes de la fecha del parcial)
 Copyright   : Your copyright notice
 Description : Primer Parcial de Laboratorio - ABM

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "eDireccion.h"
#include "eCliente.h"
#include "ePedido.h"
#include "Informes.h"
#include "utn.h"
#define TAMCLIENTES 5
#define TAMPEDIDOS 15
#define EMPTY 0
#define FULL 1



int main(void) {
	setbuf(stdout,NULL);
	eCliente clientes[TAMCLIENTES] =
			{
				{1,"CocaCola","30-45678912-3",{"Av. 25 de Mayo", 123},"CABA",FULL},
				{2,"Pepsi","30-45618912-3",{"Maipu",5800},"CABA",FULL},
				{3,"Culligan Argentina","30-12345685-2",{"Montenegro",1380},"Laferrere",FULL}
			};
	ePedido pedidos[TAMPEDIDOS];
	int opcion;
	int ultimoCliente;
	int ultimoPedido;
	int idAuxiliar;
	int retornoAuxiliar;

	ultimoCliente = 3;
	ultimoPedido = 0;

	//eCliente_InicializarClientes(clientes, TAMCLIENTES);
	ePedido_InicializarPedidos(pedidos, TAMPEDIDOS);


	printf("/***   ABM Reciclados   ***/\n");

	do
	{
		opcion = -1;

		printf(" 1 - Alta de cliente\n");
		printf(" 2 - Modificar datos de cliente\n");
		printf(" 3 - Baja de cliente\n");
		printf(" 4 - Crear pedido de recolección\n");
		printf(" 5 - Procesar residuos\n");
		printf(" 6 - Imprimir clientes\n");
		printf(" 7 - Imprimir pedidos pendientes\n");
		printf(" 8 - Imprimir pedidos procesados\n");
		printf(" 9 - Imprimir pedidos pendientes segun localidad\n");
		printf("10 - Promedio de kilos de polipropileno reciclado por cliente\n");
		printf(" 0 - Salir\n\n");

		utn_PedirEntero(&opcion,"Escoja una opcion: ","Opcion incorrecta, ingrese una opcion valida\n",0,10,0);

		switch(opcion)
		{
			case 1:
				retornoAuxiliar = eCliente_CargarUnCliente(clientes,TAMCLIENTES,&ultimoCliente);

				if(retornoAuxiliar == -1)
				{
					printf("\nSe excede el limite de clientes.\n\n");
				}
				else
				{
					if(retornoAuxiliar == 0)
					{
						printf("\nNo se pudo ingresar el cliente.\n\n");
					}
					else
					{
						printf("\nSe ha ingresado el cliente N° %d\n\n", ultimoCliente);
					}

				}

			break;
			case 2:

				retornoAuxiliar = eCliente_MostrarClientes(clientes, TAMCLIENTES);

				if(retornoAuxiliar == 0)
				{
					printf("\nNo hay clientes a modificar.\n\n");
				}
				else
				{
					retornoAuxiliar = eCliente_ModificarCliente(clientes, TAMCLIENTES);

					if(retornoAuxiliar == 1)
					{
						printf("\nSe ha modificado el cliente.\n\n");
					}
					else
					{
						printf("\nEl cliente no pudo ser modificado o no existe.\n\n");
					}
				}

			break;
			case 3:

				retornoAuxiliar = eCliente_MostrarClientes(clientes, TAMCLIENTES);

				if(retornoAuxiliar == 0)
				{
					printf("\nNo hay clientes a eliminar.\n\n");
				}
				else
				{
					retornoAuxiliar = utn_PedirEntero(&idAuxiliar,"Ingrese el ID del cliente: ","El ID es incorrecto, intente nuevamente", 1, 100,2);

					if(retornoAuxiliar != 1 || ePedido_BuscarPedidoPendientePorCliente(pedidos, TAMPEDIDOS, idAuxiliar) != -1)
					{
						printf("\nEl cliente ingresado es incorrecto o tiene pedidos pendientes\n\n");
					}
					else
					{
						retornoAuxiliar = eCliente_EliminarCliente(clientes, TAMCLIENTES, idAuxiliar);

						if(retornoAuxiliar == -1)
						{
							printf("\nLa operacion fue cancelada.\n\n");
						}
						else
						{
							if(retornoAuxiliar == 0)
							{
								printf("\nEl cliente ya fue eliminado o no existe.\n\n");
							}
							else
							{
								printf("\nSe ha eliminado al cliente.\n\n");
							}
						}
					}
				}

			break;
			case 4:
				retornoAuxiliar = eCliente_MostrarClientes(clientes, TAMCLIENTES);

				if(retornoAuxiliar == 0)
				{
					printf("\nNo hay clientes a mostrar.\n\n");
				}
				else
				{
					retornoAuxiliar = ePedido_CargarUnPedido(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, &ultimoPedido);

					if(retornoAuxiliar == -1)
					{
						printf("\nEl cliente no existe.\n\n");
					}
					else
					{
						if(retornoAuxiliar == 0)
						{
							printf("\nNo se ha podido ingresar el pedido.\n\n");
						}
						else
						{
							printf("\nEl pedido N° %d se ingreso correctamente.\n\n",ultimoPedido);
						}
					}
				}

			break;
			case 5:
				if(ultimoPedido == 0)
				{
					printf("\nNo hay pedidos cargados.\n\n");
				}
				else
				{
					retornoAuxiliar = ePedido_MostrarPedidos(pedidos, TAMPEDIDOS,1);

					if(retornoAuxiliar == 0)
					{
						printf("\nNo hay pedidos a mostrar.\n\n");
					}
					else
					{
						retornoAuxiliar = ePedido_ProcesarResiduos(pedidos, TAMPEDIDOS);

						if(retornoAuxiliar == -1)
						{
							printf("\nEl total de kg a reciclar no coincide con el total ingresado.\n\n");
						}
						else
						{
							if(retornoAuxiliar == 0)
							{
								printf("\nNo se pudo procesar el pedido o ya ha sido procesado.\n\n");
							}
							else
							{
								printf("\nEl pedido se proceso correctamente.\n\n");
							}
						}
					}
				}

			break;
			case 6:
				retornoAuxiliar = Informes_ImprimirClientesConPedidosPendientes(clientes, TAMCLIENTES, pedidos, TAMPEDIDOS, ultimoPedido);

				if(retornoAuxiliar == -1)
				{
					printf("\nNo hay pedidos cargados.\n\n");
				}
				else
				{
					if(retornoAuxiliar == 0)
					{
						printf("\nNo hay clientes cargados.\n\n");
					}

				}
			break;
			case 7:
				retornoAuxiliar = Informes_ImprimirPedidosPendientesConDatosCliente(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, ultimoPedido);

				if(retornoAuxiliar == -1)
				{
					printf("\nNo hay pedidos cargados.\n\n");
				}
				else
				{
					if(retornoAuxiliar == 0)
					{
						printf("\nNo hay pedidos pendientes.\n\n");
					}

				}
			break;
			case 8:
				retornoAuxiliar = Informes_ImprimirPedidosCompletadosConDatosCliente(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, ultimoPedido);

				if(retornoAuxiliar == -1)
				{
					printf("\nNo hay pedidos cargados.\n\n");
				}
				else
				{
					if(retornoAuxiliar == 0)
					{
						printf("\nNo hay pedidos completados.\n\n");
					}

				}
			break;
			case 9:
				retornoAuxiliar = Informes_ImprimirPedidosPendientesSegunLocalidad(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, ultimoPedido);

				if(retornoAuxiliar == -1)
				{
					printf("\nNo hay pedidos cargados.\n\n");
				}
				else
				{
					if(retornoAuxiliar == 0)
					{
						printf("\nNo se encontraron registros con la localidad ingresada.\n\n");
					}

				}
			break;
			case 10:
				retornoAuxiliar = Informes_ImprimirPromedioKgPolipropilenoPorCliente(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, ultimoCliente, ultimoPedido);

				if(retornoAuxiliar == -1)
				{
					printf("\nNo hay pedidos cargados.\n\n");
				}
				else
				{
					if(retornoAuxiliar == 0)
					{
						printf("\nNo se encontraron clientes ingresados.\n\n");
					}

				}
			break;
			case 0:
				printf("\nHasta luego!\n\n");
			break;
		}

	}while(opcion != 0);

	return EXIT_SUCCESS;
}

