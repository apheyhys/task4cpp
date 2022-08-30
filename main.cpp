#include <iostream>

#include "List_Str.h" // Структура
#include "Array_size.h" // Количество символов в файле
#include "Readfile.h" // Прочитать файл
#include "Create_struct.h" // Создать структуру
#include "Search_element.h" // Найти порядковый номер элемента, после которого необходимо произвести вставку
#include "Add_new_symbol.h" // Создать итоговую структуру
#include "Print_structure.h" // Распечатать структуру на экран
#include "Write_total_structure.h" // Запись в файл

using namespace std;

#define MAIN_LIST "/home/ubuntu/CLionProjects/task3cppStr/main_list.txt" // адрес основного текста
#define ADDITIONAL_ELEMENT "/home/ubuntu/CLionProjects/task3cppStr/additional_symbol.txt" // адрес дополнительного символа
#define SEARCHED_ELEMENT "/home/ubuntu/CLionProjects/task3cppStr/searched_symbol.txt" // адрес символа, после которого нужно вставить дополнительный символ
#define TOTAL_LIST "/home/ubuntu/CLionProjects/task3cppStr/total_list.txt" // адрес итогового текста


int main() {
    // Получаем количество символов в основном файле
    int main_list_length = array_size(MAIN_LIST);


    // Читаем файлы и получаем указатель на массив символов
    char *main_list = readfile(MAIN_LIST, main_list_length);
    char *additional_symbol = readfile(ADDITIONAL_ELEMENT, 1); // Читаем только первый символ из файла
    char *searched_symbol = readfile(SEARCHED_ELEMENT, 1); // Читаем только первый символ из файла


    // Создаем структуру из массива
    List *main_struct = create_struct(main_list, main_list_length);

    cout << "---------------------" << endl;

    cout << "Основной текст: \n" << "--------------------"
                                    "-\n";
    print_structure(main_struct); // Печатаем основной файл
    cout << "\n" << endl;
    cout << "---------------------" << endl;
    cout << "Символ, который нужно вставить: " << "\n---------------------\n";
    cout << additional_symbol << endl; // Печатаем дополнительный символ
    cout << "---------------------" << endl;
    cout << "Cимвол, после которого нужно вставить новый элемент: " << "\n---------------------\n";
    cout << searched_symbol << endl; // Печатаем дополнительный символ

    // Ищем порядковый номер в основной структуре, после которого нужно будет вставить дополнительный символ
    int element_number = search_element(main_struct, searched_symbol);
    if (element_number == -1) { // Завершаем программу, если не нашли элемент
        return -1;
    }

    // Формируем итоговый список
    add_new_element(main_struct, *additional_symbol, element_number);

    cout << "---------------------" << endl;
    // Вставляем новый элемент в имеющийся список
    cout << "Итоговый список: " << endl;
    cout << "---------------------" << endl;

    // Распечатываем итоговую структуру
    print_structure(main_struct);

    // Записываем итоговую структуру в файл
    write_total_structure(main_struct, TOTAL_LIST);

    // Освобождаем память, удаляя созданную структуру
    delete main_struct;

    return 0;
}





