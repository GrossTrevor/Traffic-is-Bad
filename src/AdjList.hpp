#include "AdjList.h"

AdjList::AdjList() {
	//create empty map
	state_to_county = map<string, vector<County>>();
}

AdjList::~AdjList() {
	//empty map 
	state_to_county.clear();
}

