// 21_위임생성자.cpp
#include <iostream>
using namespace std;

// 위임 생성자, C++11
//  정의: 자신의 다른 생성자를 통해 객체를 초기화할 수 있습니다.
//    "생성자에서 다른 생성자를 이용할 수 있습니다."

//  효과: 생성자 코드에서 발생하는 "코드 중복"을 제거할 수 있습니다.
#if 0
class Color {
    int red;
    int green;
    int blue;

public:
    void Init() { }

    Color(int r, int g, int b)
        : red { r }
        , green { g }
        , blue { b }
    {
        Init();
    }

    Color()
        : red { 0 }
        , green { 0 }
        , blue { 0 }
    {
        Init();
    }
};

int main()
{
    Color c1;

    Color c2 { 10, 50, 255 };
}
#endif

class Color {
    int red;
    int green;
    int blue;

public:
    void Init() { cout << "Init()" << endl; }

    Color(int r, int g, int b)
        : red { r }
        , green { g }
        , blue { b }
    {
        Init();
        cout << "Color(int, int, int)" << endl;
    }

    Color()
        : Color(0, 0, 0) // 위임 생성자
    {
        cout << "Color()" << endl;
    }
};

int main()
{
    Color c1;

    // Color c2 { 10, 50, 255 };
}
