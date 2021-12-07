#ifndef LAB10_1_MANAGER_H
#define LAB10_1_MANAGER_H

#include "Alkalmazott.h"

class Manager : public Alkalmazott {
public:
    Manager(string, string, int, string);
    void addAlkalmazott(Alkalmazott*);
    void deleteAlkalmazott(Alkalmazott *);
};


#endif //LAB10_1_MANAGER_H
