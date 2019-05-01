// 303. Range Sum Query - Immutable.cpp : Defines the entry point for the console application.
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

/*
	Given a 2D matrix matrix,
	find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1)
	and lower right corner (row2, col2).

	Example:
		Given matrix =
			[
				[3, 0, 1, 4, 2],
				[5, 6, 3, 2, 1],
				[1, 2, 0, 1, 5],
				[4, 1, 0, 1, 7],
				[1, 0, 3, 0, 5]
			]

	sumRegion(2, 1, 4, 3) -> 8
	sumRegion(1, 1, 2, 2) -> 11
	sumRegion(1, 2, 2, 4) -> 12

	Hint: We can use DP to calculate area construct by region (0,0) & (i,j) for each (i,j)
	From here, we can calculate the area construct by region (i1,j1) & (i2,j2)
	s(i,j) = s(i-1,j)+s(i,j-1)-s(i-1,j-1)+A(i,j) => Area by (0,0)&(i,j)
	reg(i1,j1,i2,j2) = s(i2,j2) - s(i1-1,j2) - s(i2,j1-1) + s(i-1,j-1) => area by (i1,j1)&(i2,j2)
*/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
class NumMatrix
{
public:
	vector<vector<int>> memo;
	NumMatrix(vector<vector<int>>& matrix)
	{
		if (!matrix.empty())
		{
			memo = vector<vector<int>>(1 + matrix.size(), vector<int>(1 + matrix[0].size(), 0));

			for (int i = 0; i < matrix.size(); i++)
				for (int j = 0; j < matrix[0].size(); j++)
				{
					// s(i,j) = s(i-1,j)+s(i,j-1)-s(i-1,j-1)+A(i,j)
					memo[i + 1][j + 1] = memo[i][j + 1] + memo[i + 1][j] - memo[i][j] + matrix[i][j];
				}
		}
	}

	int sumRegion(int i1, int j1, int i2, int j2)
	{
		// reg(i1,j1,i2,j2) = s(i2,j2) - s(i1-1,j2) - s(i2,j1-1) + s(i-1,j-1)
		return memo[i2 + 1][j2 + 1] - memo[i1][j2 + 1] - memo[i2 + 1][j1] + memo[i1][j1];
	}
};

class NumArray
{
public:
	vector<int>prefix_sum;
	NumArray(vector<int>& nums)
	{
		prefix_sum = vector<int>(nums.size(), 0);

		for (int i = 0; i < nums.size(); i++)
		{
			prefix_sum[i] = (i > 0 ? prefix_sum[i - 1] : 0) + nums[i];
		}
	}

	int sumRange(int i, int j)
	{
		return prefix_sum[j] - (i > 0 ? prefix_sum[i - 1] : 0);
	}
};
int main()
{

	/*
	vector<int>nums{ -2, 0, 3, -5, 2, -1 };
	NumArray obj(nums);
	cout << obj.sumRange(0, 2);
	cout << obj.sumRange(2, 5);
	cout << obj.sumRange(0, 5);
	*/

	vector<vector<int>>matrix
	{
		{3, 0, 1, 4, 2},
		{ 5, 6, 3, 2, 1 },
		{ 1, 2, 0, 1, 5 },
		{4, 1, 0, 1, 7},
		{ 1, 0, 3, 0, 5 }
	};
	NumMatrix obj(matrix);
	cout << obj.sumRegion(1, 2, 2, 4);
	cin.ignore();
	return 0;
}

