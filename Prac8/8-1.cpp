// 8-1
// 문제 1~2에 적용되는 원을 추상화한 Circle 클래스가 있다.
// 다음 코드가 실행되도록 Circle을 상속받은 
// NamedCircle 클래스를 작성하고 전체 프로그램을 완성하라.
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 0) { this->radius = radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle { // 기본 클래스 Circle을 public으로 상속받은 파생 클래스 NamedCircle
    string name;
    string getName() { return name; }
public:
    NamedCircle(int radius, string name) { 
        setRadius(radius);
        this->name = name; 
    }
    // setRadius() 함수를 사용하지 않고, 생성자를 명시하여 radius를 설정하는 방법도 있음
    // NamedCircle(int radius, string name) : Circle(radius) { this->name = name; }
    void show() {
        cout << "반지름이 " << getRadius() << "인 " << getName() << endl;
    }
};

int main() {
    NamedCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
    waffle.show();
}