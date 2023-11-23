County::County() {
	cost = make_pair("", "");
	severity = 0;

	weather["Fair"] = 0;
	weather["Mostly Cloudy"] = 0;
	weather["Cloudy"] = 0;
	weather["Partly Cloudy"] = 0;

	crossing = 0;
	junction = 0;
	stop = 0;
	signal = 0;
	day = 0;
	night = 0;
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

void County::AddVisibility(double visible) {
	visibility.push_back(visible);
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

void County::AddCrossing() {
	crossing++;
}

void County::AddJunction() {
	junction++;
}

void County::AddStop() {
	stop++;
}

void County::AddSignal() {
	signal++;
}