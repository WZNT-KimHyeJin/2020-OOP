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
    // �Ҹ��ڴ� ���������� ���ԵǾ��ִ� ��� ����� ȣ��ȴ�.
    //��ü�� �����ϴ� ���� ����Ǹ� �Ҹ��ڰ� �����Ǿ� i�� ���� 10���� ����ȴ�.
    return i;
}
int main()
{
    cout << foo() << endl;
    return 0;
}