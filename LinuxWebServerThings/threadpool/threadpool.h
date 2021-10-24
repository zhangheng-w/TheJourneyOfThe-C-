#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <list>
#include <pthread.h>
#include <exception>
#include "../lock/locker.h"
using std::list; using std::exception;

/*
线程池 --> 线程池 + 工作线程 每一时刻只有一个线程访问工作线程(加锁)
添加任务 - 提取任务
*/

template <typename T>
class threadpool {
public:
    //构造函数
    threadpool(int thread_nums = 8, int max_queue = 10000);
    //析构函数
    ~threadpool();
    //添加任务到工作队列
    bool append(T *request);

private:
    //从工作队列取出并执行
    static void* worker(void *agr);
    void run();

private:
    int _max_thread;             //最大线程数
    int _max_queue;              //工作队列最大数量
    pthread_t *_threads;         //线程池
    List<T*> _workqueue;         //工作队列
    int worklen;                 //工作队列中任务的数量
    locker _queuelock;           //互斥锁
    sem _queuestat;              //信号量
    bool _stop;                  //任务运行标志？
};
 
//构造函数 
template <typename T>
threadpool<T>::threadpool(int thread_nums, int max_queue) : _max_thread(thread_nums), _max_queue(max_queue), _threads(nullptr), worklen(0), _stop(false) {
    //线程池请求队列<=0 抛异常
    if(thread_nums <= 0 || max_queue <= 0) {
        throw exception();
    }

    //构建线程池
    _threads = new pthread_t[thread_nums];

    if(_threads) {
        throw exception();
    }

    for(int i = 0; i < thread_nums; ++i) {
        //为线程池中的每个位置存放一个线程
        //创建线程 ,失败就释放资源
        if(pthread_create(_threads+i, nullptr, worker, this) != 0) {
            delete[] _threads;
            throw exception();
        }

        //做线程分离
        if(pthread_detach(_threads[i])) {
            delete[] _threads;
            throw exception();
        }
    }
}

//析构函数
template <typename T>
threadpool<T>::~threadpool() {
    delete[] _threads;
    _stop = true;
}

//添加任务
template <typename T>
bool threadpool<T>::append(T *request) {
    _queuelock.lock();

    //工作队列已满 无法添加
    if(worklen >= _max_queue) {
        _queuelock.unlock();
        return false;
    }

    _workqueue.push_back(request);
    ++worklen;
    _queuelock.unlock();
    _queuestat.post();

    return true;
}

//工作线程
template <typename T>
void *threadpool<T>::worker(void *agr) {
    threadpool *pool = (threadpool *)agr;
    pool->run();
    return  pool;
}

//提取任务线程
template <typename T>
void threadpool<T>::run() {
    while(!_stop) {
        //信号量减一
        _queuestat.wait();
        //加锁
        _queuelock.lock();
        
        //列队为空
        if(_workqueue.empty()) {
            _queuelock.unlock();
            continue;
        }

        //提取一个任务
        T *request = _workqueue.pop_front();
        _workqueue.pop_front();
        _queuelock.unlock();

        //？
        if(!request) {
            continue;
        }

        //?
        request->pocress();
    }
}

#endif