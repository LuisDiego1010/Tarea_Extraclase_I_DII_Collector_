//
// Created by diegoubuntu on 9/3/21.
//

#ifndef TAREA_EXTRACLASE_I_DII_COLLECTOR__LIST_H
#define TAREA_EXTRACLASE_I_DII_COLLECTOR__LIST_H
#include "Node.h"

class List {
public:
    Node *firts=nullptr;
    void deleteElement(int _value);
    void showElement();
    void insert(int _value);
};


#endif //TAREA_EXTRACLASE_I_DII_COLLECTOR__LIST_H
