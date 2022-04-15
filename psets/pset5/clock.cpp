/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/

#include <iostream>
#include <iomanip>
//#include <unistd.h>
#include "clock.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


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
        Sleep(1000);

        tick(ptr);
        show(ptr, end);
        
    }
}

