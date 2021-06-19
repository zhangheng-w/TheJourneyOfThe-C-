/*
 * Created by weyiua on 2021/2/17.
 * 35������virtual�������������ѡ��
 *
 * 1. ʹ��non-virtual interface(NVI)�ַ�������Template Medthod���ģʽ��һ������ģʽ��
 *    ����public non-virtual��Ա���������ϵͷ�����(private �� protected)��virtual����
 * 2. ��virtual�����滻Ϊ"����ָ���Ա����"������Strategy���ģʽ��һ�ַֽ������ʽ
 * 3. ��tr1::function��Ա�����滻virtual�������������ʹ���κοɵ��������һ�������������ǩ��ʽ
 *    ����Ҳ��Strategy���ģʽ��ĳ����ʽ
 * 4. ���̳���ϵ�ڵ�virtual�����滻Ϊ��һ���̳���ϵ�ڵ�virtual����������Strategy���ģʽ�Ĵ�ͳ�ַ�
 *
 * * virtual�����������������NVI�ַ���Strategy���ģʽ�Ķ�����ʽ��NVI�ַ�������һ��������ʽ��template Method���ģʽ
 * * �����ܴӳ�Ա�����Ƶ�class�ⲿ������������һ��ȱ���ǣ��ǳ�Ա�����޷�����class��non-public��Ա
 * * tr1::function�������Ϊ����һ�㺯��ָ�룬�����Ķ���ɽ���"�����֮Ŀ��ǩ��ʽ����"�����пɵ�����
 *
*/
#include <iostream>
using namespace std;

class GameCharacter {
public:
    virtual int haelthVaule() const;
};

//non virtual interface���ַ�
//��ӵ��� virtual--vitual��������Ϊprivate
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
    typedef int (*HeadlthCalcFunc) (const GameCharacterTwo&);     //����ָ�� typedef�ض�������
    explicit GameCharacterTwo(HeadlthCalcFunc hcf = defaultHealthCalc) : headthFunc(hcf) {} //explicit ��ֹ��ʽת�� +���캯��
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

    //ͨ������ָ�봫����
    EvilBadGuy ebg1(loseHealthQuickly);
    EvilBadGuy ebg2(loseHealthSlowly);

    cout << ebg1.healthValue() << endl;
    cout << ebg2.healthValue() << endl;
}

//�ŵ��Strategyģʽ
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

//Ĭ�� ���캯������
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