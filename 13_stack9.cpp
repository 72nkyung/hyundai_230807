// 13_stack9.cpp
#include <iostream>
using namespace std;

// 이미 C++ 표준 라이브러리에 stack이 제공됩니다.
//  : STL(Standard Template Library)

#include <stack>

int main()
{
    stack<int> s;
    // 스택의 마지막 요소를 참조하는 연산과, 제거하는 연산이 분리되어 있습니다.
    //  * 스택의 마지막 요소: top()
    //  * 스택의 요소 제거: pop()

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
