// Bellman-FordAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
struct Node
{
	int vertex_id;
	int weight;
	Node* next;
	Node(int _vertex_id, int _weight)
	{
		vertex_id = _vertex_id;
		weight = _weight;
		next = NULL;
	}
};
struct Graph
{
	int totalVertices;
	vector<Node*>adjList;

public:
	Graph() = default;
	Graph(int _totalVertices);
	void addEdge(int u, int v, int w);
	virtual ~Graph() = default;
};

Graph::Graph(int _totalVertices)
{
	totalVertices = _totalVertices;
	adjList = vector<Node*>(totalVertices, NULL);

}
void Graph::addEdge(int u, int v, int w = 0)
{
	if (u >= totalVertices || v >= totalVertices || u < 0 || v < 0)
	{
		return;
	}

	Node* newnode = new Node(v, w);
	Node* head = adjList[u];

	if (!head)
	{
		adjList[u] = newnode;
	}
	else
	{
		while (head->next)
		{
			head = head->next;
		}

		head->next = newnode;
	}
}

void bellmanfordshortestpath(Graph g, int s)
{
	vector<int>distance(g.totalVertices, INT_MAX);

	distance[s] = 0;

	for (int i = 0; i < g.totalVertices - 1; i++)
	{
		for (int u = 0; u < g.totalVertices; u++)
		{
			Node* e = g.adjList[u];

			while (e)
			{
				int v = e->vertex_id;

				if (distance[v] > distance[u] + e->weight)
				{
					distance[v] = distance[u] + e->weight;
				}

				e = e->next;
			}
		}
	}

	//Cycle detection
	for (int u = 0; u < g.totalVertices; u++)
	{
		Node* e = g.adjList[u];

		while (e)
		{
			int v = e->vertex_id;

			if (distance[v] > distance[u] + e->weight)
			{
				cout << "Cycle detected";
				return; // Cycle detected;
			}

			e = e->next;
		}
	}

	// print
	for (int i = 0; i < g.totalVertices; i++)
	{
		cout << distance[i] << "\t";
	}
}
int main()
{
	Graph g(9);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	bellmanfordshortestpath(g, 0);
	return 0;
}

