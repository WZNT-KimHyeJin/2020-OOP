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
		if (!s_instance) { // ��ü�� �������� �ʴ´� == �ּҰ� �����Ǿ����� �ʴ�
			s_instance = new GlobalClass(); // ���ο� ��ü�� �����ؼ� ��������			
		}
		return s_instance; // GlobalClass ��ü�� �ּҸ� ��ȯ�Ͽ� �Լ� ����
	} // ��ü�� �������� �ʴٸ� ��ü�� ���������� �̹� �����Ѵٸ� ���̻��� ��ü�� �������� �ʵ��� �Ѵ�.

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
�ǽ� 2��������GlobalClass�� �ּҸ� �����ϴ� ������ ������ ���������� �����Ͽ����µ�
�ǽ� 3�������� �ش� �����͸� �ش� Ŭ���� ���� private�� �����Ͽ�
��ü�� ������ ������ �� �ִ� ������ ���Ҵ�.
==> ��ü�� �ѹ��� ������ �� �ֵ��� �Ͽ� value�� �����ϱ� ������ �Ͽ���.
*/ 
