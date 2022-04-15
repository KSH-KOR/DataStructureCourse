#include <iostream>
#define SIZE 5

struct Queue{
    int items[SIZE], front, rear;
};
using queue = Queue*;

queue newQueue();

bool full(queue q);

bool empty(queue q);

void enqueue(queue q, int element);

int dequeue(queue q);

void display(queue q);