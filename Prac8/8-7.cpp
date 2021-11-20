//7. 아래와 같은 BaseMemory 클래스를 상속받는 
// ROM(Read Only Memory), RAM 클래스를 작성하라. 
// BaseMemeory에 필요한 코드를 수정 추가하여 적절히 완성하라.

/*ROM은 읽기 전용 메모리이므로 작동 중에 값을 쓸 수가 없기 때문에, 
공장에서 생산할 때 생산자가 요청한 데이터로 초기화 하는데 
이 작업을 굽는다(burn)라고 한다. 
그러므로 ROM은 반드시 생성자에서 burn 작업이 일어나야 한다.

다음은 ROM과 RAM 메모리를 생성하고 사용하는 사례이다.
ROM의 0번지에서 4번지까지 읽어 RAM 메모리의 0~4번지에 쓰고, 
다시 RAM 메모리의 값을 화면에 출력한다.
전체 프로그램을 완성하라.*/

#include <iostream>
using namespace std;

class BaseMemory {
    char* mem;
protected:
    BaseMemory(int size) { mem = new char[size]; }
    ~BaseMemory() { delete[] mem; }
    void setMem(int i, char data) { mem[i] = data; }
    char getMem(int i) { return mem[i]; }
public:
    char read(int i) { return getMem(i); }
};

class ROM : public BaseMemory { // Read-Only Memory
public:
    ROM(int size, char* x, int initSize) : BaseMemory(size) {
        for (int i = 0; i < initSize; i++) {
            setMem(i, x[i]); // burn 작업
        }
    }
};
class RAM : public BaseMemory {
public:
    RAM(int size) : BaseMemory(size) { }
    void write(int i, char data) {
        setMem(i, data);
    }
};

int main() {
    char x[5] = { 'h', 'e', 'l', 'l', 'o' };
    ROM biosROM(1024 * 10, x, 5); // 10KB의 ROM 메모리. 배열 x로 초기화됨 
    RAM mainMemory(1024 * 1024); // 1MB의 RAM 메모리 

    // 0 번지에서 4번지까지 biosRom에서 읽어 mainMemory에 복사 
    for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
    for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
}