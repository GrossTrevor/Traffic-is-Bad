#include "state.h"

State::State() {
	total_severity_counties = 0;
	counties = vector<County>();
	name = "";
}

State::~State() {
	counties.clear(); 
}

void State::AddTotalSeverity(string severity) { 
	total_severity_counties += stod(severity);
}

double State::GetAvgSeverity() { 
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