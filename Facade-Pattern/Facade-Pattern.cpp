//
// Created by JakeLin on 2021/11/17.
//
#include <bits/stdc++.h>
using namespace std;
/**
 * 小明每天作息很规律，其中包括以下场景操作：
 *  下班回家：开灯、打开空调、打开电视；
 *  睡觉：关电视、关灯；
 * 小明购买了一个天猫精灵，通过语言控制这些设备开启关闭。设计类图如下：
 * https://gitee.com/jakel-in/images/raw/master/2021-11/Facade-Pattern-Example.png
 */

// 子系统角色：灯
class Light {
public:
    void on() {
        cout << "light(on)";
    }
    void off() {
        cout << "light(off)";
    }
};
// 子系统角色：电视
class TV {
public:
    void on() {
        cout << "TV(on)";
    }
    void off() {
        cout << "TV(off)";
    }
};
// 子系统角色：空调
class AirCondition {
public:
    void on() {
        cout << "AirCondition(on)";
    }
    void off() {
        cout << "AirCondition(off)";
    }
};

// 外观角色：天猫精灵
class TmallGenie {
public:
    TmallGenie(Light *light, TV *tv, AirCondition *airCondition)
        : m_light(light), m_tv(tv), m_airCondition(airCondition) {
        cout << "Use Tmall Genie." << endl;
    }
    // 语音控制
    void say(string scene) {
        if ("go home" == scene) {
            goHome();
            return;
        }
        if ("sleep" == scene) {
            sleep();
        }
    }
private:
    void goHome() {
        cout << "scene: go home. operations: ";
        m_light->on();
        cout << " + ";
        m_airCondition->on();
        cout << " + ";
        m_tv->on();
        cout << endl;
    }
    void sleep() {
        cout << "scene: sleep. operations: ";
        m_tv->off();
        cout << " + ";
        m_tv->off();
        cout << endl;
    }

private:
    Light *m_light;
    TV *m_tv;
    AirCondition *m_airCondition;
};

// 测试：模拟客户场景操作
int main() {
    TmallGenie tmallGenie(new Light(), new TV(), new AirCondition());
    tmallGenie.say("sleep");
    tmallGenie.say("go home");

    return 0;
}