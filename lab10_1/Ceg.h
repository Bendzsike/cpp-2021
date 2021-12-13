#ifndef LAB10_1_CEG_H
#define LAB10_1_CEG_H

#include "Manager.h"

class Ceg {
    vector<Alkalmazott *> alkalmazottak;
public:
    void hireAlkalmazott(Alkalmazott *al);
    void fireAlkalmazott(int id);
    void addAlkalmazottToManager(int managerID, int alkalmazottID);
    void removeAlkalmazottFromManager(int managerID, int alkalmazottID);
    void printAll(ostream &o = cout);
    void printManager(ostream &o = cout);
};


#endif //LAB10_1_CEG_H
