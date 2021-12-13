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
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        index.insert({str, set<int>()});
    }

    int countRows = 1;
    while(getline(input, str)) {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        str.erase(remove_if(str.begin(), str.end(), ::ispunct), str.end());
        istringstream iss(str);
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

void Index::print(ostream &o) {
    for(const auto& s : this->index) {
        o << s.first << " ";

        if(s.second.size() == 1) {
            o << *s.second.begin();
        } else {
            int start = -1;
            auto it = s.second.begin();
            for(int i = 0; i < s.second.size(); ++i) {
                if(*next(it, i) == (*next(it, i + 1)) - 1) {
                    start = *next(it, i);
                } else {
                    if(start != -1) {
                        o << start << "-" << *next(it, i);
                        start = -1;
                    } else {
                        o << *next(it, i);
                    }
                    if(i < s.second.size() - 1) {
                        o << ", ";
                    } else {
                        o << " ";
                    }
                }
            }
        }
        o << endl;
    }
}