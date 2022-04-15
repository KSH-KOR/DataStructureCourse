/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/

#include <iostream>
#include <vector>

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

template<typename T>
struct Stack{
    std::vector<T> item;
};
template<typename T>
using stack = Stack<T> *;


template<typename T>
void free(stack<T> s){ delete s; }

template<typename T>
int size(stack<T> s){ return s->item.size(); }

template<typename T>
bool empty(stack<T> s){ return s->item.empty(); }

template<typename T>
void pop(stack<T> s){ s->item.pop_back(); }

template<typename T>
T top(stack<T> s){ return s->item.back(); }

template<typename T>
void push(stack<T> s, T item){ 
    s->item.push_back(item); 
    DPRINT(std::cout << "\nsize: " << s->item.size());
    DPRINT(std::cout << "\ncapacity: " << s->item.capacity());
}

template<typename T>
void printStack(stack<T> s){
	if(empty(s)) return;

	auto t = top(s);
	std::cout<<t<<' ';
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

    Stack<std::string>* s = new Stack<std::string>;
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