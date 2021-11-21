//9-7
// 사각형에 내접하는 도형을 표현하기 위한 Shape 클래스가 있다.

//Shape 클래스를 상속받아 타원을 표현하는 Oval, 
//사각형을 표현하는 Rect, 삼각형을 표현하는 Triangular 클래스를 작성하라. 
//main()을 작성하고 실행하면 다음과 같다.

#include <iostream>
using namespace std;

class Shape {
protected:
    string name; // 도형의 이름
    int width, height; // 도형이 내접하는 사각형의 너비와 높이
public:
    Shape(string n = "", int w = 0, int h = 0) {
        name = n; width = w; height = h;
    }
    virtual double getArea() { return 0; } // dummy 값 리턴
    string getName() { return name; } // 이름 리턴
};

class Oval : public Shape {
    double area;
public:
    Oval(string name, int width, int height) : Shape(name,width,height) {}
    virtual double getArea(); // 오버라이딩
};
class Rect : public Shape {
    double area;
public:
    Rect(string name, int width, int height) : Shape(name, width, height) {}
    virtual double getArea();
};
class Triangular : public Shape {
    double area;
public:
    Triangular(string name, int width, int height) : Shape(name, width, height) {}
    virtual double getArea();
};

double Oval::getArea() { 
    area = 3.14 * (width / 2) * (height / 2); // 타원의 넓이 = pi * 긴반지름 * 짧은반지름
    return area;
}
double Rect::getArea() {
    area = width * height; // 사각형의 넓이
    return area;
}
double Triangular::getArea() {
    area = width * height / 2.0; // 삼각형의 넓이
    return area;
}

int main() {
    Shape* p[3];
    p[0] = new Oval("빈대떡", 10, 20);
    p[1] = new Rect("찰떡", 30, 40);
    p[2] = new Triangular("토스트", 30, 40);
    for (int i = 0; i < 3; ++i)
        cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;
    for (int i = 0; i < 3; ++i) delete p[i];
}