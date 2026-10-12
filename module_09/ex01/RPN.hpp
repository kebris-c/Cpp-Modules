/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:55:00 by kebris-c          +#+    #+#             */
/*   Updated: 2026/10/12 14:55:00 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN
{
	private:
		// elige el contenedor, inclúyelo tú y anota la elección en apuntes/09_stl_aplicado.md; el siguiente ejercicio no podrá usarlo
		// El subject prohíbe reutilizar el contenedor del ex00. En la evaluación
		// te preguntan cuál usaste. El de aquí queda prohibido en el ex02.
		// «borra este comentario cuando puedas explicarlo»

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void run(const std::string &expression);
};

#endif
