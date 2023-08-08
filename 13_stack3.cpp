// 13_stack3.cpp
#include <iostream>
using namespace std;

// 3. 사용자 정의 타입(구조체)를 만들 때,
//    상태와 상태를 조작하는 함수를 묶을 수 있습니다.
//   => 캡슐화: 상태 + 행위

// "상태와 행위를 가지는 변수" => "객체(object)"
//  - 객체의 상태는 멤버 함수를 통해서만 읽거나 변경될 수 있어야 합니다.
//    "정보 은닉(Information Hiding)"
//    : 접근 지정자
//     1) public: 외부에서 접근이 가능합니다.
//     2) private: 외부에서 접근이 불가능하고, 오직 멤버 함수를 통해서만 접근이 가능합니다.

struct Stack {
private:
    // 멤버 데이터(상태)
    int buff[10];
    int top;

public:
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

    // s1.top = 0;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
