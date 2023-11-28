#include ".\\json.hpp"
#include <iostream>
#include <fstream>
#include <string>

using json = nlohmann::json;

int main() {

	std::ifstream i (".\\counties.json");
	json j;
	i >> j;

	std::ofstream o(".\\county_data.json");
	o << j << std::endl;

	return 0;
}