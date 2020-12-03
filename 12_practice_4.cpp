#include <iostream>
using namespace std;
template <typename T>
void fun(const T& x)
{
    static int count = 0;
    cout << "x = " << x << " count = " << count << endl;
    ++count;
    return;
}
int main()
{
    fun<int>(1);
    cout << endl;
    fun<int>(1);
    cout << endl;
   /* fun<int>(1);
    cout << endl;*/
    fun<double>(1.1);
    cout << endl;
    /*fun<double>(1.1);
    cout << endl;*/
    return 0;
}
/*
    x = 1 count = 0 => fun<int> : int���� �ڷ������� �ϴ� �Լ��� ȣ���Ͽ���.

    x = 1 count = 1 =>fun<int> : int���� �ڷ������� �ϴ� �Լ��� ȣ���Ͽ���. 

    x = 1.1 count = 0 =>fun<double> :double���� �ڷ������� �ϴ� �Լ��� ȣ���Ͽ���.

    => �̴� �����Ϸ��� �ڷ��� Ÿ�Ժ��� �ٸ��� static ������ �ν��ϱ� �����̴�.
    => ������ �ռ� int���� �ι� �����߱⿡ int�� �Լ������� ++count�� 2�� ����� ���̰�,
        ���Ŀ� double�� �Լ��� �����Ͽ� �� ���� static ������ ������ ���� ������ ���̴�.
*/