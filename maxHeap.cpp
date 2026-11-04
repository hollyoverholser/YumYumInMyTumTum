//
// Created by holly on 10/31/2026.
//
#include "maxHeap.h"
#include <iostream>
#include <cctype>

using namespace std;

string lowerCase(const string& string) {
    size_t firstLetter = string.find_first_not_of(" \t\r");
    size_t lastLetter = string.find_last_not_of(" \t\r");

    if (firstLetter == string::npos) {
        return "";
    }

    string result = string.substr(firstLetter, lastLetter - firstLetter + 1);
    for (char& c : result) {
        c = tolower(c);
    }

    return result;
}

size_t parent(size_t i) {
    return (i - 1) / 2;
}

size_t leftChild(size_t i) {
    return (i * 2) + 1;
}

size_t rightChild(size_t i) {
    return (i * 2) + 2;
}

