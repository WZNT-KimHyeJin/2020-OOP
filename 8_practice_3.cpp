#include <iostream>
class GlobalClass
{
private:
	int m_value;
	static GlobalClass* s_instance;
	GlobalClass(int v = 0)
	{
		m_value = v;
	}
public:
	int get_value()
	{
		return m_value;
	}
	void set_value(int v)
	{
		m_value = v;
	}
	static GlobalClass* instance()
	{
		if (!s_instance) { // 객체가 존재하지 않는다 == 주소가 지정되어있지 않다
			s_instance = new GlobalClass(); // 새로운 객체를 생성해서 지정해줌			
		}
		return s_instance; // GlobalClass 객체의 주소를 반환하여 함수 종료
	} // 객체가 존재하지 않다면 객체를 생성하지만 이미 존재한다면 더이상의 객체를 생성하지 않도록 한다.

};
GlobalClass* GlobalClass::s_instance = 0;
void foo(void)
{
	GlobalClass::instance()->set_value(1);
	std::cout << "foo: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}
void bar(void)
{
	GlobalClass::instance()->set_value(2);
	std::cout << "bar: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}
int main()
{
	std::cout << "main: global_ptr is " << GlobalClass::instance()->get_value() <<
		'\n';
	foo();
	bar();
}
/*
실습 2번에서는GlobalClass의 주소를 저장하는 포인터 변수를 전역변수로 지정하였었는데
실습 3번에서는 해당 포인터를 해당 클래스 내에 private로 선언하여
객체를 여러번 생성할 수 있는 문제를 막았다.
==> 객체를 한번만 생성할 수 있도록 하여 value를 관리하기 쉽도록 하였다.
*/ 
