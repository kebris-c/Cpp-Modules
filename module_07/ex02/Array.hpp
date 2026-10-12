/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:21:00 by kebris-c          #+#    #+#             */
/*   Updated: 2026/10/12 15:21:00 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

// Clase plantilla. Los cuerpos están en Array.tpp: es el sitio legal de una plantilla.
// El subject exige new[]. Prohibido reservar de más. Prohibido acceder a memoria no reservada.
// Este esqueleto no reserva.
// Borra este comentario cuando puedas explicarlo.
template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(Array const &other);
	Array &operator=(Array const &other);
	~Array();

	T &operator[](unsigned int index);
	unsigned int size() const;

private:
	T *_data;
	unsigned int _size;
};

#include "Array.tpp"

#endif
