#ifndef LAB11_INDEX_H
#define LAB11_INDEX_H

#include <iostream>
#include <fstream>
#include <set>
#include <map>

using namespace std;

class Index {
    map<string, set<int>> index;
public:
    Index(const string& fileName);
    void print(ostream &o = cout);
};


#endif //LAB11_INDEX_H
