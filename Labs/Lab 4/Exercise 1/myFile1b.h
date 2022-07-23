#include <iostream>

using namespace std;

class Student
{
    int    numID;
    int    nbCourses;
    int    maxCourses;
    int    *List_grades;
    Course **List_courses;

public:
    Student(int numID, int maxCourses): numID(numID), maxCourses(maxCourses)
    {
        nbCourses = 0;
        List_grades = new int[maxCourses];
        List_courses = new Course *[maxCourses];
    }

    ~Student()
    {
        delete[] List_grades;
        delete[] List_courses;
    }

    double average()
    {
        if (!(nbCourses && List_grades))
            return 0;
        else
        {
            double sum = 0;
            for (int i = 0; i < nbCourses; ++i)
                sum += List_grades[i];
            return sum / nbCourses;
        }
    }

    int totalHours()
    {
        if (!(nbCourses && List_courses))
            return 0;
        else
        {
            int sum = 0;
            for (int i = 0; i < nbCourses; ++i)
                sum += List_courses[i]->getHours();
            return sum;
        }
    }

    bool addCourse(Course *ptrCourse, int grade)
    {
        if (nbCourses >= maxCourses)
            return false;
        else
        {
            List_courses[nbCourses] = ptrCourse;
            List_grades[nbCourses++] = grade;
            return true;
        }
    }
};
