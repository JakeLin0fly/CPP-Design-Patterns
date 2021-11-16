//
// Created by JakeLin on 2021/11/16.
//
#include <bits/stdc++.h>
using namespace std;
/**
 * ## 对象适配器示例 ##
 * 现有电脑仅有SD卡读写接口，而数据存储使用TF卡，
 * 此时就需要一个适配器（转接器），使得能通过电脑上仅有的SD卡接口实现对TF卡的读写。
 * 类图：https://gitee.com/jakel-in/images/raw/master/2021-11/Object-Adapter-Pattern.jpg
 */

// 卡读写接口
class Card {
public:
    virtual ~Card() = default;
    virtual string read() = 0;
    virtual void write(string msg) = 0;
};

//SD卡实现类
class SDCard : virtual public Card {
public:
    virtual ~SDCard() = default;
    // 从SD卡读数据
    virtual string read() {
        return "SD card read a msg: hello word SD";
    }
    // 往SD卡写数据
    virtual void write(string msg) {
        cout << "SD card write msg : " << msg << endl;
    }
};

//TF卡实现类
class TFCard : virtual public Card {
public:
    virtual ~TFCard() = default;
    // 从TF卡读数据
    virtual string read() {
        return "TF card read a msg: hello word TF";
    }
    // 往TF卡写数据
    virtual void write(string msg) {
        cout << "TF card write msg : "<< msg << endl;
    }
};

// 电脑类，仅支持SD卡
class Computer {
public:
    Computer(SDCard *sd) : sdCard(sd) {}
    string readSD() {
        return sdCard->read();
    }
    void writeSD(string msg) {
        sdCard->write(msg);
    }

private:
    SDCard *sdCard;
};

//定义适配器类（SD兼容TF）
class AdapterSD_TF : public SDCard {
public:
    AdapterSD_TF(TFCard *tf) : tfCard(tf) {}
    string read() {
        cout << "adapter read TF card, ";
        return tfCard->read();
    }
    void write(string msg) {
        cout << "adapter write TF card, ";
        tfCard->write(msg);
    }

private:
    TFCard *tfCard;
};

// 模拟Client读写测试
int main() {
    // 电脑A：未接适配器
    Computer *computer_A = new Computer(new SDCard);

    AdapterSD_TF *adapterSdTf = new AdapterSD_TF(new TFCard);
    // 电脑B：接上适配器
    Computer *computer_B = new Computer(adapterSdTf);

    cout << "============= test reading =============" << endl;
    cout << "Computer A(no Adapter): \n\t" << computer_A->readSD() << endl;
    cout << "Computer B(with Adapter): \n\t" << computer_B->readSD() << endl;


    cout << endl << "============= test writing =============" << endl;
    cout << "Computer A(no Adapter): \n\t";
    computer_A->writeSD("test writing");
    cout << "Computer B(with Adapter): \n\t";
    computer_B->writeSD("test writing");

    return 0;
}