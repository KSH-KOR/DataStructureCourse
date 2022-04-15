/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/
#include <iostream>

struct List{
    std::string who;
    char data;
    List *link;
};

int main(){

    List a, b, c;
    List *p, *q, *r;

    //(1) Let each p, q, and r point to a, b, and c;
    p = &a;
    q = &b;
    r = &c;
    //(2) Store each 'X', 'Y', and 'Z' in data using p, q, and r.
    p->data = 'X';
    q->data = 'Y';
    r->data = 'Z';
    //(3) Connect them using p, q and r as shown below:
    p->link = q;
    q->link = r;
    r->link = nullptr;

    std::cout << p->data << std::endl;
    std::cout << p->link->data << std::endl;
    std::cout << p->link->link->data << std::endl;


    return 0;
}