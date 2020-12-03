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

//templete�� ������ �� �Ű������� �ڷ����� ���ƾ� �ϴµ� d�� double, x �� int������ 
//templete���� ���⿡ T�� ���� �ΰ������� ������ �߻��Ѵ�. �̴� ��ȯ���� ������ �� ������ �Ǹ�
// �Լ��� ȣ�� �� �� T�� ���� ��������� ǥ���Ͽ� � �ڷ����� ���� �������� �ϴ� �� ǥ���Ͽ� ȥ���� ���´�.