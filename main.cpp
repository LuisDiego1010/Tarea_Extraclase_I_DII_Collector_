#include<iostream>

using namespace std;

/*
 * Class node
 * Cotains methods and atributtes for create a List and Collector
 */
class Node {
public:
    //Class atributtes
    int *value= nullptr;
    Node *next = nullptr;
    Node(int _value){ //Class Builder
        value=new(int);
        setValue(_value);
    }
    //Declare methods
    void setValue(int _value);
    int getValue();
    void setNext(Node *_next);
    Node* getNext();
    //Overload methods new and delete
    void* operator new (size_t);
    void operator delete (void* nodeDel);
};
//Class methods
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
/*
 * Class List
 * It is responsible for storing integer data, it contains its attributes to be able to access and modify this data.
 */
class List {
public:
    //Class atributtes
    Node *firts=nullptr;
    //Declare class methods
    void deleteElement(int _value);
    void showElements();
    void insert(int _value);
};

//Class methods
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
            delete temp;
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

void List::showElements() {
    int i=0;
    if (firts==nullptr){
        cout<<"The list is empty"<<endl;
    }
    Node *temp=firts;
    while (temp!= nullptr){
        cout<<"["<<i<<"]->"<<temp->getValue()<<endl;
        temp=temp->getNext();
        i++;
    }
}

/*
 * Class Collector
 * The one responsible for recycling the freed memory in the list class
 */

class Collector {
public:
    //Class atributtes
    static Node *firts;
    //Declare class methods
    static Node* getFirts();
    static long isEmpty();
    static void insertCollector(Node* _nodeC);
    static void showCollector();
};
Node* Collector::firts= nullptr;

//Class methods

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
        cout<<"{"<<i<<"}->"<<temp->getValue()<<endl;
        temp=temp->getNext();
        i++;
    }
}

//Overload methods new and delete
void* Node::operator new(size_t){
    //L??gica del new
    if (Collector::isEmpty()==NULL){
        return ::new Node(0);
    }else{
        Collector::getFirts();
    }
}

void Node::operator delete(void* nodeDel){
   Collector::insertCollector(static_cast<Node *>(nodeDel));
}

//Run the program
int main() {
    cout<<"This program is the first extra class task of the CE2103 Computer Engineering course at Tecnol??gico de Costa Rica.\nWhich consists of a collector to recycle the memory freed by a list of nodes."<<endl;
    List *List1 = new List();
    bool loop = true;
    while (loop){
        cout<<"\n MAIN MENU" <<endl<<"  1. Insert Element \n  2. Delete Element \n  3. Show List Elements \n  4. Show Collector \n  5. Exit\n"<<endl;
        int option;
        cout<<"\nEnter an option: "; cin>>option;
        switch (option) {
            case 1:
                int _value;
                cout<<"\nPlease enter the number you want to insert: ";cin>>_value;
                cout<<"\nChecking if collector is empty and inserting node...\n"<<endl;
                List1->insert(_value);
                break;
            case 2:
                int _value2;
                cout<<"\nPlease enter the number you want to delete: ";cin>>_value2;
                cout<<"\nDeleting node and recycling in collector..."<<endl;
                List1->deleteElement(_value2);
                break;
            case 3:
                cout<<"\nWatching list: \n"<<endl;
                List1->showElements();
                break;
            case 4:
                cout<<"\nWatching collector: \n"<<endl;
                Collector::showCollector();
                break;
            case 5:
                cout<<"\nThanks for use Collector app \n";
                loop=false;
                break;

            default: cout<<"\nOption is not in range. Please enter a valid option\n";
        }
    }
    return 0;
}
