# Módulo 08 — contenedores, iteradores, algoritmos

Puedes dejar los tres ejercicios funcionando sin abrir `<algorithm>` y aun así llevarte una mala nota. El subject lo dice por escrito: se pueden resolver sin contenedores ni algoritmos estándar, y no usarlos es el fallo del módulo.

Los fuentes de `module_08-github` compilan y están mal a propósito. `easyfind` no busca. `Span` no guarda enteros ni mide distancias. `MutantStack` no se puede recorrer. Si un test imprime `2` y luego `14`, o si un `begin()` compila, eso ya no es este esqueleto.

C++98. Sin `using namespace`, sin `friend`. Las plantillas se declaran en el header; el cuerpo puede ir en el header o en un `.tpp`. Una función que no es plantilla, implementada en el header, es un 0.

## ex00 — easyfind

Plantilla de función. Primer parámetro: un tipo `T` que será un contenedor de `int`. Segundo: un `int`. Hay que encontrar la primera ocurrencia.

El subject no pide soportar asociativos (`map`, `set`). No los metas «por si acaso» hasta que el caso de secuencia esté explicado en voz alta.

Si el entero no está, o lanzas o devuelves un error. La pista del subject es cómo lo hace `find` de los contenedores estándar: ábrelo en la referencia, no lo copies del primer ejemplo que veas (muchos están en C++11).

El retorno de este esqueleto es `void` y el cuerpo no lee el contenedor. Esa firma es falsa. El tipo de retorno lo eliges tú: iterador o excepción. También tienes que justificar si `T` viaja por copia o por referencia; el subject solo dice que el parámetro es de tipo `T`.

El algoritmo sale de `<algorithm>`. Un `for` escrito a mano, aunque funcione, es la versión perezosa que el módulo castiga.

No hay un `#include` de `vector`, `deque` o `list`. La familia está nombrada en el comentario del header. El include lo escribes tú. El `main` vivo solo hace `return 0`. Los tests están comentados y tienen que cubrir encontrado y no encontrado. No dejes un contenedor concreto como «la» solución del ejercicio.

## ex01 — Span

Clase. Desde el módulo 02 la OCF de cuatro es obligatoria, y el subject añade un constructor con un solo `unsigned int N`: el máximo de enteros.

`addNumber` añade uno. Si ya hay `N`, excepción. `shortestSpan` y `longestSpan` devuelven la distancia menor y la mayor entre los valores guardados. Con 0 o 1 números no hay distancia: excepción, no un 0 silencioso.

«Distancia» aquí es la diferencia entre valores, no `std::distance` entre iteradores. `std::distance` mide cuántos saltos hay de un iterador a otro. Si lo usas para el span, estás resolviendo otro problema.

El ejemplo del subject es `Span(5)`, luego 6, 3, 17, 9 y 11. La salida de `./ex01` es `2` y después `14`. Tienes que poder señalar qué pareja produce cada número. El `main` del PDF está comentado entero. El `main` vivo solo hace `return 0`. Si descomentas hoy, verás `0` y `0`: los stubs no calculan.

Hay que poder añadir un rango de iteradores en una sola llamada. El subject no pone nombre a esa función. En el header está `addRange` como nombre provisional de una plantilla de miembro que no inserta nada. Puedes renombrarla. Las funciones que no son plantilla están en `Span.cpp`. Si las pasas al header, el ejercicio vale 0.

Hace falta un test de al menos 10000 números. Más es mejor. Ese test lo escribes tú cuando `Span` guarde de verdad, y es el momento natural de usar el rango en vez de diez mil llamadas a `addNumber`.

El contenedor no está incluido. Familia de secuencia: `vector`, `deque`, `list`. Incluye el que elijas. La OCF del `.cpp` hoy no guarda ni copia: en cuanto añadas miembros, esos cuerpos vacíos tapan la copia que generaría el compilador y hay que escribirlos de verdad.

## ex02 — MutantStack

`std::stack` no es iterable porque es un adaptador: envuelve otro contenedor y solo enseña la interfaz de pila (`push`, `pop`, `top`, `size`, `empty`). No tiene recorrido. El contenedor subyacente es la pista. El typedef no está en estos apuntes ni en el esqueleto: eso es el ejercicio.

La clase se implementa en términos de `std::stack`. Tiene que ofrecer las funciones de la pila y, además, iteradores. El `main` del subject usa `MutantStack<int>::iterator`, `begin`, `end`, `++it`, `--it`, `push`, `pop`, `top`, `size`, y `std::stack<int> s(mstack)`. Ese `main` está comentado. No compilará hasta que existan `iterator`, `begin` y `end`. El `main` vivo solo hace `return 0`.

Si sustituyes `MutantStack` por `std::list` y cambias `push` por `push_back`, la salida tiene que ser la misma. `s(mstack)` obliga a que tu tipo se pueda usar para construir un `std::stack<int>`. Cómo lo consigues lo explicas tú en la defensa. El esqueleto no trae esa relación ni los typedef.

La OCF está solo en comentarios. El subject no exime a esta clase. El `.tpp` se incluye al final del `.hpp` y no tiene cuerpos.

## Qué practicar a mano

Fuera de `ex00`, `ex01` y `ex02`. En un directorio de usar y tirar. Cuando puedas reescribirlo sin mirar, lo pasas al ejercicio y borras los comentarios guía.

1. Un contenedor de secuencia con enteros repetidos. Un algoritmo de `<algorithm>` que localice la primera ocurrencia, y otro caso que no está. Anota qué te devuelve la biblioteca cuando no está, antes de decidir si `easyfind` lanza o devuelve eso.
2. En papel, la distancia corta y la larga de `{6, 3, 17, 9, 11}`, de un rango con duplicados y de un rango con negativos. Después, en el main de usar y tirar, pide a la biblioteca el menor y el mayor valor. No pegues eso en `Span` hasta que coincida con tu cuenta. No te digo qué algoritmo va en cada función.
3. Mete 10000 enteros en un contenedor con la función de miembro que acepta dos iteradores. Mira qué pasa si intentas pasar de la capacidad que tú mismo fijaste.
4. En papel, la lista de funciones que el `main` del subject llama sobre `MutantStack`. Al lado, las que `std::stack` tiene y las que no. Compara con `std::list` y marca la única que cambia de nombre (`push` / `push_back`).
5. La OCF de una clase que posee un contenedor, en papel, antes de teclear `Span`. Incluye qué pasa con la autoasignación.

## Tres preguntas de defensa

1. Si `easyfind` no encuentra el entero, ¿devuelves el final del rango o lanzas? ¿Qué algoritmo de `<algorithm>` usaste, y qué cambia su coste en un `list` frente a un `vector`? ¿Por qué un asociativo no entra en el contrato?
2. Con 6, 3, 17, 9 y 11, ¿qué pareja da 2 y cuál da 14? ¿Qué lanzas con cero elementos, con uno, y con un `addNumber` de más? ¿Cómo metes 10000 números en una sola llamada si el subject no te dio el nombre de esa función?
3. ¿Por qué `std::stack` no tiene `begin` ni `end` si todo el mundo lo llama contenedor? ¿Dónde está el contenedor subyacente, sin leer un typedef que te hayan escrito? ¿Por qué `std::stack<int> s(mstack)` compila con tu diseño, y qué única función cambias para que un `std::list` imprima lo mismo?

## Prohibido

- `using namespace` y `friend`. La nota puede ser -42.
- C++11 y posteriores: `auto`, `nullptr`, lambdas, range-for, `= default`, `override`, `constexpr` de los que no existían, `std::array` mal usado como si fuera C++98, y cualquier cosa de `<ranges>`.
- `unordered_map` y `forward_list`: son C++11. El libro los enseña igual.
- `*printf`, `*alloc`, `free`. Bibliotecas externas y Boost.
- Implementar en un header una función que no es plantilla.
- Elegir el contenedor en un include del esqueleto y darlo por cerrado. Lo eliges tú, y lo sabes defender.
- Un `for` a mano en `easyfind` si un algoritmo de `<algorithm>` hace el trabajo.
- Tratar `std::distance` como si fuera el span del ejercicio 01.

## Obligatorio

- Compilar con `c++ -Wall -Wextra -Werror` y que siga compilando con `-std=c++98`. El `Makefile` ya lleva ese estándar en `CXXFLAGS`. No hace falta una regla `std98` ni `bonus`.
- `$(NAME)`, `all`, `clean`, `fclean`, `re`, `.PHONY`. `NAME` es `ex00`, `ex01` o `ex02`. El subject ejecuta `./ex01`. El segundo `make`, sin cambios, no vuelve a enlazar.
- Include guards. Cada header se incluye solo y trae lo que usa.
- OCF de cuatro en las clases, aunque el subject no la repita en el enunciado del ejercicio.
- Contenedores de la STL y algoritmos de `<algorithm>` siempre que encajen. Si no están y el programa funciona, la nota baja igual.
- Tests propios. En `Span`, al menos 10000 números.
- `easyfind`: primera ocurrencia, y un fallo visible si no está.
- `Span`: tope `N`, excepción al pasar de `N`, excepción si no hay distancia, y un alta por rango de iteradores.
- `MutantStack`: en términos de `std::stack`, con sus funciones y con iteradores. La salida coincide con la de `std::list` ajustando el nombre de `push`.

## Cruce con «Un recorrido por C++», 3.ª edición

Pediste marcar los capítulos como [Likely]. El índice de la tercera actualización (Anaya) y el sumario inglés de Stroustrup (`tour3toc.pdf`) coinciden, así que los números de capítulo son [Certain]:

- Capítulo 12, Contenedores.
- Capítulo 13, Algoritmos. Los iteradores no tienen capítulo propio. [Certain] en el sumario inglés van en 13.2 (uso de iteradores) y 13.3 (tipos de iterador). [Likely] la traducción española conserva esa numeración.
- Capítulo 14, Rangos. Es C++20: vistas, generadores, pipelines. En este módulo no existe. No traslades ese capítulo a C++98.
- [Certain] Capítulo 7, Plantillas: `easyfind`, la alta por rango y `MutantStack`.
- [Certain] Capítulo 4, Manejo de errores: las excepciones de `Span` y, si eliges ese camino, las de `easyfind`.
- [Certain] Capítulo 6, Operaciones esenciales: copia y asignación, que aquí se exigen como OCF aunque el libro no use ese nombre.

El libro está escrito en C++ moderno. [Certain] `unordered_map` y `forward_list` son C++11; `std::span` (el de la biblioteca, no tu clase `Span`) y los rangos son C++20. Lees la idea y escribes C++98: `vector`, `deque`, `list`, `map`, `set`, `stack`, y algoritmos de esa época. Sin `auto`, sin range-for, sin lambda, sin `nullptr`.

[Likely] el capítulo 12 no te va a dictar el typedef de `MutantStack`. [Certain] `std::stack` no es iterable porque es un adaptador, y el contenedor subyacente es la pista. El typedef no está escrito aquí.
