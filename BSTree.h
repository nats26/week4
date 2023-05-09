#pragma once
#include <algorithm>
#include "Node.h"
using namespace std;

class BSTree {
private:
    Node* root;
public:
    BSTree(); // constructor
    ~BSTree(); // destructor
    void insert(const string &); // insert with count 1, duplicates increment count
    bool search (const string &) const; // return true if string is in tree
    string largest() const; // return largest val
    string smallest() const; // return smallest val
    int height(const string &) const; // returns height of string in tree, -1 if string DNE
    void remove(const string &); // remove string according to BST rules
    Node* GetNode(const string &) const; // returns node of the user given string

    void preOrder() const;
    void postOrder() const;
    void inOrder() const;
    void printPreOrder(Node* node) const; // used in recursion for preOrder
    void printPostOrder(Node* node) const; // PostOrder usage
    void printInOrder(Node* node) const; // InOrder usage
};