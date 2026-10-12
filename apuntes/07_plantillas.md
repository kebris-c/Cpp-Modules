# Módulo 07 — plantillas

Los tres ejercicios compilan con `c++ -Wall -Wextra -Werror -std=c++98`. El segundo `make` no vuelve a enlazar. La salida está mal a propósito.

Comprobado en esta máquina:

- `ex00` imprime `a = 2, b = 3`, `min = 3`, `max = 3`, y lo mismo con las cadenas sin intercambiarlas. El PDF pide `a = 3, b = 2`, `min = 2`, `max = 3`, y las cadenas al revés.
- `ex01` solo hace `return 0`. `iter` no recorre.
- `ex02` imprime `didn't save the same value!!` y sale con código 1. El harness de 750 elementos está en `ex02/main.cpp`. El PDF de este subject no lo pega. Tienes que poder explicar cada línea. Hacen falta `<cstdlib>` y `<ctime>`: el archivo suelto de la raíz no compilaba sin ellos, y ya no está en la raíz.

No hay README ni bonus. El estándar va en `CXXFLAGS`. No hace falta una regla `std98`.

## ex00 — swap, min, max

Plantillas de función, en `whatever.hpp`, en el espacio global. El `main` llama `::swap` para no pillar `std::swap`.

`swap` intercambia y no devuelve nada. `min` devuelve el menor; si son iguales, el segundo. `max` devuelve el mayor; si son iguales, el segundo. Los dos argumentos son del mismo tipo y tienen que soportar las comparaciones.

El stub de `swap` no toca los argumentos. `min` y `max` devuelven siempre el segundo. Eso solo coincide con el subject cuando son iguales o cuando el segundo ya es el que toca.

El tipo de retorno del stub es `T const &`. El subject no elige entre referencia y copia. Tú lo justificas: si devuelves una referencia, tiene que ser uno de los dos argumentos, no un temporal.

No incluyas `<algorithm>`. En C++98, `std::swap`, `std::min` y `std::max` viven ahí, y el STL está prohibido hasta el módulo 08.

## ex01 — iter

Tres parámetros, no devuelve nada: dirección de un array, longitud `const`, y una función que se aplica a cada elemento.

El subject pide las dos formas: función que toma el elemento por referencia, y función que lo toma por referencia `const`. También un array `const` y uno que no lo es. El tercer argumento puede ser una función plantilla ya instanciada.

La firma del stub es un puntero a función de una sola forma, `void (*)(T &)`. No acepta las dos. No está escrito aquí cómo unificarlas: si lo copias, no lo vas a poder explicar. El cuerpo no recorre.

El `main` vivo está vacío. Los tests están comentados. No los descomentes contra esta firma: no compilan, y aunque compilaran `iter` no haría nada.

## ex02 — Array

Clase plantilla. Los cuerpos están en `Array.tpp`, incluido al final del `.hpp`. Es el sitio legal: una plantilla en el header no es el 0 que te cae por implementar ahí una función normal.

Contrato:

- Sin argumentos: array vacío.
- Con `unsigned int n`: `n` elementos inicializados por defecto. La pista del subject, que no es código de esta clase: `int *a = new int();` y luego mira `*a`. El paréntesis cambia la inicialización.
- Copia y asignación profundas. Después de copiar, tocar uno no toca al otro.
- `new[]`. Prohibido reservar de más. Prohibido leer memoria que no reservaste. Si reservas, `delete[]` en el destructor.
- `operator[]` lanza `std::exception` si el índice no existe.
- `size()` no modifica el objeto.

El harness hace `numbers[-2]`. Si el índice es `unsigned int`, `-2` se convierte en un número enorme. La comprobación tiene que ver eso como fuera de rango, no como un índice válido.

El stub no llama a `new[]`. `operator[]` devuelve una `T` estática, la misma para todos los índices. Por eso el espejo del harness falla. `size()` devuelve 0.

## Qué practicar a mano

Fuera de `ex00`, `ex01` y `ex02`. Cuando puedas reescribirlo sin mirar, lo pasas y borras los comentarios guía.

1. En papel, `swap` de dos `int` y de dos `std::string`. Una variable temporal del mismo tipo. Sin función de la biblioteca.
2. `min` y `max` con iguales y con distintos. El caso trampa es la igualdad: se devuelve el segundo, no «cualquiera».
3. Una función que recorra un array de `int` y otra que recorra un array `const`, llamando en cada elemento a una función que a veces solo lee y a veces escribe. Hasta que las dos llamadas te parezcan el mismo problema, no abras `iter.hpp`.
4. `int *a = new int();` frente a `int *a = new int;`. Imprime `*a` en los dos. Quédate con la diferencia antes de escribir el constructor de `n`.
5. Un array de 3 `int` con `new[]`, copia profunda, y un `[]` que lance si el índice no está. Prueba el índice `-2` y el índice igual al tamaño. Libera con `delete[]`.

## Tres preguntas de defensa

1. ¿Por qué `min` devuelve el segundo cuando son iguales, y por qué tu retorno es una referencia o una copia? ¿Dónde está prohibido `std::min`?
2. ¿Cómo acepta `iter` una función que escribe y otra que solo lee, sobre un array `const` y sobre uno que no lo es? Si tu tercer parámetro es un puntero a función de una sola firma, ¿qué llamada del subject no entra?
3. ¿Qué imprime `*a` tras `new int()`, y por qué `-2` en un `unsigned int` no es «el índice menos dos»? ¿Dónde está el `delete[]` que corresponde a tu `new[]`?

## Prohibido

- `using namespace` y `friend`.
- C++11 y posteriores: `auto`, `nullptr`, lambdas, range-for, `= default`, `override`, `std::array` como sustituto, movimientos.
- Contenedores y `<algorithm>`. Aquí entra `std::swap` / `std::min` / `std::max`.
- `*printf`, `*alloc`, `free`.
- Implementar en un header una función que no sea plantilla.
- En `Array`, reservar de más o acceder a memoria no reservada.

## Obligatorio

- `c++ -Wall -Wextra -Werror` y que siga compilando con `-std=c++98`.
- `$(NAME)`, `all`, `clean`, `fclean`, `re`. Sin relink. Sin `bonus`.
- Plantillas definidas en el header (o en un `.tpp` incluido desde el header).
- `ex02`: `new[]`, copia que no comparte memoria, `[]` con `std::exception`, `size()` const.
- Tests propios. El harness de 750 elementos cuenta como test del `Array` si puedes explicarlo.

## Cruce con «Un recorrido por C++», 3.ª edición

Los números que ya cuadran con el sumario de esa edición, citados en `apuntes/08_stl.md`:

- Capítulo 7, plantillas. Es este módulo entero. [Certain]
- Capítulo 6, operaciones esenciales. La copia y la asignación de `Array`. El libro ya habla de mover; el move es C++11 y aquí no entra. La OCF de este módulo es la de cuatro. [Certain] el capítulo; [Certain] que el move sobra.
- Capítulo 4, manejo de errores. La `std::exception` de `operator[]`. [Certain]

El capítulo 8 (conceptos) y el 14 (rangos) son C++20. No los bajes a estos ejercicios. El libro escribe `auto` y range-for dentro de los ejemplos de plantillas: aquí eso es un 0.
