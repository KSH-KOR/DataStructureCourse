#include "queue.h"

int main(){
    queue q= newQueue();

    dequeue(q);
    for(int i=0; i<6; i++){
        enqueue(q, i+1);
    }
    display(q);

    int elem = dequeue(q);
    if(elem != -1){
        std::cout << "dequeued: " << elem << std::endl;
    }
    display(q);

    enqueue(q, 7);

    display(q);

    enqueue(q, 8);

    dequeue(q);
    dequeue(q);

    display(q);

    return 0;
}