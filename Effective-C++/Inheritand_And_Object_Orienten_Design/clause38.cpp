/*
 * Created by weyiua on 2021/6/20.
 * 38. ͨ��������ģ��has-a��"����ĳ��ʵ�ֳ�"
 *
 * * ���ϵ������public�̳���ȫ��ͬ
 * * ��Ӧ���򣬸�����ζhas-a(��һ��)������ʵ�򣬸�����ζis-implemented-in-terms-of(����ĳ��ʵ�ֳ�)
 */

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Address {

};

class PhoneNumber {

};

class Person {
public:

private:
    //has-a(��һ��) ʵ���������Ǳ���is-implemented-in-terms-of�Ĺ�ϵ(����ĳ��ʵ�ֳ�)
    string name;
    Address address;
    PhoneNumber voiceNumber;
    PhoneNumber faxNumber;
};

//set �� listʵ��
//is-a����
//has-a
template <typename T>
class SetIsA : public list<T> {  //��������

};

template <typename T>
class SetHasA {
public:
    bool member(const T& item) const ;
    void insert(const T& item) ;
    void remove(const T& item) ;
    size_t size() const ;
private:
    list<T> rep;
};

//�Ƿ������Ԫ��
template<typename T>
bool SetHasA<T>::member(const T &item) const {
    return find(rep.begin(), rep.end(), item) != rep.end();
}

//����Ԫ��
template<typename T>
void SetHasA<T>::insert(const T &item) {
    if(!member(item)) rep.push_back(item);
}

//�Ƴ�Ԫ��
template<typename T>
void SetHasA<T>::remove(const T &item) {
    typename list<T>::iterator it = find(rep.begin(), rep.end(), item);
    if(it != rep.end()) rep.erase(it);
}

//Ԫ�ظ���
template<typename T>
size_t SetHasA<T>::size() const {
    return rep.size();
}


int main(int agrc, const char *agrv[]) {
    return 0;
}
