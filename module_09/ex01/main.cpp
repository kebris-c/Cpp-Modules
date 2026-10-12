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

#include "RPN.hpp"

int main(int argc, char **argv)
{
	// Placeholder: no evalúa. Siempre return 0.
	// «borra este comentario cuando puedas explicarlo»
	// El error del subject es la palabra Error por stderr. No está impresa aquí.
	(void)argc;
	RPN rpn;

	if (argc == 2)
		rpn.run(argv[1]);
	return 0;
}
