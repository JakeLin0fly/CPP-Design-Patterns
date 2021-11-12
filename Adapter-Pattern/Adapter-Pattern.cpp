//
// Created by JakeLin on 2021/11/11.
//
#include <iostream>
using namespace std;

// 目标
class Target {
public:
    virtual ~Target() = default;
    // 直接充电需220V
    virtual void charge() {
        cout << "Direct charging 220V" << endl;
    }
};

// 需适配类/接口
class Adaptee {
public:
    // 插线板输出电压110V
    void specialCharge() {
        cout << "Patch board output 110V." << endl;
    }
};

// 对象适配器
class Adapter : public Target {
public:
    Adapter() {
        adaptee = new Adaptee();
    }
    void charge() override {
        cout << "Connect the adapter, 110V to 220V." << endl;
        adaptee->specialCharge();
    }

private:
    Adaptee *adaptee;
};

int main() {
    // 充电逻辑：插线板输出110V -> 接上适配器，110V转220V -> 充电输入电压220V
    Target *target = new Adapter();
    target->charge();

    delete target;
    target = nullptr;

    return 0;
}
