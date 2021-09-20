/*
 * Created by weyiua on 2021/9/2.
 * Vector
 */

#ifndef _VECTOR_H
#define _VECTOR_H

#include <iostream>

class Vector {
public:
    Vector() : _postion(nullptr), _lenSize(0), _capacity(10) {}
    Vector(int* p, int len, int capacity) {
        this->_lenSize = len;
        this->_capacity = capacity;
        int* pos = new int[capacity];
        int* t = pos;
        while(len) {
            *t = *p;
            --len;
            ++t;
            ++p;
        }
        this->_postion = pos;
    }

    Vector(const Vector& vector) {
        delete[] _postion;
        this->_postion = vector._postion;
        this->_lenSize = vector._lenSize;
        this->_capacity = _capacity;
    }

    Vector& operator=(const Vector& vector) {
        delete[] _postion;
        this->_postion = vector._postion;
        this->_lenSize = vector._lenSize;
        this->_capacity = _capacity;
    }

    ~Vector() {
        delete[] _postion;
        _postion = nullptr;
    }

    int* getVector() const { return _postion; }
    void setVertor(int* postion) { _postion = postion; }

    int getCapacity() const { return _capacity; }
    void setCapacity(int len) { _capacity = len; }

    int sizeVector() const { return _lenSize; }

    void printVector() {
        int* p = _postion;
        int len = _lenSize;
        while(len) {
            std::cout << *p << " ";
            ++p;
            --len;
        }
        std::cout << std::endl;
    }

    bool insertVector(int index, int value) {
        if(index > sizeVector() + 1 || _lenSize + 1 > _capacity || index < 1) return false;
        --index;
        for(int i = _lenSize; i > index; --i) {
            _postion[i] = _postion[i-1];
        }
        _postion[index] = value;
        ++_lenSize;
        return true;
    }

    bool deleteVector(int index) {
        if(_lenSize < 1) return false;
        for(int i = index; i < _lenSize; ++i) {
            _postion[i] = _postion[i+1];
        }
        --_lenSize;
        return true;
    }

private:
    int* _postion;
    int _lenSize;
    int _capacity;
};

//¿ìËÙÅÅÐò
void quickSort(int* p, int left, int right) {
    if(left < right) {
        int i = left, j = right;
        int temp = p[left];
        while(i < j) {
            while(i < j && p[j] >= temp) --j;
            if(i < j) p[i++] = p[j];
            while(i < j && p[i] < temp) ++i;
            if(i < j) p[j--] = p[i];
        }
        p[i] = temp;
        quickSort(p, left, i-1);
        quickSort(p, i+1, right);
    }
}

Vector& sort(Vector& vector) {
    quickSort(vector.getVector(), 0, vector.sizeVector()-1);
    return vector;
}

#endif //_VECTOR_H
