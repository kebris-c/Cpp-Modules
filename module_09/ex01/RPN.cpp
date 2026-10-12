/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:55:00 by kebris-c          +#+    #+#             */
/*   Updated: 2026/10/12 14:55:00 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
	// OCF vacía hasta que el contenedor exista y haya que copiarlo.
	// «borra este comentario cuando puedas explicarlo»
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		// sin miembros todavía.
		// «borra este comentario cuando puedas explicarlo»
	}
	return *this;
}

RPN::~RPN()
{
}

void RPN::run(const std::string &expression)
{
	(void)expression;
	// Contrato, no evaluación. «borra este comentario cuando puedas explicarlo»
	// ./RPN "expresión" entre comillas. Notación polaca inversa.
	// Operandos de entrada siempre menores que 10 (un dígito). El resultado puede
	// ser mayor. Tokens: + - / *. Sin paréntesis ni decimales.
	// Resultado por stdout. Si hay error, "Error" por stderr.
	// Si conviertes tokens de texto, strtod o stringstream. std::stoi prohibido.
	// Este método no calcula.
	//
	// ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" -> 42
	// ./RPN "7 7 * 7 -" -> 42
	// ./RPN "1 2 * 2 / 2 * 2 4 - +" -> 0
	// ./RPN "(1 + 1)" -> Error
}
