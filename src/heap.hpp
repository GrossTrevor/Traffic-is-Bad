#pragma once
#include "heap.h"

// constructor
MaxHeap::MaxHeap() {
	numCounties = 0;
}

// destructor
MaxHeap::~MaxHeap() {
	for (int i = 0; i < numCounties; i++)
	{
		delete countyVect[i];
	}
}

// recursively heapify up
void MaxHeap::HeapifyUp(int index) {
	while (index != 0) 
	{
		int parentIndex = (index - 1) / 2;
		if (countyVect[index] > countyVect[parentIndex])
		{
			std::swap(countyVect[index], countyVect[parentIndex]);
			HeapifyUp(parentIndex);
		}
	}
}

// recursively heapify down
void MaxHeap::HeapifyDown(int index) {
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	int largestIndex = index;

	if (leftChild < numCounties && countyVect[leftChild] > countyVect[largestIndex])
	{
		largestIndex = leftChild;
	}
	if (rightChild < numCounties && countyVect[rightChild] > countyVect[largestIndex])
	{
		largestIndex = rightChild;
	}
	if (largestIndex != index)
	{
		std::swap(countyVect[index], countyVect[largest]);
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

// insert a new county into the bottom of the heap then heapify up
void MaxHeap::Insert(countyVect* newCounty) {
	this->countyVect.push_back(newCounty);
	int num = numCounties + 1;
	HeapifyUp(num);
}

// remove a county from the heap then heapify down
void MaxHeap::Remove() {
	int num = numCounties - 1;
	swap(countyVect[0], countyVect[num]);
	delete countyVect[numCounties];
	HeapifyDown(0);
}