#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>
#include <functional>
#include <atomic>

class timer{
public:
    timer(const std::chrono::milliseconds& period,
          std::function <void()> callback);
    void start();
    void stop();
    ~timer();
private:
    void timer_main();
    std::atomic<bool> m_running{false};
    std::thread m_timer_thread;
    std::chrono::milliseconds m_period;
    std::function <void()> m_callback;
};

timer::timer(const std::chrono::milliseconds &period,
                    std::function<void ()> callback) :
    m_period(period), m_callback(callback) { }

void timer::start() {
    m_running = true;
    m_timer_thread = std::thread(&timer::timer_main, this);
    m_timer_thread.detach();
}

void timer::stop() {
    m_running = false;
    if( m_timer_thread.joinable() )
        m_timer_thread.join();
}

timer::~timer() {
    m_running = false;
    if( m_timer_thread.joinable() )
        m_timer_thread.join();
}

void timer::timer_main()
{
    while( m_running ) {
        std::this_thread::sleep_for(m_period);
        std::thread(m_callback).detach();
    }
}

#endif // TIMER_H
