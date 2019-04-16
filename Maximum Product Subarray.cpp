/*
	152. Maximum Product Subarray

	Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

	Example 1:

	Input: [2,3,-2,4]
	Output: 6
	Explanation: [2,3] has the largest product 6.
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxProduct(vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}

	int max_product_so_far = 1;
	int min_product_so_far = 1;
	int ans = INT_MIN;

	for (int num : nums)
	{
		if (num < 0)
		{
			int temp = max_product_so_far;
			max_product_so_far = min_product_so_far;
			min_product_so_far = temp;
		}

		max_product_so_far = max(max_product_so_far * num, num);
		min_product_so_far = min(min_product_so_far * num, num);
		ans = max(max_product_so_far, ans);
	}

	return ans;
}
int maxProductDP(vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}

	vector<int>dp_max(nums.size(), 0);
	vector<int>dp_min(nums.size(), 0);
	dp_max[0] = nums[0];
	dp_min[0] = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		int max_product = dp_max[i - 1] * nums[i];
		int min_product = dp_min[i - 1] * nums[i];
		dp_max[i] = max(nums[i], max(max_product, min_product));
		dp_min[i] = min(nums[i], min(min_product, max_product));
	}

	int ans = INT_MIN;

	for (int val : dp_max)
	{
		ans = max(ans, val);
	}

	return ans;
}

int main()
{
	//{2, 3, -2, 4} //6
	//{-2, 0, -1} //0
	//{-2, 0, 1} //1
	//{-1, -2, -9, -6} // 108
	cout << maxProduct(vector<int> {-1, -2, -9, -6});
	cin.ignore();
	return 0;
}

