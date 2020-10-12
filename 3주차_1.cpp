#include <iostream>

void cal(int a, int b);
int main() {
	int a = -2147483647;
	unsigned one = 2;
	int b = 2147483648U;
	
	cal(a-1
		., b);
}

void cal(int a, int b) {
	if (a > b) {
		std::cout << "a가 b보다 큰 값입니다." << std::endl;
	}
	else if(a<b){
		std::cout << "b가 a보다 큰 값입니다." << std::endl;
	}
	else {
		std::cout << "같은 값입니다." << std::endl;
	}
	std::cout << "a : " << a << " b:" << b << std::endl;
}