//
// Created by diegoubuntu on 9/3/21.
//
#include "iostream"
#include "List.h"


using namespace std;


void List::insert(int _value) {
    Node *newValue=new Node();
    *newValue->setValue(_value);
    newValue->next=firts;
    firts=newValue;
}
void List::deleteElement(int _value) {
    if(firts== nullptr){
        cout<<"EMPTY LIST"<<endl;
    }else{
        Node temp=firts, prev= nullptr; //Auxiliar Nodes
        if(temp!= nullptr &&temp->value==_value){
            firts=temp->next;
            return;
        }
        while (temp!= nullptr && temp->value!=_value){ //Scroll through the list to find the item
            prev=temp;
            temp=temp->next;
        }
        if (temp== nullptr){
            return;
        }
        prev->next=temp->next;
        delete temp;
    }
}