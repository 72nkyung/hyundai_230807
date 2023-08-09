// 20_객체복사2.cpp
#include <iostream>
using namespace std;

//  1) 깊은 복사
class User {
    char* name;
    int age;

public:
    // 컴파일러가 제공하는 복사 생성자
    User(const User& rhs)
        : name { rhs.name }
        , age { rhs.age }
    {
    }

    User(const char* s, int n)
        : age { n }
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        delete[] name;
    }

    void Print() { cout << name << ", " << age << endl; }
};

int main()
{
    User user { "Tom", 42 };
    user.Print();

    User other = user;
    other.Print();
}
