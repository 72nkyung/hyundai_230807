// 14_접근지정자.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. private: 외부에서 접근이 불가능하고, 멤버 함수를 통해서만 접근이 가능합니다.
//             friend 선언된 클래스 / 함수에서도 접근이 가능합니다.

//    public: 외부에서 접근이 가능합니다.

// 2. struct: 기본 접근 지정자는 public 입니다.
//     class: 기본 접근 지정자는 private 입니다.

// 3. friend
//    - friend 선언된 함수 또는 클래스는 private 멤버에 접근이 가능합니다.

// friend
// - 캡슐화의 정책을 깨뜨리는 요소이다.
// + 캡슐화의 경계를 확장할 수 있습니다.
//   단위 테스트에서 유용하게 활용됩니다.

class User {
private:
    string name;
    int age;

public:
    User(string s, int n)
    {
        name = s;
        age = n;
    }

    // 방법 1.
    // string GetName() { return name; }
    // int GetAge() { return age; }

    // 방법 2. friend
    friend void PrintUser(User user);
};

// 일반 함수
void PrintUser(User user)
{
    cout << user.name << ", " << user.age << endl;
    // cout << user.GetName() << ", " << user.GetAge() << endl;
}

int main()
{
    // User user("Tom", 42);
    // User user = { "Tom", 42 };
    User user { "Tom", 42 };
    PrintUser(user);
}
