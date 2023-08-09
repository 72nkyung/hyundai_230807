// 13_stack10.cpp
#include <iostream>
using namespace std;

#if 0
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
#endif

#if 0
struct Stack {
    int buff[10];
    int top;
};

void init(Stack* s)
{
    s->top = 0;
}

void push(Stack* s, int n)
{
    s->buff[(s->top)++] = n;
}

int pop(Stack* s)
{
    return s->buff[--(s->top)];
}

int main()
{
    Stack s1;
    init(&s1);

    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);

    cout << pop(&s1) << endl;
    cout << pop(&s1) << endl;
    cout << pop(&s1) << endl;
}
#endif

// private: 외부에서 접근할 수 없고, 멤버 함수를 통해서만 접근이 가능하다.
//  public: 외부에서 접근이 가능하다.
#if 0
class Stack {
private:
    int buff[10];
    int top;

public:
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
    Stack s1;
    s1.init();

    s1.push(10);
    s1.push(20);
    s1.push(30);

    // s1.top = 0;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
#endif

#if 0
class Stack {
private:
    // int buff[10];
    int* buff;
    int top;

public:
    // 기본 파라미터는 불필요한 오버로딩을 제거할 수 있습니다.
    Stack(int size = 10)
    {
        top = 0;
        buff = new int[size];
    }

    ~Stack()
    {
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
    Stack s1(100);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    // s1.top = 0;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
#endif

template <typename TYPE>
class Stack {
private:
    // int buff[10];
    TYPE* buff;
    int top;

public:
    // 기본 파라미터는 불필요한 오버로딩을 제거할 수 있습니다.
    Stack(int size = 10)
    {
        top = 0;
        buff = new TYPE[size];
    }

    ~Stack()
    {
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

int main()
{
    Stack<int> s1(100);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    // s1.top = 0;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
