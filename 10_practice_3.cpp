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
(�ǽ� 3) �Ʒ� �ڵ忡�� Derived class �� Base1, Base2 �� ��� �޴´�. �̶�, �� Ŭ������
�����ڰ� ȣ��Ǵ� ������ �����ΰ�?
*/

/*
(�ǽ� 3.1) ���� Derived Ŭ�������� ��� �޴� ������ Base2, Base1 ���� �� �����
�����ڰ� ȣ��Ǵ� ������? �ڵ带 �����ؼ� Ȯ���� ������ (Class Derived: public
Base2, Base1)
*/