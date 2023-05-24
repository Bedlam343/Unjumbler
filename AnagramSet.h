#ifndef ANAGRAMSET_H
#define ANAGRAMSET_H

#include <vector>
#include "LetterBag-1.h"

using namespace std;

class AnagramSet {

    friend ostream & operator<<(ostream &out, const AnagramSet &s);

public:
    const LetterBag key;
    AnagramSet *next;

private:
    vector<string>words;

public:
    AnagramSet(const LetterBag &theKey);

    void insert(const string &s);

    void remove(const string &s);

    int getSize() const;

    bool contains(const string &s) const ;

    void clear();

    vector<string> getWords() const;
};

#endif // ANAGRAMSET_H
