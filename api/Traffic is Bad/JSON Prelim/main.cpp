#include "../json.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using json = nlohmann::json;

int main() {

	std::ifstream i ("../counties.json");
	json j;
	i >> j;

	std::ofstream o("../county_data.js");
	o << "var county_data = " << std::setw(4) << j << ";" << std::endl;

	return 0;
}