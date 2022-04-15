/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/

#include <iostream>
#include <iomanip>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//#include <unistd.h>

struct Clock{
    int hr, min, sec;
};

using pClock = Clock*;

void tick(pClock ptr);
void show(pClock ptr, char end = '\n');
void runs(pClock ptr, char end = '\n');

int main(void){
    pClock clock_p = new Clock {14, 58, 56};

    runs(clock_p, '\r');

    delete clock_p;
    return 0;
}

void tick(pClock ptr){
    ptr->sec++;
    if(ptr->sec == 60) {
        ptr->min++;
        ptr->sec = 0;
    }
    if(ptr->min == 60) {
        ptr->hr++;
        ptr->min = 0;
    }
}

void show(pClock ptr, char end){
    std::cout.fill('0');
    std::cout<< std::setw(2) << ptr->hr << ":"
        << std::setw(2) << ptr->min << ":"
        << std::setw(2) << ptr->sec << end;
}

void runs(pClock ptr, char end){
    while(true){
        Sleep(10);

        tick(ptr);
        show(ptr, end);
        
    }
}

