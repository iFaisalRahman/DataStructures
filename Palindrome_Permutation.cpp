// Palindrome_Permutation.cpp : Defines the entry point for the console application.
// Given a string, determine if a permutation of the string could form a palindrome.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
bool palindrome_permutation(string s)
{
	unordered_map<char, int>map;
	int numberOfOdds = 0;

	for (char c : s)
	{
		map[c]++;

		if (map[c] % 2 == 1)
		{
			numberOfOdds++;
		}
		else
		{
			numberOfOdds--;
		}
	}

	return (numberOfOdds < 2);

}
int main()
{
	cout << palindrome_permutation("abbba");
	cin.ignore();
	return 0;
}

