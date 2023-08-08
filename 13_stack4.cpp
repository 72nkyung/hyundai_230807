// 13_stack4.cpp
#include <iostream>
using namespace std;

// 문제점: 객체를 생성하였을 때, 바로 사용할 수 없습니다.
//  => 객체가 메모리에 생성되었을 때, 바로 사용할 수 있는 상태가
//     되어야 합니다.
//  => 객체가 메모리에 생성된 직후, 자동으로 호출되는 약속된 멤버 함수가 있습니다.
//     생성자(Constructor) 함수
//      역활: 객체가 생성되었을 때, 초기화의 역활을 수행하기 위해 제공됩니다.
//      형태
//       1. 멤버 함수의 이름이 클래스의 이름과 동일합니다.
//       2. 반환 타입도 없고, 반환값도 존재하지 않습니다.

class Stack {
private:
    int buff[10];
    int top;

public:
    // 생성자
    Stack()
    {
        cout << "Stack()" << endl;
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
    Stack s1, s2;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    // s1.top = 0;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
