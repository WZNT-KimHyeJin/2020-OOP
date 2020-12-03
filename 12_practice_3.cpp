#include <iostream>
template<typename T>
T min(T x, T y) {
    return x < y ? x : y;
}
int main() {
    int x = 3;
    int y = 2;
    double d = 2.1;
    double e = 3.3;
    /*std::cout << "min(x,y): " << min(x, y) << ", min(d,e): " << min(d, e) << ", min(d, x): " <<
        min(d, x) << std::endl;*/
    std::cout << "min(x,y): " << min(x, y) << ", min(d,e): " << min(d, e) << ", min(d, x): " <<
        min<int>(d, x) << std::endl;
    return 0;
}

//templete을 선언할 때 매개변수의 자료형이 같아야 하는데 d는 double, x 는 int형으로 
//templete에서 보기에 T의 값이 두가지여서 오류가 발생한다. 이는 반환값을 결정할 때 문제가 되며
// 함수를 호출 할 때 T의 값을 명시적으로 표시하여 어떤 자료형일 때를 기준으로 하는 지 표시하여 혼란을 막는다.