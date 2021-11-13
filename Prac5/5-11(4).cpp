// 5-11(4) 
// 
// (4) 문제 (3)에서 실행 오류가 발생하는 원인은 Book 클래스에서 
// C-스트링(char* title) 방식으로 문자열을 다루었기 때문이다.

#include <iostream>
using namespace std;

class Book {
    string title; // 제목 문자열 -> string 클래스 사용
    int price; // 가격 
public:
    Book(string title, int price);
    void set(string title, int price);
    void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(string title, int price) {
    this->price = price;
    this->title = title;
}

void Book::set(string title, int price) {
    this->price = price;
    this->title = title;
}

int main() {
    Book cpp("명품 C++", 10000);
    Book java = cpp; 
    java.set("명품자바", 12000);
    cpp.show();
    java.show();
}