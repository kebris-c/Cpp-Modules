/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:55:00 by kebris-c          +#+    #+#             */
/*   Updated: 2026/10/12 14:55:00 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	// El subject no fija el código de salida. «borra este comentario cuando puedas explicarlo»
	// Sin el argumento (y, en este esqueleto, con argc != 2) el mensaje literal es:
	// Error: could not open file.
	// Cuando abras de verdad, el MISMO texto sale si data.csv o argv[1] no se pueden
	// abrir. Este main no abre ficheros: si argc == 2 no imprime el resultado.
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 0;
	}

	// Ejemplo del PDF, comentario, no prints:
	// $> ./btc
	// Error: could not open file.
	// $> ./btc input.txt
	// 2011-01-03 => 3 = 0.9
	// 2011-01-03 => 2 = 0.6
	// 2011-01-03 => 1 = 0.3
	// 2011-01-03 => 1.2 = 0.36
	// 2011-01-09 => 1 = 0.32
	// Error: not a positive number.
	// Error: bad input => 2001-42-42
	// 2012-01-11 => 1 = 7.1
	// Error: too large a number.

	BitcoinExchange exchange;

	exchange.run(argv[1]);
	return 0;
}
