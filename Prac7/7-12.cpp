// 7-12
// 정수 배열을 항상 증가순으로 유지하는 SortedArray 클래스를 작성하려고 한다. 
// 아래의 main 함수가 작동할 만큼만 
// SortedArray 클래스를 작성하고 +와 =연산자도 작성하라.

#include <iostream>
using namespace std;

class SortedArray {
	int size; // 현재 배열의 크기
	int* p; // 정수 배열에 대한 포인터
	void sort(); // 정수 배열을 오름차순으로 정렬
public:
	SortedArray(); // p는 Null로 size는 0으로 초기화
	SortedArray(SortedArray& src); // 복사 생성자
	SortedArray(int p[], int size); // 생성자, 정수 배열과 크기를 전달받음
	~SortedArray(); // 소멸자
	SortedArray operator+ (SortedArray& op2);
	SortedArray& operator= (const SortedArray& op2); // 현재 배열에 op2 배열을 복사
	void show(); // 배열의 원소 출력
};

// 생성자
SortedArray::SortedArray() { 
	p = NULL; 
	size = 0;
}
SortedArray::SortedArray(int p[], int size) {
	this->p = new int[size];
	this->size = size;
	for (int i = 0; i < size; i++) {
		this->p[i] = p[i];
	}
}
SortedArray::SortedArray(SortedArray& src) { // 깊은 복사 생성자
	this->size = src.size;
	this->p = new int[src.size];
	for (int i = 0; i < src.size; i++) {
		this->p[i] = src.p[i]; // 요소 복사
	}
}
// 소멸자
SortedArray::~SortedArray() {
	if (p != NULL) delete[] p; 
}

// 멤버 함수
void SortedArray::sort() { // 정수 배열을 오름차순으로 정렬
	int tmp;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (p[i] > p[j]) {
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}
void SortedArray::show() { // 출력
	sort();
	cout << "배열 출력 : ";
	for (int i = 0; i < size; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;
}

// 연산자 함수
SortedArray SortedArray::operator+ (SortedArray& op2) { 
	SortedArray c;
	c.size = this->size + op2.size; // 배열 크기 합치기
	c.p = new int[c.size]; // 새로운 크기로 동적할당

	int index = 0;
	for (int i = 0; i < this->size; i++) { // 각 요소 복사하기
		c.p[index++] = this->p[i];
	}
	for (int i = 0; i < op2.size; i++) {
		c.p[index++] = op2.p[i];
	}
	return c;
}
SortedArray& SortedArray::operator= (const SortedArray& op2) {
	delete[] this->p; // 현재 배열은 반환
	this->size = op2.size; // 배열 크기 재할당
	this->p = new int[op2.size]; // 동적배열 재할당
	for (int i = 0; i < op2.size; i++) {
		this->p[i] = op2.p[i]; // 요소 복사
	}
	return *this;
}

// 메인
int main() {
	int n[] = { 2,20,6 };
	int m[] = { 10,7,8,30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b; // +, = 연산자 작성 필요
	// + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요

	a.show();
	b.show();
	c.show();
	cout << endl;
}
