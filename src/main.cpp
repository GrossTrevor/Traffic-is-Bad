#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "../api/Traffic is Bad/json.hpp"
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

using json = nlohmann::json;
using json::parse;


int main() {
	//AdjList adj_list;

	MaxHeap heap;

	ifstream infile("../csv/US_Accidents_2022_Data.csv"); 
	vector<string> info;
	string line = "";

	string t;
	string c;
	int x = 80000;

	while (!infile.eof() && x != 0) {
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

		/*cout << heap.GetState(info[2]).GetName() << ": " << endl;
		heap.GetState(info[2]).PrintCounties();
		cout << endl;*/
		
		//add to adj list
		//adj_list.AddCounty(info[2], info[1], info[0], info[3], info[4], info[5], info[6], info[7], info[8], info[9]); 


		info.clear();
		x--;
	}

	//cout << "here" << endl;

	//adj_list.PrintTesting(); 

	heap.PrintStates();


	//make json
	ifstream county_data("../api/Traffic is Bad/county_data.json");
	json county_json;
	string obj = "";
	string line2 = "";
	string county = "";
	string state = "";
	County county_obj;

	getline(county_data, line2);
	getline(county_data, line2);
	getline(county_data, line2);

	while (!county_data.eof()) {
		getline(county_data, line2);
		if (line2 == "{") {
			json json_obj = json::parse(obj);
			county = json_obj["COUNTY"];
			state = json_obj["STATE"];
			if (!adj_list.CheckCounty(state, county)) {
				county_obj = adj_list.GetCountyObj(state, county);
				json_obj["SEVERITY"] = to_string(county_obj.GetAvgSeverity());
				json_obj["WFAIR"] = to_string(county_obj.GetWeather("Fair"));
				json_obj["WCLOUDY"] = to_string(county_obj.GetWeather("Cloudy"));
				json_obj["WFOG"] = to_string(county_obj.GetWeather("Fog"));
				json_obj["WRAIN"] = to_string(county_obj.GetWeather("Rain"));
				json_obj["WSNOW"] = to_string(county_obj.GetWeather("Snow"));
				json_obj["CROSSING"] = to_string(county_obj.GetCrossing());
				json_obj["JUNCTION"] = to_string(county_obj.GetJunction());
				json_obj["STOP"] = to_string(county_obj.GetStop());
				json_obj["SIGNAL"] = to_string(county_obj.GetSignal());
				json_obj["DAY"] = to_string(county_obj.GetDay());
				json_obj["NIGHT"] = to_string(county_obj.GetNight());
				json_obj["POOR_VISIBILITY"] = to_string(county_obj.GetAvgVisibility());
			}
			else {
				json_obj["SEVERITY"] = "0";
				json_obj["WFAIR"] = "0";
				json_obj["WCLOUDY"] = "0";
				json_obj["WFOG"] = "0";
				json_obj["WRAIN"] = "0";
				json_obj["WSNOW"] = "0";
				json_obj["CROSSING"] = "0";
				json_obj["JUNCTION"] = "0";
				json_obj["STOP"] = "0";
				json_obj["SIGNAL"] = "0";
				json_obj["DAY"] = "0";
				json_obj["NIGHT"] = "0";
				json_obj["POOR_VISIBILITY"] = "0";
			}
		}
		else
			obj += line2;
	}

	return 0;
}