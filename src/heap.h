#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "county.h"
#include "state.h" 

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stoi;
using std::swap; 

class MaxHeap
{
	vector<State> stateVect;
	void HeapifyUp(int index);
	void HeapifyDown(int index);
public:
	MaxHeap();
	~MaxHeap();
	int GetHeapSize();
	bool EmptyHeap();
	bool SearchCounty(string county, string state);
	bool SearchState(string state);
	//County GetCounty(string county, string state);
	State GetState(string state); 
	County GetCountyObj(string county_, string state, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time); 
	void EditCounty(County county, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time); 
	void Insert(string county_, string state, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time);  
	void PrintStates();
	//void Remove();
};