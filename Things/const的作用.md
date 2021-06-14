# const

### class外部可以修饰作用域中的变量，或修饰文件、函数、或区块作用域中被声明为static的对象、class内部的static和non-static成员变量。面对指针，可以指出指针本身、指针所指物、或俩者都(或都不)是const

## 常量
关键字const在\***左边**表示**被指物是常量**；在\***右边**表示**指针自身是常量**；两边都出现表示被指物和指针都是常量

```cpp
char data[] = "hello";
char* p = data;                      //non-cosnt pointer,non-const data
const char* p = data;                //non-cosnt pointer,const data
char* const p = data;                //cosnt pointer,non-const data
const char* const p = data;          //cosnt pointer,const data

std::vector<int> vec;
const std::vector<int>::iterator iter = vec.begin();
*iter = 10;                          //iter就像一个T* const 指针不可变
++iter;                              //err const指针不可变

std::vector<int>::const_itreator cItre = vec,begin();
*cIter = 10;                         //err cIter就像一个const T* 所指物不变
++cIter;                             //指针改变
```

## 成员函数
目的
1. 它使class接口比较容易被理解，因为得知那个函数可以改变对象内容而那个函数不行  
2. 它使操作const对象成为可能

真实程序中cosnt对象大多用于passed by pointer-to-const 或 passed by reference-to-const的传递结果。  
**在const成员函数不能给成员变量的值进行修改**！需要加上关键字mutable（可变的），mutable释放掉non-static成员变量的bitwise constness约束

~~~cpp
//operator 调用自身
class Text{
public:
    ...
    const char& operator[](std::size_t position) const
    {return text[position];}
    char& operator[](std::size_t position)
    {return text[position];}

private:
    std::string text;
};

Text t("hello");                     //调用non-const Text::operator
std::cout << t[0];
t[0] = 'X';

const Text ct("word");               //调用const Text::operator
std::cout << ct[0];
ct[0] = 'X';                         //err const Text 不可写

class CText{
public:
    ...
    std::size_t length() const;      //const函数不会改变其中的数据

private:
    char* PText;
    mutable std::size_t textLength;  //mutable 关键字使成员变量可能总是
    mutable bool lengthIsValid;      //被改变，即使在const成员函数中
};

std::size_t CText::length() const
{
    if(!lengthIsValid){
        textLength = std::strlen(pText);
        lengthIsValid = true;
    }
    return textLength;
}
~~~

## 避免const和non-const成员函数中避免重复
在const和non-const成员函数有着实质等价的实现时，令non-const版本调用const版本避免重复  
const成员函数承诺绝不改变其对象的逻辑状态，non-const成员函数没有这样的承诺，用const_cast将*this身上的const性质解放掉。如下代码进行了两次转型

~~~cpp
class CText{
public:
    const char& operator[](std::size_t positon) const
    { return text[positon]; }

    char& operator[](std::size_t positon)
    {
        return const_cast<char&>(    //将op[]返回值const转除
            static_cast<const CText&>(*this)[position]);
    }
private:
    std::string text;
};
~~~

