// Palindromic_longest_Subsequence.cpp : Defines the entry point for the console application.
/*
	516. Longest Palindromic Subsequence

	Given a string s, find the longest palindromic subsequence's length in s.
	You may assume that the maximum length of s is 1000.

	Example 1:
	Input:"bbbab"
	Output:4
	One possible longest palindromic subsequence is "bbbb".
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int LCS_Palindrome_helper(string& s, vector<vector<int>>& dp, int start, int end)
{
	if (start > end)
	{
		return 0;
	}

	if (start == end)
	{
		dp[start][end] = 1;
		return 1;
	}

	if (dp[start][end] != -1)
	{
		return dp[start][end];
	}

	if (s[start] == s[end])
	{
		dp[start][end] = 2 + LCS_Palindrome_helper(s, dp, start + 1, end - 1);
	}
	else
	{
		dp[start][end] = max(LCS_Palindrome_helper(s, dp, start + 1, end), LCS_Palindrome_helper(s, dp, start, end - 1));
	}

	return dp[start][end];

}

int LCS_Palindrome(string s)
{
	if (s.empty())
	{
		return 0;
	}

	vector<vector<int>>dp(s.length(), vector<int>(s.length(), -1));
	return LCS_Palindrome_helper(s, dp, 0, s.length() - 1);
}
int main()
{
	cout << LCS_Palindrome("hiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxr");
	cin.ignore();
	return 0;
}

