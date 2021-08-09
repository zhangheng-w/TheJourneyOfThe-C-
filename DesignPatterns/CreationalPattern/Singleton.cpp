/*
 * Created by weyiua on 2021/8/2.
 * 设计模式 单例模式 Singleton
 * 构造函数私有化，不允许调用
 * 静态私有成员 静态公开函数-->构造对象或者返回对象
 * 解决内存泄漏问题
 * 使用智能指针
 * 使用静态的嵌套类对象
 *
 * 角色
 * Singleton：单例
 */

#include <iostream>
using namespace std;

//单例模式 SingLeton类
class SingLeton {
public:
    static SingLeton* getInstance() {
        if(_instance == nullptr) {
            _instance = new SingLeton();
        }
        return _instance;
    }

    void printInstance() {
        cout << "constructor SingLeton" << endl;
    }

private:
    static SingLeton* _instance;

    SingLeton() {}
    SingLeton(const SingLeton&) {}
    SingLeton& operator=(const SingLeton&) { return *_instance; }
    ~SingLeton() {
        cout << "destructor SingLeton" << endl;
    }

};
//实现内部静态成员初始化
SingLeton* SingLeton::_instance = nullptr;

void testSingLeton() {
    //内存泄漏没有释放内存
    SingLeton* inst = SingLeton::getInstance();
    inst->printInstance();
}

int main(int agrc, const char *agrv[]) {
    testSingLeton();
    return 0;
}
