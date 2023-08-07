// 3_iostream.cpp
#include <iostream>
using namespace std;

// 서식을 사용하지 않고, 변수의 타입에 따라 입출력이 처리됩니다.
// > 변수의 타입이 변경되어도, 입출력의 코드는 변경할 필요가 없습니다.
#if 0
int main()
{
    double n;
    scanf("%lf", &n);
    printf("%lf\n", n);

    std::cin >> n;
    std::cout << n << std::endl;

    char buf[32];
    scanf("%s", buf);
    printf("%s\n", buf);

    std::cin >> buf;
    std::cout << buf << std::endl;
}
#endif

#include <iomanip>

int main()
{
    // 1111 1010 1111 1010
    // int n = 0xFAFA;

    // C++11에서 2진 상수를 표현하는 문법이 도입되었습니다.
    // => 작은 따옴표(')를 통해서 가독성을 높일 수 있습니다.
    int x = 10'000'000;
    int n = 0b1111'1010'1111'1010;

    printf("%x\n", n);
    printf("%X\n", n);
    printf("%d\n", n);
    printf("%10d\n", n);
    printf("%010d\n", n);

    // hex, uppercase, dec ...
    // => IO Manipulator(IO 조정자 / 조작자)
    cout << hex;
    cout << n << endl;

    cout << uppercase;
    cout << n << endl;

    cout << dec;
    cout << n << endl;

    cout << setw(10); // iomanip
    cout << n << endl;

    cout << setw(10) << setfill('0')
         << n << endl; // iomanip
}
