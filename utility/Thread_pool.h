#ifndef RAY_TRACER_THREAD_POOL_H
#define RAY_TRACER_THREAD_POOL_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>


class Thread_pool {

private:
    std::mutex token;
    std::condition_variable condition;
    std::queue<std::function<void()>> queue;
    std::vector<std::thread> pool;
    [[noreturn]] void wait_for_job();

public:


    void add_job(std::function<void()> job);

    void terminate_pool();

    Thread_pool();

    virtual ~Thread_pool();



};
static bool terminate_flag = false;


#endif
