#include <iostream>

void increament(int x) {
	++x;
}
int main() {
	int x = 55;
	std::cout << "Before increment: " << x << std::endl;
	increament(x);
	std::cout << "After increament: " << x << std::endl;
	system("pause");
	return 0;
}