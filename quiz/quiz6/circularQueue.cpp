#include <iostream>
#define SIZE 5

struct Queue{
    int items[SIZE], front, rear;
};
using queue = Queue*;

queue newQueue(){
    queue q = new Queue;
    q->front = -1;
    q->rear = -1;
    return q;
}

bool full(queue q){
    if(q->front == 0 && q->rear == SIZE-1) return true;
    if(q->front == q->rear+1) return true;
    return false;
}

bool empty(queue q){
    if(q->front == -1) return true;
    return false;
}

void enqueue(queue q, int element){
    if(full(q)){
        std::cout << "Queue is full" << std::endl;
    } else{
        if(q->front == -1) q->front = 0;
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = element;
        std::cout << "enqueued: " << element << std::endl;
    }
}

int dequeue(queue q){
    int element;
    if(empty(q)){
        std::cout << "Queue is empty" << std::endl;
    } else{
        element = q->items[q->front];
        if(q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else{
            q->front = (q->front+1)%SIZE;
        }
        return element;
    }
    return -1;
}

void display(queue q){
    int i;
    if(empty(q)){
        std::cout << "Queue is full" << std::endl;
    } else{
        std::cout << "Front[" << q->front << "]\n";
        std::cout <<"Items: ";
        for(i = q->front; i!=q->rear; i=(i+1)%SIZE){
            std::cout << q->items[i] << ' ';
        }
        std::cout << q->items[i];
        std::cout << std::endl << "Rear[" << q->rear << "]\n";

    }
}