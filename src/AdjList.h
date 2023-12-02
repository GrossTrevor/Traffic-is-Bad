#pragma once
#include <map>
#include <vector>
#include <iomanip> 
#include <algorithm> 
#include "county.h"
#include "AdjList.hpp"

using std::map;
using std::vector; 
using std::string;


class AdjList {
	map<string, vector<County>> state_to_county;
	string test;
public:
	AdjList();
	~AdjList();

	County GetCountyObj(string state, string county); 
	void AddCounty(string state, string county, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time); //add county to a state, state already exists   
	void EditCounty(County county, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time);


	bool CheckState(string state);  //check if state already exists  
	bool CheckCounty(string state, string county); //check if county already exists 
};