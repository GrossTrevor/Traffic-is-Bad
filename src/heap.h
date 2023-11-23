#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class MaxHeap
{
private:
	vector<County*> countyVect;
	int numCounties;
	void HeapifyUp(int index);
	void HeapifyDown(int index);
public:
	MaxHeap();
	~MaxHeap();
	int GetHeapSize();
	bool EmptyHeap();
	void Insert(County* newCounty);
	void Remove();
};