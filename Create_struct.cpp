#include "List_Str.h"
#include <cstdlib>

List *create_struct(const char *N, int size) {
    List *p_begin = nullptr;
    List *p = nullptr;
    // Выделяем память
    p_begin = (List *) malloc(sizeof(List)); // Выделяем память под первую ячейку структуры
    p = p_begin;
    p->next = nullptr;
    p->count = 0;

    // Заполняем новую структуру данными
    for (int k = 1; k < size; k++) {
        p->count = k - 1;
        p->value = N[k - 1];
        if (k < size - 1) {
            p->next = (List *) malloc(sizeof(List)); // Выделяем память под каждую новую ячейку структуры
            // Следующий элемент
            p = p->next;
        }
        p->next = nullptr;
    }
    return p_begin;
}