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

	void AddCounty(string state, County county, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time); //add county to a state, state already exists   
	void EditCounty(County county, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time);


	bool CheckState(string state);  //check if state already exists  
	bool CheckCounty(string state, County county); //check if county already exists 
};