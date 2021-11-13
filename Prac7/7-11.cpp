// 7-11
//스택 클래스 Stack을 만들고 푸시(push)용으로 << 연산자를, 
//팝(pop)을 위해 >> 연산자를, 
//비어 있는 스택인지를 알기 위해 ! 연산자를 작성하라.

#include <iostream>
using namespace std;

class Stack {
    int* p;
    int tos; // stack의 꼭대기를 가리키는 인덱스
public: 
    Stack() {
        p = new int[10];
        tos = -1;
    }
    ~Stack() {
        delete[] p;
    }
    bool operator! ();
    Stack& operator<< (int n);
    void operator>> (int& x);
};

bool Stack::operator! () { // stack empty 판별 
    if (p == NULL || tos == -1) return true;
    return false;
}
Stack& Stack::operator<< (int n) { // push 기능을 하는 연산자(참조 리턴)
    p[++tos] = n; // tos++; this->p[tos]=n;
    return *this;
}
void Stack::operator>> (int& x) { // pop 기능을 하는 연산자
    x = p[tos--]; // x=this->p[tos]; tos--;
}

int main() {
    Stack stack;
    stack << 3 << 5 << 10; // 3,5,10 순서대로 push 
    while (true) {
        if (!stack) break; //stack empty
        int x;
        stack >> x; //stack의 top에 있는 정수 pop 
        cout << x << ' ';
    }
    cout << endl;
}