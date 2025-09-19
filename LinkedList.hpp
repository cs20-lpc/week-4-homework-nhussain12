#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
protected:
    struct Node {
        T value;
        Node* next;
        Node(const T& val) : value(val), next(nullptr) {}
    };

    // a pointer to the front of the list
    Node* head;

    // the current number of elements in the list
    int length;

public:
    // default constructor
    LinkedList();

    // destructor
    ~LinkedList();

    // Add a Node at the end of a list
    void append(const T&);

    // Delete a node at a specific location in the list
    void remove(int);

    // Search the list for a specific node
    void search(int);

    // Returns the total number of nodes contained in the list
    int getLength() const;

    // Displays the values of each node in the list
    void displayAll() const;

    // Deletes all nodes within a list
    void clear();

    // Returns the element at a particular position
    T& getElement(int);
};

#include "LinkedList.tpp"
#endif


