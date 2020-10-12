#include <iostream>
class Animal {
public:
	Animal(){} // 클래스의 기본생성자가 없다.
	Animal(int numberOfLeg) {
		this->numberOfLeg = numberOfLeg;
	}
private:
	int numberOfLeg;
};
int main() {
	Animal a;// 이 형태의 객체 생성에 만족하는 생성자가 없다.
	return 0;
}

