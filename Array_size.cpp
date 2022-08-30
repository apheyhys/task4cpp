#include <fstream>
#include <iostream>
#include "Array_size.h"

using namespace std;

int array_size(const char *filename) {
    ifstream readfile(filename, ios::in);

    // Читаем все символы, включая пробелы
    readfile >> std::noskipws;

    if (!readfile) {
        cout << "Ошибка открытия файла" << endl;
    } else {
        int count = 0;
        char ch;
        while (!readfile.eof()) {
            readfile >> ch;
            count++;
        }
        return count;
    }
    return 0;
}