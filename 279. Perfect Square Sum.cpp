// 279. Perfect Square Sum.cpp : Defines the entry point for the console application.
/*
 Like Coin Change Problem for DP.
 Try to use static DP
 https://leetcode.com/problems/perfect-squares/discuss/71512/Static-DP-C%2B%2B-12-ms-Python-172-ms-Ruby-384-ms
 https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int numSquareStaticDP(int n)
{
	vector<int>dp(1, 0);

	while (dp.size() <= n)
	{
		int m = dp.size();
		int square = INT_MAX;

		for (int i = 1; i * i <= m; i++)
		{
			square = min(square, 1 + dp[m - i * i]);
		}

		dp.push_back(square);
	}

	return dp.back();
}
int numSquares(int n)
{
	vector<int>nums(1 + n, 0);
	int num = 0;

	while (1)
	{
		int sqr_num = num * num;

		if (sqr_num > n)
		{
			break;
		}

		nums[num] = sqr_num;
		num++;
	}

	vector<vector<int>>dp(num, vector<int>(1 + n, 0));

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 && j > 0)
			{
				dp[i][j] = INT_MAX;
				continue;
			}

			if (j == 0)
			{
				dp[i][j] = 0;
				continue;
			}

			if (j >= nums[i])
			{
				dp[i][j] = min(1 + dp[i][j - nums[i]], dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[num - 1][n];
}
int main()
{
	//12 =>3
	//13 =>2
	//5156
	int input = 12;
	cout << numSquares(input) << endl;
	cout << numSquareStaticDP(input);
	cin.ignore();
	return 0;
}

