/*
by author heng  20-12-01
�������Ӻ��������ʽ�ĳ���ʱ��

<stdexcept>��--->�쳣�׳��Ķ��������

1���������Ӻ��������ʽ�ĳ��֡������������ӳ���������Ȳ����Ƴ���Ч��
*/

#include <string>
#include <stdexcept>

void encrypt(std::string& s) {}

std::string encryptPassword(const std::string& password) {
    using namespace std;
    int  MinimumPasswordLength = 10;
    if(password.length() < MinimumPasswordLength) {
        throw logic_error("Password is to short");    
    }                                                  //���쳣�׳�,�����ӳ���������ʽ�ĳ���ʱ��
    /* string encrypted;
    encrypted = password; */                           //��ֵ
    string encrypted(password);                        //copy���캯��
    encrypt(encrypted);
    return encrypted;
}

class Widget {};

void test() {
    //ѭ���������ԱȽϸ�Ч  iԽ��ѭ���ڻ���ȽϺ�
    //ѭ����
    Widget w;
    for (int i = 0; i < 100; ++i) {
        //w = 
    }

    //ѭ����
    for (int i = 0; i < 100; ++i) {
        Widget w();
    }
}

int main(int agrc, char const *agrv[]) {
    return 0;
}