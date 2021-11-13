// 7-5 
/*다음 main()에서 Color 클래스는 3요소(빨강, 초록, 파랑)로 하나의 색을 나타내는 클래스이다(4장 실습 문제 1번 참고).
+ 연산자로 색을 더하고, == 연산자로 색을 비교하고자 한다.
실행 결과를 참고하여 Color 클래스와 연산자, 그리고 프로그램을 완성하라.*/

//(1) +와 == 연산자를 Color 클래스의 멤버 함수로 구현하라.

#include <iostream>
using namespace std;

class Color {
    int r, g, b;
public:
    Color() { r = g = b = 0; }
    Color(int red, int green, int blue) { r = red; g = green; b = blue; }
    void show() { cout << r << ' ' << g << ' ' << b << endl; }

    Color operator+ (Color b);
    bool operator== (Color a);
};

Color Color::operator+(Color b) {
    Color a;
    a.r = this->r + b.r;
    a.g = this->g + b.g;
    a.b = this->b + b.b;
    return a;
}
bool Color::operator==(Color a) {
    if (this->r == a.r && this->g == a.g && this->b == a.b)
        return true;
    return false;
}

int main() {
    Color red(255, 0, 0), blue(0, 0, 255), c;
    c = red + blue;
    c.show(); // 색 값 출력 

    Color fuchsia(255, 0, 255);
    if (c == fuchsia)
        cout << "보라색 맞음";
    else
        cout << "보라색 아님";
}

//(2) +와 == 연산자를 Color 클래스의 프렌드 함수로 구현하라.
#include <iostream>
using namespace std;

class Color {
    int r, g, b;
public:
    Color() { r = g = b = 0; }
    Color(int red, int green, int blue) { r = red; g = green; b = blue; }
    void show() { cout << r << ' ' << g << ' ' << b << endl; }

    friend Color operator+ (Color a, Color b);
    friend bool operator== (Color a, Color b);
};

Color operator+(Color a, Color b) {
    Color c;
    c.r = a.r + b.r;
    c.g = a.g + b.g;
    c.b = a.b + b.b;
    return c;
}
bool operator==(Color a, Color b) {
    if (a.r == b.r && a.g == b.g && a.b == b.b) // [객체].[멤버]
        return true;
    return false;
}
int main() {
    Color red(255, 0, 0), blue(0, 0, 255), c;
    c = red + blue;
    c.show(); // 색 값 출력 

    Color fuchsia(255, 0, 255);
    if (c == fuchsia)
        cout << "보라색 맞음";
    else
        cout << "보라색 아님";
}
