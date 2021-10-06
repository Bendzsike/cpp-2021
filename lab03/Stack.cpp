//
// Created by Benjamin on 2021. 10. 06..
//

#include "Stack.h"

void Stack::push(int e) {
    elements.insertFirst(e);
}
int Stack::pop() {
    if(isEmpty()) {
        throw length_error("The stack is empty!");
    }
    return elements.removeFirst();
}
bool Stack::isEmpty() const {
    return elements.empty();
}