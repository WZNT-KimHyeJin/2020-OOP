#include <iostream>
#include <string>
class Employee {
protected:
    std::string name;
    int age;
public:
    Employee(std::string name, int age) : name(name), age(age) {}
    virtual void showInfo() {
        std::cout << "Name:" << name << ", Age: " << age <<
            std::endl;
    }
};
class Manager : public Employee {
    int managerBonus;
public:
    Manager(int managerBonus, std::string name, int age) :
        managerBonus(managerBonus), Employee(name, age) {}
    void showInfo() {
        std::cout << "Manager Name:" << name << ", Age: " << age <<
            ", managerBonus:" << managerBonus << std::endl;
    }
};
class Intern : public Employee {
    std::string majorName;
public:
    Intern(std::string major, std::string name, int age) : majorName(major),
        Employee(name, age) {}
    void showInfo() {
        std::cout << "Intern Name:" << name << ", Age: " << age <<
            ", Major:" << majorName << std::endl;
    }
};
class Janitor : public Employee {
    int salary;
public:
    Janitor(int salary, std::string name, int age) : salary(salary),
        Employee(name, age) {}
    void showInfo() {
        std::cout << "Janitor Name:" << name << ", Age: " << age
            << ", Salary:" << salary << std::endl;
    }
};
int main() {
    Employee** employeelist = new Employee * [6];

    employeelist[0] = new Manager(200, "James", 33);
    employeelist[1] = new Manager(150, "Chulsoo", 50);

    employeelist[2] = new Intern("security", "Minsu", 24);
    employeelist[3] = new Intern("HCI", "Yong", 19);
    employeelist[4] = new Janitor(100, "Black", 90);
    employeelist[5] = new Janitor(200, "White", 100);
    employeelist[0]->showInfo();
    employeelist[1]->showInfo();
    employeelist[2]->showInfo();
    employeelist[3]->showInfo();
    employeelist[4]->showInfo();
    employeelist[5]->showInfo();
    getchar();
    return 0;
}
/*
(실습 4.1) 위 코드에서는 Manager, Intern, Janitor 타입의 오브젝트들을 관리하기 위해, 각
오브젝트와 동일한 타입을 가지는 배열 (managelist, internlist, janitorlist) 을 생성하였다.
하지만 이러한 방식의 문제점은, Employ class 를 상속받는 새로운 class 타입이 추가 (예:
Supervisor) 될 때마다, 새롭게 추가된 class 타입을 저장하기 위한 배열( 예: supervisorlist)을
생성해야 한다는 점이다.
이러한 문제점은 업캐스팅 (Upcasting)을 활용하여 해결가능하다. 즉, Employ 의 주소를
저장하기 위한 배열을 생성하고, Manager, Intern, Janitor 오브젝트들을 해당 배열에서 통합
관리할 수 있다. 아래 코드가 정상 동작할 수 있도록 코드를 수정하세요 (실습 3 과 실행
결과가 동일해야 한다).
*/