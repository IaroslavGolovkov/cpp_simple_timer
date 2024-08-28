#include <iostream>
#include <chrono>
#include <thread>

#include "timer.h"

int main()
{
    timer t(std::chrono::milliseconds(1000), [](){
        std::cout << "1s period - thread " <<
                     std::this_thread::get_id() << std::endl;
    });
    t.start();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    t.stop();
    return 0;
}
