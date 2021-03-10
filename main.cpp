#include<iostream>

using namespace std;


class Node {
public:
    //crear constructor
    int *value= nullptr;
    Node *next = nullptr;
    Node(int _value){
        value=new(int);
        setValue(_value);
    }

    void setValue(int _value);
    int getValue();
    void setNext(Node _next);
    Node getNext();
    void* operator new (size_t nodeNew);
    void operator delete (void* nodeDel);
};

void Node::setValue(int _value) {
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

void* Node::operator new(size_t nodeNew){
    //Lógica del new
    //Crear constructor y si está vacio que llame al constructor
}


void Node::operator delete(void* nodeDel){
    //Lógica del delete Pasarle el puntero al collector
}

class List {
public:
    Node *firts=nullptr;
    void deleteElement(int _value);
    void showElement();
    void insert(int _value);
};

void List::insert(int _value) {
    Node *newValue=new Node(_value);
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


class Collector {
public:
    Node *firts=nullptr;
    long isEmpty();
    void insertCollector(Node _nodeC);
    void getCollector();
    void showCollector();
};

long Collector::isEmpty() {
    if (firts==nullptr){
        return NULL;
    }
}

void Collector::showCollector() {
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
