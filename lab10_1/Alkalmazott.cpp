#include "Alkalmazott.h"

Alkalmazott::Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor) : Szemely(vezetekNev, keresztNev, szuletesiEv), munkakor(munkakor) {}

void Alkalmazott::print(ostream &o) const {
    Szemely::print(o);
    o << " " << munkakor;
}