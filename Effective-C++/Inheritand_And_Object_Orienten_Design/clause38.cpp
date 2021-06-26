/*
 * Created by weyiua on 2021/6/20.
 * 38. 通过复合塑模出has-a或"根据某物实现出"
 *
 * * 复合的意义和public继承完全不同
 * * 在应用域，复合意味has-a(有一个)。在现实域，复合意味is-implemented-in-terms-of(根据某物实现出)
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
    //has-a(有一个) 实现域类则是表现is-implemented-in-terms-of的关系(根据某物实现出)
    string name;
    Address address;
    PhoneNumber voiceNumber;
    PhoneNumber faxNumber;
};

//set 用 list实现
//is-a错误
//has-a
template <typename T>
class SetIsA : public list<T> {  //错误做法

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

//是否有这个元素
template<typename T>
bool SetHasA<T>::member(const T &item) const {
    return find(rep.begin(), rep.end(), item) != rep.end();
}

//插入元素
template<typename T>
void SetHasA<T>::insert(const T &item) {
    if(!member(item)) rep.push_back(item);
}

//移除元素
template<typename T>
void SetHasA<T>::remove(const T &item) {
    typename list<T>::iterator it = find(rep.begin(), rep.end(), item);
    if(it != rep.end()) rep.erase(it);
}

//元素个数
template<typename T>
size_t SetHasA<T>::size() const {
    return rep.size();
}


int main(int agrc, const char *agrv[]) {
    return 0;
}
