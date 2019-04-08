// Palindrome-Partitioning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string& str, int start, int end)
{
	if (start == end)
	{
		return true;
	}

	while (start <= end)
	{
		if (str[start] != str[end])
		{
			return false;
		}

		start++;
		end--;
	}

	return true;
}
void partitionHelper(string& str, vector<vector<string>>& subs, vector<string>& sub, int start)
{
	if (start == str.size())
	{
		subs.push_back(sub);
		return ;
	}

	for (int i = start; i < str.length(); i++)
	{
		if (!isPalindrome(str, start, i))
		{
			continue;
		}

		sub.push_back(str.substr(start, i - start + 1));
		partitionHelper(str, subs, sub, i + 1);
		sub.pop_back();
	}
}

vector<vector<string>> partition(string s)
{
	vector<vector<string>>subs;
	vector<string>sub;
	partitionHelper(s, subs, sub, 0);
	return subs;
}
int main()
{
	string s = "aabryrryrbaa";
	vector<vector<string>>subs = partition(s);

	for (int i = 0; i < subs.size(); i++)
	{
		for (int j = 0; j < subs[i].size(); j++)
		{
			cout << subs[i][j] << " , ";
		}

		cout << endl;
	}

	cin.ignore();
	return 0;
}

