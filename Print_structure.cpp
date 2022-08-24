#include "List_Str.h"
#include <iostream>
#include "Print_structure.h"

using namespace std;

void print_structure(List *p_begin) {
    // Печатаем до последнего символа
    while (p_begin != nullptr) {
        cout << p_begin->value;
        p_begin = p_begin->next;
    }
}


