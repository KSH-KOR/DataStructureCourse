// infixall.cpp :
//
// The program evaluates a given infix expression which is fully parenthesized.
// It uses Dijkstra's two-stack algorithm. For simplicity of coding, however,
// the expression is to be fully parenthesized.
// For example:
//   ((3 - 1 ) * 5) + 4
//   2 * ((34 - 4) * 2)
//   1 + (((12 * 2) / 4) - 1)
//
// Author: idebtor@gmail.com
// 2020.04.05	created and assert() added
//
/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/
#include <iostream>
#include <math.h>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#if 0    //////////////////////////////////////////////////////////////////////
// set #if 1, if you want to use this stack using vector instead of STL stack.
// a basic stack functinality only provided for pedagogical purpose only.
#include <vector>
template <typename T>
struct stack {
	vector<T> item;

	bool empty() const {
		return item.empty();
	}
	auto size() const {
		return item.size();
	}
	void push(T const& data) {
		item.push_back(data);
	}
	void pop() {
		if (item.empty())
			throw out_of_range("stack<>::pop(): pop stack");
		item.pop_back();
	}
	T top() const {
		if (item.empty())
			throw out_of_range("stack<>::top(): top stack");
		return item.back();
	}
};
#else  /////////////////////////// using STL stack //////////////////////////
#include <stack>
#endif ///////////////////////////////////////////////////////////////////////

template <typename T>
void printStack(stack<T> orig) {

	//cout << "Step 2: your code here: copy printStack() template version from postfix.cpp\n";
	//cout << "Step 3: rewrite printStack() using recursion. refer to PDF file\n";

	if (orig.empty()) return;

	auto top = orig.top();
	orig.pop();
	printStack(orig);
	cout << top << " ";
	orig.push(top);

	//cout << endl;
}

// performs arithmetic operations.
double apply_op(double a, double b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	case '^': return pow(a, b);
	}
	cout << "Unsupported operator encountered: " << op << endl;
	return 0;
}

// there is a bug...
double compute(stack<double>& va_stack, stack<char>& op_stack) {
	double right = va_stack.top(); va_stack.pop();
	double left = va_stack.top(); va_stack.pop();
	char op = op_stack.top(); op_stack.pop();
	double value = apply_op(left, right, op);

	va_stack.push(value);
	DPRINT(cout << " va/op_stack.pop: " << value << endl;);
	return value;
}

int operatorRank(char op) {
	if (op == '+' || op == '-') return 1;
	else if (op == '*' || op == '/') return 2;
	else if (op == '^') return 3;
	else perror("There is no matching operator");
}

// returns value of expression after evaluation.
double evaluate(string tokens) {
	DPRINT(cout << ">evaluate: tokens=" << tokens << endl;);
	stack<double>  va_stack;              // stack to store operands or values
	stack<char> op_stack;                 // stack to store operators.
	double value = 0;

	for (size_t i = 0; i < tokens.length(); i++) {
		// token is a whitespace or an opening brace, skip it.
		if (isspace(tokens[i])) continue;
		DPRINT(cout << " tokens[" << i << "]=" << tokens[i] << endl;);

		// current token is a value(or operand), push it to va_stack.
		if (isdigit(tokens[i])) {
			int ivalue = 0;
			//cout << "your code here: to handle multi-digits(operand)\n";

			bool isMultiDigits = false;
			/*
			for (char e : "0123456789") {
				if (i == 0) break;
				if ((tokens[i - 1]) == e) {
					isMultiDigits = true;
					break;
				}
			}
			*/
			if (i != 0) {
				if (isdigit(tokens[i - 1])) isMultiDigits = true;
			}
			if (isMultiDigits) {
				ivalue = va_stack.top() * 10 + (tokens[i] - '0');
				va_stack.pop();
			}
			else {
				ivalue = (tokens[i] - '0');
			}

			va_stack.push(ivalue);
		}
		else if (tokens[i] == ')') { // compute it, push the result to va_stack

			//cout << "your code here\n";
			
			char op;
			double r_value;
			double l_value;
			double result;
			do {
				op = op_stack.top(); op_stack.pop();
				if (op == '(') break;
				r_value = va_stack.top(); va_stack.pop();
				l_value = va_stack.top(); va_stack.pop();
				result = apply_op(l_value, r_value, op);
				va_stack.push(result);
			} while (true);

		}
		else { // token is an operator; push it to op_stack.
			do {
				if (!op_stack.empty() && tokens[i] != '(' && op_stack.top() != '(') {
					if (operatorRank(op_stack.top()) >= operatorRank(tokens[i])) {
						compute(va_stack, op_stack);
					}
					else {
						break;
					}
				}
				else {
					break;
				}
			} while (true);
			op_stack.push(tokens[i]);
		}
	}

	DPRINT(cout << "tokens exhausted: now, check two stacks:" << endl;);
	DPRINT(printStack(va_stack);  cout << endl;);
	DPRINT(printStack(op_stack);  cout << endl;);

	//cout << "your code here: process if !op_stack.empty() \n";
	while (!op_stack.empty()) compute(va_stack, op_stack);
	assert(op_stack.size() == 0);
	assert(va_stack.size() == 1);
	value = va_stack.top();
	/*
	double r_value, l_value;
	char op;
	while (!op_stack.empty()) {
		r_value = va_stack.top(); va_stack.pop();
		l_value = va_stack.top(); va_stack.pop();
		op = op_stack.top(); op_stack.pop();
		value = apply_op(l_value, r_value, op);
		va_stack.push(value);
	}
	*/
	//cout << "your code here: post-conditions\n";

	//cout << "your code here: return & clean-up\n";

	return value;
}
