// 221. Maximal Square.cpp : Defines the entry point for the console application.
//
/*
Given a 2D binary matrix filled with 0's and 1's,
find the largest square containing only 1's and return its area.

Example:

	Input:

	1 0 1 0 0
	1 0 1 1 1
	1 1 1 1 1
	1 0 0 1 0

	Output: 4
*/
/*
	dp[i][j] = length of square ending at i,j
	dp[i][j] = 1+min(dp[i-1][j-1],dp[i][j-1], dp[i-1][j])
	dp[i][j] = 1 + min (top-left square,left square and top square)
*/


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
	****-		*****
	****-		*****
	****-	=>	*****
	****-		*****
	++++?		*****

	Here '?' is the current element dp[i][j]
	We need to look at its top-left point, let point and top point that's end the square.
	The minimum value of that square would be consider to draw a square that ended at (i,j)
	*/
int findMinimumSquareLen(vector<vector<int>>& dp, int row, int col)
{
	int min_square_len;

	if (row > 0 && col > 0)
	{
		min_square_len = dp[row - 1][col - 1];
	}
	else
	{
		return 0;
	}

	if (col > 0)
	{
		min_square_len = min(dp[row][col - 1], min_square_len);
	}
	else
	{
		return 0;
	}

	if (row > 0)
	{
		min_square_len = min(dp[row - 1][col], min_square_len);
	}
	else
	{
		return 0;
	}

	return min_square_len;
}
int maximalSquare(vector<vector<char>>& matrix)
{
	vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(), 0));
	int ans = 0;

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] == '1')
			{
				dp[i][j] = 1 + findMinimumSquareLen(dp, i, j);
				ans = max(ans, dp[i][j]);
			}
		}
	}

	return ans * ans;
}


/////////////////////////////////
/*Next one is slow and bad solution*/
bool isPermeterOne(int row, int col, int l, vector<vector<char>>& matrix)
{
	if (l == 1)
	{
		return matrix[row][col] == '1';
	}

	for (int i = 0; i < l; i++)
	{
		if (matrix[row][col + i] == '0')
		{
			return false;
		}

		if (matrix[row + l - 1][col + i] == '0')
		{
			return false;
		}

		if (matrix[row + i][col] == '0')
		{
			return false;
		}

		if (matrix[row + i][col + l - 1] == '0')
		{
			return false;
		}
	}

	return true;
}
int maximalSquareSlow(vector<vector<char>>& matrix)
{
	if (matrix.empty())
	{
		return 0;
	}

	int row = matrix.size();
	int col = matrix[0].size();
	int len = (row > col ? col : row);
	int ans = 0;
	vector<vector<vector<bool>>>dp(row, vector<vector<bool>>(col, vector<bool>(1 + len, false)));

	for (int l = 0; l <= len; l++)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (l == 0)
				{
					dp[i][j][l] = true;
				}
				else if (l == 1)
				{
					dp[i][j][l] = matrix[i][j] == '1';

					if (dp[i][j][l] == true && ans < 1)
					{
						ans = 1;
					}
				}
				else
				{
					if ((i + l <= row) && (j + l <= col))
					{
						dp[i][j][l] = dp[i + 1][j + 1][l - 1] && isPermeterOne(i, j, l, matrix);

						if (dp[i][j][l] == true && ans < l)
						{
							ans = l;
						}
					}
				}
			}
		}
	}

	return ans * ans;
}
/////////////////////////////////
int main()
{
	/*
	{ {'0'} };
	*/
	vector<vector<char>>in =
	{
		{ '1', '0', '1', '0', '0' },
		{ '1', '0', '1', '1', '1' },
		{ '1', '1', '1', '1', '1' },
		{ '1', '0', '0', '1', '0' }
	};

	cout << maximalSquare(in);
	cin.ignore();


	return 0;
}

