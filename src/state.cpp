#include "state.h"

State::State() {
	total_severity_counties = 0;
	counties = vector<County>();
	name = "";
}

State::~State() {
	counties.clear(); 
}

//recalculates the total_severity of the state, this number is later divided by the total counties in the state 
void State::AddTotalSeverity(string severity, string county) { 
	if (IsCountyHere(county)) {
		County temp = FindCounty(county);
		total_severity_counties -= temp.GetAvgSeverity();
		temp.AddSeverity(severity);
		total_severity_counties += temp.GetAvgSeverity(); 
	}
}

//return the average severity of the state
double State::GetAvSeverity() { 
	return total_severity_counties / counties.size();
}

//adds a new county object to the county object vector 
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

//return the county object to the given county and state
County State::FindCounty(string county) {
	for (int i = 0; i < counties.size(); i++) {
		if (counties[i].GetCounty() == county) {
			return counties[i];
		}
	}
	County obj; 
	return obj; 
}

//sets the state name 
void State::SetName(string state) {
	name = state; 
}

//returns the state's name 
string State::GetName() {
	return name;
}

//get to total number of counties in the state 
int State::GetNumCounties() {
	return counties.size();
}

//returns to total crashes in the state 
int State::GetTotalCrashesState() {
	int sum = 0;
	for (int i = 0; i < counties.size(); i++) {
		sum += counties[i].GetTotalCrashes();
	}
	return sum;
}

//returns a reference to the vector of county objects 
vector<County>& State::GetCountyVect() {
	return counties;
}

//returns a reference to the given county 
County& State::GiveCounty(string county) {
	for (int i = 0; i < counties.size(); i++) {
		if (counties[i].GetCounty() == county) {
			return counties[i];
		}
	}
	County obj;
	return obj;
}

//prints all the county info for each county in the state 
void State::PrintCounties() {
	for (int i = 0; i < counties.size(); i++) {
		cout << counties[i].GetCounty() << ": " << endl;
		cout << counties[i].GetAvgSeverity() << ", " << counties[i].GetAvgVisibility() << ", " << counties[i].GetWeather("Fair") << ", " << counties[i].GetWeather("Cloudy") << ", " << counties[i].GetWeather("Rain") << ", ";
		cout << counties[i].GetWeather("Fog") << ", " << counties[i].GetWeather("Snow") << ", " << counties[i].GetCrossing() << ", " << counties[i].GetJunction() << ", " << counties[i].GetStop() << ", ";
		cout << counties[i].GetSignal() << ", " << counties[i].GetDay() << ", " << counties[i].GetNight() << ", " << counties[i].GetTotalCrashes() << endl; 
	}
}