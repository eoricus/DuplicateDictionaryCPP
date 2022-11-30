//
// Created by erick on 23.11.2022.
//

#include "dictionary.h"
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

dictionary::dictionary(string filename) {
    this->filename = filename;
};

dictionary::~dictionary() {
    ofstream file;
    file.open(filename, ofstream::out | ofstream::trunc);
    file.close();
    for (auto item: storage) {
        add_entry_to_file(item);
    };
};


void dictionary::read_from_file() {
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
}

void dictionary::create_new_dict() {
    storage.clear();
};

void dictionary::add_entry(string key, string value) {
    Couple couple(key,value);
    storage.push_back(couple);
}

void dictionary::add_entry_to_file(string key, string value) {
    ofstream file;
    file.open(filename,  ios::app);
    if (file.is_open()) {
        file << key << endl << value << endl;
    }
};

void dictionary::add_entry_to_file(Couple couple) {
    ofstream file;
    file.open(filename,  ios::app);
    if (file.is_open()) {
        file << couple.key << endl << couple.value << endl;
    }
};

//CHECK
void dictionary::delete_entry(string key) {
    for (int i = 0; i < storage.size(); ++i) {
        if (storage[i].key == key) {
            storage.erase(storage.cbegin() + i);
            return;
        }
    }
};

//CHECK
void dictionary::delete_entries(string key) {
    for (int i = 0; i < storage.size(); ++i) {
        if (storage[i].key == key) {
            storage.erase(storage.cbegin() + i);
        }
    }
}

Couple dictionary::search_entry(string key) {
    for (Couple couple : storage) {
        if (couple.key == key) {
            return couple;
        }
    };
    Couple zero_couple("", "");
    return zero_couple;
};

vector<Couple> dictionary::search_entries(string key) {
    vector<Couple> couples;
    for (Couple couple : storage) {
        if (couple.key == key) {
            couples.push_back(couple);
        }
    };
    return couples;
}




void dictionary::change_entry(string key, string new_value) {

    for (int i = 0; i < storage.size(); ++i) {
        if (storage[i].key == key) {
            Couple new_couple(key, new_value);
            storage.at(i) = new_couple;
            return;
        }
    }
};

void dictionary::print_all() {
    for (auto const& couple : storage) {

        cout << couple.key << "=" << couple.value << endl;
    }
}

Couple dictionary::operator[](string key) {
    return search_entry(key);
}





