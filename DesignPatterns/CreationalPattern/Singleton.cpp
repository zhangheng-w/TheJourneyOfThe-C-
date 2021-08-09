/*
 * Created by weyiua on 2021/8/2.
 * ���ģʽ ����ģʽ Singleton
 * ���캯��˽�л������������
 * ��̬˽�г�Ա ��̬��������-->���������߷��ض���
 * ����ڴ�й©����
 * ʹ������ָ��
 * ʹ�þ�̬��Ƕ�������
 *
 * ��ɫ
 * Singleton������
 */

#include <iostream>
using namespace std;

//����ģʽ SingLeton��
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
//ʵ���ڲ���̬��Ա��ʼ��
SingLeton* SingLeton::_instance = nullptr;

void testSingLeton() {
    //�ڴ�й©û���ͷ��ڴ�
    SingLeton* inst = SingLeton::getInstance();
    inst->printInstance();
}

int main(int agrc, const char *agrv[]) {
    testSingLeton();
    return 0;
}
