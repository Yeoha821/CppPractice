// 5-12

// 다음은 학과를 나타내는 Dept 클래스와 이를 활용하는 main()을 보여 준다.

class Dept {
    int size; // scores 배열의 크기 
    int* scores; // 동적 할당 받을 정수 배열의 주소 
public:
    Dept(int size) { // 생성자 
        this->size = size;
        scores = new int[size];
    }
    Dept(const Dept& dept); // 복사 생성자 
    ~Dept(); // 소멸자 
    int getSize() { return size; }
    void read(); // size 만큼 키보드에서 정수를 읽어 scores 배열에 저장 
    bool isOver60(int index); // index의 학생의 성적이 60보다 크면 true 리턴 
};

Dept::Dept(const Dept& dept) { // 복사 생성자 구현
	this->size = dept.size;
	scores = new int[size]; // scores를 위한 공간 할당
	for (int i = 0; i < size; i++) {
		scores[i] = dept.scores[i]; // 요소 하나씩 복사
	}
}
Dept::~Dept() {
	if(scores) // 만일 scores에 동적 할당된 배열이 있으면
		delete [] scores; // scores 메모리 반환
}
void Dept::read() {
	cout << size << "개 점수 입력>> ";
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}
bool Dept::isOver60(int index) {
	if (scores[index] >= 60) return true;
	else return false;
}


int countPass(Dept dept) { // (2) 값에 의한 호출 -> 생성자 대신 복사생성자 호출
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}
// (2) 복사 생성자(=깊은 복사)가 없으면 실행 오류가 발생하는 이유
// Dept 객체는 포인터를 가지고 있고,
// 디폴트 복사 생성자로 복사 생성(=얕은 복사)된 dept 객체의 scores는 
// com 객체와 메모리 상에서 같은 주소를 공유한다.
// scores의 반환은 dept 객체가 소멸할 때 일어나고, 
// 이미 반환한 곳을 com 객체에서 다시 반환할 수 없으므로 실행 오류 발생한다.

int main() {
    Dept com(10); // 총 10명이 있는 학과 com 
    com.read();  // 총 10명의 학생들의 성적을 키보드로부터 읽어 scores 배열에 저장 
    int n = countPass(com); // com 학과에 60점 이상으로 통과한 학생의 수를 리턴 
    cout << "60점 이상은 " << n << "명";
}

//(3) 복사 생성자를 제거해도 오류가 발생하지 않게 하려면 어느 부분을 수정해야 할까?
// 값에 의한 호출을 참조에 의한 호출로 변경하면 해결된다.
// int countPass(Dept dept) -> int countPass(Dept &dept)

// 이유:
// 값에 의한 호출은 새로운 공간을 할당하게 하지만, 
// 참조에 의한 호출(Call-by-Reference)은 실매개변수(=com 객체)가 그대로 넘어가는 것이기 때문에
// 이중 반환을 할 필요가 없다.