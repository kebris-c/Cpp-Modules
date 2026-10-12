# Revisión módulos 05 y 06

Veredicto: el módulo 05 entero y el módulo 06 (ex00, ex01 y ex02) están APTO para defensa. En el ex00, `nanf` / `+inff` / `-inff`, los tres ejemplos del PDF, el overflow de float (`1e39` → `float: impossible`) y los enteros grandes en notación científica (sin un `.0` metido en el exponente) salen bien.

Los siete Makefile tienen ahora `CXX = c++` en la línea 2, con `-std=c++98` dentro de `CXXFLAGS`. Eso es lo que pide el subject. Una regla `std98` no hace falta.

## Compilación

[Certain] El Makefile llama a `c++`. En esta máquina `/usr/bin/c++` es clang 12 y `/usr/bin/g++` es g++ 10.5.

[Certain] Cada `.cpp` de los siete ejercicios compila con `c++ -Wall -Wextra -Werror -std=c++98` y el compilador no emite avisos. El `ScalarConverter.cpp` de ahora también.

[Certain] Rehíce el `make` del ex00 del 06 con el Makefile actual: `c++` compila, enlaza `convert`, y el segundo `make` imprime `Nothing to be done for 'all'`. [Likely] los otros seis hacen lo mismo: la regla de enlace no cambió. [Certain] En ex02 y ex03, `fclean` ahora también borra `*_shrubbery` (`Makefile` línea 25 del ex02, línea 26 del ex03). No lo pide el subject. No estorba.

[Certain] El Makefile no lista los headers como dependencia. Después de `touch Bureaucrat.hpp`, `make` no recompila. Si en la defensa tocas un `.hpp`, haz `make re` o el binario se queda con el objeto viejo.

[Certain] En estos dos módulos no hay `auto`, `nullptr`, lambda, range-for, `override`, `= default`, `= delete`, `std::stoi`, `unique_ptr`, move, `using namespace`, `friend`, `*printf`, `*alloc`, `free`, contenedores ni `<algorithm>`.

Binarios reales del Makefile: `bureaucrat`, `forms`, `aforms`, `intern_forms`, `convert`, `serializer`, `identify`.

## Módulo 05 ex00 — APTO

Binario: `bureaucrat`.

El subject pide grado 1 como el más alto y 150 como el más bajo, de modo que incrementar un 3 deja un 2. Nombre constante, `getName`, `getGrade`, `GradeTooHighException`, `GradeTooLowException`, capturables con `std::exception`. Las clases de excepción no llevan OCF. El resto sí: ctor, copia, asignación, destructor. Sin move. `operator<<` con el texto `<name>, bureaucrat grade <grade>.`

[Certain] `Bureaucrat.hpp:11` el nombre es `const`. `:21-22` los getters. `:27-37` las dos excepciones heredan `std::exception`. `Bureaucrat.cpp:8-11` el constructor tira si el grado sale de 1..150. `:35-39` incrementar hace `--_grade` y tira si el grado ya es 1. `:42-46` decrementar hace `++_grade` y tira si ya es 150. `:59-62` el `operator<<` escribe el formato del subject, punto incluido. `:15-19` del header están las cuatro funciones de la OCF. `:16-20` del `.cpp` la asignación copia el grado y deja el nombre quieto, porque es `const`.

[Certain] Salida del programa:

```
Alice, bureaucrat grade 2.
Alice, bureaucrat grade 1.
Exception: grade too high
Bob, bureaucrat grade 149.
Bob, bureaucrat grade 150.
Exception: grade too low
Exception: grade too low
```

[Certain] Sonda aparte, mismo código: un grado 3 incrementado queda en 2. Un 148 decrementado queda en 149. Construir con 0 imprime `grade too high`. Incrementar un grado 1 también.

No hay un fallo que suspenda. La asignación que no copia el nombre se defiende: un miembro `const` no se puede reasignar. No lo toques con `const_cast`.

Pregunta de defensa: ¿por qué incrementar resta uno al número? ¿Qué puede copiar el `operator=` si el nombre es constante?

Tour: [Certain] capítulo 4, manejo de errores (4.2 excepciones), y capítulo 6, operaciones esenciales. En el sumario inglés de esa edición (`tour3toc.pdf`, el mismo que ya contrastaste para el 08) la copia y el move están en 6.2 y la sobrecarga de operadores en 6.4. [Likely] Anaya conserva esos números. No hay página española abierta. Trampa de al lado: el 6.2 enseña el move, y `= default` vive junto a esas operaciones. Aquí las dos cosas suspenden. El destructor se escribe.

## Módulo 05 ex01 — APTO

Binario: `forms`.

El subject pide atributos `private`, no `protected`. Nombre constante, `signed` a falso al construir, grado para firmar constante, grado para ejecutar constante. `beSigned(Bureaucrat)`. `signForm` imprime `<bureaucrat> signed <form>` o `<bureaucrat> couldn’t sign <form> because <reason>.`

[Certain] `Form.hpp:12-16` los cuatro atributos son private. El nombre y los dos grados son `const`. `Form.cpp:4` y `:10` construyen con `_isSigned(false)`. `:13-16` un grado menor que 1 tira `GradeTooHighException`; uno mayor que 150 tira `GradeTooLowException`. `:56-60` `beSigned` tira si el número del burócrata es mayor que el grado para firmar. Igual sí firma: el 1 es mejor que el 2. `Bureaucrat.cpp:57-68` llama a `beSigned` y escribe las dos frases. El apóstrofo de `couldn’t` es U+2019 (`e2 80 99`), el mismo byte que trae el PDF. Déjalo.

[Certain] Salida: Intern (150) no firma BudgetForm, que pide 50, y la razón es `form grade too low`. Chief (1) sí lo firma. Un form construido con grados 0 y 151 imprime `form grade too high`: el 151 no llega a mirarse, porque el ctor comprueba primero el extremo alto.

[Certain] Sonda: un burócrata de grado 50 firma un form que pide 50. Uno de grado 51 no, y el form sigue sin firmar.

El `operator<<` (`Form.cpp:73-79`) no tiene formato fijado en el subject. Imprime nombre, si está firmado y los dos grados. Basta.

Pregunta: ¿un grado 50 frente a un form que pide 50 firma? Firma. ¿Por qué los atributos no pueden ser `protected`?

Tour: capítulos 4 y 6, igual que el ex00. Trampa: `override` no existe en C++98. `what()` va como `const throw()`, que es la forma de C++98.

## Módulo 05 ex02 — APTO

Binario: `aforms`. El `operator=` de dos forms concretos no copia el target. Eso no tumba lo que el subject pide ejecutar, y te lo van a cazar si escriben `a = b`.

El subject pide `AForm` abstracta, atributos private en la base. Shrubbery: firmar 145, ejecutar 137, archivo `<target>_shrubbery` con árboles ASCII. Robotomy: 72 y 45, ruidos, éxito el 50% de las veces. Presidential: 25 y 5, perdón de Zaphod Beeblebrox. `execute(Bureaucrat const &) const` comprueba firmado y grado, y si no lanza. `executeForm` imprime el éxito o un error explícito.

[Certain] `AForm.hpp:12-16` los atributos siguen private. `:32` `executeAction` es pura: la clase no se puede instanciar. `AForm.cpp:64-70` `execute` exige firmado y un grado suficiente, y solo entonces llama a la acción. Grados en los constructores que reciben el target: `ShrubberyCreationForm.cpp:11` (145, 137), `RobotomyRequestForm.cpp:10` (72, 45), `PresidentialPardonForm.cpp:9` (25, 5). Los constructores por defecto repiten los mismos números en las líneas 6, 5 y 4 de esos archivos. `ShrubberyCreationForm.cpp:36` abre `_target + "_shrubbery"`. `PresidentialPardonForm.cpp:33` escribe `has been pardoned by Zaphod Beeblebrox.` `RobotomyRequestForm.cpp:35-39` imprime ruidos y usa `std::rand() % 2`. `Bureaucrat.cpp:71-82` imprime `<nombre> executed <form>` o `<nombre> couldn’t execute <form> because <razón>.`

[Certain] Salida de `aforms`: Low no firma el shrubbery. Mid lo firma y lo ejecuta. Low no ejecuta el robotomy porque no está firmado (`form is not signed`). Boss lo firma, hay ruidos, la robotomía falla, y después `Boss executed RobotomyRequestForm`. Mid no firma el perdón. Boss sí, y la línea es `Ford Prefect has been pardoned by Zaphod Beeblebrox.` El archivo `home_shrubbery` aparece en el directorio de trabajo con un árbol ASCII de nueve líneas.

[Certain] Sonda de límites: grado 145 firma el shrubbery, grado 138 no lo ejecuta (`form grade too low`), grado 137 sí. En 20 robotomías seguidas salieron 10 éxitos y 10 fallos. Este ejercicio no llama a `srand`, así que la serie se repite en cada arranque. El 50% está. Si quieres otra serie cada vez, siembra una sola vez en `main`, no dentro del form.

Qué se rompe en la asignación. [Certain] `_target` es `const` en `ShrubberyCreationForm.hpp:9` y en `PresidentialPardonForm.hpp:9`. El ctor de copia sí lo copia. El `operator=` no puede: `ShrubberyCreationForm.cpp:20-28` y `PresidentialPardonForm.cpp:19-25` solo llaman al `operator=` de `AForm`, que copia el booleano de firmado. Robotomy no declara el target `const` y sí lo asigna (`RobotomyRequestForm.cpp:24`). Lo ejecuté: después de `office = home`, ejecutar el objeto de la izquierda crea `office_shrubbery`. Después de asignar un perdón con target `two` desde uno con target `one`, el perdonado sigue siendo two.

Qué cambiar a mano: quita el `const` de `_target` en esas dos clases y copia el string en el `operator=`, como ya hace Robotomy. El mismo arreglo en los archivos gemelos de ex03. El nombre y los grados de `AForm` siguen `const`: esos no se asignan, y eso sí se explica. No uses `const_cast`.

[Certain] `executeAction` es pública (`AForm.hpp:32` y la declaración pública de cada hija). Quien la llama se salta la firma y el grado. La comprobación que pide el subject está en `AForm::execute`, y eso se defiende. Si te piden cerrarlo, pásala a `protected`. `friend` está prohibido.

[Certain] `ShrubberyCreationForm.cpp:36` no mira si el `ofstream` abrió. Si el directorio no deja escribir, `executeForm` igual imprime que ejecutó. En un directorio normal el archivo se crea.

Pregunta: ¿la comprobación de firmado y grado está en la base o repetida en cada hija? En la base. Las hijas solo hacen la acción. ¿Qué target queda si asignas dos shrubbery?

Tour: [Certain] capítulo 5 del sumario inglés, 5.3 tipos abstractos, 5.4 funciones virtuales, 5.5 jerarquías. [Likely] Anaya conserva el 5. Capítulo 4 para las excepciones que lanza `execute`. Capítulo 6 para la OCF que el `operator=` está dejando a medias. Trampa: `override`, destructor `= default`, `std::unique_ptr` para guardar el form. El destructor virtual está escrito en `AForm.cpp:33`.

## Módulo 05 ex03 — APTO

Binario: `intern_forms`.

El subject pide `makeForm(nombre, target)` devolviendo `AForm*`. El ejemplo usa `"robotomy request"` y `"Bender"` e imprime `Intern creates <form>`. Nombre desconocido: error explícito. Un bosque de if/else no se acepta en la evaluación. `std::map` es STL y en el módulo 05 es -42.

[Certain] `Intern.cpp:43-54` es una tabla de tres `std::string` y tres punteros a función, recorrida con un `for` y un solo `if`. No hay `std::map` ni una cadena de if/else. Los literales son `shrubbery creation`, `robotomy request` y `presidential pardon`. Si coincide, imprime `Intern creates ` más el nombre que te pasaron y devuelve el `new`. Si no, la línea 56 imprime el error y devuelve 0. `main.cpp:19`, `:25` y `:31` hacen `delete`. [Certain] valgrind de `intern_forms`: 0 bytes en uso al salir, 0 errores.

[Certain] Salida:

```
Intern creates robotomy request
Intern creates shrubbery creation
Intern creates presidential pardon
Intern couldn't create form "unknown form".
```

Después Boss firma y ejecuta los tres. Se crea `Garden_shrubbery`. La línea del perdón es `Arthur Dent has been pardoned by Zaphod Beeblebrox.`

El PDF solo fija el literal `"robotomy request"`. Los otros dos los has elegido tú, en minúsculas y con espacio. Si el corrector escribe `ShrubberyCreationForm`, el programa dice que ese form no existe. En la oral di los tres literales exactos.

[Certain] `Intern.hpp:24-28` declara `FormDoesNotExistException` y `what()`. En `Intern.cpp` ese `what()` no tiene cuerpo. `makeForm` no lanza esa clase: imprime y devuelve 0, que es lo que el subject pide. El programa enlaza porque nadie construye la excepción. Si alguien la lanza, el linker no encuentra `what()`. O escribes el método en el `.cpp`, o borras la clase.

El `operator=` de Shrubbery y Presidential es el mismo agujero que en el ex02, en los `.cpp` de `ex03/`.

[Certain] `Intern.hpp:24` usa `std::exception` y el header no incluye `<exception>`. Compilado solo, con `c++ -std=c++98 -Wall -Wextra -Werror`, pasa, porque en esta libstdc++ `<iostream>` ya trae `<exception>`. Si quieres el header autónomo de verdad, añade el include. Aquí no tumba el ejercicio.

Pregunta: ¿por qué una tabla de funciones y no tres if? Porque el subject rechaza el bosque de if/else, y un `std::map` en este módulo es -42.

Tour: capítulo 5, porque lo que devuelves es la clase abstracta. El capítulo 7 son las plantillas: aquí no hay ninguna y no hacen falta. Trampa: `std::map` (capítulo 12, y además -42), `std::function` y una lambda. El puntero a función estática es C++98.

## Módulo 06 ex00 — APTO

Binario: `convert` (`Makefile:1`). El ejemplo del PDF se ejecuta como `./convert`. El Makefile ya usa `c++`.

El subject pide `ScalarConverter::convert` estático y una clase que el usuario no pueda instanciar. En C++98 eso es constructor privado y copia privada. `= delete` es C++11. Hay que detectar el literal, convertirlo a su tipo, castear a los otros tres e imprimir. Pseudoliterales obligatorios: `-inff`, `+inff`, `nanf`, `-inf`, `+inf`, `nan`. Char no mostrable: mensaje. Overflow o conversión sin sentido: impossible. El PDF fija la salida de `./convert 0`, `./convert nan` y `./convert 42.0f`. El cast que se defiende en este ejercicio es `static_cast`.

[Certain] `ScalarConverter.hpp:8-12` ctor, copia, asignación y destructor son privados. El compilador rechaza `ScalarConverter s;` por ese constructor. No hay `= delete`. Los casts del valor son `static_cast` (`ScalarConverter.cpp:44`, `:47`, `:53`, `:55`, `:64`, `:77`, y los de los caminos de char en `:99-120`). No aparece otro tipo de cast.

[Certain] Los tres ejemplos del PDF salen idénticos, con el `convert` del Makefile:

```
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

[Certain] Los seis pseudos que pide el subject también. `nanf` imprime `float: nanf` y `double: nan`. `+inff` y `+inf` imprimen `float: +inff` y `double: +inf`. `-inff` y `-inf` imprimen `float: -inff` y `double: -inf`. `42.42` sale `42.42f` y `42.42`. `4.2f` sale `4.2f`. `'a'` y `a` dan char `'a'` e int 97. `-42` da char impossible e int -42. `127` es Non displayable. La cadena vacía pone los cuatro a impossible. El sufijo se quita en `ScalarConverter.cpp:128-133`: `nanf`, `+inff` y `-inff` pierden la última `f` antes de `strtod`, y `+inf` / `-inf` no, porque esa `f` es la de `inf`.

Qué estaba roto y ya está cerrado.

1. [Certain] Un float que desborda ya no se disfraza de infinito. `./convert 1e39`, `1e39f` y `3.5e38` imprimen `float: impossible` y dejan el double (`1e+39`, `3.5e+38`). El double es finito; `static_cast<float>` lo convierte en infinito y, solo en ese caso, la línea es `impossible`. `+inff` y `+inf` siguen siendo `float: +inff` porque ahí el double ya era infinito. No mezcles los dos textos.

2. [Certain] El `.0` ya no se incrusta en la notación científica. `writeScaled` mira el texto que escribiría `cout`: si no hay punto ni `e`, añade `.0` (por eso `0` y `42` coinciden con el PDF). Si ya hay exponente, no toca nada. `./convert -2147483649` sale `float: -2.14748e+09f`, no `-2.14748e+09.0f`. La comparación `f == static_cast<int>(f)` se quitó: con un float fuera de `int` ese cast es indefinido.

3. [Certain] La detección de tipo sigue a medias, y es defendible. El char entre comillas y el carácter suelto tienen camino propio. Int, float y double caen en `strtod` y luego `static_cast`. En la oral: el char se detecta; el resto se convierte desde double con casts explícitos. Con la salida de los ejemplos y del overflow ya no es el suspenso.

`inf` a secas sigue en impossible: le quitas la `f` y queda `"in"`. El subject no pide ese literal.

Pregunta: ¿qué imprime `./convert 1e39` en la línea del float, y en qué se distingue de `./convert +inff`? Tienen que ser `impossible` y `+inff`. ¿Por qué `static_cast` y no `reinterpret_cast`?

Tour: el sumario contrastado no tiene un capítulo titulado casts. No invento la sección. La conversión la defiendes tú. Al lado, el capítulo 6.2 enseña el move, y el libro usa `auto`, `nullptr` y `= default`. Aquí eso es cero. Trampa de este archivo: `= delete` en el constructor, `std::stod` / `std::stoi`, y `<cstdint>`. [Certain] `std::isnan` y `std::isinf` (`ScalarConverter.cpp:42`, `:57`, `:59`) compilan con `-std=c++98 -Werror` en esta libstdc++. [Likely] no están en el estándar C++98; entran en C++11, y en C son C99. Si el compilador de la defensa avisa, un NaN se reconoce con `d != d` y el infinito se compara con los límites. No los sustituyas por `std::stod`.

## Módulo 06 ex01 — APTO

Binario: `serializer`.

El subject pide una clase que no se pueda instanciar, `uintptr_t serialize(Data*)` y `Data* deserialize(uintptr_t)`. `Data` con miembros, no vacía. El puntero que sale de `deserialize` compara igual al original. `<cstdint>` es C++11. En C++98 el header es `<stdint.h>`. El cast de este ejercicio es `reinterpret_cast`.

[Certain] `Serializer.hpp:4` incluye `<stdint.h>`. `:11-14` las cuatro de la OCF son privadas. El compilador rechaza `Serializer s;`. `Serializer.cpp:24` hace `reinterpret_cast<uintptr_t>`. `:29` hace `reinterpret_cast<Data *>`. `Data.hpp:7-10` tiene `id`, `name` y `score`. La OCF del struct la escribe el compilador. [Likely] te la aceptan. Si te piden ver las cuatro escritas, van en el `.cpp`, no en el header: una función con cuerpo en un header, si no es plantilla, es 0.

[Certain] Salida: `same pointer : yes`, y los datos restaurados son `id=42`, `name=serialization-test`, `score=3.14`. Las dos direcciones impresas coinciden.

Pregunta: ¿por qué `reinterpret_cast` y no `static_cast`? Un entero y un puntero no están en la misma jerarquía. ¿Por qué `<stdint.h>` y no `<cstdint>`?

Tour: [Certain] el sumario inglés pone punteros, arrays y referencias en 1.7. Eso no es un capítulo de casts, y no lo voy a disfrazar de uno. Trampa: `<cstdint>`, `nullptr`, y escribir `std::uintptr_t` dando por hecho el header de C++11.

## Módulo 06 ex02 — APTO

Binario: `identify`.

El subject pide `Base` con un único miembro: destructor virtual público. `A`, `B` y `C` vacías, herencia pública. Estas cuatro no llevan OCF. `generate()` elige al azar. `identify(Base*)` imprime `A`, `B` o `C`. `identify(Base&)` imprime lo mismo y no puede usar un puntero dentro. Incluir `<typeinfo>` está prohibido. `std::bad_cast` vive en ese header: capturar `std::exception` es la salida legal. El cast es `dynamic_cast`.

[Certain] `Base.hpp:3-8` solo tiene el destructor virtual público. `:10-20` `A`, `B` y `C` están vacías y heredan en público. `main.cpp:19-24` identifica por puntero con `dynamic_cast`. `:27-56` identifica por referencia con `dynamic_cast` a referencia, dentro de `try`, y el `catch` es `std::exception`. En esa función no hay una variable puntero. El archivo no incluye `<typeinfo>`. `:7-14` `generate` usa `rand() % 3`. `:69` hay `delete`. [Certain] valgrind: 0 bytes al salir, 0 errores.

[Certain] En una ejecución de diez objetos aparecen A, B y C. En cada uno, el identify del puntero y el de la referencia imprimen la misma letra.

[Certain] `main.cpp:60` hay un `static_cast` para pasar `time` a `unsigned` antes de `srand`. No identifica ningún objeto. Si te lo señalan, di que el cast del ejercicio es el `dynamic_cast`. No lo cambies por un cast de C para "quitarlo".

[Likely] Un puntero nulo no imprime nada: los tres `dynamic_cast` a puntero fallan y no hay un `else`. No lo ejecuté. El subject no lo pide. Si te lo preguntan, dilo.

Pregunta: ¿por qué la versión por referencia lanza y la de puntero no? El `dynamic_cast` a puntero devuelve nulo si falla. A referencia no tiene un nulo que devolver, así que lanza `std::bad_cast`. Nombrar esa clase obliga a `<typeinfo>`, que está prohibido, y por eso el `catch` es `std::exception`. ¿Qué pasa si quitas el `virtual` del destructor? El objeto deja de ser polimórfico y `dynamic_cast` no tiene un tipo dinámico que mirar.

Tour: capítulo 5.4 y 5.5. Trampa: `#include <typeinfo>`, `typeid`, `override`, y `= default` en el destructor. Las cuatro clases van sin OCF porque el subject lo dice.

## Prohibido

Nota 0 o -42 en los dos módulos:

- C++11: `auto`, `nullptr`, lambda, range-for, `override`, `= default`, `= delete`, `std::stoi`, `std::stod`, `unique_ptr`, moves.
- Boost, `*printf`, `*alloc`, `free`, cualquier librería externa.
- `using namespace` y `friend`.
- Contenedores de la STL y `<algorithm>`. En el ex03, `std::map` es -42 aunque la tabla quede más corta.
- Implementar en un header una función que no sea plantilla.
- `new` sin liberar. [Certain] valgrind limpio en `intern_forms` y en `identify`. El ex00 y el ex01 del 05 no hacen `new`. El ex02 del 05 no hace `new` en el camino del `main`; el `ofstream` cierra al salir del ámbito.

## Obligatorio

- Compilar con `c++ -Wall -Wextra -Werror` y que siga compilando con `-std=c++98`. Las dos cosas están ya en el Makefile: `CXX = c++` y el estándar dentro de `CXXFLAGS`.
- OCF de cuatro en toda clase que el subject no excluya. Excluidas: las excepciones del 05, y `Base`, `A`, `B`, `C` del 06 ex02.
- Sin move.
- Grado 1 el más alto, 150 el más bajo.
- Un cast por ejercicio, y poder decir por qué ese y no otro: `static_cast`, `reinterpret_cast`, `dynamic_cast`.
- Excepciones capturables como `std::exception`.
- Tests propios. Los `main` cubren el camino feliz y algún error. El ex00 del 06, además de los tres ejemplos del PDF, tiene que aguantar `1e39` (`float: impossible`) y un entero grande sin `.0` dentro del exponente. `a = b` entre forms sigue sin estar en el `main` del 05.

## Qué rehacer a mano antes de la defensa

1. Módulo 06 ex00. Vuelve a lanzar, sin mirar el código: `0`, `nan`, `42.0f`, `nanf`, `+inff`, `-inff`, `42.42f`, `1e39`, `3.5e38` y `-2147483649`. Si `1e39` vuelve a decir `+inff`, o si el exponente lleva un `.0` pegado, el ejercicio ha retrocedido.
2. ex02 y ex03: `_target` de Shrubbery y Presidential deja de ser `const`, y el `operator=` lo copia. Robotomy ya lo hace. Si no lo cambias, entra sabiendo explicar que `office = home` sigue plantando en office.
3. Si sobra un rato, y ninguno de estos tres es el suspenso: `executeAction` a `protected`; `what()` de `FormDoesNotExistException` escrito en el `.cpp` o la clase borrada; un `srand` una sola vez en el `main` del ex02.

El arreglo del ex00 está en `module_06-github/ex00/ScalarConverter.cpp`: overflow de float → `impossible`, y el `.0` solo si el texto no trae punto ni exponente.
