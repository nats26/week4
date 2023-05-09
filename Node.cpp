#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

void Node::SetLeft(Node* leftNode) {
    left = leftNode;
}

void Node::SetRight(Node* rightNode) {
    right = rightNode;
}

string Node::GetData() const {
    return data;
}

Node* Node::GetLeft() const {
    return left;
}

Node* Node::GetRight() const {
    return right;
}

int Node::GetCount() const {
    return count;
}

void Node::IncrementCount() {
    ++count;
}

void Node::DecrementCount() {
    --count;
}