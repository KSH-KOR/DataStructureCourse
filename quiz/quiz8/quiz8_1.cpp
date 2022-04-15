/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/
#include <iostream>

int main(){

    int* p = new int(25);
    std::cout << *p << std::endl;
    int* q = p;
    std::cout << *q;
    *q = 34;
    delete p; // You should delete the first memory you allocated. If you dont, then it's gonna remain and be losted which is a junk.
    q = new int(56);
    p = new int(78);
    delete q;
    delete p;

    return 0;
}