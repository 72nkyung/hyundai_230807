// 7_함수.cpp
#include <iostream>
using namespace std;

// 기본 파라미터(Default Parameter)
//  - 정의: 함수의 파라미터의 기본값을 지정할 수 있습니다.
//         함수에 전달된 인자가 없는 경우, 파라미터의 기본값을 컴파일러가 자동으로
//         처리합니다.

//  - 주의사항 2가지
//  1) 반드시 뒤에서부터 지정해야 합니다.
//  2) 기본 파라미터는 함수의 선언부에만 작성됩니다.

// 선언
int add(int a, int b, int c = 0, int d = 0);

int main()
{
    cout << add(10, 20, 30, 40) << endl;

    cout << add(10, 20, 30) << endl;
    //      add(10, 20, 30, 0);

    cout << add(10, 20) << endl;
    //      add(10, 20, 0, 0)
}

// 정의
// > 파라미터의 기본값을 지정하면 안됩니다.
//   주석을 통해 표현하는 경우가 많습니다.
int add(int a, int b, int c /* =0 */, int d /* =0 */)
{
    return a + b + c + d;
}

#if 0
int add(int a, int b, int c, int d)
{
    return a + b + c + d;
}

int main()
{
    cout << add(10, 20, 30, 40) << endl;
    cout << add(10, 20, 30, 0) << endl;
    cout << add(10, 20, 0, 0) << endl;
}
#endif
