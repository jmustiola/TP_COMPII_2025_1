#include <iostream>
#include "LinkedList.h"
#include "Node.h"


template <class T>
void LinkedList<T>::append(T value)
{
    Node<T> *newNode = new Node<T>(value);
    newNode->setNextNode(head);
    head = newNode;
}

template <class T>
Node<T>* LinkedList<T>::getLast()
{
    Node<T> *current = head;
    if (current == nullptr) return nullptr;
    while (current->getNextNode() != nullptr) current = current->getNextNode();
    return current;
}

template <class T>
int LinkedList<T>::size()
{
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
    if (at < 0 || at > size()) return;
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
