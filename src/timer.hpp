#include <string>

class Timer {
    time_t start_time;
    time_t end_time;
    bool isRunning;
public:
    Timer();
    void start();
    void stop();
    int elapsed();
    void pretty_print();
    static void pretty_print(int time);
};
