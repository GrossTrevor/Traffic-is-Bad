#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "county.h"
#include "AdjList.h"
#include "heap.h"

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

	AdjList adj_list;


	ifstream infile("US_Accidents_2022_Data.csv"); 
	vector<string> info; 
	string line = "";


	//right now, making obj for every crash -> not wanted, no way of knowing county is already created 
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
		//add to adj list

	}


	return 0;
}