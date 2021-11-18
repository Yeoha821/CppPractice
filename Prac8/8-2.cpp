// 8-2
// 문제 1~2에 적용되는 원을 추상화한 Circle 클래스가 있다.
// 다음과 같이 배열을 선언하여 다음 실행 결과가 나오도록 Circle을 상속받은 
// NamedCircle 클래스와 main() 함수 등 필요한 함수를 작성하라.
#include <iostream>
using namespace std;

#define SIZE 5
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
    void setName(string name) { this->name = name; }
public:
    void setCircle(int radius, string name) {
        setRadius(radius);
        setName(name);
    }
    string getName() { return name; }
};

int main() {
    int radius; string name; double area[SIZE]; 

    NamedCircle pizza[SIZE];

    cout << SIZE << "개의 정수 반지름과 원의 이름을 입력하세요" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << ">> ";
        cin >> radius >> name; // 입력
        pizza[i].setCircle(radius, name); // 반지름과 이름 지정
        area[i] = pizza[i].getArea();
    }

    int max = 0;
    for (int i = 0; i < SIZE - 1; i++) {
        if (area[i] < area[i + 1])
            max = i + 1; // 가장 면적이 큰 피자의 인덱스가 저장되어 있음
    }

    cout << "가장 면적이 큰 피자는";
    for (int i = 0; i < SIZE; i++) {
        if (pizza[max].getArea() == pizza[i].getArea()) // 면적이 최댓값인 피자가 두 개 이상 존재할 때
            cout << " " << pizza[i].getName();
    }
    cout << "입니다" << endl;
}