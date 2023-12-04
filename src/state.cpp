#include "state.h"

State::State() {
	total_severity_counties = 0;
	counties = vector<County>();
	name = "";
}

State::~State() {
	counties.clear(); 
}

void State::AddTotalSeverity(string severity, string county) { 
	if (IsCountyHere(county)) {
		County temp = FindCounty(county);
		total_severity_counties -= temp.GetAvgSeverity();
		temp.AddSeverity(severity);
		total_severity_counties += temp.GetAvgSeverity(); 
	}
}

double State::GetAvSeverity() { 
	return total_severity_counties / counties.size();
}

void State::AddCounty(County county) { 
	counties.push_back(county); 
}

//return true is county is found
bool State::IsCountyHere(string county) {
	for (int i = 0; i < counties.size(); i++) {
		if (counties[i].GetCounty() == county) {
			return true;
		}
	}
	return false;
}

County State::FindCounty(string county) {
	for (int i = 0; i < counties.size(); i++) {
		if (counties[i].GetCounty() == county) {
			return counties[i];
		}
	}
	County obj; 
	return obj; 
}

void State::SetName(string state) {
	name = state; 
}

string State::GetName() {
	return name;
}

int State::GetNumCounties() {
	return counties.size();
}

vector<County>& State::GetCountyVect() {
	return counties;
}

County& State::GiveCounty(string county) {
	for (int i = 0; i < counties.size(); i++) {
		if (counties[i].GetCounty() == county) {
			return counties[i];
		}
	}
	County obj;
	return obj;
}

void State::PrintCounties() {
	for (int i = 0; i < counties.size(); i++) {
		cout << counties[i].GetCounty() << ": " << endl;
		cout << counties[i].GetAvgSeverity() << ", " << counties[i].GetAvgVisibility() << ", " << counties[i].GetWeather("Fair") << ", " << counties[i].GetWeather("Cloudy") << ", " << counties[i].GetWeather("Rain") << ", ";
		cout << counties[i].GetWeather("Fog") << ", " << counties[i].GetWeather("Snow") << ", " << counties[i].GetCrossing() << ", " << counties[i].GetJunction() << ", " << counties[i].GetStop() << ", ";
		cout << counties[i].GetSignal() << ", " << counties[i].GetDay() << ", " << counties[i].GetNight() << ", " << counties[i].GetTotalCrashes() << endl; 
	}
}