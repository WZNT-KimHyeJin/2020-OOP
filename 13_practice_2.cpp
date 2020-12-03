#include <iostream>
#include <string>
///////////////////추가 구현///////////////////////
template<typename T>
auto sum(T x) {
	return x;
}
//////////////////////////////////////////////////
template<typename T, typename...Args>
auto sum(T x, Args... args) {
	return x + sum(args...);
}
int main() {
	auto x = sum(42.5, 10, 11.1f);
	std::cout << x;
	getchar();
}//수정 전의 코드의 경우 파라미터가 여러개일 경우의 Variadic templete는 구현되어있지만// 파라미터가 하나일 때의 varadic templete는 구현이 되어있지 않기 때문에 이를 구현하여 작동한다.