County::County() {
	cost = make_pair("", "");
	severity = 0;

	weather['Fair'] = 0;
	weather['Mostly Cloudy'] = 0;
	weather['Cloudy'] = 0;
	weather['Partly Cloudy'] = 0; 

	crossing = 0;
	junction = 0; 
	stop = 0; 
	signal = 0;
	day = 0;
	night = 0;

}