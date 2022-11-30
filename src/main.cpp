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
    cout << "Данная демонстрационная программа реализует "
            "работу словаря с дубликатами. Команды программы: \n"
            "[new]    Создание пустого словаря \n"
            "[add]    Добавление элемента в словарь \n"
            "[delete] Исключение элементов с заданным ключом из словаря \n"
            "[search] Поиск значений по ключу \n"
            "[search one] Поиск значения по ключу \n"
            "[change] Изменение значения элемента словаря \n"
            "[print]  Вывод словаря в порядке возрастания ключей \n"
            "Для начала работы программы с текстовым файлом -- укажите путь до файла, или введите ~ для работы с адресом по умолчанию: "
         << endl;

    string filename;

    do {
        cin >> filename;
        if (filename == "~") filename = R"(C:\Users\erikm\Downloads\test)";

        ifstream file(filename);

        if (!file.is_open()) {
            cout << "Файл не может быть прочитан, введите путь до файла еще раз, или же воспользуйтесь файлом по умолчанию (~): " << endl;
        } else if (!is_correct_file(filename)) {
            cout << "Файл некорректен. Исходный документ не должен содержать пустых строк! " << endl;
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
                    cout << "Новый словарь создан!" << endl;
                }
                // ADD
                else if (command == "add") {
                    string key, value;
                    cout << "Введите ключ и значение для записи: " << endl;
                    cin >> key >> value;

                    dict.add_entry(key, value);

                    cout << "Значение записано!" << endl;
                }
                // DELETE
                else if (command == "delete") {
                    cout << "Введите ключ элемента, который нужно удалить: " << endl;
                    string key;cin >> key;

                    dict.delete_entries(key);
                    cout << "Значения с этим ключом удалены!" << endl;
                }
                // DELETE ONE
                else if (command == "deleteOne") {
                    cout << "Введите ключ элемента, который нужно удалить: " << endl;
                    string key;cin >> key;

                    dict.delete_entry(key);
                    cout << "Значение с этим ключом удалено!" << endl;
                }
                // SEARCH
                else if (command == "search") {
                    cout << "Введите ключ элемента, который нужно найти: " << endl;
                    string key;cin >> key;

                    vector<Couple> res = dict.search_entries(key);
                    for (const Couple& couple : res) {
                        cout << couple.value << endl;
                    }
                }
                // SEARCH ONE
                else if (command == "searchOne") {
                    cout << "Введите ключ элемента, который нужно найти: " << endl;
                    string key;cin >> key;

                    Couple res = dict[key];
                    cout << res.value << endl;
                }
                // CHANGE
                else if (command == "change") {
                    string key, value;
                    cout << "Введите ключ и значение для обновления записи: " << endl;
                    cin >> key >> value;

                    dict.change_entry(key, value);
                    cout << "Значение перезаписано!" << endl;
                }
                // PRINT
                else if (command == "print") {
                    dict.print_all();
                }
            }
        };
    } while (true);
}

