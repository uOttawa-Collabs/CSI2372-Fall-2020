#include <iostream>

using namespace std;

class Course
{
    int num;
    int hours;

public:
    Course(int num, int hours) : num(num), hours(hours)
    {}

    int getNum()
    {
        return num;
    }

    int getHours()
    {
        return hours;
    }
};
