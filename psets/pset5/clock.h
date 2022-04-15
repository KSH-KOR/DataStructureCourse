/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/

struct Clock{
    int hr, min, sec;
};

using pClock = Clock*;

void tick(pClock ptr);
void show(pClock ptr, char end = '\n');
void runs(pClock ptr, char end = '\n');