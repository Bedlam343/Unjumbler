#include <iostream>
#include "AnagramSet.h"
#include <algorithm>

ostream & operator<<(ostream &out, const AnagramSet &s) {
    out << "{" << s.key.toString() << ": ";
        for(int n = 0; n < s.getSize(); n++) {
            out << s.words[n];
            if(n < s.getSize() - 1) {
                out << ",";
            }
        }
        out << "}";
        return out;
}

AnagramSet::AnagramSet(const LetterBag &theKey) : key(theKey) {
    next = nullptr;
}

void AnagramSet::insert(const string &s) {
    int size = words.size();
    for(int n = 0; n < size; n++) {
        if(words[n] > s) {
            words.insert(words.begin() + n, s);
            return;
        } else if (words[n] == s) {
            return;
        }
    }
    words.push_back(s);
}

//Binary search
void AnagramSet::remove(const string &s) {
    int left = 0, right = getSize() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(words[mid] == s) {
            words.erase(words.begin() + mid);
            return;
        }
        else if (words[mid] > s) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
}

int AnagramSet::getSize() const {
    return words.size();
}

bool AnagramSet::contains(const string &s) const {
    int left = 0, right = getSize() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(words[mid] == s) {
            return true;
        }
        else if (words[mid] > s) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return false;
}

void AnagramSet::clear() {
    words.clear();
}

vector<string> AnagramSet::getWords() const {
    return words;
}
