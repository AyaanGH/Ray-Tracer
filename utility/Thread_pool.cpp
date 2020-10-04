#include "Thread_pool.h"

[[noreturn]] void Thread_pool::wait_for_job() {


    while (true) {

        {

            std::unique_lock<std::mutex> lock(token);

            condition.wait(lock, [&queue = queue, &terminate_flag = terminate_flag] {
                return !queue.empty() || terminate_flag;
            });
            std::function<void()> job = queue.front();
            job();
            queue.pop();
        }


    }

}

Thread_pool::Thread_pool() {

    int threads_available = std::thread::hardware_concurrency();

    terminate_flag = false;

    pool.reserve(threads_available);

    for (int i = 0; i < threads_available; ++i) {

        pool.emplace_back(&Thread_pool::wait_for_job, this);


    }


}

void Thread_pool::add_job(std::function<void()> job) {

    {
        std::unique_lock<std::mutex> lock(token);
        queue.push(job);
    }
    condition.notify_one();
}

void Thread_pool::terminate_pool() {
    std::unique_lock<std::mutex> lock(token);
    terminate_flag = true;
    condition.notify_all();


    for (std::thread &every_thread : pool) {
        every_thread.join();
    }

    pool.clear();


}

Thread_pool::~Thread_pool() {
    terminate_pool()

}


