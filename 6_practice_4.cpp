#include<iostream>
#include <string>
class Animal {
private:
	std::string name;
public:
	Animal() {};
	Animal(std::string name) : name(name) {};
	void showName() {
		std::cout << "Name is " << name << std::endl;
	}
	Animal& operator+(const Animal& a) {
		name += a.name;
		return *this;
	}
};
int main() {
	Animal cat("Nabi");
	cat.showName();
	Animal dog("Jindo");
	dog.showName();
	Animal catDog = dog + cat;
	//값이 저장되는 dog 객체에 += 연산자를 사용하여 dog 객체의 name값도 변경하였기 떄문에
	catDog.showName();
	dog.showName();
	getchar();
	return 0;
}