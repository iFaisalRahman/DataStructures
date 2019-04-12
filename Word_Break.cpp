/*
139. Word Break
	Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

	Note:

	The same word in the dictionary may be reused multiple times in the segmentation.
	You may assume the dictionary does not contain duplicate words.
	Example 1:

	Input: s = "leetcode", wordDict = ["leet", "code"]
	Output: true
	Explanation: Return true because "leetcode" can be segmented as "leet code".
*/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
bool wordBreak(string s, vector<string>& wordDict)
{
	vector<bool>dp(1 + s.length(), false);
	dp[0] = true;
	unordered_set<string>set;

	for (string str : wordDict)
	{
		set.insert(str);
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (set.find(s.substr(0, i + 1)) !=
			set.end()) // We can improve our code instead of checking each length substring, check whether the length of the substring exist in dictionary or not.
		{
			dp[i + 1] = true;
			continue;
		}

		for (int j = 1; j <= i; j++)
		{
			if (dp[j] && (set.find(s.substr(j, i - j + 1)) != set.end()))
			{
				dp[i + 1] = true;
				break;
			}
		}
	}

	return dp[s.length()];
}
int main()
{

	//s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
	string s = "catsanddog";
	vector<string>dict = { "cats", "dog", "sand", "and", "cat" };
	cout << wordBreak(s, dict);
	return 0;
}

