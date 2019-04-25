// 84. Largest Rectangle In Histogram.cpp : Defines the entry point for the console application.
/*

	Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
	find the area of largest rectangle in the histogram.
	Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
	The largest rectangle is shown in the shaded area, which has area = 10 unit.

	Brute Force: O(n2)
	We need to compute it within o(n)
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int largestRectangleAreaBruteForce(vector<int>& heights)
{
	/*
	 o(n2) time complexity
	*/
	/*
		for each bar, expand the bar towards left and right.
		whenever we can't expand (the next bar's height is less than current bar), we will stop.
		we will calculate the area. ( This is the maximum area a bar can expand)
		compare the ans with previous and store it if it is larger.
	*/
	int ans = 0;

	for (int i = 0; i < heights.size(); i++)
	{
		/*
			We will try to expand with current bar's height towards both direction.
			If we hit a smaller bar, then we will stop expanding on that direction.
		*/
		int left = i;
		int right = i;
		bool expand = true;

		while (expand)
		{
			expand = false;

			if (left >= 0 && heights[left] >= heights[i])
			{
				left--;
				expand = true;
			}

			if (right < heights.size() && heights[right] >= heights[i])
			{
				right++;
				expand = true;
			}
		}

		/*
			left/right index will point to the bar which is smaller than the current bar, or they can point to out of index;
			Hence, area = height*(right-left-1)
		*/
		ans = max(ans, heights[i] * (right - left - 1));
	}

	return ans;
}
int largestRectangleArea(vector<int>& heights)
{
	stack<int> s;
	/*
		If current bar is taller than top bar in stack, then insert it.
		if next bar is smaller than top bar in stack,
			then pop bar's from stack until the stack top is not smaller bar than the next bar.
			When we pop bar from stack, we will calculate the area. The right index would be the next bar index.

		When all bar get scanned, pop all bars from stack and calculate their areas.
	 */
	int ans = 0;

	for (int i = 0; i < heights.size(); i++)
	{
		if (s.empty() || heights[i] >= heights[s.top()])
		{
			s.push(i);
		}
		else
		{
			while (!s.empty() && heights[i] < heights[s.top()])
			{
				/*
					Stack will always have bars in increasing order.
					Hence, top bar can expand left till the index of next previous bar in the stack
					so, left index = index of previous top bar +1
					right index = index of curr bar which is not in stack.
				*/
				int curr = s.top();
				s.pop();
				int left = s.empty() ? 0 : s.top() + 1;
				int area = heights[curr] * (i - left); // max area created by bar s.top
				ans = max(area, ans);
			}

			s.push(i);
		}
	}

	// if stack is not empty
	while (!s.empty())
	{
		int curr = s.top();
		s.pop();
		int left = s.empty() ? 0 : s.top() + 1; // bar can expand toward left till to the previous bar in the stack;
		int right = heights.size();
		int area = heights[curr] * (right - left); // max area created by bar s.top
		ans = max(area, ans);
	}

	return ans;
}
int main()
{
	// [2,1,5,6,2,3] //10
	// [2] //2
	// [2,1,2] // 3
	// [5, 4, 1, 2] //8
	vector<int> in{ 5, 4, 1, 2 };
	cout << largestRectangleArea(in) << endl;
	cout << largestRectangleAreaBruteForce(in);
	cin.ignore();
	return 0;

	/*

		i=0:
		stack{}
		current bar=5
		in{ 5, 4, 1, 2 };
		5 will push into stack.

		i=1:
		stack{5}
		current bar=4
		in{ 5, 4, 1, 2 };

		Since current bar is smaller than the top bar (5) in the stack.
		Hence, we there is no way the top bar (5) can expand to the right;
		So,
			calculate the maximum area the top bar (5) can construct
			and pop it out from the stack
			and push the current bar.

		area = 5 * (1-0) = 5;
		stack{4}

		i=2:
		stack{4}
		current bar=1
		in{ 5, 4, 1, 0, 2 };

		Since current bar is smaller than the top bar (4) in the stack.
		Hence, we there is no way the top bar (4) can expand to the right;
		So,
			calculate the maximum area the top bar (4) can construct
			and pop it out from the stack
			and push the current bar.
		area = 4 * (2-0) = 8 // Here 4 is last element in the stack, hence it can expand till first bar ( 0 index)
		stack{1}

		i=3:
		stack{1}
		current bar=2
		in{ 5, 4, 1, 2 };
		stack{1,2}


		All bar get scanned.
		Since stack is not empty, that means, the bar inside the stack can expand to the end of the histogram.
		hence, right=in.size();
		left = previous bar in the stack+1;

		stack{1,2}
		area = 2 * (5-(3+1)) = 2

		stack{1}
		area = 1 * (5-(0)) = 5

	*/
}

