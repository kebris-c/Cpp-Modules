/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:21:00 by kebris-c          #+#    #+#             */
/*   Updated: 2026/10/12 15:21:00 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// Los dos argumentos son del mismo tipo y tienen que soportar
// los operadores de comparación. Plantillas globales: el main usa ::swap.
// No incluyas <algorithm>: std::swap, std::min y std::max viven ahí en C++98.
// Borra este comentario cuando puedas explicarlo.

template <typename T>
void swap(T &a, T &b)
{
	// en esta función el subject exige intercambiar los dos valores y no devolver nada.
	// El stub no intercambia.
	// Borra este comentario cuando puedas explicarlo.
	(void)a;
	(void)b;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	// en esta función el subject exige devolver el menor; si son iguales, el segundo.
	// El stub devuelve siempre el segundo (incorrecto cuando el primero es menor).
	// Borra este comentario cuando puedas explicarlo.
	(void)a;
	return b;
}

template <typename T>
T const &max(T const &a, T const &b)
{
	// en esta función el subject exige devolver el mayor; si son iguales, el segundo.
	// El stub devuelve siempre el segundo (incorrecto cuando el primero es mayor).
	// Borra este comentario cuando puedas explicarlo.
	(void)a;
	return b;
}

#endif
