/*
 * Created by weyiua on 2021/9/10.
 * 堆 完全二叉树 -> 用数组存储
 * 又叫优先队列 priority_queue
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
         * 上浮 上滤
         * 新元素默认插入到长度后面的位置
         * 最大堆
         * 然后上浮 使之平衡--> 就是父节点大于等于子节点
         * 赋值
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
        // 父节点 大于子节点 交换位置 取最后一个位置 赋值
        for(i = ++_size; _data[getDad(i)] < value; i /= 2) {
            _data[i - 1] = _data[getDad(i)];
        }
        _data[i - 1] = value;
        return true;
    }

    bool popHeap() {
        /*
         * 下滤
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
            //!= _size 代表还有右儿子 即代表有两个儿子 去最大的
            if(child != _size && _data[child] > _data[child-1]) {
                ++child;
            }
            //父节点 替换 值较大的儿子
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
