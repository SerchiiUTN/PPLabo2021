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
	char cuit[15];
	eDireccion direccion;
	int localidad;
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
/// @param localidades -> Array de localidades
/// @param tam -> Tamaño del array
/// @return Retorna 1 (OK) o 0 (Error)
int eCliente_IngresarUnCliente(eCliente* cliente, eLocalidad localidades[], int tam);

/// @fn int eCliente_CargarUnCliente(eCliente[], int, eLocalidad[], int, int*)
/// @brief Carga un nuevo cliente en el array de clientes, asignando el ultimo id al mismo
///
/// @param clientes -> Array de clientes
/// @param tamClientes -> Tamaño del array
/// @param localidades -> Array de localidades
/// @param tamLocalidades -> Tamaño del array
/// @param ultimoId -> ultimo id que se cargo
/// @return Retorna 1 (OK), 0 (Error)
int eCliente_CargarUnCliente(eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidades, int* ultimoId);

/// @fn int eCliente_BuscarClientePorID(eCliente[], int, int)
/// @brief Busca un cliente en un array y si lo encuentra retorna el indice
///
/// @param clientes -> Array de clientes
/// @param tam -> Tamaño del array
/// @param id -> ID del cliente a buscar
/// @return Retorna -1 (Error) o el indice del cliente buscado
int eCliente_BuscarClientePorID(eCliente clientes[], int tam, int id);

/// @fn int eCliente_ModificarCliente(eCliente[], int, eLocalidad[], int)
/// @brief Busca en la lista un cliente y modifica los datos segun lo ingresado en consola
///
/// @param clientes -> Lista de clientes
/// @param tamClientes -> Tamaño de la lista
/// @param localidades -> Lista de localidades
/// @param tamLocalidades -> Tamaño de la lista
/// @return Retorna 1 (OK) o 0 (Error)
int eCliente_ModificarCliente(eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidades);

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

/// @fn int eCliente_MostrarUnCliente(eCliente, eLocalidad[], int)
/// @brief Muestra los datos de un cliente por consola
///
/// @param cliente -> Cliente a mostrar
/// @param localidades -> Lista de localidades
/// @param tam -> Tamaño de la lista
/// @return Retorna 1 (OK) o 0 (Error)
int eCliente_MostrarUnCliente(eCliente cliente, eLocalidad localidades[], int tam);

/// @fn int eCliente_MostrarDatosClienteEnPedido(eCliente[], int, eLocalidad[], int, int)
/// @brief Muestra los datos de un cliente por consola (Llamada por Informes para mostrar junto a un pedido)
///
/// @param clientes -> Lista de clientes
/// @param tamClientes -> Tamaño de la lista
/// @param localidades -> Lista de localidades
/// @param tamLocalidades -> Tamaño de la lista
/// @param idCliente -> ID del cliente a mostrar
/// @return Retorna 1 (OK) o 0 (Error)
int eCliente_MostrarDatosClienteEnPedido(eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidades, int idCliente);

/// @fn int eCliente_MostrarClientes(eCliente[], int, eLocalidad[], int)
/// @brief Muestra los clientes que hay cargados en la lista
///
/// @param clientes -> Lista de clientes
/// @param tamClientes -> Tamaño de la lista
/// @param localidades -> Lista de localidades
/// @param tamLocalidades -> Tamaño de la lista
/// @return Retorna 1 (OK) o 0 (Error)
int eCliente_MostrarClientes(eCliente clientes[], int tamClientes, eLocalidad localidades[], int tamLocalidades);


#endif /* ECLIENTE_H_ */
