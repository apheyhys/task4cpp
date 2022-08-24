#include "Readfile.h"
#include <iostream>
#include <fstream>

using namespace std;

char *readfile(const char *filename, int size) {
    // Открываем файл
    ifstream readfile(filename, ios::in);
    // Читаем все символы, включая пробелы
    readfile >> std::noskipws;

    if (!readfile) {
        cout << "Ошибка открытия файла" << endl;
        return reinterpret_cast<char *>(1);
    } else {
        char *arr = new char[size];

        for (int n = 0; n < size; ++n) {
            readfile >> arr[n];
        }
        readfile.close();
        return arr;
    }
}