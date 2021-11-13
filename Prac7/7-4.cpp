// 7-4

//다음 연산을 통해 책의 제목을 사전 순으로 비교하고자 한다.

//< 연산자를 작성하라.

#include <iostream>
#include <string> // string 클래스 사용!
using namespace std;

class Book {
    string title;
    int price, pages;
public:
    Book(string title = "", int price = 0, int pages = 0) {
        this->title = title; this->price = price; this->pages = pages;
    }
    void show() {
        cout << title << " " << price << "원 " << pages << " 페이지" << endl;
    }
    string getTitle() {
        return title;
    }

    // b는 string, a는 Book
    friend bool operator< (string b, Book a); // **
};

// 외부 함수 구현 
bool operator< (string b, Book a) {
    if (b < a.title) // private 멤버인 title에 접근하기 위해 클래스 내 friend 키워드 선언함 **
        return true; // 문자열 b 앞에 오면 true 
    return false;
}
// 'b < a.title' 대신 'b.compare(a.title) < 0' 도 가능

int main() {
    Book a("청춘", 2000, 300);
    string b;
    cout << "책 이름을 입력하세요>>";
    getline(cin, b); // 키보드로부터 문자열로 책 이름을 입력 받음 (string 클래스)
    if (b < a) 
        cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!" << endl;
}