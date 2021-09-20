/*
 * Created by weyiua on 2021/9/2.
 * Stack
 */

#ifndef _STACK_H
#define _STACK_H

#include <iostream>

class Stack {
public:

    Stack() : _postion(nullptr), _lenSize(0), _capacity(1) {}
    Stack(int* p, int len, int capcaity) {
        _capacity = capcaity;
        _lenSize = len;
        int* postion = new int[capcaity];
        int* pos = postion;
        while(len) {
            *pos = *p;
            ++pos;
            ++p;
            --len;
        }
        _postion = postion;
    }

    Stack(const Stack& stack) {
        delete[] _postion;
        _postion = stack._postion;
        _lenSize = stack._lenSize;
        _capacity = stack._capacity;
    }

    int* getPostion() const { return _postion; }
    void setPostion(int* postion) { _postion = postion; }
    int sizeStack() const { return _lenSize; }
    int capacity() const { return _capacity; }

    bool pushStack(int value) {
        ++_lenSize;
        if(_lenSize > _capacity) {
            expandCapacity();
        }
        *(_postion + _lenSize-1) = value;
        return true;
    }

    bool popStack() {
        --_lenSize;
    }

    int topStack() const {
        return *(_postion + _lenSize-1);
    }

    void printStack() {
        int* p = _postion;
        int len = _lenSize;
        while(len) {
            --len;
            std::cout << *p << " ";
            ++p;
        }
        std::cout << std::endl;
    }

    bool emptyStack() const { return _lenSize == 0; }

    void expandCapacity() {
        int capacity = _capacity;
        int* p = new int[capacity];
        int* oldPostion = _postion;
        int* ptemp = p;
        int t =_lenSize;
        while(t) {
            *ptemp = *oldPostion;
            ++ptemp;
            ++oldPostion;
            --t;
        }
        delete[] _postion;
        _postion = p;
        _capacity *= _capacity;
    }

private:
    int* _postion;
    int _lenSize;
    int _capacity;
};

#endif //_STACK_H
