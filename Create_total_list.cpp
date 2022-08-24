
#include <cstdlib>
#include "List_Str.h"
#include "Create_total_list.h"

List *create_total_list(List *p_begin, List *p_additional, int search_symbol, int main_size, int additional_size) {

    List *t_begin = nullptr;
    List *t = nullptr;

    t_begin = (List *) malloc(sizeof(List)); // Выделяем память под первую ячейку структуры
    t = t_begin;
    t->next = nullptr;
    t->count = 0;

    List *p = p_begin;
    List *a = p_additional;

    // Заполняем новую структуру данными
    for (int k = 1; k < (main_size + additional_size) - 1; k++) {
        t->count = k - 1;
        t->next = (List *) malloc(sizeof(List));  // Выделяем память под каждую новую ячейку структуры
        if (k > search_symbol + 1 && k < search_symbol + additional_size + 1) { // вставляем дополнительный список если
            t->value = a->value;                                                // номер итерации соответствует искомому
            a = a->next;                                                        // символу
        } else {
            t->value = p->value; // иначе перепечатываем основной список
            p = p->next;
        }
        // Переходим к следующей ячейке
        t = t->next;

        t->next = nullptr;
    }

    return t_begin;
}
