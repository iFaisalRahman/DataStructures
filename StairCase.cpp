/*
	70. Climbing Stairs

	You are climbing a stair case. It takes n steps to reach to the top.

	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

	Note: Given n will be a positive integer.

	Example 1:

	Input: 2
	Output: 2
	Explanation: There are two ways to climb to the top.
	1. 1 step + 1 step
	2. 2 steps

*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n)
{
	vector<int>dp(1 + n, 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}
int climbStairs(int n)
{
	if (n < 2)
	{
		return 1;
	}

	int x = 1;
	int y = 1;
	int z = 0;

	for (int i = 2; i <= n; i++)
	{
		z = x + y;
		x = y;
		y = z;
	}

	return z;
}

int main()
{
	return 0;
}

