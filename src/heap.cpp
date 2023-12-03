#include "heap.h"

// constructor
MaxHeap::MaxHeap() {
	numCounties = 0;
}

// destructor
MaxHeap::~MaxHeap() {
	countyVect.clear(); 
}

// recursively heapify up
void MaxHeap::HeapifyUp(int index) {
	while (index != 0) 
	{
		int parentIndex = (index - 1) / 2;
		if (countyVect[index].GetAvgSeverity() > countyVect[parentIndex].GetAvgSeverity())
		{
			swap(countyVect[index], countyVect[parentIndex]);
			HeapifyUp(parentIndex);
		}
	}
}

// recursively heapify down
void MaxHeap::HeapifyDown(int index) {
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	int largestIndex = index;

	if (leftChild < numCounties && countyVect[leftChild].GetAvgSeverity() > countyVect[largestIndex].GetAvgSeverity()) 
	{
		largestIndex = leftChild;
	}
	if (rightChild < numCounties && countyVect[rightChild].GetAvgSeverity() > countyVect[largestIndex].GetAvgSeverity())
	{
		largestIndex = rightChild;
	}
	if (largestIndex != index)
	{
		swap(countyVect[index], countyVect[largestIndex]); 
		HeapifyDown(largestIndex);
	}
}

// get the amount of counties in the heap
int MaxHeap::GetHeapSize() {
	return numCounties;
}

// check if heap is empty
bool MaxHeap::EmptyHeap() {
	if (numCounties > 0)
	{
		return false;
	}
	return true;
}

//return true if county is found in heap 
bool MaxHeap::Search(string county, string state) {
	for (int i = 0; i < numCounties; i++) {
		if (countyVect[i].GetCounty() == county && countyVect[i].GetState() == state) {
			return true;
		}
	}
	return false;
}

County MaxHeap::GetCounty(string county, string state) {
	for (int i = 0; i < numCounties; i++) {
		if (countyVect[i].GetCounty() == county && countyVect[i].GetState() == state) {
			return countyVect[i];
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
	County temp; 
	if (!Search(county_, state)) {
		temp = GetCountyObj(county_, state, severity, visibility, w_con, crossing, junction, stop, signal, time);   
	}
	else {
		temp = GetCounty(county_, state);
		EditCounty(temp, severity, visibility, w_con, crossing, junction, stop, signal, time); 
	}

	countyVect.push_back(temp); 
	numCounties++; 
	HeapifyUp(numCounties);
}

// remove a county from the heap then heapify down
//void MaxHeap::Remove() {
//	numCounties--;
//	swap(countyVect[0], countyVect[numCounties]); 
//	delete countyVect[numCounties];     need to add erase to make this line work 
//	HeapifyDown(0);
//}

