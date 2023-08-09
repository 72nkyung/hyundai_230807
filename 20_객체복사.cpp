// 20_객체복사.cpp
#include <iostream>
using namespace std;

// 1) 객체 내부에서 자원을 할당한 경우,
//    소멸자를 통해서 자원을 해지해야 합니다.

// 2) 포인터 멤버를 가지는 클래스는
//    컴파일러가 제공하는 복사 생성자를 사용하는 경우,
//    "얕은 복사"의 문제가 발생합니다.
//  => 반드시 복사 생성자를 제공해서, 얕은 복사로 인한 문제를 해결해야 합니다.

// - 복사 생성자 제공 => "객체 복사 정책"을 구현합니다.
//  1) 깊은 복사
//  2) 참조 계수
//  3) 복사 금지
//  4) 소유권 이전

class User {
    char* name;
    int age;

public:
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
