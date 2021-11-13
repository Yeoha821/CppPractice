// 7-6
// 2차원 행렬을 추상화한 Matrix 클래스를 작성하고, 
// show() 멤버 함수와 다음 연산이 가능하도록 연산자를 모두 구현하라.

// (1)연산자 함수를 Matrix의 멤버 함수로 구현하라.
#include <iostream>
using namespace std;

class Matrix {
    int num[4];
public:
    Matrix();
    Matrix(int a, int b, int c, int d);
    void show();

    // 연산자 함수
    Matrix operator+(Matrix b);
    Matrix& operator+=(Matrix b);
    bool operator==(Matrix c);
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
// 연산자 함수 구현
Matrix Matrix::operator+(Matrix b) {
    Matrix c;
    for (int i = 0; i < 4; i++) {
        c.num[i] = this->num[i] + b.num[i];
    }
    return c;
}
Matrix& Matrix::operator+=(Matrix b) {
    for (int i = 0; i < 4; i++) {
        this->num[i] += b.num[i];
    }
    return *this;
}
bool Matrix::operator==(Matrix c) {
    for (int i = 0; i < 4; i++) {
        if (this->num[i] != c.num[i])
            return false;
    }
    return true;
}

int main() {
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
    c = a + b;
    a += b;
    a.show(); b.show(); c.show();
    if (a == c)
        cout << "a and c are the same" << endl;
}
//(2)연산자 함수를 Matrix의 프렌드 함수로 구현하라 

#include <iostream>
using namespace std;

class Matrix {
    int num[4];
public:
    Matrix();
    Matrix(int a, int b, int c, int d);
    void show();

    // 연산자 함수 - friend
    friend Matrix operator+(Matrix a, Matrix b);
    friend void operator+=(Matrix& a, Matrix b);
    friend bool operator==(Matrix b, Matrix c);
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

// 연산자 함수 - 외부 함수로 구현 
Matrix operator+(Matrix a, Matrix b) {
    Matrix c;
    for (int i = 0; i < 4; i++) {
        c.num[i] = a.num[i] + b.num[i];
    }
    return c;
}
void operator+=(Matrix& a, Matrix b) {
    for (int i = 0; i < 4; i++) {
        a.num[i] += b.num[i];
    }
}
bool operator==(Matrix b, Matrix c) {
    for (int i = 0; i < 4; i++) {
        if (b.num[i] != c.num[i])
            return false;
    }
    return true;
}

int main() {
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
    c = a + b;
    a += b;
    a.show(); b.show(); c.show();
    if (a == c)
        cout << "a and c are the same" << endl;
}