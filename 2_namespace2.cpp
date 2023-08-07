// 2_namespace2.cpp
#include <iostream>

// * namespace를 사용하는 방법 3가지

// 방법 1. 전체 이름을 명시하는 방법
#if 0
namespace audio {
namespace mp3 {
    void play() { }
}
}

int main()
{
    audio::mp3::play();

    std::cout << "Hello, C++" << std::endl;
}
#endif

#if 0
namespace audio {
namespace mp3 {
    void play() { }
}
}

// 방법 2. using 선언(declaration)
using audio::mp3::play;
using std::cout;
using std::endl;

int main()
{
    play();

    cout << "Hello, C++" << endl;
}
#endif

namespace audio {
namespace mp3 {
    void play() { }
}
}

// 방법 3. using 지시어(Directive)
// > 특정한 이름 공간(namespace)에 있는 모든 것을
// 암묵적으로 접근할 수 있습니다.
using namespace std;
using namespace audio::mp3;

int main()
{
    play();

    cout << "Hello, C++" << endl;
}
