#ifndef LAB10_1_ALKALMAZOTT_H
#define LAB10_1_ALKALMAZOTT_H

#include <iostream>
#include "Szemely.h"

using namespace std;

class Alkalmazott : public Szemely {
protected:
    static int idCounter;
    int id;
    string munkakor;

public:
    Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor);

    int getId() const;

    virtual void print(ostream &o = cout) const override;
};


#endif //LAB10_1_ALKALMAZOTT_H
