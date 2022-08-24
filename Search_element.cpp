#include <iostream>
#include "List_Str.h"
#include "Search_element.h"
using namespace std;

int search_element(List *p_begin, const char *find_symbol) {
    List *p = p_begin;

    // Переменная для проверки наличия символа в массиве
    bool symbol_missing = false;


    while (p != nullptr) {
        if (p->value == find_symbol[0]) { // Ищем нужный символ и возвращаем порядковый номер
            symbol_missing = true;
            break;
        }
        p = p->next;
    }
    if (symbol_missing) {
        return p->count;
    } else {
        cout << "Элемент не найден! Программа будет завершена." << endl; // Завершаем программу,
        return -1;                                                       // если искомого символа нет в основном списке
    }
}
