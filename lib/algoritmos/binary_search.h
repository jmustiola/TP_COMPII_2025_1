#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "data_structures.h"
#include <cmath>
#include <type_traits>

// TODO: ajustar namespaces en categorias logicas ej.: alg::sorting, alg::searching, etc.
namespace alg
{
    template <class T>
    int binarySearch(estructuras::LinkedList<T> list, T value, double epsilon = 1e-2)
    {
        if (list.size() == 0)
        {
            return -1; // lista vacia
        }

        int left = 0;
        int right = list.size() - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            // TODO: implementar el caso de los flotantes con funcion de comparacion
            if (std::is_floating_point<T>::value)
            {
                // si el tipo es de punto flotante, usamos epsilon para comparar
                if ((std::fabs(list[middle] - value) < epsilon))
                {
                    return middle; // elemento encontrado
                }
                else if (list[middle] < value)
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle - 1;
                }
            }
            else
            {
                if (list[middle] == value)
                {
                    return middle; // elemento encontradi
                }
                else if (list[middle] < value)
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle - 1;
                }
            }
        }

        return -1; // elemento no encontrado
    }
}

#endif // BINARY_SEARCH_H