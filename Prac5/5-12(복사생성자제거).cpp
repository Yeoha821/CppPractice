// 5-12 복사 생성자를 제거한 코드

//(3) 복사 생성자를 제거해도 오류가 발생하지 않게 하려면 어느 부분을 수정해야 할까?
// 값에 의한 호출을 참조에 의한 호출로 변경하면 해결된다.
// int countPass(Dept dept) -> int countPass(Dept &dept)

// 이유:
// 값에 의한 호출은 새로운 공간을 할당하게 하지만, 
// 참조에 의한 호출(Call-by-Reference)은 실매개변수(=com 객체)가 그대로 넘어가는 것이기 때문에
// 이중 반환을 할 필요가 없다.

// ~Dept.h~ 
class Dept {
    int size; // scores 배열의 크기 
    int* scores; // 동적 할당 받을 정수 배열의 주소 
public:
    Dept(int size) { // 생성자 
        this->size = size;
        scores = new int[size];
    }
    //Dept(const Dept& dept); // 복사 생성자 제거
    ~Dept(); // 소멸자 
    int getSize() { return size; }
    void read(); // size 만큼 키보드에서 정수를 읽어 scores 배열에 저장 
    bool isOver60(int index); // index의 학생의 성적이 60보다 크면 true 리턴 
};

// ~Dept.cpp~
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

// ~main.cpp~
int countPass(Dept &dept) {  // 참조에 의한 호출로 변경(문제 적용)
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
    Dept com(10); // 총 10명이 있는 학과 com 
    com.read();  // 총 10명의 학생들의 성적을 키보드로부터 읽어 scores 배열에 저장 
    int n = countPass(com); // com 학과에 60점 이상으로 통과한 학생의 수를 리턴 
    cout << "60점 이상은 " << n << "명";
}