#ifndef LIST_TIMER_H
#define LIST_TIMER_H

#include <iostream>
#include <time.h>
#include <netinet/in.h>
#include "../lock/locker.h"

const int BUFFER_SIZE = 64;

//前置声明
class util_timer;
//客户机连接信息结构
struct client_data {
    sockaddr_in address;
    int sockfd;
    char buf[BUFFER_SIZE];
    util_timer *timer;
};

class util_timer {
public:
    util_timer() : prev(nullptr), next(nullptr) {} 

private:
    time_t _time;                   //时间变量
    void (*cb_func)(client_data *); //指针函数
    client_data *user_data;         //结点数据
    util_timer *prev;               //前驱指针
    util_timer *next;               //后继指针
};

class sort_timer_list {
public: 
    //构造函数
    sort_timer_list() : head(nullptr), tail(nullptr) {}
    //析构函数 销毁排序时间链表中的所有结点的内存
    ~sort_timer_list() {
        util_timer *tmp = head;
        while(tmp) {
            head = tmp->head;
            delete tmp;
            tmp = head;
        }
    }


    void add_timer(util_timer *timer) {
        if(!timer) return;

        //链表中没有元素 直接加入
        if(!head) {
            head = tail = timer;
            return ;
        }

        //添加的这个数据的定时时间小于头结点直接添加到头结点
        if(timer->_time < head->_time) {
            timer->next = head;
            head->prev = time;
            head = timer;
            return ;
        }

        //都不是， 使用添加辅助函数，寻找插入位置
        add_timer(timer, head);
    }

    //? 定时任务发生改变 -调整在链表中间的位置-> 只考虑时间延长的情况
    void adjust_timer(util_timer *timer) {
        //空指针直接返回
        if(!timer) return ;

        util_timer *tmp = timer->next;
        //需要修改的结点处于尾结点 | 该时间定时器时间小于下一个定时器，则还是有序的无需改变位置
        if(!tmp || (timer->_time < tmp->_time)) {
            return ;
        }

        if(timer == head) {
            head = head->next;
            head->prev = nullptr;
            timer->next = nullptr;
            add_timer(timer, head);
        } else {
            //从链表删除-再重新新插入
            timer->prev->next = timer->next;
            timer->next->prev = timer->prev;
            add_timer(timer, timer->next);
        }

    }

    //删除结点, 删除的结点就在链表中- 分类讨论删除情况
    void del_timer(util_timer *timer) {
        //为空指针直接返回与
        if(!timer) return ;

        //链表只有一个结点， 且是删除的结点
        if(timer == head && timer == tail) {
            delete timer;
            head = nullptr;
            tail = nullptr;
            return ;
        }

        //删除结点是头结点
        if(timer == head) {
            head = head->next;
            head->prev = nullptr;
            delete timer;
            return ;
        }

        //删除结点是尾结点
        if(timer == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            delete timer;
            return ;
        }

        //删除结点处于链表中间
        timer->prev->next = timer->next;
        timer->next->prev = timer->prev;
        
        timer->prev = nullptr;
        timer->next = nullptr;
        delet timer;
        reutrn ;
    }

    //?心搏函数 -> 每到时间启动一次 检测时间到期的任务
    void tick() {


        if(!head) return ;
        std::cout << "timer tick\n";
        //获取系统当前时间
        time_t cur = time(nullptr);
        
        util_timer *tmp = head;
        
        //把所有的定时任务执行
        while(tmp) {
            if(cur < tmp->_time) {
                break;
            }

            //指针函数执行 定时任务， 删除链表结点
            tmp->cb_func(tmp->user_data);
            head = head->next;
            if(head) {
                head->prev = nullptr;
            }
            delete tmp;
            tmp = head;
        }
    }

private:
    //添加结点辅助函数
    void add_timer(util_timer *timer, util_timer *list_head) {
        util_timer *prev = list_head;
        util_timer *tmp = prev->next;

        //不断查找自己在链表中的位置 插入
        while (tmp) {
            if(timer->_time < tmp->_time) {
                prev->next = timer;
                timer->next = tmp;
                tmp->prev = timer;
                timer->prev = prev;
                break;
            }

            prev = tmp;
            tmp = tmp->next;
        }

        //判断是不是最后一个元素
        if(!tmp) {
            prev->next = timer;
            timer->prev = prev;
            timer->next = nullptr;
            tail = timer;
        }
    }


private:
    util_timer *head;               //头结点
    util_timer *tail;               //尾结点
};


#endif