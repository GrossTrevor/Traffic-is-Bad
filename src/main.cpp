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
		adj_list.AddCounty(info[2], info[1], info[0], info[3], info[4], info[5], info[6], info[7], info[8], info[9]);
	}


	return 0;
}