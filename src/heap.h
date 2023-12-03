#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "county.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stoi;

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
	bool Search(string county, string state);
	County GetCounty(string county, string state);
	County GetCountyObj(string county_, string state, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time); 
	void EditCounty(County county, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time); 
	void Insert(string county_, string state, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time);  
	void Remove();
};