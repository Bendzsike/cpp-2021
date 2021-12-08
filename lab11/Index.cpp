#include "Index.h"
#include <algorithm>
#include <sstream>

Index::Index(const string& fileName) {
    fstream input(fileName);
    if(!input.good()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string str;
    while(getline(input, str) && !str.empty()) {
        index.insert({str, set<int>()});
    }

    int countRows = 1;
    while(getline(input, str)) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        str.erase (remove_if (str.begin (), str.end (), ::ispunct), str.end ());
        stringstream iss(str);
        string word;
        while(iss >> word) {
            auto result = index.find(word);
            if(result != index.end()) {
                result->second.insert(countRows);
            }
        }
        ++countRows;
    }
    input.close();
}

void Index::print() {
    for(auto itMap : index) {
        cout << itMap.first << " ";
        for(auto itSet : itMap.second) {

        }
    }
}