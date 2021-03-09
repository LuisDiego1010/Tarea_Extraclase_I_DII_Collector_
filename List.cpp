//
// Created by diegoubuntu on 9/3/21.
//
#include "iostream"
#include "List.h"


using namespace std;


void List::insert(int value) {
    Node *newValue=new Node();
    *newValue->setValue(value);
    newValue->aux=firts;
    firts=newValue;
}