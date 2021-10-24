#ifndef LOCKER_H
#define LOCKER_H

#include <pthread.h>
#include <semaphore.h>
#include <exception>
using std::exception;

/*
其中封装了所有的线程同步机制的函数
sem 信号
locker 互斥锁
cond 条件变量
*/

//对信号的封装
class sem {
public:
    //构造信号量
    sem() {
        if(sem_init(&_sem, 0, 0) != 0) {
            throw exception();
        }
    }

    sem(int value) {
        if(sem_init(&_sem, 0, value) != 0) {
            throw exception();
        }
    }

    //销毁信号量
    ~sem() {
        sem_destroy(&_sem);
    }

    //信号量减一 为0时阻塞
    bool wait() {
        return sem_wait(&_sem);
    }

    //信号量加一 
    bool post() {
        return sem_post(&_sem);
    }


private:
    sem_t _sem;
};

class locker {
public:
    //构造函数
    locker() {
        if(pthread_mutex_init(&_mutex, nullptr) != 0) {
            throw exception();
        }
    }

    //析构函数
    ~locker() {
        pthread_mutex_destroy(&_mutex);
    }

    //加锁
    bool lock() {
        return pthread_mutex_lock(&_mutex) == 0; 
    }

    //解锁
    bool unlock() {
        return pthread_mutex_unlock(&_mutex) == 0;
    }

private:
    pthread_mutex_t _mutex;
};

class cond {
public:
    //构造函数
    cond() {
        if(pthread_mutex_init(&_mutex, nullptr) != 0) {
            throw exception();
        }

        if(pthread_cond_init(&_cond, nullptr) != 0) {
            pthread_mutex_destroy(&_mutex);
            throw exception();
        }
    }

    //析构函数
    ~cond() {
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_cond);
    }

    //等待条件变量
    bool wait() {
        int ans = 0;
        pthread_mutex_lock(&_mutex);
        ans =  pthread_cond_wait(&_cond, &_mutex);
        pthread_mutex_unlock(&_mutex);
        return ans == 0;
    }

    //唤醒等待条件变量的线程
    bool singal() {
        return pthread_cond_signal(&_cond) == 0;
    }

private:
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;
};

#endif