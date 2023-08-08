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

    inline void push(int n);
    inline int pop();
};

// 멤버 함수도 인라인 함수로 만들 수 있습니다.
// 인라인 함수의 경우 구현이 헤더를 통해서 제공되어야 합니다.

// :: 범위 연산자
//  - namespace
//  - class
void Stack::push(int n)
{
    buff[top++] = n;
}

int Stack::pop()
{
    return buff[--top];
}

#endif
