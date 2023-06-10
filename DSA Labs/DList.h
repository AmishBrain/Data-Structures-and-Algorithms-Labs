/*
File:			DList.h\
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:	Anita Sailors
				amsailors@student.fullsail.edu
Purpose:		A doubly-linked list (similar to std::list)
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
#define LAB_3 1
// Individual unit test toggles			
#define LAB3_CTOR						1
#define LAB3_NODE_CTOR_DEFAULT			1
#define LAB3_NODE_CTOR					1
#define LAB3_ADDHEAD_EMPTY				1
#define LAB3_ADDHEAD					1
#define LAB3_ADDTAIL_EMPTY				1
#define LAB3_ADDTAIL					1
#define LAB3_CLEAR						1
#define LAB3_DTOR						1
#define LAB3_ITER_BEGIN					1
#define LAB3_ITER_END					1
#define LAB3_ITER_INCREMENT_PRE			1
#define LAB3_ITER_INCREMENT_POST		1
#define LAB3_ITER_DECREMENT_PRE			1
#define LAB3_ITER_DECREMENT_POST		1
#define LAB3_ITER_DEREFERENCE			1
#define LAB3_INSERT_EMPTY				1
#define LAB3_INSERT_HEAD				1
#define LAB3_INSERT_MIDDLE				1
#define LAB3_ERASE_EMPTY				1
#define LAB3_ERASE_HEAD					1
#define LAB3_ERASE_TAIL					1
#define LAB3_ERASE_MIDDLE				1
#define LAB3_ASSIGNMENT_OP				1
#define LAB3_COPY_CTOR					1
template <typename Type>
class DList {
    friend class UnitTests_Lab3; // Giving access to test code
    struct Node {
        // NOTE: Values set to -1 for unit test purposes
        Type data;
        Node* next = reinterpret_cast<Node*>(-1);
        Node* prev = reinterpret_cast<Node*>(-1);
        // Constructor
        //		Creates and fills out a node
        Node(const Type& _data, Node* _next = nullptr, Node* _prev = nullptr) {
            // TODO: Implement this method
            // In:	_data	The value to store
             data = _data;
            //		_next	The address of the next node
            next = _next;
            //		_prev	The address of the prev node
            prev = _prev;
        }
    };
public:
    class Iterator {
    public:
        Node* mCurr = reinterpret_cast<Node*>(-1);
        // Example:
        //		I - Iterator's curr
        //		R - Return
        /*
            Before
            0<-[4]<->[5]<->[6]->0
                   I
            After
            0<-[4]<->[5]<->[6]->0
                            I
                            R
        */
        Iterator& operator++() {
            // TODO: Implement this method
            // Pre-fix increment operator
            mCurr = mCurr->next;
            // Return: Invoking object with curr pointing to next node
            return *this;
        }
        // NOTE:	Will need a temporary iterator 
        // Example:
        //		I - Iterator's curr
        //		R - Return
        /*
            Before
            0<-[4]<->[5]<->[6]->0
                      I
            After
            0<-[4]<->[5]<->[6]->0
                      R		I
        */
        Iterator operator++(int) {
            // TODO: Implement this method
            // Post-fix increment operator
            Iterator temp = *this;
            // In:	(unused)		Post-fix operators take in an unused int, so that the compiler can differentiate
            mCurr = mCurr->next;
            // Return:	An iterator that has its curr pointing to the "old" curr
            return temp;
        }
        // Example:
        //		I - Iterator's curr
        //		R - Return
        /*
            Before
            0<-[4]<->[5]<->[6]->0
                      I
            After
            0<-[4]<->[5]<->[6]->0
                I
                R
        */
        Iterator& operator--() {
            // TODO: Implement this method
            // Pre-fix decrement operator
            mCurr = mCurr->prev;
            // Return: Invoking object with curr pointing to previous node
            return *this;

        }
        // NOTE:	Will need a temporary iterator 
        // Example:
        //		I - Iterator's curr
        //		R - Return
        /*
            Before
            0<-[4]<->[5]<->[6]->0
                      I
            After
            0<-[4]<->[5]<->[6]->0
                I	  R
        */
        Iterator operator--(int) {
            // TODO: Implement this method
            // Post-fix decrement operator
            Iterator temp = *this;
            // In:	(unused)		Post-fix operators take in an unused int, so that the compiler can differentiate
            mCurr = mCurr->prev;
            // Return:	An iterator that has its curr pointing to the "old" curr
            return temp;
        }
        Type& operator*() {
            // TODO: Implement this method
            // Dereference operator
            // Return: The data the curr is pointing to
            return mCurr->data;
        }
        // Not-equal operator (used for testing)
        // 
        // In:	_iter		The iterator to compare against
        //
        // Return: True, if the iterators are not pointing to the same node
        bool operator !=(const Iterator& _iter) const {
            return mCurr != _iter.mCurr;
        }
    };
    // Data members
    // NOTE: All values set to -1 for unit test purposes
    Node* mHead = reinterpret_cast<Node*>(-1);
    Node* mTail = reinterpret_cast<Node*>(-1);
    size_t mSize = -1;
public:
    DList() {
        // TODO: Implement this method
        // Default constructor
        mHead = nullptr;
        mTail = nullptr;
        //		Creates a new empty linked list
        mSize = 0;
    }
    ~DList() {
        // TODO: Implement this method
        // Destructor
        //		Cleans up all dynamically allocated memory
        Clear();
    }
    DList(const DList& _copy) {
        // TODO: Implement this method
        // Copy constructor
        //		Used to initialize one object to another
        RecursiveCopy(_copy.mHead);
        // In:	_copy			The object to copy from
        mSize = _copy.mSize;
    }
    DList& operator=(const DList& _assign) {
        // TODO: Implement this method
        // Assignment operator
        //		Used to assign one object to another
        if(this != &_assign) {
            Clear();
            // In:	_assign			The object to assign from
            RecursiveCopy(_assign.mHead);
            //		This allows us to daisy-chain
            mSize = _assign.mSize;
        }
        // Return: The invoking object (by reference)
        return *this;
    }
private:
    void RecursiveCopy(const Node* _curr) {
        // TODO (optional): Implement this method
        // Optional recursive helper method for use with Rule of 3
        if(_curr) {
            // In:	_curr		The current Node to copy
            RecursiveCopy(_curr->next);
            AddHead(_curr->data);
        }
    }
public:
    void AddHead(const Type& _data) {
        // TODO: Implement this method
        // Add a piece of data to the front of the list
        Node* newNode = new Node(_data);
        // In:	_data			The object to add to the list
        if(mHead){
        newNode->next = mHead;
        mHead->prev = newNode;
            mHead = newNode;
            }
        else {
            mHead = newNode;
            mTail = newNode;
        }
        mSize++;
    }
    void AddTail(const Type& _data) {
        // TODO: Implement this method
        // Add a piece of data to the end of the list
        Node* newNode = new Node(_data);
        // In:	_data			The object to add to the list
        if(mTail){
            newNode->prev = mTail;
            mTail->next = newNode;
            mTail = newNode;
        }
        else {
            mHead = newNode;
            mTail = newNode;
        }
        mSize++;
    }
    void Clear() {
        // TODO: Implement this method
        // Clear the list of all dynamic memory
        RecursiveClear(mHead);
        //			Resets the list to its default state
        mHead = nullptr;
        mTail = nullptr;
        mSize = 0;
    }
private:
    void RecursiveClear(const Node* _curr) {
        // TODO (Optional): Implement this method
        // Optional recursive helper method for use with Clear
        if(_curr) {
            // In:	_curr		The current Node to clear
            RecursiveClear(_curr->next);
            delete _curr;
        } 
    }
public:
    // Example:
    /*
        Before
            0<-[4]<->[5]<->[6]->0
                      I
        After
            0<-[4]<->[9]<->[5]<->[6]->0
                      I
    */
    // Return:	The iterator
    // SPECIAL CASE:	Inserting at head or empty list
    // NOTE:	The iterator should now be pointing to the new node created
    Iterator Insert(Iterator& _iter, const Type& _data) {
        // Implement this method
        // In:	_iter		The iterator
        if(_iter.mCurr ==nullptr || _iter.mCurr ==mHead) {
            // Insert a piece of data *before* the passed-in iterator
            AddHead(_data);
            //		_data		The value to add
            _iter.mCurr = mHead;
        }
        else {
            Node* newNode = new Node(_data);
            newNode->next = _iter.mCurr;
            newNode->prev = _iter.mCurr->prev;
            _iter.mCurr->prev->next = newNode;
            _iter.mCurr->prev = newNode;
            _iter.mCurr = newNode;
            mSize++;
        }
        return _iter;
    }
    // In:	_iter		The iterator
    //
    
    // SPECIAL CASE:	Erasing head or tail
    // NOTE:	The iterator should now be pointing at the node after the one erased
    Iterator Erase(Iterator& _iter) {
        // TODO: Implement this method
        // Erase a Node from the list
        // Example
        /*
            Before
                0<-[4]<->[5]<->[6]->0
                          I
            After
                0<-[4]<->[6]->0
                          I
        */
        // Return:	The iterator
        if(_iter.mCurr == mHead) {
               mHead = mHead->next;
            delete _iter.mCurr;
            _iter.mCurr = mHead;
            mSize--;
        }
        else if(_iter.mCurr == mTail) {
            mTail = mTail->prev;
            delete _iter.mCurr;
            _iter.mCurr = nullptr;
            mSize--;
        }
        else {
            _iter.mCurr->prev->next = _iter.mCurr->next;
            _iter.mCurr->next->prev = _iter.mCurr->prev;
            delete _iter.mCurr;
            _iter.mCurr = _iter.mCurr->next;
            mSize--;
        }
        return _iter;
     
    }
    Iterator Begin() const {
        // TODO: Implement this method
        // Set an Iterator at the front of the list
        Iterator iter;
        iter.mCurr = mHead;
        // Return: An iterator that has its curr pointing to the list's head
        return iter;
    }
    Iterator End() const {
        // TODO: Implement this method
        // Set an Iterator pointing to the end of the list
        Iterator iter;
        iter.mCurr = nullptr;
        // Return: An iterator that has its curr pointing to a null pointer
        return iter;
    }
};
