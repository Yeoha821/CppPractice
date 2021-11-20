// 8-6
// BaseArray 클래스를 상속받아 스택으로 작동하는 MyStack 클래스를 작성하라

#include <iostream>
using namespace std;

class BaseArray {
    int capacity; // 배열의 크기
    int* mem; // 정수 배열을 만들기 위한 메모리의 포인터
protected: // 생성자가 protected 
    BaseArray(int capacity = 100) {
        this->capacity = capacity; mem = new int[capacity];
    }
    ~BaseArray() { delete[] mem; }
    void put(int index, int val) { mem[index] = val; }
    int get(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {
    int tos; // 현재 가리키고 있는 위치
public:
    MyStack(int capacity) : BaseArray(capacity) {
        tos = -1;
    }
    void push(int n) {
        tos++;
        if (tos >= getCapacity()) {
            cout << "Stack is full\n";
            exit(1);
        }
        put(tos, n);
    }
    int pop() {
        if (tos < 0) {
            cout << "Stack is empty\n";
            exit(1);
        }
        return get(tos--);
    }
    int capacity() { return getCapacity(); }
    int length() { return tos + 1; } // tos는 Index임
    
};
int main() {
    MyStack mStack(100);
    int n;
    cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
    for (int i = 0; i < 5; ++i) {
        cin >> n;
        mStack.push(n); // 스택에 푸시
    }
    cout << "스택 용량:" << mStack.capacity() << ", 스택 크기:" << mStack.length() << endl;
    cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
    while (mStack.length() != 0) {
        cout << mStack.pop() << ' '; // 스택에서 팝
    }
    cout << endl << "스택의 현재크기 : " << mStack.length() << endl;

    // Stack 기능 test 코드
    //cout << "Stack 기능 Test Code" << endl;
    //for (int i = 0; i < 90; i++) // 90개 push
    //    mStack.push(i);
    //for (int i = 0; i < 20; i++) // 20개 pop
    //    cout << mStack.pop() << ' ';
    //cout << endl << "스택의 현재크기 : " << mStack.length() << endl;

    //for (int i = 90; i < 110; i++)
    //    mStack.push(i); // 20개 push
    //cout << endl << "스택의 현재크기 : " << mStack.length() << endl;

    //int i = 110;
    //while (mStack.length() <= mStack.capacity()) { 
    //    cout << mStack.length() << ' ';
    //    mStack.push(i); // 30개 push -> stack full 
    //    i++;
    //}
    ///*for (int i = 0; i <= 100; i++) {
    //    cout << mStack.pop() << ' '; // 100개 pop -> stack empty
    //}*/
}