#include "Szemely.h"

Szemely::Szemely(string vezetekNev, string keresztNev, int szuletesiEv) : vezetekNev(vezetekNev), keresztNev(keresztNev), szuletesiEv(szuletesiEv){}

void Szemely::print(ostream &o) const {
    o << vezetekNev << " " << keresztNev << " " << szuletesiEv;
}

ostream &operator<<(ostream &os, const Szemely &sz) {
    sz.print(os);
    return os;
}
