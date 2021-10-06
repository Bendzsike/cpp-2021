//
// Created by Benjamin on 2021. 10. 06..
//

#ifndef LAB3_STACK_H
#define LAB3_STACK_H

#include "List.h"

class Stack {
    List elements;

public:
    void push(int e);
    int pop();
    bool isEmpty() const;
};


#endif //LAB3_STACK_H
