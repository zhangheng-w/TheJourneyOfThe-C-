/*
 * Created by weyiua on 2021/2/17.
 * 35、考虑virtual函数以外的其他选择
 *
 * 1. 使用non-virtual interface(NVI)手法，那是Template Medthod设计模式的一种特殊模式。
 *    它以public non-virtual成员函数包裹较低访问性(private 或 protected)的virtual函数
 * 2. 将virtual函数替换为"函数指针成员函数"，这是Strategy设计模式的一种分解表现形式
 * 3. 以tr1::function成员函数替换virtual函数，因而允许使用任何可调用物搭配一个兼容于需求的签名式
 *    ，这也是Strategy设计模式的某种形式
 * 4. 将继承体系内的virtual函数替换为另一个继承体系内的virtual函数，这是Strategy设计模式的传统手法
 *
 * * virtual函数的替代方案包括NVI手法及Strategy设计模式的多种形式，NVI手法自身是一个特殊形式的template Method设计模式
 * * 将机能从成员函数移到class外部函数，带来的一个缺点是，非成员函数无法访问class的non-public成员
 * * tr1::function对象的行为就像一般函数指针，这样的对象可接纳"与给定之目标签名式兼容"的所有可调用物
 *
*/
#include <iostream>
using namespace std;

class GameCharacter {
public:
    virtual int haelthVaule() const;
};

//non virtual interface的手法
//间接调用 virtual--vitual函数设置为private
class GameCharacterTONVI{
public:
    int headlthValue() const {
        int retVal = doHeadlthValue();
        return retVal;
    }

private:
    virtual int doHeadlthValue() const {
        return 1;
    }
};


class GameCharacterTwo;
int defaultHealthCalc(const GameCharacterTwo& gc);
class GameCharacterTwo {
public:
    typedef int (*HeadlthCalcFunc) (const GameCharacterTwo&);     //函数指针 typedef重定义名字
    explicit GameCharacterTwo(HeadlthCalcFunc hcf = defaultHealthCalc) : headthFunc(hcf) {} //explicit 防止隐式转换 +构造函数
    int healthValue() const {
        return headthFunc(*this);
    }

private:
    HeadlthCalcFunc headthFunc;
};

class EvilBadGuy : public GameCharacterTwo {
public :
    explicit EvilBadGuy(HeadlthCalcFunc hcf = defaultHealthCalc) : GameCharacterTwo(hcf) {}

};

int loseHealthQuickly(const GameCharacterTwo&) { return 100; }
int loseHealthSlowly(const GameCharacterTwo&) { return 1; }

void TestNVI() {

    //通过函数指针传参数
    EvilBadGuy ebg1(loseHealthQuickly);
    EvilBadGuy ebg2(loseHealthSlowly);

    cout << ebg1.healthValue() << endl;
    cout << ebg2.healthValue() << endl;
}

//古典的Strategy模式
class GameCharacterStrate;
class HealthCalacFuncStrate {
public:
    explicit HealthCalacFuncStrate(const int num = 0) : nums(num) {}

    virtual int calc(const GameCharacterStrate& gc) const {
        return 0;
    }

private:
    int nums;
};

//默认 构造函数参数
HealthCalacFuncStrate defaultHealthCalcStratr;
class GameCharacterStrate {
public:
    explicit GameCharacterStrate(HealthCalacFuncStrate* phcf = &defaultHealthCalcStratr) : pHealthCalc(phcf) {}
    int healthValue() const {
        return pHealthCalc->calc(*this);
    }

private:
    HealthCalacFuncStrate* pHealthCalc;
};


void strategyTest() {
}

int main(int agrc, const char *agrv[]) {
    TestNVI();
    strategyTest();
    return 0;
}