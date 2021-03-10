//
// Created by diegoubuntu on 9/3/21.
//

#ifndef TAREA_EXTRACLASE_1_DATOS_II_NODE_H
#define TAREA_EXTRACLASE_1_DATOS_II_NODE_H


class Node {
public:
    int *value= nullptr;
    Node *next = nullptr;
    void setValue(int _value);
    int getValue();
    void setNext(Node _next);
    Node getNext();
};


#endif //TAREA_EXTRACLASE_1_DATOS_II_NODE_H
