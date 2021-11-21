//
// Created by JakeLin on 2021/11/1.
//

/**
 * 懒汉模式
 */
class Singleton {
public:
    static Singleton* getInstance();

private:
    Singleton();

    static Lock; // 并发锁
    static Singleton* INSTANCE;
};
Singleton* Singleton::INSTANCE = nullptr;

// 线程不安全版本
Singleton* Singleton::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new Singleton();
    }
    return INSTANCE;
}

// 线程安全版本
Singleton* Singleton::getInstance() {
    if (INSTANCE == nullptr) {
        // Lock 并发锁
        if (INSTANCE == nullptr) {
            INSTANCE = new Singleton();
        }
        // UnLock
    }
    return INSTANCE;
}
