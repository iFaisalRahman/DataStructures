/*
64. Minimum Path Sum
		Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

		Note: You can only move either down or right at any point in time.

		Example:

		Input:	[
					[1,3,1],
					[1,5,1],
					[4,2,1]
				]
		Output: 7
		Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int minPathSumHelper(vector<vector<int>>& grid, int row_start, int col_start, vector<vector<int>>& dp)
{
	if (row_start == grid.size() - 1 && col_start == grid[0].size() - 1)
	{
		dp[row_start][col_start] = grid[row_start][col_start];
		return dp[row_start][col_start];
	}

	if (row_start >= grid.size() || col_start >= grid[0].size())
	{
		return INT_MAX;
	}

	if (dp[row_start][col_start] != -1)
	{
		return dp[row_start][col_start];
	}

	dp[row_start][col_start] = min(minPathSumHelper(grid, row_start, col_start + 1, dp), minPathSumHelper(grid,
								   row_start + 1, col_start, dp)) + grid[row_start][col_start];
	return dp[row_start][col_start];
}
int minPathSum(vector<vector<int>>& grid)
{
	if (grid.empty())
	{
		return 0;
	}

	vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), -1));
	return minPathSumHelper(grid, 0, 0, dp);
}
int main()
{
	vector<vector<int>>grid
	{
		{1, 2},
		{5, 6},
		{1, 1}
	};
	/*{
		{1, 3, 1 },
		{1, 5, 1},
		{4, 2, 1}
	};*/
	cout << minPathSum(grid);
	cin.ignore();
	return 0;
}

