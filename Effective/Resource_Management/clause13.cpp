/*
by author heng  20-11-26
�Ѷ��������Դ p61

?????????????

<memory>
auto_ptr ����ָ��  auto_ptr������ʱ���Զ�ɾ������ָ��
ע�����auto_ptrͬʱָ��ͬһ������

1��Ϊ��ֹ��Դй©����ʹ��RAII���������ڹ��캯���л����Դ�������������ͷ���Դ
2����������ʹ�õ�RAII class��Ϊ�ֱ���tr1::shared_ptr �� auto_ptr.ǰ��ͨ���ǽϼ�ѡ��
   ��Ϊ��copy��Ϊ�Ƚ�ֱ�ۡ���ѡ��auto_ptr�����ƶ�����ʹ�����������ָ��null

*/

#include <memory>
#include <iostream>
using namespace std;

class Investment {

};

Investment* createInvestment() {
    return new Investment();
}

void f() {
    /* Investment* pInv = createInvestment();
    delete pInv; */                                       //�ֶ��ͷŶ���

    auto_ptr<Investment> pInv(createInvestment());        //ͨ��auto_ptr�����������Զ�ɾ��pInv

    auto_ptr<Investment> pInv2(pInv);
    //pInv == pInv2;                                      //����ͬʱָ��һ������-- null -----????

    shared_ptr<Investment> sharedPtrpInv(createInvestment());
    shared_ptr<Investment> sharedPtrpInv2(sharedPtrpInv);
    sharedPtrpInv = sharedPtrpInv2;                       //���ᱨ��   sharedPtrpInv and sharedPtrpInv2 ��������ָ�Ķ���Ҳ�ᱻ����
 
    //auto_ptr<string> aps(new string[10]);               //auto_ptr �����������õ���delete ����delete[]
}

int main(int agrc, char const *agrv[]) {
    f();
    return 0;
}