#include <iostream>
using namespace std;
int i;
class A
{
public:
    ~A()
    {
        i = 10;
        cout << "현재 i값은 : "<<i << "(소멸자 호출됨)" << endl;
    }
};
int foo()
{
    i = 3;
    A ob;
    return i;
    //여기서 소멸자가 호출된다고 보면 됨
    // 함수 끝난 직후
}
int main()
{
    cout << "foo 함수의 결과값 :"<<foo() << endl;
    cout << "함수 종료 이후의 i값 : " << i << endl;
    return 0;
    /*
    이거는 foo 함수 종료 전에 저장된 i의 값을 반환하는 거
    그래서 foo함수 내에서는 i가 3으로 변경되었기 때문에 함수 종료 전까지는 i의 값은 3
    함수 종료 이후에는 소멸자가 호출되기 때문에 종료 이후에는 소멸자의 값인 10이 출력

    정리)
    순서가 소멸자 호출 -> main문의 foo 함수 결과값 출력 -> 함수 종료 후의 값


    */
}