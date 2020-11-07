#include<iostream>
class Strategy {
public:
	virtual int doOperation(int num1, int num2) = 0;
	//pure로 생성해서 상속받는 클래스에서 구현하도록 함
};
class OperationAdd : public Strategy {
public:
	virtual int	doOperation(int num1, int num2) {
		return num1 + num2;
	}
};
class OperationSubstract : public Strategy {
public:
	virtual int	doOperation(int num1, int num2) {
		return num1 +- num2;
	}
};
class OperationMultifly : public Strategy {
public:
	virtual int	doOperation(int num1, int num2) {
		return num1 * num2;
	}
};
class Context {
private:
	Strategy* strategy;
public:
	Context(Strategy* s) {
		strategy = s;
	}
	int executeStrategy(int num1, int num2) {
		return strategy->doOperation(num1, num2);
	}
};

int main() {
	Context* context = new Context(new OperationAdd);
	std::cout << "10 + 5 = " << context->executeStrategy(10, 5) << std::endl;
	context = new Context(new OperationSubstract);
	std::cout << "10 - 5 = " << context->executeStrategy(10, 5) << std::endl;
	context = new Context(new OperationMultifly);
	std::cout << "10 + 5 = " << context->executeStrategy(10, 5) << std::endl;

}