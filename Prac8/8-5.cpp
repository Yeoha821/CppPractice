// 8-5 
//문제 5~6에 적용되는 BaseArray 클래스는 다음과 같다.
//BaseArray를 상속받아 큐처럼 작동하는 MyQueue 클래스를 작성하라.
//MyQueue를 활용하는 사례는 다음과 같다.
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

// 원형 큐 사용
// 큐의 특성인 선입선출을 잘 고려하여 코드를 작성
class MyQueue : public BaseArray { 
    int front; // 첫 번째 요소로부터 시계 방향으로 하나 앞
    int rear; // 마지막 요소
public:
    MyQueue(int capacity) : BaseArray(capacity) { // 기본클래스의 생성자를 명시함
        front = rear = 0; // 초기화
    }
    void enqueue(int n) { // 삽입
        rear = (rear + 1) % getCapacity();
        if (front == rear) { // 큐에 데이터가 한 공간 빼고 다 차있을 경우 
            cout << "Queue is full\n";
            exit(1);
        }
        put(rear, n); // 실제로 mem[rear] = n 을 실행함
    }
    int dequeue() { // 추출
        if (length() == 0) {
            cout << "Queue is empty\n"; 
            exit(1);
        }
        front = (front + 1) % getCapacity();
        return get(front);  // mem[front] 꺼냄
    }
    int capacity() { return getCapacity(); }
    int length() { return abs(getCapacity() + rear - front) % getCapacity(); }
};

int main() {
    MyQueue mQ(100);
    int n;
    cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        mQ.enqueue(n); // 큐에 삽입 
    }
    cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
    cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
    while (mQ.length() != 0) {
        cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력 
    }
    cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;

    // queue 기능 test 코드
    /*for (int i = 0; i < 80; i++)
        mQ.enqueue(i);
    for (int i = 0; i < 50; i++)
        cout << mQ.dequeue() << ' ';
    cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
    for (int i = 80; i < 100; i++)
        mQ.enqueue(i);
    for (int i = 0; i < 30; i++)
        cout << mQ.dequeue() << ' ';
    cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;*/
}