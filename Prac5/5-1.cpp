// 5-1
// 두 개의 Circle 객체를 교환하는 swap() 함수를 
// '참조에 의한 호출'이 되도록 작성하고 호출하는 프로그램을 작성하라.

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

void swap(Circle &a, Circle &b) { // 참조로 받음
	Circle tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	Circle a(1), b(2);
	cout << "a의 면적 = " << a.getArea() << ", b의 면적 = " << b.getArea() << endl;
	swap(a, b);
	cout << "a의 면적 = " << a.getArea() << ", b의 면적 = " << b.getArea() << endl;
}