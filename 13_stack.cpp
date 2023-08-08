// 13_stack.cpp
#include <iostream>
using namespace std;

// 스택을 만들어봅시다.
// : 가장 마지막에 들어간 요소가 가장 먼저 나옵니다.
//   LIFO(Last In First Out)

// 1. 전역 변수 + 전역 함수
//  문제점: 스택을 여러개 제공하기 어렵습니다.
int buff[10];
int top = 0;

void push(int n)
{
    buff[top++] = n;
}

int pop()
{
    return buff[--top];
}

int main()
{
    push(10);
    push(20);
    push(30);

    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
}
