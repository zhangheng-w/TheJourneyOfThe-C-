/*
by author heng  20-11-27
�ɶ�ʹ��new��deleteʱҪ������ͬ��ʽ

1���������new���ʽ��ʹ��[]����������Ӧ��delete���ʽ��Ҳʹ��[]
   �������new���ʽ�в�ʹ��[]��һ����Ҫ��delete���ʽ��ʹ��[]
*/
#include <string>
using namespace std;

void test() {
    string* stringArray = new string[10];
    //delete stringArray;       //err
    delete[] stringArray; 

    //�ɶ�ʹ�ã�������ͬ
    string* stringPtr1 = new string;
    string* stringPtr2 = new string[100];
    delete stringPtr1;
    delete[] stringPtr2;

    //��ò�Ҫ��������ʽ��typedef����
    typedef string AddressLine[4];
    string* ptr = new AddressLine;
    delete[] ptr;
}

int main(int agrc, char const *agrv[]) {
    test();
    return 0;
}
