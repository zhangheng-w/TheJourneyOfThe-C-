/*
 * Created by weyiua on 2021/6/3.
 * ����ָ��
 * �Զ��ͷ���ָ��Ķ���
 * copy���캯�� ��ָ��Ϊ���� ���켴Ϊcopy���캯��
 * �� =��ֵ����
 */

#include <memory>
#include <string>
#include <iostream>
using namespace std;


/*
 * auto_ptr 11�Ѿ�����
 *
 */
template <typename T>
class AutoPtr {
public:
    //Ĭ�Ϲ��캯�� ȱʡ����
    AutoPtr(T* value = nullptr) : _point(value) {
        cout << "AutoPtr Constructors" << endl;
    }
    //��������
    AutoPtr(AutoPtr<T> &ap) : _point(ap._point) {}

    //=���������
    AutoPtr<T> &operator=(const AutoPtr<T> &ptr) {
        if(this != ptr) {
            if(_point) { delete _point; }
            _point = ptr._point;
        }
        return *this;
    }

    ~AutoPtr() {
        if(_point) {
            delete _point;
            _point = nullptr;
        }
        cout << "AutoPtr Destrucroes" << endl;
    }

    T& operator*() { return *_point; }

    T* operator->() { return _point; }

    T* Get() { return _point; }

    void Reset(T *ptr) {
        if(ptr) {
            delete _point;
        }
        _point = ptr;
    }


protected:
    T* _point;
};

void shared_ptr_things() {
    /*
     * ����ָ�� ��תָ�� ͨ�����캯������������ ��������ٶ���
     *
     */
    //���캯��
    shared_ptr<string> p1;
    shared_ptr<int> p2(new int(1));
    auto p3 = make_shared<int>(1);
    shared_ptr<int> p4(p2);
    shared_ptr<int> p5 = p4;

    if(p1 && p1->empty()) {
        *p1 = "hi";
    }
    cout << *p1;
}

struct A {
    string _str;
    int _a;
    int _b;

    A(const string &str = "hi", const int a = 0, const int b = 0) : _str(str) , _a(a), _b(b) {
        cout << "A constructors" << endl;
    }

    ~A() {
        cout << "A destructors\n";
    }


    friend ostream& operator<<(ostream &out, const A &a) {
        if(!&a)
            return out << "NULL\n";
        out << "_str" << ":" << a._str << endl
            << "_a" << ":" << a._a << endl
            << "_b" << ":" << a._b << endl;
        return out;
    }
};

void autoPtrTest(){
    AutoPtr<int> ap1(new int);
    *ap1 = 100;

    AutoPtr<A> ap2(new A);
    ap2->_str = "hi";
    ap2->_a = 1;
    ap2->_b = 2;
};

/*-----------------------------shared_ptr---------------------------*/

/*
 *shared_ptr
 * ֧�ֶ��ֻ��ָ��ָ��һ������ɾ��һ��ָ�벻Ӱ�����
 * auto_ptr ��Ӱ���11����auto_ptr
 * ���ü��� if count == 0 deleteɾ����������ü���
 * �ڶ��߳����а�ȫ���⣬��Ҫmutex����
 */


template <typename T>
class Shared_Ptr{

public:

    Shared_Ptr(A* sp = nullptr) : _point(sp) , _object_count(nullptr){
        cout << "shared_ptr constructors\n";
        if(sp) {
            _object_count = new int(1);
        }
    }

    /*
     * �����ü��� == 0 deleteָ����ڴ�
     * �� --���ü���
     */
    ~Shared_Ptr() {

        if(_point && 0 == --(*_object_count)) {
            cout << "shared_ptr Destructors\n";
            delete _point;
            delete _object_count;
            _point = nullptr;
            _object_count = nullptr;
        }
        /*
        if(_point != nullptr) {
            cout << "shared_ptr Destructors\n";
            delete _point;
            _point = nullptr;
        }
        */

    }


    /*
     * �������캯��
     * ++���ü���
     */
    Shared_Ptr(const Shared_Ptr<T>& sp) : _point(sp._point) , _object_count(sp._object_count) {
        if(_point) {
            ++(*_object_count);
        }
        cout << "shared_ptr copy Destructors\n";
    }

    /*
     * ��ֵ���������
     *
     */

    Shared_Ptr<T> &operator=(const Shared_Ptr<T> &sp) {
        //��ַ�Ƚ�
        cout << "= assignment \n";
        if(this != &sp) {
            if(_point && 0 == --(*_object_count)) {
                delete _point;
                delete _object_count;
                _point = nullptr;
                _object_count = nullptr;
            }
            _point = sp._point;
            _object_count = sp._object_count;
            if(_point) ++(*_object_count);
        }
        return *this;
    }

    int useCount() {
        return *_object_count;
    }

    T &operator*() {
        return *_point;
    }

    T &operator->(){
        return *_point;
    }

    friend ostream &operator<<(ostream &out, const Shared_Ptr<T> &sp) {
        out << "_point the value is \n" << *sp._point
            << "_object_count the value is " << *sp._object_count << endl;
        return cout;
    }


protected:
    T *_point;
    int *_object_count;
};

void shared_ptrTest() {
    Shared_Ptr<A> sp1(new A ("hello", 12, 12));
    Shared_Ptr<A> sp2 = sp1; //����copy constructors ����
    Shared_Ptr<A> sp3(sp2);
    Shared_Ptr<A> sp4;
    sp4 = sp1;
    //cout << sp1 << sp2  << sp3;
    //cout << "sp3\n" << sp3;
    cout << "sp1 destructor\n";
    sp1.~Shared_Ptr();
    cout <<"sp1\n" << sp1;
    cout << "sp2 destructor\n";
    sp2.~Shared_Ptr();
    cout << "----\n";
    //sp3.~Shared_Ptr();
    //cout <<"sp3\n" << sp3;
}

/*-----------------------------unique_ptr---------------------------*/
/*
 * unique_ptr��ռ����
 *
 */

template <typename T>
class Unique_Ptr {
public:
    Unique_Ptr(T *up = nullptr) : _point(up) {}
    ~Unique_Ptr() {
        if(_point) {
            delete _point;
            _point = nullptr;
        }
    }

    T& operator*() {
        return *_point;
    }

    T& operator->() {
        return *_point;
    }

    //�ͷ���ָ����
    void reset() {
        if(_point) {
            delete _point;
            _point = nullptr;
        }
    }

    T* reset(T *p = nullptr) {
        if(_point) {
            p = _point;
            delete _point;
            _point = nullptr;
        }
        return p;
    }

private:
    Unique_Ptr(const Unique_Ptr<T> &up) = default;
    Unique_Ptr<T> &operator=(const Unique_Ptr<T> &up) = default;

protected:
    T* _point;

};

void unique_PtrTest() {
    Unique_Ptr<A> up(new A("hello", 123, 123));
    //һ������ָ���ռһ������ copy���캯�� =��ֵ���� private
    //Unique_Ptr<A> up2 = up;
    //Unique_Ptr<A> up3(up);
    cout << *up;
}


template <typename T>
class Weaka_Ptr{
public:
    Weaka_Ptr(Shared_Ptr<T> *sp = nullptr) : _point(sp) {}

    Weaka_Ptr(const Weaka_Ptr<T> &wp) {
        if(this != &wp) {
            _point = wp._point;
        }
    }

    int use_count() {
        return _point->useCount();
    }

    bool expired() {
        return use_count() == 0;
    }

    Shared_Ptr<T>* lock() {
        if(!expired()) return _point;
        Shared_Ptr<T> p = Shared_Ptr<T>();
        return &p;
    }

private:
    //Shared_Ptr<T> &operator*() = default;
    //Shared_Ptr<T> &operator->() = default;
protected:
    Shared_Ptr<T>* _point;
};

void weaka_PtrTest() {
    Shared_Ptr<A> sp(new A("zh", 18, 19));
    Shared_Ptr<A> s1(sp);
    Shared_Ptr<A> s2(sp);
    Shared_Ptr<A> s3(sp);
    Weaka_Ptr<A> wp1(&sp);
    Weaka_Ptr<A> wp2(&sp);
    cout << "wp: " << wp1.use_count() << endl;
    if(Shared_Ptr<A>* p = wp1.lock()) {
        p->useCount();
        cout << "wp to p\n" << *p << endl;
    }
    if(Shared_Ptr<A>* p = wp2.lock()) {
        p->useCount();
        cout << "wp to p\n" << *p << endl;
    }
}


int main(int agrc, const char* agrv[]) {
    /*
    A a1;
    cout << a1;
    A a2("hello", 12, 12);
    cout << a2;
    */
    //shared_ptr_things();
    autoPtrTest();
    int* p = new int(1);
    cout << p << " : " << *p << endl;
    //ָ��ĵ�ַ ɾ���˶����ַ pָ��Ŀռ� ��pû�б�ɾ��
    delete p;
    p = nullptr;
    //cout << p << " : " << *p << endl;
    cout << "--------shared_ptr---------\n";
    shared_ptrTest();
    cout << "--------unique_ptr---------\n";
    unique_PtrTest();
    cout << "--------weak_ptr---------\n";
    weaka_PtrTest();
    return 0;
}
