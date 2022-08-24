#include <iostream>

#include "List_Str.h" // Структура
#include "Array_size.h" // Количество символов в файле
#include "Readfile.h" // Прочитать файл
#include "Create_struct.h" // Создать структуру
#include "Search_element.h" // Найти порядковый номер элемента, после которого необходимо произвести вставку
#include "Create_total_list.h" // Создать итоговую структуру
#include "Print_structure.h" // Распечатать структуру на экран
#include "Write_total_structure.h" // Запись в файл

using namespace std;

#define MAIN_LIST "/home/ubuntu/CLionProjects/task4cpp/main_list.txt" // адрес основного текста
#define ADDITIONAL_LIST "/home/ubuntu/CLionProjects/task4cpp/additional_list.txt" // адрес дополнительного текста
#define TOTAL_LIST "/home/ubuntu/CLionProjects/task4cpp/total_list.txt" // адрес итогового текста


int main() {
    // Получаем количество символов в основном и дополнительном файле
    int main_list_length = array_size(MAIN_LIST);
    int additional_list_length = array_size(ADDITIONAL_LIST);
    cout << "---------------------" << endl;

    // Читаем файлы и получаем указатель на массив символов
    char *main_list = readfile(MAIN_LIST, main_list_length);
    char *additional_list = readfile(ADDITIONAL_LIST, additional_list_length);

    // Создаем структуры из массивов
    List *main_struct = create_struct(main_list, main_list_length);
    List *additional_struct = create_struct(additional_list, additional_list_length);

    cout << "Основной текст: \n" << "---------------------\n";
    print_structure(main_struct); // Печатаем основной файл
    cout << "\n" << endl;
    cout << "---------------------" << endl;
    cout << "Дополнительный текст: " << "\n---------------------\n";
    print_structure(additional_struct); // Печатаем дополнительный файл
    cout << "\n" << endl;

    // Запрашиваем символ, после которого нужно будет вставить дополнительный текст
    char searched_symbol;
    cout << "-----------------------------" << endl;
    cout << "Введите символ, после которого нужно вставить новый список:" << endl;
    cin >> searched_symbol;

    // Ищем порядковый номер в основной структуре, после которого нужно будет вставить дополнительную структуру
    int element_number = search_element(main_struct, &searched_symbol);
    if (element_number == -1) { // Завершаем программу, если не нашли элемент
        return -1;
    }

    // Формируем итоговый список
    List *total_structure = create_total_list(main_struct, additional_struct, element_number, main_list_length,
                                              additional_list_length);
    // Распечатываем итоговую структуру
    cout << "-----------------------------" << endl;
    cout << "Итоговый текст:" << endl;
    cout << "-----------------------------" << endl;
    print_structure(total_structure);
    cout << "\n-----------------------------" << endl;

    // Записываем итоговую структуру в файл
    write_total_structure(total_structure, TOTAL_LIST);


    // Освобождаем память, удаляя все созданные структуры
    delete main_struct;
    delete additional_struct;
    delete total_structure;

    return 0;
}


