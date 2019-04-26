// (HARD)32. Longest Valid Parentheses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int longestValidParentheses(string s)
{
	if (s.empty())
	{
		return 0;
	}

	vector<bool>dp(s.length(), false);
	stack<int>stack;
	int index = 0;

	for (char c : s)
	{
		if (c == '(')
		{
			stack.push(index);
		}
		else
		{
			if (stack.empty())
			{
				dp[index] = false;
			}
			else
			{
				dp[index] = true;
				dp[stack.top()] = true;
				stack.pop();
			}
		}

		index++;
	}

	int ans = 0;
	int count = 0;

	for (int i = 0; i < dp.size(); i++)
	{
		if (dp[i] == true)
		{
			count++;
		}
		else
		{
			count = 0;
		}

		ans = max(ans, count);
	}

	return ans;
}
int main()
{
	//(() //2
	//")()())" //4
	string in = "((()()()))";
	cout << longestValidParentheses(in);
	cin.ignore();

	return 0;
}

