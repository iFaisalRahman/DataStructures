/*
673. Number of Longest Increasing Subsequence
	Given an unsorted array of integers, find the number of longest increasing subsequence.

	Example 1:
	Input: [1,3,5,4,7]
	Output: 2
	Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
	Example 2:
	Input: [2,2,2,2,2]
	Output: 5
	Explanation: The length of longest continuous increasing subsequence is 1,
	and there are 5 subsequences' length is 1, so output 5.

	HINTS:

	dp_len[i] = length of subsequence ending with element nums[i]; // nums[i] is in the subsequence
	dp_count[i] = # of subsequence can be construct.

	dp_len[i] = max(dp_len[j]) for all j<i and nums[i]<nums[j];
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int lengthOfLIS(vector<int>& nums, vector<int>& dp);
int findNumberOfLIS(vector<int>nums)
{
	if (nums.empty())
	{
		return 0;
	}

	vector<int>dp_len(nums.size(), 0);
	vector<int>dp_count(nums.size(), 0);
	dp_len[0] = 1;
	dp_count[0] = 1;
	int max_len = 1;
	int max_count = 1;

	for (int i = 1; i < dp_len.size(); i++)
	{
		int len = 0;
		int count = 0;

		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
			{
				if (len < dp_len[j])
				{
					count = dp_count[j];
					len = dp_len[j];
				}
				else if (len == dp_len[j])
				{
					count += dp_count[j];
				}
			}
		}

		dp_len[i] = 1 + len;
		dp_count[i] = count > 0 ? count : 1;

		if (max_len < dp_len[i])
		{
			max_len = dp_len[i];
			max_count = dp_count[i];
		}
		else if (max_len == dp_len[i])
		{
			max_count += dp_count[i];
		}
	}



	return max_count;

}
int lengthOfLIS(vector<int>& nums, vector<int>& dp)
{
	if (nums.empty())
	{
		return 0;
	}

	dp[0] = 1;
	int ans = 1;

	for (int i = 1; i < dp.size(); i++)
	{
		int len = 0;

		for (int j = 0; j < i; j++)
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
	//[1,3,5,4,7]
	// [2,2,2,2,2]
	//[1,2,4,3,5,4,7,2] => 3
	vector<int>in{ 1, 2, 4, 3, 5, 4, 7, 2 };
	cout << findNumberOfLIS(in);
	cin.ignore();
	return 0;
}

