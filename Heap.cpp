// Heap.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include <vector>
using namespace std;

class Heap
{
private:
	vector<int>data;
	int size;

public:
	Heap()
	{
		size = 0;
	};
	void insert(int v);
	void extractMin();
	int getMin();
	bool isEmpty()
	{
		return size > 0 ? false : true;
	}
private:
	int parent(int i)
	{
		return (i - 1) >> 1;
	}
	int left(int i)
	{
		return 1 + (i << 1);
	}
	int right(int i)
	{
		return 2 + (i << 1);
	}
	void swap(int i, int j)
	{
		data[i] = data[i] + data[j];
		data[j] = data[i] - data[j];
		data[i] = data[i] - data[j];
	}
	void heapify(int i)
	{
		int left_ind = left(i);
		int right_ind = right(i);
		int lowest = i;

		if (left_ind < size && data[i] > data[left_ind])
		{
			lowest = left_ind;
		}

		if (right_ind < size && data[lowest] > data[right_ind])
		{
			lowest = right_ind;
		}

		if (lowest != i)
		{
			swap(i, lowest);
			heapify(lowest);
		}
	}
};
void Heap::insert(int v)
{
	if (data.size() <= size)
	{
		data.push_back(v);
	}
	else
	{
		data[size] = v;
	}

	int i = size;
	size++;

	while (i > 0)
	{
		int parent_ind = parent(i);

		if (data[i] < data[parent_ind])
		{
			swap(i, parent_ind);
			i = parent_ind;
		}
		else
		{
			break;
		}
	}
}
int Heap::getMin()
{
	return data[0];
}
void Heap::extractMin()
{
	swap(0, size - 1);
	size--;
	heapify(0);
}

int main()
{
	Heap pq = Heap();
	pq.insert(9);
	pq.insert(1);
	pq.insert(5);
	pq.insert(3);
	pq.insert(8);
	pq.insert(6);


	while (!pq.isEmpty())
	{
		cout << pq.getMin() << " ";
		pq.extractMin();
	}

	return 0;
}

