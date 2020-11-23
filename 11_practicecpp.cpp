#include <iostream>
#include <string>
using namespace std;

enum BeverageSize {
    TALL,
    GRANDE,
    VENTI
};

class Beverage {

public:
    string description;
    Beverage() {
        description = "Unknown Beverage";
    }
    virtual double cost() = 0;
    BeverageSize size;

    virtual string getDescription() {
        return description;
    }
    BeverageSize getSize() {
        return size;
    }

};

class CondimentDecorator : public Beverage {
public:
    virtual string getDescription() = 0;
};


class DarkRoast : public Beverage {
public:
    DarkRoast(BeverageSize size) {
        description = "Dark Roast";
    }
    double cost() {
        return .99;
    }
};
class Decaf : public Beverage {
public:
    Decaf(BeverageSize size) {
        description = "Decaf Coffee";
    }
    double cost() {
        return 1.05;
    }
};


class Espresso : public Beverage {
public:
    Espresso(BeverageSize size) {
        description = "Espresso";
    }
    double cost() {
        return 1.99;
    }
};

class HouseBlend : public Beverage {
public:
    HouseBlend(BeverageSize size) {
        description = "House Blend Coffee";
    }
    double cost() {
        return .89;
    }
};

class Milk : public CondimentDecorator {
public:
    Beverage* beverage;
    Milk(Beverage* beverage) {
        this->beverage = beverage;
    }
    string getDescription() {
        return beverage->getDescription() + ", Milk";
    }
    double cost() {
        if (getSize() == TALL) {
            return beverage->cost() + 1.00;
        }
        else if (getSize() == GRANDE) {
            return beverage->cost() + 2.00;
        }
        else if (getSize() == VENTI) {
            return beverage->cost() + 3.00;
        }
    }

};

class Mocha : public CondimentDecorator {
public:
    Beverage* beverage;
    Mocha(Beverage* beverage) {
        this->beverage = beverage;
    }
    string getDescription() {
        return beverage->getDescription() + ", Mocha";
    }
    double cost() {
        if (getSize() == TALL) {
            return beverage->cost() + 0.50;
        }
        else if (getSize() == GRANDE) {
            return beverage->cost() + 1.00;
        }
        else if (getSize() == VENTI) {
            return beverage->cost() + 1.50;
        }
    }
};

class Soy : public CondimentDecorator {
public:
    Beverage* beverage;
    Soy(Beverage* beverage) {
        this->beverage = beverage;
    }
    string getDescription() {
        return beverage->getDescription() + ", Soy";
    }
    double cost() {
        if (getSize() == TALL) {
            return beverage->cost() + 2.00;
        }
        else if (getSize() == GRANDE) {
            return beverage->cost() + 2.50;
        }
        else if (getSize() == VENTI) {
            return beverage->cost() + 3.00;
        }
    }
};

class Whip : public CondimentDecorator {
public:
    Beverage* beverage;
    Whip(Beverage* beverage) {
        this->beverage = beverage;
    }
    string getDescription() {

        return beverage->getDescription() + ".Whip";
    }
    double cost() {
        if (getSize() == TALL) {
            return beverage->cost() + 0.70;
        }
        else if (getSize() == GRANDE) {
            return beverage->cost() + 1.40;
        }
        else if (getSize() == VENTI) {
            return beverage->cost() + 2.10;
        }
    }

};
int main() {
    Beverage* bever1 = new DarkRoast(TALL);
    bever1 = new Milk(bever1);
    bever1 = new Mocha(bever1);
    bever1 = new Milk(bever1);
    //bever1->desplayDescription();
    cout << bever1->getDescription() << " : " << bever1->cost() << endl;

    Beverage* bever2 = new Espresso(GRANDE);
    bever2 = new Milk(bever2);
    bever2 = new Milk(bever2);
    bever2 = new Milk(bever2);
    //bever2->desplayDescription();
    cout << bever2->getDescription() << " : " << bever1->cost() << endl;


    Beverage* bever3 = new HouseBlend(VENTI);
    bever3 = new Whip(bever1);
    bever3 = new Milk(bever1);
    bever3 = new Soy(bever1);
    bever3 = new Mocha(bever1);
    //bever3->desplayDescription();
    cout << bever3->getDescription() << " : " << bever1->cost();

    return 0;
}