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

int main() {
	ifstream infile("US_Accidents_March23.csv");
	ofstream outfile("US_Accidents_2022.csv");
	string line = "";
	string total = "";

	while (!infile.eof()) {
		total = "";

		getline(infile, line, ',');
		total += line + ",";
		getline(infile, line, ',');
		total += line + ",";
		getline(infile, line, ',');
		total += line + ",";
		getline(infile, line);
		total += line;
		if (line.substr(0, 4) == "2022") {
			outfile << total << endl;
		}
	}

	return 0;
}