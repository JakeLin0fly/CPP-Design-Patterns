//
// Created by JakeLin on 2021/11/9.
//
#include <iostream>
#include <string>

using namespace std;

/**
 * 原型类，声明一个克隆自身的接口
 */
class Prototype {
public:
    virtual ~Prototype() = default;

    virtual void display() = 0;

    virtual Prototype *clone() = 0;
};

/**
 * 具体原型类，实现克隆自身的接口
 */
class Resume : public Prototype {
public:
    Resume() = default;

    Resume(const Resume &resume) {
        this->name = resume.name;
        this->sex = resume.sex;
        this->age = resume.age;
    }

    void setPersonalInfo(string name, string sex, int age) {
        this->name = name;
        this->sex = sex;
        this->age = age;
    }

    void display() override {
        cout << "====== Resume ======" << endl;
        cout << "\tname : " << name << endl;
        cout << "\tsex : " << sex << endl;
        cout << "\tage : " << age << endl;
    }

    // 克隆
    Prototype *clone() override {
        return new Resume(*this);
    }

private:
    string name;
    string sex;
    int age{};
    // ...
};

// 测试
int main() {
    Resume resumeA;
    resumeA.setPersonalInfo("ZhangSan", "male", 18);
    cout << "print resumeA" << endl;
    resumeA.display();
    cout << endl;

    Prototype *p1 = resumeA.clone();
    cout << "print first clone resume" << endl;
    p1->display();
    cout << endl;

    // 通过基类指针来复制派生类对象
    Prototype *p2 = p1->clone();
    cout << "print second clone resume" << endl;
    p2->display();
    cout << endl;

    return 0;
}