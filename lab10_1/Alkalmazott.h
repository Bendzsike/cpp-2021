#ifndef LAB10_1_ALKALMAZOTT_H
#define LAB10_1_ALKALMAZOTT_H

#include <iostream>
#include "Szemely.h"

using namespace std;

class Alkalmazott : public Szemely {
protected:
    string munkakor;

public:
    Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor);
    virtual void print(ostream &o = cout) const override;
};


#endif //LAB10_1_ALKALMAZOTT_H
