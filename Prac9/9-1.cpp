//9-1
// 다음은 단위를 변환하는 추상 클래스 Converter 이다.

// Converter 클래스를 상속받아 
// 달러를 원화로 환산하는 WonToDollar 클래스를 작성하라. 

#include <iostream>
using namespace std;

class Converter { // 추상클래스
protected:
    double ratio;
    virtual double convert(double src) = 0; // src를 다른 단위로 변환한다. (순수가상함수)
    virtual string getSourceString() = 0; // src 단위 명칭
    virtual string getDestString() = 0; // dest 단위 명칭
public:
    Converter(double ratio) { this->ratio = ratio; }
    void run() {
        double src;
        cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
        cout << getSourceString() << "을 입력하세요>> ";
        cin >> src;
        cout << "변한 결과 : " << convert(src) << getDestString() << endl;
    }
};

class WonToDollar : public Converter { 
protected:
    virtual double convert(double src) { // 오버라이딩
        return src/ratio; 
    }
    virtual string getSourceString() { return "원"; }
    virtual string getDestString() { return "달러"; }
public:
    WonToDollar(double ratio) : Converter(ratio) { }
};

int main() {
    WonToDollar wtd(1191.74); // 1달러에 1191.74원
    wtd.run();
}