#include <iostream>
#include "stack.h"

//"a+b*(c-d)-e/f"
//"abcd-*+ef/-"
using namespace std;

int isp(char);
int icp(char);
char* get_postfix_exp(char*, int);
int calculate_postfix_exp(char*);

int main()
{
	char infix[] = "a+b*(c-d)-e/f";
	char* postfix = get_postfix_exp(infix, sizeof(infix)/sizeof(char));
	cout << postfix << endl;       //abcd-*+ef/-
	delete postfix;

	return 0;
}


int isp(char ch)
{
	switch(ch)
	{
		case '+': return 2;
		case '-': return 2;
		case '*': return 4;
		case '/': return 4;
		case '(': return 0;
		case ')': return 10;
		case '\0': return -1;
	}
	return 0;
}

int icp(char ch)
{
	switch(ch)
	{
		case '+': return 1;
		case '-': return 1;
		case '*': return 3;
		case '/': return 3;
		case '(': return 10;
		case ')': return 0;
		case '\0': return -1;
	}
	return 0;
}


char* get_postfix_exp(char* infix_exp, int len)
{
	Stack<char> stack;
	char* postfix_exp = new char[len];
	int index = 0;
	int new_index = 0;
	stack.push('\0');
	while(infix_exp[index] != '\0')
	{
		char income = infix_exp[index];
		if(income == '+' or income == '-' or income == '*' or income == '/' or income == '(' or income == ')')
		{
			if(isp(stack.get_top_element()) < icp(income))
				stack.push(income);
			else if(isp(stack.get_top_element()) > icp(income))
			{
				while(isp(stack.get_top_element()) > icp(income))
				{
					char outcome = stack.pop();
					postfix_exp[new_index] = outcome;
					new_index++;
				}
				if(isp(stack.get_top_element()) == icp(income))
					stack.pop();
				else
					stack.push(income);
			}
			else
				stack.pop();
		}
		else
		{
			postfix_exp[new_index] = income;
			new_index++;
		}
		index++;
	}
	while(!stack.is_empty())
	{
		postfix_exp[new_index] = stack.pop();
		new_index++;
	}

	return postfix_exp;
}
