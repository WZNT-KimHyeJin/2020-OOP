#include <iostream>
using namespace std;

void increament(int *x) {
	++*x;
}
int main()
{
	int x = 10;
	int *ptr = &x;
	cout << "before increament: " << x << endl;

	increament(&x);
	cout << "After increament: " << x << endl;

	return 0;
}