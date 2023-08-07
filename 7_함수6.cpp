// 7_함수6.cpp
#include <iostream>
using namespace std;

// 최대 공약수
// => 오직 정수를 대상으로 하는 함수 입니다.
int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}

// C++ 에서 함수의 호출을 금지하는 방법
//  => 런타임 오류가 아닙니다.
// 1) 구현을 하지 않고, 선언만 제공합니다.
//   : 링크 오류를 의도합니다.
// double gcd(double a, double b);

/*
Undefined symbols for architecture x86_64:
  "gcd(double, double)", referenced from:
      _main in 7_함수6-7b4814.o
*/
// 문제점: 문제의 원인을 파악하기 어렵고,
//       의도를 전달하기 어렵습니다.

// 2) C++11, 함수를 금지하는 문법이 도입되었습니다.
//   : Delete function
/*
함수 "gcd(double a, double b)" (선언됨 줄 28)을(를) 참조할 수 없습니다.
삭제된 함수입니다.C/C++(1776)
*/

double gcd(double a, double b) = delete;

int main()
{
    cout << gcd(15, 25) << endl;
    cout << gcd(12, 4) << endl;

    // 실수 타입이 전달되었을 때, 금지하고 싶습니다.
    // cout << gcd(3.5, 21.6) << endl;
}
