#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
using namespace std;

class threadPool{
private:
    vector<thread> workers;         // 存储工作的线程容器
    queue<function<void()>> tasks;
    mutex task_mutex;               // 互斥锁
    condition_variable task_cv;     // 用于通知线程有新任务的条件变量 
    bool stop;                      // 线程池的标志，判断线程池是否停止 
    
    // 启动线程池
    void startThreadPool(size_t numThreads);


public:
    threadPool(int threadPoolSize);      // 构造函数声明
    ~threadPool();                       // 析构函数声明

    void addTask(function<void()> task); // 添加任务到线程池

};







#endif