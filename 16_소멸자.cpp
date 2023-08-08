// 16_소멸자.cpp
#include <iostream>
#include <cstring>
using namespace std;

// 1. 사용자가 소멸자를 제공하지 않으면,
//    컴파일러가 아무일도 수행하지 않는 소멸자를 만들어 줍니다.
//     ~Person() {}

// 2. 클래스 내부에서 자원(메모리, 파일 등)을 할당한 경우,
//    소멸자를 통해 객체가 파괴되는 시점에 자원을 해지해야 합니다.
//    * 소멸자
//     - ~클래스이름() 형태입니다.
//     - 클래스는 소멸자를 1개만 가질 수 있습니다.

class Person {
    char* name;

public:
    Person(const char* s)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~Person()
    {
        delete[] name; // !!!
    }

    void Print()
    {
        cout << "Person=" << name << endl;
    }
};

int main()
{
    Person person("Tom");
    person.Print();
}
