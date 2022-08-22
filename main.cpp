#include <iostream>
using namespace std;
#include "array_size.h"


char *readfile(const char *filename, int size);

#define MAIN_LIST "/home/ubuntu/CLionProjects/task4cpp/main_list.txt" // адрес основного текста
#define ADDITIONAL_LIST "/home/ubuntu/CLionProjects/task4cpp/additional_list.txt" // адрес дополнительного текста
#define TOTAL_LIST "/home/ubuntu/CLionProjects/task4cpp/total_list.txt" // адрес итогового текста

struct List {
    char value;
    int count;
    struct List *next;
};

List* create_list(const char *N, int size);

List* create_total_list(List *p_begin, List *p_additional, int search_symbol);

int search_element(List *p_begin, const char *find_symbol);

int main() {
//    List L1{};
//    L1.size = 5;
//    cout << L1.size << endl;
    int main_list_length = array_size(MAIN_LIST);
    int additional_list_length = array_size(ADDITIONAL_LIST);
    cout << "main_list_length: " << main_list_length << endl;
    cout << "additional_list_length: " << additional_list_length << endl;
    cout << "---------------------" << endl;
    char * main_list = readfile(MAIN_LIST, main_list_length);
    char * additional_list = readfile(ADDITIONAL_LIST, additional_list_length);
    cout << "Основной текст: \n" << "---------------------\n" << main_list  << "\n"  << endl;
    cout << "---------------------" << endl;
    cout << "Дополнительный текст: " << "\n---------------------\n" << additional_list << endl;
    List *main_struct = create_list(main_list, main_list_length);

    List *additional_struct = create_list(additional_list, additional_list_length);

    char searched_symbol;
    cout << "-----------------------------" << endl;
    cout << "Введите символ, после которого нужно вставить новый список:" << endl;
    cin >> searched_symbol;

    int element_number = search_element(main_struct, &searched_symbol);

    cout << element_number << endl;

    List *total_list = create_total_list(main_struct, additional_struct, element_number);


//    cout << main_struct->value << endl;
//    while (main_struct != NULL) {
//        fprintf(f, "%c", p->value);
//        main_struct = main_struct->next;
//        cout << sizeof(main_struct->count) << "\t";
//    }

    return 0;
}

List* create_total_list(List *p_begin, List *p_additional, int search_symbol) {
//    cout << p_begin << " | " << sizeof(*p_additional) << " | " << search_symbol << endl;
}


int search_element(List *p_begin, const char *find_symbol) {
    List *p = p_begin;

    // Переменная для проверки наличия символа в массиве
    bool symbol_missing = false;


    while (p != nullptr) {
        if (p->value==find_symbol[0]) { // Ищем нужный символ, а затем сразу завершаем цикл и возвращаем порядковый номер
            symbol_missing = true;
            break;
        }
        p = p->next;
    }
    if (symbol_missing) {
        return p->count;
    } else {
        cout << "Элемент не найден! Программа будет завершена." << endl;
        return -1;
    }
}



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
        return arr;
    }
}

List* create_list(const char *N, int size) {
    List *p_begin = nullptr;
    List *p = nullptr;
    // Выделяем память
    p_begin = (List *)malloc(size);
    p = p_begin;
    p->next = nullptr;
    p->count = 0;

//    cout << "Структура: " << endl;


    for(int k = 1; k < size; k++) {
        p->count = k-1;
        p->value = N[k-1];
        p->next = (List *)malloc(size);
        // Следующий элемент
        p = p->next;
//        cout << k << endl;
//        cout << N[k-1]; // Сразу печатаем символы, чтобы не создавать отдельную функцию для печати
        // Заполняем новую структуру данными
        p->next = nullptr;
    }
    return p_begin;
}