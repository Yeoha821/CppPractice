// 7-1
// Book 객체에 대해 다음 연산을 하고자 한다.
/*
Book a("청춘", 20000, 300) , b("미래", 30000, 500);
a += 500; // 책 a의 가격 500원 증가
b -= 500; // 책 b의 가격 500원 감소
a.show();
b.show();
*/

//(1) +=, -= 연산자 함수를 Book 클래스의 멤버 함수로 구현하라.
#include <iostream>
using namespace std;

class Book{
    string title;
    int price, pages;
public:
    Book(string title="", int price=0, int pages=0){
        this->title = title; this->price = price; this->pages = pages;
    }
    void show() {
        cout << title << " " << price << "원 " << pages << " 페이지" << endl;
    }
    string getTitle() {
        return title;
    }

    Book& operator+= (int a); // += 연산자 함수 선언
    Book& operator-= (int a);
};

Book& Book::operator+= (int a){ // 구현
	price += a;
	return *this; // this 포인터가 가리키는 곳 반환
}
Book& Book::operator-= (int a){
	price-= a;
	return *this;
}

int main(){
	Book a("청춘", 20000, 300) , b("미래", 30000, 500);
	a += 500; // 책 a의 가격 500원 증가
	b -= 500; // 책 b의 가격 500원 감소
	a.show();
	b.show();
}

//(2) +=, -= 연산자 함수를 Book 클래스 외부 함수로 구현하라.

class Book{
    string title;
    int price, pages;
public:
    Book(string title="", int price=0, int pages=0){
        this->title = title; this->price = price; this->pages = pages;
    }
    void show() {
        cout << title << " " << price << "원 " << pages << " 페이지" << endl;
    }
    string getTitle() {
        return title;
    }

    friend Book operator+= (Book& b, int a);
    friend Book operator-= (Book& b, int a);
};

// 외부 함수 구현
Book operator+= (Book& b, int a){
	b.price += a; // private 멤버인 price에 접근하기 위해 friend 사용
	return b;
}
Book operator-= (Book& b, int a){
	b.price -= a;
	return b;
}

int main(){
	Book a("청춘", 20000, 300) , b("미래", 30000, 500);
	a += 500; // 책 a의 가격 500원 증가
	b -= 500; // 책 b의 가격 500원 감소
	a.show();
	b.show();
}