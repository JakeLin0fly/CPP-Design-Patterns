//
// Created by JakeLin on 2021/11/19.
//
#include <bits/stdc++.h>
using namespace std;

/**
 * 俄罗斯方块中每次产生的方块只有几种形状（L、I、T、O）。如果每个不同的方块都是一个实例对象，
 * 这些对象就要占用很多的内存空间，此时适合利用享元模式进行实现。类图设计如下：
 * https://gitee.com/jakel-in/images/raw/master/2021-11/Flyweight-Pattern-Example.png
 */
// 抽象享元
class AbstractBox {
public:
    virtual ~AbstractBox() = default;
    virtual string getShape() = 0;
    void display(string color) {
        cout << "Box Shape: " << getShape() << ", Color: " << color << endl;
    }
};
// 具体享元：I型
class IBox : public AbstractBox {
public:
    virtual string getShape() {
        return "I";
    }
};
// 具体享元：L型
class LBox : public AbstractBox {
public:
    virtual string getShape() {
        return "L";
    }
};
// 具体享元：O型
class OBox : public AbstractBox {
public:
    virtual string getShape() {
        return "O";
    }
};

class TBox : public AbstractBox {
public:
    virtual string getShape() {
        return "T";
    }
};

// 享元工厂：单例（恶汉）
class BoxFactory {
public:
    static BoxFactory* INSTANCE;
    static BoxFactory* getInstance() {
        return BoxFactory::INSTANCE;
    }
    AbstractBox* getBox(string shape) {
        if ("I" != shape && "L" != shape && "T" != shape && "O" != shape) {
            return nullptr;
        }
        return hashMap[shape];
    }

protected:
    BoxFactory() {
        hashMap["I"] = new IBox();
        hashMap["L"] = new LBox();
        hashMap["T"] = new TBox();
        hashMap["O"] = new OBox();
    }

private:
    unordered_map<string, AbstractBox*> hashMap;
};
BoxFactory* BoxFactory::INSTANCE = new BoxFactory();

// 测试
int main() {
    BoxFactory* factory = BoxFactory::getInstance();

    AbstractBox *iBox = factory->getBox("I");
    AbstractBox *lBox = factory->getBox("L");
    iBox->display("Red");
    lBox->display("Blue");

    AbstractBox *iBox2 = factory->getBox("I");
    iBox2->display("Blue");

    cout << "iBox == lBox ?   " << (iBox == lBox) << endl;
    cout << "iBox == iBox2 ?   " << (iBox == iBox2) << endl;
    return 0;
}