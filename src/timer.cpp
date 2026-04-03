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
    int hours = time / 3600;
    int minutes = time / 60 % 60;
    int seconds = time % 60;

    std::vector<std::string> segments;

    if (hours > 0) {
        segments.push_back(hours == 1 ? "1 hour" : std::to_string(hours) + " hours");
    }
    if (minutes > 0) {
        segments.push_back(minutes == 1 ? "1 minute" : std::to_string(minutes) + " minutes");
    }
    if (seconds > 0) {
        segments.push_back(seconds == 1 ? "1 second" : std::to_string(seconds) + " seconds");
    }

    if (segments.empty()) {
        std::cout << "No time has passed." << std::endl;
        return;
    }

    std::string ending = hours + minutes + seconds == 1 ? "has passed." : "have passed.";

    if (segments.size() == 1) {
        std::cout << segments[0] << " " << ending << std::endl;
        return;
    }

    if (segments.size() == 2) {
        std::cout << segments[0] << " and " << segments[1] << " " << ending << std::endl;
        return;
    }

    if (segments.size() == 3) {
        std::cout << segments[0] << ", " << segments[1] << ", and " << segments[2] << " " << ending << std::endl;
    }
}
