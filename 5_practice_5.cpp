#include <iostream>

class Animal {
public:
	char* name;
	int age;
	Animal(int age_, const char* name_) {
		age = age_;
		name = new char[strlen(name_) + 1];
		strcpy(name, name_);
	}
	Animal(Animal& a) { //복사 생성자
		age = a.age;
		name = new char[strlen(a.name) + 1];
		strcpy(name, a.name);
	}
	void changeName(const char* newName) {
		strcpy(name, newName);
	}
	void printAnimal() {
		std::cout << "Name: " << name << " Age: "
			<< age << std::endl;
	}
};
void main() {
	Animal A(10, (char*)"Jenny"); //10살 Jenny 생성
	Animal B = A; // 10살 Jenny인 A를 B에게 복사
	/*
	이렇게 할당하면서 name의 주소값을 공유하게끔 감.
	&name(b) = &name(a)
	이렇게 되어서 이따가 changename으로 깊은복사를 해도 
	가리키는 주소값이 같기 때문에 변하지 않음.
	*/
	A.age = 22; //A의 나이를 22살로 바꿈
	A.changeName((char*)"Brown"); //A의 이름을 Brown으로 바꿈

	A.printAnimal();
	B.printAnimal();
	getchar();
}
