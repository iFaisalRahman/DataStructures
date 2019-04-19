/*
322. Coin Change

You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

	Example 1:

	Input: coins = [1, 2, 5], amount = 11
	Output : 3
	Explanation : 11 = 5 + 5 + 1

	Example 2 :

	Input : coins = [2], amount = 3
	Output : -1
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Time = O(n * amount)
Space = O(amount)
*/
int coinChange(vector<int>& coins, int amount)
{
	if (coins.empty())
	{
		return amount == 0 ? 0 : -1;
	}

	vector<vector<int>>dp(coins.size(), vector<int>(1 + amount, 0));

	for (int i = 0; i < coins.size(); i++)
	{
		int coin = coins[i];

		for (int j = 1; j <= amount; j++)
		{
			int x = dp_ret(i, j - coin, dp);
			int y = dp_ret(i - 1, j, dp);

			if (x == INT_MAX && y == INT_MAX)
			{
				dp[i][j] = INT_MAX;
			}
			else if (x == INT_MAX)
			{
				dp[i][j] = y;
			}
			else
			{
				dp[i][j] = min(1 + x, y);
			}
		}
	}

	return dp[coins.size() - 1][amount] == INT_MAX ? -1 : dp[coins.size() - 1][amount];
}

/*	Next solution is time=o(n*amount)
	space=o(n*amount)*/
int dp_ret(int i, int j, vector<vector<int>>& dp)
{
	if (j < 0 || i < 0)
	{
		return INT_MAX;
	}

	return dp[i][j];
}

int coinChangeDP(vector<int>& coins, int amount)
{
	if (coins.empty())
	{
		return amount == 0 ? 0 : -1;
	}

	vector<int>dp(amount + 1, 0);

	for (int i = 1; i <= amount; i++)
	{
		int min_value = INT_MAX;

		for (int j = 0; j < coins.size(); j++)
		{
			if (coins[j] > i)
			{
				continue;
			}

			if (dp[i - coins[j]] < INT_MAX)
			{
				min_value = min(1 + dp[i - coins[j]], min_value);
			}
		}

		dp[i] = min_value;
	}

	return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main()
{
	//1, 2, 5 & 11 => 3
	// 2 & 3 =>-1
	vector<int>coins{2, 1, 5};
	int amount = 11;

	cout << coinChangeDP(coins, amount);
	cin.ignore();
	return 0;
}

