// 223. Rectangle Area.cpp : Defines the entry point for the console application.
/*
	Find the total area covered by two rectilinear rectangles in a 2D plane.
	Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

	Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
	Output: 45
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool IsOverlap(int A, int B, int C, int D, int E, int F, int G, int H)
{
	if (A >= G || E >= C)
	{
		return false;
	}

	if (B >= H || F >= D)
	{
		return false;
	}

	return true;

}
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	//(A,B) (C,D)
	//(E,F) (G,H)
	int area1 = (C - A) * (D - B);
	int area2 = (G - E) * (H - F);

	//First check whether they overlap or not
	if (!IsOverlap(A, B, C, D, E, F, G, H))
	{
		return area1 + area2;
	}

	return	 area1 - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F)) + area2;
}

int main()
{
	//0, 0, 50000, 40000, 0, 0, 50000, 40000
	// A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2

	cout << computeArea(0, 0, 50000, 40000, 0, 0, 50000, 40000);
	cin.ignore();
	return 0;
}

