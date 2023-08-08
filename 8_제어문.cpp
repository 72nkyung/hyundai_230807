// 8_제어문.cpp
#include <iostream>
#include <string>
using namespace std;

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
