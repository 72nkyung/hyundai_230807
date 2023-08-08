// 13_stack7.cpp
#include <iostream>
using namespace std;

// 아래의 클래스를 헤더와 소스로 분리해서 관리해야 합니다.
#include "stack.h"

int main()
{
    Stack s1(100);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}

// $ g++ stack.cpp 13_stack7.cpp
