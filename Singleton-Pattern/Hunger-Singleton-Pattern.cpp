//
// Created by JakeLin on 2021/11/1.
//

/**
 * 恶汉模式，线程安全
 */
class Singleton {
public:
    static Singleton* getInstance();

private:
    Singleton();

    static Singleton* INSTANCE;
};

Singleton* Singleton::INSTANCE = new Singleton();

Singleton* Singleton::getInstance() {
    return Singleton::INSTANCE;
}