#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

//this code removes any unwanted data from each car crash 

int main() {
	ifstream infile("US_Accidents_2022.csv");
	ofstream outfile("US_Accidents_2022_Data.csv");
	string line = ""; 
	string total = "";
	string sum = "";

	while (!infile.eof()) {
		total = "";
		sum = ""; 

		getline(infile, line, ','); 
		getline(infile, line, ','); 
		getline(infile, line, ','); //severity int 
		sum += line + ","; 
		getline(infile, line, ','); //start time
		getline(infile, line, ','); //end time
		getline(infile, line, ','); //start lat
		getline(infile, line, ','); //start lng
		getline(infile, line, ','); //end lat
		getline(infile, line, ','); //end lng
		getline(infile, line, ','); //distance 
		getline(infile, line, ','); //description 
		getline(infile, line, ','); //street
		getline(infile, line, ','); //city 
		getline(infile, line, ','); //county 
		sum += line + ","; 
		getline(infile, line, ','); //state
		sum += line + ",";
		getline(infile, line, ','); //zip code
		getline(infile, line, ','); //country 
		getline(infile, line, ','); //timezone
		getline(infile, line, ','); //airport code
		getline(infile, line, ','); //weather timestamp
		getline(infile, line, ','); //temp
		getline(infile, line, ','); //wind chill
		getline(infile, line, ','); //humdity
		getline(infile, line, ','); //pressure
		getline(infile, line, ','); // visibility 
		sum += line + ",";
		getline(infile, line, ','); //wind direction
		getline(infile, line, ','); //wind speed
		getline(infile, line, ','); //precipitation
		getline(infile, line, ','); // weather condition
		sum += line + ",";
		getline(infile, line, ','); //amenity
		getline(infile, line, ','); //bump
		getline(infile, line, ','); //crossing 
		sum += line + ",";
		getline(infile, line, ','); // give way
		getline(infile, line, ','); //junction
		sum += line + ",";
		getline(infile, line, ','); //no exit 
		getline(infile, line, ','); //roundabout 
		getline(infile, line, ','); //station
		getline(infile, line, ','); //stop
		sum += line + ",";
		getline(infile, line, ','); //traffic state
		getline(infile, line, ','); //traffic signal
		sum += line + ","; 
		getline(infile, line, ','); //turning loop
		getline(infile, line, ','); //sunrise/sunset
		sum += line; 
		getline(infile, line); //civil twilight, nautical twilight, astronomical twilight

		outfile << sum << endl;
	}


	return 0;
}