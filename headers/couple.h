//
// Created by erick on 10.12.2022.
//

#ifndef COURSEWORK_COUPLE_H
#define COURSEWORK_COUPLE_H

#include <utility>

#include "string"

using namespace std;

class Couple {

public:
    string key;
    string value;

    Couple(string key, string value) {
        this->key = move(key);
        this->value = move(value);
    };
};

#endif //COURSEWORK_COUPLE_H
