/*

	120. Triangle
	Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

	For example, given the following triangle
	Input:
			[
				[2],
				[3,4],
				[6,5,7],
				[4,1,8,3]
			]
	Output : 11 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

	Note:

	Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle)
{
	int total_row = triangle.size();
	int total_col_in_last_row = triangle[total_row - 1].size();

	vector<int>dp(total_col_in_last_row, 0);
	vector<int>dp_prev(total_col_in_last_row, 0);

	int ans = INT_MAX;

	int prev = 0;

	for (int i = 0; i < total_row; i++)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			int temp = dp[j];

			if (j == 0)
			{
				dp[j] = dp[j] + triangle[i][j];
			}
			else if (j == triangle[i].size() - 1)
			{
				dp[j] = prev + triangle[i][j];
			}
			else
			{
				dp[j] = min(prev, dp[j]) + triangle[i][j];
			}

			if (i == total_row - 1)
			{
				ans = min(ans, dp[j]);
			}

			prev = temp;
		}
	}

	return ans;
}
int main()
{
	vector<vector<int>>triangle
	{
		{2 },
		{3, 4},
		{6, 5, 7},
		{4, 1, 8, 3}
	};

	cout << minimumTotal(triangle);
	cin.ignore();
	return 0;
}

