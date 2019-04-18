/*
	Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

	Example 1:
	Input: [1,3,5,4,7]
	Output: 3
	Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
	Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.


	loop through the array.
	Check current element > previous element.
	If it is, then len++;
	if not, then start counting for this element.
	update ans. ans = max(ans.len);
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findLengthOfLCIS(vector<int>& nums)
{
	int ans = 0;
	int curr_subsequence_len = 0;
	int prev_num = INT_MIN;

	for (int num : nums)
	{
		if (num > prev_num)
		{
			curr_subsequence_len++;
		}
		else
		{
			curr_subsequence_len = 1;
		}

		prev_num = num;
		ans = max(ans, curr_subsequence_len);
	}

	return ans;
}
int main()

{
	//{1, 3, 5, 4, 7}
	//{1, 5, 9, 13, 15, 17, 16, 18, 19, 21, 23, 25, 27, 20}
	vector<int>in({ 1, 5, 9, 13, 15, 17, 16, 18, 19, 21, 23, 25, 27, 20 });
	cout << findLengthOfLCIS(in);
	cin.ignore();
	return 0;
}

