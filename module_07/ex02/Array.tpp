/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:21:00 by kebris-c          #+#    #+#             */
/*   Updated: 2026/10/12 15:21:00 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _data(0), _size(0)
{
	// en esta función el subject exige un array vacío.
	// Este stub no reserva.
	// Borra este comentario cuando puedas explicarlo.
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(0), _size(0)
{
	// en esta función el subject exige n elementos inicializados por defecto.
	// Pista del subject, no es código de esta clase: int *a = new int(); luego mostrar *a.
	// Tienes que usar new[]. Este stub no hace new[]: si reservas, tienes que liberar.
	// Borra este comentario cuando puedas explicarlo.
	(void)n;
}

template <typename T>
Array<T>::Array(Array<T> const &other) : _data(0), _size(0)
{
	// en esta función el subject exige copia: después de copiar, modificar uno no afecta al otro.
	// Este stub no copia. El test del espejo fallará hasta que haya copia profunda y new[].
	// Borra este comentario cuando puedas explicarlo.
	(void)other;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &other)
{
	// en esta función el subject exige asignación: después de copiar, modificar uno no afecta al otro.
	// Este stub no copia. El test del espejo fallará hasta que haya copia profunda y new[].
	// Borra este comentario cuando puedas explicarlo.
	(void)other;
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	// en esta función el subject exige no filtrar lo que reserves con new[].
	// Este stub no reservó, así que aquí no hay delete[].
	// Borra este comentario cuando puedas explicarlo.
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	// en esta función el subject exige std::exception si el índice está fuera de rango.
	// El harness llama numbers[-2] y numbers[MAX_VAL].
	// Un unsigned int convierte -2 en un número enorme, así que la comprobación de límites tiene que contemplar eso.
	// El stub devuelve una T estática: eso está mal.
	// El test del espejo fallará hasta que haya copia profunda y new[].
	// Borra este comentario cuando puedas explicarlo.
	(void)index;
	static T dummy;
	return dummy;
}

template <typename T>
unsigned int Array<T>::size() const
{
	// en esta función el subject exige el número de elementos. No modifica la instancia.
	// El stub devuelve 0.
	// Borra este comentario cuando puedas explicarlo.
	return 0;
}
