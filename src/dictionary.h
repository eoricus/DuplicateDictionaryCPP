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
    // ���������
    dictionary(string filename);
    // ��������, �����⢫�� ������ ���ᨢ� � 䠩�
    ~dictionary();

    // ��饭�� ᫮���� � ������ ����� ���祭��
    void create_new_dict();

    // ������ ������ ���祭�� � ᫮����
    void add_entry(string key, string value);
    // ������ ������ ���祭�� � 䠩�
    void add_entry_to_file(string key, string value);
    void add_entry_to_file(Couple couple);

    // �������� ��ࢮ� �����
    void delete_entry(string key);
    // �������� ��� ����ᥩ
    void delete_entries(string key);
    // �������� ��� ����ᥩ �� 䠩��
    void delete_entries_from_file();

    // ���� ����� �� �����
    Couple search_entry(string key);
    // ���� ��� ����⮢
    vector<Couple> search_entries(string key);

    // ��������� ���祭�� ����� �� �����
    void change_entry(string key, string new_value);

    // �뢮� ��� ����⮢ ᫮����
    void print_all();

    // �⥭�� ���祭�� �� 䠩��
    void read_from_file();

    // �࠭����
    vector<Couple> storage;

    // TODO ��ॣ�㦥��� �������
    Couple operator[](string key);
};



#endif //TEST_DICTIONARY_H
