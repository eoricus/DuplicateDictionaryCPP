//
// Created by erick on 23.11.2022.
//

#ifndef TEST_DICTIONARY_H
#define TEST_DICTIONARY_H
#include "couple.cpp"
#include "string"
#include "vector"
#include <fstream>
#include <iostream>


using namespace std;

class dictionary {
public:
    string filename;
    // Конструктор
    dictionary(string filename);
    // Деструктор, осуществляет запись массива в файл
    ~dictionary();

    // Очищение словаря и запись новых значений
    void create_new_dict();

    // Запись нового значения в словарь
    void add_entry(string key, string value);
    // Запись нового значения в файл
    void add_entry_to_file(string key, string value);
    void add_entry_to_file(Couple couple);

    // Удаление первой записи
    void delete_entry(string key);
    // Удаление всех записей
    void delete_entries(string key);
    // Удаление всех записей из файла
    void delete_entries_from_file();

    // Поиск элемента по ключу
    Couple search_entry(string key);
    // Поиск всех элементов
    vector<Couple> search_entries(string key);

    // Изменение значения записи по ключу
    void change_entry(string key, string new_value);

    // Вывод всех элементов словаря
    void print_all();

    // Чтение значений из файла
    void read_from_file();

    // Хранилище
    vector<Couple> storage;

    // TODO Перегруженные операторы
    Couple operator[](string key);
};



#endif //TEST_DICTIONARY_H
