#include "LinkedList.h"

// TODO: repair copy constructor and update library in repository

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), size(0) {
    Node<T>* current = other.head;
    while (current != nullptr) {
        append(current->value);
        current = current->next;
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this != &other) {
        clear();
        Node<T>* current = other.head;
        while (current != nullptr) {
            append(current->value);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
Node<T>* LinkedList<T>::get_head() const {
    return head;
}

template <typename T>
void LinkedList<T>::set_head(Node<T>* head) {
    this->head = head;
}

template <typename T>
Node<T>* LinkedList<T>::get_tail() const {
    return tail;
}

template <typename T>
void LinkedList<T>::set_tail(Node<T>* tail) {
    this->tail = tail;
}

template <typename T>
int LinkedList<T>::get_size() const {
    return size;
}

template <typename T>
void LinkedList<T>::set_size(int size) {
    this->size = size;
}

template <typename T>
void LinkedList<T>::append(const T& value) {
    Node<T>* new_node = new Node<T>(value);
    
    if (size == 0) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    size++;
}

template <typename T>
void LinkedList<T>::delete_last() {
    if (size == 0) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    
    if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<T>* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    size--;
}

template <typename T>
void LinkedList<T>::clear() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
void LinkedList<T>::reverse() {
    if (size <= 1) {
        return;
    }
    
    Node<T>* current = head;
    Node<T>* temp = nullptr;
    
    
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  
    }
    
    temp = head;
    head = tail;
    tail = temp;
}


template <typename T>
void LinkedList<T>::print() const {
    if (size == 0) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    Node<T>* current = head;
    std::cout << "List (size = " << size << "): ";
    while (current != nullptr) {
        std::cout << current->value;
        if (current->next != nullptr) {
            std::cout << " <-> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<std::string>;
