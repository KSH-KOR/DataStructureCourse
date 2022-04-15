#include <iostream>

struct Node{
	int data;
	Node* next;

	Node(int i=0, Node* n = nullptr){
		this->data = i;
		this->next = n;
	}
	~Node() {};
};

int main(){
    Node* myNode = new Node();
    std::cout << myNode->data;

    return 0;
}
