#include <iostream>
#include <cassert>
#include <string>
#include "LinkedList.h"

using namespace std;

// ==================== ТЕСТЫ ДЛЯ LINKEDLIST ====================

// Тест 1: Создание пустого списка
void test_constructor() {
    cout << "Testing constructor... ";
    LinkedList<int> list;
    assert(list.get_head() == nullptr);
    assert(list.get_tail() == nullptr);
    assert(list.get_size() == 0);
    cout << "PASSED ✓" << endl;
}

// Тест 2: Добавление элементов (append)
void test_append() {
    cout << "Testing append... ";
    LinkedList<int> list;
    list.append(10);
    assert(list.get_head() != nullptr);
    assert(list.get_head()->value == 10);
    assert(list.get_tail()->value == 10);
    assert(list.get_size() == 1);
    
    list.append(20);
    assert(list.get_tail()->value == 20);
    assert(list.get_head()->next->value == 20);
    assert(list.get_size() == 2);
    
    list.append(30);
    assert(list.get_tail()->value == 30);
    assert(list.get_tail()->next == nullptr);
    assert(list.get_size() == 3);
    
    cout << "PASSED ✓" << endl;
}

// Тест 3: Очистка списка (clear)
void test_clear() {
    cout << "Testing clear... ";
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    
    assert(list.get_head() != nullptr);
    assert(list.get_size() == 4);
    list.clear();
    assert(list.get_head() == nullptr);
    assert(list.get_tail() == nullptr);
    assert(list.get_size() == 0);
    
    // Очистка пустого списка
    list.clear();
    assert(list.get_head() == nullptr);
    assert(list.get_tail() == nullptr);
    assert(list.get_size() == 0);
    
    cout << "PASSED ✓" << endl;
}

// Тест 4: Проверка print
void test_print() {
    cout << "Testing print... ";
    LinkedList<int> list;
    
    cout << "\n  Empty list: ";
    list.print();
    
    list.append(1);
    list.append(2);
    list.append(3);
    cout << "  List with elements: ";
    list.print();
    
    cout << "PASSED ✓" << endl;
}

// Тест 5: Проверка разворота списка (reverse)
void test_reverse() {
    cout << "Testing reverse... ";
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    
    list.reverse();
    
    Node<int>* current = list.get_head();
    assert(current->value == 5);
    current = current->next;
    assert(current->value == 4);
    current = current->next;
    assert(current->value == 3);
    current = current->next;
    assert(current->value == 2);
    current = current->next;
    assert(current->value == 1);
    assert(current->next == nullptr);
    
    assert(list.get_tail()->value == 1);
    assert(list.get_size() == 5);
    
    // Реверс пустого списка
    LinkedList<int> empty_list;
    empty_list.reverse();
    assert(empty_list.get_head() == nullptr);
    assert(empty_list.get_size() == 0);
    
    cout << "PASSED ✓" << endl;
}

// Тест 6: Реверс списка с двумя элементами
void test_reverse_two_elements() {
    cout << "Testing reverse two elements... ";
    LinkedList<int> two_list;
    two_list.append(1);
    two_list.append(2);
    
    two_list.reverse();
    
    assert(two_list.get_head()->value == 2);
    assert(two_list.get_tail()->value == 1);
    assert(two_list.get_head()->next->value == 1);
    assert(two_list.get_tail()->next == nullptr);
    assert(two_list.get_size() == 2);
    
    cout << "PASSED ✓" << endl;
}

// Тест 7: Проверка удаления значений (delete_value)
void test_delete_value() {
    cout << "Testing delete_value... ";
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    
    list.delete_value(3);
    
    Node<int>* current = list.get_head();
    assert(current->value == 1);
    current = current->next;
    assert(current->value == 2);
    current = current->next;
    assert(current->value == 4);
    current = current->next;
    assert(current->value == 5);
    assert(current->next == nullptr);
    assert(list.get_size() == 4);
    
    // Удаление первого элемента
    list.delete_value(1);
    assert(list.get_head()->value == 2);
    assert(list.get_size() == 3);
    
    // Удаление последнего элемента
    list.delete_value(5);
    assert(list.get_tail()->value == 4);
    assert(list.get_size() == 2);
    
    cout << "PASSED ✓" << endl;
}

// Тест 8: Удаление значения, которого нет
void test_delete_non_existent() {
    cout << "Testing delete non-existent... ";
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    
    list.delete_value(999);
    
    Node<int>* current = list.get_head();
    assert(current->value == 1);
    current = current->next;
    assert(current->value == 2);
    current = current->next;
    assert(current->value == 3);
    assert(current->next == nullptr);
    assert(list.get_size() == 3);
    
    cout << "PASSED ✓" << endl;
}

// Тест 9: Удаление всех одинаковых значений
void test_delete_all_duplicates() {
    cout << "Testing delete all duplicates... ";
    LinkedList<int> list;
    list.append(2);
    list.append(2);
    list.append(2);
    list.append(3);
    list.append(2);
    list.append(4);
    
    list.delete_value(2);
    
    Node<int>* current = list.get_head();
    assert(current->value == 3);
    current = current->next;
    assert(current->value == 4);
    assert(current->next == nullptr);
    assert(list.get_tail()->value == 4);
    assert(list.get_size() == 2);
    
    cout << "PASSED ✓" << endl;
}

// Тест 10: Проверка удаления последнего элемента (delete_last)
void test_delete_last() {
    cout << "Testing delete_last... ";
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    
    list.delete_last();
    Node<int>* current = list.get_head();
    assert(current->value == 1);
    current = current->next;
    assert(current->value == 2);
    current = current->next;
    assert(current->value == 3);
    current = current->next;
    assert(current->value == 4);
    assert(current->next == nullptr);
    assert(list.get_tail()->value == 4);
    assert(list.get_size() == 4);
    
    // Удаляем все элементы
    list.delete_last();
    list.delete_last();
    list.delete_last();
    list.delete_last();
    
    assert(list.get_head() == nullptr);
    assert(list.get_tail() == nullptr);
    assert(list.get_size() == 0);
    
    // Удаление из пустого списка
    list.delete_last();
    assert(list.get_head() == nullptr);
    assert(list.get_size() == 0);
    
    cout << "PASSED ✓" << endl;
}

// Тест 11: Проверка редактирования по индексу (edit_by_index)
void test_edit_by_index() {
    cout << "Testing edit_by_index... ";
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    
    list.edit_by_index(99, 2);
    
    Node<int>* current = list.get_head();
    assert(current->value == 1);
    current = current->next;
    assert(current->value == 2);
    current = current->next;
    assert(current->value == 99);
    current = current->next;
    assert(current->value == 4);
    current = current->next;
    assert(current->value == 5);
    assert(list.get_size() == 5);
    
    // Редактирование первого элемента
    list.edit_by_index(100, 0);
    assert(list.get_head()->value == 100);
    
    // Редактирование последнего элемента
    list.edit_by_index(200, 4);
    assert(list.get_tail()->value == 200);
    
    cout << "PASSED ✓" << endl;
}

// Тест 12: Редактирование по несуществующему индексу
void test_edit_by_invalid_index() {
    cout << "Testing edit_by_invalid_index... ";
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    
    cout << "\n  Attempting to edit invalid index (should show error): ";
    list.edit_by_index(99, 100);
    
    // Список не должен измениться
    Node<int>* current = list.get_head();
    assert(current->value == 1);
    current = current->next;
    assert(current->value == 2);
    current = current->next;
    assert(current->value == 3);
    assert(current->next == nullptr);
    assert(list.get_size() == 3);
    
    // Редактирование в пустом списке
    LinkedList<int> empty_list;
    cout << "  Attempting to edit empty list (should show error): ";
    empty_list.edit_by_index(99, 0);
    assert(empty_list.get_head() == nullptr);
    assert(empty_list.get_size() == 0);
    
    cout << "PASSED ✓" << endl;
}

// Тест 13: Конструктор копирования
void test_copy_constructor() {
    cout << "Testing copy constructor... ";
    LinkedList<int> original;
    original.append(1);
    original.append(2);
    original.append(3);
    
    LinkedList<int> copy(original);
    
    Node<int>* orig = original.get_head();
    Node<int>* cop = copy.get_head();
    
    while (orig != nullptr && cop != nullptr) {
        assert(orig->value == cop->value);
        assert(orig != cop);
        orig = orig->next;
        cop = cop->next;
    }
    assert(orig == nullptr);
    assert(cop == nullptr);
    assert(copy.get_size() == original.get_size());
    
    // Проверяем независимость
    copy.edit_by_index(999, 0);
    assert(original.get_head()->value == 1);
    assert(copy.get_head()->value == 999);
    assert(original.get_size() == 3);
    assert(copy.get_size() == 3);
    
    cout << "PASSED ✓" << endl;
}

// Тест 14: Оператор присваивания
void test_assignment_operator() {
    cout << "Testing assignment operator... ";
    LinkedList<int> original;
    original.append(100);
    original.append(200);
    original.append(300);
    
    LinkedList<int> copy;
    copy = original;
    
    Node<int>* orig = original.get_head();
    Node<int>* cop = copy.get_head();
    
    while (orig != nullptr && cop != nullptr) {
        assert(orig->value == cop->value);
        assert(orig != cop);
        orig = orig->next;
        cop = cop->next;
    }
    assert(orig == nullptr);
    assert(cop == nullptr);
    assert(copy.get_size() == original.get_size());
    
    // Проверяем независимость
    copy.edit_by_index(999, 0);
    assert(original.get_head()->value == 100);
    assert(copy.get_head()->value == 999);
    
    cout << "PASSED ✓" << endl;
}

// Тест 15: Присваивание самому себе
void test_assignment_to_self() {
    cout << "Testing assignment to self... ";
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    
    list = list;
    
    Node<int>* current = list.get_head();
    assert(current->value == 1);
    current = current->next;
    assert(current->value == 2);
    current = current->next;
    assert(current->value == 3);
    assert(current->next == nullptr);
    assert(list.get_size() == 3);
    
    cout << "PASSED ✓" << endl;
}

// Тест 16: Сложный сценарий с copy и reverse
void test_copy_and_reverse() {
    cout << "Testing copy and reverse... ";
    LinkedList<int> original;
    original.append(1);
    original.append(2);
    original.append(3);
    original.append(4);
    original.append(5);
    
    LinkedList<int> copy = original;
    copy.reverse();
    
    Node<int>* orig = original.get_head();
    assert(orig->value == 1);
    orig = orig->next;
    assert(orig->value == 2);
    orig = orig->next;
    assert(orig->value == 3);
    assert(original.get_size() == 5);
    
    Node<int>* cop = copy.get_head();
    assert(cop->value == 5);
    cop = cop->next;
    assert(cop->value == 4);
    cop = cop->next;
    assert(cop->value == 3);
    assert(copy.get_size() == 5);
    
    cout << "PASSED ✓" << endl;
}

// Тест 17: Проверка размера после операций
void test_size_after_operations() {
    cout << "Testing size after operations... ";
    LinkedList<int> list;
    
    assert(list.get_size() == 0);
    
    list.append(1);
    assert(list.get_size() == 1);
    
    list.append(2);
    assert(list.get_size() == 2);
    
    list.delete_last();
    assert(list.get_size() == 1);
    
    list.clear();
    assert(list.get_size() == 0);
    
    cout << "PASSED ✓" << endl;
}

// Тест 18: Проверка работы с разными типами
void test_different_types() {
    cout << "Testing different types... ";
    
    // Список строк
    LinkedList<std::string> string_list;
    string_list.append("Hello");
    string_list.append("World");
    string_list.append("!");
    assert(string_list.get_size() == 3);
    assert(string_list.get_head()->value == "Hello");
    assert(string_list.get_tail()->value == "!");
    
    string_list.delete_value("World");
    assert(string_list.get_size() == 2);
    assert(string_list.get_head()->value == "Hello");
    assert(string_list.get_tail()->value == "!");
    
    // Список double
    LinkedList<double> double_list;
    double_list.append(3.14);
    double_list.append(2.718);
    double_list.append(1.618);
    assert(double_list.get_size() == 3);
    assert(double_list.get_head()->value == 3.14);
    assert(double_list.get_tail()->value == 1.618);
    
    double_list.edit_by_index(9.99, 1);
    assert(double_list.get_head()->next->value == 9.99);
    
    cout << "PASSED ✓" << endl;
}

// ==================== ТОЧКА ВХОДА ====================

int main() {
    cout << "========================================" << endl;
    cout << "     LINKED LIST TESTS" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    test_constructor();
    test_append();
    test_clear();
    test_print();
    test_reverse();
    test_reverse_two_elements();
    test_delete_value();
    test_delete_non_existent();
    test_delete_all_duplicates();
    test_delete_last();
    test_edit_by_index();
    test_edit_by_invalid_index();
    test_copy_constructor();
    test_assignment_operator();
    test_assignment_to_self();
    test_copy_and_reverse();
    test_size_after_operations();
    test_different_types();
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "   ALL TESTS PASSED! ✓" << endl;
    cout << "========================================" << endl;
    
    return 0;
}