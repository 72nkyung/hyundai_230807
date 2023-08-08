// 6_string.cpp
#include <iostream>
using namespace std;

// #include <string.h>
#include <cstring> // strcmp

// C의 문자열
//  - 정의: '\0(널 문자)'로 종료되는 char 배열

// 문제점
// 1) 문자열의 연산을 함수를 통해서 수행해야 합니다.
//    - strcmp, strcpy, strcat
// 2) 메모리 관리를 직접 수행해야 합니다.
//    충분한 메모리가 없는 상태에서 연산을 수행할 경우,
//    미정의 동작이 발생합니다.
#if 0
int main()
{
    char str1[32] = "hello";
    const char* str2 = "hello";
    // 문자열을 참조할 때, 반드시 const char*를 사용해야 합니다.

    // 문자열 비교를 위해서는 문자열 함수를 이용해야 합니다.
    // if (str1 == str2) {
    if (strcmp(str1, str2) == 0) {
        std::cout << "같은 문자열" << std::endl;
    } else {
        std::cout << "다른 문자열" << std::endl;
    }

    // str1 = "world"; // 허용 X
    strcpy(str1, "world");
    // str1이 복사되는 문자열을 수용할만큼 충분한 메모리가 존재해야 합니다.
    cout << str1 << endl;

    strcat(str1, "!!");
    // str1이 추가적으로 지정된 문자열을 수용할만큼의 충분한 메모리가 존재해야 합니다.
    cout << str1 << endl;
}
#endif

// C++ 문자열
//  => std::string
//  1) 연산자를 통해 문자열의 비교 / 복사 / 연결 등의 작업을 수행할 수 있습니다.
//  2) 메모리 관리를 자동으로 수행합니다.
//    => 미정의 동작의 위험성을 제거할 수 있습니다.
//    => 짧은 문자열의 경우에는 내부적으로 메모리 할당을 수행하지 않는 형태로
//       최적화되어 있습니다.

#include <string>

int main()
{
    std::string s1 { "hello" };
    std::string s2 = { "hello" };
    std::string s3 = "hello";
    std::string s4("hello");

    if (s1 == s2) {
        cout << "같은 문자열" << endl;
    } else {
        cout << "다른 문자열" << endl;
    }

    std::string s3 = s1;
    s3 = "world";
    cout << s3 << endl;

    // s3 = s3 + "!!";
    s3 += "!!";
    cout << s3 << endl;
}
