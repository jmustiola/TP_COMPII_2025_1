#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "data_structures/core/Node/Node.h"

template <class T> class LinkedList
{
private:
    Node<T> *head;

public:
    static LinkedList<T> createListFromStdIn();

    T& operator[](int index);

    LinkedList() : head(nullptr) {}
    void print();
    void append(T value);
    T getMin();
    int indexOf(T value);
    LinkedList<T> splice(int start, int end);
    Node<T>* getLast();
    void insert(int at, T value);
    int size();
    T removeByValueAndReturn(T value);
};

#include "LinkedList.tpp"

#endif // LINKEDLIST_H