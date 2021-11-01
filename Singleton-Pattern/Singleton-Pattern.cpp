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

////////////////////////////////////////////////

/**
 * 恶汉模式
 */
class Singleton {
public:
    static Singleton* getInstance();

private:
    Singleton();

    static Lock; // 并发锁
    static Singleton* instance;
};
Singleton::instance = nullptr;

// 线程不安全版本
Singleton* Singleton::getInstance() {
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}

// 线程安全版本
Singleton* Singleton::getInstance() {
    if (instance == nullptr) {
        // Lock 并发锁
        if (instance == nullptr) {
            instance = new Singleton();
        }
        // UnLock
    }
    return instance;
}