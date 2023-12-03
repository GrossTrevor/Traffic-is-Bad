#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "county.h"

using std::vector; 
using std::string; 
using std::stod; 
using std::cout;
using std::endl;

class State {
	string name;
	double total_severity_counties;
	vector<County> counties;

public:
	State();
	~State();

	void AddTotalSeverity(string severity, string county);
	double GetAvSeverity();
	void AddCounty(County county); 
	void SetName(string state);

	bool IsCountyHere(string county);
	County FindCounty(string county); 
	string GetName(); 
	int GetNumCounties();
	vector<County> GetCountyVect()
	void PrintCounties();
};
