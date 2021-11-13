// 7-7
// 2차원 행렬을 추상화한 Matrix 클래스를 활용하는 다음 코드가 있다.
// (1) <<, >> 연산자 함수를 Matrix의 멤버 함수로 구현하라.

#include <iostream>
using namespace std;

class Matrix {
    int num[4];
public:
    Matrix();
    Matrix(int a, int b, int c, int d);
    void show();

    // 연산자 함수
    void operator>> (int* x);
    void operator<< (int* y);
};

Matrix::Matrix() {
    for (int i = 0; i < 4; i++)
        num[i] = 0;
}
Matrix::Matrix(int a, int b, int c, int d) {
    num[0] = a; num[1] = b; num[2] = c; num[3] = d;
}
void Matrix::show() {
    cout << "Matrix = { ";
    for (int i = 0; i < 4; i++) {
        cout << num[i] << ' ';
    }
    cout << '}' << endl;
}

void Matrix::operator>> (int* x) { // int 배열 첫 번째 요소의 주소를 받음 (대신 int x[]도 가능)
    for (int i = 0; i < 4; i++) {
        x[i] = this->num[i];
    }
}
void Matrix::operator<< (int* y) {
    for (int i = 0; i < 4; i++) {
        this->num[i] = y[i];
    }
}
int main() {
    Matrix a(4, 3, 2, 1), b;
    int x[4], y[4] = { 1,2,3,4 }; // 2차원 행렬의 4 개의 원소 값 
    a >> x; // a의 각 원소를 배열 x에 복사. x[]는 {4,3,2,1} 
    b << y; // 배열 y의 원소 값을 b의 각 원소에 설정 

    for (int i = 0; i < 4; i++) cout << x[i] << ' '; // x[] 출력 
    cout << endl;
    b.show();
}

// (2) <<, >> 연산자 함수를 Matrix의 프렌드 함수로 구현하라.
#include <iostream>
using namespace std;

class Matrix {
    int num[4];
public:
    Matrix();
    Matrix(int a, int b, int c, int d);
    void show();

    // 연산자 함수 - friend
    friend void operator>> (Matrix a, int* x);
    friend void operator<< (Matrix& b, int* y);
};

Matrix::Matrix() {
    for (int i = 0; i < 4; i++)
        num[i] = 0;
}
Matrix::Matrix(int a, int b, int c, int d) {
    num[0] = a; num[1] = b; num[2] = c; num[3] = d;
}
void Matrix::show() {
    cout << "Matrix = { ";
    for (int i = 0; i < 4; i++) {
        cout << num[i] << ' ';
    }
    cout << '}' << endl;
}

// 연산자 함수 구현 - 외부 함수
void operator>> (Matrix a, int* x) { // int 배열 첫 번째 요소의 주소를 받음 (대신 int x[]도 가능)
    for (int i = 0; i < 4; i++) {
        x[i] = a.num[i];
    }
}
void operator<< (Matrix& b, int* y) {
    for (int i = 0; i < 4; i++) {
        b.num[i] = y[i];
    }
}
int main() {
    Matrix a(4, 3, 2, 1), b;
    int x[4], y[4] = { 1,2,3,4 }; // 2차원 행렬의 4 개의 원소 값 
    a >> x; // a의 각 원소를 배열 x에 복사. x[]는 {4,3,2,1} 
    b << y; // 배열 y의 원소 값을 b의 각 원소에 설정 

    for (int i = 0; i < 4; i++) cout << x[i] << ' '; // x[] 출력 
    cout << endl;
    b.show();
}