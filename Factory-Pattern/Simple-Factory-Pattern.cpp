//
// Created by JakeLin on 2021/11/3.
//
#include <iostream>

using namespace std;

/**
 * 抽象产品
 */
class Shape {
public:
    virtual void draw() = 0;
};

/**
 * 具体产品：圆形
 */
class Circle : public Shape {
public:
    void draw() {
        cout << "draw a circle" << endl;
    }
};
/**
 * 具体产品：长方形
 */
class Rectangle : public Shape {
public:
    void draw() {
        cout << "draw a rectangle" << endl;
    }
};

/**
 * 工厂：负责实现创建所有实例的内部逻辑
 */
class ShapeFactory {
public:
    Shape * createShape(string name) {
        switch (name) {
            case "circle": return new Circle();
            case "rectangle": return Rectangle();
        }
        return nullptr;
    }
};
