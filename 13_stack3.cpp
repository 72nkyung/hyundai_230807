// 13_stack3.cpp
#include <iostream>
using namespace std;

// 3. 사용자 정의 타입(구조체)를 만들 때,
//    상태와 상태를 조작하는 함수를 묶을 수 있습니다.
//   => 캡슐화: 상태 + 행위

// "상태와 행위를 가지는 변수" => "객체(object)"

struct Stack {
    // 멤버 데이터(상태)
    int buff[10];
    int top;

    // 멤버 함수(상태를 조작하는 행위)
    void init()
    {
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

    s1.init();

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
