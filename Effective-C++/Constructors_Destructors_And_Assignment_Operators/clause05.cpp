/*
by author heng  20-11-23
了解c++默默编写并调用那些函数 p34

class ->
    默认构造函数
    copy构造函数
    copy assignment(赋值)函数
    析构函数

1、编译器可以暗自为class创建default构造函数、copy构造函数、copy assignment操作符，以及析构函数
*/

#include <iostream>
#include <string>
using namespace std;

class Empty {
public :
    Empty() {}                                    //默认构造函数
    Empty(const Empty& rhs) { *this = rhs; }      //copy构造函数
    ~Empty() {}                                   //析构函数

    Empty& operator=(const Empty& rhs) {          //copy assignment(赋值)函数
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
    //NameObjectSt& operator=(const NameObjectSt& c) {}     //遇到referneces和const类型成员变量--需自己定义copy assignment(赋值)函数
                                                            //或copy assignment(赋值)函数定义为私有
private :
    string& _nameValue;
    const T _objectValue;
    
};

void nameObjectStTest() {
    string newDog("Persephone");
    string oldDog("Satch");
    NameObjectSt<int> p(newDog, 2);
    NameObjectSt<int> s(oldDog, 36);
    //p = s;                                                 //报错
}

int main(int argc, char const *argv[]){
    emptyTest();
    nameObjectTest();
    return 0;
}
