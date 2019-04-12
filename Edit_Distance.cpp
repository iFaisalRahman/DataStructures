// Edit_Distance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int minDistance(string word1, string word2)
{
	int n = word1.length();
	int m = word2.length();
	vector<vector<int>>dp(1 + n, vector<int>(1 + m, 0));

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = i;
	}

	for (int i = 0; i <= m; i++)
	{
		dp[0][i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (word1[i - 1] == word2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
			}
		}
	}

	return dp[n][m];
}
int main()
{
	//intention,execution
	cout << minDistance("horse", "ros");
	//cout << minDistance("intention", "execution");
	cin.ignore();
	return 0;
}

