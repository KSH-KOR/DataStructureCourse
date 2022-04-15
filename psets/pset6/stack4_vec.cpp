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

struct Stack{
    std::vector<std::string> item;
};
using stack = Stack *;

stack newStack(){ return new Stack; }
void free(stack s){ delete s; }
int size(stack s){ return s->item.size(); }
bool empty(stack s){ return s->item.empty(); }

void pop(stack s){ s->item.pop_back(); }

std::string top(stack s){ return s->item.back(); }

void push(stack s, std::string item){ 
    s->item.push_back(item); 
    DPRINT(std::cout << "\nsize: " << s->item.size());
    DPRINT(std::cout << "\ncapacity: " << s->item.capacity());
}
void printStack(stack s){
	if(empty(s)) return;

	auto t = top(s);
	std::cout<<t<<' ';
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