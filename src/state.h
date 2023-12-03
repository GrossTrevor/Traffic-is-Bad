#pragma once
#include <string>
#include <vector>
#include <map>
#include "county.h"

using std::vector; 
using std::string; 

class State {
	string name;
	double total_severity_counties;
	vector<County> counites;

public:
	State();
	~State();

	void AddTotalSeverity(double severity);
	double GetAvgSeverity();
	void AddCounty(County county); 

	bool IsCountyHere(string county);
	County FindCounty(string county); 
	void SetName(string state);
	void GetName(); 
};
