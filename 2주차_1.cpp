#include <iostream>
int a = 10;
namespace N
{
	int a = 100;
	void f()
	{
		int a = 1000;
		std::cout <<"void f�� �������� a :"<< a << std::endl;
		std::cout << "namespace N�� ���� a :"<<N::a << std::endl;
		std::cout <<"global scope�� ���� a :"<< ::a << std::endl;
	}
}
int main() {
	N::f();
	system("pause");
}