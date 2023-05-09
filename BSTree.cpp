#include "BSTree.h"
#include <algorithm>
using namespace std;

BSTree::BSTree() : root(nullptr) {}

BSTree::~BSTree() {
    delete root; // change later
}

void BSTree::insert(const string & newString) {
    Node* curr = root;

    if (search(newString)) {
        curr = GetNode(newString); // find exact node so count can be incremented
        curr->IncrementCount();
    }
    else {
        Node* insertNew = new Node(newString);

        if (curr == nullptr) {
            root = insertNew; // if tree is empty insert root
        }
        else {
            bool returnStatement = true;

            while (returnStatement) { // while loop helps find parent
                if (newString < curr->GetData()) {
                    if (curr->GetLeft() == nullptr) { // if bst left is open insert node
                        curr->SetLeft(insertNew);
                        returnStatement = false;
                    }
                    else { // if not open, go left again
                        curr = curr->GetLeft();
                    }
                }
                else {
                    if (curr->GetRight() == nullptr) { // if bst right is open insert node
                        curr->SetRight(insertNew);
                        returnStatement = false;
                    }
                    else { // else if not open go right
                        curr = curr->GetRight();
                    }
                }
            }
        }
    }
}

bool BSTree::search (const string & key) const {
    Node* curr = root;

    while (curr != nullptr && curr->GetData() != key) {
        if (key < curr->GetData()) {
            curr = curr->GetLeft(); // if key is less than curr, go left
        }
        else if (key > curr->GetData()) {
            curr = curr->GetRight(); // if key is greater than curr, go right
        }
    }

    return curr != nullptr; // if key is found, curr will not be nullptr
}

string BSTree::largest() const {
    Node* curr = root;

    if (curr == nullptr) {
        return ""; // if tree is empty return empty string
    }
    else {
        while (curr->GetRight() != nullptr) {
            curr = curr->GetRight(); // curr goes right
        }
        return curr->GetData();
    }
}

string BSTree::smallest() const {
    Node* curr = root;

    if (curr == nullptr) {
        return ""; // if tree is empty return empty string
    }
    else {
        while (curr != nullptr) {
            curr = curr->GetLeft(); // curr goes left
        }
        return curr->GetData();
    }
}

int BSTree::height(const string & userVal) const {
    if (!search(userVal)) {
        return -1; // return -1 if userVal isn't part of tree
    }
    
    Node* curr = GetNode(userVal); // when recursion loops, function will find new curr
    Node* nextLeft = curr;
    Node* nextRight = curr;
    int countLeft = 0;
    int countRight = 0;

    if (curr->GetLeft() != nullptr) {
        nextLeft = nextLeft->GetLeft();
        ++countLeft;
        countLeft = countLeft + height(nextLeft->GetData()); // recursive function until there is no left node
    } 

    if (curr->GetRight() != nullptr) {
        nextRight = nextRight->GetRight();
        ++countRight;
        countRight = countRight + height(nextRight->GetData()); // recursive function until there is no right node
    }

    if (countLeft > countRight) {
        return countLeft;
    }
    else {
        return countRight;
    }
}

void BSTree::remove(const string & userVal) {
    Node* removeNode = GetNode(userVal);

    if (removeNode->GetCount() > 1) {
        removeNode->DecrementCount(); // if there is more than one only decrease count
    }
    else {
        if (removeNode->GetLeft() == nullptr && removeNode->GetRight() == nullptr) {
            delete removeNode; // simply delete leaf nodes
        }
        else {
            // for non leaf nodes
        }
    }
}

Node* BSTree::GetNode(const string & key) const {
    Node* curr = root;

    if (search(key)) { // save time - run only if key is found
        while (curr->GetData() != key) {
            if (key < curr->GetData()) {
                curr = curr->GetLeft();
            }
            else if (key > curr->GetData()) {
                curr = curr->GetRight();
            }
            else {
                return curr;
            }
        }
    }

    return curr;
}

void BSTree::preOrder() const {
    printPreOrder(root);
}

void BSTree::printPreOrder(Node* node) const {
    if (node != nullptr) {
        cout << node->GetData() << "(" << node->GetCount() << "), ";
        printPreOrder(node->GetLeft());
        printPreOrder(node->GetRight());
    }
}

void BSTree::postOrder() const {
    printPostOrder(root);
}

void BSTree::printPostOrder(Node* node) const {
    if (node != nullptr) {
        printPostOrder(node->GetLeft());
        printPostOrder(node->GetRight());
        cout << node->GetData() << "(" << node->GetCount() << "), ";
    }
}

void BSTree::inOrder() const {
    printInOrder(root);
}

void BSTree::printInOrder(Node* node) const {
    if (node != nullptr) {
        printInOrder(node->GetLeft());
        cout << node->GetData() << "(" << node->GetCount() << "), ";
        printInOrder(node->GetRight());
    }
}