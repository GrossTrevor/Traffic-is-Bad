County::County() {
	cost = make_pair("", "");
	severity = 0;

	weather["Fair"] = 0;
	weather["Mostly Cloudy"] = 0;
	weather["Cloudy"] = 0;
	weather["Partly Cloudy"] = 0;
	weather["Fog"] = 0;
	weather["Shallow Fog"] = 0;
	weather["Haze"] = 0;
	weather["Light Rain"] = 0;
	weather["Rain"] = 0;
	weather["Heavy Rain"] = 0;

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
	else if (w_state == "Mostly Cloudy") {
		weather["Mostly Cloudy"] + 1;
	}
	else if (w_state == "Cloudy") {
		weather["Cloudy"] + 1;
	}
	else if (w_state == "Partly Cloudy") {
		weather["Partly Cloudy"] + 1;
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

