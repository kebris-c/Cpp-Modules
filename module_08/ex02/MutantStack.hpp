/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:55:00 by kebris-c          #+#    #+#             */
/*   Updated: 2026/10/12 14:55:00 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

// MutantStack se implementa en términos de std::stack.
// Tiene que ofrecer las funciones de stack y, además, iteradores.
// El test del subject usa MutantStack<int>::iterator, begin, end,
// ++it, --it, push, pop, top, size, y std::stack<int> s(mstack).
// Sustituir MutantStack por std::list (push pasa a ser push_back)
// tiene que dar la misma salida.
// Este esqueleto no trae la relación con stack ni los typedef de iterador:
// eso es el ejercicio. Ahora mismo no es iterable.
// Incluye <stack> cuando sepas cómo te apoyas en él.
// Borra este comentario cuando puedas explicarlo.
template <typename T>
class MutantStack
{
	// OCF comentada: es una clase y el subject no te exime. Escríbela tú.
	// MutantStack();
	// MutantStack(const MutantStack &other);
	// MutantStack &operator=(const MutantStack &other);
	// ~MutantStack();
	// Borra este comentario cuando puedas explicarlo.
};

// El .tpp se incluye al final de este header, después de la clase.
// Borra este comentario cuando puedas explicarlo.
#include "MutantStack.tpp"

#endif
