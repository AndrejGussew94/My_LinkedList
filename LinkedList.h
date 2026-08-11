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
    LinkedList(const LinkedList& other);
    ~LinkedList();
    
    LinkedList& operator=(const LinkedList& other);
    
    // Геттеры и сеттеры
    Node<T>* get_head() const;
    void set_head(Node<T>* head);
    
    Node<T>* get_tail() const;
    void set_tail(Node<T>* tail);
    
    int get_size() const;
    void set_size(int size);
    
    // Основные операции
    void append(const T& value);
    void delete_last();
    void clear();
    void reverse();
    void print() const;
    
    // Дополнительные операции
    void delete_value(const T& value);      // Удаление всех элементов с заданным значением
    void edit_by_index(const T& new_value, int index);  // Изменение элемента по индексу
    
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};


// make copy operator