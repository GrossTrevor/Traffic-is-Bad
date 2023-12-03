#include "heap.h"

// constructor
MaxHeap::MaxHeap() {
	numStates = 0;
}

// destructor
MaxHeap::~MaxHeap() {
	stateVect.clear(); 
}

// recursively heapify up
void MaxHeap::HeapifyUp(int index) {
	while (index != 0) 
	{
		int parentIndex = (index - 1) / 2;
		if (stateVect[index].GetAvgSeverity() > stateVect[parentIndex].GetAvgSeverity())
		{
			swap(stateVect[index], stateVect[parentIndex]);
			HeapifyUp(parentIndex);
		}
	}
}

// recursively heapify down
void MaxHeap::HeapifyDown(int index) {
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	int largestIndex = index;

	if (leftChild < numStates && stateVect[leftChild].GetAvgSeverity() > stateVect[largestIndex].GetAvgSeverity()) 
	{
		largestIndex = leftChild;
	}
	if (rightChild < numStates && stateVect[rightChild].GetAvgSeverity() > stateVect[largestIndex].GetAvgSeverity())
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
	return numStates;
}

// check if heap is empty
bool MaxHeap::EmptyHeap() {
	if (numStates > 0)
	{
		return false;
	}
	return true;
}

//return true if state and county is found in heap 
bool MaxHeap::SearchCounty(string county, string state) {
	for (int i = 0; i < numStates; i++) {
		if (stateVect[i].GetName() == state) { 
			return stateVect[i].IsCountyHere(county); 
		}
	}
	return false;
}

bool MaxHeap::SearchState(string state) {
	for (int i = 0; i < numStates; i++) {
		if (stateVect[i].GetName() == state) {
			return true;
		}
	}
	return false;
}


//warning: only use if the county already exists in state
//County MaxHeap::GetCounty(string county, string state) {
//	for (int i = 0; i < numStates; i++) {
//		if (stateVect[i].GetName() == state) {
//			return stateVect[i].FindCounty(county); 
//		}
//	}
//	County obj;
//	return obj; 
//}

State MaxHeap::GetState(string state) {
	for (int i = 0; i < numStates; i++) {
		if (stateVect[i].GetName() == state) {
			return stateVect[i];
		}
	}
	County obj;
	return obj;
}

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

void MaxHeap::EditCounty(County county, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time) {
	county.AddSeverity(severity);
	county.AddVisibility(visibility);
	county.ChangeWeather(w_con);
	county.AddCrossing(crossing);
	county.AddJunction(junction);
	county.AddStop(stop);
	county.AddSignal(signal);
	county.AddDayOrNight(time);
	county.AddToTotalCrashes();
}

// insert a new county into the bottom of the heap then heapify up
void MaxHeap::Insert(string county_, string state, string severity, string visibility, string w_con, string crossing, string junction, string stop, string signal, string time) { 
	//if state is not found in heap 
	if (!SearchState(state)) {
		State temp;
		temp.AddTotalSeverity(severity);
		temp.SetName(state); 
		County c_temp;
		c_temp = GetCountyObj(county_, state, severity, visibility, w_con, crossing, junction, stop, signal, time);  
		temp.AddCounty(c_temp); 
		stateVect.push_back(temp); 
		numStates++; 
	}
	else if (!IsCountyHere(county_)){ //if state is found in heap but county is not found in the state 
		County c_temp; 
		c_temp = GetCountyObj(county_, state, severity, visibility, w_con, crossing, junction, stop, signal, time); 
		State temp = GetState(state);
		temp.AddCounty(c_temp); 
		temp.AddTotalSeverity(severity);
	}
	else { //state is found in heap and county already exists within state 
		State temp = GetState(state);
		temp.AddTotalSeverity(severity);
		EditCounty(temp.FindCounty(state), severity, visibility, w_con, crossing, junction, stop, signal, time); 
	}
	HeapifyUp(numStates);
}

// remove a county from the heap then heapify down
//void MaxHeap::Remove() {
//	numCounties--;
//	swap(countyVect[0], countyVect[numCounties]); 
//	delete countyVect[numCounties];     need to add erase to make this line work 
//	HeapifyDown(0);
//}

