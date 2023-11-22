#pragma once
#include <string>
#include <vector>
#include <map>
#include <county.hpp>

using std::string;
using std::vector;
using std::pair;

struct County {
	string county;
	string state;
	pair<string, string> cost;
	int severity;
	double visibility;
	string weather;
	bool crossing;
	bool junction;
	bool station;
	bool stop;
	bool signal;
	bool day;

	County(string county, string state, int severity, vector<double> visibility, map<string, int> weather, int crossing, int junction, int station, int stop, int signal, int day, int night);
	//int = count the number of crashes that are present in crossings, junctions, stations, stops, signals
	//day or night == amount of crashes that happen during the day/night
	//vector a visibility to get to average for each county 
	//map of weather = counts the amount of each weather pattern present during each crash 
};