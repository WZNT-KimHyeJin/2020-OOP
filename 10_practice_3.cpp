#include <vector>
#include <string>
#include <iostream>
class Base1 {
public:
    Base1(int n) : vector_(n, 3) {}
    //.....
private:
    std::vector<char> vector_;
};
class Base2 {
public:
    Base2(int n) : vector_(n, 3) {}
    //.....
private:
    std::vector<char> vector_;
};
class Derived : public Base1, Base2 {
public:
    Derived(const std::string& str) : Base2(1024), Base1(512)
    {
        i = 0;
    }
    // ...
private:
    std::string str_;
    int i = 0;
};
int main() {
    Derived drv(1);
    return 0;
}

/*
(실습 3) 아래 코드에서 Derived class 는 Base1, Base2 를 상속 받는다. 이때, 각 클래스의
생성자가 호출되는 순서는 무엇인가?
*/

/*
(실습 3.1) 만약 Derived 클래스에서 상속 받는 순서를 Base2, Base1 으로 할 경우의
생성자가 호출되는 순서는? 코드를 수정해서 확인해 보세요 (Class Derived: public
Base2, Base1)
*/