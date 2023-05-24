#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include "AnagramSet.h"

using namespace std;

class Dictionary {

public:
    static const int tableSize = 5001;

private:
    AnagramSet *hashTable[tableSize] = { nullptr };
    int numWords;

    AnagramSet * find(AnagramSet *head, const LetterBag &key) const;

    AnagramSet * findWord(const string &w) const;

    void insertNew(int index, AnagramSet *toInsert);

public:
    Dictionary();  // default constructor: creates an empty dictionary.

    Dictionary(string fileName);  // insert all words from the file into an empty dictionary.

    Dictionary(string words[], int arraySize) ;  // insert all words from the array into an empty dictionary.

    Dictionary(const Dictionary & d);  // copy constructor

    ~Dictionary() ;  // destructor


    int getNumWords() const;  // return number of words.

    void clear(); // remove all the words.

    bool insertWord(const string &w);  // insert a word, return true if wasn’t already there, false if already there.

    int insertWords(const vector<string> v);  // insert multiple words and return how many weren’t already there.

    bool removeWord(string w) ;  // remove the word. Return true if it was there to be removed and false otherwise.

    bool contains(const string &word) const;

    vector<string> getWords(const string &word) const;  // return words that are anagrams for the given word.

    int getNumAnagrams(const string & word) const;  // return number of anagrammatic forms found for the given word.

    void printDictionary(int limit = tableSize, ostream & out = cout) const; // print AnagramSets in each bucket of table.
};

#endif // DICTIONARY_H
