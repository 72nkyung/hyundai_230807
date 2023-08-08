// 13_stack5.cpp
#include <iostream>
using namespace std;

// 문제점: 사용자가 원하는 크기의 스택을 생성하고 싶습니다.

// 해결 방법
//  : 생성자는 객체를 초기화할 때, 인자를 전달받을 수 있습니다.
//    "생성자는 오버로딩을 통해, 다양한 생성자를 제공할 수 있습니다."
//    => 객체를 생성하는 다양한 방법을 제공할 수 있습니다.

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
