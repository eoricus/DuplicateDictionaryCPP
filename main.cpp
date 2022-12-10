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
    cout << "Данная демонстрационная программа реализует "
            "работу словаря с дубликатами. Команды программы: \n"
            "[1]   Создание нового словаря (запускается по умолчанию)\n"
            "[2]   Добавление элемента в словарь \n"
            "[3]   Исключение элементов с заданным ключом из словаря \n"
            "[4]   Исключение первого элемента с заданным ключом из словаря \n"
            "[5]   Поиск всех значений по ключу \n"
            "[6]   Поиск первого значения по ключу \n"
            "[7]   Изменение всех значений элемента по ключу\n"
            "[8]   Изменение первого значения элемента по ключу\n"
            "[9]   Вывод словаря"
            "[a/A] Удаление словаря"
            "[0]   Остановка/завершение программы \n"
            "Для начала работы программы с текстовым файлом -- укажите путь до файла, откуда нужно выгрузить данные (или '-', если программа будет хранить данные только в памяти программы):"
         << endl;

    do {
        bool dict_can_be_created = false; // Маяк для проверки, начала программа свою работу, или нет
        dictionary *dict;

        string filename;
        cin >> filename;

        if (filename == "-") {
            // Если данные будут храниться только в памяти программы
            dict_can_be_created = true;
            dict = new dictionary();
            cout << "Создан пустой словарь.\n"
                    "Данные хранятся только в памяти программы и будут сброшены после завершения.\n"
                    "(вы можете сохранить данные в ходе работы программы, воспользовавшись командой \"s\")" << endl;
        } else {
            // Если данные будут храниться в файле

            ifstream file(filename);
            if (!file.is_open()) {
                cout << "Файл не может быть прочитан.\n"
                        "Введите путь до файла еще раз, или введите \"-\" если хотите хранить словарь только в памяти программы:" << endl;
            } else if (!is_correct_file(filename)) {
                cout << "Файл некорректен. Исходный документ не должен содержать пустых строк!\n"
                        "Введите путь до файла еще раз, или введите \"-\" если хотите хранить словарь только в памяти программы:" << endl;
            } else {
                // Корректный файл
                dict_can_be_created = true;
                dict = new dictionary(filename);
                cout << "Словарь открыт в файле: " << filename << endl;
                cout << "При желании вы можете пересохранить файл, воспользовавшись командой \"s\"" << endl;
            }
            file.close();
        }

        while (dict_can_be_created) {
            char command; cin >> command;

            switch (command) {
                case '1': { // Создание нового словаря
                    cout << "Создание нового словаря предполагает перезапуск программы, и начало работы с новым словарём. Продолжить? (y/n)\n";
                    char answer; cin >> answer;

                    if (answer == 'y') {
                        dict_can_be_created = false;
                        delete dict;
                    }
                    break;
                }
                case '2': { // Добавление элемента в словарь
                    cout << "Введите ключ и значение элемента, который необходимо добавить в словарь: " << endl;
                    string key, value; cin >> key >> value;

                    dict->add_new_couple(key, value);
                    cout << "Значение добавлено в словарь!" << endl;
                    break;
                }
                case '3': { // Исключение элементов с заданным ключом из словаря
                    cout << "Введите ключ элемента, значения которых необходимо удалить: " << endl;
                    string key; cin >> key;

                    dict->delete_couples(key);
                    cout << "Значение удалено из словаря!" << endl;
                    break;
                }
                case '4': { // Исключение первого элемента с заданным ключом из словаря
                    cout << "Введите ключ элемента, значения которых необходимо удалить:" << endl;
                    string key; cin >> key;

                    dict->delete_couples(key);
                    cout << "Значение удалено из словаря!" << endl;
                    break;
                }
                case '5': { // Поиск всех значений по ключу
                    cout << "Введите ключ элементов, которые необходимо найти: " << endl;
                    string key; cin >> key;

                    vector<Couple> couples = dict->search_couples(key);
                    for (const Couple& couple: couples) {
                        cout << couple.key << endl << couple.value << endl;
                    }
                    break;
                }
                case '6': { // Поиск первого значения по ключу
                    cout << "Введите ключ элементов, которые необходимо найти: " << endl;
                    string key; cin >> key;

                    Couple couple = dict->search_couple(key);
                    cout << couple.key << endl << couple.value << endl;
                    break;
                }
                case '7': { // Изменение всех значений элемента по ключу
                    cout << "Введите ключи элементов, который необходимо изменить, а также новое значение: " << endl;
                    string key, value; cin >> key >> value;

                    dict->change_couples(key, value);
                    cout << "Значения изменены!" << endl;
                    break;
                }
                case '8': { // Изменение первого значения элемента по ключу
                    cout << "Введите ключ элемента, который необходимо изменить, а также новое значение: " << endl;
                    string key, value; cin >> key >> value;

                    dict->change_couple(key, value);
                    cout << "Значение изменено!" << endl;
                    break;
                }
                case '9': { // Вывод словаря
                    dict->print_all();
                    break;
                }
                case 'a': case 'A': { // Удаление словаря
                    cout << "Команда предполагает удаление всех значений словаря. Продолжить? (y/n)" << endl;
                    char answer; cin >> answer;

                    if (answer == 'y') {
                        dict->delete_all_couples();
                        cout << "Словарь удалён!" << endl;
                    }
                    break;
                }
                case 's': case 'S': { // Сохранение словаря
                    cout << "Введите путь, по которому будет сохранен словарь" << endl;
                    string path; cin >> path;

                    ifstream file(path);
                    if (file.is_open()) {
                        dict->set_filename(path);
                        cout << "Путь сохранен! После закрытия программы словарь будет записан в файл по указанному пути!" << endl;
                    } else {
                        cout << "Введенный путь некорректный, перезапустите команду (введите c) и попробуйте другой" << endl;
                    }

                    break;
                }
                case '0': { // Завершение программы
                    delete dict;
                    return 0;
                }
                default: {
                    cout << "\"" << command << "\"" << " - команда не найдена." << endl;
                    break;
                }
            }
        }
    } while (true);
}