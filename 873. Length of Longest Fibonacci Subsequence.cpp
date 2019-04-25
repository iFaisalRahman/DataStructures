/*
	873. Length of Longest Fibonacci Subsequence.cpp : Defines the entry point for the console application.
	A sequence X_1, X_2, ..., X_n is fibonacci-like if:

	n >= 3
	X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
	Given a strictly increasing array A of positive integers forming a sequence,
	find the length of the longest fibonacci-like subsequence of A.
	If one does not exist, return 0.

	Input: [1,3,7,11,12,14,18]
	Output: 3
	Explanation:
	The longest subsequence that is fibonacci-like:
	[1,11,12], [3,11,14] or [7,11,18].

	Hints:
	dp[i][j] = length of fibonacci-like subsequence ending at i,j [last two elements are i,j]
	we can use two sum problem to find the sum of two number A[l],A[r] equal to A[i].
	Then, dp[r][i]=1+dp[l][r];
	Ans is maximum dp[r][i]
*/
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lenLongestFibSubseq(vector<int>& A)
{
	vector<vector<int>>dp(A.size(), vector<int>(A.size(), 0));
	int ans = 0;

	for (int i = 2; i < A.size(); i++) // Starting from index 2, because at least 3 elements makes a fibonacci sequence.
	{
		/*
			Find l and r so that A[l]+A[r] = A[i] where l<r<i
			It is two sum problem.
		*/
		int l = 0, r = i - 1;

		while (l < r)
		{
			int sum = A[l] + A[r];

			if (sum == A[i])
			{
				dp[r][i] = 1 + dp[l][r];
				ans = max(ans, dp[r][i]); // cashing ans.
				l++;
				r--;
			}
			else if (sum < A[i])
			{
				l++;
			}
			else
			{
				r--;
			}
		}
	}

	return ans > 0 ? ans + 2 : 0;
}
int main()
{
	// in={ 1, 2, 3, 4, 5, 6, 7, 8 }; => 5
	vector<int>in{ 1, 3, 7, 11, 12, 14, 18};
	cout << lenLongestFibSubseq(in);
	cin.ignore();
	return 0;
}

