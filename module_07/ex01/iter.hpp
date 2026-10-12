/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:21:00 by kebris-c          #+#    #+#             */
/*   Updated: 2026/10/12 15:21:00 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *array, unsigned int const length, void (*function)(T &))
{
	// en esta función el subject exige tres parámetros y no devolver nada:
	// (1) la dirección de un array, (2) la longitud como valor const,
	// (3) una función que se llama sobre cada elemento.
	// Obligatorio las dos formas: una función que toma el elemento por referencia const,
	// y una función que toma el elemento por referencia no const.
	// También un array const y uno que no lo es. El tercer argumento puede ser
	// una función plantilla ya instanciada.
	// Esta firma es un puntero a función de una sola forma. No unifica las dos.
	// No escribas aquí cómo unificarlas.
	// El stub no recorre el array.
	// Borra este comentario cuando puedas explicarlo.
	(void)array;
	(void)length;
	(void)function;
}

#endif
