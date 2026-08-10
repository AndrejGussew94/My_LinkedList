#pragma once

#include <iostream>

template <typename T>
struct Node {
    T value;
    Node* next;
    Node* prev;
    
    Node() : next(nullptr), prev(nullptr) {}
    Node(const T& val) : value(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    
    Node<T>* get_head() const;
    void set_head(Node<T>* head);
    
    Node<T>* get_tail() const;
    void set_tail(Node<T>* tail);
    
    int get_size() const;
    void set_size(int size);
    
    void append(const T& value);
    void delete_last();
    void clear();
    void reverse();
    void print() const;
    
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};


// make copy operator