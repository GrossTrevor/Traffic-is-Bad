#include "AdjList.h"

AdjList::AdjList() {
	//create empty map
	state_to_county = map<string, vector<County>>();
}

AdjList::~AdjList() {
	//empty map 
	state_to_county.clear();
}

void AdjList::AddCounty(string state, County county, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time) { 
	//if county isn't in the specific state 
	if (!CheckCounty(state, county)) {
		EditCounty(county, severity, visibility, w_con, crossing, junction, stop, signal, time);
		states_to_county[state].push_back(county); 
	}
	else {
		EditCounty(county, severity, visibility, w_con, crossing, junction, stop, signal, time);
	}
}

void AdjList::EditCounty(County county, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time) {
	county.AddSeverity(severity); 
	county.AddVisibility(visibility); 
	county.ChangeWeather(w_con);
	county.AddCrossing(crossing);
	county.AddJunction(junction);
	county.AddStop(stop);
	county.AddSignal(signal);
	county.AddDayOrNight(time);
}

//return true if not found in map already
bool AdjList::CheckCounty(string state, County county) { 
	if (find(states_to_county[state].begin(), states_to_county[state].end(), county) == states_to_county[state].end()) {
		return true;
	}
	else {
		return false;
	}
}

//return true if key not found in map 
bool AdjList::CheckState(string state) {
	if (states_to_county.find(state) == states_to_county.end()) {
		return true;
	}
	else {
		return false;
	}
}