# Módulo 09 — STL aplicada

El `main.cpp` suelto de `module_07-github/` es el test del `Array` del módulo 07 (750 enteros, mirror, excepciones). No es la entrada de bitcoin, ni de RPN, ni de PmergeMe. Meterlo aquí no acerca ningún ejercicio.

`cpp_09/data.csv` es la base del subject y se queda donde está. La copia de trabajo es `module_09-github/ex00/data.csv`. Es del ex00: columnas `date,exchange_rate`, se abre desde el cwd junto con el fichero pasado a `./btc`. [Certain] el original tiene 1612 fechas, todas distintas, ya en orden creciente, de 2009-01-02 a 2022-03-29. El ex02 no lee ese csv. Sus argumentos son enteros en `argv`.

## Cada ejercicio quema contenedores

Es obligatorio usar contenedores estándar: al menos uno por ejercicio, y el ex02 exige dos distintos entre sí. Un contenedor con el que validas un ejercicio queda prohibido en el resto del módulo. No se quema «la familia»: se quema el que de verdad usaste para validar.

El ex00 se queda con el primero. El ex01 tiene que elegir otro; el del ex00 ya no existe para él. El ex02 necesita dos que no hayan salido ni en el ex00 ni en el ex01, y que tampoco se repitan entre ellos. Cuando elijas, escríbelo aquí. Hasta entonces los esqueletos no incluyen ninguno: el `#include` lo pones tú.

- ex00:
- ex01:
- ex02, primero:
- ex02, segundo:

Si el ex01 lo resuelves con un adaptador, el contenedor subyacente también cuenta en una defensa estricta. [Certain] en C++98 el adaptador de pila usa `deque` por defecto, igual que la cola; la cola de prioridad usa `vector` por defecto. [Likely] un evaluador que lea «los contenedores que usaste» te cobra también ese subyacente aunque no lo hayas escrito. Si quieres comparar `vector` y `deque` en el ex02, no los gastes antes: ni nombrándolos como argumento de plantilla del adaptador, ni heredando el que el adaptador trae callado. Anotar «usé el adaptador» sin decir encima de qué está es una respuesta incompleta.

## Prohibido y obligatorio

Obligatorio: contenedor estándar (dos en el ex02); Makefile con `$(NAME)`, `all`, `clean`, `fclean`, `re`; compilador `c++`; flags `-Wall -Wextra -Werror` y que siga compilando con `-std=c++98`; sin relink; forma canónica de cuatro en las clases, declarada en el `.hpp` e implementada en el `.cpp`; include guards; cada cabecera compilable sola. Los errores del ejemplo van literales. En el ex00 salen por stdout (el subject no pide stderr). En el ex01 y el ex02 el error va por stderr: la palabra `Error`.

Prohibido: repetir contenedor; `using namespace`; `friend`; biblioteca externa; `*printf`, `*alloc`, `free`; C++11 y lo que arrastra (`auto`, `nullptr`, lambda, range-for, `std::stoi`, `= default`). `std::stoi` no se «arregla» con un cast: para pasar de cadena a número en este módulo valen `strtod` o `stringstream`. Hardcodear la salida del PDF no valida el ejercicio. En el ex02, `std::sort` no sustituye al algoritmo que pide el subject, aunque `<algorithm>` esté permitido desde el módulo 08.

El valor del ex00 está entre 0 y 1000. El ejemplo manda `-1` a `Error: not a positive number.` y `2147483648` a `Error: too large a number.` El 0 está dentro del intervalo escrito y a la vez no es un positivo: el subject no lo muestra. Decídelo tú y defiéndelo. Los duplicados del ex02 también quedan a tu criterio; el esqueleto no elige.

## «Un recorrido por C++», tercera actualización

La cubierta en español dice «Tercera actualización» (Anaya). Es el tour de Stroustrup puesto al día a C++20, no un manual de este módulo.

[Certain] el índice de esa edición coloca los contenedores en el capítulo 12, los algoritmos de la biblioteca en el 13 y las utilidades en el 16. [Likely] el tiempo dentro de utilidades es la sección 16.2: ese número sale del sumario inglés de la misma edición (`tour3toc.pdf`), no de una página española abierta línea a línea. El capítulo 14 es rangos. El 16.6 es `move` y `forward`.

Ford-Johnson no está en ese libro. [Certain] el índice no tiene merge-insertion ni esa cita. El subject te manda a Knuth, *The Art of Computer Programming*, vol. 3, Merge Insertion, pág. 184. Lo lees tú y lo implementas una vez por contenedor. El capítulo 13 enseña los algoritmos ya escritos de la STL; copiar `std::sort` no es hacer el ex02.

El libro suspende este módulo si lo sigues al pie de la letra. Usa `auto`, rangos y movimiento. Aquí eso es C++11 o posterior: nota cero, no «estilo moderno». El tiempo del capítulo 16 está contado con `chrono`, que no existe en C++98. Para medir, la herramienta de esta norma es `std::clock` (`<ctime>`). Mides el proceso entero, ordenación y gestión de los datos, no solo las comparaciones. Con menos de 3000 enteros la diferencia entre contenedores puede quedar enterrada en el ruido. El formato de las dos líneas de tiempo es libre; la precisión no.

## Qué practicar

Mapa ordenado y `lower_bound` para la fecha inferior del ex00. Un `map` mantiene las claves ordenadas. `lower_bound` no devuelve «la anterior»: devuelve la primera clave que no es menor que la fecha buscada. Si esa clave es la fecha, ya está. Si no lo es, el iterador señala la fecha posterior, y la inferior es la anterior a ese iterador. Si el iterador es `begin()` y no hay igualdad, la base no tiene ninguna fecha más baja. El subject no dice qué imprimir en ese caso (el ejemplo no lo provoca; la DB empieza en 2009). Prepáralo.

Adaptador de pila para la expresión en polaca inversa. Los operandos del argumento son un dígito; el resultado puede crecer. No reutilices el contenedor con el que hayas validado el ex00, y no dejes el subyacente del adaptador en uno de los dos que quieras para el ex02.

`vector` y `deque` no cuestan lo mismo cuando insertas por el medio de una secuencia ya colocada. El `vector` es un solo bloque: meter un elemento en medio desplaza el tramo de atrás. El `deque` está en bloques: los extremos son baratos y el acceso por índice sigue siendo constante, con más indirección; insertar en medio también mueve elementos. Esa diferencia de coste es lo que el tiempo del ex02 tiene que dejar ver. No está escrito aquí cómo se ordena: eso es Knuth, y son dos implementaciones, no una plantilla que esconda el contenedor. El subject desaconseja la función genérica porque en la defensa no podrías explicar qué cambia de uno a otro.

## Tres preguntas de defensa

1. La fecha no está en la DB. ¿Por qué te quedas con la inferior y no con la superior, y qué devuelve en realidad `lower_bound`? ¿Qué haces si la fecha es anterior a toda la base?

2. ¿Qué contenedor validó cada ejercicio? Si uno es un adaptador, ¿cuál es el subyacente y por qué eso puede haberte dejado sin `deque` (o sin `vector`) para el ex02?

3. Las dos líneas de tiempo, ¿cuentan solo el sort o también la gestión de los datos, y por qué 3000 enteros? ¿Por qué dos funciones y no una plantilla? Los duplicados los decides tú: ¿qué hace tu programa y por qué?
