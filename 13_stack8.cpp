// 13_stack8.cpp
#include <iostream>
using namespace std;

// 클래스도 템플릿으로 만들 수 있습니다.

// => 클래스 템플릿
template <typename TYPE>
class Stack {
private:
    TYPE* buff;
    int top;

public:
    Stack()
    {
        buff = new TYPE[10];
        top = 0;
    }

    Stack(int size)
    {
        buff = new TYPE[size];
        top = 0;
    }

    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff;
    }

    void push(TYPE n)
    {
        buff[top++] = n;
    }

    TYPE pop()
    {
        return buff[--top];
    }
};

// 함수 템플릿은 인자를 통해, 컴파일러가 타입을 추론할 수 있지만,
// 클래스 템플릿은 추론이 불가능한 경우가 많습니다.
// => 명시적으로 타입을 지정해야 합니다.
int main()
{
    Stack<double> s1(100); // TYPE -> int

    s1.push(3.14);
    s1.push(5.5);
    s1.push(1.4);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}

#if 0
int main()
{
    Stack<int> s1(100); // TYPE -> int

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
#endif
