#include "Add_new_symbol.h"
#include <cstdlib>

void add_new_element(List *p_begin, char additional_symbol, int element_number) {
    unsigned i = 0;

    // Выделяем память под новый элемент
    List *tmp = (List*) malloc(sizeof(List));

    // Присваиваем значения
    tmp->value = additional_symbol;
    tmp->count = element_number+1;

    // Находим нужный элемент. Если вышли за пределы списка, то вставляем в конец
    while (i < element_number && p_begin->next) {
        p_begin = p_begin->next;
        i++;
    }

    // Если это не последний элемент, то next перекидываем на следующий узел
    if (p_begin->next) {
        tmp->next = p_begin->next;
    } else {
        tmp->next = nullptr;
    }
    p_begin->next = tmp;
}

