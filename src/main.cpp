#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "county.h"
#include "state.h"
#include "AdjList.h"
#include "heap.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

int main() {
	//choose which data structure to use 
	//AdjList adj_list;
	MaxHeap heap;

	ifstream infile("../csv/US_Accidents_2022_Data.csv");
	vector<string> info;
	string line = "";

	while (!infile.eof()) {
		getline(infile, line, ',');
		info.push_back(line);			//severity = 0
		getline(infile, line, ',');
		info.push_back(line);			//county = 1
		getline(infile, line, ',');
		info.push_back(line);			//state = 2
		getline(infile, line, ',');
		info.push_back(line);			//visibility = 3
		getline(infile, line, ',');
		info.push_back(line);			//weather = 4
		getline(infile, line, ',');
		info.push_back(line);			//crossing = 5
		getline(infile, line, ',');
		info.push_back(line);			//junction = 6
		getline(infile, line, ',');
		info.push_back(line);			//stop = 7
		getline(infile, line, ',');
		info.push_back(line);			//traffic signal = 8
		getline(infile, line);
		info.push_back(line);			//sunrise/sunset = 9


		//add to heap
		heap.Insert(info[1], info[2], info[0], info[3], info[4], info[5], info[6], info[7], info[8], info[9]); 

		//add to adj list
		//adj_list.AddCounty(info[2], info[1], info[0], info[3], info[4], info[5], info[6], info[7], info[8], info[9]);


		info.clear();
	}

	/*
	//MAKE JS FILE FROM ADJACENCY LIST
	ifstream county_data("../api/Traffic is Bad/county_dataPre.js");
	ofstream county_data2("../api/Traffic is Bad/county_data.js");
	string line2 = "";
	string county = "";
	string state = "";
	County county_obj;

	while (!county_data.eof()) {
		getline(county_data, line2);
		if (line2.length() > 14 && line2.substr(9, 6) == "COUNTY") {
			county = line2.substr(19, line2.length() - 1 - 20);
			county_data2 << line2 << endl;
		}
		if (line2.length() > 14 && line2.substr(9, 5) == "STATE") {
			state = line2.substr(18, line2.length() - 1 - 19);
			county_data2 << line2 << endl;
			if (!adj_list.CheckCounty(state, county)) {
				county_obj = adj_list.GetCountyObj(state, county);
				county_data2 << "        \"SEVERITY\": \"" << to_string(county_obj.GetAvgSeverity()) << "\"," << endl;
				county_data2 << "        \"CROSSING\": \"" << to_string(county_obj.GetCrossing()) << "\"," << endl;
				county_data2 << "        \"DAY\": \"" << to_string(county_obj.GetDay()) << "\"," << endl;
				county_data2 << "        \"JUNCTION\": \"" << to_string(county_obj.GetJunction()) << "\"," << endl;
				county_data2 << "        \"NIGHT\": \"" << to_string(county_obj.GetNight()) << "\"," << endl;
				county_data2 << "        \"POOR_VISIBILITY\": \"" << to_string(county_obj.GetAvgVisibility()) << "\"," << endl;
				county_data2 << "        \"SIGNAL\": \"" << to_string(county_obj.GetSignal()) << "\"," << endl;
				county_data2 << "        \"STOP\": \"" << to_string(county_obj.GetStop()) << "\"," << endl;
				county_data2 << "        \"WFAIR\": \"" << to_string(county_obj.GetWeather("Fair")) << "\"," << endl;
				county_data2 << "        \"WCLOUDY\": \"" << to_string(county_obj.GetWeather("Cloudy")) << "\"," << endl;
				county_data2 << "        \"WFOG\": \"" << to_string(county_obj.GetWeather("Fog")) << "\"," << endl;
				county_data2 << "        \"WRAIN\": \"" << to_string(county_obj.GetWeather("Rain")) << "\"," << endl;
				county_data2 << "        \"WSNOW\": \"" << to_string(county_obj.GetWeather("Snow")) << "\"" << endl;

				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
			}
			else {
				county_data2 << "        \"SEVERITY\": \"0\"," << endl;
				county_data2 << "        \"CROSSING\": \"0\"," << endl;
				county_data2 << "        \"DAY\": \"0\"," << endl;
				county_data2 << "        \"JUNCTION\": \"0\"," << endl;
				county_data2 << "        \"NIGHT\": \"0\"," << endl;
				county_data2 << "        \"POOR_VISIBILITY\": \"0\"," << endl;
				county_data2 << "        \"SIGNAL\": \"0\"," << endl;
				county_data2 << "        \"STOP\": \"0\"," << endl;
				county_data2 << "        \"WFAIR\": \"0\"," << endl;
				county_data2 << "        \"WCLOUDY\": \"0\"," << endl;
				county_data2 << "        \"WFOG\": \"0\"," << endl;
				county_data2 << "        \"WRAIN\": \"0\"," << endl;
				county_data2 << "        \"WSNOW\": \"0\"" << endl;

				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
				getline(county_data, line2);
			}
		}
		else if (line2.length() < 18 || (line2.length() > 14 && !(line2.substr(9, 6) == "COUNTY" || line2.substr(9, 8) == "SEVERITY" || line2.substr(9, 8) == "CROSSING" || line2.substr(9, 3) == "DAY" || line2.substr(9, 8) == "JUNCTION" || line2.substr(9, 5) == "NIGHT" || line2.substr(9, 15) == "POOR_VISIBILITY" || line2.substr(9, 6) == "SIGNAL" || line2.substr(9, 4) == "STOP" || line2.substr(9, 5) == "WFAIR" || line2.substr(9, 7) == "WCLOUDY" || line2.substr(9, 4) == "WFOG" || line2.substr(9, 5) == "WRAIN" || line2.substr(9, 5) == "WSNOW")))
			county_data2 << line2 << endl;
	}
	*/

	//MAKE JS FILE FROM MAX HEAP
	ifstream county_data("../api/Traffic is Bad/county_dataPre.js");
	ofstream county_data2("../api/Traffic is Bad/county_dataHeap.js");
	string line2 = "";
	string county = "";
	string state = "";
	string tempout = "";
	County county_obj;
	State state_obj;
	vector<pair<string, string>> state_county;
	bool isFirst = true;
	bool addXtra = false;

	getline(county_data, line2);
	county_data2 << line2 << endl;
	getline(county_data, line2);
	county_data2 << line2 << endl;
	getline(county_data, line2);
	county_data2 << line2 << endl;

	while (!heap.EmptyHeap()) {
		state_obj = heap.ExtractMax();
		while (!county_data.eof()) {
			for (int j = 0; j < state_obj.GetNumCounties(); j++) {
				getline(county_data, line2);
				if (line2.length() > 14 && line2.substr(9, 6) == "COUNTY") {
					county = line2.substr(19, line2.length() - 1 - 20);
					tempout += line2 + '\n';
				}
				if (line2.length() > 14 && line2.substr(9, 5) == "STATE") {
					state = line2.substr(18, line2.length() - 1 - 19);
					tempout += line2 + '\n';
					if ((state == state_obj.GetName()) && !(heap.SearchCounty(county, state))) {
						county_obj = state_obj.FindCounty(county);
						if (isFirst) {
							tempout.erase(0, tempout.find('\n') + 1);
							tempout.erase(0, tempout.find('\n') + 1);
							tempout.erase(0, tempout.find('\n') + 1);
							isFirst = false;
						}
						if (state == "CA" && county == "San Francisco") {
							tempout.erase(0, tempout.find('\n') + 1);
							tempout.erase(0, tempout.find('\n') + 1);
							tempout.erase(0, tempout.find('\n') + 1);
						}
						if (state == "IL" && county == "Pulaski")
							addXtra = true;
						county_data2 << tempout;
						tempout = "";
						if(to_string(county_obj.GetAvgSeverity()) == "nan")
							county_data2 << "        \"SEVERITY\": \"0\"," << endl;
						else
							county_data2 << "        \"SEVERITY\": \"" << to_string(county_obj.GetAvgSeverity()) << "\"," << endl;
						county_data2 << "        \"CROSSING\": \"" << to_string(county_obj.GetCrossing()) << "\"," << endl;
						county_data2 << "        \"DAY\": \"" << to_string(county_obj.GetDay()) << "\"," << endl;
						county_data2 << "        \"JUNCTION\": \"" << to_string(county_obj.GetJunction()) << "\"," << endl;
						county_data2 << "        \"NIGHT\": \"" << to_string(county_obj.GetNight()) << "\"," << endl;
						if (to_string(county_obj.GetAvgVisibility()) == "nan")
							county_data2 << "        \"POOR_VISIBILITY\": \"0\"," << endl;
						else
							county_data2 << "        \"POOR_VISIBILITY\": \"" << to_string(county_obj.GetAvgVisibility()) << "\"," << endl;
						county_data2 << "        \"SIGNAL\": \"" << to_string(county_obj.GetSignal()) << "\"," << endl;
						county_data2 << "        \"STOP\": \"" << to_string(county_obj.GetStop()) << "\"," << endl;
						county_data2 << "        \"WFAIR\": \"" << to_string(county_obj.GetWeather("Fair")) << "\"," << endl;
						county_data2 << "        \"WCLOUDY\": \"" << to_string(county_obj.GetWeather("Cloudy")) << "\"," << endl;
						county_data2 << "        \"WFOG\": \"" << to_string(county_obj.GetWeather("Fog")) << "\"," << endl;
						county_data2 << "        \"WRAIN\": \"" << to_string(county_obj.GetWeather("Rain")) << "\"," << endl;
						county_data2 << "        \"WSNOW\": \"" << to_string(county_obj.GetWeather("Snow")) << "\"" << endl;

						if (addXtra) {
							county_data2 << "      },\n      \"type\": \"Feature\"\n    },\n";
							addXtra = false;
						}

						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
					}
					else if ((state == state_obj.GetName()) || ((find(state_county.begin(), state_county.end(), make_pair(county, state)) == state_county.end()) && ((state == "AK") || (state == "HI") || (state == "PR")))) {
						state_county.push_back(make_pair(county, state));
						if (isFirst) {
							tempout.erase(0, tempout.find('\n') + 1);
							tempout.erase(0, tempout.find('\n') + 1);
							tempout.erase(0, tempout.find('\n') + 1);
							isFirst = false;
						}
						county_data2 << tempout;
						tempout = "";
						county_data2 << "        \"SEVERITY\": \"0\"," << endl;
						county_data2 << "        \"CROSSING\": \"0\"," << endl;
						county_data2 << "        \"DAY\": \"0\"," << endl;
						county_data2 << "        \"JUNCTION\": \"0\"," << endl;
						county_data2 << "        \"NIGHT\": \"0\"," << endl;
						county_data2 << "        \"POOR_VISIBILITY\": \"0\"," << endl;
						county_data2 << "        \"SIGNAL\": \"0\"," << endl;
						county_data2 << "        \"STOP\": \"0\"," << endl;
						county_data2 << "        \"WFAIR\": \"0\"," << endl;
						county_data2 << "        \"WCLOUDY\": \"0\"," << endl;
						county_data2 << "        \"WFOG\": \"0\"," << endl;
						county_data2 << "        \"WRAIN\": \"0\"," << endl;
						county_data2 << "        \"WSNOW\": \"0\"" << endl;

						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
						getline(county_data, line2);
					}
					tempout = "";
				}
				else if (line2.length() < 18 || (line2.length() > 14 && !(line2.substr(9, 6) == "COUNTY" || line2.substr(9, 8) == "SEVERITY" || line2.substr(9, 8) == "CROSSING" || line2.substr(9, 3) == "DAY" || line2.substr(9, 8) == "JUNCTION" || line2.substr(9, 5) == "NIGHT" || line2.substr(9, 15) == "POOR_VISIBILITY" || line2.substr(9, 6) == "SIGNAL" || line2.substr(9, 4) == "STOP" || line2.substr(9, 5) == "WFAIR" || line2.substr(9, 7) == "WCLOUDY" || line2.substr(9, 4) == "WFOG" || line2.substr(9, 5) == "WRAIN" || line2.substr(9, 5) == "WSNOW")))
					tempout += line2 + '\n';
			}
		}
		tempout = "";
		county_data.clear();
		county_data.seekg(0);
	}
	county_data2 << "      },\n		\"type\": \"Feature\"\n    }\n  ],\n};\n";

	return 0;
}