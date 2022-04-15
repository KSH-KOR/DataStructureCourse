/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/

#include <iostream>
#include <math.h>

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

struct Stack{
    std::string *item;
    int N;
    int capacity;
};
using stack = Stack *;

stack newStack(int capacity = 1){
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

void resize(stack s, int new_capacity){
    std::string *copied = new std::string[new_capacity];
    for(int i=0; i<s->N; i++) copied[i] = s->item[i];
    delete[] s->item;
    s->item = copied;
    s->capacity = new_capacity;
}

void pop(stack s){ 
    s->N--; 
    if(s->N < s->capacity/4) resize(s, s->capacity/2);
}

std::string top(stack s){
    return s->item[s->N-1];
}

void push(stack s, std::string item){
    if(s->N == s->capacity) resize(s, s->capacity*2);
    s->item[s->N++] = item;
    DPRINT(std::cout << "\nsize: " << s->N);
    DPRINT(std::cout << "\ncapacity: " << s->capacity);
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

int main(){
    //int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    std::string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    //std::string list[] = {"s","t","o","p", "A"};

    int N = sizeof(list)/sizeof(*(list));
    //stack<std::string> s = new Stack<std::string>;
    stack s = newStack();
    /*
    for(auto x: list)
        push(s, x);
    */
    for(auto item: list){
        if(item != "-"){
            push(s, item);
        } else{
            std::cout << top(s) << ' ';
            pop(s);
        }
    }
    
    std::cout<<"\nsize: "<<size(s);
    std::cout<<"\ntop: "<<top(s);
    std::cout<<"\nstack T:: "; printStack(s);
    std::cout<<"\nstack B:: "; printStack_fromBottom(s);
    std::cout<<"\nHappy Coding";
}