/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:55:00 by kebris-c          #+#    #+#             */
/*   Updated: 2026/10/12 14:55:00 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

// Familia de secuencia: vector, deque, list.
// Incluye aquí el que tú elijas. Un asociativo no encaja con esta clase.
// Borra este comentario cuando puedas explicarlo.

class Span
{
  public:
	// OCF de 4 (desde el módulo 02) más el constructor de N del subject.
	// Las funciones que no son plantilla están en Span.cpp. En el header serían un 0.
	// Borra este comentario cuando puedas explicarlo.
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	// Si ya hay N enteros, tiene que lanzar. Ahora no guarda y no lanza.
	// El tipo de excepción lo diseñas tú.
	// Borra este comentario cuando puedas explicarlo.
	void addNumber(int number);

	// Con 0 o 1 números, excepción. El ejemplo del subject imprime 2 y luego 14.
	// Estos stubs devuelven 0. No es una distancia.
	// Contenedor y un algoritmo de <algorithm> donde encaje; el algoritmo lo eliges tú.
	// Borra este comentario cuando puedas explicarlo.
	int shortestSpan() const;
	int longestSpan() const;

	// Nombre provisional: addRange. Puedes renombrarla. El subject no fija el nombre.
	// Plantilla de miembro: mete un rango de iteradores en una sola llamada.
	// Puede vivir en el header. Ahora no inserta.
	// Borra este comentario cuando puedas explicarlo.
	template <typename Iter>
	void addRange(Iter first, Iter last)
	{
		(void)first;
		(void)last;
	}

  private:
	// Aquí vivirán N y los enteros, en el contenedor que incluyas arriba.
	// Borra este comentario cuando puedas explicarlo.
};

#endif
