/*
by author heng  20-11-23
�˽�c++ĬĬ��д��������Щ���� p34

class ->
    Ĭ�Ϲ��캯��
    copy���캯��
    copy assignment(��ֵ)����
    ��������

1�����������԰���Ϊclass����default���캯����copy���캯����copy assignment���������Լ���������
*/

#include <iostream>
#include <string>
using namespace std;

class Empty {
public :
    Empty() {}                                    //Ĭ�Ϲ��캯��
    Empty(const Empty& rhs) { *this = rhs; }      //copy���캯��
    ~Empty() {}                                   //��������

    Empty& operator=(const Empty& rhs) {          //copy assignment(��ֵ)����
        //*this = rhs; 
        return *this; 
    }
};

void emptyTest() {
    Empty e1;
    Empty e2(e1);
    Empty e3 = e2;
}


template <typename T>
class NameObject {
public:
    NameObject( const char* name, const T& value ) : _nameValue(name), _objectValue(value) { }
    NameObject( const string& name, const T& value ) : _nameValue(name), _objectValue(value) { }
    NameObject( const NameObject& nameobject ) { this->_nameValue = nameobject._nameValue; this->_objectValue = nameobject._objectValue; }
    NameObject& operator=( const NameObject& nameobject ) { *this = nameobject; return *this; }
    ~NameObject() {}

    //??
    void operator<<( ostream& os ) { 
        os << "_nameValue=" << this->_nameValue << "\n"
           << "_objectValue=" << this->_objectValue << endl;   
    }
private :
    string _nameValue;
    T _objectValue;
};

void nameObjectTest() {
    NameObject<int> no1("Smallest prime Number", 2);
    NameObject<int> no2(no1);
    NameObject<int> no3 = no2;
    no1<<(cout);
    no2<<(cout);
    no3<<(cout);
}

template<typename T>
class NameObjectSt {
public :
    NameObjectSt(string& nameValue, const T& objectValue) : _nameValue(nameValue), _objectValue(objectValue) {}
    //NameObjectSt& operator=(const NameObjectSt& c) {}     //����referneces��const���ͳ�Ա����--���Լ�����copy assignment(��ֵ)����
                                                            //��copy assignment(��ֵ)��������Ϊ˽��
private :
    string& _nameValue;
    const T _objectValue;
    
};

void nameObjectStTest() {
    string newDog("Persephone");
    string oldDog("Satch");
    NameObjectSt<int> p(newDog, 2);
    NameObjectSt<int> s(oldDog, 36);
    //p = s;                                                 //����
}

int main(int argc, char const *argv[]){
    emptyTest();
    nameObjectTest();
    return 0;
}
