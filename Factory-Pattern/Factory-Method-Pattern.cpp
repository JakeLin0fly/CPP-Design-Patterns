//
// Created by JakeLin on 2021/11/4.
//

#include <iostream>
using namespace std;

/**
 * 抽象产品
 */
class Shape {
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
 * 具体产品：三角形
 */
class Rectangle : public Shape {
public:
    void draw() {
        cout << "draw a rectangle" << endl;
    }
};

/**
 * 抽象工厂
 */
class Factory {
public:
    virtual Shape * createShape() = 0;
};

/**
 * 具体工厂：圆形工厂
 */
class CircleFactory : Factory {
public:
    Shape * createShape() {
        return new Circle();
    }
};
/**
 * 具体工厂：三角形工厂
 */
class RectangleFactory : Factory {
public:
    Shape * createShape() {
        return new Rectangle();
    }
};