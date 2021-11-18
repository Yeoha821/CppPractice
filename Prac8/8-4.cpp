// 8-4
// 문제 3~4에 적용되는 2차원 상의 한 점을 표현하는 Point 클래스가 있다.
// 다음 main() 함수가 실행되도록 Point 클래스를 상속받는 
// ColorPoint 클래스를 작성하고, 전체 프로그램을 완성하라.
#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point(int x, int y) { this->x = x; this->y = y; }
    int getX() { return x; }
    int getY() { return y; }
protected:
    void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point { // public 상속 지정
    string color;
public:
    // 전달받은 값이 없으면 x, y는 0, color는 BLACK ->  디폴트 매개변수 이용
    ColorPoint(int x = 0, int y = 0, string color = "BLACK") : Point(x, y) { 
        this->color = color;
    }
    void setPoint(int x, int y) { move(x, y); }
    void setColor(string color) { this->color = color; }
    void show() {
        cout << color << " 색으로 (" << getX() << ", " << getY() << ")에 위치한 점입니다." << endl;
    }
};

int main() {
    ColorPoint zeroPoint; // BLACK 색에 (0, 0) 위치의 점
    zeroPoint.show(); // zeroPoint를 출력한다.

    ColorPoint cp(5, 5);
    cp.setPoint(10, 20);
    cp.setColor("BLUE");
    cp.show(); // cp를 출력한다.
}
