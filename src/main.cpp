#include <iostream>
#include "dictionary.h"
#include <algorithm>

using namespace std;

bool is_correct_file(const string& filename) {
    ifstream file; string stroke;
    file.open(filename);

    while (getline(file, stroke)) {
        if (count(stroke.begin(), stroke.end(), ' ') != 0 || stroke.empty()) {
            return false;
        };
    };
    return true;
}

int main() {
    cout << "������ ��������樮���� �ணࠬ�� ॠ����� "
            "ࠡ��� ᫮���� � �㡫���⠬�. ������� �ணࠬ��: \n"
            "[new]    �������� ���⮣� ᫮���� \n"
            "[add]    ���������� ����� � ᫮���� \n"
            "[delete] �᪫�祭�� ����⮢ � ������� ���箬 �� ᫮���� \n"
            "[search] ���� ���祭�� �� ����� \n"
            "[search one] ���� ���祭�� �� ����� \n"
            "[change] ��������� ���祭�� ����� ᫮���� \n"
            "[print]  �뢮� ᫮���� � ���浪� �����⠭�� ���祩 \n"
            "��� ��砫� ࠡ��� �ணࠬ�� � ⥪�⮢� 䠩��� -- 㪠��� ���� �� 䠩��, ��� ������ ~ ��� ࠡ��� � ���ᮬ �� 㬮�砭��: "
         << endl;

    string filename;

    do {
        cin >> filename;
        if (filename == "~") filename = R"(C:\Users\erikm\Downloads\test)";

        ifstream file(filename);

        if (!file.is_open()) {
            cout << "���� �� ����� ���� ���⠭, ������ ���� �� 䠩�� �� ࠧ, ��� �� ��ᯮ������ 䠩��� �� 㬮�砭�� (~): " << endl;
        } else if (!is_correct_file(filename)) {
            cout << "���� �����४⥭. ��室�� ���㬥�� �� ������ ᮤ�ঠ�� ������ ��ப! " << endl;
        } else {
            dictionary dict = dictionary(filename); string command;
            dict.read_from_file(); dict.print_all();

            while (true) {
                cin >> command;

                // END
                if (command == "end") {
                    return 0;
                }
                // NEW
                else if (command == "new") {
                    dict.create_new_dict();
                    cout << "���� ᫮���� ᮧ���!" << endl;
                }
                // ADD
                else if (command == "add") {
                    string key, value;
                    cout << "������ ���� � ���祭�� ��� �����: " << endl;
                    cin >> key >> value;

                    dict.add_entry(key, value);

                    cout << "���祭�� ����ᠭ�!" << endl;
                }
                // DELETE
                else if (command == "delete") {
                    cout << "������ ���� �����, ����� �㦭� 㤠����: " << endl;
                    string key;cin >> key;

                    dict.delete_entries(key);
                    cout << "���祭�� � �⨬ ���箬 㤠����!" << endl;
                }
                // DELETE ONE
                else if (command == "deleteOne") {
                    cout << "������ ���� �����, ����� �㦭� 㤠����: " << endl;
                    string key;cin >> key;

                    dict.delete_entry(key);
                    cout << "���祭�� � �⨬ ���箬 㤠����!" << endl;
                }
                // SEARCH
                else if (command == "search") {
                    cout << "������ ���� �����, ����� �㦭� ����: " << endl;
                    string key;cin >> key;

                    vector<Couple> res = dict.search_entries(key);
                    for (const Couple& couple : res) {
                        cout << couple.value << endl;
                    }
                }
                // SEARCH ONE
                else if (command == "searchOne") {
                    cout << "������ ���� �����, ����� �㦭� ����: " << endl;
                    string key;cin >> key;

                    Couple res = dict[key];
                    cout << res.value << endl;
                }
                // CHANGE
                else if (command == "change") {
                    string key, value;
                    cout << "������ ���� � ���祭�� ��� ���������� �����: " << endl;
                    cin >> key >> value;

                    dict.change_entry(key, value);
                    cout << "���祭�� ��१���ᠭ�!" << endl;
                }
                // PRINT
                else if (command == "print") {
                    dict.print_all();
                }
            }
        };
    } while (true);
}

