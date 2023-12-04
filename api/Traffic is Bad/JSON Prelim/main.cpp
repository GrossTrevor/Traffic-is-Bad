#include "../json.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>

//using json = nlohmann::json;
using std::endl;

int main() {

	////Create the map of states and their codes
	//std::map<std::string, std::string> states;
	//states["01"] = "AL";
	//states["02"] = "AK";
	//states["04"] = "AZ";
	//states["05"] = "AR";
	//states["06"] = "CA";
	//states["08"] = "CO";
	//states["09"] = "CT";
	//states["10"] = "DE";
	//states["11"] = "DC";
	//states["12"] = "FL";
	//states["13"] = "GA";
	//states["15"] = "HI";
	//states["16"] = "ID";
	//states["17"] = "IL";
	//states["18"] = "IN";
	//states["19"] = "IA";
	//states["20"] = "KS";
	//states["21"] = "KY";
	//states["22"] = "LA";
	//states["23"] = "ME";
	//states["24"] = "MD";
	//states["25"] = "MA";
	//states["26"] = "MI";
	//states["27"] = "MN";
	//states["28"] = "MS";
	//states["29"] = "MO";
	//states["30"] = "MT";
	//states["31"] = "NE";
	//states["32"] = "NV";
	//states["33"] = "NH";
	//states["34"] = "NJ";
	//states["35"] = "NM";
	//states["36"] = "NY";
	//states["37"] = "NC";
	//states["38"] = "ND";
	//states["39"] = "OH";
	//states["40"] = "OK";
	//states["41"] = "OR";
	//states["42"] = "PA";
	//states["44"] = "RI";
	//states["45"] = "SC";
	//states["46"] = "SD";
	//states["47"] = "TN";
	//states["48"] = "TX";
	//states["49"] = "UT";
	//states["50"] = "VT";
	//states["51"] = "VA";
	//states["53"] = "WA";
	//states["54"] = "WV";
	//states["55"] = "WI";
	//states["56"] = "WY";
	//states["72"] = "PR";


	////Read in the file
	//std::ifstream f ("../counties.json");
	//std::ofstream p ("countiesMid.json");
	//std::string line = "";
	//std::string total = "";
	//std::string state = "";

	////Manually add the first 5 lines
	//std::getline(f, line);
	//p << line << std::endl;

	//std::getline(f, line);
	//p << line << std::endl;

	//std::getline(f, line);
	//p << line << std::endl;

	//std::getline(f, line);
	//p << line << std::endl;

	//std::getline(f, line);
	//p << line << std::endl;

	//bool doit = true;

	////Add the rest of the lines, excluding the irrelevant properties
	//while(!f.eof()) {
	//	total = "";

	//	std::getline(f, line, '}');
	//	
	//	if (line.length() < 3) {
	//		p << "]" << std::endl << "}" << std::endl;
	//		break;
	//	}

	//	total += line.substr(0, 38);
	//	line = line.substr(38);

	//	state = line.substr(11, 2);
	//	state = states[state];

	//	total += "COUNTY\": \"" + line.substr(116, line.substr(116).find(',')) + ", ";

	//	total += "\"STATE\": \"" + state + "\", ";

	//	total += "\"SEVERITY\": \"\", ";
	//	total += "\"WFAIR\": \"\", ";
	//	total += "\"WCLOUDY\": \"\", ";
	//	total += "\"WFOG\": \"\", ";
	//	total += "\"WRAIN\": \"\", ";
	//	total += "\"WSNOW\": \"\", ";
	//	total += "\"CROSSING\": \"\", ";
	//	total += "\"JUNCTION\": \"\", ";
	//	total += "\"STOP\": \"\", ";
	//	total += "\"SIGNAL\": \"\", ";
	//	total += "\"DAY\": \"\", ";
	//	total += "\"NIGHT\": \"\", ";
	//	total += "\"POOR_VISIBILITY\": \"\" ";
	//	total += "}";

	//	std::getline(f, line);
	//	total += line;
	//	p << total << std::endl;
	//}

	//std::ifstream i ("countiesMid.json");
	//json j;
	//i >> j;

	//std::ofstream o("../county_data.js");
	//o << "var county_data = " << std::setw(2) << j << ";" << std::endl;


	//county_data remake

	std::ifstream county_data("../county_data.js");
	std::ofstream county_dataRe("../county_dataRe.js");
	std::string line2 = "";
	
	while (!county_data.eof()) {
		getline(county_data, line2);
		if (line2.length() > 14 && line2.substr(9, 6) == "COUNTY") {
			county_dataRe << line2 << endl;
		}
		if (line2.length() > 14 && line2.substr(9, 5) == "STATE") {
			county_dataRe << line2 << endl;
			county_dataRe << "        \"SEVERITY\": \"\"," << endl;
			county_dataRe << "        \"WFAIR\": \"\"," << endl;
			county_dataRe << "        \"WCLOUDY\": \"\"," << endl;
			county_dataRe << "        \"WFOG\": \"\"," << endl;
			county_dataRe << "        \"WRAIN\": \"\"," << endl;
			county_dataRe << "        \"WSNOW\": \"\"," << endl;
			county_dataRe << "        \"CROSSING\": \"\"," << endl;
			county_dataRe << "        \"JUNCTION\": \"\"," << endl;
			county_dataRe << "        \"STOP\": \"\"," << endl;
			county_dataRe << "        \"SIGNAL\": \"\"," << endl;
			county_dataRe << "        \"DAY\": \"\"," << endl;
			county_dataRe << "        \"NIGHT\": \"\"," << endl;
			county_dataRe << "        \"POOR_VISIBILITY\": \"\"" << endl;
		}
		else if(line2.length() < 18 || (line2.length() > 14 && !(line2.substr(9, 6) == "COUNTY" || line2.substr(9, 8) == "SEVERITY" || line2.substr(9, 8) == "CROSSING" || line2.substr(9, 3) == "DAY" || line2.substr(9, 8) == "JUNCTION" || line2.substr(9, 5) == "NIGHT" || line2.substr(9, 15) == "POOR_VISIBILITY" || line2.substr(9, 6) == "SIGNAL" || line2.substr(9, 4) == "STOP" || line2.substr(9, 5) == "WFAIR" || line2.substr(9, 7) == "WCLOUDY" || line2.substr(9, 4) == "WFOG" || line2.substr(9, 5) == "WRAIN" || line2.substr(9, 5) == "WSNOW")))
			county_dataRe << line2 << endl;
	}

	return 0;
}