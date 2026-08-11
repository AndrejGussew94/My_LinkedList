#include <iostream>
#include <cassert>
#include <string>
#include "LinkedList.h"

using namespace std;

// Тест 1: Создание пустого списка
void test_constructor() {
    cout << "Testing constructor... ";
    LinkedList<int> list;
    assert(list.get_size() == 0);
    assert(list.get_head() == nullptr);
    assert(list.get_tail() == nullptr);
    cout << "PASSED ✓" << endl;
}

// Тест 2: Добавление элементов (append)
void test_append() {
    cout << "Testing append... ";
    LinkedList<int> list;
    list.append(10);
    assert(list.get_size() == 1);
    assert(list.get_head()->value == 10);
    assert(list.get_tail()->value == 10);
    
    list.append(20);
    assert(list.get_size() == 2);
    assert(list.get_head()->value == 10);
    assert(list.get_tail()->value == 20);
    assert(list.get_head()->next->value == 20);
    assert(list.get_tail()->prev->value == 10);
    
    list.append(30);
    assert(list.get_size() == 3);
    assert(list.get_tail()->value == 30);
    assert(list.get_tail()->prev->value == 20);
    
    cout << "PASSED ✓" << endl;
}

// Тест 3: Удаление последнего элемента (delete_last)
void test_delete_last() {
    cout << "Testing delete_last... ";
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    
    list.delete_last();
    assert(list.get_size() == 2);
    assert(list.get_tail()->value == 2);
    assert(list.get_tail()->next == nullptr);
    
    list.delete_last();
    assert(list.get_size() == 1);
    assert(list.get_tail()->value == 1);
    assert(list.get_head()->value == 1);
    assert(list.get_head()->next == nullptr);
    assert(list.get_head()->prev == nullptr);
    
    list.delete_last();
    assert(list.get_size() == 0);
    assert(list.get_head() == nullptr);
    assert(list.get_tail() == nullptr);
    
    // Попытка удалить из пустого списка
    list.delete_last(); // Должно вывести "List is empty!"
    assert(list.get_size() == 0);
    
    cout << "PASSED ✓" << endl;
}

// Тест 4: Очистка списка (clear)
void test_clear() {
    cout << "Testing clear... ";
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    assert(list.get_size() == 4);
    
    list.clear();
    assert(list.get_size() == 0);
    assert(list.get_head() == nullptr);
    assert(list.get_tail() == nullptr);
    
    // Очистка пустого списка
    list.clear();
    assert(list.get_size() == 0);
    
    cout << "PASSED ✓" << endl;
}

// Тест 5: Реверс списка (reverse)
void test_reverse() {
    cout << "Testing reverse... ";
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    
    list.reverse();
    assert(list.get_size() == 5);
    assert(list.get_head()->value == 5);
    assert(list.get_tail()->value == 1);
    assert(list.get_head()->next->value == 4);
    assert(list.get_tail()->prev->value == 2);
    
    // Реверс списка с одним элементом
    LinkedList<int> single;
    single.append(42);
    single.reverse();
    assert(single.get_size() == 1);
    assert(single.get_head()->value == 42);
    assert(single.get_tail()->value == 42);
    
    // Реверс пустого списка
    LinkedList<int> empty;
    empty.reverse();
    assert(empty.get_size() == 0);
    
    cout << "PASSED ✓" << endl;
}

// Тест 6: Копирующий конструктор
void test_copy_constructor() {
    cout << "Testing copy constructor... ";
    LinkedList<int> original;
    original.append(1);
    original.append(2);
    original.append(3);
    
    LinkedList<int> copy(original);
    assert(copy.get_size() == original.get_size());
    assert(copy.get_head()->value == original.get_head()->value);
    assert(copy.get_tail()->value == original.get_tail()->value);
    
    // Проверяем, что копия независима
    copy.append(4);
    assert(copy.get_size() == 4);
    assert(original.get_size() == 3);
    
    cout << "PASSED ✓" << endl;
}

// Тест 7: Оператор присваивания
void test_assignment_operator() {
    cout << "Testing assignment operator... ";
    LinkedList<int> original;
    original.append(1);
    original.append(2);
    original.append(3);
    
    LinkedList<int> copy;
    copy = original;
    assert(copy.get_size() == original.get_size());
    assert(copy.get_head()->value == original.get_head()->value);
    assert(copy.get_tail()->value == original.get_tail()->value);
    
    // Проверяем, что копия независима
    copy.append(4);
    assert(copy.get_size() == 4);
    assert(original.get_size() == 3);
    
    // Присваивание самому себе
    copy = copy;
    assert(copy.get_size() == 4);
    
    cout << "PASSED ✓" << endl;
}

// Тест 8: Работа с разными типами данных
void test_different_types() {
    cout << "Testing different types... ";
    
    // Список строк
    LinkedList<std::string> strings;
    strings.append("Hello");
    strings.append("World");
    strings.append("!");
    assert(strings.get_size() == 3);
    assert(strings.get_head()->value == "Hello");
    assert(strings.get_tail()->value == "!");
    
    // Список double
    LinkedList<double> doubles;
    doubles.append(3.14);
    doubles.append(2.718);
    doubles.append(1.618);
    assert(doubles.get_size() == 3);
    assert(doubles.get_head()->value == 3.14);
    assert(doubles.get_tail()->value == 1.618);
    
    cout << "PASSED ✓" << endl;
}

// Тест 9: Сложный сценарий
void test_complex_scenario() {
    cout << "Testing complex scenario... ";
    LinkedList<int> list;
    
    // Добавляем элементы
    for (int i = 1; i <= 10; i++) {
        list.append(i);
    }
    assert(list.get_size() == 10);
    assert(list.get_head()->value == 1);
    assert(list.get_tail()->value == 10);
    
    // Реверсируем
    list.reverse();
    assert(list.get_head()->value == 10);
    assert(list.get_tail()->value == 1);
    
    // Удаляем последний
    list.delete_last();
    assert(list.get_size() == 9);
    assert(list.get_tail()->value == 2);
    
    // Реверсируем обратно
    list.reverse();
    assert(list.get_size() == 9);
    assert(list.get_head()->value == 2);
    assert(list.get_tail()->value == 10);
    
    cout << "PASSED ✓" << endl;
}

// Тест 10: Проверка связей (prev/next)
void test_links() {
    cout << "Testing links... ";
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    
    Node<int>* head = list.get_head();
    assert(head->value == 1);
    assert(head->next->value == 2);
    assert(head->next->prev->value == 1);
    assert(head->next->next->value == 3);
    assert(head->next->next->prev->value == 2);
    assert(head->next->next->next == nullptr);
    
    cout << "PASSED ✓" << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "   LINKED LIST TESTS" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    test_constructor();
    test_append();
    test_delete_last();
    test_clear();
    test_reverse();
    test_copy_constructor();
    test_assignment_operator();
    test_different_types();
    test_complex_scenario();
    test_links();
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "   ALL TESTS PASSED! ✓" << endl;
    cout << "========================================" << endl;
    
    return 0;
}