#include <iostream>
class Animal {
public:
	Animal(){} // Ŭ������ �⺻�����ڰ� ����.
	Animal(int numberOfLeg) {
		this->numberOfLeg = numberOfLeg;
	}
private:
	int numberOfLeg;
};
int main() {
	Animal a;// �� ������ ��ü ������ �����ϴ� �����ڰ� ����.
	return 0;
}

