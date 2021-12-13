#include "Ceg.h"

void Ceg::hireAlkalmazott(Alkalmazott *al) {
    alkalmazottak.emplace_back(al);
}

void Ceg::fireAlkalmazott(int id) {
    for(int i = 0; i < alkalmazottak.size(); ++i) {
        if(alkalmazottak[i]->getId() == id) {
            alkalmazottak.erase(alkalmazottak.begin() + i);
            return;
        }
    }
}

void Ceg::addAlkalmazottToManager(int managerID, int alkalmazottID) {
    for(int i = 0; i < alkalmazottak.size(); ++i) {
        if(alkalmazottak[i]->getId() == managerID) {
            for(int j = 0; j < alkalmazottak.size(); ++j) {
                if(alkalmazottak[j]->getId() == alkalmazottID) {
                    dynamic_cast<Manager *>(alkalmazottak[i])->addAlkalmazott(alkalmazottak[j]);
                    return;
                }
            }
        }
    }
}

void Ceg::removeAlkalmazottFromManager(int managerID, int alkalmazottID) {
    for(int i = 0; i < alkalmazottak.size(); ++i) {
        if(alkalmazottak[i]->getId() == managerID) {
            dynamic_cast<Manager *>(alkalmazottak[i])->deleteAlkalmazott(alkalmazottID);
            return;
        }
    }
}

void Ceg::printAll(ostream &o) {
    for(int i = 0; i < alkalmazottak.size(); ++i) {
        alkalmazottak[i]->print(o);
        o << endl;
    }
}

void Ceg::printManager(ostream &o) {
    for(int i = 0; i < alkalmazottak.size(); ++i) {
        if(dynamic_cast<Manager*>(alkalmazottak[i])) {
            alkalmazottak[i]->print(o);
            o << endl;
        }
    }
}

