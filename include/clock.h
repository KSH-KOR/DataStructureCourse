struct Clock{
    int hr, min, sec;
};

using pClock = Clock*;

void tick(pClock ptr);
void show(pClock ptr, char option = '\n');
void runs(pClock ptr, char option);