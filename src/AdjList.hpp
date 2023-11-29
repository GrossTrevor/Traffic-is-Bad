#include "AdjList.h"

AdjList::AdjList() {
	//create empty map
	state_to_county = map<string, vector<County>>();
}

AdjList::~AdjList() {
	//empty map 
	state_to_county.clear();
}

void AdjList::AddCounty(string state, County county) { 
	//if county isn't in the specific state 
	if (!CheckCounty(state, county)) {
		states_to_county[state].push_back(county); 
	}
	else {
		//edit the county directly 
	}
}

//return true if not found in map already
bool CheckCounty(string state, County county) { 
	if (find(states_to_county[state].begin(), states_to_county[state].end(), county) == states_to_county[state].end()) {
		return true;
	}
	else {
		return false;
	}
}

//return true if key not found in map 
bool CheckState(string state) {
	if (states_to_county.find(state) == states_to_county.end()) {
		return true
	}
	else {
		return false;
	}
}