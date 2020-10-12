#include <iostream>
int a = 10;
namespace N
{
	int a = 100;
	void f()
	{
		int a = 1000;
		std::cout <<"void f의 지역변수 a :"<< a << std::endl;
		std::cout << "namespace N의 변수 a :"<<N::a << std::endl;
		std::cout <<"global scope의 변수 a :"<< ::a << std::endl;
	}
}
int main() {
	N::f();
	system("pause");
}