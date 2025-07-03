#include "threadPool.h"
#include <iostream>

using namespace std;


int main(){
    threadPool p(5);

    for(int i=0;i<20;i++){
    p.addTask([i]{
            //使用lambda表达式当做线程体函数

            cout<<"任务："<<i<<"正在执行,其tid = "<<this_thread::get_id()<<endl;

            //模拟任务执行时间，表示该任务执行100毫秒
            this_thread::sleep_for(std::chrono::milliseconds(500)); });
    }

    // 等待所有任务完成
    this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}