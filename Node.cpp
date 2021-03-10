//
// Created by diegoubuntu on 9/3/21.
//

#include "Node.h"

using namespace std;

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
