/*
File:			DSA_Lab4.h	
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:	Anita Sailors
				amsailors@student.fullsail.edu
Purpose:		Usage of the std::list class
Notes:			Property of Full Sail University 2305
*/
// Header protection
#pragma once
/***********/
/* Defines */
/***********/
/*
How to use:
	When working on a lab, turn that lab's #define from 0 to 1
		Example:	#define LAB_1	1
	When working on an individual unit test, turn that #define from 0 to 1
		Example:	#define DYNARRAY_DEFAULT_CTOR	1
NOTE: If the unit test is not on, that code will not be compiled!
*/
// Main toggle
#define LAB_4	1
// Individual unit test toggles
#define LAB4_QUEUE_ADD			1
#define LAB4_STACK_ADD			1
#define LAB4_QUEUE_REMOVE		1
#define LAB4_STACK_REMOVE		1
#define LAB4_INSERT_ITER		1
#define LAB4_INSERT_INDEX		1
#define LAB4_REMOVE_DECIMAL		1
/************/
/* Includes */
/************/
#include <list>
class DSA_Lab4 {
	friend class UnitTests_Lab4; // Giving access to test code
	// Data members
	std::list<float> mList;
public:
	// Add all of the values from the array into the list using queue ordering
	//
	// In:	_arr			The array of values
	//		_size			The number of elements in the array
	void QueueOrderingAdd(const float* _arr, size_t _size) {
		// TODO: Implement this method
	}

	// Add all of the values from the array into the list using stack ordering
	//
	// In:	_arr			The array of values
	//		_size			The number of elements in the array
	void StackOrderingAdd(const float* _arr, size_t _size) {
		// TODO: Implement this method
	}

	// Remove a single value from the list using queue ordering
	//
	// Return: The value that was removed
	float QueueOrderingRemove() {
		// TODO: Implement this method
	}

	// Remove a single value from the list using stack ordering
	//
	// Return: The value that was removed
	float StackOrderingRemove() {
		// TODO: Implement this method
	}

	// Insert a value _index nodes away from the head node
	//		If _index is 0 - insert in front of the head/front node
	//		If _index is 5 - insert in front of the 5th node in the list
	//
	// Example:	
	//			0<-[5]<->[1]<->[6]<->[4]<->[2]->0
	//	
	// Inserting a 7 at index 2
	//
	//			0<-[5]<->[1]<->[7]<->[6]<->[4]<->[2]->0
	//
	//
	// In:	_index		The "index" to add at
	//		_val		The value to insert
	void Insert(int _index, float _val) {
		// TODO: Implement this method
	}

	// Insert a value at the spot specified by the iterator passed in
	// 
	// In:	_iter		The iterator at the place to insert
	//		_val		The value to insert
	void Insert(std::list<float>::iterator _iter, float _val) {
		// TODO: Implement this method
	}

	// Remove all values from mList that have a decimal value > _decimal
	//		Example:   
	//			_decimal 0.5
	// 
	//			2.84	- removed
	//			0.5		- not removed
	//			482.043 - removed 
	//
	// In:	_decimal		The decimal value to check against
	//
	// Return: The total number of values removed
	int RemoveDecimalGreater(float _decimal) {
		// TODO: Implement this method
	}
};