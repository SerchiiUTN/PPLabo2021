/*
 * ePedido.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Sergio
 */

#ifndef EPEDIDO_H_
#define EPEDIDO_H_

#include "eCliente.h"
#define EMPTY 0
#define FULL 1

typedef struct
{
	int idPedido;
	float kilosTotales;
	int idCliente;
	int estado;
	float kilosHDPE;
	float kilosLDPE;
	float kilosPP;
	int isEmpty;
}ePedido;

/// @fn int ePedido_InicializarPedidos(ePedido[], int)
/// @brief Inicializa el campo "isEmpty" de los pedidos en 0 (EMPTY)
///
/// @param pedidos -> Array de pedidos
/// @param tam -> Tamaño de pedidos
/// @return Retorna 1 (OK) o 0 (Error)
int ePedido_InicializarPedidos(ePedido pedidos[], int tam);

/// @fn int ePedido_BuscarPrimerEspacioLibre(ePedido[], int)
/// @brief Busca el primer espacio libre del array y retorna el indice
///
/// @param pedidos -> Array de pedidos
/// @param tam -> Tamaño del array
/// @return Retorna -1 (Error) o el indice del primer espacio libre
int ePedido_BuscarPrimerEspacioLibre(ePedido pedidos[], int tam);

/// @fn int ePedido_BuscarPedidoPendientePorCliente(ePedido[], int, int)
/// @brief Busca si el cliente con el ID ingresado tiene pedidos pendientes,
/// 		si lo encuentra retorna el indice
///
/// @param pedidos -> Array de pedidos
/// @param tam -> Tamaño del array
/// @param id -> ID del cliente
/// @return Retorna -1 (No encontro pedidos pendientes para ese cliente) o el indice del cliente
int ePedido_BuscarPedidoPendientePorCliente(ePedido pedidos[], int tam, int id);

/// @fn int ePedido_CargarUnPedido(ePedido[], int, eCliente[], int, int*)
/// @brief Pide por consola el ID del cliente y los kg totales a reciclar,
/// 		luego genera un nuevo pedido.
///
/// @param pedidos -> Array de pedidos
/// @param tamPedidos ->Tamaño del array pedidos
/// @param clientes -> Array de clientes
/// @param tamClientes -> Tamaño del array clientes
/// @param ultimoPedido -> Ultimo pedido ingresado (0 si no se ingreso ninguno)
/// @return Retorna 1 (OK),  0 (Si no se pudo cargar el pedido) o -1 (Si los parametros no son validos)
int ePedido_CargarUnPedido(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int* ultimoPedido);



/// @fn int ePedido_ContarPedidos(ePedido[], int, int, int)
/// @brief  Cuenta los pedidos activos de un cliente segun el modo indicado
///
/// @param pedidos -> Lista de pedidos
/// @param tam -> Tamaño de la lista
/// @param idCliente -> ID del cliente
/// @param modo -> 1 (Pendientes), 2 (Completados), si se ingresa cualquier otro entero contara
/// 		pendientes y completados
/// @return Retorna la cantidad de pedidos que tiene ese cliente segun el modo
int ePedido_ContarPedidos(ePedido pedidos[], int tam, int idCliente, int modo);

/// @fn int ePedido_MostrarUnPedido(ePedido, int)
/// @brief Muestra por consola los datos de un pedido dependiendo el modo indicado
/// 		(1 - Pendiente o 2 - Completado)
///
/// @param pedido -> Puntero a estructura
/// @param modo -> Entero que indica que campos mostrara (1 - Pendiente o 2 - Completado)
/// @return Retorna 1 (Pudo mostrar al menos un pedido) o 0 (No encontro resultados)
int ePedido_MostrarUnPedido(ePedido pedido, int modo);

/// @fn int ePedido_MostrarPedidos(ePedido[], int, int)
/// @brief Muestra por consola los pedidos, dependiendo el modo mostrara pendientes o completados
///
/// @param pedidos -> Array de pedidos
/// @param tam -> Tamaño del array
/// @param modo -> Entero que indica que campos mostrara (1 - Pendiente o 2 - Completado)
/// @return Retorna 0 (No encontro resultados) o 1 (Encontro al menos un resultado)
int ePedido_MostrarPedidos(ePedido pedidos[], int tam, int modo);

/// @fn int ePedido_ProcesarResiduos(ePedido[], int)
/// @brief Procesa los pedidos pendientes separando el total de kg en tres tipos que se ingresaran
///			por consola
///
/// @param pedidos -> Array de pedidos
/// @param tam -> Tamaño del array
/// @return Retorna 1 (OK), 0 (Los parametros son incorrectos) o -1 (No se encontraron pedidos pendientes)
int ePedido_ProcesarResiduos(ePedido pedidos[],int tam);

#endif /* EPEDIDO_H_ */
