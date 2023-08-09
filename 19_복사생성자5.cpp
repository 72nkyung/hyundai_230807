// 19_복사생성자5.cpp

#include <iostream>
using namespace std;

#if 0
class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(const Sample& rhs) { cout << "Sample(const Sample&)" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }
};

Sample foo()
{
    Sample s; // 1) Sample()
    return s; // 2) 반환용 임시 객체 복사 생성: Sample(const Sample&)
} // 3) 지역 객체 파괴: ~Sample()

// g++ 19_복사생성자5.cpp -fno-elide-constructors -std=c++98
/*
Sample()
Sample(const Sample&)
~Sample()
Sample(const Sample&)
~Sample()
~Sample()
*/
int main()
{
    Sample result = foo(); // 4) result 객체가 반환용 임시 객체를 복사해서 생성 - Sample(const Sample&)
    // 5) 반환용 임시 객체 파괴: ~Sample()
} // 6) result 지역 객체 파괴: ~Sample()
#endif

#if 0
class Sample {
public:
    Sample() { cout << "Sample()" << endl; }

    Sample(const Sample& rhs) { cout << "Sample(const Sample&)" << endl; } // 복사 생성자

    Sample(Sample&& rhs) { cout << "Sample(Sample&&)" << endl; } // 이동 생성자
    ~Sample() { cout << "~Sample()" << endl; }
};

Sample foo()
{
    Sample s; // 1) 지역 객체 s 생성: Sample()
    return s; // 2) 반환용 임시 객체가 이동 생성자를 통해서 생성: Sample(Sample&&)
} // 3) 지역 객체 s 파괴: ~Sample()

// g++ 19_복사생성자5.cpp -fno-elide-constructors -std=c++11
/*
Sample()
Sample(Sample&&)
~Sample()
Sample(Sample&&)
~Sample()
~Sample()
*/
int main()
{
    Sample result = foo(); // 4) result 객체가 이동 생성자를 통해 생성
    // 5) 임시 객체 파괴: ~Sample()
} // 6) 지역 객체 result 파괴: ~Sample()
#endif

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }

    Sample(const Sample& rhs) { cout << "Sample(const Sample&)" << endl; } // 복사 생성자

    Sample(Sample&& rhs) { cout << "Sample(Sample&&)" << endl; } // 이동 생성자
    ~Sample() { cout << "~Sample()" << endl; }
};

Sample foo()
{
    Sample s;
    return s; // 반환용 임시 객체 이동/복사 생성
}

// g++ 19_복사생성자5.cpp -fno-elide-constructors -std=c++17
// > 복사(이동) 생성자의 제거가 컴파일러의 최적화 레벨이 아니라,
//   C++17의 언어 표준이 되었습니다.
//   "Mandatory Copy ellison"

/*
Sample()
Sample(Sample&&)
~Sample()
~Sample()
*/

// 지역 객체 -> 반환용 임시 객체 생성 ---> result 지역 객체 생성
int main()
{
    Sample result = foo(); // 반환용 임시 객체를 지역 객체로 이동/복사
}
