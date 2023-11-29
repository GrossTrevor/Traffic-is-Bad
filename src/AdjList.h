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

	void AddState(string state, County county);  //add state to the list  
	void AddCounty(string state, County county); //add county to a state, state already exists  


	bool CheckState(string state);  //check if state already exists  
	bool CheckCounty(string state, string county); //check if county already exists 
};