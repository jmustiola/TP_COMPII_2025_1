

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "data_structures.h"

namespace alg
{
    template <class T>
    void selectionSort(estructuras::LinkedList<T>& list)
    {
        int size = list.size();
        for (int i = 0; i < size; i++)
        {
            T minValue = list[i];
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
    }
}


#endif