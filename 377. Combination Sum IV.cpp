/* 377. Combination Sum IV
	Given an integer array with all positive numbers and no duplicates,
	find the number of possible combinations that add up to a positive integer target.
	https://leetcode.com/problems/combination-sum-iv/discuss/85120/C%2B%2B-template-for-ALL-Combination-Problem-Set
	Example:

	nums = [1, 2, 3]
	target = 4

	The possible combination ways are:
	(1, 1, 1, 1)
	(1, 1, 2)
	(1, 2, 1)
	(1, 3)
	(2, 1, 1)
	(2, 2)
	(3, 1)

	Note that different sequences are counted as different combinations.

	Therefore the output is 7.

		| 0 | 1 | 2 | 3 | 4 |  <= Targets
		---------------------
		| 1 | 1 | 2 | 4 | 7 |  <= DP[Target]

		DP[i] = sum{ DP[i-j] } for all j in nums.

	Backtracking & DP
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int combinationSum4(vector<int>& nums, int Target)
{
	if (nums.empty())
	{
		return 0;
	}

	vector<unsigned int>dp(1 + Target, 0);
	dp[0] = 1;

	for (int target = 1; target <= Target; target++)
	{

		for (int num : nums)
		{
			if (num > target)
			{
				continue;
			}

			dp[target] += dp[target - num];
		}
	}

	return dp[Target];
}
int main()
{
	// [1,2,3] & 4 => 7
	//[3,33,333] & 10000

	vector<int>nums{3, 33, 333};
	int target = 10000;
	cout << combinationSum4(nums, target);
	cin.ignore();
	return 0;
}

