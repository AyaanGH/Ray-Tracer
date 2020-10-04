#ifndef RAY_TRACER_THREAD_POOL_H
#define RAY_TRACER_THREAD_POOL_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>


class Thread_pool {

public:
    std::mutex token;
    std::condition_variable condition;
    std::queue<std::function<void()>> queue;
    std::vector<std::thread> pool;

    bool terminate_flag;


    void add_job(std::function<void()> job);

    [[noreturn]] void wait_for_job();

    void terminate_pool();

    Thread_pool();

    virtual ~Thread_pool();


};


#endif
