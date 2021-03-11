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
    void setNext(Node *_next);
    Node* getNext();
    void* operator new (size_t nodeNew);
    void operator delete (void* nodeDel);
};

void Node::setValue(int _value) {
    *value=_value;
}

int Node::getValue() {
    return *value;
}

void Node::setNext(Node *_next) {
    next=_next;
}

Node* Node::getNext() {
    return next;
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
            firts=temp->getNext();
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
        temp=temp->getNext();
        i++;
    }
}


class Collector {
public:
    static Node *firts;
    static long isEmpty();
    static void insertCollector(Node* _nodeC);
    static void showCollector();
};
Node* Collector::firts= nullptr;

Node * Collector::getFirts() {
    Node *temp = firts;
    firts=firts->getNext();
    temp->setNext(nullptr);
    return temp;
}

long Collector::isEmpty() {
    if (firts==nullptr){
        return NULL;
    }
}
void Collector::insertCollector(Node* _nodeC) {
    _nodeC->next=firts;
    firts=_nodeC;
}
void Collector::showCollector() {
    int i=0;
    if (firts==nullptr){
        cout<<"The collector is empty"<<endl;
    }
    Node *temp=firts;
    while (temp!= nullptr){
        cout<<"("<<i<<")->"<<*temp->value<<endl;
        temp=temp->getNext();
        i++;
    }
}

void* Node::operator new(size_t nodeNew){
    //Lógica del new
    if (Collector::isEmpty()==NULL){
        return ::new Node(0);
    }else{
        Collector::getFirts();
    }
}


void Node::operator delete(void* nodeDel){
   Collector::insertCollector(static_cast<Node *>(nodeDel));
}

int main() {
    List *List1 = new List();
    List1->insert(10);
    List1->insert(20);
    List1->insert(30);

    List1->showElement();

    List1->deleteElement(10);
    List1->insert(40);

    List1->deleteElement(20);
    Collector::showCollector();


}
