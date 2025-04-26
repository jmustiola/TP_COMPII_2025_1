// Archivo de cabecera Nodo.h
#ifndef _NODO_H
#define _NODO_H

template <class T> class Node {
protected:
  T value;
  Node *next;

public:
  Node(T v) { value = v; next = nullptr; }
  Node(T v, Node *n)
  {
    value = v;
    next = n;
  }
  // Constructor de copia
  Node(const Node &other) : value(other.value), next(other.next) {}
  // Destructor
  ~Node() { delete next; }
  T getNodeValue() const { return value; }
  T& getNodeValueRef() { return value; }
  Node *getNextNode() const { return next; }
  void setNextNode(Node *nextNode) { next = nextNode; }
};

#endif // _NODO_H
