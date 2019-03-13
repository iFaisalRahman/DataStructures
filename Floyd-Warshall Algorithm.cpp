// Floyd-Warshall Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
struct Graph
{
	int totalVertices;
	vector<vector<int>>adjList;

public:
	Graph(int numOfVertices)
	{
		totalVertices = numOfVertices;
		vector<int>tempList = vector<int>(numOfVertices, INT_MAX);
		adjList = vector<vector<int>>(numOfVertices, tempList);
	}
	void addEdge(int u, int v, int w)
	{
		adjList[u][v] = w;
	}
};
void FloydWarshall(Graph g)
{
	vector<vector<int>>mat = g.adjList;

	for (int u = 0; u < g.totalVertices; u++)
	{
		for (int i = 0; i < g.totalVertices; i++)
		{
			if (i == u)
			{
				continue;
			}

			for (int j = 0; j < g.totalVertices; j++)
			{
				if (j == u)
				{
					continue;
				}

				if (mat[i][u] < INT_MAX && mat[u][j] < INT_MAX && mat[i][j] > mat[i][u] + mat[u][j])
				{
					mat[i][j] = mat[i][u] + mat[u][j];
				}
			}
		}
	}


	//print
	for (int i = 0; i < g.totalVertices; i++)
	{
		cout << "\n";

		for (int j = 0; j < g.totalVertices; j++)
		{
			cout << (mat[i][j] == INT_MAX ? -1 : mat[i][j]) << "\t";
		}
	}
}

int main()
{
	Graph g(4);
	g.adjList =
	{
		{ 0,   5,  INT_MAX, 10 },
		{ INT_MAX, 0,   3, INT_MAX },
		{ INT_MAX, INT_MAX, 0,   1 },
		{ INT_MAX, INT_MAX, INT_MAX, 0 }
	};

	FloydWarshall(g);

	return 0;
}

