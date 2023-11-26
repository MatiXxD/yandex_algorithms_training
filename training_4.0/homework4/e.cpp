#include <iostream>
#include <string>
#include <stack>
#include <cstdio>

void generateBrackets(int n, std::string brackets, std::stack<char>& stack){

	if(brackets.size() == n){
		printf("%s\n", brackets.c_str());
		return;
	}

	if(n - brackets.size() > stack.size()){
		brackets.push_back('('); stack.push('(');
		generateBrackets(n, brackets, stack);
		brackets.pop_back(); stack.pop();
		brackets.push_back('['); stack.push('[');
		generateBrackets(n, brackets, stack);
		brackets.pop_back(); stack.pop();
	}
	if(!stack.empty()){
		char top = stack.top();
		if(top == '('){
			stack.pop(); brackets.push_back(')');
			generateBrackets(n, brackets, stack);
			brackets.pop_back(); stack.push('(');
		}
		else if(top == '['){
			stack.pop(); brackets.push_back(']');
			generateBrackets(n, brackets, stack);
			brackets.pop_back(); stack.push('[');
		}
	}

}

int main(){

	int n; std::cin >> n;
	if(!(n % 2)){
		std::string brackets;
		std::stack<char> stack;
		generateBrackets(n, brackets, stack);
	}
	else{
		std::cout << "" << std::endl;
	}

	return 0;

}