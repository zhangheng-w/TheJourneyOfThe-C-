/*
 * Created by weyiua on 2021/6/20.
 * 40. ���Ƕ�������ʹ�ö��ؼ̳�
 *
 * ��̳� --- ��"public�̳�����ĳ�ӿ�"��"private�̳���ĳʵ��"�����һ��
 *
 * * ���ؼ̳бȵ�һ�̳и��ӡ������ܵ����µ������ԣ��Լ�����virtual�̳е���Ҫ��
 * * virtual�̳л����Ӵ�С���ٶȡ���ʼ��(����ֵ)���Ӷȵȵȳɱ������virtual base class�����κ����ݣ����������ʹ�ü�ֵ�����
 * * ���ؼ̳е�ȷ��������;������һ������漰"public�̳�ĳ��Interface class" �� "private�̳�ĳ��Э��ʵ�ֵ�class"��������
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
    //mp.ElectronicGadget::checkOut(); err˽�г�Ա
}

//err שʯ�Ͷ��ؼ̳�
class File {};
class InputFile : public File {};
class OutFile : public File {};
class IOFile : public InputFile, public OutFile {};

/*
 * virtual�̳�
 * virtual base�ĳ�ʼ���������м̳���ϵ�е���ײ�(most derived)class�����
 * 1. class��������virtual base����Ҫ��ʼ����������֪��virtual base ������Щbase�����Զ
 * 2. ��һ���µ�virtual class����̳���ϵ�У�������е���virtual base�ĳ�ʼ������(����ֱ�ӻ���)
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

//��̳� --- ��"public�̳�����ĳ�ӿ�"��"private�̳���ĳʵ��"�����һ��

int main(int agrc, const char *agrv[]) {

    testMI();
    testDataFactory();
    testMIPublicPrivate();
    return 0;
}


