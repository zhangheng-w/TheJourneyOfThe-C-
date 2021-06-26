/*
 * Created by heng on 2020/12/23.
 * 将文件间的编译依存关系将至最低
 *
 * 1、支持”编译依存最小化“的一般构想是：相依与声明式，不要相依于定义式。基于此构想的两Handle class和Interface class
 * 2、程序库头文件应该以”完全且仅有声明式“的形式存在。这种做法不论是否涉及template都使用
*/


#include <iosfwd>
#include <string>
#include <memory>
#include <iostream>
using namespace std;

class Date{};
class Address{};

class PersonImpl{
public:
    const string &Name() const {
        return name;
    }

    void Name(const string &name) {
        PersonImpl::name = name;
    }

    const Date &Birthday() const {
        return birthday;
    }

    void Birthday(const Date &birthday) {
        PersonImpl::birthday = birthday;
    }

    const Address &getAddress() const {
        return address;
    }

    void setAddress(const Address &address) {
        PersonImpl::address = address;
    }

private:
    string name;
    Date birthday;
    Address address;
};

class Person {
public:
    Person() {}
    /*Person(const string &theName, const Date &theBrithDate, const Address &theAddress) : theName(theName),
                                                                                         theBrithDate(theBrithDate),
                                                                                         theAddress(theAddress) {}

    const string &getTheName() const {
        return theName;
    }

    void setTheName(const string &theName) {
        Person::theName = theName;
    }

    const Date &getTheBrithDate() const {
        return theBrithDate;
    }

    void setTheBrithDate(const Date &theBrithDate) {
        Person::theBrithDate = theBrithDate;
    }

    const Address &getTheAddress() const {
        return theAddress;
    }

    void setTheAddress(const Address &theAddress) {
        Person::theAddress = theAddress;
    }*/

    string name() const {
        return pImpl->Name();
    }
    string birthDate() const;
    string address() const;


private:
    /*string theName;
    Date theBrithDate;
    Address theAddress;*/
    shared_ptr<PersonImpl> pImpl;
};

Date today();
void clearAppointments(Date d);


//接口 纯虚函数
class PersonInterface {
public:
    virtual ~PersonInterface();
    virtual string name() const = 0;
    virtual Date birthDate() const = 0;
    virtual Address address() const = 0;

    static shared_ptr<Person> create(const string &theName, const Date &theBrithDate, const Address &theAddress) {
        cout << "this PersonInterface class\n";
        return shared_ptr<Person>();
    }
};

class RealPerson : public Person {
public:
    RealPerson(const string &theName, const Date &theBirthday, const Address &theAddress) : theName(theName),
                                                                                            theBirthday(theBirthday),
                                                                                            theAddress(theAddress) {}

    virtual ~RealPerson() {}
    string name() const {}
    Date birthday() const {}
    Address address() const {}

    static shared_ptr<Person> create(const string &theName, const Date &theBrithDate, const Address &theAddress) {
        cout << "this RealPerson class\n";
        return shared_ptr<Person>( new RealPerson(theName, theBrithDate, theAddress) );
    }

private:
    string theName;
    Date theBirthday;
    Address theAddress;
};

void personInterfaceTest() {
    string name;
    Date dateOfBirth;
    Address address;
    shared_ptr<Person> pp(PersonInterface::create(name, dateOfBirth, address));
    shared_ptr<Person> p(RealPerson::create(name, dateOfBirth, address) );
}

int main(int agrc, char const *agrv[]) {
    personInterfaceTest();
    return 0;
}

