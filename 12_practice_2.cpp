#include <iostream>

template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//template specialization
template<> // 괄호 안에 아무것도 존재하지 않음

void swap(std::string& a, std::string& b) {
	std::string temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 1;
	int b = 2;
	float c = 3.3;
	float d = 4.4;
	std::string e = "World";
	std::string f = "Hello";

	swap<int>(a, b);
	swap<float>(c, d);
	// 위의 두 templete은 처음 생성한 T값에 괄호 안의 자료형이
	// 입력되어서 specialization을 하지 않은 templete로 입력된다

	swap<>(e, f);
	//괄호 안에 특정 자료형을 아무것도 입력하지 않은 경우 specialization을 적용한
	//templete로 인지되어 해당 함수를 실행한다


	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "e: " << e << ", f: " << f << std::endl;

	return 0;
}
