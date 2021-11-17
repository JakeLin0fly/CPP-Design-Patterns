//
// Created by JakeLin on 2021/11/12.
//
#include <bits/stdc++.h>
using namespace std;

/**
 * 现需设计实现一个视频播放器，有多个版本，分别支持不同的操作系统、解码不同的视频格式。
 * 如：Windows系统+AVI视频格式，Mac系统+RMVB视频格式等。
 * 类图：https://gitee.com/jakel-in/images/raw/master/2021-11/Bridge-Pattern-Example.png
 */

// 实现接口角色：解码器
class Decoder {
public:
    virtual ~Decoder() = default;
    virtual void decode(string video) = 0;
};

// 具体实现角色：AVI解码器
class AviDecoder : public Decoder {
public:
    virtual void decode(string fileName) {
        cout << "decode avi file : " << fileName;
    }
};
// 具体实现角色：RMVB解码器
class RmvbDecoder : public Decoder {
public:
    virtual void decode(string fileName) {
        cout << "decode rmvb file : " << fileName;
    }
};

// 抽象角色：操作系统
class OperatingSystem {
public:
    OperatingSystem(Decoder *decoder) : m_decoder(decoder) {}
    virtual ~OperatingSystem() = default;

    virtual void play(string video) = 0;

protected:
    Decoder *m_decoder;
};

// 扩充抽象角色：具体操作系统 Windows
class Windows : public OperatingSystem {
public:
    Windows(Decoder *decoder) : OperatingSystem(decoder) {}

    virtual void play(string video) {
        cout << "Play on Windows ";
        m_decoder->decode(video);
    }
};
// 扩充抽象角色：具体操作系统 Mac
class Mac : public OperatingSystem {
public:
    Mac(Decoder *decoder) : OperatingSystem(decoder) {}

    virtual void play(string video) {
        cout << "Play on Mac ";
        m_decoder->decode(video);
    }
};

// ========= 测试 =========
int main() {
    Decoder *aviDecoder = new AviDecoder();
    Decoder *rmvbDecoder = new RmvbDecoder();

    OperatingSystem *win = new Windows(aviDecoder);
    win->play("Titanic");
    cout << endl;

    OperatingSystem *mac = new Mac(rmvbDecoder);
    mac->play("Titanic");
    cout << endl;

    return 0;
}