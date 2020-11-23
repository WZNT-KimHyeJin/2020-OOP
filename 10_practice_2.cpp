#include <iostream>

class Base {
public:
	void func_1() {};
protected:
	void func_2() {};
private:
	int x_;
};
class Derived : public Base { //원래 protected였
public:
	void func_3() {
		func_1();
		func_2();
	}
};
int main() {
	Derived d;
	d.func_3();
	d.func_1();
}
// compile err가 나는 이유는?
//protected로 선언을 받아서. 