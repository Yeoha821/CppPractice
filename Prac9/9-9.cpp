//9-9
// 다음 그림과 같은 상속 구조를 갖는 클래스를 설계한다.
/*모든 프린터는 모델명(model), 제조사(manufacturer), 인쇄 매수(printedConut), 
인쇄 종이 잔량(availableCount)을 나타내는 정보를 가진다. 
print(int pages) 함수와 show() 함수는 가상 함수로 구현하라. 
print(int pages)는 pages 만큼 프린트하는 함수이고, 
show() 함수는 현재프린트의 모델, 제조사, 인쇄 매수, 인쇄 종이 잔량 등을 출력하는 함수이다.*/

/*잉크젯 프린터는 잉크 잔량(availableInk) 정보를 추가적으로 가지며, 
레이저 프린터는 토너 잔량(avialableToner) 정보를 추가적으로 가진다. 
이들의 print(int pages) 멤버 함수는 프린터 타입에 맞게 구현하라. 
각클래스를 설계 구현하고 다음과 같이 실행되도록 전체 프로그램을 완성하라. 
InkJetPrinter 객체와 LaserPrinter 객체를 하나만 동적으로 생성하여 시작한다.*/

#include <iostream>
using namespace std;
// **: 8-8에서 가상함수 개념 적용한 코드

// 프린터
class Printer {
	string model, manufacturer; // 모델명과 제조사명
	int printedCount, availCount; // 인쇄 매수, 종이 잔량
protected:
	Printer(string model, string manufacturer, int availCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->printedCount = 0;
		this->availCount = availCount;
	}
	string getModel() { return model; }
	string getManufacturer() { return manufacturer; }
	int getAvailCount() { return availCount; }

	void setAvailCount(int pages) { availCount -= pages; } // **
	void setPrintedCount(int pages) { printedCount += pages; }

	virtual bool print(int pages) = 0; // ** 순수가상함수 
	virtual void show() = 0;
public:
	int getPrintedCount() { return printedCount; } // 총 인쇄된 매수
};

// 잉크젯 프린터
class InkJetPrinter : public Printer { // 가상 상속 선언
	int availInk; // 잉크 잔량
public:
	InkJetPrinter(string model, string manufacturer, int availCount, int availInk)
		: Printer(model, manufacturer, availCount) {
		this->availInk = availInk;
	}
	bool print(int pages); // ** 오버라이딩
	void show() {
		cout << "잉크젯: " << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailCount()
			<< "장, 남은 잉크 " << availInk << endl;
	}
};
// 레이저 프린터
class LaserPrinter : public Printer {
	int availToner; // 토너 잔량
public:
	LaserPrinter(string model, string manufacturer, int availCount, int availToner)
		: Printer(model, manufacturer, availCount) {
		this->availToner = availToner;
	}
	bool print(int pages);
	void show() {
		cout << "레이저: " << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailCount()
			<< "장, 남은 토너 " << availToner << endl;
	}
};

bool InkJetPrinter::print(int pages) {
	// 용지 잔량 조사 **
	if (pages > getAvailCount()) {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		return false;
	}
	// 잉크 잔량 조사
	if (pages > availInk) { // 잉크 부족
		cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;  // 결과
		return false; // 함수 종료
	}

	// 용지와 잉크가 부족하지 않은 경우
	setPrintedCount(pages); // 인쇄된 매수 update
	setAvailCount(pages); // 용지 소비 **
	availInk -= pages; // 잉크 소비
	cout << "프린트 하였습니다." << endl;  // 결과
	return true;
}
bool LaserPrinter::print(int pages) {
	// 용지 잔량 조사 **
	if (pages > getAvailCount()) {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		return false;
	}
	// 토너 잔량 조사
	if (pages > availToner) { // 토너 부족
		cout << "토너가 부족하여 프린트할 수 없습니다." << endl;  // 결과
		return false; // 함수 종료
	}

	// 용지와 토너가 부족하지 않은 경우
	setPrintedCount(pages); // 인쇄된 매수 update
	setAvailCount(pages); // 용지 소비 **
	availToner -= pages; // 토너 소비
	cout << "프린트 하였습니다." << endl; // 결과
	return true;
}

int main() {
	// 동적 객체 생성(문제에 주어진 정보로 초기화)
	InkJetPrinter* inkjet = new InkJetPrinter("Offircejet V40", "Hp", 5, 10); // 잉크젯 프린터
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20); // 레이저 프린터

	int ch, pages;
	char answer;

	// 1단계-처음 상태 출력
	cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
	inkjet->show(); laser->show();

	// 2단계-프린터/매수 입력
	// 매수에 따라 종이와 잉크(혹은 토너)의 잔량이 줄어든다
	while (1) {
		cout << "\n프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> ch >> pages;

		// 3단계-프린트 결과 출력
		if (ch == 1) { // 프린터 선택 
			inkjet->print(pages); // 잉크젯 프린트 실행 **
			// 위 함수의 반환형도 bool 형이기 때문에 새로운 조건문 임의 추가 가능
		}
		else if (ch == 2) {
			laser->print(pages); // 레이저 프린트 실행 **
		}
		else {
			cout << "(1:잉크젯, 2:레이저)가 아닌 값이 입력되었습니다. 다시 입력해 주세요."; // 예외
			continue; // while 반복문으로 다시 돌아감
		}

		// 4단계-현재 상태 출력
		inkjet->show(); laser->show();

		// 5단계-프린트 추가 실행 여부 입력
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> answer;
		if (answer == 'y') {
			continue; // while 반복문 처음으로 돌아가기
		}
		else if (answer == 'n') {
			cout << "\n\n프린터를 종료합니다." << endl;
			break; // while 반복문 종료
		}
		else {
			cout << "지원하지 않는 기능입니다. 프린터를 종료합니다." << endl; // 예외
			break;
		}
	}

	cout << "총 인쇄된 매수\n잉크젯 프린터: " << inkjet->getPrintedCount()
		<< "장\n레이저 프린터: " << laser->getPrintedCount() << "장" << endl;

	delete inkjet;
	delete laser;
}