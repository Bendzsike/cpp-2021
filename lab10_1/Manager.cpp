#include "Manager.h"

const string Manager::MANAGER_MUNKAKOR = "manager";

Manager::Manager(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor) : Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkakor) {}

void Manager::addAlkalmazott(Alkalmazott *al) {
    beosztottak.emplace_back(al);
}

void Manager::deleteAlkalmazott(int id) {
    for(int i = 0; i < beosztottakSzama(); ++i) {
        if (beosztottak[i]->getId() == id ) {
            beosztottak.erase(beosztottak.begin() + i);
            return;
        }
    }
}

int Manager::beosztottakSzama() {
    return beosztottak.size();
}

void Manager::print(ostream &o) const {
    o << "Manager ";
    Alkalmazott::print(o);
    o <<" beosztottjai:" << endl;
    for(int i = 0; i < beosztottak.size(); ++i) {
        o << "Alkalmazott ";
        beosztottak[i]->print(o);
        o << endl;
    }
    o << "---------------------------------------------" << endl;
}

