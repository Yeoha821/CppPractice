// 5-11(1~3)
// 책의 이름과 가격을 저장하는 다음 Book 클래스에 대해 물음에 답하여라.

// (1) Book 클래스의 생성자, 소멸자, set() 함수를 작성하라. set() 함수는 멤버 변수 title에 할당된 메모리가 있으면 먼저 반환한다. 그러고 나서 새로운 메모리를 할당받고 이곳에 매개 변수로 전달받은 책이름을 저장한다.

// (2) 컴파일러가 삽입하는 디폴트 복사 생성자 코드는 무엇인가?
/*Book::Book(const Book& b){
	this->title = b.title;
	this->price = b.price;
}*/

// (3) 디폴트 복사 생성자만 있을 때 아래 main() 함수는 실행 오류가 발생한다.
// 실행 오류가 발생하는 원인은 Book 클래스에서 
// C-스트링(char* title) 방식으로 문자열을 다루었기 때문.
// 복사 생성자를 작성하지 말고, 문자열을 string 클래스를 사용하여 코드를 알맞게 수정

#include <iostream>
using namespace std;

class Book {
    char* title; // 제목 문자열 
    int price; // 가격 
public:
    Book(const Book& b); // (3) 깊은 복사 생성자 
    Book(const char* title, int price);
    ~Book();
    void set(char* title, int price);
    void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const Book& b) { // (3) 깊은 복사 생성자 작성
    this->price = b.price;
    int size = strlen(b.title) + 1;
    this->title = new char[size];
    strcpy(this->title, b.title);
}

Book::Book(const char* title, int price) {
    this->price = price;
    int size = strlen(title) + 1;
    this->title = new char[size];
    strcpy(this->title, title);
}
Book::~Book() {
    delete[] title;
}
void Book::set(char* title, int price) {
    if (this->title) 
        delete[] this->title;
   
    this->price = price;
    int size = strlen(title) + 1;
    this->title = new char[size];
    strcpy(this->title, title);
}

int main() {
    Book cpp("명품 C++", 10000);
    Book java = cpp; // 복사 생성자 호출됨 
    java.set("명품자바", 12000); 
    cpp.show();
    java.show();
}
