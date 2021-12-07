#include "Szemely.h"

Szemely::Szemely(string vezetekNev, string keresztNev, int szuletesiEv) : vezetekNev(vezetekNev), keresztNev(keresztNev), szuletesiEv(szuletesiEv){}

const string &Szemely::getVezetekNev() const {
    return vezetekNev;
}

const string &Szemely::getKeresztNev() const {
    return keresztNev;
}

int Szemely::getSzuletesiEv() const {
    return szuletesiEv;
}

void Szemely::print(ostream &o) const {
    o << *this;
}

ostream &operator<<(ostream &os, const Szemely &sz) {
    os << sz.getVezetekNev() << " " << sz.getKeresztNev() << " " << sz.getSzuletesiEv();
    return os;
}
