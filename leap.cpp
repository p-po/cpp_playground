#include <iostream>
#include <ctime>

namespace {
    bool isLeap(int year)
    {
        if (year % 4) return false;
        else if (year % 100) return true;
        else if (year % 400) return false;
        else return true;
    }
}


int main(void)
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);

    int this_year = now->tm_year + 1900;
    int leap_count = 20;

    std::cout << "Next " << leap_count << "leap years:" << std::endl;

    for (int i = this_year; leap_count ; ++i) {
        if (isLeap(i)) {
            std::cout << i << " " << std::endl;
            --leap_count;
        }
    }
}
