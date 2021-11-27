/*
 * Informes.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Sergio
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "eCliente.h"
#include "ePedido.h"
#define EMPTY 0
#define FULL 1


/// @fn int Informes_ImprimirClientesConPedidosPendientes(eCliente[], int, ePedido[], int, eLocalidad[], int, int)
/// @brief Imprime los clientes y la cantidad de pedidos pendientes que tiene cada uno
///
/// @param clientes -> Lista de clientes
/// @param tamClientes -> Tamaño de la lista
/// @param pedidos -> Lista de pedidos
/// @param tamPedidos -> Tamaño de la lista
/// @param localidades -> Lista de localidades
/// @param tamLocalidades -> Tamaño de la lista
/// @param ultimoPedido -> ultimo pedido cargado
/// @return -> Retorna 1 (OK), 0 (Error) o -1 (Sin pedidos)
int Informes_ImprimirClientesConPedidosPendientes(eCliente clientes[], int tamClientes, ePedido pedidos[], int tamPedidos, eLocalidad localidades[], int tamLocalidades, int ultimoPedido);

/// @fn int Informes_ImprimirPedidosPendientesConDatosCliente(ePedido[], int, eCliente[], int, eLocalidad[], int, int)
/// @brief Imprime la lista de pedidos pendientes con los datos del cliente
///
/// @param pedidos -> Lista de pedidos
/// @param tamPedidos -> Tamaño de la lista
/// @param clientes -> Lista de clientes
/// @param tamClientes -> Tamaño de la lista
/// @param localidades -> Lista de localidades
/// @param tamLocalidades -> Tamaño de la lista
/// @param ultimoPedido -> ultimo pedido cargado
/// @return -> Retorna 1 (OK), 0 (Error) o -1 (Sin pedidos)
int Informes_ImprimirPedidosPendientesConDatosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidades, int ultimoPedido);

/// @fn int Informes_ImprimirPedidosCompletadosConDatosCliente(ePedido[], int, eCliente[], int, eLocalidad[], int, int)
/// @brief Imprime la lista de pedidos completados con los datos del cliente (si no fue eliminado)
///
/// @param pedidos -> Lista de pedidos
/// @param tamPedidos -> Tamaño de la lista
/// @param clientes -> Lista de clientes
/// @param tamClientes -> Tamaño de la lista
/// @param localidades -> Lista de localidades
/// @param tamLocalidades -> Tamaño de la lista
/// @param ultimoPedido -> ultimo pedido cargado
/// @return -> Retorna 1 (OK), 0 (Error) o -1 (Sin pedidos)
int Informes_ImprimirPedidosCompletadosConDatosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidades, int ultimoPedido);

/// @fn int Informes_ImprimirPedidosPendientesSegunLocalidad(ePedido[], int, eCliente[], int, eLocalidad[], int, int)
/// @brief Le pide al usuario que ingrese una localidad y si hay pedidos pendientes los muestra
///
/// @param pedidos -> Lista de pedidos
/// @param tamPedidos -> Tamaño de la lista
/// @param clientes -> Lista de clientes
/// @param tamClientes -> Tamaño de la lista
/// @param localidades -> Lista de localidades
/// @param tamLocalidades -> Tamaño de la lista
/// @param ultimoPedido -> ultimo pedido cargado
/// @return -> Retorna 1 (OK), 0 (Error) o -1 (Sin pedidos)
int Informes_ImprimirPedidosPendientesSegunLocalidad(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidades, int ultimoPedido);

/// @fn int Informes_ImprimirPromedioKgPolipropilenoPorCliente(ePedido[], int, eCliente[], int, int, int)
/// @brief Calcula el promedio de kilos de polipropileno por cliente (si es que hay)
///
/// @param pedidos -> Array de pedidos
/// @param tamPedidos -> Tamaño del array pedidos
/// @param clientes -> Array de Clientes
/// @param tamClientes -> Tamaño del array Clientes
/// @param ultimoPedido -> Ultimo pedido realizado
/// @param ultimoCliente -> Ultimo cliente registrado
/// @return Retorna 1 (OK), 0 (Parametros incorrectos) o -1(No encontro pedidos)
int Informes_ImprimirPromedioKgPolipropilenoPorCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente);

/// @fn int Informes_ClientesConMasPedidos(ePedido[], int, eCliente[], int, int, int, int)
/// @brief
///
/// @param pedidos -> Array de pedidos
/// @param tamPedidos -> Tamaño del array pedidos
/// @param clientes -> Array de Clientes
/// @param tamClientes -> Tamaño del array Clientes
/// @param ultimoPedido -> Ultimo pedido realizado
/// @param ultimoCliente -> Ultimo cliente registrado
/// @param modo -> 1 (Pendientes), 2 (Completados), si se ingresa cualquier otro entero contara
/// 		pendientes y completados
/// @return Retorna 1 (OK), 0 (Parametros incorrectos) o -1(No encontro pedidos)
int Informes_ClientesConMasPedidos(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente, int modo);

#endif /* INFORMES_H_ */
