/*
by author heng  20-11-28
�ýӿ����ױ���ȷʹ�ã����ױ�����

1���õĽ�ں����ױ�ʹ�ã������ױ����á���Ӧ����������нӿ���Ŭ�������Щ����
2�����ٽ���ȷʹ�á��İ취�����ӿڵ�һ���ԣ��Լ���������Ϊ�ļ���
3������ֹ���á��İ취�ǽ��������͡����������ϵĲ�������������ֵ���Լ������ͻ���Դ��������
4��str1::shared_ptr֧�ֶ�����ɾ������custom delete������ɷ���DLL���⣬�ɱ������Զ������������mutexes��
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
    Date date(123, 12, 1);    //����û�����ǲ�������Ҫ�Ľ��
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
    //DateToDMY(30, 3, 1999);                              //err ����ȷ�ĸ�ʽ
    //DateToDMY(new Day(30), Month(3), Year(1999));        //err ����ȷ�ĸ�ʽ
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
    DateToDMY(Month::Jan(), Day(30), Year(1999));   //�������ͣ���ʹ���߲�����
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