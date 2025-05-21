#ifndef MAIN_HPP
#define MAIN_HPP
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

class HashTableChaining {
private:
    vector<list<int> > table;
    size_t hash(int key) const{ return key % table.size(); }

public:
    HashTableChaining(size_t size) : table(size) {}

    void insert(int key){
        size_t idx = hash(key);
        if (find(table[idx].begin(), table[idx].end(), key) == table[idx].end()){
            table[idx].push_back(key);
        }
    }

    bool search(int key) const{
        size_t idx = hash(key);
        return find(table[idx].begin(), table[idx].end(), key) != table[idx].end();
    }
    
    void remove(int key){
        size_t idx = hash(key);
        table[idx].remove(key);
    }

    void print() const{
        for (size_t i = 0; i < table.size(); i++){
            cout << i << ":";
            for (int key : table[i]){
                cout << " " << key;
            }
            cout << endl;
        }
    }
};

class HashTableLinearProbing {
private:
    vector<int> table;
    vector<bool> occupied;
    size_t size;
    size_t hash(int key) const {return key % size; }

public:
    HashTableLinearProbing(size_t s) : table(s, -1), occupied(s, false), size(s) {}

    void insert(int key){
        size_t idx = hash(key);
        for (size_t i = 0; i <size; i++){
            size_t probe = (idx + i) % size;
            if (!occupied[probe] || table[probe] == key){
                table[probe] = key;
                occupied[probe] = true;
                return;
            }
        }
    }

    bool search(int key) const{
        size_t idx = hash(key);
        for (size_t i = 0; i < size; i++){
            size_t probe = (idx + i) % size;
            if (!occupied[probe]){
                return false;
            }
            if (table[probe] == key){
                return true;
            }
        }
        return false;
    }

    void remove(int key){
        size_t idx = hash(key);
        for (size_t i = 0; i < size; i++){
            size_t probe = (idx + i) % size;
            if (!occupied[probe]){
                return;
            }
            if  (table[probe] == key){
                occupied[probe] = false;
                table[probe] = -1;
                return;
            }
        }
    }

    void print() const{
        for (size_t i = 0; i < size; i++){
            cout << i << ": ";
            if (occupied[i]){
                cout << table[i];
            }
            cout << endl;
        }
    }
};

inline unsigned int stringHash(const string& str, unsigned int tableSize){
    unsigned int hash = 5381;
    for (char c : str){
        hash = ((hash << 5) + hash) + c;
    }
    return hash % tableSize;
}

#endif