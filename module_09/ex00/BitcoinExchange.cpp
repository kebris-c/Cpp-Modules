/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:55:00 by kebris-c          +#+    #+#             */
/*   Updated: 2026/10/12 14:55:00 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
	// OCF vacía a propósito: cuando el contenedor exista, la copia tiene que copiarlo.
	// «borra este comentario cuando puedas explicarlo»
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		// mismo aviso que en el constructor de copia: aquí aún no hay miembros.
		// «borra este comentario cuando puedas explicarlo»
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::run(const std::string &inputPath)
{
	(void)inputPath;
	// Contrato, no algoritmo. «borra este comentario cuando puedas explicarlo»
	// Programa: ./btc. Un argumento: el fichero de input. La DB es data.csv
	// (date,exchange_rate), abierta desde el cwd. Este csv es de ESTE ejercicio.
	// Cada línea válida del input: "date | value". Fecha Year-Month-Day.
	// Valor float o entero, entre 0 y 1000.
	// Salida stdout: "YYYY-MM-DD => value = result" (valor por el tipo de cambio
	// de esa fecha). Si la fecha no está en la DB, la fecha inferior más cercana,
	// nunca la superior.
	// Errores exactos, también por stdout (el subject no pide stderr aquí):
	// "Error: could not open file."
	// "Error: not a positive number."
	// "Error: bad input => 2001-42-42"
	// "Error: too large a number."
	// Cadenas a número: strtod o stringstream. std::stoi es C++11 y está prohibido.
	// Este método no abre el csv, no parsea y no multiplica.
}
