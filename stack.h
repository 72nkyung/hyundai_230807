// stack.h
#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* buff;
    int top;

public:
    Stack();
    Stack(int size);

    ~Stack();

    void push(int n);
    int pop();
};

#endif
