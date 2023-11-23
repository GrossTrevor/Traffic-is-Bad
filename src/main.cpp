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
	ifstream infile("US_Accidents_2022_Data.csv"); 
	string line = "";
	string state = "";

	while (!infile.eof()) {
		County c_obj;

		getline(infile, line, ','); 
		c_obj.AddSeverity(line);  
		getline(infile, line, ',');  
		getline(infile, state, ',');  
		c_obj.AddCountyAndState(line, state); 
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