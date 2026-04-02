#include "timer.hpp"
#include <chrono>
#include <iostream>
#include <string>

Timer::Timer() {
    isRunning = false;
    start_time = static_cast<time_t>(0);
    end_time = static_cast<time_t>(0);
}

void Timer::start() {
    if (isRunning) {
        throw std::logic_error("Timer must be stopped to start again");
    }
    auto time = std::chrono::system_clock::now();
    start_time = std::chrono::system_clock::to_time_t(time);
    //end_time = start_time;
    isRunning = true;
}

void Timer::stop() {
    if (!isRunning) {
        throw std::logic_error("Timer must be started to stop again");
    }
    auto time = std::chrono::system_clock::now();
    end_time = std::chrono::system_clock::to_time_t(time);
    isRunning = false;
}

int Timer::elapsed() {
    if (isRunning) {
        throw std::logic_error("Timer must be stopped to get the elapsed time");
    }
    return static_cast<int>(end_time - start_time);
}

void Timer::pretty_print() {
    pretty_print(elapsed());
}

void Timer::pretty_print(int time) {
    int hours = static_cast<int>(time / 3600);
    int minutes = static_cast<int>((time / 60) % 60);
    int seconds = static_cast<int>(time % 60);

    //if two of them are 0 then no 'and' and no commas
    //if one of them us 0 then 'and'
    //if none of them are 0 then commas

    // std::string timeHoursText = hours == 1 ? "hour" : "hours";
    // std::string timeMinutesText = minutes == 1 ? "minute" : "minutes";
    // std::string timeSecondsText = seconds == 1 ? "second" : "seconds";
    //
    // std::string hasHaveHoursText = hours == 1 ? "has" : "have";

    if (time == 0) {
        std::cout << "No time has passed" << std::endl;
    } else if (time == 1 || time == 60 || time == 3600) {
        if (time == 1) {
            std::cout << "1 minute has passed" << std::endl;
        }
        if (time == 60) {
            std::cout << "1 hour has passed" << std::endl;
        }
        if (time == 3600) {
            std::cout << "1 minute has passed" << std::endl;
        }
        std::cout << "has passed." << std::endl;
    } else {
        std::cout << "have passed." << std::endl;
    }

    //std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
}

//
// std::string pretty_print() {
//    return "Implement your code here!";
// }
