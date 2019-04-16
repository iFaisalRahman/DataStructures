/*
	Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

	Example:

	Input: [-2,1,-3,4,-1,2,1,-5,4],
	Output: 6
	Explanation: [4,-1,2,1] has the largest sum = 6.

	Solution:
	Here first we need to find max sub array ending at index i
	BTW, this not max sub array at length of index i.
	dp[i] = max( dp[i-1]+nums[i] , nums[i] ) // Whether we extend the subarray or start new subarray

	Then we need to do another pass to find which dp[i] is maximum.

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums)
{

	if (nums.empty())
	{
		return 0;
	}

	vector<int>dp(nums.size(), 0);

	// dp[i] = maximum sum sub array ending at i
	dp[0] = nums[0];

	for (int i = 1; i < dp.size(); i++)
	{
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
	}

	int ans = INT_MIN;
	int index = 0;

	for (int i = 0; i < dp.size(); i++)
	{
		if (ans < dp[i])
		{
			ans = dp[i];
			index = i;
		}
	}

	/*
	// Print the subarray
	int tempAns = ans;

	for (int i = index; i >= 0; i--)
	{
		cout << i;

		if (tempAns == 0)
		{
			break;
		}

		tempAns -= tempAns - nums[i];
	}*/

	return ans;
}
int main()
{
	cout << maxSubArray(vector<int> { -2, 1, -3, 4, -1, 2, 1, -5, 4});
	cin.ignore();
	return 0;
}

