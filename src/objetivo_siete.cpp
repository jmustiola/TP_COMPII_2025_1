/*

    Objetivo 7: Binary Search
    ====================================

    - Realizar un programa en C++ que realice las siguientes tareas:
    * a) Generar, aleatoriamente e imprimir una lista de 999 números reales en el rango de  0 a 2000.
    * b) Buscar si existe el número x (leído del teclado) en la lista. Aplicar la búsqueda  binaria.

*/

#include "data_structures.h"
#include "algoritmos.h"
#include <iostream>
#include <random>
using namespace std;


void objetivoSiete()
{
    estructuras::LinkedList<double> list;

    // generar una lista de 999 numeros reales aleatorios en el rango de 0 a 2000
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::uniform_real_distribution<double> dis(0.0, 2000.0);

    for (int i = 0; i < 20; i ++)
    {
        list.append(dis(gen));
    }

    cout << "lista generada: ";
    list.print();
    cout << "fin de la lista generada" << endl;

    cout << "ordenando la lista..." << endl;
    alg::selectionSort(list);
    cout << "lista ordenada: ";
    list.print();
    cout << "fin de la lista ordenada" << endl;

    double x;
    cout << "ingrese el numero a buscar: ";
    cin >> x;
    cout << "has ingresado el numero " << x << endl;
    cout << "buscando el numero " << x << " en la lista..." << endl;
    int index = alg::binarySearch(list, x);
    if (index != -1)
    {
        cout << "el numero " << x << " se encuentra en la lista en la posicion " << index << endl;
    }
    else
    {
        cout << "el numero " << x << " no se encuentra en la lista" << endl;
    }
    cout << "fin de la busqueda" << endl;
    cout << "fin del objetivo 7" << endl;
}