// 13_stack7.cpp
#include <iostream>
using namespace std;

// 아래의 클래스를 헤더와 소스로 분리해서 관리해야 합니다.

class Stack {
private:
    // int buff[10];
    int* buff;
    int top;

public:
    // 생성자
    Stack()
    {
        cout << "Stack()" << endl;
        buff = new int[10];
        top = 0;
    }

    Stack(int size)
    {
        cout << "Stack(int)" << endl;
        buff = new int[size];
        top = 0;
    }

    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff;
    }

    void push(int n)
    {
        buff[top++] = n;
    }

    int pop()
    {
        return buff[--top];
    }
};

int main()
{
    // Stack s1; // Stack()
    Stack s1(100); // -> Stack(int)

    s1.push(10);
    s1.push(20);
    s1.push(30);

    // s1.top = 0;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
