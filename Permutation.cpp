// Permutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permutationHelper(vector<int>& nums, vector<vector<int>>& subs, vector<int>& sub, vector<bool>& visited)
{
	if (sub.size() == nums.size())
	{
		subs.push_back(sub);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (visited[i] == true)
		{
			continue;
		}

		// If duplicate elements exist, then avoid creating permutation for duplicate elements
		if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false)
		{
			continue;
		}

		sub.push_back(nums[i]);
		visited[i] = true;
		permutationHelper(nums, subs, sub, visited);

		sub.pop_back();
		visited[i] = false;
	}
}

vector<vector<int>> permutation(vector<int> nums)
{
	vector<vector<int>>subs;
	vector<int>sub;
	vector<bool>visited(nums.size(), false);
	sort(nums.begin(), nums.end());
	permutationHelper(nums, subs, sub, visited);

	return subs;
}
int main()
{
	vector<int>nums{ 1, 1, 1  };
	vector<vector<int>>subs;

	subs = permutation(nums);

	// print results
	for (int i = 0; i < subs.size(); i++)
	{
		cout << " [ ";

		for (int j = 0; j < subs[i].size(); j++)
		{
			cout << subs[i][j] << " , ";
		}

		cout << " ] " << endl;
	}

	cin.ignore();
	return 0;
}

