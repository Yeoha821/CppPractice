// 7-8
// 원을 추상화한 Circle 클래스는 간단히 아래와 같다.

#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle(int radius=0) { this->radius = radius; }
    void show() { cout << "radius = " << radius << " 인 원" << endl; }
    
    friend Circle& operator++ (Circle& a);
    friend Circle operator++ (Circle& a, int x);
};

// 다음 연산이 가능하도록 연산자를 프렌드 함수로 작성하라.
Circle& operator++ (Circle& a) { // 전위연산자
    a.radius++;
    return a;
}
Circle operator++ (Circle& a, int x) { // 후위연산자
    Circle c;
    c = a;
    a.radius++;
    return c; // radius에 1을 더하기 전의 c를 반환
}
int main() {
    Circle a(5), b(4);
    ++a; // 반지름을 1 증가 시킨다. 
    b = a++; // 반지름을 1 증가 시킨다. 
    a.show(); // 7
    b.show(); // 6
}
