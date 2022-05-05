#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include "Course.h"

using namespace std;


//******************************************
//* ListNode class creates a type used to  *
//* store a node of the linked list.       *
//******************************************

template <class T>
class ListNode {
	public:
		T value;			// node value
		ListNode<T>* next;  // pointer to the next node

		// Constructor
		ListNode(T nodeValue) {
			value = nodeValue;
			next = nullptr;
		}

};

// ********************
// * LinkedList class *
// ********************

template <class T>
class LinkedList {
	private:
		ListNode<T>* head; // List head pointer
		ListNode<T>* sorted; // List head pointer
	public:
		// Constructor
		LinkedList() {
			head = nullptr;
		}

		// Linked list operations
        ListNode<T>* getHead() const;
        void appendNode(T);
        void deleteNode(T);
		void displayList() const;
        void sortedInsert(ListNode<T>* newnode);
		void insertionsort();
};

// ***************************************************
// * appendNode appends a node containing the value  *
// * passed into newValue, to the end of the list.   *
// * for lab 6, this is the add function             *
// ***************************************************

template <class T>
void LinkedList<T>::appendNode(T newValue) {
	ListNode<T>* newNode;
	ListNode<T>* nodePtr; 
	// allocate a new node and store newValue there
	newNode = new ListNode<T>(newValue);

	// if there are no nodes in the list
	// make newNode the first node
	if (!head) {

		head = newNode;

	} else {

		// initialize nodePtr to head of list
		nodePtr = head;

		// find the last node in the list
		while (nodePtr->next) {

			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
	}
}

// *****************************************************************
// * deleteNode searches for a node with searchValue as its value. *
// * The node, if found, is deleted from the list and from memory  *
// * For lab 6, this is the drop function                          *
// *****************************************************************

template <class T>
void LinkedList<T>::deleteNode(T searchValue) {

	ListNode<T>* nodePtr;		// To traverse the list
	ListNode<T>* previousNode;  // To point to the previous node

	// If the list is empty, do nothing
	if (!head) {

		return;

	}

	// Determine if the first node is the one
	if (head->value == searchValue) {

		nodePtr = head->next;
		delete head;
		head = nodePtr;

	}
	else {

		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num
		while (nodePtr != nullptr && nodePtr->value != searchValue) {

			previousNode = nodePtr;
			nodePtr = nodePtr->next;

		}

		// If node Ptr is not at the end of the list,
		// link the previous node to the nmode after
		// nodePtr, then delete nodePtr
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

// ***************************************************
// * displayList shows the value stored in each node *
// * of the linked list pointed to by head.          *
// ***************************************************

template <class T>
void LinkedList<T>::displayList() const {

	ListNode<T>* nodePtr; // To move through the list

	// Position noedPtr at the head of the list
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list
	while (nodePtr) {

		// Display the value in this node
		std::cout << nodePtr->value << std::endl;

		// Move to the next node
		nodePtr = nodePtr->next;
	}
}

template <class T>
ListNode<T>* LinkedList<T>::getHead() const{
    return head;
}


template <class T>
void LinkedList<T>::sortedInsert(ListNode<T>* newnode)
{
    /* Special case for the head end */
    if (sorted == NULL || sorted->value >= newnode->value) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        ListNode<T>* current = sorted;
        /* Locate the node before the point of insertion
         */
        while (current->next != NULL
               && current->next->value < newnode->value) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}
 
// function to sort a singly linked list
// using insertion sort

template <class T>
void LinkedList<T>::insertionsort()
{
 
    ListNode<T>* current = head;
 
    // Traverse the given linked list and insert every
    // node to sorted
    while (current != NULL) {
 
        // Store next for next iteration
        ListNode<T>* next = current->next;
 
        // insert current in sorted linked list
        sortedInsert(current);
 
        // Update current
        current = next;
    }
    // Update head to point to sorted linked list
    head = sorted;
}
#endif