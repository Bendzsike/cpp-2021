#include "Alkalmazott.h"

int Alkalmazott::idCounter{0};

Alkalmazott::Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor) : Szemely(vezetekNev, keresztNev, szuletesiEv), munkakor(munkakor), id(++idCounter) {}

void Alkalmazott::print(ostream &o) const {
    o << id << " ";
    Szemely::print(o);
    o << " " << munkakor;
}

int Alkalmazott::getId() const {
    return id;
}
