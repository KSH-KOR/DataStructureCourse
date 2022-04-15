// postfix.cpp :
//
// The program evaluates a given postfix expression and produces a fully
// parenthesized infix expression. If the postfix expression may be 
// evaluated to a numeric value if it is expressed using numerically.
// For simplicity of coding, however, the postfix expression consists
// of single character operands and operators only and may have spaces.
//
// Author: idebtor@gmail.com
// 2020.04.05	Creation
// 2020.10.03	evaluation of numerical postfix expressions
//
/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// change the printStack to use template once you finish part 1 in step 1.
// prints the stack contents from the bottom. 
template <typename T>
void printStack(stack<T> orig) {

	//cout << "your code here" << endl;
	if (orig.empty()) return;
	
	stack<T> temp;
	while (!orig.empty()) {
		temp.push(orig.top());
		orig.pop();
	}
	while (!temp.empty()) {
		cout << temp.top() << " ";
		orig.push(temp.top());
		temp.pop();
	}


}


// returns a fully parenthesized infix expression in string after postfix evaluation.
string evaluate(string tokens) {
	stack<string> st;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// current token is a value(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {

			//cout << "your code here" << endl;
			if (st.top() != "+" && st.top() != "-" && st.top() != "*" && st.top() != "/") {
				string temp = "";
				string r_value = st.top();
				st.pop();
				string l_value = st.top();
				st.pop();
				
				temp = "(" + l_value + token + r_value + ")";
				
				st.push(temp);
			}
			else {
				string s = "";
				s += token;
				st.push(s);
			}

		}
		else {  // push the operand
			DPRINT(cout << "  push: " << token << endl;);
			// convert token(char type) to a string type and push it to the stack

			//cout << "your code here" << endl;
			string s="";
			s += token;
			st.push(s);

		}
	}

	DPRINT(cout << "token exhausted: \n";);
	DPRINT(printStack(st););
	DPRINT(cout << "stack size() should be 1.\n";);

	assert(st.size() == 1);

	//cout << "your code here" << endl;

	DPRINT(cout << "<evaluate() returns " << "your expr" << endl;);
	return st.top();
}

// returns true if the tokens consist of '+', '-', '*', '/', spaces, and 
// digits (0 ~ 9), false otherwise.
bool is_numeric(string tokens) {

	bool isConsistOf=true;
	bool temp = false;
	//cout << "your code here" << endl;
	for (char token : tokens) {
		temp = false;
		for (char e : " +-*/0123456789") {
			if (token == e) {
				temp = true;
				break;
			}
		}
		isConsistOf = temp && isConsistOf;
		if (!isConsistOf) break;
	}

	return isConsistOf;
}

// returns a numeric value after evaluating the postfix evaluation.
double evaluate_numeric(string tokens) {
	stack<double> st;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// if token is a operator, evaluate; if a digit(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			// checking the stack top() for right operand 
			// checking the stack top() for left oprand 
			// compute the expression and push the result

			//cout << "your code here" << endl;
			double r_value = st.top();
			st.pop();
			double l_value = st.top();
			st.pop();
			double e_value = 0;
			if (token == '+') e_value = l_value + r_value;
			else if (token == '-') e_value = l_value - r_value;
			else if (token == '*') e_value = l_value * r_value;
			else if (token == '/') e_value = l_value / r_value;
			else perror("Something is wrong. There is no matching operator");
			st.push(e_value);
			
		}
		else { // push the operand (digit) in a value to the stack
			// convert token to a numeric data type and push it the stack

			//cout << "your code here" << endl;
			double d = token - '0';
			st.push(d);

		}
	}

	DPRINT(cout << "token exhausted: check the stack, its size() should be 1.\n";);
	DPRINT(printStack(st););

	//cout << "your code here" << endl;
	double expr = st.top();

	DPRINT(cout << "<evaluate() returns " << expr << endl;);
	return expr;
}
