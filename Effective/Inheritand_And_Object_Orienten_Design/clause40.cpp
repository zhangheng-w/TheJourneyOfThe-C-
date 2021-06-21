/*
 * Created by weyiua on 2021/6/20.
 * 40. 明智而审慎地使用多重继承
 *
 * 多继承 --- 将"public继承自其某接口"和"private继承自某实现"结合在一起
 *
 * * 多重继承比单一继承复杂。它可能导致新的歧义性，以及对其virtual继承的需要。
 * * virtual继承会增加大小、速度、初始化(及赋值)复杂度等等成本，如果virtual base class不带任何数据，将是最具有使用价值的情况
 * * 多重继承的确有正当用途，其中一个情节涉及"public继承某个Interface class" 和 "private继承某个协助实现的class"的两相结合
 */

#include <iostream>
#include <string>
#include <cstring>
#include <memory>
using namespace std;

class BorrowableItem {
public:
    void checkOut() { cout << "BorrowableItem::checkOut\n"; }
};
class ElectronicGadget {
private:
    bool checkout() const { cout << "ElectronicGadget::checkOut\n"; return true; }
};

class MP3Player : public BorrowableItem, public ElectronicGadget {

};

void testMI() {
    MP3Player mp;
    mp.checkOut();
    //mp.ElectronicGadget::checkOut(); err私有成员
}

//err 砖石型多重继承
class File {};
class InputFile : public File {};
class OutFile : public File {};
class IOFile : public InputFile, public OutFile {};

/*
 * virtual继承
 * virtual base的初始化责任是有继承体系中的最底层(most derived)class负责的
 * 1. class若派生自virtual base而需要初始化，必须认知其virtual base 无论那些base距离多远
 * 2. 当一个新的virtual class加入继承体系中，它必须承担其virtual base的初始化责任(不论直接或间接)
 */
class InputFileVir : virtual public File {};
class OutFileVir : virtual public File {};
class IOFileVir : public InputFile, public OutFile {};


class DataBaseID {};
class IPerson {
public:
    virtual ~IPerson() {}
    virtual string name() const = 0;
    virtual string birthDate() const = 0;
};

DataBaseID askUserForDataBaseID() {
    return DataBaseID();
}

shared_ptr<IPerson> make_Person(DataBaseID personIdentifier) {
    return shared_ptr<IPerson>();
}

void testDataFactory() {
    DataBaseID id(askUserForDataBaseID());
    shared_ptr<IPerson> pp(make_Person(id));
    cout << pp.use_count() << "\t" << pp.get() << endl;
}


class PersonInfo {
public:
    explicit PersonInfo(DataBaseID pid) : id(pid) {}
    virtual ~PersonInfo() {}
    virtual const char* theName() const ;
    virtual const char* thebirthDate() const { return ""; }

private:
    virtual const char* valueDelimOpen() const ;
    virtual const char* valueDelimClose() const ;

    const char *name;
    DataBaseID id;
};

const int Max_ForMatted_Field_Value_Lenght = 100;

const char* PersonInfo::valueDelimOpen() const {
    return "[";
}

const char* PersonInfo::valueDelimClose() const {
    return "]";
}

const char* PersonInfo::theName() const {
    static char value[Max_ForMatted_Field_Value_Lenght];
    strcpy(value, valueDelimOpen());
    strcat(value, name );
    strcat(value, valueDelimClose());
    return value;
}

class CPerson : public IPerson, private PersonInfo {
public:
    explicit CPerson(DataBaseID pid) : PersonInfo(pid) {}
    virtual string name() const {
        return PersonInfo::theName();
    }
    virtual string birthDate() const {
        return PersonInfo::thebirthDate();
    }
};

void testMIPublicPrivate() {
    DataBaseID id;
    CPerson cp(id);
    cout << cp.name();
}

//多继承 --- 将"public继承自其某接口"和"private继承自某实现"结合在一起

int main(int agrc, const char *agrv[]) {

    testMI();
    testDataFactory();
    testMIPublicPrivate();
    return 0;
}


