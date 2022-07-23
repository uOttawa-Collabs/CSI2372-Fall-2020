#include <iostream>
#include <process.h>
using namespace std; 
const int SIZE = 20; 	// SIZE string 

struct Evaluation
{
    char student[SIZE];
    int grade;
    Evaluation *next;
};

Evaluation *add(Evaluation *, int &);
Evaluation *remove(Evaluation *, int &);
void display(Evaluation *);
int average(Evaluation *, int const &);

void flushInputBuffer();
