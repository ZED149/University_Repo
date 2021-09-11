

#pragma once


#include <iostream>
#include <vector>
using namespace std;



// This is a Max-Heap Class
template <typename T>
class maxHeap 
{
	// Utlitity Functions
	// Heapify
	void heapify(int i)
	{
		int imax = i;
		if (2 * i <= heap_array.size() - 1 && heap_array[2 * i] > heap_array[i])
		{
			imax = (2 * i);
		}
		if ((2 * i) + 1 <= heap_array.size() - 1 && heap_array[(2 * i) + 1] > heap_array[imax])
		{
			imax = (2 * i) + 1;
		}

		if (imax != i)
		{
			swap(heap_array[i], heap_array[imax]);
			heapify(imax);
		}
	}


	// Private Data Members
	vector<T> heap_array;	// Heap Array which is physically stored as an Vector[array] but is logically implemented as a Binary Tree



public:	// This is where the member goes
	maxHeap()
	{
		cout << "heap() called" << endl;
		heap_array.push_back(NULL);
	}


	// Insert
	void Insert(const T key)
	{
		// First I need to push key into the heap_array
		heap_array.push_back(key);
		
		// Now I need to check whether my heap_array is still a max-heap or not
		// if it is not then make it a max-heap
		int i = heap_array.size() - 1;
		while (i != 1 && heap_array[i] > heap_array[i / 2])
		{
			swap(heap_array[i], heap_array[i / 2]);
			i /= 2;
		}
	}


	// Extract Max
	void ExtractMax()
	{
		if (heap_array.size() > 1)
		{
			T temp = heap_array[heap_array.size() - 1];
			heap_array[1] = temp;	// always root
			heap_array.pop_back();
			heapify(1);
		}
	}

};