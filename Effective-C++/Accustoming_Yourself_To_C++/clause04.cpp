/*
by author heng  20-11-22
确认对象使用前已先被初始化 p26

local 局部的

1、为内置型对象进行手工初始化
2、构造函数最好使用成员初值列，而不要在函数本体内使用赋值操作
   初值列列出的成员变量，其排列次序应该和class中声明次序相同
3、为免除"跨编译单元之初始化次序"问题， 请用local static(局部静态)对象替换non-local static(非局部静态)对象
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

ABEntry::ABEntry()                                                           //default构造函数
    : _theName(), _theAddress(), _thePhones(), _numTimesConsulted(0) {}      //调用引用类型的构造函数

/*//成员函数赋值
ABEntry::ABEntry(const string& name, const string& address, const list<PhoneNumber> thePhones) {
    _theName = name;
    _theAddress = address;
    _thePhones = thePhones;
    _numTimesConsulted = 0;
}
*/

//成员函数初始化
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