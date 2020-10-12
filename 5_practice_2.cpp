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
int& foo(int& i)
{
    i = 3;
    A ob;
    return i;
}
int main()
{
    cout << foo(i) << endl;
    return 0;
}