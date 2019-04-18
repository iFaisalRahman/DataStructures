/*
	264. Ugly Number II
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:

1 is typically treated as an ugly number.
n does not exceed 1690.

//  dp[n]: n ugly number，
//  dp[n] = min(dp[i]*2, dp[j]*3, dp[k]*5)
//  dp[1]=1,i=j=k=1

	Another solution is using priority queue.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

struct compare
{
	bool operator()(const int& l, const int& r)
	{
		return l > r;
	}
};
int nthUglyNumberUsingHeap(int n)
{
	priority_queue<int, vector<int>, compare >pq;

	pq.push(1);
	int count = 1;
	int prevItem = 0;

	while (count <= n)
	{
		if (pq.top() != prevItem)
		{
			pq.push(pq.top() * 2);
			pq.push(pq.top() * 3);
			pq.push(pq.top() * 5);
			prevItem = pq.top();
			count++;
		}

		pq.pop();
	}

	return n > 1 ? prevItem : 1;
}
int nthUglyNumber(int n)
{
	vector<int>dp(n, 1);
	vector<int>value(3, 0);
	vector<int>index(3, 0);

	value[0] = 2;
	value[1] = 3;
	value[2] = 5;

	int count = 1;

	while (count < n)
	{
		dp[count] = min(min(value[0], value[1]), value[2]);

		if (dp[count] == value[0])
		{
			index[0] = index[0] + 1;
			value[0] = dp[index[0]] * 2;
		}

		if (dp[count] == value[1])
		{
			index[1] = index[1] + 1;
			value[1] = dp[index[1]] * 3;
		}

		if (dp[count] == value[2])
		{
			index[2] = index[2] + 1;
			value[2] = dp[index[2]] * 5;
		}

		count++;
	}

	return dp[n - 1];
}
int main()
{
	for (int i = 1; i < 101; i++)
	{
		cout << i << " " << nthUglyNumberUsingHeap(i) << " " << nthUglyNumber(i) << endl;
	}

	/*cout << nthUglyNumberUsingHeap(1407) << endl;
	cout << nthUglyNumber(1407) << endl;
	*/
	cin.ignore();
	return 0;
}

