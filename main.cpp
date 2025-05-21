#include "main.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Hash Table with chaining:" << endl;
    HashTableChaining chainTable(7);
    chainTable.insert(10);
    chainTable.insert(20);
    chainTable.insert(15);
    chainTable.insert(7);
    chainTable.print();
    cout << "Search 15: " << (chainTable.search(15) ? "Found" : "Not Found") << endl;
    chainTable.remove(15);
    chainTable.print();

    cout << endl;

    cout << "Hash Table with linear probing:" << endl;
    HashTableLinearProbing probeTable(7);
    probeTable.insert(10);
    probeTable.insert(20);
    probeTable.insert(15);
    probeTable.insert(7);
    probeTable.print();
    cout << "Search 15: " << (probeTable.search(15) ? "Found" : "Not Found") << endl;
    probeTable.remove(15);
    probeTable.print();

    cout << "\n String Hash Example: " << endl;
    string s = "Hello";
    cout << "Hash of \"" << s << "\": " << stringHash(s, 7) << endl;
    return 0;
}