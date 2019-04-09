// Longest_Palindromic_Substring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
string LongestPalindromehelper(string s)
{
	if (s.empty())
	{
		return "";
	}

	vector<vector<bool>>dp(s.length(), vector<bool>(s.length(), false));
	int x = 0, y = 0;

	for (int len = 0; len < s.length(); len++)
	{
		// len=0 means sunstring length = len+1 = 1
		// dp[j][j] = true when substring length = 1;
		// dp[j][j+len] = s[j]==s[j+1] when substring length = 2;
		// dp[i][j] = dp[i+1][j-1] && s[i]==s[j] when substring length >2

		for (int j = 0; (j + len) < s.length(); j++)
		{
			if ((len >= 2 ? dp[j + 1][j + len - 1] : true) && (s[j] == s[j + len]))
			{
				dp[j][j + len] = true;
				x = j;
				y = len + 1;
			}
		}
	}

	return s.substr(x, y);
}

string longestPalindrome(string s)
{
	return LongestPalindromehelper(s);
}

int main()
{
	string s = "zabbab";
	cout << longestPalindrome(s);
	cin.ignore();
	return 0;
}

