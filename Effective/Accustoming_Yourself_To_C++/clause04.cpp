/*
by author heng  20-11-22
ȷ�϶���ʹ��ǰ���ȱ���ʼ�� p26

local �ֲ���

1��Ϊ�����Ͷ�������ֹ���ʼ��
2�����캯�����ʹ�ó�Ա��ֵ�У�����Ҫ�ں���������ʹ�ø�ֵ����
   ��ֵ���г��ĳ�Ա�����������д���Ӧ�ú�class������������ͬ
3��Ϊ���"����뵥Ԫ֮��ʼ������"���⣬ ����local static(�ֲ���̬)�����滻non-local static(�Ǿֲ���̬)����
*/

#include <string>
#include <list>
using namespace std;

class PhoneNumber {
private:
};

class ABEntry{
private:
    ABEntry();
    ABEntry(const string& name, const string& address, const list<PhoneNumber> thePhones);


private:
    string _theName;
    string _theAddress;
    list<PhoneNumber> _thePhones;
    int _numTimesConsulted;
};

ABEntry::ABEntry()                                                           //default���캯��
    : _theName(), _theAddress(), _thePhones(), _numTimesConsulted(0) {}      //�����������͵Ĺ��캯��

/*//��Ա������ֵ
ABEntry::ABEntry(const string& name, const string& address, const list<PhoneNumber> thePhones) {
    _theName = name;
    _theAddress = address;
    _thePhones = thePhones;
    _numTimesConsulted = 0;
}
*/

//��Ա������ʼ��
ABEntry::ABEntry(const string& name, const string& address, const list<PhoneNumber> thePhones) 
    : _theName(name), _theAddress(address), _thePhones(thePhones), _numTimesConsulted(0) {}



class FileSystem {
public :
    size_t numDists() const;
};
    extern FileSystem tfs;


/*
FileSystem& tfs() {
    static FileSystem fs;
    return fs;
}


class Diectory {
public :
    Diectory(params) ;
    
};


Diectory tempDir(params);
Diectory& tempDir() {
    static Diectory td;
    return td;
}
*/

int main(int agrc, const char *agrv[]) {

    return 0;
}