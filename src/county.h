#pragma once
#include <string>
#include <vector>
#include <map>
#include <county.hpp>

using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::stod;

class County {
	string county;
	string state;
	pair<string, string> cost;
	int severity;
	vector<double> visibility;
	map<string, int> weather;
	int crossing;
	int junction;
	int stop;
	int signal;
	int day;
	int night;
	int total_crashes;

private:
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

	//int = count the number of crashes that are present in crossings, junctions, stations, stops, signals
	//day or night == amount of crashes that happen during the day/night
	//vector a visibility to get to average for each county 
	//map of weather = counts the amount of each weather pattern present during each crash 
};