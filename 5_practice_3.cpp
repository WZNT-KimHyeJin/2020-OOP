#include <iostream>
using namespace std;
int i;
class A
{
public:
    ~A()
    {
        i = 10;
    }
};
int foo()
{
        i = 3;
    {
        A ob;
    }
    // 소멸자는 지역변수가 포함되어있는 블록 종료시 호출된다.
    //객체를 생성하는 블럭이 종료되면 소멸자가 생성되어 i의 값이 10으로 변경된다.
    return i;
}
int main()
{
    cout << foo() << endl;
    return 0;
}