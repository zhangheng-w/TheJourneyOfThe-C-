/*
by author heng  20-11-28
让接口容易被正确使用，不易被勿用

1、好的借口很容易被使用，不容易被误用。你应该在你的所有接口中努力达成这些性质
2、“促进正确使用”的办法包括接口的一致性，以及于内置行为的兼容
3、“阻止误用”的办法是建立新类型、限制类型上的操作，束缚对象值，以及消除客户资源管理责任
4、str1::shared_ptr支持定制型删除器（custom delete）。这可防范DLL问题，可被用来自动解除互斥锁（mutexes）
*/

#include <memory>

using namespace std;

class Date {
public :
    Date(const int& month, const int& day, const int& year) : _month(month), _day(day), _year(year) {}

private :
    int _month;
    int _day;
    int _year;
};

void testDate_1() {
    Date date(123, 12, 1);    //调用没错，但是不是我想要的结果
}


struct Day{
    explicit Day(const int& d) : val(d) {}
    int val;
};

/* struct Month{
    explicit Month(const int& m) : val(m) {}
    int val;
}; */

class Month {
public :
    static Month Jan() { return Month(1); }
    static Month Feb() { return Month(2); }
    //...
    static Month Dec() { return Month(12);}
private :
    explicit Month(int m) : _val(m) {}
    int _val;
};

struct Year{
    explicit Year(const int& y) : val(y) {}
    int val;
};

class DateToDMY {
public :
    DateToDMY(const Month& month, const Day& day, const Year& year) : _month(month), _day(day), _year(year) {}

private :
    Month _month;
    Day _day;
    Year _year;
};

void dateToDMYTest_1() {
    //DateToDMY(30, 3, 1999);                              //err 不正确的格式
    //DateToDMY(new Day(30), Month(3), Year(1999));        //err 不正确的格式
    //DateToDMY(Month(3), Day(30), Year(1999));
}


/* class Month {
public :
    static Month Jan() { return Month(1); }
    static Month Feb() { return Month(2); }
    //...
    static Month Dec() { return Month(12);}
private :
    explicit Month(int m) : _val(m) {}
    int _val;
}; */

void dateToDMYTest_2() {
    DateToDMY(Month::Jan(), Day(30), Year(1999));   //定义类型，—使用者不出错
}

class Inverstment {};

void getRidOfInverstment(Inverstment* p) { delete p; }

shared_ptr<Inverstment> createInverstment() {
    //shared_ptr<Inverstment> pInv(0, getRidOfInverstment);
    shared_ptr<Inverstment> retVal(static_cast<Inverstment* >(0), getRidOfInverstment);
    return retVal; 
}


int main(int agrc, char const *agrv[]) {
    testDate_1();
    dateToDMYTest_2();
    shared_ptr<Inverstment> pInv(createInverstment());
    return 0;
}