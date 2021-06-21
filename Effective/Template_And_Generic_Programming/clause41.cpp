/*
 * Created by weyiua on 2021/6/21.
 * 41. �˽���ʽ�ӿڵı����ڶ�̬
 *
 * * class �� template��֧�ֽӿںͶ�̬
 * * ��class���Խӿڶ�����ʽ�ģ��Ժ���ǩ��Ϊ���ġ���̬����ͨ��virtual����������������
 * * ��template�������ԣ��ӿ�����ʽ�ģ��������Ч�ı��ʽ����̬����ͨ��template���廯�ͺ������ؽ��������ڱ�����
 */

#include <iostream>
using namespace std;

//��ʽ�ӿڣ������ڶ�̬
class Wight {
public:
    Wight() {}
    virtual ~Wight() {}
    virtual size_t size() const { return 11; }
    virtual void normalize() { cout << "Wight::normalizer\n"; }
    void swap(Wight& w) {}

    bool operator!=(Wight& w) {
        return true;
    }
};

Wight someNastyWidget;
void doProcessing(Wight& w) {
    if(w.size() > 10 && w != someNastyWidget) {
        Wight temp(w);
        temp.normalize();
        temp.swap(w);
    }
}

//someNastyWidget ���ͱ��������ʽת��T  ���ܱȽ�!=
//����w����Ҫ�к���size normalize �� swap
template <typename T>
void doProcessingTemp(T& w) {
    if(w.size() > 10 && w != someNastyWidget) {
        T temp(w);
        temp.normalize();
        temp.swap(w);
    }
}

void testWight() {
    Wight w;
    doProcessing(w);
    doProcessingTemp<Wight>(w);
    //doProcessingTemp<int>(w); //err���Ͳ�ͬ
}

int main(int agrc, const char *agrv[]) {
    testWight();
    return 0;
}