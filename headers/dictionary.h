//
// Created by erick on 23.11.2022.
//

#ifndef TEST_DICTIONARY_H
#define TEST_DICTIONARY_H
#include "string"
#include "vector"
#include <fstream>
#include <iostream>
#include "couple.h"


using namespace std;

class dictionary {
private:
    vector<Couple> storage;
    string filename;
public:
    const string &get_filename() const;
    void set_filename(const string &filename);

    // Конструктор
    dictionary(const string& filename);
    dictionary();
    // Деструктор
    ~dictionary();

    // Добавление новой записи в словарь
    void add_new_couple(string key, string value);
    // Добавление новой записи в файл
    void add_new_couple_to_file(const string& key, const string& value) const;
    void add_new_couple_to_file(const Couple& couple) const;

    // Удаление записей из словаря
    void delete_couples(string key);
    // Удаление записи из словаря
    void delete_couple(string key);
    // Удаление всех записей
    void delete_all_couples();
    // Удаление всех записей из файла
    void delete_all_couples_from_file();

    // Поиск всех значений по ключу
    vector<Couple> search_couples(string key);
    // Поиск первого значения по ключу
    Couple search_couple(string key);

    // Изменение всех значений элементов по ключу
    void change_couples(const string& key, const string& new_value);
    // Изменение значения первого элемента по ключу
    void change_couple(const string& key, const string& new_value);

    void print_all();

    // Перегруженные операторы
    Couple operator[](string key);
};



#endif //TEST_DICTIONARY_H
