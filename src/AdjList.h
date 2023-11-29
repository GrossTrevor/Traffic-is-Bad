#pragma once
#include <map>
#include <vector>
#include <iomanip> 
#include <algorithm> 
#include "county.h"

using std::map;
using std::vector; 
using std::string;


class AdjList {
	map<string, vector<County>> states_to_county;
public:
	AdjList();
	~AdjList();

	void AddState();  //add state to the list 
	void AddCounty(); //add county to a state 


	bool CheckState();  //check if state already exists 
	bool CheckCounty(); //check if county already exists 
};