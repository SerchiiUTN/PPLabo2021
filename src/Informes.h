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
#include "Auxiliar.h"
#define EMPTY 0
#define FULL 1

/// @fn int Informes_ImprimirClientesConPedidosPendientes(eCliente[], int, ePedido[], int, int)
/// @brief Muestra por consola la lista de clientes y la cantidad de pedidos pendientes, si es que tiene
///
/// @param clientes -> Array de Clientes
/// @param tamClientes -> Tamaño del array Clientes
/// @param pedidos -> Array de pedidos
/// @param tamPedidos -> Tamaño del array pedidos
/// @param ultimoPedido -> Ultimo pedido realizado
/// @return Retorna 1 (OK), 0 (Parametros incorrectos) o -1(No encontro clientes)
int Informes_ImprimirClientesConPedidosPendientes(eCliente clientes[], int tamClientes, ePedido pedidos[], int tamPedidos, int ultimoPedido);

/// @fn int Informes_ImprimirPedidosPendientesConDatosCliente(ePedido[], int, eCliente[], int, int)
/// @brief Imprime pedidos pendientes y los datos del cliente de ese pedido
///
/// @param pedidos -> Array de pedidos
/// @param tamPedidos -> Tamaño del array pedidos
/// @param clientes -> Array de Clientes
/// @param tamClientes -> Tamaño del array Clientes
/// @param ultimoPedido -> Ultimo pedido realizado
/// @return Retorna 1 (OK), 0 (Parametros incorrectos) o -1(No encontro pedidos)
int Informes_ImprimirPedidosPendientesConDatosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido);

/// @fn int Informes_ImprimirPedidosCompletadosConDatosCliente(ePedido[], int, eCliente[], int, int)
/// @brief Imprime pedidos completados y los datos del cliente de ese pedido (si esta activo)
///
/// @param pedidos -> Array de pedidos
/// @param tamPedidos -> Tamaño del array pedidos
/// @param clientes -> Array de Clientes
/// @param tamClientes -> Tamaño del array Clientes
/// @param ultimoPedido -> Ultimo pedido realizado
/// @return Retorna 1 (OK), 0 (Parametros incorrectos) o -1(No encontro pedidos)
int Informes_ImprimirPedidosCompletadosConDatosCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido);

/// @fn int Informes_ImprimirPedidosPendientesSegunLocalidad(ePedido[], int, eCliente[], int, int)
/// @brief Pide la localidad por pantalla y si hay pedidos con esa localidad los muestra
///
/// @param pedidos -> Array de pedidos
/// @param tamPedidos -> Tamaño del array pedidos
/// @param clientes -> Array de Clientes
/// @param tamClientes -> Tamaño del array Clientes
/// @param ultimoPedido -> Ultimo pedido realizado
/// @return Retorna 1 (OK), 0 (Parametros incorrectos) o -1(No encontro pedidos)
int Informes_ImprimirPedidosPendientesSegunLocalidad(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido);

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

/// @fn int Informes_ClientesConMasPedidosPendientes(ePedido[], int, eCliente[], int, int, int)
/// @brief Imprime el consola el/los cliente/s con mas pedidos pendientes
///
/// @param pedidos -> Array de pedidos
/// @param tamPedidos -> Tamaño del array pedidos
/// @param clientes -> Array de Clientes
/// @param tamClientes -> Tamaño del array Clientes
/// @param ultimoPedido -> Ultimo pedido realizado
/// @param ultimoCliente -> Ultimo cliente registrado
/// @return Retorna 1 (OK), 0 (Parametros incorrectos) o -1(No encontro pedidos)
int Informes_ClientesConMasPedidosPendientes(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente);

/// @fn int Informes_ClientesConMasPedidosCompletados(ePedido[], int, eCliente[], int, int, int)
/// @brief Imprime el consola el/los cliente/s con mas pedidos completados
///
/// @param pedidos -> Array de pedidos
/// @param tamPedidos -> Tamaño del array pedidos
/// @param clientes -> Array de Clientes
/// @param tamClientes -> Tamaño del array Clientes
/// @param ultimoPedido -> Ultimo pedido realizado
/// @param ultimoCliente -> Ultimo cliente registrado
/// @return Retorna 1 (OK), 0 (Parametros incorrectos) o -1(No encontro pedidos)
int Informes_ClientesConMasPedidosCompletados(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente);

/// @fn int Informes_ClientesConMasPedidos(ePedido[], int, eCliente[], int, int, int)
/// @brief Imprime el consola el/los cliente/s con mas pedidos
///
/// @param pedidos -> Array de pedidos
/// @param tamPedidos -> Tamaño del array pedidos
/// @param clientes -> Array de Clientes
/// @param tamClientes -> Tamaño del array Clientes
/// @param ultimoPedido -> Ultimo pedido realizado
/// @param ultimoCliente -> Ultimo cliente registrado
/// @return Retorna 1 (OK), 0 (Parametros incorrectos) o -1(No encontro pedidos)
int Informes_ClientesConMasPedidos(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, int ultimoPedido, int ultimoCliente);

#endif /* INFORMES_H_ */
