
#ifndef LAB10_1_SZEMELY_H
#define LAB10_1_SZEMELY_H

#include <iostream>

using namespace std;

class Szemely {
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;
public:
    Szemely(string, string, int);

    virtual void print(ostream &o = cout) const;
};

ostream& operator<<(ostream &os, const Szemely &sz);


#endif //LAB10_1_SZEMELY_H
