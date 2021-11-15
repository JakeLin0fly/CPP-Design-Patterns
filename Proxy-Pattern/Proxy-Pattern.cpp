//
// Created by JakeLin on 2021/11/15.
//
/**
 * 以前交通、互联网没那么发达，购买火车票可以在火车站直接购买，但通常人们是在车票代售点进行购买。
 * 这个例子中火车站是目标对象，代售点是代理对象。
 */
#include <bits/stdc++.h>

// 抽象主题（买票接口）
class SellTickets {
public:
    SellTickets() = default;
    virtual ~SellTickets() = default;

    virtual void sell() = 0;
};

// 具体主题（代理目标）：火车站
class TrainStation : public SellTickets {
public:
    virtual void sell() {
        std::cout << "sell ticket from train station" << std::endl;
    }
};

// 代理：代售点
class ProxyPoint : public SellTickets {
public:
    virtual void sell() {
        std::cout << "proxy point charges handling fees, ";
        station.sell();
    }

private:
    TrainStation station;
};


// 测试：客户通过代售点购票
int main() {
    ProxyPoint proxyPoint;
    proxyPoint.sell();

    return 0;
}