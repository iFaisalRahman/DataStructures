// LRU.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;
class LRU
{
	int capacity;
	int size;
	list<pair<int, int>>dList; // Doubly link list data::(Key,Val)
	unordered_map<int, list<pair<int, int>>::iterator>map; // Hash map data::(Key,Val)

public:
	LRU(int _capacity)
	{
		size = 0;
		capacity = _capacity;
	}
	int get(int key);
	void put(int key, int value);
};

int LRU::get(int key)
{
	//Find Key in Hash Table
	//If Key not exist then return -1
	//IF key exist, then return the associated value from the Cache
	// And reorder the cache.

	if (map.find(key) == map.end())
	{
		return -1; // Page faults.
	}

	list<pair<int, int>>::iterator it = map[key];

	pair<int, int> node = *it;
	int value = node.second;

	dList.erase(it);
	dList.push_front(node);
	map[key] = dList.begin();

	return value;
}

void LRU::put(int key, int val)
{
	// Find key is already exists there or not.
	// If key exist  there, then just update the item and reorder it.
	// If key not exist there, then check if there is enough capacity or not.
	// If there is no capacity then remove the last item and reorder the new item.

	if (map.find(key) != map.end())
	{
		list<pair<int, int>>::iterator it = map[key];
		pair<int, int>node(key, val);
		dList.erase(it);
		dList.push_front(node);
		map[key] = dList.begin();
	}
	else
	{
		if (size == capacity)
		{
			pair<int, int> last = dList.back();
			int lastKey = last.first;
			dList.pop_back();
			map.erase(lastKey);
		}

		pair<int, int> newNode(key, val);
		dList.push_front(newNode);
		map[key] = dList.begin();

		if (size < capacity)
		{
			size++;
		}
	}
}
int main()
{
	//1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5

	LRU* lru = new LRU(4);
	lru->put(1, 10);
	lru->put(2, 20);
	lru->get(2);
	lru->put(3, 30);
	lru->put(4, 40);
	lru->get(1);
	lru->get(5);
	lru->put(5, 50);
	lru->put(6, 60);
	return 0;
}

