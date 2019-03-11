#include<iostream> 
#include<climits> 
using namespace std; 

Class Heap
{
private:
	vector<int>data;
	int size;

public:
	Heap();
	void insert(int v);
	void extractMin();
private:
	int parent(int i){
		return (i-1)>>1;
	}

	int left(int i){
		return 1+(i<<1);
	}
	int right(int i){
		return 2+(i<<1);
	}
	void swap(int i, int j){
		data[i]=data[i]+data[j];
		data[j]=data[i]-data[j];
		data[i]=data[i]-data[j];
	}
	void heapify(int i)
	{
		int left_ind = left(i);
		int right_ind = right(i);
		int lowest=i;
		if(left_ind<size && data[i]>data[left_ind])
		{
			lowest=left_ind;
		}
		if(right_ind<size && data[lowest]>data[right_ind])
		{
			lowest=right_ind;
		}

		if(lowest!=i)
		{
			swap(i,lowest);
			heapify(lowest);
		}
	}
}
Heap:Heap(){
	size=0;
}
Heap::insert(int v)
{
	data[size]=v;
	int i=size;
	size++;
	while(i>0)
	{
		int parent_ind=parent(i);
		if(data[i]>data[parent_ind])
		{
			swap(i,parent_ind);
			i=parent_ind;
		}
	}
}
int Heap::getMin()
{
	return data[0];
}
Heap::extractMin()
{
	swap(0,size-1);
	size--;
	heapify(0);
}