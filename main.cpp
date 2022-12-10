#include <iostream>
#include "./headers/dictionary.h"
#include <algorithm>

using namespace std;

bool is_correct_file(const string& filename) {
    ifstream file; string stroke;
    file.open(filename);

    while (getline(file, stroke)) {
        if (count(stroke.begin(), stroke.end(), ' ') != 0 || stroke.empty()) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "������ ��������樮���� �ணࠬ�� ॠ����� "
            "ࠡ��� ᫮���� � �㡫���⠬�. ������� �ணࠬ��: \n"
            "[1]   �������� ������ ᫮���� (����᪠���� �� 㬮�砭��)\n"
            "[2]   ���������� ����� � ᫮���� \n"
            "[3]   �᪫�祭�� ����⮢ � ������� ���箬 �� ᫮���� \n"
            "[4]   �᪫�祭�� ��ࢮ�� ����� � ������� ���箬 �� ᫮���� \n"
            "[5]   ���� ��� ���祭�� �� ����� \n"
            "[6]   ���� ��ࢮ�� ���祭�� �� ����� \n"
            "[7]   ��������� ��� ���祭�� ����� �� �����\n"
            "[8]   ��������� ��ࢮ�� ���祭�� ����� �� �����\n"
            "[9]   �뢮� ᫮����"
            "[a/A] �������� ᫮����"
            "[0]   ��⠭����/�����襭�� �ணࠬ�� \n"
            "��� ��砫� ࠡ��� �ணࠬ�� � ⥪�⮢� 䠩��� -- 㪠��� ���� �� 䠩��, ��㤠 �㦭� ���㧨�� ����� (��� '-', �᫨ �ணࠬ�� �㤥� �࠭��� ����� ⮫쪮 � ����� �ணࠬ��):"
         << endl;

    do {
        bool dict_can_be_created = false; // ��� ��� �஢�ન, ��砫� �ணࠬ�� ᢮� ࠡ���, ��� ���
        dictionary *dict;

        string filename;
        cin >> filename;

        if (filename == "-") {
            // �᫨ ����� ���� �࠭����� ⮫쪮 � ����� �ணࠬ��
            dict_can_be_created = true;
            dict = new dictionary();
            cout << "������ ���⮩ ᫮����.\n"
                    "����� �࠭���� ⮫쪮 � ����� �ணࠬ�� � ���� ��襭� ��᫥ �����襭��.\n"
                    "(�� ����� ��࠭��� ����� � 室� ࠡ��� �ணࠬ��, ��ᯮ�짮������ �������� \"s\")" << endl;
        } else {
            // �᫨ ����� ���� �࠭����� � 䠩��

            ifstream file(filename);
            if (!file.is_open()) {
                cout << "���� �� ����� ���� ���⠭.\n"
                        "������ ���� �� 䠩�� �� ࠧ, ��� ������ \"-\" �᫨ ��� �࠭��� ᫮���� ⮫쪮 � ����� �ணࠬ��:" << endl;
            } else if (!is_correct_file(filename)) {
                cout << "���� �����४⥭. ��室�� ���㬥�� �� ������ ᮤ�ঠ�� ������ ��ப!\n"
                        "������ ���� �� 䠩�� �� ࠧ, ��� ������ \"-\" �᫨ ��� �࠭��� ᫮���� ⮫쪮 � ����� �ணࠬ��:" << endl;
            } else {
                // ���४�� 䠩�
                dict_can_be_created = true;
                dict = new dictionary(filename);
                cout << "������� ����� � 䠩��: " << filename << endl;
                cout << "�� ������� �� ����� �����࠭��� 䠩�, ��ᯮ�짮������ �������� \"s\"" << endl;
            }
            file.close();
        }

        while (dict_can_be_created) {
            char command; cin >> command;

            switch (command) {
                case '1': { // �������� ������ ᫮����
                    cout << "�������� ������ ᫮���� �।�������� ��१���� �ணࠬ��, � ��砫� ࠡ��� � ���� ᫮����. �த������? (y/n)\n";
                    char answer; cin >> answer;

                    if (answer == 'y') {
                        dict_can_be_created = false;
                        delete dict;
                    }
                    break;
                }
                case '2': { // ���������� ����� � ᫮����
                    cout << "������ ���� � ���祭�� �����, ����� ����室��� �������� � ᫮����: " << endl;
                    string key, value; cin >> key >> value;

                    dict->add_new_couple(key, value);
                    cout << "���祭�� ��������� � ᫮����!" << endl;
                    break;
                }
                case '3': { // �᪫�祭�� ����⮢ � ������� ���箬 �� ᫮����
                    cout << "������ ���� �����, ���祭�� ������ ����室��� 㤠����: " << endl;
                    string key; cin >> key;

                    dict->delete_couples(key);
                    cout << "���祭�� 㤠���� �� ᫮����!" << endl;
                    break;
                }
                case '4': { // �᪫�祭�� ��ࢮ�� ����� � ������� ���箬 �� ᫮����
                    cout << "������ ���� �����, ���祭�� ������ ����室��� 㤠����:" << endl;
                    string key; cin >> key;

                    dict->delete_couples(key);
                    cout << "���祭�� 㤠���� �� ᫮����!" << endl;
                    break;
                }
                case '5': { // ���� ��� ���祭�� �� �����
                    cout << "������ ���� ����⮢, ����� ����室��� ����: " << endl;
                    string key; cin >> key;

                    vector<Couple> couples = dict->search_couples(key);
                    for (const Couple& couple: couples) {
                        cout << couple.key << endl << couple.value << endl;
                    }
                    break;
                }
                case '6': { // ���� ��ࢮ�� ���祭�� �� �����
                    cout << "������ ���� ����⮢, ����� ����室��� ����: " << endl;
                    string key; cin >> key;

                    Couple couple = dict->search_couple(key);
                    cout << couple.key << endl << couple.value << endl;
                    break;
                }
                case '7': { // ��������� ��� ���祭�� ����� �� �����
                    cout << "������ ���� ����⮢, ����� ����室��� ��������, � ⠪�� ����� ���祭��: " << endl;
                    string key, value; cin >> key >> value;

                    dict->change_couples(key, value);
                    cout << "���祭�� ��������!" << endl;
                    break;
                }
                case '8': { // ��������� ��ࢮ�� ���祭�� ����� �� �����
                    cout << "������ ���� �����, ����� ����室��� ��������, � ⠪�� ����� ���祭��: " << endl;
                    string key, value; cin >> key >> value;

                    dict->change_couple(key, value);
                    cout << "���祭�� ��������!" << endl;
                    break;
                }
                case '9': { // �뢮� ᫮����
                    dict->print_all();
                    break;
                }
                case 'a': case 'A': { // �������� ᫮����
                    cout << "������� �।�������� 㤠����� ��� ���祭�� ᫮����. �த������? (y/n)" << endl;
                    char answer; cin >> answer;

                    if (answer == 'y') {
                        dict->delete_all_couples();
                        cout << "������� 㤠��!" << endl;
                    }
                    break;
                }
                case 's': case 'S': { // ���࠭���� ᫮����
                    cout << "������ ����, �� ���஬� �㤥� ��࠭�� ᫮����" << endl;
                    string path; cin >> path;

                    ifstream file(path);
                    if (file.is_open()) {
                        dict->set_filename(path);
                        cout << "���� ��࠭��! ��᫥ ������� �ணࠬ�� ᫮���� �㤥� ����ᠭ � 䠩� �� 㪠������� ���!" << endl;
                    } else {
                        cout << "�������� ���� �����४��, ��१������ ������� (������ c) � ���஡�� ��㣮�" << endl;
                    }

                    break;
                }
                case '0': { // �����襭�� �ணࠬ��
                    delete dict;
                    return 0;
                }
                default: {
                    cout << "\"" << command << "\"" << " - ������� �� �������." << endl;
                    break;
                }
            }
        }
    } while (true);
}