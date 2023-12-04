#include "heap.h"

// constructor
MaxHeap::MaxHeap() {
	stateVect = vector<State>(); 
}

// destructor
MaxHeap::~MaxHeap() {
	stateVect.clear(); 
}

// heapify up
void MaxHeap::HeapifyUp(int index) {
	int child = index - 1;
	int parent = (child - 1) / 2;

	while (parent >= 0 && stateVect[child].GetAvSeverity() > stateVect[parent].GetAvSeverity()) 
	{		
		swap(stateVect[child], stateVect[parent]);
		child = parent;
		parent = (child - 1) / 2;
	}
}

// recursively heapify down
void MaxHeap::HeapifyDown(int index) {
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	int largestIndex = index;

	if (leftChild < stateVect.size() && stateVect[leftChild].GetAvSeverity() > stateVect[largestIndex].GetAvSeverity())
	{
		largestIndex = leftChild;
	}
	if (rightChild < stateVect.size() && stateVect[rightChild].GetAvSeverity() > stateVect[largestIndex].GetAvSeverity())
	{
		largestIndex = rightChild;
	}
	if (largestIndex != index)
	{
		swap(stateVect[index], stateVect[largestIndex]); 
		HeapifyDown(largestIndex);
	}
}

// get the amount of counties in the heap
int MaxHeap::GetHeapSize() {
	return stateVect.size();
}

// check if heap is empty
//return false when heap is not emtpy 
bool MaxHeap::EmptyHeap() {
	if (stateVect.size() > 0) 
	{
		return false;
	}
	return true;
}

//return true if state and county is found in heap 
bool MaxHeap::SearchCounty(string county, string state) {
	for (int i = 0; i < stateVect.size(); i++) {
		if (stateVect[i].GetName() == state) { 
			return stateVect[i].IsCountyHere(county); 
		}
	}
	return false;
}


//return true if state is found in heap 
bool MaxHeap::SearchState(string state) {
	for (int i = 0; i < stateVect.size(); i++) { 
		if (stateVect[i].GetName() == state) {
			return true;
		}
	}
	return false;
}

//return a state object for specified state 
State MaxHeap::GetState(string state) { 
	for (int i = 0; i < stateVect.size(); i++) { 
		if (stateVect[i].GetName() == state) {
			return stateVect[i];
		}
	}
	State obj;
	return obj;
}

//return county object with specified data (add initial data to new county)
County MaxHeap::GetCountyObj(string county_, string state, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time) {
	County county;
	county.AddCountyAndState(county_, state);
	county.AddSeverity(severity);
	county.AddVisibility(visibility);
	county.ChangeWeather(w_con);
	county.AddCrossing(crossing);
	county.AddJunction(junction);
	county.AddStop(stop);
	county.AddSignal(signal);
	county.AddDayOrNight(time);
	county.AddToTotalCrashes();

	return county;
}

// insert a new county into the bottom of the heap then heapify up
void MaxHeap::Insert(string county_, string state, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time) { 
	//if state is not found in heap 
	if (!SearchState(state)) {
		State temp;
		temp.AddTotalSeverity(severity, county_); 
		temp.SetName(state); 
		County c_temp;
		c_temp = GetCountyObj(county_, state, severity, visibility, w_con, crossing, junction, stop, signal, time);  
		temp.AddCounty(c_temp); 
		stateVect.push_back(temp);  
	}
	else if (!SearchCounty(county_, state)){ 
		//if state is found in heap but county is not found in the state 
		County c_temp; 
		c_temp = GetCountyObj(county_, state, severity, visibility, w_con, crossing, junction, stop, signal, time); 

		for (int i = 0; i < stateVect.size(); i++) {
			if (stateVect[i].GetName() == state) {
				stateVect[i].AddCounty(c_temp);
				stateVect[i].AddTotalSeverity(severity, county_);
			}
		}
	}
	else { 
		//state is found in heap and county already exists within state 
		for (int i = 0; i < stateVect.size(); i++) {
			if (stateVect[i].GetName() == state) {
				for (int j = 0; j < stateVect[i].GetNumCounties(); j++) {
					if (stateVect[i].FindCounty(county_).GetCounty() == county_) {
						stateVect[i].AddTotalSeverity(severity, county_);

						stateVect[i].GiveCounty(county_).AddToTotalCrashes(); 
						stateVect[i].GiveCounty(county_).AddSeverity(severity);
						stateVect[i].GiveCounty(county_).AddVisibility(visibility);
						stateVect[i].GiveCounty(county_).ChangeWeather(w_con);
						stateVect[i].GiveCounty(county_).AddCrossing(crossing); 
						stateVect[i].GiveCounty(county_).AddJunction(junction); 
						stateVect[i].GiveCounty(county_).AddStop(stop);  
						stateVect[i].GiveCounty(county_).AddSignal(signal);
						stateVect[i].GiveCounty(county_).AddDayOrNight(time);
						break;
					}
				}
				break;
			}
		}
	}
	HeapifyUp(stateVect.size());

	//making sure vector is not adding more than states given
	if (stateVect.size() == 50) {
		stateVect.pop_back();
	}
}

//prints only the states in the heap
void MaxHeap::PrintStates() {
	for (int i = 0; i < stateVect.size(); i++) {
		cout << stateVect[i].GetName() << endl;
		cout << "_____________" << endl;
	}
}

//prints the total crashes for each county and the total of all counties and states
void MaxHeap::PrintTotalCrashes() {
	int sum = 0;
	for (int i = 0; i < stateVect.size(); i++) {
		cout << "state: " << stateVect[i].GetName() << ": " << endl;
		for (int j = 0; j < stateVect[i].GetNumCounties(); j++) {
			vector<County> temp = stateVect[i].GetCountyVect();
			cout << "county: " << temp[j].GetCounty() << " | crashes: " << temp[j].GetTotalCrashes() << endl;
			sum += temp[j].GetTotalCrashes();
		}
	}
	cout << "total crashes: " << sum << endl;
}

//prints the data of each county in every state 
void MaxHeap::PrintCounties() {
	//cout << "size: " << stateVect.size() << endl;
	for (int i = 0; i < stateVect.size(); i++) {
		cout << "state: " << stateVect[i].GetName() << ": " << endl;
		stateVect[i].PrintCounties();
	}
}

// remove a county from the heap then heapify down
State MaxHeap::ExtractMax() {
	if (!EmptyHeap()) {
		swap(stateVect[0], stateVect[stateVect.size() - 1]);
		State temp = stateVect[stateVect.size() - 1];
		stateVect.pop_back();
		HeapifyDown(0);
		return temp;
	}
}

