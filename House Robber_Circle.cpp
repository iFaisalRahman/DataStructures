/*
213. House Robber II
	You are a professional robber planning to rob houses along a street.
	Each house has a certain amount of money stashed.
	All houses at this place are arranged in a circle.
	That means the first house is the neighbor of the last one.
	Meanwhile, adjacent houses have security system connected and
	it will automatically contact the police if two adjacent houses were broken into on the same night.

	Given a list of non-negative integers representing the amount of money of each house,
	determine the maximum amount of money you can rob tonight without alerting the police.

	Example 1:

	Input: [2,3,2]
	Output: 3
	Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
	because they are adjacent houses.

	We can decompose the problem into two robber problem 0...n-1 and 0...n-2, then return the max;

	https://leetcode.com/problems/house-robber-ii/discuss/227366/Thinking-process-from-easy-question-to-harder-question-within-the-same-question-set
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int rob(vector<int>& nums)
{

	if (nums.empty())
	{
		return 0;
	}

	vector<int>dp(1 + nums.size(), 0);
	vector<int>dp_notIncludingFirst(1 + nums.size(), 0);

	dp[1] = nums[0];
	dp_notIncludingFirst[1] = 0;

	for (int i = 2; i <= nums.size(); i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
		dp_notIncludingFirst[i] = max(dp_notIncludingFirst[i - 1], dp_notIncludingFirst[i - 2] + nums[i - 1]);
	}

	int ans = max(dp_notIncludingFirst[nums.size()], dp[nums.size() - 1]);
	return ans;
}
int main()
{
	vector<int>input{2, 3, 2};
	cout << rob(input);
	cin.ignore();
	return 0;
}

