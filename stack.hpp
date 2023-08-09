// stack.hpp
#ifndef STACK_HPP
#define STACK_HPP

// template 에서 typename 대신 class도 사용할 수 있습니다.
template <class TYPE>
class Stack {
private:
    TYPE* buff;
    int top;

public:
    Stack(int size = 10);
    ~Stack();
    void push(TYPE n);
    TYPE pop();
};

//       Stack: 클래스 템플릿
// Stack<TYPE>: 클래스

// template <typename T1, typename T2>
// Stack<T1, T2>::Stack() {}

template <class TYPE>
Stack<TYPE>::Stack(int size = 10)
{
    top = 0;
    buff = new TYPE[size];
}

template <class TYPE>
Stack<TYPE>::~Stack()
{
    delete[] buff;
}

template <class TYPE>
void Stack<TYPE>::push(TYPE n)
{
    buff[top++] = n;
}

template <class TYPE>
TYPE Stack<TYPE>::pop()
{
    return buff[--top];
}

#endif
