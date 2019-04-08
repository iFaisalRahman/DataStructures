// 8QueenProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
bool HasHorizontalConflict(int row, int col, vector<vector<int>>& board)
{
	int size = board.size();

	for (int j = 0; j < size; j++)
	{
		if (board[row][j] == 1 && j != col)
		{
			return true;
		}
	}

	return false;
}
bool HasVerticalConflict(int row, int col, vector<vector<int>>& board)
{
	int size = board.size();

	for (int i = 0; i < size; i++)
	{
		if (board[i][col] == 1 && i != row)
		{
			return true;
		}
	}

	return false;
}
bool HasDiagonalConflict(int row, int col, vector<vector<int>>& board)
{
	int size = board.size();
	int i = row;
	int j = col;

	while (i < size - 1 && j < size - 1)
	{
		if (board[++i][++j] == 1)
		{
			return true;
		}
	}

	i = row;
	j = col;

	while (i > 0 && j > 0)
	{
		if (board[--i][--j])
		{
			return true;
		}
	}

	i = row;
	j = col;

	while (i > 0 && j < size - 1)
	{
		if (board[--i][++j] == 1)
		{
			return true;
		}
	}

	while (i < size - 1 && j > 0)
	{
		if (board[++i][--j] == 1)
		{
			return true;
		}
	}

	return false;
}
bool HasConflict(int row, int col, vector<vector<int>>& board)
{
	int size = board.size();

	return HasHorizontalConflict(row, col, board) || HasVerticalConflict(row, col, board)
		   || HasDiagonalConflict(row, col, board);
}
void NQueenHelper(int row, vector<vector<vector<int>>>& res, vector<vector<int>>& board, int n)
{
	if (row == n)
	{
		res.push_back(board);
		return;
	}

	for (int col = 0; col < n; col++)
	{
		if (HasConflict(row, col, board))
		{
			continue;
		}

		board[row][col] = 1;
		NQueenHelper(row + 1, res, board, n);
		board[row][col] = 0;
	}

	return ;
}
void NQueenProblem(int n)
{
	vector<int>col(n, 0);
	vector<vector<int>>board(n, col);
	vector<vector<vector<int>>>res;

	NQueenHelper(0, res, board, n);

	if (res.empty())
	{
		cout << "No Solution";
	}
	else
	{

		for (vector<vector<int>>sol : res)
		{
			cout << endl << "\n\n\n--------------------------------" << endl;

			for (int i = 0; i < n; i++)
			{


				for (int j = 0; j < n; j++)
				{
					cout << (sol[i][j] == 1 ? "X" : "0");
					cout << " | ";
				}

				cout << endl << "--------------------------------" << endl;
			}
		}
	}
}

int main()
{
	NQueenProblem(8);
	cin.sync();
	cin.ignore();
	return 0;
}

