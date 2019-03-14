// TopologicalSort.cpp : Defines the entry point for the console application.
//

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

void topologicalsortutil(Graph g, int s, vector<bool>& visited, stack<int>& Stack)
{
	visited[s] = true;
	Node* e = g.adjList[s];

	while (e)
	{
		int v = e->vertex_id;
		e = e->next;

		if (visited[v])
		{
			continue;
		}

		topologicalsortutil(g, v, visited, Stack);
	}

	Stack.push(s);

}
void topologicalsort(Graph g)
{
	vector<bool>visited(g.totalVertices, false);
	stack<int>Stack;

	for (int u = 0; u < g.totalVertices; u++)
	{
		if (!visited[u])
		{
			topologicalsortutil(g, u, visited, Stack);
		}
	}

	//Print
	while (!Stack.empty())
	{
		cout << Stack.top() << "\t";
		Stack.pop();
	}
}
int main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	topologicalsort(g);
	cin.ignore();
	return 0;
}

