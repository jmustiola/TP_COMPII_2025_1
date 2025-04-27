# TP Computacion II

## Descripción

Este proyecto corresponde al Trabajo Práctico de la materia Computación II. Implementa diversas estructuras de datos y algoritmos fundamentales, incluyendo listas enlazadas y algoritmos de búsqueda y ordenamiento. El objetivo principal es demostrar la comprensión y aplicación de los conceptos aprendidos en la materia

## Especificaciones Técnicas

| Característica           | Descripción                                               |
| ------------------------ | --------------------------------------------------------- |
| Lenguaje de Programación | C++                                                       |
| Estructuras de Datos     | Lista Enlazada (LinkedList)                               |
| Algoritmos               | Búsqueda Binaria, Selección Ordenamiento (Selection Sort), Floyd-Wharshall |
| Compilación              | CMake                                                     |

## Dependencias

*   **CMake:**  Utilizado para la gestión del proceso de compilación y generación de los archivos necesarios para la construcción del proyecto.
*   **Biblioteca Estándar de C++ (STL):**  Se utilizan componentes de la STL tales como `<iostream>`, `<random>`, `<cmath>`, `<type_traits>` para funcionalidades de entrada/salida, generación de números aleatorios, funciones matemáticas y manipulación de tipos, respectivamente.

## Intrucciones para la compilacion

### Cualquier sistema operativo

Abre el terminal un terminal y ejecuta

```sh
git clone git@github.com:jmustiola/TP_COMPII_2025_1.git
cd TP_COMPII_2025_1
```

O Puedes [descargar](https://github.com/jmustiola/TP_COMPII_2025_1/archive/refs/heads/main.zip) el proyecto en .zip y descomprimirlo

Una vez dentro del directorio

```sh
mkdir build # debes crear una carpeta build dentro de la raiz
cd build # entrar a la carpeta
cmake ..
cmake --build .
```

### Si estas en Windows

Ejecuta el script que viene dentro del repositorio para automatizar la compilacion

```sh
.\build.bat
```