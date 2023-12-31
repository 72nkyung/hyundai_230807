// 20_객체복사5.cpp
#include <iostream>
using namespace std;

//  4) 소유권 이전
//   => 이동 생성자를 통해서 구현합니다.
//     User(User&& rhs)

class User {
    char* name;
    int age;

public:
    // 복사 생성자
    User(const User& rhs)
        : age { rhs.age }
    {
        cout << "User(const User&)" << endl;
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    // 이동 생성자
    User(User&& rhs)
        : name { rhs.name }
        , age { rhs.age }
    {
        cout << "User(User&&)" << endl;
        rhs.name = nullptr;
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

    void Print()
    {
        if (name) {
            cout << name << ", " << age << endl;
        } else {
            cout << "(null)" << endl;
        }
    }
};

int main()
{
    User user { "Tom", 42 };
    user.Print();

    // User other = User("Bob", 100);

    // C++11에서 lvalue를 rvalue로 변경할 수 있는 연산을 제공합니다.
    //  : std::move

    User other = std::move(user);
    user.Print();
    other.Print();
}
