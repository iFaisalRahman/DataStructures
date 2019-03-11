#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <string>

using namespace std;
struct Person
{
	string key;
	int value;
	Person(string _key, int _value)
	{
		key = _key;
		value = _value;
	}
};

struct comparison
{
	bool operator()(Person& p1, Person& p2)
	{
		return p1.value > p2.value;
	}
};

int main()
{
	priority_queue <Person, vector<Person>, comparison> pq;
	pq.push(Person("Faisal", 10));
	pq.push(Person("Linda", 5));
	pq.push(Person("Rahman", 15));

	while (!pq.empty())
	{
		Person p = pq.top();
		pq.pop();
		cout << p.key << p.value << "\n";
	}

	return 0;
}

