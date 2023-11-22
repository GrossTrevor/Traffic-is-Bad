#pragma once
#include <string>
#include <vector>

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

	County(string county, string state, int severity, double visibility, string weather, bool crossing, bool junction, bool station, bool stop, bool signal, bool day);
};