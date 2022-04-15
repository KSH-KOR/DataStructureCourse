/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/

#include <iostream>
#include <iomanip>

using namespace std;

struct Clock{
    int hr, min, sec;
};

void tick(Clock *ptr);
void show(Clock *ptr);

int main(void){
    Clock* clock = new Clock {14, 58, 56};

    for(int i=0; i<360; i++){
        tick(clock);
        show(clock);
    }

    delete clock;
    return 0;
}

void tick(Clock *ptr){
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

void show(Clock *ptr){
    cout.fill('0');
    cout<< setw(2) << ptr->hr << ":"
        << setw(2) << ptr->min << ":"
        << setw(2) << ptr->sec << endl;

}