
// 416. Partition Equal Subset Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
bool canPartition(vector<int>& nums, int target)
{
	vector<bool>dp(1 + target, false);
	dp[0] = true;

	for (int i = 0; i < nums.size(); i++)
	{
		for (int k = target; k >= 1 ; k--)
		{
			dp[k] = (k - nums[i] >= 0 ? dp[k - nums[i]] : false) || dp[k];
		}
	}

	return dp[target];
}

bool canPartition(vector<int>& nums)
{
	int sum = 0;

	for (int num : nums)
	{
		sum += num;
	}

	if (sum % 2 == 0)
	{
		return canPartition(nums, sum >> 1);
	}
	else
	{
		return false;
	}
}
int main()
{
	//{1, 5, 11, 5}
	//{2,2,3,5}
	cout << canPartition(vector<int> { 1, 5, 11, 5 });
	//cout << canPartition(vector<int> {2, 2, 3, 5}, 6);
	cin.ignore();
	return 0;
}

