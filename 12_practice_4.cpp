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
    x = 1 count = 0 => fun<int> : int형을 자료형으로 하는 함수를 호출하였다.

    x = 1 count = 1 =>fun<int> : int형을 자료형으로 하는 함수를 호출하였다. 

    x = 1.1 count = 0 =>fun<double> :double형을 자료형으로 하는 함수를 호출하였다.

    => 이는 컴파일러가 자료형 타입별로 다르게 static 변수를 인식하기 때문이다.
    => 때문에 앞서 int형을 두번 선언했기에 int형 함수에서의 ++count가 2번 실행된 것이고,
        이후에 double형 함수를 실행하여 그 안의 static 변수가 별개로 값이 증가된 것이다.
*/