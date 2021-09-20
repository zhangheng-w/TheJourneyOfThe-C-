/*
 * Created by weyiua on 2021/9/10.
 * �� ��ȫ������ -> ������洢
 * �ֽ����ȶ��� priority_queue
 */

#ifndef _HEAP_H
#define _HEAP_H

#include <iostream>
using std::cout;


class Heap {

public:
    Heap(int x) {
        _data = new int(x);
        _size = 0;
        _capactiy = x;
    }

    ~Heap() {
        if(_data != nullptr) {
            delete _data;
            _data = nullptr;
        }
    }


    int* getHeapData() const {
        return _data;
    }

    int topHeap()  const {
        return _data[0];
    }

    int HeapSize() const { return _size; }

    bool pushHeap(int value) {
        /*
         * �ϸ� ����
         * ��Ԫ��Ĭ�ϲ��뵽���Ⱥ����λ��
         * ����
         * Ȼ���ϸ� ʹ֮ƽ��--> ���Ǹ��ڵ���ڵ����ӽڵ�
         * ��ֵ
         *
         */
        if(isEmpty()) {
            _data[0] = value;
            ++_size;
            return true;
        }

        if(_size+1 > _capactiy) {
            cout << "capactiy full \n";
            return false;
        }
        int i = 0;
        // ���ڵ� �����ӽڵ� ����λ�� ȡ���һ��λ�� ��ֵ
        for(i = ++_size; _data[getDad(i)] < value; i /= 2) {
            _data[i - 1] = _data[getDad(i)];
        }
        _data[i - 1] = value;
        return true;
    }

    bool popHeap() {
        /*
         * ����
         */
        if(isEmpty()) {
            cout << "Heap Capactiy Null \n";
            return false;
        }
        int i, child;
        int lastChildValue = _data[_size-1];
        --_size;

        for(i = 1; i * 2 <= _size; i = child) {
            child = i * 2;
            //!= _size �������Ҷ��� ���������������� ȥ����
            if(child != _size && _data[child] > _data[child-1]) {
                ++child;
            }
            //���ڵ� �滻 ֵ�ϴ�Ķ���
            if(lastChildValue < _data[child-1] ) _data[i-1] = _data[child-1];
            else break;
        }
        _data[i-1] = lastChildValue;
        return true;
    }

    bool isEmpty() const {
        return _size == 0;
    }

private:

    int _size;
    int _capactiy;
    int* _data;;

    int getClich(int val) {
        return val * 2 - 1;
    }

    int getDad(int value) {
        return value / 2 - 1;
    }



};


#endif //_HEAP_H
