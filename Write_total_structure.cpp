#include <fstream>
#include "List_Str.h"

using namespace std;

void write_total_structure(List *p_begin, const char *filename) {
    ofstream writefile(filename, ios_base::trunc);

    while (p_begin != nullptr) {
        writefile << p_begin->value; // Записываем value посимвольно
        p_begin = p_begin->next;
    }

    writefile.close();
}


