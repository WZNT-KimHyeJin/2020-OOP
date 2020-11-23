#include <iostream>
class Parent {
    char* p;
public:
    Parent() {
        p = new char[10];
        std::cout << "Parent Constructor invocation" << std::endl;
    }
    virtual ~Parent() {
        delete[] p;
        std::cout << "Parent Destructor invocation" << std::endl;
    }// 베이스 클래스의 소멸자에는 virtual 키워드를 붙이도록 코딩 해야 함.
};
class Child : public Parent {
    char* c;
public:
    Child() : Parent() {
        c = new char[10];
        std::cout << "Child Constructor invocation" << std::endl;
    }
    ~Child() {
        delete[] c;
        std::cout << "Child Destructor invocation" << std::endl;
    }
};
int main() {
    std::cout << "--- Case1: Normal Child instantiation ---" << std::endl;
    Child* c = new Child();
    delete c;
    std::cout << "--- Case2: Parent pointer to Child ---" << std::endl;

    Parent* p = new Child();
    delete p;

    getchar();
}
/*
(실습 5) 아래 코드를 실행하고 문제점을 찾아보세요.
자식 클래스를 부모 클래스에 upcasting 하고 생성자를 delete 하였을때 
소멸자가 제대로 호출이 안됨
==> 자식 클래스의 소멸자가 호출이 안됨
*/

/*
(실습 5.1) 위 코드를 수정하여 문제점을 해결해 보세요.
*/