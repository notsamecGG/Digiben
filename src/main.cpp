#include <chrono>
#include <ctime>
#include <thread>

#include "frame.hpp"

void get_time(char* timeBuff)
{    
    std::time_t rawtime;
    std::tm* tm;

    time(&rawtime);
    tm = localtime(&rawtime);

    std::strftime(timeBuff, 24, "%T", tm);
}

int main()
{
    char timeBuff[24];
    std::string timeStr;
    Frame frame;

    while(true)
    {
        get_time(timeBuff);
        timeStr = timeBuff;

        frame.clear();
        frame.render(timeStr);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}