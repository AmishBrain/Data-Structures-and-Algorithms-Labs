/*
File:			Lab2.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student: Anita Sailors
	                amsailors@student.fullsail.edu
Purpose:		Usage of the std::vector class
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
#define LAB_2	1
// Individual unit test toggles
#define LAB2_PALINDROME_NUMBER		1
#define LAB2_FILL_FILE				1
#define LAB2_FILL_ARRAY 1
#define LAB2_CLEAR					1
#define LAB2_SORT_ASCENDING 1
#define LAB2_SORT_DESCENDING		1
#define LAB2_BRACKETS				1
#define LAB2_CONTAINS_TRUE			1
#define LAB2_CONTAINS_FALSE			1
#define LAB2_MOVE_PALINDROMES		1
/************/
/* Includes */
/************/
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
inline bool IsPalindromeNumber(unsigned int _num) {
    // TODO: Implement this function
   // Checks to see if a number is a palindrome (reads the same forwards and backwards)
    std::string str = std::to_string(_num);
    // In: _num			The number to check
    size_t length = str.length();
    // Return: True, if the number is a palindrome number
    for (size_t i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}
class DSA_Lab2 {
    friend class UnitTests_Lab2; // Giving access to test code
    private:
    std::vector<int> mValues; // contains all of the values
    std::vector<int> mPalindromes; // contains just the numbers that are palindromes (only used in MovePalindromes method)
    public:
    void Fill(const char* _input) {
        // TODO: Implement this method
        // Fill out the mValues vector with the contents of the binary file
        std::ifstream file(_input, std::ios::binary);
        //		First four bytes of the file are the number of ints in the file
        if (!file) {
            // In:	_input		Name of the file to open
            std::cout << "Failed to open file: " << _input << std::endl;
            return;
        }
        int numCount = 0;
        file.read(reinterpret_cast<char*>(&numCount), sizeof(numCount));
        mValues.resize(numCount);
        file.read(reinterpret_cast<char*>(mValues.data()), numCount * sizeof(int));
        file.close();
    }
    void Fill(const int* _arr, size_t _size) {
        // TODO: Implement this method
        // Fill out the mValues vector with the contents of an array
        // In:	_arr			The array of values
        //		_size			The number of elements in the array
        mValues.assign(_arr, _arr + _size);
    }
    void Clear() {
        // TODO: Implement this method
        // Remove all elements from vector and decrease capacity to 0
        mValues.clear();
        mValues.shrink_to_fit();
    }
    void Sort(bool _ascending) {
        // TODO: Implement this method
        // NOTE: Use the std::sort method in this implementation
        if (_ascending) {
            // Sort the vector 
            std::sort(mValues.begin(), mValues.end());
        }
        else {
            // In:	_ascending		To sort in ascending order or not
            std::sort(mValues.rbegin(), mValues.rend());
        }
    }
    int operator[](int _index) {
        // TODO: Implement this method
        // Get an individual element from the mValues vector
        if(_index >= 0 && _index < static_cast<int>(mValues.size())) {
            return mValues[_index];
        }
        return 0;
    }
    bool Contains(int _val) const {
        // TODO: Implement this method
        // Determine if a value is present in the vector
        for(int value : mValues) {
            // In:	_val		The value to find
            if(value == _val) {
                // Return: True, if the value is present
                return true;
            }
        }  
        return false;
    }
    void MovePalindromes() {
        // TODO: Implement this method
        // Move all palindrome numbers from mValues vector to mPalindromes vector
        auto it = mValues.begin();
        //		iterate through the main values vector
        while(it != mValues.end()) {
            //			if the value is a palindrome
            if(IsPalindromeNumber(*it)) {
                mPalindromes.push_back(*it);
                //				remove it from the values vector
                it = mValues.erase(it);
            }else {
                //				add it to the palindrome vector
                ++it;
            }
        }
    }
};
