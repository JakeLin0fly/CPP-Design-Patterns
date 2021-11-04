//
// Created by JakeLin on 2021/11/4.
//
#include <iostream>
using namespace std;

/** 抽象产品 **/
class IMouse {
public:
    virtual void use() = 0;
};
class IKeyboard {
public:
    virtual void use() = 0;
};

/** 具体产品 **/
class DellMouse : public IMouse {
public:
    void use() {
        cout << "use Dell mouse" << endl;
    }
};
class DellKeyBoard : public IKeyboard {
public:
    void use() {
        cout << "use Dell keyboard" << endl;
    }
};

class HPMouse : public IMouse {
public:
    void use() {
        cout << "use HP mouse" << endl;
    }
};
class HPKeyBoard : public IKeyboard {
public:
    void use() {
        cout << "use HP keyboard" << endl;
    }
};

/** 抽象工厂 **/
class IFactory {
public:
    virtual IMouse * createMouse() = 0;
    virtual IKeyboard * createKeyboard() = 0;
};

/** 具体工厂 **/
// 戴尔工厂生产戴尔鼠标、戴尔键盘
class DellFactory : public IFactory {
public:
    IMouse * createMouse() {
        return new DellMouse()
    }
    IKeyboard * createKeyboard() {
        return new DellKeyBoard();
    }
};
// 惠普工厂生产惠普鼠标、惠普键盘
class HPFactory : public IFactory {
public:
    IMouse * createMouse() {
        return new HPMouse()
    }
    IKeyboard * createKeyboard() {
        return new HPKeyBoard();
    }
};