#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <typeinfo>

using std::string;
using std::vector;
using std::pair;
using std::map;
using std::make_pair;
using std::stod;
using std::to_string;
using std::cout;
using std::endl;

class County {
	string county;
	string state;
	pair<string, string> cost;
	double total_severity;
	vector<double> visibility;
	map<string, int> weather;
	int crossing;
	int junction;
	int stop;
	int signal;
	int day;
	int night;
	double total_crashes;

public:
	County();
	void ChangeWeather(string w_state);
	void AddVisibility(string visible);
	void AddDayOrNight(string time);
	void AddCrossing(string line);
	void AddJunction(string line);
	void AddStop(string line);
	void AddSignal(string line);
	void AddSeverity(string s);
	void AddCountyAndState(string county, string state);
	void AddToTotalCrashes(); 

	string GetCounty();
	string GetState();

	double GetAvgSeverity();
	double GetAvgVisibility();
	int GetWeather(string w_cond);
	int GetCrossing();
	int GetJunction();
	int GetStop();
	int GetSignal();
	int GetDay();
	int GetNight();
	int GetTotalCrashes();
};
