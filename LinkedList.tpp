#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), length(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& value) {
    Node* new_node = new Node(value);
    
    if(head == nullptr) {
        head = new_node;
    }
    else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
    curr->next = new_node;
    }
    length++;
}

template <typename T>
void LinkedList<T>::remove(int id) {
    // Exception Handling
    if(head == nullptr) {
        throw string("remove: error, list is empty");
    }

    // Function Implementation
    Node* mustDelete;
    if(head->value.getStudentId() == id) {
        mustDelete = head;
        head = head->next;
    } else {
        Node* curr = head;
        while(curr->next != nullptr && curr->next->value.getStudentId() != id) {
            curr = curr->next;
        }
        mustDelete = curr->next;
        if (curr->next == nullptr) {
            throw string("search error: no student found with given ID");
        }
        curr->next = mustDelete->next;
    }
    delete mustDelete;
    length--;
}

template <typename T>
void LinkedList<T>::search(int id) {
    // When list empty
    if (head == nullptr) {
        throw string("search: error, list is empty");
    }

    Node* curr = head;
    while(curr != nullptr && curr->value.getStudentId() != id) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        throw string("search error: no student found with given ID");
    }
    curr->value.displayStudent();
}

template <typename T>
int LinkedList<T>::getLength() const { 
    return length; 
}

template <typename T>
void LinkedList<T>::displayAll() const {
    Node* curr = head;
    while (curr != nullptr) {
        curr->value.display();
        curr = curr->next;
    }
}

template <typename T>
void LinkedList<T>::clear() {
    Node* curr = head;

    while(curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
    length = 0;
}

template <typename T>
T& LinkedList<T>::getElement(int index) {
    if (index < 0 || index >= length) throw string("Index out of bounds");
    Node* curr = head;
    for (int i = 0; i < index; i++) curr = curr->next;
    return curr->value;
}


