// 12_nullptr.cpp
#include <iostream>
using namespace std;

#if 0
void foo(int n) { cout << "int" << endl; }
void foo(int* p) { cout << "int*" << endl; }

int main()
{
    // int* p = 100;
    // 정수 타입은 포인터 타입으로의 암묵적인 변환을 허용하지 않습니다.

    // int* p = 0;
    // 정수 0은 포인터 타입으로의 암묵적인 변환을 허용합니다.

    // #define NULL (void*)0
    int* p = NULL;

    foo(0);
    // foo(NULL); /* 컴파일 오류! */
    // : 정수 타입인지 포인터 타입인지 모호합니다.
}
#endif

// C++11, 기존의 NULL을 대체하는 새로운 nullptr이 도입되었습니다.
// => nullptr_t 타입으로 설계되었습니다.
//    : 포인터 타입으로의 암묵적인 변환을 허용하고, 논리 표현식에서 false로 판단되는
//      형태로 동작합니다.

void foo(int n) { cout << "int" << endl; }
void foo(int* p) { cout << "int*" << endl; }

int main()
{
    int* p = nullptr;

    foo(0);
    foo(nullptr);

    if (!p) {
        cout << "p는 null 입니다." << endl;
    }
}
