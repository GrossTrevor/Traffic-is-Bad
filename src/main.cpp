#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "county.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream; 


int main() {

	//Adding to the structure guide/plan:
	// make seperate variables for each line OR make a vector and call each item that way 
	//get state and county names
	//search through either structure to see if county is already in with the specific state 
	//if state not in the sturcture, add the state with the county
	//if the county is not in the state but the state already exists, add the county to the state 
	//if the county already exists, edit the counts of the county with the new data given


	ifstream infile("US_Accidents_2022_Data.csv"); 
	string line = "";
	string state = "";
	string severity = "";
	string county = "";


	//right now, making obj for every crash -> not wanted, no way of knowing county is already created 
	while (!infile.eof()) {
		County c_obj;

		getline(infile, severity, ','); 
		c_obj.AddSeverity(severity);  
		getline(infile, county, ',');  
		getline(infile, state, ',');  
		c_obj.AddCountyAndState(county, state); 

		//search through data structures here, edit or add to county 
		//use state and county strings to search 

		getline(infile, line, ',');
		c_obj.AddVisibility(line); 
		getline(infile, line, ',');
		c_obj.ChangeWeather(line);
		getline(infile, line, ',');
		c_obj.AddCrossing(line);
		getline(infile, line, ','); 
		c_obj.AddJunction(line);
		getline(infile, line, ','); 
		c_obj.AddStop(line);
		getline(infile, line, ','); 
		c_obj.AddSignal(line);
		getline(infile, line);
		c_obj.AddDayOrNight(line);

		c_obj.AddToTotalCrashes();

		//add to heap
		//add to adjlist
	}


	return 0;
}