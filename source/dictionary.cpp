#include "../headers/dictionary.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

dictionary::dictionary(const string& filename) {
    this->filename = filename;

    ifstream file;
    file.open(filename);

    if (file.is_open()) {
        vector<string> row; string stroke;
        for (int i = 0, end_of_entry = false; getline(file, stroke) ; i++,end_of_entry = !end_of_entry) {
            row.push_back(stroke);
            if (end_of_entry) {
                Couple couple(row[0], row[1]);
                storage.push_back(couple);
                row.clear();
            }
        }
    }
};
dictionary::dictionary() {
    this->filename = "-";
};

dictionary::~dictionary() {
    if (filename != "-") {
        delete_all_couples_from_file();
        for (auto item: storage) {
            add_new_couple_to_file(item);
        };
    }
}



void dictionary::add_new_couple(string key, string value) {
    Couple couple(std::move(key), std::move(value));
    storage.push_back(couple);
}

void dictionary::add_new_couple_to_file(const Couple& couple) const {
    add_new_couple_to_file(couple.key,couple.value);
};

void dictionary::add_new_couple_to_file(const string& key, const string& value) const {
    ofstream file;
    file.open(filename,  ios::app);
    if (file.is_open()) {
        file << key << endl << value << endl;
    }
}



void dictionary::delete_couples(string key) {
    for (int i = 0; i < storage.size(); ++i) {
        if (storage[i].key == key) {
            storage.erase(storage.cbegin() + i);
        }
    }
}

void dictionary::delete_couple(string key) {
    for (int i = 0; i < storage.size(); ++i) {
        if (storage[i].key == key) {
            storage.erase(storage.cbegin() + i);
            return;
        }
    }
}

void dictionary::delete_all_couples() {
    storage.clear();
}

void dictionary::delete_all_couples_from_file() {
    ofstream file;
    file.open(filename, ofstream::out | ofstream::trunc);
    file.close();
}



Couple dictionary::search_couple(string key) {
    for (Couple couple : storage) {
        if (couple.key == key) {
            return couple;
        }
    };
    Couple zero_couple("", "");
    return zero_couple;
}

vector<Couple> dictionary::search_couples(string key) {
    vector<Couple> couples;
    for (const Couple& couple : storage) {
        if (couple.key == key) {
            couples.push_back(couple);
        }
    };
    return couples;
}



void dictionary::change_couples(const string& key, const string& new_value) {
    for (auto & i : storage) {
        if (i.key == key) {
            Couple new_couple(key, new_value);
            i = new_couple;
        }
    };
//    add_new_couple(key, new_value);
}

void dictionary::change_couple(const string& key, const string& new_value) {
    for (auto &i: storage) {
        if (i.key == key) {
            Couple new_couple(key, new_value);
            i = new_couple;
            return;
        }
    };
}

void dictionary::print_all() {
    for (auto const& couple : storage) {
        cout << couple.key << "=" << couple.value << endl;
    }
}

const string &dictionary::get_filename() const {
    return filename;
}

void dictionary::set_filename(const string &filename) {
    dictionary::filename = filename;
}

Couple dictionary::operator[](string key) {
    return search_couple(key);
}
