#include <chrono>
#include <iostream>
#include <thread>

#include "src/timer.hpp"

void wait_for_a_few_seconds(int seconds) {
    std::cout << "I will sleep for " << seconds << " second(s)." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int main() {
    Timer timer;
    std::cout << "Elapsed time before start: " << timer.elapsed() << std::endl;
    timer.start();
    wait_for_a_few_seconds(1);
    timer.stop();
    auto elapsed = timer.elapsed();
    std::cout << "Elapsed time: " << elapsed << std::endl;
    timer.pretty_print();

    // pretty_print() examples
    Timer::pretty_print(0);
    Timer::pretty_print(1);
    Timer::pretty_print(59);
    Timer::pretty_print(60);
    Timer::pretty_print(62);
    Timer::pretty_print(125);
    Timer::pretty_print(3600);
    Timer::pretty_print(9623);
}