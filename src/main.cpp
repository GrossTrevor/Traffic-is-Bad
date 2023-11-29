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

	//future work!!!!!!!!!!
	//make vector of county objects, check if county + state is already in heap/hash (using the two get functions to check if the state and county are correct)
	//if not, make new county obj, then add to heap/hash
	//if it is, get obj and add to it


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
		//add to hash
	}


	return 0;
}