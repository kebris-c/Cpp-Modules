/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:55:00 by kebris-c          #+#    #+#             */
/*   Updated: 2026/10/12 14:55:00 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// No guarda N. Borra este comentario cuando puedas explicarlo.
Span::Span()
{
}

// No guarda N. Borra este comentario cuando puedas explicarlo.
Span::Span(unsigned int n)
{
	(void)n;
}

// No copia estado. En cuanto haya miembros, este cuerpo está mal:
// al escribirlo tú, el compilador ya no genera la copia.
// Borra este comentario cuando puedas explicarlo.
Span::Span(const Span &other)
{
	(void)other;
}

// Igual que la copia: ahora no asigna nada.
// Borra este comentario cuando puedas explicarlo.
Span &Span::operator=(const Span &other)
{
	(void)other;
	return *this;
}

// No hay nada que liberar. Borra este comentario cuando puedas explicarlo.
Span::~Span()
{
}

// No guarda el entero y no lanza, aunque ya hubiera N.
// Borra este comentario cuando puedas explicarlo.
void Span::addNumber(int number)
{
	(void)number;
}

// Devuelve 0. No mira ningún número. No es la distancia corta.
// Borra este comentario cuando puedas explicarlo.
int Span::shortestSpan() const
{
	return 0;
}

// Devuelve 0. No mira ningún número. No es la distancia larga.
// Borra este comentario cuando puedas explicarlo.
int Span::longestSpan() const
{
	return 0;
}
