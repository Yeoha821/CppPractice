//9-6
// 다음 AbstractSack 은 정수 스택 클래스로서 추상 클래스이다.
//이를 상속받아 정수를 푸시, 팝하는 
//IntStack 클래스를 만들고 사용 사례를 보여라.

#include <iostream>
using namespace std;

class AbstractStack { // 추상 클래스
public:
    virtual bool push(int n) = 0; // 스택에 n을 푸시한다. 스택이 full이면 false 리턴
    virtual bool pop(int& n) = 0; // 스택에서 팝한 정수를 n에 저장하고 스택이 empty이면 false 리턴
    virtual int size() = 0; // 현재 스택에 저장된 정수의 개수 리턴
};

class IntStack : public AbstractStack { 
    int* p; 
    int tos; // 스택의 맨 위를 가리킴
    int stackSize;
public:
    IntStack(int size) {
        stackSize = size;
        p = new int[stackSize];
        tos = -1;
    }
    ~IntStack() {
        delete[] p;
    }
    bool push(int n); // 오버라이딩
    bool pop(int& n);
    int size();
};
bool IntStack::push(int n) {
    if (tos >= stackSize - 1) {
        cout << "stack is full..." << endl; 
        return false;
    }
    cout << "push > "; // push 성공 알림
    p[++tos] = n;
    return true;
}
bool IntStack::pop(int& n) {
    if (tos < 0) {
        cout << "\nstack is empty..." << endl;
        return false;
    }
    n = p[tos--];
    return true;
}
int IntStack::size() { // 스택에 들어있는 정수 개수
    return tos + 1;
}

int main() {
    IntStack s(10);

    int i = 0;
    while (s.push(i)) i++;

    cout << "\n현재 스택에 들어있는 정수 개수: " << s.size() << endl;

    int n;
    cout << "현재 스택에 들어있는 정수: ";
    while (s.pop(n)) cout << n << " ";
}