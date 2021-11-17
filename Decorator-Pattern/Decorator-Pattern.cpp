//
// Created by JakeLin on 2021/11/17.
//
#include <bits/stdc++.h>
using namespace std;

/**
 * 现在有一个咖啡店售卖多种单品咖啡（Espresso、ShortBlack等）销售火爆，
 * 店家推出组合咖啡（单品咖啡+配料），组合很多，如：单品咖啡+牛奶，单品咖啡+糖 等等。
 * 现需要更新系统支持组合咖啡价格计算。
 * 类图：https://gitee.com/jakel-in/images/raw/master/2021-11/Decorator-Pattern-example.jpg
 */

// 【抽象构件】 咖啡抽象类
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual string description() = 0;
    virtual double cost() = 0;
};

// 【具体构件】 咖啡单品类：Espresso
class Espresso : public Coffee {
public:
    virtual string description() {
        return "Espresso(12)";
    }
    virtual double cost() {
        return 12;
    }
};
// 【具体构件】 咖啡单品类：ShortBlack
class ShortBlack : public Coffee {
public:
    virtual string description() {
        return "ShortBlack(13)";
    }
    virtual double cost() {
        return 13;
    }
};

// 【抽象装饰】 组合咖啡基类
class CoffeeDecorator : public Coffee {
public:
    CoffeeDecorator(Coffee *coffee) : m_coffee(coffee) { }
    virtual string description() {
        return m_coffee->description();
    }
    virtual double cost() {
        return m_coffee->cost();
    }
private:
    Coffee *m_coffee;
};

// 【具体装饰】 加糖
class CoffeeWithSugar : public CoffeeDecorator {
public:
    CoffeeWithSugar(Coffee *coffee) : CoffeeDecorator(coffee) { }
    virtual string description() {
        return CoffeeDecorator::description() + " + Sugar(2)";
    }
    virtual double cost() {
        return CoffeeDecorator::cost() + 2;
    }
};
// 【具体装饰】 加牛奶
class CoffeeWithMilk : public CoffeeDecorator {
public:
    CoffeeWithMilk(Coffee *coffee) : CoffeeDecorator(coffee) {}
    virtual string description() {
        return CoffeeDecorator::description() + " + Milk(3)";
    }
    virtual double cost() {
        return CoffeeDecorator::cost() + 3;
    }
};

// 测试
int main() {
    Coffee *originCoffee = new Espresso();
    cout << originCoffee->description() << " : " << originCoffee->cost() << endl;

    Coffee *addSugar = new CoffeeWithSugar(originCoffee);
    cout << addSugar->description() << " : " << addSugar->cost() << endl;

    Coffee *addMilk = new CoffeeWithMilk(originCoffee);
    cout << addMilk->description() << " : " << addMilk->cost() << endl;

    Coffee *addMilkSugar = new CoffeeWithSugar(addMilk);
    cout << addMilkSugar->description() << " : " << addMilkSugar->cost() << endl;

    return 0;
}



