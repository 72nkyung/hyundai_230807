// 13_stack6.cpp
#include <iostream>
using namespace std;

// 문제점: 객체 내부에서 new를 통해 할당한 메모리는,
//       객체가 메모리에서 사라지기 전에 반드시 delete 되어야 합니다.

// 해결 방법
// > 객체가 메모리에서 해지되기 직전에 호출되는 약속된 멤버 함수가 있습니다.
//   : 소멸자(Destructor) 함수
//    - 객체 내부에서 반드시 해지되어야 하는 자원(메모리, 파일, ..)이 존재하는 경우,
//      소멸자를 통해 반드시 해지해야 합니다.
//    - 함수의 이름이 ~클래스 입니다.
//    - 반환 타입도 없고, 반환값도 존재하지 않습니다.
//    - 인자도 없습니다.
//    - 오버로딩 불가능합니다.

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
