// Implimentation of Linked List Header
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

// Tests whether the list is empty.
// Returns true if empty, false otherwise
bool LinkedList::isEmpty(Node*& head) const
{
	if (head == nullptr) {
		return true;
	}
	return false;
}

// Function inserts new node in the list at the head of the list
void LinkedList::insertAtHead(Node*& head, Node*& tail, string input) 
{
	Node *temp;
	temp = new Node;
	temp->data = input;
	temp->next = nullptr;
	head = temp;
	tail = temp;
}

// Function inserts new node at the tail end of list or head if new list
void LinkedList::insert(Node*& head, Node*& tail, string input) 
{
	if (isEmpty(head))
		insertAtHead(head, tail, input);
	else {
		Node *temp = new Node;
		temp->data = input;
		temp->next = nullptr;
		tail->next = temp;
		tail = temp;
	}
}

// Function prints out linked list from head to tail.
// Was used for testing purposes.
void LinkedList::printList()
{
	Node *cursor;
	cursor = head;
	for (cursor; cursor != nullptr; cursor = cursor->next) {
		cout << cursor->data << endl;
	}
}

// Returns most recent entry into the list
string LinkedList::pop(Node*& head, Node*& tail)
{
	Node *cursor = head;
	string dataOutput;
	for (cursor; cursor != nullptr; cursor = cursor->next)
		dataOutput = cursor->data;

	deleteTail();
	return dataOutput;
}

// Returns a count of number of nodes in the list
// was used for testing purposes
int LinkedList::getNodeCount(Node*& head) 
{
	if (isEmpty(head))
		return 0;

	Node *cursor = head;
	int nodeCount{ 0 };
	for (cursor; cursor != nullptr; cursor = cursor->next) {
		nodeCount++;
	}
	return nodeCount;
}

// Function deletes tail of list and moves tail to previous node
void LinkedList::deleteTail()
{
	if (tail == nullptr)
		return;
	else {
		Node *removedNode;
		removedNode = tail;
		if (head == tail) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node *previousToTail = head;
			while (previousToTail->next != tail)
				previousToTail = previousToTail->next;
			tail = previousToTail;
			tail->next = nullptr;
		}
	}
}

// Function clears list for new
// Reverse Polish Notation calculation
void LinkedList::eraseList(Node*& head) {
	while (!(isEmpty(head))) {
		deleteTail();
	}
}