// 20_객체복사3.cpp
#include <iostream>
using namespace std;

//  2) 참조 계수

class User {
    char* name;
    int age;

    int* ref;

public:
    User(const User& rhs)
        : name { rhs.name }
        , age { rhs.age }
        , ref { rhs.ref }
    {
        // 참조 계수 증가
        ++(*ref);
    }

    User(const char* s, int n)
        : age { n }
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);

        ref = new int { 1 };
    }

    ~User()
    {
        if (--(*ref) == 0) {
            delete[] name;
            delete ref;
            cout << "자원 파괴" << endl;
        }
        cout << "~User(): " << Ref() << endl;
    }

    int Ref() { return *ref; }
    void Print() { cout << name << ", " << age << endl; }
};

int main()
{
    User user { "Tom", 42 };
    cout << user.Ref() << endl; // 1

    user.Print();

    User other = user;
    cout << user.Ref() << endl; // 2

    other.Print();
}
