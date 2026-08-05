#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& otherlist) {
    head = nullptr;
    tail = nullptr;
    
    Node* current_other = otherlist.head;
    while(current_other != nullptr) {
        append(current_other->value);
        current_other = current_other->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& otherlist) {
    if (this == &otherlist) {
        return *this;
    }
    
    clear();    

    Node* current_other = otherlist.head;
    while(current_other != nullptr) {
        append(current_other->value);
        current_other = current_other->next;
    }
    
    return *this;
}

void LinkedList::append(int value) { 
    Node* new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
        tail = head;
        return;
    }
    
    tail->next = new_node;
    tail = new_node;
}

void LinkedList::clear() {
    
    while(head != nullptr) {
        Node* node_to_delete = head;
        head = head->next;
        delete node_to_delete;
    }
    tail = nullptr;
}

void LinkedList::print() {
    if (head == nullptr) return;
    Node* temp_node = head;
    while(temp_node != nullptr) {
        std::cout << temp_node->value;
        if (temp_node->next != nullptr) std::cout << ", ";
        temp_node = temp_node->next;
    }
    std::cout << std::endl;
}

void LinkedList::reverse() {
    if (head == nullptr) return;

    tail = head;
    Node* current_node = head;
    Node* previous_node = nullptr;
   
    while (current_node != nullptr) {
        Node* next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    head = previous_node;
    
}

void LinkedList::delete_value(int remove_value) {
    while (head != nullptr && head->value == remove_value) {
        Node* node_to_delete = head;
        head = head->next;
        delete node_to_delete;
    }
    
    if (head == nullptr) {
        tail = nullptr; 
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->value == remove_value) {
            Node* node_to_delete = current->next;
            current->next = current->next->next;
            if(current->next == nullptr) tail = current;
            delete node_to_delete;
        } else {
            current = current->next;
        }
    }
}


void LinkedList::edit_by_index(int new_value, int target_index) {
    if (head == nullptr) {
        std::cout << "This list is empty" << std::endl;
        return;
    }
    
    int index = 0;
    Node* temp = head;
    
    while(temp != nullptr && index < target_index) {
        temp = temp->next;
        index++;
    }
    
    if (temp == nullptr) {
        std::cout << "This index does not exist" << std::endl;
        return;
    }
    
    temp->value = new_value;
}

void LinkedList::delete_last() {
   
    if (head == nullptr) {
        return;
    }
    
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;

}

