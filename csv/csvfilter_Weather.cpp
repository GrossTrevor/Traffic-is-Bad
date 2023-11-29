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
using std::find;

//this code removes any unwanted data from each car crash 

int main() {
	ifstream infile("US_Accidents_2022.csv");
	ofstream outfile("US_Accidents_2022_Weather.csv");
	string line = ""; 
	string total = "";
	string sum = "";
	vector<string> vect;

	while (!infile.eof()) {
		total = "";
		sum = ""; 

		getline(infile, line, ','); 
		getline(infile, line, ','); 
		getline(infile, line, ','); //severity int 
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
		getline(infile, line, ','); //state
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
		getline(infile, line, ','); //wind direction
		getline(infile, line, ','); //wind speed
		getline(infile, line, ','); //precipitation
		getline(infile, line, ','); // weather condition
		//outfile << line << endl; 
		if (find(vect.begin(), vect.end(), line) == vect.end()) {
			outfile << line << endl; 
			vect.push_back(line);
		}
		getline(infile, line, ','); //amenity
		getline(infile, line, ','); //bump
		getline(infile, line, ','); //crossing 
		getline(infile, line, ','); // give way
		getline(infile, line, ','); //junction
		getline(infile, line, ','); //no exit 
		getline(infile, line, ','); //roundabout 
		getline(infile, line, ','); //station
		getline(infile, line, ','); //stop
		getline(infile, line, ','); //traffic state
		getline(infile, line, ','); //traffic signal
		getline(infile, line, ','); //turning loop
		getline(infile, line, ','); //sunrise/sunset
		getline(infile, line); //civil twilight, nautical twilight, astronomical twilight
	}


	return 0;
}