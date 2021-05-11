/*
by author heng  20-11-21
尽可能使用const p17

const_iterator 迭代器指向的元素不可变 const

mutable(可变)

1、将某些东西声明为const可帮助编译器侦测出错误用法->
   const可以施加于任何作用域内的对象、函数参数、函数返回类型、成员函数本体
2、当const和non-const成员函数有着实质等价的实现时，令non-const版本调用const版本可避免代码重复。
*/

#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

//const修饰常量  const在*左边表示指物是常量，右边指针本身是常量
char gteeting[] = "hello";
char *p = gteeting;                       //non-const pointer, non-const data
const char* p1 = gteeting;                //non-const pointer, const data
char* const p2 = gteeting;                //const pointer, ono-const data
const char* const p3 = gteeting;          //const pointer, const data

void testConstPointer( ostream &os = cout ) {
    os << "p=" << p << "\n"
       << "p1=" << p1 << "\n"
       << "p2=" << p2 << "\n"
       << "p3=" << p3 << "\n";
    p = NULL;
    p1 = nullptr;
    //gteeting = "da";                    //const char* p1----p1指向物是常量
    //p2 = nullptr;                       //char* const p2---p2是指针常量
    os << "p=" << p << "\n";
}

void f1(const char* c);      //c是指针指向一个常量
void f1(char const* c);      //一样

/*
stl中iterator迭代器类似于T* 
iter不变，不得指向不同的东西，iter指向东西的值可以改变
*/
void iteratorConstTest() {
    vector<int> vec;
    const vector<int>::iterator iter = vec.begin();  //iter 的作用像 T* const
    *iter = 10;
    //++iter;                                        //报错
    vector<int>::const_iterator cIter = vec.begin(); //cIter 的作用像 const T*
    //*cIter = 10;                                   //报错
    ++cIter;
}


//const成员函数
class TextBlock {
public :
    TextBlock(const string& str) : text(str) {}
    const char& operator[] ( size_t position ) const { return text[position]; }   //operator[] for cosnt对象
    char& operator[] ( size_t position ) { return text[position]; }               //operator[] for non-const对象
private:
    string text;
};

void textBlocktest() {
    TextBlock tb("hello");
    const TextBlock ctb("world");
    cout << "tb[0]=" << tb[0] << "\n"
         << "ctb[0]=" << ctb[0] << "\n";
    tb[0] = '1';
    cout << "tb[0]=" << tb[0];
    //ctb[0] = '1';           //ctb是const对象可以调用对象中-const函数
}


class CTextBlock {
public:
    CTextBlock(char* c) : _pText(c) {}
    std::size_t length() const;
    char* pText() const { return _pText; }
    bool lengthIsValid() const { return _lengthIsValid; }

private:
    char* _pText;
    mutable size_t _textLength;
    mutable bool _lengthIsValid;
};

size_t CTextBlock::length() const {             //const函数内中不能赋值  mutable(可变)成员变量
    if(!_lengthIsValid) {
        _textLength = strlen(_pText);
        _lengthIsValid = true;
    }
    return _textLength;
}

void cTextBlockTest() {
    char p[] = "1231";
    CTextBlock ctb(p);
    cout << "ctb.pText()=" << ctb.pText() << "\n"
         << "ctb.length()=" << ctb.length() << "\n"
         << "ctb.lengthIsValid()=" << ctb.lengthIsValid();

}

int main(int argc, char const *argv[])
{
    //testConstPointer();
    //textBlocktest();
    cTextBlockTest();
    return 0;
}
