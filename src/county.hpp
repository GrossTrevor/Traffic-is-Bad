#include "county.h"

County::County() {
	cost = make_pair("", "");
	severity = 0;

	weather["Fair"] = 0;
	weather["Cloudy"] = 0;
	weather["Fog"] = 0;
	weather["Rain"] = 0;
	weather["Snow"] = 0;

	crossing = 0;
	junction = 0;
	stop = 0;
	signal = 0;
	day = 0;
	night = 0;
	total_crashes = 0;
}

void County::ChangeWeather(string w_state) { 
	if (w_state == "Fair") {
		weather["Fair"] + 1;
	}
	else if (w_state == "Mostly Cloudy" || w_state == "Cloudy" || w_state == "Partly Cloudy" || w_state == "Smoke" || w_state == "Thunder" || w_state == "Blowing Dust" || w_state == "Widespread Dust" || w_state == "Funnel Cloud") {
		weather["Cloudy"] + 1;
	}
	else if (w_state == "Rain" || w_state == "Drizzle" || w_state == "Light Rain" || w_state == "Heavy Rain" || w_state == "Light Rain with Thunder " || w_state == "Light Drizzle" || w_state == "Showers in the Vicinity" || w_state == "T-Storm" || w_state == "Heavy T-Storm" || w_state == "Mist" || w_state == "Light Rain Shower" || w_state == "Heavy Drizzle" || w_state == "Tornado" || w_state == "Rain Shower" || w_state == "Light Freezing Rain" || w_state == "Light Freezing Drizzle" || w_state == "Freezing Drizzle" || w_state == "Freezing Rain" || w_state == "Heavy Freezing Rain" || w_state == "Squalls" || w_state == "Heavy Freezing Drizzle") {
		weather["Rain"] + 1;
	}
	else if (w_state == "Fog" || w_state == "Shallow Fog" || w_state == "Patches of Fog") {
		weather["Fog"] + 1;
	}
	else if (w_state == "Snow" || w_state == "Light Snow" || w_state == "Wintery Mix" || w_state == "Light Snow with Thunder" || w_state == "Snow and Thunder" || w_state == "Heavy Snow" || w_state == "Light Snow Shower" || w_state == "Sleet" || w_state == "Light Snow and Sleet" || w_state == "Snow and Sleet" || w_state == "Light Sleet" || w_state == "Blowing Snow" || w_state == "Hail" || w_state == "Sleet and Thunder" || w_state == "Small Hail" || w_state == "Heavy Sleet and Thunder" || w_state == "Thunder and Hail" || w_state == "Heavy Sleet" || w_state == "Heavy Snow with Thunder") {
		weather["Snow"] + 1;
	}
	//cannot use "else" because some crashes do not have some data points -> ensure they don't add things if they don't have the data 
}

void County::AddVisibility(string visible) {
	if (visible != "") {
		visibility.push_back(stod(visible));
	}
}

void County::AddDayOrNight(string time) {
	if (time == "Day") {
		day++;
	}
	else if (time == "Night") {
		night++;
	}
	//cannot use "else" because some crashes do not have some data points -> ensure they don't add things if they don't have the data 
}

void County::AddCrossing(string line) {
	if (line == "True") {
		crossing++;
	}
}

void County::AddJunction(string line) {
	if (line == "True") {
		junction++;
	}
}

void County::AddStop(string line) {
	if (line == "True") {
		stop++;
	}
}

void County::AddSignal(string line) {
	if (line == "True") {
		signal++;
	}
}

void County::AddSeverity(string s) {
	if (s != "") {
		total_severity += stoi(s);
	}
}

void County::AddCountyAndState(string county, string state) {
	cost = make_pair(county, state);
}

void County::AddToTotalCrashes() {
	total_crashes++;
}

string County::GetState() {
	return cost.second;
}

string County::GetCounty() {
	return cost.first;
}

int County::GetAvgSeverity() {
	return total_severity / total_crashes; 
}

int County::GetAvgVisibility() {
	int temp = 0;
	for (int i = 0; i < visibility.size(); i++) {
		temp += vibility[i];
	}
	return temp / visibility.size();
}

int County::GetWeather(string w_cond) {
	if (w_cond == "Fair") {
		return weather["Fair"];
	}
	else if (w_cond = "Cloudy") {
		return weather["Cloudy"];
	}
	else if (w_cond = "Rain") {
		return weather["Rain"];
	}
	else if (w_cond = "Fog") {
		return weather["Fog"];
	}
	else if (w_cond = "Snow") {
		return weather["Snow"];
	}
}

int County::GetCrossing() {
	return crossing;
}

int County::GetJunction() {
	return junctions;
}

int County::GetStop() {
	return stop;
}

int County::GetSignal() {
	return signal;
}

int County::GetDay() {
	return day;
}

int County::GetNight() {
	return night;
}

int County::GetTotalCrashes() {
	return total_crashes;
}