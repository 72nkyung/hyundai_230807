// 8_제어문.cpp
#include <iostream>
#include <string>
using namespace std;

#if 0
int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };

    for (int i = 0; i < sizeof(x) / sizeof(x[0]); ++i) {
        cout << x[i] << endl;
    }

    // C++11, Ranged-for
    //  : index가 필요하지 않을 때
    for (auto e : x) {
        cout << e << endl;
    }

    std::string s = "hello";
    for (auto e : s) {
        cout << e << endl;
    }
}
#endif

struct File { };

File* OpenFile(std::string filename)
{
    // 실패할 경우, NULL을 반환합니다.
    return NULL;
}

int Process()
{
    // 실패할 경우, 0이 아닌값을 반환합니다.
    return -1;
}

// 실패 가능성이 있는 함수를 사용하면, 반드시 반환값을 체크해야 합니다.
#if 0
int main()
{
    File* ret = OpenFile("a.txt");
    if (ret == NULL) {
        cout << "File open error..." << endl;
    }

    int ret2 = Process();
    if (ret2 != 0) {
        cout << "Process failed..." << endl;
    }
}
#endif

// if statement with initializer, C++17
// => 조건문에서만 유효한 변수를 정의할 수 있습니다.
int main()
{
    if (File* ret = OpenFile("a.txt"); ret == NULL) {
        cout << "File open error..." << endl;
    }

    if (int ret = Process(); ret != 0) {
        cout << "Process failed..." << endl;
    }
}
