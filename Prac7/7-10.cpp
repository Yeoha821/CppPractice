// 7-10
// 통계를 내는 Statistics 클래스를 만들려고 한다.
// 데이터는 Statistics 클래스 내부에 int 배열을 동적으로 할당받아 유지한다.
// 다음과 같은 연산이 잘 이루어지도록 Statistics 클래스와 
// !, >>, <<, ~ 연산자 함수를 작성하라.

#include <iostream>
using namespace std;

class Statistics {
    int* p;
    int num; // 배열 원소 개수
public:
    Statistics() { p = new int[10]; }
    ~Statistics() { delete[] p; }

    // !, <<, ~, >> 연산자 함수 
    bool operator! ();
    Statistics& operator<< (int* x);
    Statistics& operator<< (int n);
    void operator~ ();
    void operator>> (float& avg);
};

bool Statistics::operator!() {
    if (p == NULL && this->num == 0) return true;
    return false;
}
Statistics& Statistics::operator<< (int* x) { // stat<< 이므로 반환형(참조) 있어야 함
    for (int i = 0; i < sizeof(x); i++) {
        this->p[i] = x[i];
        this->num++;
    }
    return *this;
}
Statistics& Statistics::operator<< (int n) { // stat<<
    this->p[this->num++] = n; // num 자리에 n값 넣어주고 num++
    return *this;
}
void Statistics::operator~ () {
    for (int i = 0; i < this->num; i++) {
        cout << this->p[i] << ' ';
    }
    cout << endl;
}
void Statistics::operator>> (float& avg) { // >>avg 이므로 avg를 참조형 매개변수로 받아서 변경
    int sum = 0;
    for (int i = 0; i < this->num; i++) {
        sum += this->p[i];
    }
    avg = (float)sum / this->num;
}
int main() {
    Statistics stat;
    if (!stat) cout << "현재 통계 데이타가 없습니다." << endl;

    int x[5];
    cout << "5 개의 정수를 입력하라>>";
    for (int i = 0; i < 5; i++) cin >> x[i]; // x[i]에 정수 입력 

    for (int i = 0; i < 5; i++) stat << x[i]; // x[i] 값을 통계 객체에 삽입한다. 
    stat << 100 << 200; // 100, 200을 통계 객체에 삽입한다. 
    ~stat; // 통계 데이터를 모두 출력한다. 

    float avg; // float으로 임의 변경
    stat >> avg; // 통계 객체로부터 평균을 받는다. 
    cout << "avg=" << avg << endl;  // 평균을 출력한다. 
}
