/*
	300. Longest Increasing Subsequence
	Given an unsorted array of integers, find the length of longest increasing subsequence.

	Example:

	Input: [10,9,2,5,3,7,101,18]
	Output: 4
	Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
	Note:

	There may be more than one LIS combination, it is only necessary for you to return the length.
	Your algorithm should run in O(n2) complexity.
	Follow up: Could you improve it to O(n log n) time complexity?
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int lengthOfLIS(vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}

	vector<int>dp(nums.size(), 0);
	dp[0] = 1;
	int ans = 1;

	for (int i = 1; i < dp.size(); i++)
	{
		int len = 0;

		for (int j = 0; j < i ; j++)
		{
			if (nums[i] > nums[j])
			{
				len = max(len, dp[j]);
			}
		}

		dp[i] = 1 + len;
		ans = max(ans, dp[i]);
	}

	return ans;
}
int main()
{
	//{10,9,2,5,3,7,101,18}

	vector<int>in{ 10, 9, 2, 5, 3, 7, 101, 18 };
	cout << lengthOfLIS(in);
	cin.ignore();
	return 0;
}

