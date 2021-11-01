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

    static Singleton* instance;
};

Singleton::instance = new Singleton();

Singleton* Singleton::getInstance() {
    return instance;
}
