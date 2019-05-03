// 376. Wiggle Subsequence.cpp : Defines the entry point for the console application.
/*
	A sequence of numbers is called a wiggle sequence if the differences between
	successive numbers strictly alternate between positive and negative.
	The first difference (if one exists) may be either positive or negative.
	A sequence with fewer than two elements is trivially a wiggle sequence.

	For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3)
	are alternately positive and negative.
	In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences,
	the first because its first two differences are positive and the second because its last difference is zero.

	Example 1:

	Input: [1,7,4,9,2,5]
	Output: 6
	Explanation: The entire sequence is a wiggle sequence.
	Example 2:

	Input: [1,17,5,10,13,15,10,5,16,8]
	Output: 7
	Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
	Example 3:

	Input: [1,2,3,4,5,6,7,8,9]
	Output: 2
*/

/*
Follow up:
Can you do it in O(n) time?
*/
/*
	up[i] => Length of Wiggle sequence that ends at i-th element with UP status.
	down[i] = Length of Wiggle sequence that ends at i-th element with UP status.

	up[i] = 1 + max(down[j]) here, 0<= j <i and nums[j] < nums[i] (UP status)
	down [i] =  1 + max (up[j]) here, 0<= j <i and nums[j] > nums[i] (down status)

	up[0] = down [0] = 1
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int wiggleMaxLength(vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}

	vector<int>up(nums.size(), 1);
	vector<int>down(nums.size(), 1);
	int ans = 1;

	for (int i = 1; i < nums.size(); i++)
	{
		int prev_max_down = 0, prev_max_up = 0;

		for (int j = i - 1; j >= 0; j--)
		{
			if (nums[j] < nums[i] && prev_max_down < down[j])
			{
				prev_max_down = down[j];
			}
			else if (nums[j] > nums[i] && prev_max_up < up[j])
			{
				prev_max_up = up[j];
			}
		}

		up[i] = 1 + prev_max_down;
		down[i] = 1 + prev_max_up;
		ans = max(ans, max(up[i], down[i]));
	}

	return ans;
}

int main()
{
	//{1,7,4,9,2,5} => 6
	//{ 1,2,3,4,5,6,7,8,9} => 2
	vector<int>input{ 1 };
	cout << wiggleMaxLength(input);
	cin.ignore();
	return 0;
}

