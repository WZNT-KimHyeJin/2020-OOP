#include <iostream>
class MyData {
    int number;
    std::string strNumber;
public:
    MyData(int data, std::string str) : number(data), strNumber(str) {}
    //number와 strNumber를 초기화 시켜주는 cinstructor
    
    //Operator conversion
    operator int() { return number; }
    operator std::string() { return strNumber; }
    //Unary operator
    int operator++(int) { //postfix operation (indicated by dummy 'int')
        int temp = number;
        number++;
        return temp;
    }
    int operator++() { //prefix operation
        return ++number;
    }
    friend std::ostream& operator<<(std::ostream&, MyData&);
};
// non-member operator<< function
std::ostream& operator<<(std::ostream& os, MyData& md) {
    return os << "This number is: " << md.strNumber << "\n";
} 
int main() {
    MyData mydata(1, "one");
    std::string strNum = mydata; // strNum = MyData.strNumber
    //String 형 객체에 이러한 형식은 지원하지 않음
    //String이라는 변수에는 ="왈라리" 이런 형태로 원래 문자열만 넣을 수 잇었는데
    //convertino을 사용해서 객체를 넣어줄 수 있도록 객체 형변환 가능.
    int intNum = mydata;// intNum = MyData.number
    std::cout << strNum << std::endl; // one
    std::cout << intNum << std::endl; // 1
    std::cout << mydata++ << std::endl; // 1
    std::cout << ++mydata << std::endl; // 3
    //이런 전위 후위 연산자도 overlaoding 하면 원하는 연산을 할 수 있도록 함.
    std::cout << mydata;
}
// 코드를 실행/분석해보세요  (operator overloading 과 conversion 에 대해 복습).
