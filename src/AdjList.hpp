//#include "AdjList.h"
//
//AdjList::AdjList() {
//	//create empty map
//	state_to_county = map<string, vector<County>>();
//}
//
//AdjList::~AdjList() {
//	//empty map 
//	state_to_county.clear();
//}
//
//County AdjList::GetCountyObj(string state, string county) {
//	auto itr = state_to_county.find(state);
//	for (int i = 0; i < itr->second.size(); i++) {  
//		if (itr->second[i].GetCounty() == county) { 
//			return itr->second[i];  
//		}
//	}
//}
//
//void AdjList::EditCounty(County county, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time) {
//	county.AddSeverity(severity);
//	county.AddVisibility(visibility);
//	county.ChangeWeather(w_con);
//	county.AddCrossing(crossing);
//	county.AddJunction(junction);
//	county.AddStop(stop);
//	county.AddSignal(signal);
//	county.AddDayOrNight(time);
//	county.AddToTotalCrashes();
//}
//
////return true if key not found in map 
//bool AdjList::CheckState(string state) {
//	if (state_to_county.find(state) == state_to_county.end()) {
//		return true;
//	}
//
//	return false;
//
//}
//
////return true if not found in map already
//bool AdjList::CheckCounty(string state, string county) {
//	if (!CheckState) {
//		auto it = state_to_county.find(state);
//		for (int i = 0; i < it->second.size(); i++) {
//			if (it->second[i].GetCounty() == county) {
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//void AdjList::AddCounty(string state, string county, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time) { 
//	//if county isn't in the specific state 
//	if (CheckCounty(state, county)) {
//		//must create county object then edit it
//		County county_obj;
//		county_obj.AddCountyAndState(county, state); 
//		EditCounty(county_obj, severity, visibility, w_con, crossing, junction, stop, signal, time);
//		state_to_county[state].push_back(county);
//	}
//	else {
//		EditCounty(GetCountyObj(state, county), severity, visibility, w_con, crossing, junction, stop, signal, time);
//	}
//}
