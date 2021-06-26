/*
by author heng  20-11-29
����pass-by-reference-to-const�滻pass-by-value

1��������pass-by-reference-to-const�滻pass-by-value��ǰ��ͨ�Ƚϸ�Ч�������Ա����и�����
2�����Ϲ��򲢲��������������ͣ��Լ�STL�ĵ������ͺ������󡣶����Ƕ��ԣ�pass-by-value�����Ƚ��ʺ�
*/

#include <string>
#include <iostream>
using namespace std;


class Person {
public :
    Person() { cout << "Person Default Constructor\n"; }
    Person(const string& name, string& address) : _name(name), _address(address) { cout << "Person Constructor Pass By Reference To Const\n"; }
    virtual ~Person() { cout << "Person Default Destructor \n";  }
    
private :
    string _name;
    string _address;
}; 

class Student : public Person {
public :
    Student() { cout << "Student Default Constructor\n";  }
    Student(const string& schoolName, const string& schoolAdress) : _schoolName(schoolName), _schoolAdress(schoolAdress) { cout << "Student Constructor Pass By Reference To Const\n"; }
    virtual ~Student() { cout << "Student Default Destructor \n"; }
private :
    string _schoolName;
    string _schoolAdress;
};

bool vaildateStudentPassByValue(Student s) { return false; }
bool vaildateStudentPassByReferenceToConst(const Student& s) { return false; }

void personStudentTest() {
    Student he;
    bool hetoIsOk = vaildateStudentPassByValue(he);
    cout << "\n";
    bool hetoisR = vaildateStudentPassByReferenceToConst(he);            //ͨ����reference to constЧ�ʸ���
}

class Windom {
public :
    Windom() { cout << "Windom Default Constructor\n"; }
    Windom(const string& name) : _name(name) { cout << "Windom Constructor Pass By Reference To Const\n"; }
    virtual ~Windom() {}

    string name() const { return _name; }
    virtual void display() const { cout << "Windom In Display\n"; }

private :
    string _name;
};

class WindomWithScrollBars : public Windom {
public :
    WindomWithScrollBars(const string& name) : Windom::Windom(name) { cout << "WindomWithScrollBars Constructor Pass By Reference To Const\n"; }
    virtual void display() const { cout << "WindomWithScrollBars In Display\n"; }
};

void PrintNameWindomPassByValue(Windom w) {
    cout << w.name() << "\n";
    w.display();
}
void PrintNameWindomPassReferenceToConst(const Windom& w) {
    cout << w.name() << "\n";
    w.display();
}

void WindomTest() {
    Windom w("123value");
    PrintNameWindomPassByValue(w);
    WindomWithScrollBars ws("456value");
    PrintNameWindomPassByValue(ws);                              //���ǵ���base class�ĺ���

    cout << "Reference To Const:\n";
    Windom wreference("123reference");
    PrintNameWindomPassReferenceToConst(wreference);
    WindomWithScrollBars wsreferencec("456reference");
    PrintNameWindomPassReferenceToConst(wsreferencec);           //reference to const ���ñ�����ĺ���

}

int main(int agrc, char const *agrv[]) {
    personStudentTest();
    WindomTest();
    return 0;
}