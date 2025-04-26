// #include "Node.h"

#ifndef LINKED_LIST_TPP
#define LINKED_LIST_TPP

#include <iostream>
// #include "LinkedList.h"

template <class T>
void LinkedList<T>::append(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node<T> *current = head;
    while (current->getNextNode() != nullptr)
    {
        current = current->getNextNode();
    }
    current->setNextNode(newNode);
}

template <class T>
Node<T> *LinkedList<T>::getLast()
{
    Node<T> *current = head;
    if (current == nullptr)
        return nullptr;
    while (current->getNextNode() != nullptr)
        current = current->getNextNode();
    return current;
}

template <class T>
int LinkedList<T>::size()
{
    if (head == nullptr)
        return 0;

    Node<T> *current = head;
    int count = 0;
    while (current != nullptr)
    {
        count++;
        current = current->getNextNode();
    }
    return count;
}

template <class T>
void LinkedList<T>::insert(int at, T value)
{
    if (at < 0 || at > size())
        return;
    if (at == 0)
    {
        append(value);
        return;
    }
    Node<T> *newNode = new Node<T>(value);
    Node<T> *current = head;
    for (int i = 0; i < at - 1; i++)
    {
        current = current->getNextNode();
    }
    newNode->setNextNode(current->getNextNode());
    current->setNextNode(newNode);
}

template <class T>
void LinkedList<T>::print()
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        std::cout << current->getNodeValue() << " ";
        current = current->getNextNode();
    }
    std::cout << std::endl;
}

template <class T>
T LinkedList<T>::getMin()
{
    // TODO: Asegurar comparacion de T para tipos no comparables y para los que si lo son
    Node<T> *current = head;

    if (current == nullptr)
        return T(); // Retorna un valor por defecto de T

    T min = current->getNodeValue();
    while (current != nullptr)
    {
        if (current->getNodeValue() < min)
        {
            min = current->getNodeValue();
        }
        current = current->getNextNode();
    }

    return min;
}

template <class T>
LinkedList<T> LinkedList<T>::splice(int start, int end)
{

    // TODO:
    if (start < 0 || end < start || end >= size() || start >= size())
    {
        std::cerr << "Indices invalidos para la lista enlazada." << std::endl;
        return LinkedList<T>(); // Retorna una lista vacia
    }

    LinkedList<T> newList;
    Node<T> *current = head;
    int index = 0;

    while (current != nullptr && index <= end)
    {
        if (index >= start)
        {
            newList.append(current->getNodeValue());
        }
        current = current->getNextNode();
        index++;
    }
    return newList;
}

template <class T>
T LinkedList<T>::removeByValueAndReturn(T value)
{
    // TODO:
    Node<T> *current = head;
    Node<T> *preview = nullptr;

    while (current != nullptr)
    {
        if (current->getNodeValue() == value)
        {
            // ...
            if (preview == nullptr)
            {
                head = current->getNextNode();
            }
            else
            {
                preview->setNextNode(current->getNextNode());
            }

            T returnValue = current->getNodeValue();
            delete current;
            return returnValue;
        }

        preview = current;
        current = current->getNextNode();
    }
    return T(); // Retorna un valor por defecto de T si no se encuentra el valor
}

template <class T>
int LinkedList<T>::indexOf(T value)
{
    // TODO:
    Node <T> *current = head;
    int index = 0;
    while (current != nullptr)
    {
        if (current->getNodeValue() == value)
        {
            return index;
        }
        current = current->getNextNode();
        index++;
    }
    return -1; // Retorna -1 si no se encuentra el valor
}

template <class T>
T& LinkedList<T>::operator[](int index)
{
    if (index < 0 || index >= size()) {
        throw std::out_of_range("Indice fuera de rango");
    }

    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->getNextNode();
    }
    return current->getNodeValueRef();
}

template <class T>
LinkedList<T> LinkedList<T>::createListFromStdIn()
{
    int x;
    LinkedList<T> list;
    std::cout << "Termina con -1" << std::endl;
    do
    {
        std::cin >> x;
        if (x != -1)
        {
            list.append(x);
        }
        else
        {
            std::cout << "Fin de la lista" << std::endl;
        }
    } while (x != -1);
    return list;
}

#endif // LINKED_LIST_TPP