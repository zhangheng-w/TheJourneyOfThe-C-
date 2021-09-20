/*
 * Created by weyiua on 2021/8/31.
 * List
 */

#ifndef _List_H
#define _List_H

#include <iostream>

struct Node {
    int val;
    Node* _next;

    Node(int v) : val(v), _next(nullptr) {}
};

typedef Node* Position;

class List {

private:
    Position _postion;
    int _listLen;

public:
    List() {
        //头结点
        makeHeadNode();
        _listLen = 0;
    }

    List(int* p, int len) {
        makeHeadNode();
        makeList(p, len);
        _listLen = len;
    }

    List(const List& list) : _postion(list._postion), _listLen(list._listLen) {}

    List(const Position& position, int len) : _postion(position), _listLen(len) {}

    //创建头结点
    void makeHeadNode() { _postion = new Node(0x3f3f3f3f); }

    void setPostion(Position& position) { _postion = position; }

    void setListSize(const int len) { _listLen = len; }

    int getListSize() const { return _listLen; }

    Position getList() const { return _postion; }

    void printList() {
        Position p = _postion->_next;
        while(p) {
            std::cout << p->val << " ";
            p = p->_next;
        }
        std::cout << std::endl;
    }

    int sizeList() const { return _listLen; }

    bool emtpyList() {
        return _postion->_next == nullptr;
    }

    Position makeList(int* p, int len) {
        Position temp = _postion;
        for(int i = 0; i < len; ++i) {
            temp->_next = new Node(*p);
            temp = temp->_next;
            ++p;
        }
        return _postion;
    }

    bool destroyList() {
        Position temp = _postion->_next;
        while(temp != nullptr) {
            Position t = temp;
            temp = temp->_next;
            delete t;
        }
        _listLen = 0;
        return _postion->_next == nullptr;
    }


    Position findList(int val) {
        Position temp = _postion;
        while(temp && temp->val != val) {
            temp = temp->_next;
        }
        return temp;
    }

    int beginListValue() {
        if(emtpyList()) return -1;
        return _postion->_next->val;
    }

    int endListValue() const {
        Position temp = _postion;
        int val = 0;
        while(temp) {
            val = temp->val;
            temp = temp->_next;
        }
        return val;
    }

    bool insertList(int value, int index) {
        Position temp = _postion;
        --index;
        while(index && temp) {
            temp = temp->_next;
            --index;
        }
        if(index) return false;
        Position t = new Node(value);
        t->_next = temp->_next;
        temp->_next = t;
        ++_listLen;
        return true;
    }

    bool deleteList(int index) {
        Position temp = _postion;
        --index;
        while(index && temp) {
            temp = temp->_next;
            --index;
        }
        if(temp == nullptr || (temp && temp->_next == nullptr) ) return false;
        Position t = temp->_next;
        temp->_next = t->_next;
        delete t;
        --_listLen;
        return true;
    }
};


//翻转链表
List reverseList(List list) {
    Position p = new Node(0x3f3f3f3f);
    Position temp = list.getList()->_next;
    delete list.getList();
    while(temp) {
        Position t = temp;
        temp = temp->_next;
        t->_next = p->_next;
        p->_next = t;
    }
    list.setPostion(p);
    return list;
}


//合并有序链表
List mergeList(List& left, List& right) {
    Position leftPos = left.getList()->_next;
    Position rightPos = right.getList()->_next;
    Position reList = new Node(0x3f3f3f3f);
    Position t = reList;
    while(leftPos && rightPos) {
        if(leftPos->val < rightPos->val) {
            t->_next = leftPos;
            leftPos = leftPos->_next;
        } else {
            t->_next = rightPos;
            rightPos = rightPos->_next;
        }
        t = t->_next;
    }
    if(leftPos || rightPos) t->_next = leftPos ? leftPos : rightPos;
    List list(reList, left.getListSize() + right.getListSize());
    return list;
}

//排序链表
List sortList(List& list) {

}

#endif //_List_H
