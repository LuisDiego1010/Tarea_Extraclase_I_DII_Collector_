#include<iostream>

using namespace std;

class Node {
public:
    int *value= nullptr;
    Node *next = nullptr;
    void setValue(int _value);
    int getValue();
    void setNext(Node _next);
    Node getNext();
};

void Node::setValue(int _value) {
    value=new(int);
    *value=_value;
}
int Node::getValue() {
    return *value;
}

void Node::setNext(Node _next) {
    *next=_next;
}

Node Node::getNext() {
    return *next;
}


class List {
public:
    Node *firts=nullptr;
    void deleteElement(int _value);
    void showElement();
    void insert(int _value);
};

void List::insert(int _value) {
    Node *newValue=new Node();
    newValue->setValue(_value);
    newValue->next=firts;
    firts=newValue;
}

void List::deleteElement(int _value) {
    if(firts== nullptr){
        cout<<"EMPTY LIST"<<endl;
    }else{
        Node *temp=firts, *prev= nullptr; //Auxiliar Nodes
        if(temp!= nullptr && *temp->value==_value){
            *firts=temp->getNext();
            return;
        }
        while (temp!= nullptr && *temp->value!=_value){ //Scroll through the list to find the item
            prev=temp;
            temp=temp->next;
        }
        if (temp== nullptr){
            cout<<"The item is not in the list"<<endl;
            return;
        }
        prev->next=temp->next;
        delete temp;
    }
}

void List::showElement() {
    int i=0;
    if (firts==nullptr){
        cout<<"The list is empty"<<endl;
    }
    Node *temp=firts;
    while (temp!= nullptr){
        cout<<"["<<i<<"]->"<<*temp->value<<endl;
        *temp=temp->getNext();
        i++;
    }
}

int main() {
    List *List1 = new List();
    List1->insert(10);
    List1->insert(20);
    List1->insert(30);
    List1->insert(40);
    List1->insert(50);

    List1->deleteElement(10);
    List1->deleteElement(10);
    List1->deleteElement(10);
    List1->deleteElement(30);

    List1->showElement();
    cout<<"Finish";
}
