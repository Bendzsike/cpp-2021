#ifndef LAB10_1_MANAGER_H
#define LAB10_1_MANAGER_H

#include "Alkalmazott.h"
#include <vector>

class Manager : public Alkalmazott {
    vector<Alkalmazott *> beosztottak;
public:
    static const string MANAGER_MUNKAKOR;
    Manager(string, string, int, string);
    void addAlkalmazott(Alkalmazott*);
    void deleteAlkalmazott(int id);
    int beosztottakSzama();
    virtual void print(ostream &o = cout) const override;
};


#endif //LAB10_1_MANAGER_H
