/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/

#include <iostream>

template<typename T>
struct Stack{
    T *item;
    int N;
    int capacity;
};

template<typename T>
using stack = Stack<T> *;

template<typename T>
stack<T> newStack(int capacity, stack<T> s){
    s->item = new T[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

template<typename T>
void free(stack<T> s){
    delete[] s->item;
    delete s;
}

template<typename T>
int size(stack<T> s){ return s->N; }

template<typename T>
bool empty(stack<T> s){ return s->N == 0; }

template<typename T>
void pop(stack<T> s){ s->N--; }

template<typename T>
std::string top(stack<T> s){ return s->item[s->N-1]; }

template<typename T>
void push(stack<T> s, T item){ s->item[s->N++] = item; }

template<typename T>
void printStack(stack<T> s){
    if(empty(s)) return;

    auto t = top(s);
    std::cout << t << ' ';
    pop(s);
    printStack(s);
    push(s, t);
}

template<typename T>
void printStack_fromBottom(stack<T> s){
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
    stack<std::string> s = newStack(N, new Stack<std::string>);
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