/*
 * Created by weyiua on 2021/9/3.
 * Queue
 */

#ifndef _QUEUE_H
#define _QUEUE_H


class Queue {
public:

    Queue() {}

    bool emptyQueue() const { return _begin == _end; }
    



private:
    int* _postion;
    int _lenSize;
    int _capacity;
    int _begin;
    int _end;
};

#endif //_QUEUE_H
