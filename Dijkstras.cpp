// Dijkstras.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <string>
#include <list>

using namespace std;
struct vertex
{
	int v;
	int w;

	vertex(int _v, int _w)
	{
		v = _v;
		w = _w;
	}
};
struct comparison
{
	bool operator()(vertex& p1, vertex& p2)
	{
		return p1.w > p2.w;
	}
};
struct node
{
	int vertex;
	int distance;
	node* next;
	node()
	{
		vertex = 0;
		distance = 0;
		next = NULL;
	};
	node(int v, int d)
	{
		vertex = v;
		distance = d;
		next = NULL;
	}
};
class graph
{
	int numVertex;
	vector<edge>* adjList;
public:
	graph(int num)
	{
		numVertex = num;
		adjList = new list<edge>(num);
	};

	void addEdge(int u, int v, int dist)
	{
		edge e = edge(v, dist);
		adjList[u].push_front(e);
	}
	int getNumberOfVertex()
	{
		return numVertex;
	}
	void printGraph()
	{
		for (int i = 0; i < numVertex; i++)
		{
			cout << i << "=>:";

			for (auto v : adjList[i])
			{
				cout << v.vertex << " " << v.distance;
			}

			cout << "\n";
		}
	}
	void dijkstra(int s);
};

void graph::dijkstra(int s)
{
	/*
	vector<bool>visited;
	vector<int>weight;

	for (int i = 0; i < numVertex; i++)
	{
		visited[i] = false;
		weight[i] = INT_MAX;
	}

	weight[s] = 0;
	vertex v(s, 0);
	priority_queue<vertex>pq;
	pq.push(v);

	while (!pq.empty())
	{
		vertex u = pq.top();
		pq.pop();

		if (visited[u.v])
		{
			continue;
		}

		visited[u.v] = true;
		vector<edge>* i;
	}*/
}
int main()
{
	graph* g = new graph(4);
	g->addEdge(0, 1, 5);
	g->addEdge(1, 2, 10);
	g->addEdge(0, 2, 3);
	g->addEdge(1, 3, 2);
	g->addEdge(2, 3, 1);

	g->printGraph();
	return 0;
}

