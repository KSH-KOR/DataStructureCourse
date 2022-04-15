#include <iostream>

struct Stack{
    std::string *item;
    int N;
    int capacity;
};
using stack = Stack *;

stack newStack(int capacity){
    stack s = new Stack;
    s->item = new std::string[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

void free(stack s){
    delete[] s->item;
    delete s;
}

int size(stack s){ return s->N; }
bool empty(stack s){ return s->N == 0; }
void pop(stack s){ 
    s->N--; 

}

std::string top(stack s){
    return s->item[s->N-1];
}
void push(stack s, std::string item){
    s->item[s->N++] = item;
    /*
    s->N++;
    s->item[s->N] = item;
    */
}
void printStack(stack s){
    if(empty(s)) return;

    auto t = top(s);
    std::cout << t << ' ';
    pop(s);
    printStack(s);
    push(s, t);
}
void printStack_fromBottom(stack s){
    if(empty(s)) return;
    
    auto t = top(s);
    pop(s);
    printStack_fromBottom(s);
    std::cout << t << ' ';
    push(s, t);
}