#include "fstream"
#include "Dictionary.h"

AnagramSet * Dictionary::find(AnagramSet *head, const LetterBag &key) const { while(head != nullptr) { if(head->key == key) { return head; } head = head->next; } return nullptr; }AnagramSet * Dictionary::
findWord(const string &w) const { LetterBag key(w); int index = key.hashValue(tableSize); return find(hashTable[index], key); }void Dictionary::insertNew(int index, AnagramSet *toInsert) { toInsert->next 
= hashTable[index]; hashTable[index] = toInsert; } Dictionary::Dictionary() { numWords = 0; } Dictionary::Dictionary(string fileName) { numWords = 0; ifstream infile; infile.open(fileName, ios::in); if(
!infile) { cout << "File named \"" << fileName << "\" not found!" << endl; cout << "Exiting program...hit any key."; getchar(); exit(0); } string word;infile >> word; while(!infile.eof()) { insertWord(
word); infile >> word; } infile.close(); }Dictionary::Dictionary(string words[], int arraySize) { numWords = 0; for(int counter = 0; counter < arraySize; counter++) { insertWord(words[counter]); } } 
Dictionary::Dictionary(const Dictionary &d) { for(int outer = 0; outer < tableSize; outer++) { AnagramSet *otherCurr = d.hashTable[outer]; while(otherCurr != nullptr) { AnagramSet *thisNew = new AnagramSet
(otherCurr->key);vector<string>words = otherCurr->getWords(); for(unsigned int inner = 0; inner < words.size(); inner++) { thisNew->insert(words[inner]); } insertNew(outer, thisNew); otherCurr = otherCurr->
next; } } numWords = d.getNumWords(); } Dictionary::~Dictionary() { clear(); } int Dictionary::getNumWords() const { return numWords; } void Dictionary::clear() { for(int n = 0; n < tableSize; n++) {
while(hashTable[n] != nullptr) { AnagramSet *temp = hashTable[n]->next; delete hashTable[n]; hashTable[n] = temp; } hashTable[n] = nullptr; } numWords = 0; } bool Dictionary::insertWord(const string &w) {
const LetterBag key(w); int index = key.hashValue(tableSize); AnagramSet *currAnagram = find(hashTable[index], key); if(currAnagram == nullptr) { currAnagram = new AnagramSet(key); currAnagram->insert(w);
numWords++; insertNew(index, currAnagram); return true; } if(currAnagram->contains(w)) { return false; } currAnagram->insert(w); numWords++; return true; }int Dictionary::insertWords(const vector<string> v) 
{ int numInstered = 0; for(unsigned int counter = 0; counter < v.size(); counter++) { if(insertWord(v[counter])) { numInstered++; } } return numInstered; } bool Dictionary::removeWord(string w) {const 
LetterBag currKey(w); int index = currKey.hashValue(tableSize); AnagramSet *currAnagram = hashTable[index]; AnagramSet *prevAnagram = nullptr; while(currAnagram != nullptr) {if(currAnagram->key == 
currKey) { if(currAnagram->contains(w)) { currAnagram->remove(w); numWords--; if(currAnagram->getSize() == 0) { if(prevAnagram == nullptr) { hashTable[index] = currAnagram->next;delete currAnagram; } else 
if (currAnagram->next == nullptr) { prevAnagram->next = nullptr; delete currAnagram; } else { prevAnagram->next = currAnagram->next; delete currAnagram; } } return true; } return false; } prevAnagram = 
currAnagram; currAnagram = currAnagram->next; } return false; } bool Dictionary::contains(const string &word) const { AnagramSet *match = findWord(word); return (match == nullptr)? false : match->contains
(word);} vector<string> Dictionary::getWords(const string & word) const { AnagramSet *match = findWord(word); return (match == nullptr)? vector<string>(0) : match->getWords();} int Dictionary::
getNumAnagrams(const string & word) const { AnagramSet *match = findWord(word); return (match == nullptr)? 0 : match->getSize(); } void Dictionary::printDictionary(int limit, ostream & out) const { out << 
endl; for(int counter = 0; counter < tableSize && limit > 0; counter++) { AnagramSet *currAnagram = hashTable[counter]; if(currAnagram != nullptr) { out << "\t" << counter << "..." << "     "; while
(currAnagram != nullptr) { out << *currAnagram << "  "; currAnagram = currAnagram->next;} limit--; out << endl << endl; } } }
