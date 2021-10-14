/*
 * eCliente.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Sergio
 */

#ifndef ECLIENTE_H_
#define ECLIENTE_H_

#include "eDireccion.h"
#include "eLocalidad.h"
#define EMPTY 0
#define FULL 1



typedef struct
{
	int idCliente;
	char empresa[51];
	char cuit[14];
	eDireccion direccion;
	eLocalidad localidad;
	int isEmpty;
}eCliente;

/// @fn int eCliente_InicializarClientes(eCliente[], int)
/// @brief Inicializa el campo "isEmpty" de los clientes en 0 (EMPTY)
///
/// @param clientes -> Array de clientes
/// @param tam -> Tamaño del array
/// @return Retorna 1 (OK) o 0 (Error)
int eCliente_InicializarClientes(eCliente clientes[], int tam);

/// @fn int eCliente_BuscarPrimerEspacioLibre(eCliente[], int)
/// @brief Busca el primer espacio libre del array y retorna el indice
///
/// @param clientes -> Array de clientes
/// @param tam -> Tamaño del array
/// @return Retorna -1 (Error) o el indice del 1er espacio libre del array
int eCliente_BuscarPrimerEspacioLibre(eCliente clientes[], int tam);

/// @fn int eCliente_IngresarUnCliente(eCliente*)
/// @brief Toma por consola los datos de un cliente y los guarda
/// 		en una direccion de memoria de una estructura
///
/// @param cliente -> Direccion de memoria de la estructura
/// @return Retorna 1 (OK) o 0 (Error)
int eCliente_IngresarUnCliente(eCliente* cliente);

/// @fn int eCliente_CargarUnCliente(eCliente[], int, int*)
/// @brief Busca espacio en array, si lo encuentra toma por consola los datos de un cliente
/// 		y los guarda en una estructura
///
/// @param clientes -> Array de clientes
/// @param tam -> Tamaño del array
/// @param ultimoIngresado -> ID del ultimo cliente que se ingreso (0 si no se ingreso ninguno)
/// @return Retorna 1 (OK), 0 (No se pudo guardar el cliente) o -1 (No se encontro espacio libre)
int eCliente_CargarUnCliente(eCliente clientes[], int tam, int* ultimoIngresado);

/// @fn int eCliente_BuscarClientePorID(eCliente[], int, int)
/// @brief Busca un cliente en un array y si lo encuentra retorna el indice
///
/// @param clientes -> Array de clientes
/// @param tam -> Tamaño del array
/// @param id -> ID del cliente a buscar
/// @return Retorna -1 (Error) o el indice del cliente buscado
int eCliente_BuscarClientePorID(eCliente clientes[], int tam, int id);

/// @fn int eCliente_ModificarCliente(eCliente[], int)
/// @brief Pide por consola un ID de cliente, si lo encuentra toma los datos por consola
/// 		y modifica al cliente buscado
///
/// @param clientes -> Array de clientes
/// @param tam -> Tamaño del array
/// @return Retorna 1 (OK) o 0 (Error)
int eCliente_ModificarCliente(eCliente clientes[], int tam);

/// @fn int eCliente_EliminarCliente(eCliente[], int, int)
/// @brief Busca un cliente por ID y si lo encuentra da la opcion de eliminar
///
/// @param clientes -> Array de clientes
/// @param tam -> Tamaño del array
/// @param id -> ID del cliente a buscar
/// @return Retorna 1 (OK), 0 (No se encontro el cliente) o -1 (Se cancelo la operacion)
int eCliente_EliminarCliente(eCliente clientes[], int tam, int id);

/// @fn int eCliente_VerificarClientes(eCliente[], int)
/// @brief Recorre el array de clientes buscando si hay clientes activos
///
/// @param clientes -> Array de clientes
/// @param tam -> Tamaño del array
/// @return Retorna 1 (Encontro cliente) o 0 (No encontro cliente)
int eCliente_VerificarClientes(eCliente clientes[], int tam);

/// @fn int eCliente_MostrarUnCliente(eCliente)
/// @brief Imprime por consola los datos de un cliente
///
/// @param cliente -> Cliente a imprimir
/// @return Retorna 1 (OK) o 0 (Error)
int eCliente_MostrarUnCliente(eCliente cliente);

/// @fn int eCliente_MostrarDatosClienteEnPedido(eCliente[], int, int)
/// @brief Muestra los datos de un cliente que realizo algun pedido
///
/// @param clientes -> Array de clientes
/// @param tam -> Tamaño del array
/// @param idCliente -> ID del cliente
/// @return Retorna 0 (No encontro el cliente) o 1 (Lo encontro y mostro en consola
int eCliente_MostrarDatosClienteEnPedido(eCliente clientes[], int tam, int idCliente);

/// @fn int eCliente_MostrarClientes(eCliente[], int)
/// @brief Recorre una lista de clientes y los imprime por consola
///
/// @param clientes -> Array de clientes
/// @param tam -> Tamaño del array
/// @return Retorna 1 (OK) o 0 (No hay clientes activos)
int eCliente_MostrarClientes(eCliente clientes[], int tam);


#endif /* ECLIENTE_H_ */
