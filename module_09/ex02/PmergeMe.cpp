/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:55:00 by kebris-c          +#+    #+#             */
/*   Updated: 2026/10/12 14:55:00 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
	// OCF vacía. Con dos contenedores, la copia tiene que copiar los dos.
	// «borra este comentario cuando puedas explicarlo»
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		// sin miembros todavía.
		// «borra este comentario cuando puedas explicarlo»
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::run(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// «borra este comentario cuando puedas explicarlo»
	// Argumentos: secuencia de enteros positivos. Negativo o inválido: "Error"
	// por stderr. Duplicados: el subject lo deja a tu criterio. Este esqueleto
	// no decide.
	// Algoritmo: merge-insert sort, Ford-Johnson, Knuth, The Art of Computer
	// Programming, vol. 3, Merge Insertion, pág. 184. Lo lees tú y lo
	// implementas por contenedor. El subject desaconseja una función genérica:
	// dos implementaciones, una por contenedor.
	// argv llega como texto. Si conviertes cadenas: strtod o stringstream.
	// std::stoi es C++11 y está prohibido.
	// Salida obligatoria (constrúyela al ordenar; no la hardcodees):
	// línea 1: texto explícito + secuencia sin ordenar. Ejemplo: "Before: 3 5 9 7 4"
	// línea 2: texto + secuencia ordenada. Ejemplo: "After:  3 4 5 7 9"
	// línea 3 y 4: tiempo de TODO el proceso (sort + gestión de datos), uno por
	// contenedor. Precisión suficiente para ver la diferencia. El formato es
	// libre. Mínimo 3000 enteros.
	// Ejemplo del PDF (los microsegundos del subject son deliberadamente raros;
	// mides tú el proceso entero):
	// Time to process a range of 5 elements with std::[..] : 0.00031 us
	// Time to process a range of 5 elements with std::[..] : 0.00014 us
	// $> ./PmergeMe "-1" "2"
	// Error
	// Este método no ordena.
}
