#include <iostream>

class SetValue
{
	int x, y;
public:
	void setXY(int a, int b) {
		this->x = a;
		this->y = b;
	}
	void show() {
		printf("%d %d", this->x, this->y);
	}
};
int main()
{
	SetValue obj;

	obj.setXY(33, 44);
	obj.show();
	system("pause");
	return 0;
}