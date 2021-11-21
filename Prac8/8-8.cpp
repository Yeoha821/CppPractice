// 8-8
// 다음 그림과 같은 상속 구조를 갖는 클래스를 설계한다.

/*모든 프린터는 모델명(model), 제조사(manufacturer), 인쇄 매수(printedCount), 
인쇄 종이 잔량(availableCount)을 나타내는 정보와 print(int pages) 
멤버 함수를 가지며, print()가 호출할 때마다 pages 매의 용지를 사용한다. 
잉크젯 프린터는 잉크 잔량(availableInk) 정보와 printInkJet(int pages) 
멤버 함수를 추가적으로 가지며, 레이저 프린터는 토너 잔량(availableToner) 
정보와 역시 printLaser(int pages) 멤버 함수를 추가적으로 가진다. 
각 클래스에 적절한 접근 지정으로 멤버 변수와 함수, 생성자, 소멸자를 작성하고, 
다음과 같이 실행되도록 전체 프로그램을 완성하라. 

잉크젯 프린터 객체와 레이저 프린터 객체를 각각 하나만 동적 생성하여 시작한다.*/

#include <iostream>
using namespace std;

// 프린터
class Printer {
	string model, manufacturer; // 모델명과 제조사명
	int printedCount, availCount; // 인쇄 매수, 종이 잔량
protected:
	string getModel() { return model; }
	string getManufacturer() { return manufacturer; }
	int getAvailCount() { return availCount; }

	Printer(string model, string manufacturer, int availCount) {
		this->model = model; 
		this->manufacturer = manufacturer; 
		this->printedCount = 0;
		this->availCount = availCount;
	}
	bool print(int pages);
public:
	int getPrintedCount() { return printedCount; }
};
bool Printer::print(int pages) {
	// 매수 잔량 조사
	if (pages > availCount) { // 용지 부족
		cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;  // 결과
		return false; 
	}
	printedCount += pages; // 인쇄 매수 증가
	availCount -= pages; // 용지 소비
}

// 잉크젯 프린터
class InkJetPrinter : public Printer { // 가상 상속 선언
	int availInk; // 잉크 잔량
public:
	InkJetPrinter(string model, string manufacturer, int availCount, int availInk) 
		: Printer(model, manufacturer, availCount) {
		this->availInk = availInk;
	}
	bool printInkJet(int pages);
	void show() { 
		cout << "잉크젯: " << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailCount()
			<< "장, 남은 잉크 " << availInk << endl;
	}
};
bool InkJetPrinter::printInkJet(int pages) {
	// 잉크 잔량 조사
	if (pages > availInk) { // 잉크 부족
		cout << "잉크가 부족하여 프린트 할 수 없습니다." << endl;  // 결과
		return false; // 함수 종료
	}
	if (print(pages)) { // print 호출(여기서 용지 잔량 조사)
		// 용지가 부족하지 않은 경우
		availInk -= pages; // 잉크 소비
		cout << "프린트 하였습니다." << endl;  // 결과
	}
	else {
		return false;
	}
}

// 레이저 프린터
class LaserPrinter : public Printer {
	int availToner; // 토너 잔량
public:
	LaserPrinter(string model, string manufacturer, int availCount, int availToner)
		: Printer(model, manufacturer, availCount) {
		this->availToner = availToner;
	}
	bool printLaser(int pages);
	void show() { 
		cout << "레이저: " << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailCount()
			<< "장, 남은 토너 " << availToner << endl;
	}
};
bool LaserPrinter::printLaser(int pages) {
	// 토너 잔량 조사
	if (pages > availToner) { // 토너 부족
		cout << "토너가 부족하여 프린트 할 수 없습니다." << endl;  // 결과
		return false; // 함수 종료
	}
	if (print(pages)) { // print 호출(여기서 용지 잔량 조사)
		// 용지가 부족하지 않은 경우
		availToner -= pages; // 토너 소비
		cout << "프린트 하였습니다." << endl; // 결과
	}
	else {
		return false;
	}
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
			inkjet->printInkJet(pages); // 잉크젯 프린트 실행
			// 위 함수의 반환형도 bool 형이기 때문에 새로운 조건문 임의 추가 가능
		}
		else if (ch == 2) {
			laser->printLaser(pages); // 레이저 프린트 실행
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
			cout << "프린터를 종료합니다." << endl;
			break; // while 반복문 종료
		}
		else {
			cout << "지원하지 않는 기능입니다. 프린터를 종료합니다." << endl; // 예외
			break;
		}
	}
	
	cout << "\n\n총 인쇄된 매수\n잉크젯 프린터: " << inkjet->getPrintedCount()
		<< "장\n레이저 프린터: " << laser->getPrintedCount() << "장" << endl;

	delete inkjet;
	delete laser;
}