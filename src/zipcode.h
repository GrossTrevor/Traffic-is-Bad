#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Zip {
	int zip;
	int severity;
	double visibility;
	string weather;
	bool crossing;
	bool junction;
	bool station;
	bool stop;
	bool signal;
	bool day;

	Zip(int zip, int severity, double visibility, string weather, bool crossing, bool junction, bool station, bool stop, bool signal, bool day);
};