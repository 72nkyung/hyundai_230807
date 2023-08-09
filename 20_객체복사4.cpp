// 20_객체복사4.cpp
#include <iostream>
using namespace std;

//  3) 복사 금지
// - 복사 생성자를 private 영역에 선언만 둡니다.
//   : 외부에서 접근이 불가능하고, 내부에서 잘못 사용할 경우,
//     링크 오류가 발생합니다.
// - C++11, delete function을 이용해서, 복사 생성자를 제거합니다.

class User {
    char* name;
    int age;

public:
    User(const User& rhs) = delete;

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

    // User other = user;
    // other.Print();
}
