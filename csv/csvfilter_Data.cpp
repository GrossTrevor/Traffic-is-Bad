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
	string county = "";
	string state = "";

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
		county = line;
		//sum += line + ","; 
		getline(infile, line, ','); //state
		state = line;
		//sum += line + ",";

		if (county == "District Of Columbia") {
			county = "District of Columbia";
		}
		else if (state == "MD" && county == "Baltimore City") {
			county = "Baltimore (City)";
		}
		else if (state == "MD" && county == "Baltimore County") {
			county = "Baltimore";
		}
		else if (state == "MO" & county == "St. Louis City") {
			county = "St. Louis (City)";
		}
		else if (state == "MO" & county == "St. Louis County") {
			county = "St. Louis";
		}
		else if (state == "NV" && county == "Carson City") {
			county = "Carsin City (City)";
		}
		else if (state == "VA") {
			if (county == "Richmond City") {
				county = "Richmond (City)";
			}
			else if (county == "Richmond County") {
				county = "Richmond";
			}
			else if (county == "Alexandria") {
				county = "Alexandria (City)";
			}
			else if (county == "Alexandria City") {
				county = "Alexandria (City)";
			}
			else if (county == "Chesapeake") {
				county = "Chesapeake (City)";
			}
			else if (county == "Norfolk") {
				county = "Norfolk (City)";
			}
			else if (county == "Hampton") {
				county = "Hampton (City)";
			}
			else if (county == "Fredericksburg") {
				county = "Fredericksburg (City)";
			}
			else if (county == "Fairfax City") {
				county = "Fairfax (City)";
			}
			else if (county == "Fairfax County") {
				county = "Fairfax";
			}
			else if (county == "Franklin County") {
				county = "Franklin";
			}
			else if (county == "Bedford County") {
				county = "Bedford";
			}
			else if (county == "Roanoke City") {
				county = "Roanoke (City)";
			}
			else if (county == "Roanoke County") {
				county = "Roanoke";
			}
			else if (county == "Manassas") {
				county = "Manassas (City)";
			}
			else if (county == "Manassas Park") {
				county = "Manassas Park (City)";
			}
			else if (county == "Newport News") {
				county = "Newport News (City)";
			}
			else if (county == "Virginia Beach") {
				county = "Virginia Beach (City)";
			}
			else if (county == "Harrisonburg") {
				county = "Harrisonburg (City)";
			}
			else if (county == "Colonial Heights") {
				county = "Colonial Heights (City)";
			}
			else if (county == "Petersburg") {
				county = "Petersburg (City)";
			}
			else if (county == "Waynesboro") {
				county = "Waynesboro (City)";
			}
			else if (county == "Suffolk") {
				county = "Suffolk (City)";
			}
			else if (county == "Lynchburg") {
				county = "Lynchburg (City)";
			}
			else if (county == "Emporia") {
				county = "Emporia (City)";
			}
			else if (county == "Bristol") {
				county = "Bristol (City)";
			}
			else if (county == "Staunton"){
				county = "Staunton (City)";
			}
			else if (county == "Charlottesville") {
				county = "Charlottesville (City)";
			}
			else if (county == "Hopewell") {
				county = "Hopewell (City)";
			}
			else if (county == "Covington") {
				county = "Covington (City)";
			}
			else if (county == "Winchester") {
				county = "Winchester (City)";
			}
			else if (county == "Williamsburg") {
				county = "Williamsburg (City)";
			}
			else if (county == "Poquoson") {
				county = "Poquoson (City)";
			}
			else if (county == "Danville") {
				county = "Danville (City)";
			}
			else if (county == "Falls Church") {
				county = "Falls Church (City)";
			}
			else if (county == "Martinsville") {
				county = "Martinsville (City)";
			}
			else if (county == "Norton") {
				county = "Norton (City)";
			}
			else if (county == "Portsmouth") {
				county = "Portsmouth (City)";
			}
			else if (county == "Salem") {
				county = "Salem (City)";
			}
			else if (county == "Isle Of Wight") {
				county = "Isle of Wight";
			}
		}


		sum += county + ",";
		sum += state + ",";
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
		getline(infile, line, ',');
		getline(infile, line, ','); //sunrise/sunset
		sum += line; 
		getline(infile, line); //civil twilight, nautical twilight, astronomical twilight

		outfile << sum << endl;
	}


	return 0;
}