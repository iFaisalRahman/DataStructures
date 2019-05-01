// 368. Largest Divisible Subset.cpp : Defines the entry point for the console application.
/*

	Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

	Si % Sj = 0 or Sj % Si = 0.

	If there are multiple solutions, return any subset is fine.

	Example 1:

	Input: [1,2,3]
	Output: [1,2] (of course, [1,3] will also be ok)
	Example 2:

	Input: [1,2,4,8]
	Output: [1,2,4,8]

*/
/*

If we sort the number in ascending order, then a  finding a subset (x1,x2,x3...xn) is enough, if xi is divisor of xi-1; for i in this subset.
Sort the array.

	T[n] = the length of the largest divisible subset whose largest number is a[n]

	T[n+1] = max{ 1 + T[i] if a[n+1] mod a[i] == 0 else 1 }
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums)
{


	if (nums.empty())
	{
		return{};
	}

	vector<int>count(nums.size(), 0); // store the largest count of divisor of element i
	vector<int>prev(nums.size(), -1); // previous divisor of element i

	sort(nums.begin(), nums.end());
	int max = 0; // It will store the max value of count[i]
	int max_ind = 0; // it will store which elements has max number of divisor

	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] % nums[j] == 0)
			{
				if (count[i] < 1 + count[j])
				{
					count[i] = 1 + count[j];
					prev[i] = j;

					if (max < count[i])
					{
						max = count[i];
						max_ind = i;
					}
				}
			}
		}
	}

	vector<int>result(max + 1, 0);

	while (max >= 0)
	{
		result[max] = nums[max_ind];
		max_ind = prev[max_ind];
		max--;
	}

	return result;
}

int main()
{
	/*
	Input: [1, 2, 3]
	// {1, 2, 3, 4, 6, 8, 12, 24} => {1,2,4,8,24} or {1,3,6,12,24}
	//{0} =>0
	//{23,47} => {23} or {47}
	Output : [1, 2](of course, [1, 3] will also be ok)
	*/
	vector<int>input{0, 1, 23, 46};
	vector<int>result = largestDivisibleSubset(input);
	cin.ignore();
	return 0;
}

