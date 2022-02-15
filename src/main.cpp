#include <chrono>
#include <ctime>
#include <thread>

#include "common.hpp"
#include "renderer.hpp"

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
    Renderer renderer;
    Frame frame;

    while(true)
    {
        frame.clear();
        
        get_time(timeBuff);
        timeStr = timeBuff;

        frame.render(timeStr);

        // renderer.render(timeStr);

        // renderer.swap();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}