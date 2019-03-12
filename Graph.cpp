// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

// Node of adjacent list
struct vertex
{
	int key;
	int weight;
	vertex* next;

	vertex(int _key, int _weight)
	{
		key = _key;
		weight = _weight;
		next = NULL;
	}
};

struct Graph
{
	int totalVertices;
	vector<vertex*> adjList;

	Graph(int _totalVertices)
	{
		totalVertices = _totalVertices;
		adjList = vector<vertex*>(totalVertices, NULL);
	}

	void addEdge(int u, int v, int w)
	{
		// Undirected graph.
		//Edge(u,v) and weight w
		addEdgeHelper(u, v, w);
		addEdgeHelper(v, u, w);
	}

	void addEdgeHelper(int u, int v, int w)
	{
		vertex* _vertex = new vertex(v, w);
		vertex* head = adjList[u];

		if (head)
		{
			while (head->next)
			{
				head = head->next;
			}

			head->next = _vertex;
		}
		else
		{
			adjList[u] = _vertex;
		}
	}
};

// Node used in priority queue
struct QueueNode
{
	int key;
	int distance;
	QueueNode(int _v, int d)
	{
		key = _v;
		distance = d;
	}
};

// Comparison function to use in Priority Queue
struct comparison
{
	bool operator()(QueueNode* v1, QueueNode* v2)
	{
		return v1->distance >= v2->distance;
	}
};

void dijkstra(int s, Graph* g)
{
	vector<int>distance(g->totalVertices, INT_MAX); // Hold the distance of each vertex from source vertex.
	vector<int>previous(g->totalVertices, -1); // hold the previous vertex of a vertex along the path.
	vector<bool>visited(g->totalVertices, false);

	previous[s] = -1;

	priority_queue<QueueNode*, vector<QueueNode*>, comparison>pq;
	QueueNode* qNode = new QueueNode(s, 0); // source node distance is zero.
	pq.push(qNode);

	while (!pq.empty())
	{
		QueueNode* qNode = pq.top();
		pq.pop();
		int u = qNode->key;

		if (visited[u])
		{
			delete qNode;
			continue;
		}

		distance[u] = qNode->distance;
		delete qNode;
		visited[u] = true;

		// Relax all adjacent node
		vertex* head = g->adjList[u];

		while (head)
		{
			int v = head->key;
			int weight = head->weight;

			head = head->next;

			if (visited[v])
			{
				continue;
			}

			if (distance[v] > distance[u] + weight)
			{
				previous[v] = u;
				distance[v] = distance[u] + weight;
				QueueNode* qNode = new QueueNode(v, distance[v]);
				pq.push(qNode);
			}
		}
	}

	// Print
	cout << "Vertex" << "\t" << "Distance" << "\t" << "Previous Vertex" << "\n";

	for (int i = 0; i < g->totalVertices; i++)
	{
		cout << i << "\t \t" << distance[i] << "\t \t" << previous[i] << "\n";
	}

}
int main()
{
	Graph* g = new Graph(9);
	g->addEdge(0, 1, 4);
	g->addEdge(0, 7, 8);
	g->addEdge(1, 2, 8);
	g->addEdge(1, 7, 11);
	g->addEdge(2, 3, 7);
	g->addEdge(2, 8, 2);
	g->addEdge(2, 5, 4);
	g->addEdge(3, 4, 9);
	g->addEdge(3, 5, 14);
	g->addEdge(4, 5, 10);
	g->addEdge(5, 6, 2);
	g->addEdge(6, 7, 1);
	g->addEdge(6, 8, 6);
	g->addEdge(7, 8, 7);
	dijkstra(0, g);



	return 0;
}

