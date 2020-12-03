#include <iostream>
template <typename T, int num = 2>
T add_num(T t) {
	return t + num;
}
int main() {
	int x = 3;
	std::cout << "x : " << add_num(x) << std::endl;
}


//수정 전의 결과값은 num + x == 5 + 3 => 결과 값은 8이 나온다
// 수정 후의 결과 값은 default parameter의 값을 2로 변경하여 결과값이 5가 나오도록 한다.