#pragma once

#include <iostream>

struct Node {
    Node(int value) : value(value), next(nullptr) {}
    Node(int value, Node* next) : value(value), next(next) {}
    int value;
    Node* next;
};

class LinkedList {
public:
    LinkedList() { head = nullptr; tail = nullptr; }
    LinkedList(const LinkedList& otherlist);
    ~LinkedList() { clear(); }
    
    LinkedList& operator=(const LinkedList& otherlist);

    Node* get_head() { return head; }
    void set_head(Node* head) { this->head = head; }

    Node* get_tail() { return tail; }
    void set_tail(Node* tail) { this->tail = tail; }

    void append(int value);
    void clear();
    void print();
    void reverse();
    void delete_value(int remove_value);
    void edit_by_index(int new_value, int target_index);
    void delete_last();

private:
    Node* head = nullptr;
    Node* tail = nullptr;
};


// make copy operator