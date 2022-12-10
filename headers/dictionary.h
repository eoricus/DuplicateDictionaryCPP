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

    // ���������
    dictionary(const string& filename);
    dictionary();
    // ��������
    ~dictionary();

    // ���������� ����� ����� � ᫮����
    void add_new_couple(string key, string value);
    // ���������� ����� ����� � 䠩�
    void add_new_couple_to_file(const string& key, const string& value) const;
    void add_new_couple_to_file(const Couple& couple) const;

    // �������� ����ᥩ �� ᫮����
    void delete_couples(string key);
    // �������� ����� �� ᫮����
    void delete_couple(string key);
    // �������� ��� ����ᥩ
    void delete_all_couples();
    // �������� ��� ����ᥩ �� 䠩��
    void delete_all_couples_from_file();

    // ���� ��� ���祭�� �� �����
    vector<Couple> search_couples(string key);
    // ���� ��ࢮ�� ���祭�� �� �����
    Couple search_couple(string key);

    // ��������� ��� ���祭�� ����⮢ �� �����
    void change_couples(const string& key, const string& new_value);
    // ��������� ���祭�� ��ࢮ�� ����� �� �����
    void change_couple(const string& key, const string& new_value);

    void print_all();

    // ��ॣ�㦥��� �������
    Couple operator[](string key);
};



#endif //TEST_DICTIONARY_H
