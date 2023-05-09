#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    string data;
    int count;
    Node* left;
    Node* right;

public: 
    Node(string userData) : data(userData), count(1), left(nullptr), right(nullptr) {} 
    // each node has a string, left/right pointer and integer count
    void SetLeft(Node*); // mutator
    void SetRight(Node*);
    void IncrementCount();
    void DecrementCount();
    string GetData() const; // accessor
    Node* GetLeft() const;
    Node* GetRight() const;
    int GetCount() const;
};