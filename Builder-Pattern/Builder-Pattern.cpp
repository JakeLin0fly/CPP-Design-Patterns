//
// Created by JakeLin on 2021/11/9.
//
#include <iostream>
#include <string>
using namespace std;

/**
 * 产品类
 */
class Computer {
public:
    // setter
    void setMainBoard(string mainBoard) {
        m_mainBoard = mainBoard;
    }
    void setCPU(string cpu) {
        m_cpu = cpu;
    }
    void setRam(string ram) {
        m_ram = ram;
    }
    void setDisk(string disk) {
        m_disl = disk;
    }
    void setDisplay(string display) {
        m_display = display;
    }
    // getter 省略...
    string getMainBoard() {
        return m_mainBoard;
    }
private:
    string m_mainBoard; // 主板
    string m_cpu;       // CPU
    string m_ram;       // 内存
    string m_disk;      // 硬盘
    string m_display;   // 显示器
};

/**
 * 抽象建造者，非必要
 */
class Builder {
public:
    // 安装主板
    virtual void createMainBoard(string mainBoard) = 0;
    // 安装 cpu
    virtual void createCPU(string cpu) = 0;
    // 安装内存
    virtual void createRam(string ram) = 0;
    // 安装硬盘
    virtual void createDisk(string hardDisk) = 0;
    // 安装显示器
    virtual void createDisplay(string display) = 0;
    // 组成电脑
    virtual Computer build() = 0;
};

/**
 * 具体建造者
 */
class ConcreteBuilder : public Builder {
public:
    void createMainBoard(string mainBoard) {
        m_computer.setMainBoard(mainBoard);
    }
    void setCPU(string cpu) {
        m_computer.setCPU(cpu);
    }
    void createRam(string ram) {
        m_computer.setRam(ram);
    }
    void createDisk(string disk) {
        m_computer.setDisk(disk);
    }
    void createDisplay(string display) {
        m_computer.setDisplay(display);
    }

    Computer build() {
        return m_computer;
    }
private:
    Computer m_computer;
};

/**
 * 指挥者，非必要
 */
class Director {
public:
    Director(Builder builder) {
        m_builder = new Builder(builder);
    }

    Computer createComputer() {
        // 工作人员按顺序组装
        m_builder->createMainBoard("mainBoard");
        m_builder->createCpu("cpu") ;
        m_builder->createMemory("ram");
        m_builder->createhardDisk("disk");
        m_builder->createDisplay("display");

        return m_builder->build();
    }

private:
    Builder *m_builder;
};