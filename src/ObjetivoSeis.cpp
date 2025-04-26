/*

    Objetivo 6: Ordenacion por seleccion
    ====================================

    - Un método de ordenación muy simple, pero no muy eficiente, de elementos 𝒙𝟏, 𝒙𝟐,
    𝒙𝟑,...𝒙𝒏 en orden ascendente es el siguiente:

    * Paso 1: Localizar el elemento más pequeño de la lista 𝒙𝟏 a 𝒙𝒏; intercambiarlo con 𝒙𝟏.
    * Paso 2: Localizar el elemento más pequeño de la lista 𝒙𝟐 a 𝒙𝒏 ; intercambiarlo con 𝒙𝟐.
    * Paso 3: Localizar el elemento más pequeño de la lista 𝒙𝟑 a 𝒙𝒏; intercambiarlo con 𝒙𝒏.

    En el último paso, los dos últimos elementos se comparan e intercambian, si es 
    necesario, y la ordenación se termina. Realice un programa en C++ para ordenar una 
    lista de elementos, siguiendo el método descrito previamente.

*/

#include "DataStructures.h"
#include <iostream>
using namespace std;

void objetivoSeis(bool useDefault = false)
{ 
    // si default es verdadero, se crea una lista por defecto
    // de 7 elementos, de lo contrario se crea una lista
    // a partir de la entrada estandar

    LinkedList<int> list;

    if (useDefault)
    {
        cout << "Creando lista por defecto..." << endl;
        list.append(30);
        list.append(10);
        list.append(5);
        list.append(20);
        list.append(15);
        list.append(35);
        list.append(25);
        cout << "Lista por defecto creada." << endl;
        cout << "Lista por defecto: ";
        list.print();
    }
    else
    {
        cout << "Creando lista a partir de la entrada estandar..." << endl;
        list = LinkedList<int>::createListFromStdIn();
        cout << "Lista creada." << endl;
        cout << "Lista: ";
        list.print();
    }

    // ordenar la lista usando el metodo de ordenacion por seleccion
    int size = list.size();
    for (int i = 0; i < size; i++)
    {

        int minValue = list[i];
        for (int j = i + 1; j < size; j++)
        {
            // encontrar el índice del elemento mas pequeno en la lista
            // desde i hasta el final de la lista
            if (minValue > list[j])
            {
                // intercambiar el elemento mas pequeno con el
                // elemento en la posicion i
                minValue = list[j];
                list[j] = list[i];
                list[i] = minValue;
            }
        }
    }

    cout << "Lista ordenada: ";
    list.print();
    cout << "Fin de la lista ordenada." << endl;
}
